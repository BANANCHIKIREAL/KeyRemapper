const menuToggle = document.querySelector('[data-menu-toggle]');
const nav = document.querySelector('[data-nav]');
const header = document.querySelector('[data-header]');
const iconTrigger = document.querySelector('[data-icon-trigger]');

const closeMenu = () => {
  if (!menuToggle || !nav) return;
  menuToggle.setAttribute('aria-expanded', 'false');
  nav.classList.remove('is-open');
};

menuToggle?.addEventListener('click', () => {
  const willOpen = menuToggle.getAttribute('aria-expanded') !== 'true';
  menuToggle.setAttribute('aria-expanded', String(willOpen));
  nav?.classList.toggle('is-open', willOpen);
});

nav?.querySelectorAll('a').forEach((link) => link.addEventListener('click', closeMenu));

document.addEventListener('keydown', (event) => {
  if (event.key === 'Escape') closeMenu();
});

const setHeaderState = () => header?.classList.toggle('is-scrolled', window.scrollY > 32);
setHeaderState();
window.addEventListener('scroll', setHeaderState, { passive: true });

let releaseTimer;

const activateRemap = () => {
  window.clearTimeout(releaseTimer);
  iconTrigger?.classList.add('is-active');
};

const releaseRemap = () => {
  iconTrigger?.classList.remove('is-active');
};

const pulseRemap = () => {
  activateRemap();
  releaseTimer = window.setTimeout(releaseRemap, 520);
};

iconTrigger?.addEventListener('pointerdown', activateRemap);
iconTrigger?.addEventListener('pointerup', releaseRemap);
iconTrigger?.addEventListener('pointerleave', releaseRemap);
iconTrigger?.addEventListener('click', pulseRemap);

document.addEventListener('keydown', (event) => {
  if (event.key !== 'ArrowUp' || event.repeat) return;
  event.preventDefault();
  activateRemap();
});

document.addEventListener('keyup', (event) => {
  if (event.key === 'ArrowUp') releaseRemap();
});

const revealItems = document.querySelectorAll('.reveal');

if ('IntersectionObserver' in window && !window.matchMedia('(prefers-reduced-motion: reduce)').matches) {
  const observer = new IntersectionObserver((entries) => {
    entries.forEach((entry) => {
      if (!entry.isIntersecting) return;
      entry.target.classList.add('visible');
      observer.unobserve(entry.target);
    });
  }, { threshold: 0.12, rootMargin: '0px 0px -35px' });

  revealItems.forEach((item) => observer.observe(item));
} else {
  revealItems.forEach((item) => item.classList.add('visible'));
}
