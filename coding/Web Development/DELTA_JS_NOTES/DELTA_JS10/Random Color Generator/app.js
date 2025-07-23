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
    let red,green,blue;
    red = Math.floor(Math.random()*255);
    green = Math.floor(Math.random()*255);
    blue = Math.floor(Math.random()*255);
    let color = `rgb(${red} , ${green},${blue})`;
    return color;
}