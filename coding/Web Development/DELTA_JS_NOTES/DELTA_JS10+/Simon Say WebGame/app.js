// SIMON SAYS GAME

// arrays 
let gameSeq = []; // stores game seq
let userSeq = []; // stores user seq

let btns = ["red" , "yellow" , "green" , "purple"]; // stores classes of butons

//flags
let started = false; // flag that indicated whether the game started or not
let level = 0; // initial level set to 0

let h2 = document.querySelector("h2"); //selecting heading to display level


// game starts on key press
document.addEventListener("keypress" , function(){
    if(started==false){
        console.log("game stared");
        started = true;
        levelUp();
    }
});

// flash by game seq (new btn)
function gameFlash(btn){
    btn.classList.add("flash");
    setTimeout(function(){btn.classList.remove("flash");},250);
}

// flash by user sequence
function userFlash(btn){
    btn.classList.add("userflash");
    setTimeout(function(){btn.classList.remove("userflash");},250);
}

// level up
function levelUp(){
    //emoty user seq
    userSeq = [];
    level++;
    h2.innerText = `Level ${level}`;

    // random index generator
    let randIdx = Math.floor((Math.random() * 4)%4);
    let randColor = btns[randIdx];
    let randBtn = document.querySelector(`.${randColor}`);
    gameSeq.push(randColor);
    // console.log(gameSeq);

    // flash the generated btn
    gameFlash(randBtn);
}

// check if the user seq was same as the game seq
function checkAns(idx) {
    if (userSeq[idx] === gameSeq[idx]) {
      if (userSeq.length == gameSeq.length) {
        setTimeout(levelUp, 1000);
      }
    //   else{console.log("carry On!");}
    } else {
      h2.innerHTML = `Game Over! Your score was <b>${level}</b> <br> Press any key to start.`;
      document.querySelector("body").style.backgroundColor = "red";
      setTimeout(function () {
        document.querySelector("body").style.backgroundColor = "white";
      }, 150);
      reset();
    }
}


function btnPress(){
    let btn = this;
    userFlash(btn);
    userColor = btn.getAttribute("id");
    userSeq.push(userColor);
    // console.log(userSeq);

    checkAns(userSeq.length-1);
    
}


let allBtns = document.querySelectorAll(".btn");
for(btn of allBtns){
    btn.addEventListener("click" , btnPress);
}



function reset() {
    started = false;
    gameSeq = [];
    userSeq = [];
    level = 0;
  }
  
