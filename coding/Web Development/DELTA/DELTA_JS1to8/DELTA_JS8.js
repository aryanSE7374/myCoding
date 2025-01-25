//DELTA_JS8

//ARRAY METHODS

let arr1 = [4,5,6,7];

let student = [
    {
        name: "aryan",
        marks: 93.8
    },
    {
        name: "aman",
        marks: 92
    },
    {
        name: "priya",
        marks: 87.8
    }
];

let print = function(el){
    console.log(el);
}

let print2els = function(a,b){
    console.log(a,b);
}

let print3els = function(a,b,c){
    console.log(a,b,c);
}

let print4els = function(a,b,c,d){
    console.log(a,b,c,d);
}

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

//#1. 
//arr.foreach(callback).....func define, arrow, pass


// arr1.forEach(print); //type1
// console.log("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*");
// arr1.forEach(print2els); //type1 --- for the other (i.e. 2nd) agument, it has passed the index of element
// console.log("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*");
// arr1.forEach(print3els); //type1 --- for another (i.e. 3rd) agument, it has passed the array itself as an argument
// console.log("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*");
// arr1.forEach(print4els); //type1 --- printing the 4th argument gives undefined as no argument is passed by forEach() method
// console.log("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*");

// /*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
// //printing arr of objects
// student.forEach(print); //type1 for objects
// console.log("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*");

// arr1.forEach(function(el){
//     console.log(el);
// }); //type2
// console.log("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*");
// arr1.forEach((el)=>{
//     console.log(el);
// });


/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

//#2. 
// map function :  same as forEach but returns the value after every element processing and stores into a new array
// let newArray = arr.map(callback); --arrow ,pass, initialize (must have a return statement)

// let arr1Double = arr1.map((el)=>{
//     return el*2;
// });
// console.log("arr1: ");
// console.log(arr1);
// console.log("arr1Double: ");
// console.log(arr1Double);
// console.log("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*");

// let arr1Copy = arr1.map(print);
// console.log("arr1Copy: ");
// console.log(arr1Copy);

// let arr1Copy2el = arr1.map(print2els);
// console.log("arr1Copy2el: ");
// console.log(arr1Copy2el);
 
// let arr1Copy3el = arr1.map(print3els);
// console.log("arr1Copy3el: ");
// console.log(arr1Copy3el);

// console.log("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*");

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

//#3. 
// let newArray = arr.filter(callback); -- function must return either true or false 
// if true : el added to newArray  // else : ignored el

// let arrEven = arr1.filter((el)=>(el%2==0));//stroes only even elements
// console.log(arrEven);

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
// #4. 
//arr.every(callback/statement); func must return either true or false 
//if for every element in the arr , the condition came out to be true , 
// it returns true , else returns false === analogous to logical AND 

// let OP1 = [2,4,6,8,10].every((el)=>(el%2==0)); // true
// let OP2 = [2,3,4,6,8,10].every((el)=>(el%2==0)); // false
// console.log(OP1);
// console.log(OP2);

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

// #5. 
//arr.some(callback/statement); func must return either true or false 
//if atleast one element in the arr satisfies the condition i.e .came out to be true , 
// it returns true , else returns false === analogous to logical OR

// let OP1 = [2,4,6,8,10].some((el)=>(el%2!=0)); // false
// let OP2 = [2,3,4,6,8,10].some((el)=>(el%2==0)); // true
// console.log(OP1);
// console.log(OP2);

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

// #6. 
//arr.reduce(reducer function with w variables (accumulator , element) ); redcuer fucntion returns updated accumulator
//eg: arr1.reduce( (res,el)=> (res+el) );

// let val1 = [1,2,3,4].reduce( (res,el) => {
//     console.log(res);
//     return res+el;
// } );
// console.log(val1);
// console.log("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*");
// let val2 = arr1.reduce( function(res2,el){
//     console.log(el , res2);
//     return res2+el;
// } )
// console.log(val2);
// console.log("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*");
// let inres = 10;

