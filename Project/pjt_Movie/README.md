# :pushpin: Movie
>CGV와 유사한 영화 예매 사이트  
>  

</br>

## 1. 제작 기간 & 참여 인원
- 2020.01 ~ 2020.12
- 팀 프로젝트(8명)

</br>

## 2. 사용 기술
#### `Back-end`
  - Java 8
  - Spring 5.2
  - GIT
  - MariaDB
  - Jsoup
#### `Front-end`
  - JSP

</br>

## 3. ERD 설계
![image](https://user-images.githubusercontent.com/56072258/163358547-dca86309-a9f2-49f8-a526-ed0c70fa4e14.png)


## 4. 핵심 기능
이 서비스의 핵심 기능은 좌석 예매 기능입니다.  
사용자는 관심있는 영화와 시간대를 선택하고 좌석을 선택하여 예매를 할 수 있습니다.

<details>
<summary><b>핵심 기능 설명 펼치기</b></summary>
<div markdown="1">

### 4.1. 전체 흐름
![image](https://user-images.githubusercontent.com/56072258/163327848-988768fb-bb0b-490b-8bf4-d5dd318fc9e1.png)

### 4.2. 웹 크롤링
![image](https://user-images.githubusercontent.com/56072258/163333749-0c0bc6ee-cfa2-4c3f-a2f8-918e2f0573f2.png)

- **웹 크롤링** :pushpin: [코드 확인](https://github.com/Altudy/chang-rok/blob/master/Project/pjt_Movie/1210kp/src/main/java/com/kdis/demo/controller/BoardController.java)
  - CGV의 현재 상영 목록 리스트를 html의 class로 접근하여 데이터를 불러옵니다.

### 4.3. Controller(영화 선택 및 좌석 선택)

![image](https://user-images.githubusercontent.com/56072258/163334046-8f264a46-98d1-4873-b331-5bdc6ea75494.png)

- **영화선택** :pushpin: [코드 확인](https://github.com/Altudy/chang-rok/blob/master/Project/pjt_Movie/1210kp/src/main/webapp/WEB-INF/views/ticketing/reserve.jsp)
  - Home화면의 예매하기 버튼을 통해 구체적인 예매정보를 선택할 수 있는 화면으로 이동합니다.
	
![image](https://user-images.githubusercontent.com/56072258/163335427-b9d2657d-8579-46e2-a100-7c3802e4c48c.png)
	
- **좌석선택** :pushpin: [코드 확인](https://github.com/Altudy/chang-rok/blob/master/Project/pjt_Movie/1210kp/src/main/webapp/WEB-INF/views/ticketing/seat.jsp)
  - 좌석을 선택할 수 있는 화면으로 이동합니다.

### 4.4. Service & Repository

![image](https://user-images.githubusercontent.com/56072258/163363691-c803be9e-6301-47a0-b068-afa031587580.png)

- **POST 방식으로 form data 전송** :pushpin: [코드 확인](https://github.com/Altudy/chang-rok/blob/master/Project/pjt_Movie/1210kp/src/main/webapp/WEB-INF/views/ticketing/seat.jsp)
  - 영화 선택 페이지에서 선택한 정보들과 좌석 및 가격 정보를 POST 방식으로 전송합니다.
	
![image](https://user-images.githubusercontent.com/56072258/163364284-4e11af73-87b0-47ed-bb20-8734aa61e9a2.png)

- **ID값 세팅** :pushpin: [코드 확인](https://github.com/Altudy/chang-rok/blob/master/Project/pjt_Movie/1210kp/src/main/resources/mappers/ReserveMapper.xml)
  - Reservation_info Table은 Reservation Table의 id가 필요합니다.
  - 따라서, Reservation Table에 Insert한 후 리턴 받은 ID를 DTO에 Set해주고 Reservation_info Table에 Insert 진행했습니다.

</div>
</details>

</br>

## 5. 핵심 트러블 슈팅
### 5.1. OPEN API 필수데이터 부재 문제
- 처음에는 현재 영화 상영 목록을 Kobis에서 제공하는 API를 통해 불러오려고 했습니다.
- 하지만 이용하려는 API에 영화 이미지 정보가 들어 있지 않다는 점과 화면 구성에 필요한 데이터를 조회하기 위해 2번의 API call로 페이지 로딩 속도 이슈가 있는 점이 불편했습니다.
- 또한, 주기적으로 현재 상영 목록 데이터를 불러와 DB에 INSERT 해줘야 한다는 점이 불편했습니다.

- 그래서 해결책을 찾던 중, 웹 크롤링에 대해 알게 되었고 CGV의 현재 상영 페이지에 있는 영화목록을 불러오도록 해결했습니다.

<details>
<summary><b>기존 코드</b></summary>
<div markdown="1">

![image](https://user-images.githubusercontent.com/56072258/163365811-d199a976-9a37-4020-8174-0cb930b4b45a.png)
	
:pushpin: [코드 확인](https://github.com/Altudy/chang-rok/blob/master/Project/pjt_Movie/1210kp/src/main/java/com/kdis/demo/controller/TicketingAPIController.java)

</div>
</details>

<details>
<summary><b>웹 크롤링 적용 코드</b></summary>
<div markdown="1">

![image](https://user-images.githubusercontent.com/56072258/163366710-b9a21a17-79f2-4e41-955e-2144e8bc243d.png)
	
:pushpin: [코드 확인](https://github.com/Altudy/chang-rok/blob/master/Project/pjt_Movie/1210kp/src/main/java/com/kdis/demo/controller/CGVCrwalingController.java)	

</div>
</details>

</br>

## 6. 회고 / 느낀점

