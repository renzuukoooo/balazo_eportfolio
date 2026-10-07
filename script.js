document.documentElement.classList.add('js');
const menuToggle = document.querySelector('.menu-toggle');
const navLinks = document.querySelector('#nav-links');

if (menuToggle && navLinks) {
  menuToggle.addEventListener('click', () => {
    const open = navLinks.classList.toggle('open');
    menuToggle.setAttribute('aria-expanded', String(open));
  });
  navLinks.querySelectorAll('a').forEach(link => link.addEventListener('click', () => {
    navLinks.classList.remove('open');
    menuToggle.setAttribute('aria-expanded', 'false');
  }));
}

const observer = new IntersectionObserver(entries => {
  entries.forEach(entry => {
    if (entry.isIntersecting) entry.target.classList.add('visible');
  });
}, {threshold: 0.12});
document.querySelectorAll('.reveal').forEach(el => observer.observe(el));

// Small interactive touch: the hero panel responds to pointer movement without adding visual clutter.
const panel = document.querySelector('.hero-panel');
if (panel && window.matchMedia('(pointer:fine)').matches) {
  panel.addEventListener('pointermove', event => {
    const r = panel.getBoundingClientRect();
    const x = ((event.clientX - r.left) / r.width - .5) * 4;
    const y = ((event.clientY - r.top) / r.height - .5) * -4;
    panel.style.transform = `perspective(900px) rotateY(${x}deg) rotateX(${y}deg)`;
  });
  panel.addEventListener('pointerleave', () => { panel.style.transform = ''; });
}
