// JavaScript Code
// Get the nav button and menu
const navButton = document.querySelector('.nav-button');
const navMenu = document.querySelector('.nav-menu');

// Add event listener to the nav button
navButton.addEventListener('click', () => {
    // Toggle the nav menu
    navMenu.classList.toggle('show');
});

// Get the hero slider
const heroSlider = document.querySelector('.hero-slider');

// Add event listener to the hero slider
heroSlider.addEventListener('mouseover', () => {
    // Show the next slide
    const currentSlide = heroSlider.querySelector('.hero-slide.active');
    const nextSlide = currentSlide.nextElementSibling;
    if (nextSlide) {
        currentSlide.classList.remove('active');
        nextSlide.classList.add('active');
    } else {
        const firstSlide = heroSlider.querySelector('.hero-slide');
        currentSlide.classList.remove('active');
        firstSlide.classList.add('active');
    }
});

// Initialize the hero slider
const firstSlide = heroSlider.querySelector('.hero-slide');
firstSlide.classList.add('active');

// Add event listener to the shopping cart
const shoppingCart = document.querySelector('.shopping-cart');
const cartButton = document.querySelector('.cart-button');

// Add event listener to the cart button
cartButton.addEventListener('click', () => {
    // Show the shopping cart
    shoppingCart.classList.toggle('show');
});

// Initialize the shopping cart
shoppingCart.classList.remove('show');