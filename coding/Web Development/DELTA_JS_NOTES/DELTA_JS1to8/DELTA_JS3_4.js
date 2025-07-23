//javascript revision notes


// //strings are immutable
// const x = 'type';
// x[1] = 'a';       // Nothing happens, doesn't throw an error
// console.log(x);   // LOGS: 'type'

// string slice method
let str = "aryanshrivastav";
let newstr = str.slice(0,5); // 0,1,2,3,4
str.slice(0,9); // does not change the actual str, it only returns a new sliced string object 
console.log(str);
console.log(newstr);

//only one argument
console.log("by one argument : " , str.slice(11)); // slice(num , str.length)

// console.log(str.slice(-num)) == console.log(str.slice(str.length-num))
console.log("length : " , str.length);
console.log(str.slice(-4)); // slice(15-4)

console.log("-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*");



// str.replace method
//replaces the first appearance of a pattern in a string with another string
const paragraph = "I think Ruth's dog is cuter than your dog!";

console.log(paragraph.replace("Ruth's", 'my'));
// Expected output: "I think my dog is cuter than your dog!"


//not learned yet
// const regex = /Dog/i;
// console.log(paragraph.replace(regex, 'ferret'));
// // Expected output: "I think Ruth's ferret is cuter than your dog!"


console.log("-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*");


//Arrays
// slice method in array : copies a portion of an array
//arr.slice(start,end) : end index is exculsive
let arr = [1,2,3,4,5,6,7,8];
console.log("slice 2,5 : " , arr.slice(2,5));
console.log("slice 2 : " , arr.slice(2));
console.log( "slice -3 : " , arr.slice(-3));
//arr.slice(-num) == last se num elements 
console.log("-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*");

//array.splice(startidx , no. of elements to be deleted(optional) , item0 , item1, .... (items to be added))
//splice method returns the deleted portion of the array
let cars = ["bmw","audi","honda","maruti"];
console.log(cars.splice()); //had no impact on cars array
console.log(cars); // (4) ['bmw', 'audi', 'honda', 'maruti']
// cars
// (4) ['bmw', 'audi', 'honda', 'maruti']

console.log(cars.splice(0,1,'gwagon'));
// cars.splice(0,1,'gwagon') => ['bmw']

console.log(cars);
// cars
// (4) ['gwagon', 'audi', 'honda', 'maruti']

let newcars = cars.splice(0,1,"ferrari");
// let newcars = cars.splice(0,1,"ferrari")
// undefined

console.log(newcars);
// newcars
// ['gwagon']
console.log(cars);
// cars
// (4) ['ferrari', 'audi', 'honda', 'maruti'] 
console.log("-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*");

//arrays.sort in js
// this method sorts the array based on unicode and returns the reference to the original array, now sorted
// To memorize this, remember that (a, b) => a - b sorts numbers in ascending order.
// If omitted, the array elements are converted to strings, then sorted according to each character's Unicode code point value.

let nums = [12,324,25,2,97,54,9,43,234,7,85,4,13123];
let chars = ['d','f','u','q','g','b','z'];
console.log("nums ; " , nums);
console.log("chars : " , chars);
nums.sort();
chars.sort();
console.log("nums ; " , nums);
console.log("chars : " , chars);

//sorting the nums array using comparator function
nums.sort((a,b)=>a-b); //will sort in the ascending order
console.log(nums);
console.log("-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*");



