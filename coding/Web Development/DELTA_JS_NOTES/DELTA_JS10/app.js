// DOM JS10

//DOM EVENTS : events are signals that indicate something has occupink

// inline event attributes in HTML
/* <button onclick="console.log('button was clicked!')"> Click Me </button> */

//onclick event
// let btn = document.querySelector("button");
// btn.onclick = function(){
// console.log("button was clicked");
// }
// function sayHello(){
//     console.log("Hello");
// }

//another method to select and add event
// document.querySelector("button").onclick = sayHello;


//these mouse events not work on brave during inspection
// to make them work, u should of the inspection window

//onmouseenter event
// btn.onmouseenter = function(){
//     alert("mouse entepink the button!");
// }
// btn.onmousemove = function(){console.log("mouse moved");}

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

//event listeners aka event handlers
// the above method doesn't allow us to assign more than one function to a single event 
// this can be done using event listeners

//how to add an eventListener to a DOM event
// element.addEventListener(event,callback)

/*
function f1(){console.log("Hello ji!");}
function f2(){console.log("Namasate ji!");}
btn.addEventListener("click",f1);
btn.addEventListener("click",f2);
*/

// mdn reference: https://developer.mozilla.org/en-US/docs/Web/API/EventTarget/addEventListener

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
// random color generator

// HTML code

/*
<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>Random Color Generator</title>
  <link rel="stylesheet" href="style.css" />
</head>
<body>
  <h3>Random Color Generator</h3>
  <br>
  <button>Generate Color</button>
  <br><br>
  <div>This is your Color</div>
  <br>
  <script src="app.js"></script>
</body>
</html>
*/


// js code:

/* 

let btn = document.querySelector("button");
btn.addEventListener("click",function(){
    let h3 = document.querySelector("h3");
    let randomColor = getRandomColor();
    h3.innerText = randomColor;
    let div = document.querySelector("div");
div.style.backgroundColor = randomColor;
    console.dir(div);
});
function getRandomColor(){ 
    let pink,green,blue;
    pink = Math.floor(Math.random()*255);
    green = Math.floor(Math.random()*255);
    blue = Math.floor(Math.random()*255);
    let color = `rgb(${pink} , ${green},${blue})`;
    return color;

}

*/
 
/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
//EVENT LISTENERS FOR MULTIPLE ELEMENTS
// NOTE: that event listeners are not button specific

/*
let h1 = document.querySelector("h1");
let p = document.querySelector("p");
let box = document.querySelector(".box");

h1.addEventListener("click" , function(){
  alert("heading is clicked!");
});
p.addEventListener("click" , function(){
    alert("para is clicked!");
});
box.addEventListener("click" , function(){
  alert("box is clicked!");
});

// will work

*/
/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
// this keyword in event listeners : refers to the object on which eventListener is being added
/* 
eg: Object.addEventListener(event,callback(){
  console.log(this.property);
});
this => Object

let box = document.querySelector(".box");
box.addEventListener('click' , function(){
  console.dir(this);
  console.log("this.innerText = " , this.innerText);
  this.style.backgroundColor = "pink"; // this => box
  console.log("color changed to pink!");
});


let para = document.querySelector("p");
para.addEventListener('click' , function() {
  console.dir(this);
  this.style.backgroundColor = "pink"; // this => para
  console.log(this.style);
});

*/

//an application of this:
// While selecting multiple elements and adding event listeners to those elements
// One method would be selecting each and every elements and assigning them into separate variables And then add Even listeners to the variables 

/* 
Method1 : laborious
let h1 = document.querySelector("h1");
let h3 = document.querySelector("h3");
let p = document.querySelector("p");
let btn = document.querySelector("button");

// change the bgcolor of every element whenever we click it to pink
h1.addEventListener('click' , function() {
  h1.style.backgroundColor = "pink";
});
h3.addEventListener('click' , function() {
  h3.style.backgroundColor = "pink";
});
p.addEventListener('click' , function() {
  p.style.backgroundColor = "pink";
});
btn.addEventListener('click' , function() {
  btn.style.backgroundColor = "pink";
});

*/

/*
Method2 : efficient
let h1 = document.querySelector("h1");
let h3 = document.querySelector("h3");
let p = document.querySelector("p");
let btn = document.querySelector("button");

function changeColor(){
  this.style.backgroundColor = "pink";
  console.log(this.tagName , ": bg color changed to pink");
}
h1.addEventListener("click" , changeColor);
h3.addEventListener("click" , changeColor);;
p.addEventListener("click" , changeColor);
btn.addEventListener("click" , changeColor);

//this is efficient method
*/
/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
/**
// default event in callback function argument of addEL : eg : pointer event for mouse and 
let btn = document.querySelector("button");
btn.addEventListener("click" , function(event){
  console.dir(event); //logs Poitner event object
});

//keyboard events example
let inp = document.querySelector("input");
inp.addEventListener("keyup" , function(event){
  console.dir(event); //logs Keyboard event object
  console.log("key: " , event.key, " , Keycode: " , event.keyCode );
});
*/
/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
//form events
/*
let form = document.querySelector("form");
form.addEventListener("submit" , function(event){
  event.preventDefault(); // to prevent the default action URL in the form and rest of the code below this line will get executed
  console.log(event); //logs sumbitEvent
  alert("form submited");
});
*/
/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
//extracting from data

// value property
/*
let form = document.querySelector("form");
form.addEventListener("submit" , function(event){
  event.preventDefault();
  let inp = document.querySelector("input");
  console.dir(inp);
  console.log("inp.innerText : " , inp.innerText); //logs blank
  // value property of input object
  console.log("inp.value  :" , inp.value);
});
*/


//example1
/*
let form = document.querySelector("form");
form.addEventListener("submit" , function(event){
  event.preventDefault();
  let user = document.querySelector("#user");
  let pass = document.querySelector("#password");
  console.log("username: " , user.value);
  console.log("password: " , pass.value);

  alert(`Hi ${user.value}! your password is set to : ${pass.value}`);
});
*/


// form elemetns HTML colection and application of this keyword to acces elements of form
/*
let form = document.querySelector("form");
form.addEventListener("submit" , function(event){
  event.preventDefault();
  console.dir(form); //checkout elements property
  console.dir(form.elements); //returns an HTMLFormControlsCollection(3), can be iterated using indices
  let user = this.elements[0];
  let pass = this.elements[1];
  console.log("username: " , user.value);
  console.log("password: " , pass.value);

  alert(`Hi ${user.value}! your password is set to : ${pass.value}`);
  
});
*/

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/


/*
More Events

1. change event : The change event occurs when the value of an element has been changed 
(only works on <input>, <textarea>, and <select> elements).

2. input event : The input event fires when the value of an <input>, <select>, or <textarea> element has been changed.

let form = document.querySelector("form");
form.addEventListener("submit" , function(event){
  event.preventDefault();
});

let user = document.querySelector("#user");
user.addEventListener("change" , function(event){
  console.log(`input changed...final value : ${user.value}`);
});

user.addEventListener("input" , function(e){
  console.log("username value changed to : " , user.value);
});
*/

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/