// ArduParam: WiFi-міст ESP32 <-> ArduPilot (MAVLink) + сторінка для телефону
// Політ (горизонт, акселерометр, гіроскоп, вібрації) і Full Parameter List.
//
// Плата: будь-яка ESP32 (ESP32 DevKit, ESP32-C3, ESP32-S3).
// Arduino IDE: Boards Manager -> "esp32" by Espressif. Додаткові бібліотеки не потрібні.

#include <WiFi.h>
#include <WebServer.h>
#include <ESPmDNS.h>
#include "page.h"

// ================= НАЛАШТУВАННЯ =================
const char*    WIFI_SSID = "ArduParam";
const char*    WIFI_PASS = "12345678";   // мінімум 8 символів, краще змініть
const uint32_t FC_BAUD   = 115200;       // має збігатися з SERIALx_BAUD = 115 на польотнику
const int      FC_RX_PIN = 16;           // ESP32 RX  <- TX польотника
const int      FC_TX_PIN = 17;           // ESP32 TX  -> RX польотника
// Для ESP32-C3 SuperMini зручно: FC_RX_PIN = 20, FC_TX_PIN = 21
// =================================================

HardwareSerial FC(1);
WebServer server(80);

static uint8_t ring[32768];
static size_t rHead = 0, rTail = 0;
static uint8_t outBuf[8192];
static uint8_t txBuf[512];

static void drainUart() {
  while (FC.available()) {
    int b = FC.read();
    if (b < 0) break;
    size_t nh = (rHead + 1) % sizeof(ring);
    if (nh == rTail) rTail = (rTail + 1) % sizeof(ring);  // переповнення: відкидаємо найстаріше
    ring[rHead] = (uint8_t)b;
    rHead = nh;
  }
}

static int hexv(char c) {
  if (c >= '0' && c <= '9') return c - '0';
  if (c >= 'a' && c <= 'f') return c - 'a' + 10;
  if (c >= 'A' && c <= 'F') return c - 'A' + 10;
  return 0;
}

// POST /x: тіло = байти для польотника в hex, відповідь = байти від польотника
static void handleX() {
  if (server.hasArg("plain")) {
    const String& h = server.arg("plain");
    size_t n = 0;
    for (size_t i = 0; i + 1 < h.length(); i += 2) {
      txBuf[n++] = (uint8_t)((hexv(h[i]) << 4) | hexv(h[i + 1]));
      if (n == sizeof(txBuf)) { FC.write(txBuf, n); n = 0; }
    }
    if (n) FC.write(txBuf, n);
  }
  drainUart();
  size_t n = 0;
  while (rTail != rHead && n < sizeof(outBuf)) {
    outBuf[n++] = ring[rTail];
    rTail = (rTail + 1) % sizeof(ring);
  }
  server.sendHeader("Cache-Control", "no-store");
  server.setContentLength(n);
  server.send(200, "application/octet-stream", "");
  if (n) server.sendContent((const char*)outBuf, n);
}

void setup() {
  Serial.begin(115200);
  FC.setRxBufferSize(4096);
  FC.begin(FC_BAUD, SERIAL_8N1, FC_RX_PIN, FC_TX_PIN);

  WiFi.mode(WIFI_AP);
  WiFi.softAP(WIFI_SSID, WIFI_PASS);
  WiFi.setSleep(false);
  MDNS.begin("ardu");  // також відкривається як http://ardu.local

  server.on("/", HTTP_GET, []() {
    server.sendHeader("Cache-Control", "no-cache");
    server.send(200, "text/html; charset=utf-8", PAGE);
  });
  server.on("/x", HTTP_POST, handleX);
  server.onNotFound([]() {
    server.sendHeader("Location", "/");
    server.send(302, "text/plain", "");
  });
  server.begin();

  Serial.printf("ArduParam: WiFi \"%s\", http://%s\n", WIFI_SSID, WiFi.softAPIP().toString().c_str());
}

void loop() {
  drainUart();
  server.handleClient();
  drainUart();
}
