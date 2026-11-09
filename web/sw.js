// Офлайн-кеш: програма відкривається в полі без інтернету
const CACHE = 'arduparam-v3';
const FILES = ['./', 'index.html', 'manifest.webmanifest', 'icon-192.png', 'icon-512.png',
               'meta/copter.json', 'meta/plane.json', 'meta/rover.json', 'meta/sub.json'];

self.addEventListener('install', e => {
  e.waitUntil(caches.open(CACHE).then(c => Promise.all(FILES.map(f =>
    fetch(f, {cache: 'no-cache'}).then(r => { if (r.ok) return c.put(f, r); }).catch(() => {})
  ))));
  self.skipWaiting();
});

self.addEventListener('activate', e => {
  e.waitUntil(caches.keys().then(ks => Promise.all(ks.filter(k => k !== CACHE).map(k => caches.delete(k)))));
  self.clients.claim();
});

// Спершу мережа без HTTP-кешу браузера (щоб одразу отримувати оновлення); без мережі береться збережене
self.addEventListener('fetch', e => {
  const req = e.request;
  if (req.method !== 'GET' || new URL(req.url).origin !== location.origin) return;
  e.respondWith(
    fetch(req.url, {cache: 'no-cache'})
      .then(r => { if (r.ok){ const copy = r.clone(); caches.open(CACHE).then(c => c.put(req, copy)); } return r; })
      .catch(() => caches.match(req, {ignoreSearch: true}).then(r => r || caches.match('index.html')))
  );
});
