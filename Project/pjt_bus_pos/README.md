# :pushpin: 실시간 버스 위치 조회
> 버스 번호를 입력하면 실시간 버스 위치를 5초마다 보여주는 간단한 서비스 제작  
>  

</br>

## 1. 제작 기간 & 참여 인원
- 2021.01 ~ 2021.06
- 개인 프로젝트

</br>

## 2. 사용 기술
#### `Back-end`
  - Java 8
  - Spring Boot 2.1
  - OPEN API(네이버 지도, 공공 데이터 포털)
#### `Front-end`
  - JSP

</br>

## 3. 핵심 기능
이 서비스의 핵심 기능은 실시간 버스 위치 조회 기능입니다.  
사용자는 버스 번호를 입력하면 해당 버스의 위치를 지도에서 5초마다 살펴볼 수 있습니다.

<details>
<summary><b>핵심 기능 설명 펼치기</b></summary>
<div markdown="1">

### 4.1. 전체 흐름
![image](https://user-images.githubusercontent.com/56072258/164239180-5fc0ae3b-02d5-49af-8151-043d1f240589.png)

### 4.2. Controller & API Call
![image](https://user-images.githubusercontent.com/56072258/164239985-5f4f39c7-a14e-49a1-88b6-25f316313894.png)

- **노선 정보 조회 API Call** :pushpin: [코드 확인](https://github.com/Altudy/chang-rok/blob/master/Project/pjt_bus_pos/src/main/java/com/changrok/location/web/ApiController.java)
  - 입력한 버스 번호로 API Call하여 busRouteId를 얻습니다.
  - 버스 번호 입력 후 확인 버튼 클릭시 이벤트가 발생하여 AJAX통신을 합니다.
  - serviceKey와 버스 번호로 get 요청 후, xml을 받아 busRouteId를 파싱했습니다.
  
- **버스 위치 정보 조회 API Call** :pushpin: [코드 확인](https://github.com/Altudy/chang-rok/blob/master/Project/pjt_bus_pos/src/main/java/com/changrok/location/web/ApiController.java)
  - busRouteId로 API Call하여 버스들의 위치 좌표를 얻습니다.
  - serviceKey와 busRouteId로 get 요청 후, xml을 받아 itemList의 루프를 돌면서 gpsY와 gpsX를 파싱합니다.

### 4.3. VIEW
![image](https://user-images.githubusercontent.com/56072258/164242564-9a0bb2ac-381c-478c-9388-1818082ea5b8.png)
  
- **5초마다 반복 실행** :pushpin: [코드 확인](https://github.com/Altudy/chang-rok/blob/master/Project/pjt_bus_pos/src/main/resources/static/js/index.js)
  - 노선 정보 조회 API는 1번만 Call하면 되므로 SetInterval 함수를 통해 5초마다 버스 위치 정보 조회 API를 Call하도록 해줬습니다.
  
- **Promise를 사용하여 동기적 처리** :pushpin: [코드 확인](https://github.com/Altudy/chang-rok/blob/master/Project/pjt_bus_pos/src/main/resources/static/js/index.js)
  - 노선 정보 조회 API가 반드시 먼저 호출되고 나서 버스 위치 정보 조회 API가 호출되어야 하므로 Promise를 사용하여 동기적으로 처리해줬습니다.
  
- **Ajax통신할 때마다 marker 재설정** :pushpin: [코드 확인](https://github.com/Altudy/chang-rok/blob/master/Project/pjt_bus_pos/src/main/resources/static/js/index.js)
  - Ajax통신시마다 marker 배열을 초기화 해주고 Controller로부터 받은 버스 좌표 정보로 marker를 세팅해줬습니다.

</div>
</details>

</br>

## 5. 핵심 트러블 슈팅
### 5.1. 2번의 API Call 동기 처리
- 버스 위치 정보를 얻기 위해서는 공공 데이터 포털의 2가지 API를 이용해야만 했습니다.
- 노선 정보 조회 API를 통해 busRouteId를 얻고 이를 통해 버스 위치 정보를 조회할 수 있었습니다.
- 따라서, 노선 정보 조회 API가 우선적으로 호출되고 버스 위치 정보 API를 호출해야만 했습니다.

- 이러한 문제를 해결하기 위해 콜백함수를 이용하여 동기처리코드를 작성하던 중 Ajax 통신을 동기적으로 처리하게 해주는 Promise에 대해 알게 되었고 적용하여 문제를 해결할 수 있었습니다.

</br>

## 6. 회고 / 느낀점
