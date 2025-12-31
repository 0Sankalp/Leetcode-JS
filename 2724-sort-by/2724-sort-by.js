// Function to sort an array based on fn output
function sortBy(arr, fn) {
    return arr.slice().sort((a, b) => fn(a) - fn(b));
}

// Example usage:

// Sample array
const arr = ['apple', 'banana', 'cherry'];

// Sample function: sort by string length
const fn = str => str.length;

// Call the function
const sortedArr = sortBy(arr, fn);

console.log(sortedArr); // Output: ['apple', 'cherry', 'banana']
