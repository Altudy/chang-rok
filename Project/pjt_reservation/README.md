# :pushpin: 전시 정보 예약 관리 시스템
> 관심 있는 컨텐츠의 정보를 확인하고 예약하는 예약 관리 시스템  
>  

</br>

## 1. 제작 기간 & 참여 인원
- 2020.07 ~ 2020.11
- 팀 프로젝트(2명)

</br>

## 2. 사용 기술
#### `Back-end`
  - Java 8
  - Spring 5.2
  - GIT
  - MySQL
#### `Front-end`
  - JSP

</br>

## 3. ERD 설계
![image](https://user-images.githubusercontent.com/56072258/163819378-2f98e034-e3bd-4731-9f85-6e8091e8cbe0.png)


## 4. 핵심 기능
이 서비스의 핵심 기능은 전시 예매 기능입니다.  
사용자는 관심있는 전시와 선택하고 예매자 정보를 입력하여 예매를 할 수 있습니다.
또한, 예매한 내역을 확인할 수 있습니다.

<details>
<summary><b>핵심 기능 설명 펼치기</b></summary>
<div markdown="1">

### 4.1. 전체 흐름
![image](https://user-images.githubusercontent.com/56072258/163830711-e14b6be1-03d7-4a55-a693-73d6191b8788.png)

### 4.2. Controller
![image](https://user-images.githubusercontent.com/56072258/163827537-e6fd221e-d6c7-45c9-98f5-5b7c73117e14.png)

- **상세 화면으로 이동** :pushpin: [코드 확인](https://github.com/Altudy/chang-rok/blob/master/Project/pjt_reservation/reservation/src/main/java/kr/or/connect/reservation/controller/DetailController.java)
  - 전시id를 파라미터로 하여 get 방식으로 호출합니다.
  - 전시 정보에 관한 데이터를 model에 담아 detail view name을 반환합니다.
  
- **예매 화면으로 이동** :pushpin: [코드 확인](https://github.com/Altudy/chang-rok/blob/master/Project/pjt_reservation/reservation/src/main/java/kr/or/connect/reservation/controller/ReserveController.java)
  - 전시id를 파라미터로 하여 get 방식으로 호출합니다.
  - 전시 정보와 예매에 관련된 데이터를 model에 담아 reserve view name을 반환합니다.

### 4.3. Repository
![image](https://user-images.githubusercontent.com/56072258/163829639-9f88ce47-5de0-4089-8d84-bdf83ee1ac21.png)
![image](https://user-images.githubusercontent.com/56072258/163830565-c5451cc2-163c-4945-853b-2a8b0d7c5ea5.png)
  
- **예매 진행** :pushpin: [코드 확인](https://github.com/Altudy/chang-rok/blob/master/Project/pjt_reservation/reservation/src/main/java/kr/or/connect/reservation/dao/ReservationDao.java)
  - Reservation_info 테이블에 예매 정보를 insert한 후 id값을 리턴 받습니다.
  - Reservation_info_price 테이블에 예매한 가격 정보를 insert 합니다.

### 4.4. Sqls & DB

![image](https://user-images.githubusercontent.com/56072258/163831996-b0521b18-afef-45ba-a6a3-8eb1274e0c14.png)

- **Jdbc Template을 이용하여 DB 연결** :pushpin: [코드 확인](https://github.com/Altudy/chang-rok/blob/master/Project/pjt_reservation/reservation/src/main/java/kr/or/connect/reservation/dao/ReservationDao.java)
  - Jdbc Template 이외에 <b>NamedParameterJdbcTemplate</b>, <b>SimpleJdbcInsert</b>, <b>SimpleJdbcTemplate</b> 을 이용하여 select, insert 구문을 실행했습니다.
  - <b>NamedParameterJdbcTemplate</b>를 이용할 경우 Sql 파일을 따로 만들어 관리했습니다. [코드확인](https://github.com/Altudy/chang-rok/blob/master/Project/pjt_reservation/reservation/src/main/java/kr/or/connect/reservation/dao/ReservationDaoSqls.java)

</div>
</details>

</br>

## 5. 핵심 트러블 슈팅
### 5.1. 잦은 DB의 수정
- 페이지 단위로 역할을 분담하여 코드를 작성하다보니 팀원과 서로 같은 테이블을 빈번하게 수정하는 일이 잦았습니다.
- GIT을 통해 merge하는 과정에서 변수명을 수정하거나 중복되는 칼럼을 수정하는 등 효율이 매우 떨어졌습니다.
- 역할을 분담하기 전에 DB의 테이블을 먼저 정하지 않아서 생긴 문제라고 생각했고 작업 진행 중에 ERD를 작성하는 것이 급선무라고 생각했습니다.

- ERD 작성 후 가장 좋았던 점은 시각적인 부분이었습니다. 머리 속으로 구상하던 테이블과의 관계성을 직접 의논하고 그려보면서 CRUD의 주체를 명확히 할 수 있었습니다.
- 이러한 경험을 통해 프로젝트 시작 전 백엔드 개발자로서 DB 모델링 과정의 중요성을 배울 수 있었습니다.

</br>

## 6. 회고 / 느낀점
