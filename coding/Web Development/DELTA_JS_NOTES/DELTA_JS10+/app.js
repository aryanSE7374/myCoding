// JS DELTA module 10+ (mini project)
// event bubbling
/*
Event Bubbling in JavaScript

Event Bubbling is a mechanism in the DOM where an event starts from the target 
element that triggered it and propagates upwards to its ancestors in the DOM 
hierarchy.
*/


// let div = document.querySelector("div");
// let ul = document.querySelector("ul");
// let lis = document.querySelectorAll("li");
// div.addEventListener("click" , function(){
//   console.log("div was clicked!");
  
// });
// ul.addEventListener("click" , function(){
//   console.log("ul was clicked!");
  
// });
// for(li of lis){
//   li.addEventListener("click" , function(){
//     console.log("li was clicked!");
//   });
// }


//OP
/*
on clicking div frst, then ul and then li lalstly: 
1. div was clicked!
2. ul was clicked!
   div was clicked!
3. li was clicked!
   ul was clicked!
   div was clicked!
*/


// to get rid of this problem use stopPropagation
/*
stopPropagation() Method

The stopPropagation() method is used to stop the event from bubbling further up 
the DOM tree. If you want the event to trigger only on the target element and 
prevent it from affecting parent elements, you can use this method.
*/


// let div = document.querySelector("div");
// let ul = document.querySelector("ul");
// let lis = document.querySelectorAll("li");
// div.addEventListener("click" , function(){
//   console.log("div was clicked!"); // outer most hence stopPop not needed
  
// });
// ul.addEventListener("click" , function(event){
//   console.log("ul was clicked!");
//   event.stopPropagation();
  
// });
// for(li of lis){
//   li.addEventListener("click" , function(event){
//     console.log("li was clicked!");
//     event.stopPropagation();
//   });
// }


/*
//OP
on clicking div frst, then ul and then li lalstly: 
div was clicked!
ul was clicked!
li was clicked!
*/

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

//TO-DO LIST activity

//1st approach without event delegation

/*
let btn = document.querySelector("button");
let ul = document.querySelector("ul");
let inp = document.querySelector("input");

btn.addEventListener("click"  , function(){
  // console.log("a button clicked");
  let item = document.createElement("li"); // creating an element as list item
  item.innerText = inp.value; // setting inner text

  let delBtn = document.createElement("button");
  delBtn.innerText = "delete";
  item.appendChild(delBtn);

  ul.appendChild(item); // append to the ul

  inp.value = ""; // reset input value after rpessing the button

});

// to add functionality in delete buttons

let delBtns = document.querySelectorAll(".delete");
for(delBtn of delBtns){
  delBtn.addEventListener("click" , function(){
    // console.log("item deleted"); 
    let par = this.parentElement;
    console.log(par);
    par.remove(); 
  });
}
*/

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

// this js code has issues with new li elements that dlete buttons are no more functional
// to get rid of this problem we use event delegation

/*
Event Delegation in JavaScript

Event Delegation is a technique in JavaScript where you use a single event listener on a parent element to 
manage events for its child elements. Instead of attaching individual listeners to each child, you rely on 
event bubbling to capture events as they propagate up the DOM.

*/


let btn = document.querySelector("button");
let ul = document.querySelector("ul");
let inp = document.querySelector("input");

btn.addEventListener("click"  , function(){
  // console.log("a button clicked");
  let item = document.createElement("li"); // creating an element as list item
  item.innerText = inp.value; // setting inner text

  let delBtn = document.createElement("button");
  delBtn.innerText = "delete";
  item.appendChild(delBtn);

  ul.appendChild(item); // append to the ul
  console.log("list item added");
  inp.value = ""; // reset input value after rpessing the button

});

// to add functionality in delete buttons we use event delegation
ul.addEventListener("click" , function(event){
  // console.dir(event.target); //must explore this target property
  // console.dir(event.target.nodeName); // log BUTTON // nodeName : "BUTTON"
  if(event.target.nodeName == "BUTTON"){
    // console.log("deleted button");
    let par = event.target.parentElement;
    // console.log(par);
    par.remove();
    console.log("list item remoeved from ul");
  }else{
    console.log("not deleted");
  }
});


/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/


