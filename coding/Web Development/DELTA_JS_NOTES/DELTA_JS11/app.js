// function one(){
//     return 1;
// }
// function two(){
//     return one() + one();
// }
// function three(){
//     let ans = two() + one();
//     console.log(ans);
    
// }
// three();


// let h1 = document.querySelector("h1");
// function changeColor(clr, delay ){
//     setTimeout(()=>{h1.style.color = clr;
//         console.log(`headong color changed to ${clr}`);} , delay);
// }

// setTimeout(()=>{changeColor("red")} , 1000);
// setTimeout(()=>{changeColor("blue")} , 2000);
// setTimeout(()=>{changeColor("green")} , 3000);


/*

// setting up a problem of callback hell , solution : Promise 

function savetoDb(data, success, failure) {
    let internetSpeed = Math.floor(Math.random() * 10) + 1;
    if (internetSpeed > 4) {
        success();
    } else {
        failure();
    }
}

// a typical callback hell example

savetoDb(
    "apna college",
    () => {
        console.log("success : your data was saved");
        savetoDb(
            "hello world",
            () => {
                console.log("success2: data2 saved");
                savetoDb(
                    "data3",
                    () => {
                        console.log("success3: data3 saved");
                    },
                    () => {
                        console.log("failure3: data3 not saved");
                    }
                );
            },
            () => {
                console.log("failure2: data2 not saved");
            }
        );
    },
    () => {
        console.log("failure: your data was not saved");
    }
);


*/



// the above problem can be solved using a Promise


/*

// Promise : an object that reperesents eventual completion/failure of an async operation and its resulting values
asynchronous function : a function that depends on one or more factore factors
promise : 1. resolve(success callback)
          2. reject(failure callback)  


A Promise is in one of these states:

1. pending: initial state, neither fulfilled nor rejected.
2. fulfilled: meaning that the operation was completed successfully.
3. rejected: meaning that the operation failed.
// solution: 

function savetoDb(data){
    return new Promise((resolve, reject) => {
        let internetSpeed = Math.floor(Math.random() * 10) + 1;
        if(internetSpeed>4){resolve("resolved!");}
        else{reject("rejected!");}
    })
} 
// savetoDb("Aryan"); //executed multiple times and this was the resposne


// > savetoDb("Aryan");
// > Promise {<rejected>: 'rejected!'}
// > ❌ Uncaught (in promise) rejected! app.js:99
// > savetoDb("Aryan");
// > Promise {<rejected>: 'rejected!'}
// > ❌ Uncaught (in promise) rejected! app.js:99
// > savetoDb("Aryan");
// > Promise {<fulfilled>: 'resolved!'}
// > savetoDb("Aryan");
// > Promise {<fulfilled>: 'resolved!'}
//   > [[Prototype]]: Promise
//   > [[PromiseState]]: "fulfilled"
//   > [[PromiseResult]]: "resolved!"
function savetoDb(){
    return new Promise((resolve, reject) => {
        let internetSpeed = Math.floor(Math.random() * 10) + 1;
        if(internetSpeed>4){resolve(1);}
        else{reject(0);}
    })
} 
// let i = 0;
// let val = savetoDb();
// console.log(val); 


// this and catch method

function savetoDb(data) {
    return new Promise((resolve, reject) => {
        let internetSpeed = Math.floor(Math.random() * 10) + 1;
        if (internetSpeed > 4) {
            resolve("success : data was saved");
        } else {
            reject("failure : weak connection");
        }
    });
}

savetoDb("apna college")
    .then(() => {
        console.log("promise was resolved");
    })
    .catch(() => {
        console.log("promise was rejected");
    });


// more readable version

function savetoDb(data) {
    return new Promise((resolve, reject) => {
        let internetSpeed = Math.floor(Math.random() * 10) + 1;
        if (internetSpeed > 4) {
            resolve("success : data was saved");
        } else {
            reject("failure : weak connection");
        }
    });
}

savetoDb("apna_college")
  .then(() => {
    console.log("data1 saved");
    return savetoDb("helloworld");
  })
  .then(() => {
    console.log("data2 saved");
    return savetoDb("shradha");
  })
  .then(() => {
    console.log("data3 saved");
  })
  .catch(() => {
    console.log("promise was rejected");
  });
  
  // result and error in promises
  
  function savetoDb(data) {
      return new Promise((resolve, reject) => {
          let internetSpeed = Math.floor(Math.random() * 10) + 1;
          if (internetSpeed > 4) {
              resolve("success : data was saved"); // argument of resolve is returned as a result for then methods' arrow function argument : 
          } else {
              reject("failure : weak connection"); // argument of reject is returned as a result for catch methods'  arrow function argument : error
          }
      });
  }
  
  
  savetoDb("apna college")
    .then((result) => {
      console.log("data1 saved");
      console.log("result of promise: ", result);
      return savetoDb("helloworld");
    })
    .then((result) => {
      console.log("data2 saved");
      console.log("result of promise: ", result);
      return savetoDb("shradha");
    })
    .then((result) => {
      console.log("data3 saved");
      console.log("result of promise: ", result);
    })
    .catch((error) => {
      console.log("promise was rejected");
      console.log("error of promise: ", error);
    });



// async functions optimized version example

h1 = document.querySelector("h1");

function changeColor(color, delay, nextColorChange) {
  setTimeout(() => {
    h1.style.color = color;
    if (nextColorChange) nextColorChange();
  }, delay);
}

changeColor("red", 1000, () => {
  changeColor("orange", 1000, () => {
    changeColor("green", 1000, () => {
      changeColor("yellow", 1000, () => {
        changeColor("blue", 1000);
      });
    });
  });
});




// more optimizatoin using 

h1 = document.querySelector("h1");

function changeColor(color, delay) {
    return new Promise((resolve, reject) => {
        setTimeout(() => {
            h1.style.color = color;
            resolve("color changed!");
        }, delay);
    });
}

changeColor("red", 2000)
  .then((result) => {
    console.log("red color was completed , returned value : " , result);
    return changeColor("orange", 2000);
  })
  .then((result) => {
    console.log("orange color was completed, returned value : " , result);
    return changeColor("green", 2000);
  })
  .then((result) => {
    console.log("green color was completed, returned value : " , result);
    return changeColor("blue", 2000);
  })
  .then((result) => {
    console.log("blue color was completed, returned value : " , result);
  });


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



