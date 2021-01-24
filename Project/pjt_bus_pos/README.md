# 실시간 버스 위치 정보 조회
```
* 버스 번호를 입력하면 실시간 버스 위치를 5초마다 보여주는 간단한 서비스 제작

* 이용한 API
* 네이버 지도 api
* 공공데이터 포털 : 버스위치정보 조회 서비스(서울시), 노선 정보 조회 서비스(서울시)

```

## 개발 환경
```

* intelliJ에서 Spring boot를 이용하여 개발 진행.
* pom.xml이 아닌 gradle를 이용하여 환경을 설정(pom.xml에 비해서 환경 설정 구성이 쉬웠다.)
* 템플릿 엔진으로는 jsp를 이용
  -springboot에서는 정적요소(css,js)를 resources에서 관리하므로 새로고침해도 즉각적으로 반영이 안됨
  -이를 해결하기 위해 spring-boot-devtools를 이용
  -application.properties에 prefix와 suffix static=path-pattern 설정.
```

### 동작 과정
```
* localhost:8080으로 요청하면 IndexController를 통해 index.jsp로 이동(getmapping "/")
* 버스 번호로 노선 정보 조회 서비스 API를 통해 busRouteId를 얻고 busRouteId로 버스위치정보 조회 서비스 API를 통해 버스들의 위치 좌표를 알 수 있다.
* 따라서, 2번에 걸친 ajax 통신을 해야한다.

* 첫번째 ajax 통신(입력한 버스 번호로 busRouteId를 얻음)
* 버스 번호 입력후 확인 버튼 클릭시 이벤트가 발생하여 "/map"으로 ajax통신을 한다.
* servicekey와 버스 번호로 get 요청 후, xml을 받아 busRouteId를 파싱

* 두번째 ajax 통신(busRouteId로 버스들의 위치 좌표 얻음)
* "/bus_pos"로 ajax통신을 하는데 busRouteId를 파라미터로 설정
* servicekey와 busRouteId로 get 요청 후, xml을 받아 itemList의 루프를 돌면서 gpsY와 gpsX를 파싱하여 naver map의 marker 설정.

* 반드시 첫번째 ajax통신 후 두번째 ajax 통신이 이루어져야 하기 때문에 Promise를 이용하여 코드 구성.
* 매 5초마다 버스의 위치 정보를 받아서 지도에 marker를 표시하기 위해 marker들을 담을 markers 배열 선언.
* setInterval 함수를 통해 5초마다 ajax통신을 하는데 get 요청을 하기 전에 map에 있는 marker들을 지우고 markers 배열을 초기화함.
```
