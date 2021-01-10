# VanillaJS
```
이 Project는 Momentum을 직접 구현한 프로젝트입니다. (NomadCoder의 VanillaJs 수강)

1. 시계기능 구현
2. local storage를 이용해 사용자 정보를 입력해 나타내는 기능 구현
3. 할 일 목록을 추가하여 리스트로 보이게 하는 기능 구현.
4. background에 이미지를 넣고 @keyFrame을 이용해 animation 효과를 줌.
5. weather API를 이용하여 날씨 정보를 얻어 보여주는 기능 구현.

위의 기능을 Javascript로 구현하였습니다.
```

# Why VanillaJs?
```
* Spring을 공부하면서 controller에서 비즈니스 로직처리를 통해 얻은 model을 view단으로 보내 jsp를 통해 브라우저로 보여주는 과정에서
웹 프로그래밍 언어(html,css,javascript)실력의 부족을 느꼈습니다.
* 머리 속으로 생각하는 것들을 간단하게라도 구현하기 위해 라이브러리를 쓰지 않는 javascript의 기본인 vanillaJs 공부를 택했습니다.
```

# Result
```
1) local Storage에 대해 처음 알게 되었습니다. key와 value 쌍으로 값을 저장하고 읽으면서 새로고침을 해도 그 값을 유지할 수 있습니다.
2) background img를 넣는 과정에서 @keyframe 속성에 대해 지식의 부족함을 느꼈습니다. 그래서 네이버부스트코스의 웹 UI 과정을 수강하기 시작했습니다.
3) openweathermap API를 이용하면서 data를 읽어오는 fetch 함수를 처음 접했습니다. 그 과정에서 javascript의 동기와 비동기 처리에 대한 부분을 기초지식 폴더에 정리했습니다.
```

# 1. js folder

## 1) clock.js
```
* new Date()를 통해 현재 시간를 얻고 시/분/초를 각각 구해 setInterval() 함수를 통해 새로고침 없이 반복적으로 현재 시간의 정보를 얻을 수 있다.
```

## 2) greeting.js
```
* local Storage(key,value로 저장)로부터 value 값을 가져와서 user 정보가 있는지 없는지 확인한다.(loadName)

* user가 없다면 이름을 요청한다.(askForName)

* form의 input이 showing으로 바뀜.

* submit시에는 화면 전체가 새로고침 되기 때문에 이를 막기 위해 event.preventDefault() 함수를 이용(handleSubmit)
    그 후 화면에 user의 이름을 나타내고(paintGreeting), local Storage에 user를 저장한다.(saveName)
    
* user가 있다면 화면에 user의 이름을 나타낸다.(paintGreeting)
```

## 2) todo.js
```
* input에 값을 입력후 submit 했을 때, 입력값이 todo list에 추가 된것을 확인.

* submit시 화면 전체가 새로고침 되는 것을 막기 위해 event.preventDefault() 함수를 이용.

* createElement와 appendChild 를 이용하여 입력한 값을 li에 추가하여 ul 밑에 붙임.

* localStorage에 저장되어 있지 않을 상태기 때문에 화면을 새로고침하면 초기화됨.

* localStorage에 저장하기 위해 toDos 배열을 만들고 배열 안에 Object 형식(text,id)으로 넣기 위해 toDoObj 선언.

* saveToDos 함수를 통해 localStorage에 저장.(String으로 저장해야 하기 때문에 JSON.stringify 로 저장.)

* localStorage에 item이 있다면 JSON.parse를 통해 String을 Object 형식으로 가져옴.

* 그 후, forEach를 통해 paintToDo 함수를 반복 호출하여 화면에 list 추가.

* x 버튼을 누르면 목록을 삭제 하기 위해 클릭시 이벤트 발생.

* event.target.parentNode로 부모 노드를 찾고 removeChild로 li를 지움.

* toDos 배열에는 삭제가 안됐기 때문에 filter함수를 통해 todo.id와 li.id가 같지 않으면 true를 리턴하여 거름.

* filter를 통한 cleanToDos를 다시 toDos로 바꿈.(따라서 toDos를 const로 선언하면 안됨)

* saveToDos 함수를 통해 localStorage에 저장.
```

## 3) bg.js
```
* img folder에서 랜덤으로 img을 불러오기 위해 Math.floor과 Math.random 함수를 씀.

* paintImage 함수의 인자로 randomNumber를 받아서 random img를 얻고 classList.add("bgImage")를 주어 클래스 부여.

* css파일에 bgImage에 대한 css 부여.( z-index 값을 -1로 주어 이전에 작업한 항목들이 background위로 다 뜨게 함.
```

## 4) weather.js
```
* navigator API를 이용하여 위치정보(경도,위도)를 받아옴.
* 가져오는데 성공할 시 위치 정보를 localStorage에 저장.

* localStorage에 위치 정보가 있다면 getWeather 함수 실행.
* fetch를 통해 url에서 data를 얻어옴, then() 함수를 통해 fetch가 완료된 후에 함수가 실행되도록 함.
* 최종적으로 response를 json으로 바꾼 후, temperature과 place를 얻어 화면에 표시.
```