// let val3 = [1,2,3,4].reduce( (inres,el) => {
//     console.log(inres); //inres used is from function scope not from global scope
//     return inres+el;
// } );
// console.log(val3);
// console.log("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*");

// #7. 
// default parameters in JS

//#8. SPREAD CONCEPT OF ITERABLES
// any iterable object can be spreaded/expaned into space seperated elements


// console.log(arr1);  // (4) [4, 5, 6, 7]
// console.log(...arr1); // 4 5 6 7
// Math.min(1,2,3,4,5,0); // 0  // to use min function
// Math.min(arr1); // NaN
// Math.min(...arr1) // 4
// console.log("aryanshrivastav"); //aryanshrivastav
// console.log("...aryanshrivastav"); //...aryanshrivastav
// console.log(..."aryanshrivastav"); // a r y a n s h r i v a s t a v

// SPREAD over array literals
// The spread (...) syntax allows an iterable, such as an array or string, to be expanded 
// in places where zero or more arguments (for function calls) or elements (for array literals) are expected.
//


// let arr = [1,2,3,4,5];
// let newArr = [...arr];

// console.log(arr);
// console.log(newArr);
// console.log("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*");

// let chars = [..."hello"];
// console.log(chars);
// console.log("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*");

// let odd = [1,3,5,7,9];
// let even = [2,4,6,8,10];
// console.log(odd);
// console.log(even);
// let nums = [...odd , ...even];
// console.log(nums);
// console.log("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*");

// SPREAD over Object literals

// const data = {
//     email : "shriaryan01@gmail.com",
//     password : "Pooja123"
// };

// console.log(data);
// console.log("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*");

// const dataCopy = {...data , id : 123  , country : "India" }; 
// console.log(dataCopy);
// console.log("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*");

//  In an object literal, the spread syntax enumerates the properties of an object
//  and adds the key-value pairs to the object being created.

// let num1 = [1,2,3,4,5];
// let obj1 = {...num1}; // key = index , value = element
// let obj2 = {..."hello" }; // key = index , value = character
// console.log(obj1);
// console.log(obj2);
// console.log("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*");

// ARGUMENTS in JS
// arguments is an array-like object accessible inside functions
// that contains the values of the arguments passed to that function.


// function args(...agrs){
//     // arguments.push(5); //will return error -- arguments.push is not a function 
//     console.log(arguments);
// }

// console.log(args(1,2,3,4)); //Arguments(4) [1, 2, 3, 4, callee: (...), Symbol(Symbol.iterator): ƒ]
// arguments.push(5); //will produce an error


// REST in JS (...args)
// function funcname(...args){
//     return args;
// }

// function sum(...args){
//     return args.reduce( (result , el) => result+el );
// }

// function func2(...args) {
//     for (let i = 0; i < args.length; i++) {
//         console.log("you passed: " , args[i]);   
//     }
// }

// console.log(func2(1,2,3,4,5));

//example to get min value from a sequence in spreaded form to resrt form
// function min(msg, ...args) {
//     console.log("msg = " , msg);
//     return args.reduce((min, el) => {
//       if (min > el) {
//         return el;
//       } else {
//         return min;
//       }
//     });
// }
// console.log(min(1,2,3,0));
// console.log(min('aryan' , arr1));


//Destrucuturing in JS
//array
// let names = ["tony", "bruce", "steve", "peter"];
// let [winner, runnerup] = names;
// console.log(winner, runnerup); // "tony" "bruce"

// console.log("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*");

// let names2 = ["tony", "bruce", "peter", "steve", "abc", "xyz", "pyq"];

// // let winner = names[0];
// // let runnerup = names[1];
// // let secondRunnerup = names[2];

// let [winner2, runnerup2, ...others] = names2;

// console.log(winner);       // "tony"
// console.log(runnerup);     // "bruce"
// console.log(others);       // ["peter", "steve", "abc", "xyz", "pyq"]
// console.log("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*");


