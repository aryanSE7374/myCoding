// //DELTA JAVASCRIPT MODULE 7 CODE

// /* 
// FUNCTIONS CONCPET
// */

// let greet = function(){
//     console.log("hello");
// }
// let wish = function(){
//     console.log("good morning");
// }

// greet();


// function funcFactory(req){
//     if (req==0) {
//         return greet;
//     } else {
//         return wish;
//     }
// }

// let req = 0;
// let myfun = funcFactory(req);

// console.log("-----------------");
// myfun();


// greet = function(){ //function redifinition
//     console.log("namaste");
// }
// greet();

// console.log("-*-*-*-*-*-*--*-*-*-*-*-*-");
// // HOISTING concept
// f(); //although it is defined below but due to hoIsting , we can call it from anyhere that is from above the definition as well

// function f(){
//     console.log("hello from f function");
// }

// console.log("-*-*-*-*-*-*--*-*-*-*-*-*-");

// function fun(func , count){ // using func() will create an error
//     for (let i = 0; i < count; i++){
//         func();
//     }
// }

// fun(f, 5); // will call f 5 times

// console.log("-*-*-*-*-*-*--*-*-*-*-*-*-");

// function outer(){
//     let a = 10;
//     function inner(){
//         console.log(a);
//     }
//     inner();
// }

// outer(); // logs a i.e. : 10
// console.log("-*-*-*-*-*-*--*-*-*-*-*-*-");
// // console.log("trying to log the value of a : " , a);  // throw an error : ReferenceError: a is not defined
// // inner(); // will throw an error  : ReferenceError: inner is not defined

// //one more activity 
// function outerAct(){
//     let a = 10;
//     function innerAct(){
//         console.log(a);
//         a++;
//     }
//     innerAct();
// }

// for(let i=0 ; i<5 ; i++){
//     outerAct();
// } //logs 10 five times
// console.log("-*-*-*-*-*-*--*-*-*-*-*-*-");

// //Activity2 
// let x = 10;
// function outerAct2(){
//     function innerAct2(){
//         console.log(x);
//         x++;
//     }
//     innerAct2();
// }

// for(let i=0 ; i<5 ; i++){
//     outerAct2();
// } 
// console.log("final value of x: " , x);
// console.log("-*-*-*-*-*-*--*-*-*-*-*-*-");

// /*
// OBJECTS CONCEPT
// */

// let arr = [2,4,6,3,3,3,3,3,3,3,2,4,65,6,4,3,3];


// let obj = {  a : 1 , b : 2 , c  : 3 , null: null , 1 : 'one' , 2 : ' two' };

// const student1 = {
//     name : "aryan",
//     roll : 67
// };

// const student2 = {
//     name : "arnav",
//     roll : 68
// };

// // LIST OF OBJECTS
// // const arrayList =[student1  ,student2];

// const list = {
//     student1 , student2
//     // student1 : {l
//     //     name : "aryan",
//     //     roll : 67
//     // },
//     // student2 : {
//     //     name : "arnav",
//     //     roll : 68
//     // }
// };

// // for (x of arr) {
// //     console.log(x);
// // }
// // for (let i = 0; i < arr.length; i++) {
// //     console.log(arr[i]);

// // }
// // str = "abcsUHKJNdvcnbdIHKNcdiKJHJ";
// // str2 = "acbjdknc";
// // console.log('hello');
// // let i = 1;
// // let nums = [[1,1,1],[2,2,2],[3,3,3],[4,4,4]];
// // for(x of nums){
// //     for(e of x){
// //         console.log(e);
// //     }
// // }


// /*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

// //TRY CATCH SYNTAX
// let a = 1;
// let c = 'a';
// try {
//     console.log((a-1)**2+c+d);
//     console.log("hello");
    
// } catch (error) {
//     console.log("there's an error...");
//     console.log(error);
// }

// console.log("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*");



// //Assignment q1
// // /Write a Java Script function that returns array elements larger than a number
// // function greaterElements(arr , num){
// //     for (let i = 0; i < arr.length; i++) {
// //         if (arr[i]>num) {
// //             console.log(arr[i]);
            
// //         }
// //     }
// // }


// /*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/


// obj1.b(); // logs undefined as there's no i variable defined in the Window onject 
// // Window { /* … */ } (or the global object)
// //this keyword in arrow function explained below

