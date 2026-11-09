#pragma once
// Р—РіРµРЅРµСЂРѕРІР°РЅРѕ Р· web/index.html СЃРєСЂРёРїС‚РѕРј build_page.ps1. РќРµ СЂРµРґР°РіСѓР№С‚Рµ РІСЂСѓС‡РЅСѓ.
const char PAGE[] PROGMEM = R"PAGE_RAW(<!doctype html>
<html lang="uk">
<head>
<meta charset="utf-8">
<meta name="viewport" content="width=device-width, initial-scale=1, viewport-fit=cover">
<meta name="apple-mobile-web-app-capable" content="yes">
<meta name="mobile-web-app-capable" content="yes">
<meta name="apple-mobile-web-app-status-bar-style" content="black-translucent">
<meta name="apple-mobile-web-app-title" content="ArduParam">
<meta name="theme-color" content="#0f1216">
<title>ArduParam</title>
<style>
:root{--bg:#0f1216;--card:#181c22;--card2:#20252d;--line:#272c35;--text:#e7eaee;--mut:#8b939e;--acc:#3b9eff;--ok:#2fbf71;--warn:#f0a020;--err:#ff5a5a}
*{box-sizing:border-box;-webkit-tap-highlight-color:transparent}
html,body{margin:0;background:var(--bg);color:var(--text);font:16px -apple-system,BlinkMacSystemFont,"Segoe UI",Roboto,sans-serif}
body{padding-bottom:calc(64px + env(safe-area-inset-bottom))}
header{position:sticky;top:0;z-index:5;background:var(--bg);padding:calc(env(safe-area-inset-top) + 8px) 12px 8px;border-bottom:1px solid var(--line)}
.row{display:flex;gap:8px;align-items:center}
.dot{width:10px;height:10px;border-radius:50%;background:var(--err);flex:none}
.dot.half{background:var(--warn)}.dot.on{background:var(--ok)}
#st{font-size:13px;color:var(--mut);flex:1;min-width:0;white-space:nowrap;overflow:hidden;text-overflow:ellipsis}
button{font:inherit;font-size:15px;border:0;border-radius:10px;padding:10px 14px;background:var(--card2);color:var(--text);cursor:pointer}
button.pri{background:var(--acc);color:#fff}
button.danger{background:#3a1d1f;color:#ff8a8a}
button:disabled{opacity:.4}
#ptools{margin-top:8px}
#ptools[hidden]{display:none}
input[type=search],input[type=text]{font:inherit;width:100%;min-width:0;padding:10px 12px;border-radius:10px;border:1px solid var(--line);background:var(--card);color:var(--text);outline:none;-webkit-appearance:none}
input:focus{border-color:var(--acc)}
.tog{font-size:13px;padding:10px;white-space:nowrap}
.tog.on{background:var(--warn);color:#000}
#prog{height:4px;background:var(--card2);border-radius:2px;overflow:hidden;margin-top:8px;display:none}
#prog i{display:block;height:100%;width:0;background:var(--acc);transition:width .2s}
#cnt{font-size:12px;color:var(--mut);margin-top:6px}
.p{display:flex;justify-content:space-between;gap:12px;padding:12px;border-bottom:1px solid var(--line);cursor:pointer}
.p:active{background:var(--card)}
.n{font-family:ui-monospace,Menlo,Consolas,monospace;font-size:14px;word-break:break-all}
.n b{color:var(--acc);font-weight:600}
.v{font-family:ui-monospace,Menlo,Consolas,monospace;font-size:14px;color:var(--acc);white-space:nowrap}
.p.mod .v{color:var(--warn)}
.empty{padding:40px 16px;text-align:center;color:var(--mut);font-size:14px;line-height:1.5}
/* flight */
#hudwrap{position:relative;margin:10px 12px 0;border-radius:14px;overflow:hidden;background:#000;aspect-ratio:4/3;max-height:58vh}
#hud{width:100%;height:100%;display:block}
.grid{display:grid;grid-template-columns:repeat(3,1fr);gap:8px;margin:10px 12px 0}
.tile{background:var(--card);border-radius:12px;padding:8px 10px;min-width:0}
.tile .k{font-size:11px;color:var(--mut);text-transform:uppercase;letter-spacing:.04em}
.tile .x{font-family:ui-monospace,Menlo,Consolas,monospace;font-size:17px;margin-top:2px;white-space:nowrap;overflow:hidden;text-overflow:ellipsis}
.tile .bar{height:3px;background:var(--card2);border-radius:2px;margin-top:6px;position:relative;overflow:hidden}
.tile .bar i{position:absolute;top:0;bottom:0;background:var(--acc)}
h3{font-size:12px;color:var(--mut);text-transform:uppercase;letter-spacing:.06em;margin:16px 12px 0;font-weight:600}
#msgs{margin:8px 12px 0;background:var(--card);border-radius:12px;font-size:13px;font-family:ui-monospace,Menlo,Consolas,monospace;max-height:200px;overflow:auto}
#msgs div{padding:7px 10px;border-bottom:1px solid var(--line)}
#msgs div:last-child{border-bottom:0}
#msgs .s0,#msgs .s1,#msgs .s2,#msgs .s3{color:var(--err)}#msgs .s4{color:var(--warn)}
#msgs .t{color:var(--mut);margin-right:6px}
/* tabs */
nav{position:fixed;left:0;right:0;bottom:0;z-index:6;display:flex;background:rgba(15,18,22,.96);border-top:1px solid var(--line);padding-bottom:env(safe-area-inset-bottom)}
nav button{flex:1;background:none;border-radius:0;padding:10px 0 12px;color:var(--mut);font-size:12px;display:flex;flex-direction:column;align-items:center;gap:3px}
nav button.on{color:var(--acc)}
nav svg{width:24px;height:24px}
/* sheet */
#back{position:fixed;inset:0;background:rgba(0,0,0,.55);z-index:10;display:none}
.sheet{position:fixed;left:0;right:0;bottom:0;z-index:11;background:var(--card);border-radius:16px 16px 0 0;padding:16px 16px calc(16px + env(safe-area-inset-bottom));display:none;max-height:85vh;overflow:auto}
.sheet.show,#back.show{display:block}
.sheet h2{margin:0 0 4px;font:600 18px ui-monospace,Menlo,Consolas,monospace;word-break:break-all}
.sheet .sub{font-size:13px;color:var(--mut);margin-bottom:14px}
.sheet .btns{display:flex;gap:8px;margin-top:14px}
.sheet .btns button{flex:1}
.menu button{display:block;width:100%;text-align:left;margin-bottom:8px}
.dif{display:flex;gap:10px;align-items:center;padding:10px 0;border-bottom:1px solid var(--line);font-size:14px}
.dif input{width:20px;height:20px;flex:none}
.dif .n{flex:1}
.dif .ch{font-family:ui-monospace,Menlo,Consolas,monospace;font-size:13px;color:var(--mut);text-align:right}
.dif .ch b{color:var(--warn);font-weight:500}
#toasts{position:fixed;left:12px;right:12px;top:calc(env(safe-area-inset-top) + 56px);z-index:20;display:flex;flex-direction:column;gap:6px;pointer-events:none}
.toast{background:#2a3038;color:var(--text);padding:10px 12px;border-radius:10px;font-size:14px;box-shadow:0 4px 16px rgba(0,0,0,.4);border-left:4px solid var(--acc)}
.toast.ok{border-color:var(--ok)}.toast.warn{border-color:var(--warn)}.toast.err{border-color:var(--err)}
.help{font-size:14px;line-height:1.5;color:var(--mut)}
#usbBtn[hidden]{display:none}
/* splash */
#splash{position:fixed;inset:0;z-index:30;background:#02080a;overflow:hidden;transition:opacity .35s}
#splash.off{opacity:0;pointer-events:none}
#splash .bg{position:absolute;inset:-40px;width:calc(100% + 80px);height:calc(100% + 80px);object-fit:cover;filter:blur(28px) brightness(.45)}
#splash .fg{position:absolute;inset:0;width:100%;height:100%;object-fit:contain}
#splash .sbot{position:absolute;left:0;right:0;bottom:0;padding:40px 20px calc(24px + env(safe-area-inset-bottom));background:linear-gradient(transparent,rgba(0,0,0,.85) 45%);display:flex;flex-direction:column;align-items:center;gap:10px}
#sst{display:flex;align-items:center;gap:8px;font-size:14px;color:#cfd6dd;text-align:center}
#sUsb{min-width:240px;padding:14px 20px;font-size:16px}
#sUsb[hidden]{display:none}
#sSkip{background:none;color:#8b939e;font-size:13px;padding:6px}
@media (min-width:820px){
  #tab-fly{display:grid;grid-template-columns:minmax(0,1.25fr) minmax(0,1fr);align-items:start}
  #tab-fly[hidden]{display:none}
  #flyL{position:sticky;top:60px}
  #hudwrap{max-height:none;margin-right:0}
  #flyR h3:first-child{margin-top:10px}
  #msgs{max-height:260px}
  .sheet{left:50%;right:auto;width:520px;transform:translateX(-50%)}
  #toasts{left:auto;width:420px}
}
.help code{color:var(--text);font-family:ui-monospace,Menlo,Consolas,monospace}
</style>
</head>
<body>
<header>
  <div class="row">
    <span class="dot" id="dot"></span>
    <span id="st">Підключення…</span>
    <button id="usbBtn" hidden>🔌 USB</button>
    <button id="menuBtn" aria-label="Меню">⋯</button>
  </div>
  <div id="ptools" hidden>
    <div class="row">
      <button class="pri" id="loadBtn">Завантажити</button>
      <input type="search" id="q" placeholder="Пошук: SERVO, VTX…" autocomplete="off" autocapitalize="characters" spellcheck="false">
      <button class="tog" id="modBtn" title="Тільки змінені">Змін.</button>
    </div>
    <div id="prog"><i></i></div>
    <div id="cnt"></div>
  </div>
</header>

<main>
  <section id="tab-fly">
    <div id="flyL"><div id="hudwrap"><canvas id="hud"></canvas></div></div>
    <div id="flyR">
    <h3>Акселерометр, м/с²</h3>
    <div class="grid">
      <div class="tile"><div class="k">X</div><div class="x" id="ax">—</div><div class="bar"><i id="axb"></i></div></div>
      <div class="tile"><div class="k">Y</div><div class="x" id="ay">—</div><div class="bar"><i id="ayb"></i></div></div>
      <div class="tile"><div class="k">Z</div><div class="x" id="az">—</div><div class="bar"><i id="azb"></i></div></div>
    </div>
    <h3>Гіроскоп, °/с</h3>
    <div class="grid">
      <div class="tile"><div class="k">X</div><div class="x" id="gx">—</div><div class="bar"><i id="gxb"></i></div></div>
      <div class="tile"><div class="k">Y</div><div class="x" id="gy">—</div><div class="bar"><i id="gyb"></i></div></div>
      <div class="tile"><div class="k">Z</div><div class="x" id="gz">—</div><div class="bar"><i id="gzb"></i></div></div>
    </div>
    <h3>Положення і вібрації</h3>
    <div class="grid">
      <div class="tile"><div class="k">Roll</div><div class="x" id="tr">—</div></div>
      <div class="tile"><div class="k">Pitch</div><div class="x" id="tp">—</div></div>
      <div class="tile"><div class="k">Yaw</div><div class="x" id="ty">—</div></div>
      <div class="tile"><div class="k">Vibe X</div><div class="x" id="vx">—</div><div class="bar"><i id="vxb"></i></div></div>
      <div class="tile"><div class="k">Vibe Y</div><div class="x" id="vy">—</div><div class="bar"><i id="vyb"></i></div></div>
      <div class="tile"><div class="k">Vibe Z</div><div class="x" id="vz">—</div><div class="bar"><i id="vzb"></i></div></div>
      <div class="tile"><div class="k">Clipping</div><div class="x" id="clip">—</div></div>
      <div class="tile"><div class="k">Батарея</div><div class="x" id="bat">—</div></div>
      <div class="tile"><div class="k">GPS</div><div class="x" id="gps">—</div></div>
    </div>
    <h3>Повідомлення</h3>
    <div id="msgs"><div class="t">Поки немає</div></div>
    <div style="height:16px"></div>
    </div>
  </section>

  <section id="tab-par" hidden>
    <div id="list"></div>
  </section>
</main>

<nav>
  <button id="tbFly" class="on"><svg viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2"><circle cx="12" cy="12" r="9"/><path d="M3 13h5l2-2h4l2 2h5"/></svg>Політ</button>
  <button id="tbPar"><svg viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2"><path d="M4 6h16M4 12h16M4 18h10"/></svg>Параметри</button>
</nav>

<div id="back"></div>

<div class="sheet" id="editSheet">
  <h2 id="eName"></h2>
  <div class="sub" id="eSub"></div>
  <div class="row">
    <button id="eNeg" title="Змінити знак">±</button>
    <input type="text" id="eVal" inputmode="decimal" autocomplete="off" spellcheck="false">
  </div>
  <div class="btns"><button id="eCancel">Скасувати</button><button class="pri" id="eWrite">Записати</button></div>
</div>

<div class="sheet menu" id="menuSheet">
  <button id="mSave">💾 Зберегти параметри у файл</button>
  <button id="mLoad">📂 Завантажити параметри з файлу</button>
  <button id="mReboot" class="danger">⟳ Перезавантажити польотний контролер</button>
  <button id="mHelp">ℹ️ Як підключити</button>
  <button id="mClose">Закрити</button>
  <input type="file" id="fileIn" accept=".param,.parm,.params,.txt,text/plain" hidden>
</div>

<div class="sheet" id="diffSheet">
  <h2 style="font-family:inherit">Відмінності з файлу</h2>
  <div class="sub" id="dSub"></div>
  <div id="dList"></div>
  <div class="btns"><button id="dCancel">Скасувати</button><button class="pri" id="dWrite">Записати</button></div>
</div>

<div class="sheet" id="helpSheet">
  <h2 style="font-family:inherit">Підключення</h2>
  <div class="help">
    <b>USB (Android-планшет або ПК):</b> польотник з'єднується OTG-кабелем, далі натисни «🔌 USB» і вибери плату. Налаштовувати нічого не потрібно, USB у ArduPilot працює як MAVLink за замовчуванням. Якщо порт зайнятий, закрий QGroundControl або Mission Planner.<br><br>
    <b>Через ESP32 (iPhone):</b><br>
    1. ESP32 з'єднаний з UART польотника: TX↔RX, RX↔TX, GND↔GND.<br>
    2. На польотнику для цього порту: <code>SERIALx_PROTOCOL = 2</code>, <code>SERIALx_BAUD = 115</code>.<br>
    3. Телефон підключений до WiFi <code>ArduParam</code>, сторінка <code>http://192.168.4.1</code>.<br>
    4. Жовта точка означає, що ESP32 на зв'язку, але польотник не відповідає: перевір дроти, TX/RX і номер SERIAL.<br><br>
    Додай сторінку на екран «Додому»: Safari → Поділитися → «На початковий екран».
  </div>
  <div class="btns"><button id="hClose">Закрити</button></div>
</div>

<div id="toasts"></div>

<div id="splash">
  <img class="bg" src="data:image/jpeg;base64,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" alt="">
  <img class="fg" alt="">
  <script>document.querySelector('#splash .fg').src = document.querySelector('#splash .bg').src;</script>
  <div class="sbot">
    <div id="sst"><span class="dot" id="sdot"></span><span id="stx">Очікування борту…</span></div>
    <button id="sUsb" class="pri" hidden>🔌 Підключити USB</button>
    <button id="sSkip">Відкрити без борту</button>
  </div>
</div>

<script>
'use strict';
const DEMO = /[?&]demo/.test(location.search) || location.protocol === 'file:';
const $ = s => document.querySelector(s);
const sleep = ms => new Promise(r => setTimeout(r, ms));
const esc = s => String(s).replace(/[&<>"]/g, c => ({'&':'&amp;','<':'&lt;','>':'&gt;','"':'&quot;'}[c]));

/* ================= MAVLink ================= */
// id: [crc_extra, мінімальна довжина payload]
const MSG = {0:[50,9],1:[124,31],20:[214,20],21:[159,2],22:[220,25],23:[168,23],24:[24,30],27:[144,26],
             30:[39,28],74:[20,20],76:[152,33],77:[143,3],241:[90,32],253:[83,51]};
function crcAcc(b, c){ let t = (b ^ (c & 0xff)) & 0xff; t = (t ^ (t << 4)) & 0xff; return ((c >> 8) ^ (t << 8) ^ (t << 3) ^ (t >> 4)) & 0xffff; }
function encode(id, payload, sys, comp, seqObj){
  const len = payload.length, f = new Uint8Array(12 + len);
  f[0]=0xFD; f[1]=len; f[2]=0; f[3]=0; f[4]=(seqObj.v++) & 255; f[5]=sys; f[6]=comp;
  f[7]=id & 255; f[8]=(id >> 8) & 255; f[9]=(id >> 16) & 255; f.set(payload, 10);
  let c = 0xffff; for (let k = 1; k < 10 + len; k++) c = crcAcc(f[k], c); c = crcAcc(MSG[id][0], c);
  f[10+len] = c & 255; f[11+len] = c >> 8; return f;
}
function makeParser(onMsg){
  let buf = new Uint8Array(0);
  return function feed(chunk){
    const nb = new Uint8Array(buf.length + chunk.length); nb.set(buf); nb.set(chunk, buf.length); buf = nb;
    let i = 0;
    while (i < buf.length){
      const s = buf[i];
      if (s !== 0xFD && s !== 0xFE){ i++; continue; }
      const v2 = s === 0xFD, hl = v2 ? 10 : 6;
      if (buf.length - i < hl) break;
      const len = buf[i+1], sig = (v2 && (buf[i+2] & 1)) ? 13 : 0, tot = hl + len + 2 + sig;
      if (buf.length - i < tot) break;
      let sys, comp, id;
      if (v2){ sys=buf[i+5]; comp=buf[i+6]; id=buf[i+7] | (buf[i+8] << 8) | (buf[i+9] << 16); }
      else   { sys=buf[i+3]; comp=buf[i+4]; id=buf[i+5]; }
      const m = MSG[id];
      if (!m){ i++; continue; }
      let c = 0xffff; for (let k = i+1; k < i+hl+len; k++) c = crcAcc(buf[k], c); c = crcAcc(m[0], c);
      const p = i + hl + len;
      if (c !== (buf[p] | (buf[p+1] << 8))){ i++; continue; }
      const pl = new Uint8Array(Math.max(len, m[1])); pl.set(buf.subarray(i+hl, i+hl+len));
      try { onMsg(id, sys, comp, new DataView(pl.buffer)); } catch(e){ console.error(e); }
      i += tot;
    }
    buf = buf.slice(i);
  };
}
const mk = n => { const u = new Uint8Array(n); return [u, new DataView(u.buffer)]; };
function putStr(u, off, s, max){ for (let k = 0; k < max && k < s.length; k++) u[off+k] = s.charCodeAt(k) & 255; }
function getStr(d, off, max){ let s=''; for (let k=0;k<max;k++){ const c=d.getUint8(off+k); if(!c) break; s+=String.fromCharCode(c);} return s; }

/* ================= State ================= */
const MY_SYS = 255, MY_COMP = 190, gcsSeq = {v:0};
let tgtSys = 0, tgtComp = 1, vehType = 0, baseMode = 0, customMode = 0, lastHb = 0, wasConnected = false;
// Режим ESP32: сторінку віддає сама ESP32 по http. Інакше (https / localhost) працюємо через USB.
const ESP_MODE = !DEMO && location.protocol === 'http:' && location.hostname !== 'localhost' && location.hostname !== '127.0.0.1';
let espOk = false, lastEsp = 0, usb = null, usbChain = Promise.resolve();
const linkOk = () => DEMO || (ESP_MODE ? Date.now() - lastEsp < 3000 : !!usb);
const params = new Map();   // name -> {v,t,i}
let pCount = 0, loading = false, lastPV = 0;
const gotIdx = new Set(), changed = new Set(), waiters = new Map();
const tel = {att:null, attT:0, imu:null, vib:null, bat:null, gps:null, hud:null};
const msgs = [];

let txq = [], mock = null;
function tx(id, payload){
  const f = encode(id, payload, MY_SYS, MY_COMP, gcsSeq);
  if (DEMO) setTimeout(() => mock.rx(f), 2);
  else if (ESP_MODE) txq.push(f);
  else if (usb){ const l = usb; usbChain = usbChain.then(() => l.write(f)).catch(() => {}); }
}
const feed = makeParser(handle);

function sendHeartbeat(){ const [u] = mk(9); u[4]=6; u[5]=8; u[7]=4; u[8]=3; tx(0, u); }
function reqList(){ const [u] = mk(2); u[0]=tgtSys; u[1]=tgtComp; tx(21, u); }
function reqRead(idx){ const [u,d] = mk(20); d.setInt16(0, idx, true); u[2]=tgtSys; u[3]=tgtComp; tx(20, u); }
function paramSet(name, val, type){ const [u,d] = mk(23); d.setFloat32(0, val, true); u[4]=tgtSys; u[5]=tgtComp; putStr(u, 6, name, 16); u[22]=type; tx(23, u); }
function cmdLong(cmd, p1=0, p2=0){ const [u,d] = mk(33); d.setFloat32(0,p1,true); d.setFloat32(4,p2,true); d.setUint16(28,cmd,true); u[30]=tgtSys; u[31]=tgtComp; tx(76, u); }
function requestStreams(){
  // MAV_CMD_SET_MESSAGE_INTERVAL: id, інтервал у мкс
  [[30,100000],[27,200000],[1,500000],[74,250000],[24,500000],[241,500000]].forEach(([id,us]) => cmdLong(511, id, us));
}

function handle(id, sys, comp, d){
  if (id === 0){
    const type = d.getUint8(4), ap = d.getUint8(5);
    if (ap !== 3 || type === 6) return;            // лише ArduPilot, не GCS
    if (!tgtSys){ tgtSys = sys; tgtComp = comp; }
    if (sys !== tgtSys || comp !== tgtComp) return;
    customMode = d.getUint32(0, true); vehType = type; baseMode = d.getUint8(6);
    const was = Date.now() - lastHb < 3000; lastHb = Date.now();
    if (!was){ requestStreams(); if (!params.size && !loading) setTimeout(loadAll, 300); }
    return;
  }
  if (sys !== tgtSys) return;
  switch (id){
    case 22: onParam(getStr(d,8,16), d.getFloat32(0,true), d.getUint8(24), d.getUint16(6,true), d.getUint16(4,true)); break;
    case 30: tel.att = {r:d.getFloat32(4,true), p:d.getFloat32(8,true), y:d.getFloat32(12,true)}; tel.attT = Date.now(); hudDirty = true; break;
    case 27: tel.imu = {ax:d.getInt16(8,true), ay:d.getInt16(10,true), az:d.getInt16(12,true), gx:d.getInt16(14,true), gy:d.getInt16(16,true), gz:d.getInt16(18,true), t:Date.now()}; break;
    case 241: tel.vib = {x:d.getFloat32(8,true), y:d.getFloat32(12,true), z:d.getFloat32(16,true), c:[d.getUint32(20,true),d.getUint32(24,true),d.getUint32(28,true)], t:Date.now()}; break;
    case 1: tel.bat = {v:d.getUint16(14,true), a:d.getInt16(16,true), pct:d.getInt8(30), t:Date.now()}; break;
    case 24: tel.gps = {fix:d.getUint8(28), sats:d.getUint8(29), t:Date.now()}; break;
    case 74: tel.hud = {alt:d.getFloat32(8,true), gs:d.getFloat32(4,true), hdg:d.getInt16(16,true), thr:d.getUint16(18,true), t:Date.now()}; break;
    case 253: addMsg(d.getUint8(0), getStr(d,1,50)); break;
  }
}

/* ================= Params ================= */
function onParam(name, v, t, idx, count){
  if (!name) return;
  if (count) pCount = count;
  params.set(name, {v, t, i: idx});
  if (idx !== 65535) gotIdx.add(idx);
  lastPV = Date.now();
  const w = waiters.get(name); if (w) w(v);
  if (loading) setProg(pCount ? gotIdx.size / pCount : 0);
  scheduleRender();
}
function waitUntil(fn, ms){
  return new Promise(res => { const t0 = Date.now(); const iv = setInterval(() => { if (fn() || Date.now() - t0 > ms){ clearInterval(iv); res(fn()); } }, 100); });
}
async function loadAll(){
  if (loading) return;
  if (!tgtSys || Date.now() - lastHb > 3000){ toast('Польотний контролер не на зв\'язку', 'err'); return; }
  loading = true; params.clear(); gotIdx.clear(); changed.clear(); pCount = 0; updateLoadBtn(); setProg(0); render();
  for (let a = 0; a < 3 && !pCount; a++){ reqList(); lastPV = Date.now(); await waitUntil(() => pCount > 0, 3000); }
  if (!pCount){ loading = false; setProg(null); updateLoadBtn(); toast('ФК не відповідає на запит параметрів', 'err'); return; }
  for (let round = 0; round < 6; round++){
    await waitUntil(() => gotIdx.size >= pCount || Date.now() - lastPV > 1200, 90000);
    if (gotIdx.size >= pCount) break;
    const miss = []; for (let k = 0; k < pCount; k++) if (!gotIdx.has(k)) miss.push(k);
    for (let j = 0; j < miss.length; j += 10){ miss.slice(j, j + 10).forEach(reqRead); await sleep(250); }
    lastPV = Date.now();
  }
  loading = false; setProg(null); updateLoadBtn(); render();
  if (gotIdx.size >= pCount) toast(`Отримано ${params.size} параметрів`, 'ok');
  else toast(`Отримано ${gotIdx.size} з ${pCount}. Натисни «Завантажити» ще раз`, 'warn');
}
const same = (a, b) => Math.abs(a - Math.fround(b)) <= 1e-6 * Math.max(1, Math.abs(b));
function writeParam(name, val){
  const p = params.get(name);
  return new Promise(async res => {
    let got = null; waiters.set(name, v => { got = v; });
    for (let a = 0; a < 3 && got === null; a++){ paramSet(name, val, p.t); await waitUntil(() => got !== null, 1500); }
    waiters.delete(name); res(got);
  });
}
const TYPE = {1:'UINT8',2:'INT8',3:'UINT16',4:'INT16',5:'UINT32',6:'INT32',9:'FLOAT'};
const RANGE = {1:[0,255],2:[-128,127],3:[0,65535],4:[-32768,32767],5:[0,4294967295],6:[-2147483648,2147483647]};
const isInt = t => t >= 1 && t <= 8;
function fmt(v, t){
  if (isInt(t)) return String(Math.round(v));
  if (Number.isInteger(v)) return String(v);
  return String(parseFloat(v.toPrecision(6)));
}

/* ================= Transport ================= */
async function pump(){
  for (;;){
    let body = '';
    if (txq.length){ for (const f of txq) for (const b of f) body += (b < 16 ? '0' : '') + b.toString(16); txq = []; }
    const ac = new AbortController(), to = setTimeout(() => ac.abort(), 3000);
    try {
      const r = await fetch('/x', {method:'POST', body, headers:{'Content-Type':'text/plain'}, cache:'no-store', signal: ac.signal});
      const b = new Uint8Array(await r.arrayBuffer()); clearTimeout(to);
      espOk = true; lastEsp = Date.now();
      if (b.length) feed(b);
      if (b.length < 1024 && !txq.length) await sleep(40);
    } catch(e){ clearTimeout(to); espOk = false; await sleep(800); }
  }
}

/* ================= USB (Android: WebUSB, ПК: Web Serial) ================= */
const isAndroid = /Android/i.test(navigator.userAgent);
const preferUsb = 'usb' in navigator && (isAndroid || !('serial' in navigator));
async function openWebUsb(dev){
  await dev.open();
  if (!dev.configuration) await dev.selectConfiguration(1);
  let commIf, dataIf, epIn, epOut;
  for (const itf of dev.configuration.interfaces){
    const alt = itf.alternates[0];
    if (alt.interfaceClass === 2 && commIf === undefined) commIf = itf.interfaceNumber;
    if (alt.interfaceClass === 10 && dataIf === undefined){
      dataIf = itf.interfaceNumber;
      for (const ep of alt.endpoints) if (ep.type === 'bulk'){ if (ep.direction === 'in') epIn = ep.endpointNumber; else epOut = ep.endpointNumber; }
    }
  }
  if (dataIf === undefined || epIn === undefined || epOut === undefined){ dev.close().catch(() => {}); throw new Error('Це не польотний контролер (немає USB-serial)'); }
  await dev.claimInterface(dataIf);
  if (commIf !== undefined){
    try { await dev.claimInterface(commIf); } catch(e){}
    try { await dev.controlTransferOut({requestType:'class', recipient:'interface', request:0x22, value:0x03, index:commIf}); } catch(e){}  // DTR+RTS
  }
  const link = {dev, write: u => dev.transferOut(epOut, u), close: () => dev.close().catch(() => {})};
  setLink(link);
  (async () => {
    try {
      while (usb === link){
        const r = await dev.transferIn(epIn, 4096);
        if (r.data && r.data.byteLength) feed(new Uint8Array(r.data.buffer, r.data.byteOffset, r.data.byteLength));
      }
    } catch(e){ if (usb === link) dropLink('USB від\'єднано'); }
  })();
}
async function openSerial(port){
  await port.open({baudRate: 115200});
  const writer = port.writable.getWriter(), reader = port.readable.getReader();
  const link = {port, write: u => writer.write(u), close: async () => {
    try { await reader.cancel(); } catch(e){} try { writer.releaseLock(); } catch(e){} try { await port.close(); } catch(e){} }};
  setLink(link);
  (async () => {
    try { for (;;){ const {value, done} = await reader.read(); if (done) break; if (value) feed(value); } } catch(e){}
    if (usb === link) dropLink('USB від\'єднано');
  })();
}
function setLink(l){ usb = l; usbChain = Promise.resolve(); lastHb = 0; tgtSys = 0; updateUsbBtn(); toast('USB підключено', 'ok'); }
function dropLink(msg){ const l = usb; usb = null; if (l) l.close(); updateUsbBtn(); if (msg) toast(msg, 'warn'); }
function usbErr(e){
  const m = String(e && e.message || e);
  if (/claim|busy|Unable|Access denied/i.test(m)) return 'USB-порт зайнятий іншою програмою (QGC, Mission Planner). Закрий її та спробуй ще';
  return 'USB: ' + m;
}
async function connectUsb(){
  if (usb){ dropLink('USB відключено'); return; }
  try {
    if (preferUsb) await openWebUsb(await navigator.usb.requestDevice({filters: []}));
    else if ('serial' in navigator) await openSerial(await navigator.serial.requestPort());
    else toast('Цей браузер не підтримує USB. Відкрий у Chrome (через https)', 'err');
  } catch(e){ if (e && e.name !== 'NotFoundError') toast(usbErr(e), 'err'); }
}
async function autoUsb(){
  if (usb) return;
  try {
    if (preferUsb){ const ds = await navigator.usb.getDevices(); if (ds.length) await openWebUsb(ds[0]); }
    else if ('serial' in navigator){ const ps = await navigator.serial.getPorts(); if (ps.length) await openSerial(ps[0]); }
  } catch(e){}
}
function initUsb(){
  if (preferUsb){
    navigator.usb.addEventListener('connect', () => setTimeout(autoUsb, 500));
    navigator.usb.addEventListener('disconnect', e => { if (usb && usb.dev === e.device) dropLink('USB від\'єднано'); });
  } else if ('serial' in navigator){
    navigator.serial.addEventListener('connect', () => setTimeout(autoUsb, 500));
  }
  autoUsb();
}
function updateUsbBtn(){
  const b = $('#usbBtn'); if (ESP_MODE || DEMO){ b.hidden = true; return; }
  b.hidden = false; b.textContent = usb ? '⏏ USB' : '🔌 USB'; b.classList.toggle('pri', !usb);
}
$('#usbBtn').onclick = connectUsb;

/* ================= UI: status ================= */
const COPTER = {0:'STABILIZE',1:'ACRO',2:'ALT_HOLD',3:'AUTO',4:'GUIDED',5:'LOITER',6:'RTL',7:'CIRCLE',9:'LAND',11:'DRIFT',13:'SPORT',14:'FLIP',15:'AUTOTUNE',16:'POSHOLD',17:'BRAKE',18:'THROW',20:'GUIDED_NOGPS',21:'SMART_RTL',22:'FLOWHOLD',23:'FOLLOW',24:'ZIGZAG',25:'SYSTEMID',26:'AUTOROTATE',27:'AUTO_RTL',28:'TURTLE'};
const PLANE = {0:'MANUAL',1:'CIRCLE',2:'STABILIZE',3:'TRAINING',4:'ACRO',5:'FBWA',6:'FBWB',7:'CRUISE',8:'AUTOTUNE',10:'AUTO',11:'RTL',12:'LOITER',13:'TAKEOFF',15:'GUIDED',17:'QSTABILIZE',18:'QHOVER',19:'QLOITER',20:'QLAND',21:'QRTL',22:'QAUTOTUNE',23:'QACRO',24:'THERMAL'};
const ROVER = {0:'MANUAL',1:'ACRO',3:'STEERING',4:'HOLD',5:'LOITER',6:'FOLLOW',7:'SIMPLE',10:'AUTO',11:'RTL',12:'SMART_RTL',15:'GUIDED'};
function vehKind(){ if ([1,19,20,21,22,23,24,25].includes(vehType)) return 'Plane'; if ([10,11].includes(vehType)) return 'Rover'; if (vehType===12) return 'Sub'; return 'Copter'; }
function modeName(){ const k = vehKind(); const tbl = k==='Plane'?PLANE:k==='Rover'?ROVER:COPTER; return tbl[customMode] || ('MODE ' + customMode); }
const fcOk = () => Date.now() - lastHb < 3000;
const armed = () => (baseMode & 128) !== 0;
function updateStatus(){
  const dot = $('#dot'), st = $('#st');
  if (!linkOk()){ dot.className = 'dot'; st.textContent = ESP_MODE ? 'Немає зв\'язку з ESP32. Перевір WiFi «ArduParam»' : 'USB не підключено. Натисни «USB»'; }
  else if (!fcOk()){ dot.className = 'dot half'; st.textContent = (ESP_MODE ? 'ESP32' : 'USB') + ' є, польотник не відповідає'; }
  else { dot.className = 'dot on'; st.textContent = `${DEMO?'ДЕМО · ':''}${vehKind()} · ${modeName()} · ${armed()?'ARMED':'disarmed'}`; }
  if (fcOk() !== wasConnected){ wasConnected = fcOk(); updateLoadBtn(); }
  updateSplash();
}

/* ================= Заставка: поки борт не підключений ================= */
let splashOn = true, splashSkip = false;
function updateSplash(){
  if (fcOk()) splashSkip = false;          // після підключення заставка знову з'явиться при втраті зв'язку
  const want = !fcOk() && !splashSkip;
  if (want !== splashOn){
    splashOn = want;
    $('#splash').classList.toggle('off', !want);
    if (!want && fcOk()) setTab('fly');    // борт підключився: одразу сторінка польоту
  }
  $('#sdot').className = $('#dot').className;
  $('#stx').textContent = $('#st').textContent;
  $('#sUsb').hidden = ESP_MODE || DEMO || !!usb;
}
$('#sUsb').onclick = connectUsb;
$('#sSkip').onclick = () => { splashSkip = true; updateSplash(); };
function updateLoadBtn(){ const b = $('#loadBtn'); b.disabled = loading || !fcOk(); b.textContent = loading ? 'Йде…' : 'Завантажити'; }
function setProg(f){ const p = $('#prog'); if (f === null){ p.style.display='none'; return; } p.style.display='block'; p.firstElementChild.style.width = Math.round(f*100) + '%'; }

/* ================= UI: params list ================= */
let modOnly = false, renderT = 0;
function scheduleRender(){ if (renderT) return; renderT = setTimeout(() => { renderT = 0; render(); }, loading ? 500 : 60); }
function render(){
  if ($('#tab-par').hidden){ updateCount(null); return; }
  const terms = $('#q').value.trim().toUpperCase().split(/\s+/).filter(Boolean);
  const names = [...params.keys()].sort();
  let h = '', n = 0;
  for (const nm of names){
    if (terms.length && !terms.every(t => nm.includes(t))) continue;
    if (modOnly && !changed.has(nm)) continue;
    const p = params.get(nm);
    let disp = esc(nm);
    if (terms[0]){ const k = nm.indexOf(terms[0]); disp = esc(nm.slice(0,k)) + '<b>' + esc(terms[0]) + '</b>' + esc(nm.slice(k + terms[0].length)); }
    h += `<div class="p${changed.has(nm)?' mod':''}" data-n="${esc(nm)}"><span class="n">${disp}</span><span class="v">${fmt(p.v,p.t)}</span></div>`;
    n++;
  }
  if (!h){
    h = `<div class="empty">${params.size ? 'Нічого не знайдено' : loading ? 'Завантаження параметрів…' : 'Параметри ще не завантажені.<br>Натисни «Завантажити».'}</div>`;
  }
  $('#list').innerHTML = h;
  updateCount(n);
}
let shownN = null;
function updateCount(n){
  if (n === null) n = shownN; else shownN = n;
  const total = pCount ? `${params.size} / ${pCount}` : `${params.size}`;
  $('#cnt').textContent = `Параметрів: ${total}` + (n !== null && n !== params.size ? ` · показано ${n}` : '') + (changed.size ? ` · змінено ${changed.size}` : '');
}
$('#q').addEventListener('input', scheduleRender);
$('#modBtn').onclick = () => { modOnly = !modOnly; $('#modBtn').classList.toggle('on', modOnly); render(); };
$('#loadBtn').onclick = loadAll;

/* ================= Sheets ================= */
let openSheet = null;
function show(el){ hide(); openSheet = el; el.classList.add('show'); $('#back').classList.add('show'); }
function hide(){ if (openSheet) openSheet.classList.remove('show'); openSheet = null; $('#back').classList.remove('show'); }
$('#back').onclick = hide;

let editName = null;
$('#list').addEventListener('click', e => {
  const row = e.target.closest('.p'); if (!row) return;
  editName = row.dataset.n; const p = params.get(editName);
  $('#eName').textContent = editName;
  $('#eSub').textContent = `Тип: ${TYPE[p.t] || p.t} · Зараз: ${fmt(p.v, p.t)}`;
  $('#eVal').value = fmt(p.v, p.t);
  $('#eWrite').disabled = false; $('#eWrite').textContent = 'Записати';
  show($('#editSheet'));
  setTimeout(() => { $('#eVal').focus(); $('#eVal').select(); }, 50);
});
$('#eCancel').onclick = hide;
$('#eNeg').onclick = () => { const i = $('#eVal'); const s = i.value.trim(); i.value = s.startsWith('-') ? s.slice(1) : '-' + s; i.focus(); };
$('#eVal').addEventListener('keydown', e => { if (e.key === 'Enter') $('#eWrite').click(); });
$('#eWrite').onclick = async () => {
  const p = params.get(editName); if (!p) return;
  const s = $('#eVal').value.trim().replace(',', '.'); const v = Number(s);
  if (s === '' || !isFinite(v)){ toast('Введи число', 'err'); return; }
  if (isInt(p.t)){
    if (!Number.isInteger(v)){ toast('Цей параметр приймає лише ціле число', 'err'); return; }
    const [lo, hi] = RANGE[p.t]; if (v < lo || v > hi){ toast(`Допустимо від ${lo} до ${hi}`, 'err'); return; }
  }
  if (!fcOk()){ toast('Польотник не на зв\'язку', 'err'); return; }
  const b = $('#eWrite'); b.disabled = true; b.textContent = 'Запис…';
  const name = editName, r = await writeParam(name, v);
  b.disabled = false; b.textContent = 'Записати';
  if (r === null){ toast('Немає підтвердження від ФК', 'err'); return; }
  changed.add(name); render();
  if (!same(r, v)) toast(`ФК встановив ${name} = ${fmt(r, p.t)} (не ${v})`, 'warn');
  else { toast(`${name} = ${fmt(r, p.t)} ✓`, 'ok'); hide(); }
};

$('#menuBtn').onclick = () => show($('#menuSheet'));
$('#mClose').onclick = hide;
$('#mHelp').onclick = () => show($('#helpSheet'));
$('#hClose').onclick = hide;
$('#mReboot').onclick = () => {
  if (!fcOk()){ toast('Польотник не на зв\'язку', 'err'); return; }
  if (armed()){ toast('Спочатку дизарм', 'err'); return; }
  if (!confirm('Перезавантажити польотний контролер?')) return;
  cmdLong(246, 1); hide(); toast('Перезавантаження… Після нього натисни «Завантажити»', 'warn');
  params.clear(); pCount = 0; changed.clear(); render();
};
$('#mSave').onclick = () => {
  if (!params.size){ toast('Спершу завантаж параметри', 'err'); return; }
  const d = new Date(), pad = x => String(x).padStart(2, '0');
  const stamp = `${d.getFullYear()}-${pad(d.getMonth()+1)}-${pad(d.getDate())}_${pad(d.getHours())}${pad(d.getMinutes())}`;
  let s = `# ArduParam ${d.toISOString()}\n`;
  for (const nm of [...params.keys()].sort()){ const p = params.get(nm); s += `${nm},${isInt(p.t) ? Math.round(p.v) : parseFloat(p.v.toPrecision(8))}\n`; }
  const a = document.createElement('a'); a.href = URL.createObjectURL(new Blob([s], {type:'text/plain'}));
  a.download = `params_${stamp}.param`; document.body.appendChild(a); a.click(); a.remove();
  hide(); toast('Файл збережено', 'ok');
};
$('#mLoad').onclick = () => { if (!params.size){ toast('Спершу завантаж параметри з ФК', 'err'); return; } $('#fileIn').value = ''; $('#fileIn').click(); };

// калібрування та службові параметри за замовчуванням не відмічаємо
const CAL_RE = /^(STAT_|FORMAT_VERSION|SYSID_SW|INS_.*(OFFS|SCAL|_ID|TCAL)|COMPASS_.*(OFS|DIA|ODI|MOT|_ID|SCALE|DEV_ID)|BARO.*(GND|_DEVID)|GND_ABS_PRESS|AHRS_TRIM)/;
let diffRows = [];
$('#fileIn').onchange = async e => {
  const f = e.target.files[0]; if (!f) return;
  const text = await f.text(); const rows = []; let missing = 0;
  for (const line of text.split(/\r?\n/)){
    const l = line.trim(); if (!l || l[0] === '#') continue;
    const parts = l.split(/[\s,]+/); let nm, val;
    if (parts.length >= 4 && /^\d+$/.test(parts[0]) && /^\d+$/.test(parts[1])){ nm = parts[2]; val = parts[3]; }
    else { nm = parts[0]; val = parts[1]; }
    let v = Number(val); if (!nm || !isFinite(v)) continue;
    const p = params.get(nm); if (!p){ missing++; continue; }
    if (isInt(p.t)) v = Math.round(v);
    if (same(p.v, v)) continue;
    rows.push({nm, old: p.v, v, t: p.t, on: !CAL_RE.test(nm)});
  }
  diffRows = rows;
  $('#dSub').textContent = rows.length ? `Відрізняється: ${rows.length}` + (missing ? ` · немає на ФК: ${missing}` : '') + '. Калібрування не відмічені.' : 'Усі параметри з файлу вже такі самі.';
  $('#dList').innerHTML = rows.map((r, k) => `<label class="dif"><input type="checkbox" data-k="${k}"${r.on?' checked':''}><span class="n">${esc(r.nm)}</span><span class="ch">${fmt(r.old,r.t)} → <b>${fmt(r.v,r.t)}</b></span></label>`).join('');
  $('#dWrite').disabled = !rows.length; $('#dWrite').textContent = 'Записати';
  show($('#diffSheet'));
};
$('#dList').addEventListener('change', e => { const k = e.target.dataset.k; if (k !== undefined) diffRows[k].on = e.target.checked; });
$('#dCancel').onclick = hide;
$('#dWrite').onclick = async () => {
  const sel = diffRows.filter(r => r.on); if (!sel.length) return;
  if (!fcOk()){ toast('Польотник не на зв\'язку', 'err'); return; }
  const b = $('#dWrite'); b.disabled = true; let ok = 0, bad = [];
  for (let k = 0; k < sel.length; k++){
    b.textContent = `Запис ${k+1}/${sel.length}…`;
    const r = await writeParam(sel[k].nm, sel[k].v);
    if (r !== null && same(r, sel[k].v)){ ok++; changed.add(sel[k].nm); } else bad.push(sel[k].nm);
  }
  hide(); render();
  toast(bad.length ? `Записано ${ok}, помилки: ${bad.slice(0,5).join(', ')}${bad.length>5?'…':''}` : `Записано ${ok} параметрів ✓`, bad.length ? 'warn' : 'ok');
};

function toast(text, kind = ''){
  const el = document.createElement('div'); el.className = 'toast ' + kind; el.textContent = text;
  $('#toasts').appendChild(el); setTimeout(() => el.remove(), kind === 'err' ? 5000 : 3000);
}
function addMsg(sev, text){
  const d = new Date(); msgs.unshift({sev, text, t: d.toTimeString().slice(0, 8)}); if (msgs.length > 50) msgs.pop();
  $('#msgs').innerHTML = msgs.map(m => `<div class="s${m.sev}"><span class="t">${m.t}</span>${esc(m.text)}</div>`).join('');
  if (sev <= 3) toast(text, 'err');
}

/* ================= Tabs ================= */
function setTab(t){
  const fly = t === 'fly';
  $('#tab-fly').hidden = !fly; $('#tab-par').hidden = fly; $('#ptools').hidden = fly;
  $('#tbFly').classList.toggle('on', fly); $('#tbPar').classList.toggle('on', !fly);
  try { localStorage.setItem('tab', t); } catch(e){}
  if (fly) hudDirty = true; else render();
  window.scrollTo(0, 0);
}
$('#tbFly').onclick = () => setTab('fly');
$('#tbPar').onclick = () => setTab('par');

/* ================= HUD ================= */
let hudDirty = true;
const D = 180 / Math.PI;
function drawHud(){
  const c = $('#hud'), dpr = window.devicePixelRatio || 1, W = c.clientWidth, H = c.clientHeight;
  if (!W || !H) return;
  if (c.width !== Math.round(W*dpr) || c.height !== Math.round(H*dpr)){ c.width = Math.round(W*dpr); c.height = Math.round(H*dpr); }
  const g = c.getContext('2d'); g.setTransform(dpr, 0, 0, dpr, 0, 0);
  const a = tel.att || {r:0, p:0, y:0}, stale = !tel.att || Date.now() - tel.attT > 2000;
  const ppd = H / 50, cx = W / 2, cy = H / 2, big = Math.hypot(W, H) * 2;
  // horizon
  g.save(); g.translate(cx, cy); g.rotate(-a.r); g.translate(0, a.p * D * ppd);
  g.fillStyle = '#2f7fd0'; g.fillRect(-big, -big, big*2, big);
  g.fillStyle = '#7a4f24'; g.fillRect(-big, 0, big*2, big);
  g.strokeStyle = '#fff'; g.lineWidth = 2; g.beginPath(); g.moveTo(-big, 0); g.lineTo(big, 0); g.stroke();
  g.fillStyle = '#fff'; g.font = '11px -apple-system,system-ui,sans-serif'; g.textBaseline = 'middle'; g.lineWidth = 1.5;
  for (let deg = -60; deg <= 60; deg += 5){
    if (!deg) continue;
    const y = -deg * ppd, w = deg % 10 === 0 ? W * 0.16 : W * 0.07;
    g.beginPath(); g.moveTo(-w/2, y); g.lineTo(w/2, y); g.stroke();
    if (deg % 10 === 0){ g.textAlign = 'right'; g.fillText(Math.abs(deg), -w/2 - 4, y); g.textAlign = 'left'; g.fillText(Math.abs(deg), w/2 + 4, y); }
  }
  g.restore();
  // roll scale (rotates), fixed pointer
  const R = Math.min(W, H) * 0.42;
  g.save(); g.translate(cx, cy); g.rotate(-a.r); g.strokeStyle = '#fff'; g.lineWidth = 2;
  g.beginPath(); g.arc(0, 0, R, (-90-60)/D, (-90+60)/D); g.stroke();
  for (const t of [-60,-45,-30,-20,-10,0,10,20,30,45,60]){
    const an = (t - 90) / D, l = (t % 30 === 0) ? 12 : 7;
    g.beginPath(); g.moveTo(Math.cos(an)*R, Math.sin(an)*R); g.lineTo(Math.cos(an)*(R-l), Math.sin(an)*(R-l)); g.stroke();
  }
  g.restore();
  g.fillStyle = '#ffd400'; g.beginPath(); g.moveTo(cx, cy - R + 2); g.lineTo(cx - 8, cy - R + 16); g.lineTo(cx + 8, cy - R + 16); g.closePath(); g.fill();
  // aircraft symbol
  g.strokeStyle = '#ffd400'; g.lineWidth = 4; g.lineCap = 'round';
  g.beginPath(); g.moveTo(cx - W*0.22, cy); g.lineTo(cx - W*0.07, cy); g.lineTo(cx - W*0.035, cy + 10); g.moveTo(cx + W*0.22, cy); g.lineTo(cx + W*0.07, cy); g.lineTo(cx + W*0.035, cy + 10); g.stroke();
  g.fillStyle = '#ffd400'; g.beginPath(); g.arc(cx, cy, 4, 0, 7); g.fill();
  // heading tape
  const hdg = ((a.y * D) % 360 + 360) % 360, tapeH = 26, ppdH = W / 90;
  g.fillStyle = 'rgba(0,0,0,.45)'; g.fillRect(0, 0, W, tapeH);
  g.save(); g.beginPath(); g.rect(0, 0, W, tapeH); g.clip();
  g.strokeStyle = '#fff'; g.fillStyle = '#fff'; g.lineWidth = 1; g.textAlign = 'center'; g.textBaseline = 'middle'; g.font = '11px -apple-system,system-ui,sans-serif';
  for (let h = Math.floor((hdg - 50) / 5) * 5; h <= hdg + 50; h += 5){
    const x = cx + (h - hdg) * ppdH, hh = ((h % 360) + 360) % 360;
    g.beginPath(); g.moveTo(x, tapeH); g.lineTo(x, tapeH - (hh % 10 === 0 ? 7 : 4)); g.stroke();
    if (hh % 30 === 0){ const lbl = {0:'N',90:'E',180:'S',270:'W'}[hh]; g.fillText(lbl || hh, x, 9); }
  }
  g.restore();
  g.fillStyle = '#000'; g.fillRect(cx - 22, 0, 44, tapeH); g.strokeStyle = '#ffd400'; g.lineWidth = 1.5; g.strokeRect(cx - 22, 0.75, 44, tapeH - 1.5);
  g.fillStyle = '#fff'; g.font = 'bold 13px ui-monospace,Menlo,monospace'; g.fillText(String(Math.round(hdg) % 360).padStart(3, '0'), cx, tapeH/2 + 1);
  // text overlays
  const shadow = (txt, x, y, align, color = '#fff', font = 'bold 14px -apple-system,system-ui,sans-serif') => {
    g.font = font; g.textAlign = align; g.textBaseline = 'alphabetic'; g.fillStyle = 'rgba(0,0,0,.7)'; g.fillText(txt, x + 1, y + 1); g.fillStyle = color; g.fillText(txt, x, y);
  };
  if (fcOk()){
    shadow(modeName(), 10, tapeH + 20, 'left');
    shadow(armed() ? 'ARMED' : 'DISARMED', W - 10, tapeH + 20, 'right', armed() ? '#ff5a5a' : '#2fbf71');
  }
  const b = tel.bat; if (b && b.v !== 65535) shadow(`${(b.v/1000).toFixed(1)} V` + (b.a >= 0 ? `  ${(b.a/100).toFixed(1)} A` : '') + (b.pct >= 0 ? `  ${b.pct}%` : ''), 10, H - 10, 'left');
  const gp = tel.gps; if (gp) shadow(`GPS ${['Немає','Немає','2D','3D','DGPS','RTK float','RTK fix'][gp.fix] || gp.fix} · ${gp.sats} сат`, W - 10, H - 10, 'right', gp.fix >= 3 ? '#fff' : '#f0a020');
  const hd = tel.hud; if (hd){ shadow(`Alt ${hd.alt.toFixed(1)} m`, W - 10, cy - 8, 'right', '#fff', 'bold 13px ui-monospace,Menlo,monospace'); shadow(`GS ${hd.gs.toFixed(1)} m/s`, 10, cy - 8, 'left', '#fff', 'bold 13px ui-monospace,Menlo,monospace'); }
  if (stale){
    g.fillStyle = 'rgba(0,0,0,.55)'; g.fillRect(0, 0, W, H);
    shadow(fcOk() ? 'Немає даних положення' : 'Немає зв\'язку', cx, cy + 5, 'center', '#fff', 'bold 16px -apple-system,system-ui,sans-serif');
  }
}
function setTile(id, v, digits, span){
  const el = $('#' + id); el.textContent = v === null ? '—' : (v >= 0 ? '+' : '') + v.toFixed(digits);
  const bar = $('#' + id + 'b'); if (!bar) return;
  if (v === null){ bar.style.width = '0'; return; }
  const f = Math.max(-1, Math.min(1, v / span)), w = Math.abs(f) * 50;
  bar.style.left = (f >= 0 ? 50 : 50 - w) + '%'; bar.style.width = w + '%';
}
function setVibe(id, v){
  const el = $('#' + id), bar = $('#' + id + 'b');
  if (v === null){ el.textContent = '—'; bar.style.width = '0'; return; }
  el.textContent = v.toFixed(1); el.style.color = v > 60 ? 'var(--err)' : v > 30 ? 'var(--warn)' : '';
  bar.style.left = '0'; bar.style.width = Math.min(100, v / 90 * 100) + '%';
  bar.style.background = v > 60 ? 'var(--err)' : v > 30 ? 'var(--warn)' : 'var(--ok)';
}
function updateTiles(){
  const fresh = o => o && Date.now() - o.t < 3000;
  const im = fresh(tel.imu) ? tel.imu : null, G = 9.80665 / 1000, R2D = 0.001 * D;
  setTile('ax', im && im.ax * G, 2, 20); setTile('ay', im && im.ay * G, 2, 20); setTile('az', im && im.az * G, 2, 20);
  setTile('gx', im && im.gx * R2D, 1, 200); setTile('gy', im && im.gy * R2D, 1, 200); setTile('gz', im && im.gz * R2D, 1, 200);
  const at = tel.att && Date.now() - tel.attT < 3000 ? tel.att : null;
  $('#tr').textContent = at ? (at.r * D).toFixed(1) + '°' : '—';
  $('#tp').textContent = at ? (at.p * D).toFixed(1) + '°' : '—';
  $('#ty').textContent = at ? (((at.y * D) % 360 + 360) % 360).toFixed(0) + '°' : '—';
  const vb = fresh(tel.vib) ? tel.vib : null;
  setVibe('vx', vb && vb.x); setVibe('vy', vb && vb.y); setVibe('vz', vb && vb.z);
  $('#clip').textContent = vb ? vb.c.join(' / ') : '—';
  const b = fresh(tel.bat) ? tel.bat : null;
  $('#bat').textContent = b && b.v !== 65535 ? (b.v / 1000).toFixed(2) + ' V' : '—';
  const gp = fresh(tel.gps) ? tel.gps : null;
  $('#gps').textContent = gp ? `${gp.sats} сат` : '—';
}
function frame(){
  if (!$('#tab-fly').hidden && (hudDirty || !tel.att || Date.now() - tel.attT > 2000)){ hudDirty = false; drawHud(); }
  requestAnimationFrame(frame);
}
window.addEventListener('resize', () => hudDirty = true);

/* ================= Demo FC (?demo) ================= */
function makeMock(deliver){
  const P = [];
  const add = (n, v, t) => P.push({n, v, t});
  [['ACRO_YAW_P',4.5,9],['ANGLE_MAX',3000,4],['ARMING_CHECK',1,6],['ATC_ACCEL_P_MAX',110000,9],['ATC_ACCEL_R_MAX',110000,9],['ATC_ANG_PIT_P',4.5,9],['ATC_ANG_RLL_P',4.5,9],['ATC_ANG_YAW_P',4.5,9],
   ['ATC_RAT_PIT_P',0.135,9],['ATC_RAT_PIT_I',0.135,9],['ATC_RAT_PIT_D',0.0036,9],['ATC_RAT_RLL_P',0.135,9],['ATC_RAT_RLL_I',0.135,9],['ATC_RAT_RLL_D',0.0036,9],['ATC_RAT_YAW_P',0.18,9],['ATC_RAT_YAW_I',0.018,9],
   ['BATT_MONITOR',4,2],['BATT_CAPACITY',1300,6],['BATT_LOW_VOLT',14.0,9],['BATT_CRT_VOLT',13.2,9],['BATT_FS_LOW_ACT',2,2],['COMPASS_OFS_X',12.5,9],['COMPASS_OFS_Y',-40.25,9],['COMPASS_OFS_Z',8,9],['COMPASS_USE',1,2],
   ['FLTMODE_CH',5,2],['FLTMODE1',0,2],['FLTMODE2',2,2],['FLTMODE3',5,2],['FLTMODE4',16,2],['FLTMODE5',6,2],['FLTMODE6',9,2],['FRAME_CLASS',1,2],['FRAME_TYPE',1,2],['FS_THR_ENABLE',1,2],['FS_THR_VALUE',975,4],
   ['INS_ACCOFFS_X',0.012,9],['INS_ACCOFFS_Y',-0.034,9],['INS_ACCOFFS_Z',0.09,9],['INS_GYRO_FILTER',20,4],['INS_ACCEL_FILTER',20,4],['INS_HNTCH_ENABLE',0,2],['LOG_BITMASK',176126,6],
   ['MOT_PWM_TYPE',6,2],['MOT_SPIN_ARM',0.1,9],['MOT_SPIN_MIN',0.15,9],['MOT_THST_HOVER',0.35,9],['MOT_BAT_VOLT_MAX',16.8,9],['MOT_BAT_VOLT_MIN',13.2,9],['OSD_TYPE',1,2],['RTL_ALT',1500,6],
   ['SERVO_BLH_AUTO',1,2],['SERVO_BLH_MASK',0,6],['SERVO_BLH_RVMASK',0,6],['SERVO_DSHOT_ESC',1,2],['SYSID_THISMAV',1,4],['VTX_ENABLE',1,2],['VTX_BAND',4,2],['VTX_CHANNEL',0,2],['VTX_FREQ',5658,4],['VTX_POWER',25,4],['VTX_MAX_POWER',800,4],['VTX_OPTIONS',0,2],
   ['WPNAV_SPEED',1000,9],['STAT_RUNTIME',123456,6],['FORMAT_VERSION',120,4]].forEach(a => add(...a));
  for (let k = 1; k <= 8; k++){ add(`RC${k}_MIN`,1000,4); add(`RC${k}_MAX`,2000,4); add(`RC${k}_TRIM`,1500,4); add(`RC${k}_OPTION`,k===6?94:0,4); add(`RC${k}_REVERSED`,0,2); }
  for (let k = 1; k <= 8; k++){ add(`SERVO${k}_FUNCTION`,k<=4?32+k:0,4); add(`SERVO${k}_MIN`,1100,4); add(`SERVO${k}_MAX`,1900,4); add(`SERVO${k}_TRIM`,1500,4); add(`SERVO${k}_REVERSED`,0,2); }
  for (let k = 0; k <= 6; k++){ add(`SERIAL${k}_PROTOCOL`,[2,2,2,5,37,-1,23][k],2); add(`SERIAL${k}_BAUD`,[115,57,57,38,4,57,115][k],6); add(`SERIAL${k}_OPTIONS`,k===4?4:0,4); }
  const seq = {v:0}; let listQ = [];
  const out = (id, u) => { const f = encode(id, u, 1, 1, seq); setTimeout(() => deliver(f), 3); };
  const pv = i => { const [u,d] = mk(25); d.setFloat32(0,P[i].v,true); d.setUint16(4,P.length,true); d.setUint16(6,i,true); putStr(u,8,P[i].n,16); u[24]=P[i].t; out(22,u); };
  const text = (sev, s) => { const [u] = mk(51); u[0]=sev; putStr(u,1,s,50); out(253,u); };
  const parse = makeParser((id, sys, comp, d) => {
    if (id === 21) listQ = P.map((_, i) => i);
    else if (id === 20){ const i = d.getInt16(0,true); if (i >= 0 && i < P.length) pv(i); }
    else if (id === 23){ const nm = getStr(d,6,16), i = P.findIndex(p => p.n === nm); if (i >= 0){ let v = d.getFloat32(0,true); if (P[i].t < 9) v = Math.round(v); P[i].v = v; pv(i); } }
    else if (id === 76 && d.getUint16(28,true) === 246) setTimeout(() => text(4, 'Rebooting (demo)'), 200);
  });
  setInterval(() => { for (let k = 0; k < 25 && listQ.length; k++){ const i = listQ.shift(); if (Math.random() > 0.03) pv(i); } }, 40);
  setInterval(() => { const [u,d] = mk(9); d.setUint32(0,0,true); u[4]=2; u[5]=3; u[6]=81; u[7]=3; u[8]=3; out(0,u); }, 1000);
  let tick = 0;
  setInterval(() => {
    const t = Date.now() / 1000, r = 0.35*Math.sin(t*0.7), p = 0.2*Math.sin(t*0.45), y = (t*0.2) % (2*Math.PI);
    { const [u,d] = mk(28); d.setFloat32(4,r,true); d.setFloat32(8,p,true); d.setFloat32(12,y,true); out(30,u); }
    if (tick % 2 === 0){ const [u,d] = mk(26); const n = () => (Math.random()-0.5)*40;
      d.setInt16(8, 1000*Math.sin(p)+n(), true); d.setInt16(10, -1000*Math.sin(r)*Math.cos(p)+n(), true); d.setInt16(12, -1000*Math.cos(r)*Math.cos(p)+n(), true);
      d.setInt16(14, 245*Math.cos(t*0.7)+n()/4, true); d.setInt16(16, 90*Math.cos(t*0.45)+n()/4, true); d.setInt16(18, 200+n()/4, true); out(27,u); }
    if (tick % 5 === 0){
      { const [u,d] = mk(31); d.setUint16(14,16420+Math.round(Math.random()*30),true); d.setInt16(16,120,true); d.setInt8(30,87); out(1,u); }
      { const [u,d] = mk(20); d.setFloat32(4,0.3,true); d.setFloat32(8,2.4,true); d.setInt16(16,Math.round(y*D),true); out(74,u); }
      { const [u] = mk(30); u[28]=3; u[29]=14; out(24,u); }
      { const [u,d] = mk(32); d.setFloat32(8,8+Math.random()*4,true); d.setFloat32(12,9+Math.random()*4,true); d.setFloat32(16,14+Math.random()*6,true); out(241,u); }
    }
    tick++;
  }, 100);
  setTimeout(() => text(6, 'ArduCopter V4.5.7 (demo)'), 1500);
  return {rx: f => parse(f)};
}

/* ================= Start ================= */
let startTab = 'fly'; try { startTab = localStorage.getItem('tab') || 'fly'; } catch(e){}
setTab(startTab === 'par' ? 'par' : 'fly');
updateLoadBtn();
updateUsbBtn();
if (DEMO) mock = makeMock(f => feed(f)); else if (ESP_MODE) pump(); else initUsb();
setInterval(() => { if (linkOk()) sendHeartbeat(); }, 1000);
if (location.protocol === 'https:'){
  const l = document.createElement('link'); l.rel = 'manifest'; l.href = 'manifest.webmanifest'; document.head.appendChild(l);
  if ('serviceWorker' in navigator) navigator.serviceWorker.register('sw.js').catch(() => {});
}
setInterval(() => { updateStatus(); updateTiles(); if (!$('#tab-par').hidden) updateCount(null); }, 300);
requestAnimationFrame(frame);
</script>
</body>
</html>
)PAGE_RAW";
