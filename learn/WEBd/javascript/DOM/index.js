// let box = document.querySelector('.box');
// let n = 4;
// let movies = ["Bahubali", "Conjering", "Drashyam", "Lagan"]
// for (let i=0;i<n;i++){
//     let ele = document.createElement('div');
//     ele.className = 'point';
//     ele.textContent = movies[i];
//     box.append(ele);
// }

// let txt = "Lorem ipsum dolor, sit amet consectetur adipisicing elit. Sapiente voluptate ab voluptatibus quos aut. Fugiat, dignissimos ea quasi eveniet, repudiandae impedit unde animi sequi architecto quam esse accusantium explicabo consequuntur.";
// let boxes = document.querySelectorAll(".box");
// function whenClick(){
//     for (let i=0;i<button.length;i++){
//         boxes[i].style.backgroundColor = 'cyan';
//     }
// }
// let button = document.querySelectorAll("button");
// for (let i=0;i<button.length;i++){
//     button[i].addEventListener('mouseover', whenClick);
// }
// function hide(){
//     let ele = document.querySelector(".shown");
//     ele.style.display = 'none';
//     ele = document.querySelector(".hidden");
//     ele.style.display = 'flex';

// }
// function show(){
//     let ele = document.querySelector(".hidden");
//     ele.style.display = 'none';
//     ele = document.querySelector(".shown");
//     ele.style.display = 'flex';
// }
// let revMore = document.querySelector("h2");
// revMore.addEventListener('click', hide);
// let revLess = document.querySelector(".rev-less");
// revLess.addEventListener('click', show)

document.querySelector("ul").addEventListener("click", function(e){
    let target = e.target;
    if (target.matches('li')){
        console.log(target.textContent + " is clicked !");
        if (target.style.color == 'white'){
            target.style.backgroundColor = "white";
            target.style.color = "black";
        }else{
            target.style.backgroundColor = "black";
            target.style.color = "white";
        }
    }
});
let ul = document.querySelector('ul');
document.querySelector("#add-btn").addEventListener("click", function(e){
    let txt = document.querySelector("#add-box").value;
    if (txt != "" && txt != null){
        let ele = document.createElement('li');
        ele.textContent = txt;
        ele.className = 'box';
        ul.insertBefore(ele, ul.firstChild);
    }else{
        alert("Please enter some sport name !");
    }
});