// obj1.c(); // logs 10, Object { /* … */ }
// console.log("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*");



// // ARROW FUNCTION : nameless functions , no function keyword is used
// //syntax : 
// // const arrowfuncName = (arg1, arg2 , ....) => { //function body}
// // to call the arrowfunction named as arrowfuncName : arrowfuncNaeme(arg1, arg2, ....);
// //if there's a single aargument then, braces not rquired
// // eg: const cube = n => {return n*n*n};

// function print(){
//     console.log("hello!");
// };


// const printHello = () => {
//     console.log("hello!");
// }

// printHello();

// // //arrow func 2
// const sum = (a,b) => {
//     console.log(a+b);
// }

// sum(5,6);
// console.log("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*");


// //retruning value arrow func

// const cube = num => {return num*num*num;}
// console.log(cube(5));


// // implicit return function (if thrre's a single return statement)
//eg: // const impcube = num => (num*num*num);
// console.log(impcube(6));


// console.log("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*");

// /*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

// // this keyword in arrow function
// // normal functions have a scope depending on calling object i.e. the caller : this mtlb caller
// // but arrow functions have a lexical scope : wehen we have nested functions i.e. 
// // i.e. the scope of the parent, caller of the parent  
// // parent ka this = arrow function ka this

// // shraddha didi ke exaples: 
// const student = {
//     name: "aman",
//     marks: 95,
//     prop: this, // global scope
//     getName: function () {
//       console.log(this);
//       return this.name;
//     },
//     getMarks: () => {
//       console.log(this); // parent's scope -> window
//       return this.marks; // marks undefined in window
//     },

//     getInfo1: function () {
//       setTimeout(() => {
//         console.log(this); // student : scope of the parent: getInfo1 : function()  i.e student
//       }, 2000);
//     },
//     getInfo2: function () {
//       setTimeout(function () {
//         console.log(this); // window as setTimeout() is being called by window object
//       }, 2000);
//     },
// };




// const human = {
//     Name: "aryan",
//     age: 18,
//     getName : function() {
//         console.log(this); //human
//         console.log(this.Name); //'aryan' 
//     },
//     getAge : () => {
//         console.log(this); // window i.e. default this : scope fo the parent bcz arrow function has lexical scope
//         console.log(this.age); //undefined in Window object
//     }
// };



// human.getName();
// human.getAge();

//example2 
// //this in ARROW FUNCTION

// // "use strict";
// const i = 5;
// const obj1 = {
//   i: 10,
//   b: () => console.log(this.i),
//   c() {
//     console.log(this.i);
//   },
// };


// console.log("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*");   



/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

// setTimeout

// console.log("  hello");


// setTimeout(callback function (arrow func) , time delay in ms(optional) );
// A function to be executed after the timer expires.
// geenralized syntax : setTimeout(functionRef, delay, param1, param2, /* …, */ paramN)
setTimeout( () => {
    console.log("bye bye");
} , 4000); //will not stop the flow of program it is like everything below that get executed in sequence 
// this function will get executed after exactly 4 secs independent of code flow


// console.log("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*");

function square(n) {
    console.log(n*n);
}
// setTimeout(square(3), 2000 ); 
// console.log(Window);


// console.log("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*");

// console.log("welcome to aryanshrivastav.com");

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

// setInterval


// setInterval( () => {
//     console.log("bye bye");
// } , 2000);


// store id of above func

let id = setInterval( () => {
    console.log("bye bye");
} , 1000);
console.log(id);

setTimeout(
    ()=>{
        clearInterval(id);
        console.log("clearInterval called after 6 secs! ");
        
    },6000
);

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

//JS assi 7 q1
// Write an arrow function named arrayAverage that accepts an array of numbers and returns the average of those numbers

// const arrowAverage = (arr) => {
//     let sum = 0;
//     for (let i = 0; i < arr.length; i++) {
//         sum+=arr[i];
//     }
//     return (sum/arr.length);
// }

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
//JS assi 7 q3

// const object = {
//     message:'Hello,World!',
//     logMessage(){
//         console.log(this.message);
//     }
// };
// setTimeout(object.logMessage,1000);


/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
//JS assi 7 q4 (this question is doubtful as of now)

// let length = 4;
// function callback(){
//     console.log(this.length);//
// }

// const object = {
//     length : 5,
//     method(callback) {
//         callback();//
//     }
// }

// object.method(callback , 1, 2); //


