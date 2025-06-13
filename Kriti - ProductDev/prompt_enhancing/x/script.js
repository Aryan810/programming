document.querySelector('header button').addEventListener('click', function() {
    // Get the search input value
    var searchValue = document.querySelector('header input[type="search"]').value;
    
    // Log the search value to the console
    console.log(searchValue);
});

// Add event listener to the add to cart button
document.querySelector('.product-details button').addEventListener('click', function() {
    // Log a message to the console
    console.log('Product added to cart');
});

// Add event listener to the checkout button
document.querySelector('.shopping-cart button').addEventListener('click', function() {
    // Log a message to the console
    console.log('Checkout initiated');
});