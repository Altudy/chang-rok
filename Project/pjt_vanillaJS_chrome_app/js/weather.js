const weather = document.querySelector(".js-weather");

const API_KEY = "59d99cc62341f903da3b59843c84223a";
const COORDS = 'coords';

// openweathermap API를 통해서 날씨 정보를 얻기.
function getWeather(lat,lng) {
  // fetch함수를 통해 url에서 data를 얻음.
  fetch(
    `https://api.openweathermap.org/data/2.5/weather?lat=${lat}&lon=${lng}&appid=${API_KEY}`
  ).then(function(response){ // then은 fetch를 완료한 후에 실행.
    return response.json();
  })
  .then(function(json){
    const temperature = json.main.temp;
    const place = json.name;
    weather.innerText = `${temperature} @ ${place}`
  });
}

// localStorage에 경도와 위도 저장.
function saveCoords(coordsObj) {
  localStorage.setItem(COORDS,JSON.stringify(coordsObj));
}

// 위치 정보 가져오는데 성공.
function handleGeoSuccess(position) {
  const latitude = position.coords.latitude;
  const longitude = position.coords.longitude;
  const coordsObj={
    latitude,
    longitude
  };
  saveCoords(coordsObj);
  getWeather(latitude,longitude);
}

// 위치 정보 가져오는데 실패.
function handleGeoError() {
  console.log("cant access");
}

// 위치 정보를 확인하는 함수.
function askForCoords() {
  navigator.geolocation.getCurrentPosition(handleGeoSuccess,handleGeoError);
}

function loadCoords() {
  const loadedCoords = localStorage.getItem(COORDS);
  if(loadedCoords === null){
    askForCoords();
  } else{ // 위치정보가 있다면
    const parsedCoords = JSON.parse(loadedCoords);
    getWeather(parsedCoords.latitude,parsedCoords.longitude);
  }
}

function init() {
  loadCoords();
}

init();
