// DOM JS9
// use console.dir(obj) : for objects

// Window
// ƒ Window() { [native code] }
// window
// Window {window: Window, self: Window, document: document, name: '', location: Location, …}
// document
// console.dir(document)
// VM130:1  #document
// undefined
// console.dir(document.all); //all cont  ain HTML elements collection
// VM167:1 
// HTMLAllCollection(38)
// undefined
// console.dir(document.all[8]);
// VM184:1 
// h1
// undefined
// console.dir(document.all."8");
// VM201:1 Uncaught SyntaxError: Unexpected string
// console.dir(document.all.8);
// VM210:1 Uncaught SyntaxError: missing ) after argument list
// console.dir(document.all[8].innerText);
// VM247:1 Spider Man
// undefined
// document.all[8].innerText = "Peter Parker";
// 'Peter Parker'
/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

// How to select elements 

// 1. getElementById : Returns element as an object or null (if not found)
// syntax : document.getElementById(id); //if id is passed as a variable then write as variable but if id is passed as id(i.e. string form) then use "id" example below

// document.getElementById("mainImg") //returns image object to console hence it can be stored in an object variable
let imgObj = document.getElementById("mainImg");
// console.log(document.getElementById("mainImg")); //logs
console.log("image object : ");
console.dir(imgObj);
console.log("obj.src : " ,imgObj.src);
console.log("obj.tagName : "  , imgObj.tagName);

// imgObj.src = "assets/creation_1.png"; //will change the image object


// 2. getElementByClassName : Returns element as an HTML collection(siliar to array) or empty collection (if not found)
// syntax : document.getElementsByClassName(classname); //if className is passed as a variable then write as variable but if className is passed as className(i.e. string form) then use "className" example below

htmlCol = document.getElementsByClassName("oldImg");
htmlCol[0];
for (let i = 0; i < htmlCol.length; i++) {
    console.dir(htmlCol[i]);   
}

wrongCol = document.getElementsByClassName("noSuchClassExists"); //returs a n empty HTMLcollectiom
console.dir(wrongCol);


// 3. document.getElementsByTagName : Returns element as an HTML collection(siliar to array) or empty collection (if not found)
// syntax : document.getElementsByTagName(tagname); 

paraCol = document.getElementsByTagName("p"); //returns a collection containing all "p"  tag elements in the document
console.dir(paraCol); 

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

//Query Selectors: 
console.dir(document.querySelector('p')); // Selects first p element if there exists more than one p
console.log(document.querySelector('p'));

console.dir(document.querySelector('#myId'));// Selects first element with id = myId

console.dir(document.querySelector('.myClass'));// Selects first element with class = myClass

console.dir(document.querySelectorAll('p')); // Selects all p elements and returns a nodelist

console.dir(document.querySelector('div a')); // searches for 1st div and then 1st a tag in that div 

console.dir(document.querySelectorAll('div a')); // returns a nodeList containing all the anchor tags contained in a div tag
console.dir(document.querySelectorAll('p')); //returns a nodeList containing all the paragraph tags in the document

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

//MANIPULATING THE ELEMENTS

//setting content in Objects

//innerText:
// Description: Retrieves and sets the visible text contained in a node.
// Usage: This property only includes the text that is visible to the user, meaning it won't include hidden text or text from hidden elements.

// textContent:
// Description: Retrieves and sets the text content of the specified node and all its descendants.
// Usage: Unlike innerText, textContent includes all text, even hidden text, within the element. such as spaces, nextlines, hidden, display:none etc

// innerHTML:
// Description: Retrieves or sets the HTML or XML markup contained within the element.
// Usage: This property allows you to access and modify the inner HTML markup of an element, which includes HTML tags and content.

para = document.querySelector('p'); 
console.dir(para);
console.log(para.innerText);
console.log(para.textContent);
console.log(para.innerHTML);

// let heading = document.querySelector("h1");
// // -> undefined
// heading
// //-> <h1>​Spider Man​</h1>​
// heading.innerHTML = `<u>${heading.innerText}</u>`; //this way we dont need to write whole innerText again
// // -> '<u>Spider Man</u>'

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

//getetrs and setters for attributes

// let img = document.querySelector('img');
// console.log(img); // Check the selected image element
// console.log(img.getAttribute('id')); // Get the current 'id' attribute of the image
// img.setAttribute('id', 'spidermanImg'); // Set a new 'id' attribute for the image :- this will affect the styling of the mainImg as the styling will also be get changed 

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

// manipulating style (with style attribute)
// let img = document.querySelector("img");
// console.dir(img.style);

// in css : a property is written in hyphen seprated case i.e. background-image
// but in js : the property is written in camelCase : backgroundImage

//activity to demonstrate : copy these lines one by one in the console
// let heading = document.querySelector("h1");
// heading.style.color = "purple";
// heading.style.color = "green";
// heading.style.backgroundColor = "yellow";

// this block of code will change the color of all the anchor tags lying inside a div of class .box to yellow

// let links = document.querySelectorAll(".box a");
// for (let i = 0; i < links.length; i++){
//     links[i].style.color = "yellow";
// }
// // method2 using for of loop
// for(link of links){
//     link.style.color = "green";
// }

