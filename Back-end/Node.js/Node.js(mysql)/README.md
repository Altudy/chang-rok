# Node.js를 통해 mysql을 이용하는 실습

## 실습 준비

* [다운로드](https://github.com/web-n/node.js-mysql/releases/tag/1)를 통해 실습 환경 구성
* package.json의 dependencies에서 sanitize-html를 설치하기 위해 npm install 명령어 실행(해당 디렉토리에서 명령을 실행해야 한다.)
* 그 결과 node_modules 디렉토리가 추가됨.
* node main.js 명령으로 실행 가능하지만 파일이 수정되면 자동으로 reload하기 위해 pm2 start main.js --watch 명령으로 실행
* pm2 log 를 통해 문제가 있는지 없는지 확인.

## mysql 모듈의 기본 사용 방법

* npm install -S mysql로 패키지 설치.(-S 옵션을 주어 package.json의 dependencies에 추가)
* require('mysql')로 mysql 객체를 얻고 createConnection 메소드를 통해 연결 정보를 셋팅한다.(host,user,password,database)
* connect 메소드로 연결.
* query 메소드로 query문 입력하고 콜백함수로 결과가 나옴.(error,results,fields 가 콜백함수의 인자로 들어감)
* 나의 경우엔 "ER_NOT_SUPPORTED_AUTH_MODE" 에러가 발생해서 아래와 같은 방법으로 해결함.
* alter user 'username'@'%' IDENTIFIED WITH mysql_native_password by 'password';

## mysql로 홈페이지 구현

* Node.js(CRUD)의 완성본의 main.js 파일을 이어서 작성.
* 기존의 메인 화면(queryData.id === undefined)을 query메소드를 통해 화면 구성.
* template.js에서 list function은 리스트 목록을 <a>태그로 감싸서 return 한다. list의 인자로 query의 결과인 topics를 넣어준다.
* topics는 object이므로 해당 index의 fields 값을 지정해 줘야함. (ex. topics[i].title, topics[i].id)

## mysql로 상세보기 구현

* id값에 따라 가져오는 데이터가 다르므로 이를 쿼리로 작성(SELECT * FROM topic where id=${queryData.id})
* 위와 같은 방법으로 쿼리 작성이 공격의 위험이 있으므로 id=?로 작성하고 [queryData.id] 로 두번째 인자를 줌으로써 
공격의 의도가 있는 코드를 막아줌.
* error 처리를 위해 throw error; (error 발생시 애플리케이션이 종료된다.)

## mysql로 글생성 기능 구현

* create 버튼 누를시 쿼리를 통해 database에 insert 되도록 한다.
* 쿼리를 작성하고 사용자 입력을 받을 부분은 ?로 작성, 2번째 인자로 배열을 넣어 ?값을 대체할 값을 넣는다.
* insert된 row의 id값은 콜백함수의 result의 insertId로 알 수 있다.

