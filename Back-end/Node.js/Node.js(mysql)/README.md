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

## mysql로 글생성 기능 구현(create)

* create 버튼 누를 시 쿼리를 통해 database에 insert 되도록 한다.
* 쿼리를 작성하고 사용자 입력을 받을 부분은 ?로 작성, 2번째 인자로 배열을 넣어 ?값을 대체할 값을 넣는다.
* insert된 row의 id값은 콜백함수의 result의 insertId로 알 수 있다.

## mysql로 글수정 기능 구현(update)

* update 버튼 누를 시 목록을 가져오고(select * from topic), title과 description을 사용자 입력으로 받아(input tag) submit한다.
* update_process에서 qs.parese(body)를 통해 id,title,description에 각각 접근 할 수 있게 한다.
* 그 후 query를 통해 database에 update해준다.

## mysql로 글삭제 기능 구현(delete)

* delete 버튼 누를 시 delete_prcoess에서 쿼리를 통해 datebase의 id에 해당하는 row를 삭제한다.

## join을 이용해서 상세보기 구현

* 기존의 목록을 누르면 나오는 화면에 topic의 저자가 누구인지 보이게 하려고 한다.
* left join 속성을 이용하여 기존의 쿼리문(select * from topic where id=?)을 새롭게 바꾼다. (select * from topic left join author on topic.author_id = author.id where topic.id=?)

## join을 이용해서 글생성 구현

* 기존의 create 기능을 업그레이드 한다.(database에서 author의 name을 불러와서 select, option 속성을 통해 사용자가 저자의 이름을 지정할 수 있게 한다.)
* select tag의 name속성으로 submit이 값을 읽을 수 있음.

# join을 이용해서 글수정 구현

* 글수정시 저자의 이름도 나타나게 한다.(author_id에 따른 저자가 selected되게 한다.)
* 기존의 template.js에서 Object template에 추가된 function authorSelect를 2번째 매개변수로 author_id를 받도록 수정한다.
* tag에 option html코드를 더해 나갈 시 루프를 돌면서 author[i].id와 author_id가 같다면 selected 속성이 추가되도록 한다.

# 정리정돈 - db

* main.js의 코드의 가독성이 떨어지므로 main.js의 전체 파일에서 해당 로직들을 여러 js파일로 분리 작업 실행.
* db접속에 해당하는 부분을 lib폴더 밑에 db.js에 넣음.(마지막에 module.exports = db)
* 실제 버젼관리 시에는 db정보를 공유하면 안되므로 해당 값을 빈값으로 한 de.template.js로 버젼관리해서 공유하고 그걸 이용해서 db.js 파일을 만듬.

# 정리정돈 - topic

* lib 폴더 밑에 topic.js 파일을 만들고 db의 topic table을 이용한 코드 부분을 따로 뺀다.
* 기존 홈화면 부분을 topic.home(reuqest,response)로 바꾸고 topic.js에서 exports.home = function(request,response){}로 바꿈.
* 위와 같은 방식으로 create,update,delete 진행.

# 저자 목록 보기 기능의 구현

* 메인 화면에 author page로 이동할 수 있는 <a> 태그를 만든다.
* css table 속성을 이용해 database에서 author의 이름을 표 형식으로 출력한다.

# 저자 생성 기능 구현

* author page에 name과 description을 쓰고 제출할 수 있는 form 생성.
* 제출시 name와 profile(description)이 database에 insert되고 /author 로 리다이렉트 됨.

# 저자 수정 기능 구현

* update 클릭시 create와 유사한 형태로 form 생성된다.
* form의 input요소(name,profile)은 database에서 queryData.id를 통해 가져온 author[0]의 name과 profile을 보여준다.
* 그 후, update 버튼 클릭 시 database에 update 된다.

# 저자 삭제 기능 구현

* delete 클릭시 database에서 author와 topic의 정보를 삭제한다.
* topic table에서 author_id에 해당하는 row를 삭제 후, author table에서 해당 row를 삭제.

# SQL Injection

* 공격의 의도를 가진 sql 코드를 방어하는 법.
* 사용자의 파라미터를 받는 부분에 sql코드를 넣어 공격할 수 있기 때문에 ?로 쓰고 그 뒤에 배열의 형태로 파라미터를 받는다.
* 기본적으로 쿼리의 다중 수행은 막혔기 때문에 위와 같은 방법은 실행안됨.(하지만 ?로 파라미터 받는 방법으로 코드 작성)

# escaping

* 공격의 의도를 가진 자바스크립트 코드를 입력해서 웹 브라우저를 공격하는 Cross site scripting(XSS)를 sanitizehtml 모듈을 이용해서 방어.