// NOTE : THIS TYPE OF MANIPUKLATION USING STYLE ATTRIBUTE IS NOT PREFERRABLE AS THIS ATTRIBUTE MANIPULATES ON INLINE STYLE (HTML)
// BUT MOST OF THE STYLINGS NEEEDED TO BE DONE IN CSS FILE
// SO WHEN WE SELECT ANY STYLING USING STYLE ATTRIBUTE, IT WILL RETURN ONLY INLINE STYLES AND NOT THOSE DONE IN CSS

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

// manipulating styles
/*
Manipulating Style using classList:
Syntax: obj.classList
Methods:
	1.	classList.add() - Adds new classes.
	2.	classList.remove() - Removes existing classes.
	3.	classList.contains() - Checks if a class exists.
	4.	classList.toggle() - Toggles between adding and removing classes. (returns true if adds a class else returns false if removes a class to the calssList)
*/

/*
let heading = document.querySelector('h1');

heading.classList.add('green');
// Adds the class 'green'

heading.classList.add('underline');
// Adds the class 'underline'

heading.classList.remove('green');
// Removes the class 'green'

heading.classList.remove('green');
// Removes the class 'green' (no error if it's already removed)

heading.setAttribute('class', 'green');
// Sets the class attribute to 'green'
*/

/*
heading.classList; 
// Output: DOMTokenList ['green', value: 'green']

heading.toggle("green"); 
// Error: Uncaught TypeError: heading.toggle is not a function

heading.classList.toggle("green"); 
// Output: false

heading.classList.toggle("underline"); 
// Output: true

heading.classList.toggle("green"); 
// Output: true

heading.classList; 
// Output: DOMTokenList ['underline', 'green', value: 'underline green']

heading.classList.toggle("underline"); 
// Output: false

heading.classList; 
// Output: DOMTokenList ['green', value: 'green']
*/

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

//NAVIGATION ON PAGE
/*
1. parentElement
2. children
3. previousElementSibling / nextElementSibling
** childElementCount
*/

/*
let h4 = document.querySelector("h4");

h4.parentElement;
// Output: <div class="box">...</div>

let box = document.querySelector(".box");

box.children;
// Output: HTMLCollection(2) [h4, ul]

box.childElementCount;
// Output: 2

let ul = document.querySelector("ul");

ul.parentElement;
// Output: <div class="box">...</div>

ul.childElementCount;
// Output: 3

ul.children;
// Output: HTMLCollection(3) [li, li, li]

ul.children[1];
// Output: <li>...</li>

ul.children[1].previousElementSibling;
// Output: <li>...</li>

ul.children[1].nextElementSibling;
// Output: <li>...</li>

ul.children[1].previousElementSibling.style.color = "green";
// Sets the color of the previous sibling <li> element to green
// Output: 'green'
*/

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

// ADDING ELEMENTS ON PAGE
/*
to create an element : document.createElement("element")
but creating will not add the element to the webPage, to add we have following functions

1. appendChild(el) : parent.appendChild(element) , adds the element Node at the end of the parentNode
2. append(el) : can add element, string, text anything hence it is used more than appenDdChild
3. prepend(el) ; adds to the begining of the parent
4. insertAdjacentElement(position , element) : inserts at adjacent positions : 
    4(a) 'beforebegin': Before the targetElement itself.
    4(b) 'afterbegin': Just inside the targetElement, before its first child.
    4(c) 'beforeend': Just inside the targetElement, after its last child.
    4(d) 'afterend': After the targetElement itself.
*/

/* 
demonstration of 1. append Child

// Create a new paragraph element
let newP = document.createElement("p");

// Log the new paragraph element to the console
console.dir(newP);

// Select the body element
let body = document.querySelector("body");

// Append the new paragraph to the body
body.appendChild(newP);

// Select an element with the class 'box'
let box = document.querySelector(".box");

// Append the new paragraph to the box element
box.appendChild(newP);

// Create a new button element
let btn = document.createElement("button");

// Set the button's inner text
btn.innerText = "Click Me!";

// Append the button to the box element
box.appendChild(btn);

*/

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
/*
demonstration of 2. append and 3. prepend

let newP = document.createElement("p"); //creating element
let btn = document.createElement("button"); //creating element

newP.append("this is a paragraph");
// appends text to the newP

btn.innerText = "click Me!";
// changes the text of btn

let box = document.querySelector(".box");
box.appendChild(newP);

newP.append(btn);

newP.append("some more text in para after the button");

// prepend
box.prepend("newP"); // textually adds newP
box.prepend(newP); // adds newP in the begininning of box replacing it from end to begin

*/

/*
demonstration of 4. insertAdjacentElement(position , element)
let btn = document.createElement("button");
btn.innerText = "New Button";
let p = document.querySelector("p");
p.insertAdjacentElement("beforebegin", btn);
p.insertAdjacentElement("afterbegin", btn);
p.insertAdjacentElement("beforeend", btn);
p.insertAdjacentElement("afterend", btn);

*/

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
//REMOVING ELEMENTS FROM PAGE
// 1. parent.removeChild(element)
// 2. remove(element) //more easy to use,more prefered

/*
let body = document.querySelector("body");
let div1 = document.querySelector("div");
body.removeChild(div1);
let img = document.querySelector("img");
let remImg = body.removeChild(img);
console.log(remImg);
body.remove();

*/
/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/