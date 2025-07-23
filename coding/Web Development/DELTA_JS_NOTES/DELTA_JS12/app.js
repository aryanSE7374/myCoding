

// JS part 12



/*
// async functions
async function greet() {
  // throw "404 page not found";
  return "hello!";
}

greet()
  .then((result) => { // result = the value being returned by greet method
      console.log("promise was resolved");
      console.log("result was : ", result);
  })
  .catch((err) => {
      console.log("promise was rejected with err : ", err);
  });

let demo = async () => { return 5; };

// Example usage of async demo function
demo()
  .then((result) => {
      console.log("demo function resolved with result : ", result);
  })
  .catch((err) => {
      console.log("demo function rejected with err : ", err);
  });




// using await keyword

function getNum() {
  return new Promise((resolve, reject) => {
      setTimeout(() => {
          let num = Math.floor(Math.random() * 10) + 1;
          console.log(num);
          resolve();
      }, 1000);
  });
}

async function demo() {
  // if we'll not use the await keyword before async calls , all the three functions will get executed one by one at the same time without any pause 
  await getNum();
  await getNum();
  await getNum();
  await getNum();
  getNum();
}

// color change code using async await

h1 = document.querySelector("h1");

function changeColor(color, delay) {
  return new Promise((resolve, reject) => {
    setTimeout(() => {
      let num = Math.floor(Math.random() * 10) + 1;

      h1.style.color = color;
      console.log(`color changed to ${color}!`);
      resolve("color changed!");
    }, delay);
  });
}

async function demo() {
  await changeColor("red", 1000);
  await changeColor("orange", 1000);
  await changeColor("green", 1000);
  changeColor("blue", 1000);
}

demo();
// handling rejections

h1 = document.querySelector("h1");

function changeColor(color, delay) {
  return new Promise((resolve, reject) => {
    setTimeout(() => {
      let num = Math.floor(Math.random() * 10) + 1;
      if(num>3){
        reject("promise rejected"); // throws an error as given in the argumnent
      }

      h1.style.color = color;
      console.log(`color changed to ${color}!`);
      resolve("color changed!");
    }, delay);
  });
}




/*
async function demo() {
  await changeColor("red", 1000);
  await changeColor("orange", 1000);
  await changeColor("green", 1000);
  changeColor("blue", 1000);

  //as soon as error is triggered , the above promise chain will be broken
  // and the execution of the below code stops 
  // to escape this problem use error handling using try catch block
  let a = 5;
  console.log(a);
  console.log("new num : " , a+3);
  
  
}
*/

/*
async function demo() {
  try {
    await changeColor("red", 1000);
    await changeColor("orange", 1000);
    await changeColor("green", 1000);
    changeColor("blue", 1000);
  } catch (err) {
    console.log("an error is caught : " , err);
    
  }

  //as soon as error is triggered , the above promise chain will be broken
  // and the execution of the below code stops 
  // to escape this problem use error handling using try catch block
  let a = 5;
  console.log(a);
  console.log("new num : " , a+3);
  
  
}

demo();

*/














/*

//APIs 
let url = "https://catfact.ninja/fact";

fetch(url)
  .then((res) => {
    console.log(res);
    return res.json();
  })
  .then((data) => {
    console.log(data);
  })
  .catch((err) => {
    console.log("ERROR - ", err);
  });


let url = "https://catfact.ninja/fact";

fetch(url)
  .then((res) => {
    return res.json();
  })
  .then((data) => {
    console.log("data1 = ", data.fact);
    return fetch(url);
  })
  .then((res) => {
    return res.json();
  })
  .then((data2) => {
    console.log("data2 = ", data2.fact);
  })
  .catch((err) => {
    console.log("ERROR - ", err);
  });

console.log("i am happy");


*/



