
// JS OBJECT LTERALS
let arr = [];
console.log(typeof(arr)); // logs object
//used to store key,value pairs
//collection of properties : (key,value) is  a property of an object

let student1 = {
    name : "aryan",
    age : 18,
    marks : 93.8
};

const student2 = {
    name : "paras",
    age : 19,
    marks : 94.2
};

console.log(student1);

console.log("using obj['key'] : " , student1["name"]);
// student1[name]: will log an error
console.log("using obj.key : " ,student1.name); //no error, correct syntax
// console.log("using obj.key : " ,student1."name"); // student1."name": will log an error 


//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//IMPORTANT NOTE: 
//when using the "." operator to access value of a key, js automatically converts object keys to strings
// even if we made the number as a key, the number will be converted to string
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*


//we can modify the properties of an object
student1.marks = 91;
//we can add a new property (key-value pair) to an object
student1.gender = 'M';

console.log(student1);

// we can also do nesting of objects i.e. object of objects

console.log("-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*");


//fucntions in js
function funcNmae(){
    //function code
}

//note that: block scope does not applies on var keyword

//Method : actions performed on objects
// methods are used to manipulate objects. They are written in the same way as functions,
// but they are defined within the object  

//to be continued in JS part 7 