const body =document.querySelector("body");
const IMG_NUMBER = 3;

// background에 img를 넣음.
function paintImage(imgNumber) {
  const image = new Image();
  image.src = `/img/img_${imgNumber+1}.jpg`;
  image.classList.add("bgImage");
  body.prepend(image);
}

// random number 발생.
function genRandom() {
  const number = Math.floor(Math.random()*IMG_NUMBER);
  return number;
}

function init() {
  const randomNumber = genRandom();
  paintImage(randomNumber);
}

init();
