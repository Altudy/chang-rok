# Node.js Express를 실습

## Express의 주요 기능

* 라우팅 : if문이 아닌 app.get, app.post 경로를 설정해준다.

* 미들웨어 : 다른 사람이 만든 소프트웨어를 부품으로 나의 제품을 만든다.


## Hello word

* npm install express --save로 설치.
* express module require, const app = express()로 시작.
* app.get과 app.listen으로 시작.
* 기존의 if문으로 routing을 구현하던 것을 app.get으로 routing(가독성 up)

## 홈페이지 구현

* 기존의 코드 부분을 옮기고 response.writeHead 와 response.end 부분을 묶어서 response.send()로 바꿈.

## 상세보기 페이지 구현

* ?id=1 로 받았던 url을 바꿈.
* /page/:pageId 로 설정하면 url입력시 /page/5 로 입력을하면 pageId: 5 로 할당이 된다.
* 이것을 이용하여 코드 수정.

## 페이지 생성 구현

* create 페이지는 상세보기 페이지와 같이 구현.
* create의 제출 버튼을 누르면 post 방식으로 submit하므로 create_process는 app.post로 명시

## 페이지 수정 기능 구현

* 상세보기 페이지에서 update에 해당하는 <a> 태그의 href를 /update/${title} 이 오도록 바꾼다.
* app.get(/update/:pageId') 로 설정해 request.params.pageId 로 값을 받는다.
  
## 페이지 삭제 기능 구현

* 상세보기 페이지의 delete 버튼 form의 action에 "delete_process"로 해주어 /page/delete_process로 url이 바뀜.
* 이를 고치기 위해 action을 "/delete_process"로 수정.
* redirect 함수를 이용하기 위해 response.redirect('/')로 설정하여 삭제후 main page로 리다이렉트 됨.

## Express 미들웨어의 사용

* 미들웨어중 body-parser를 이용해 본다.
* npm install body-parser --save 명령으로 nodemodule에 body parser module을 넣어준다.
* app.user(bodyParser.urlencoded({ extend : false }) 로 bodyParser를 이용
* 기존 create_process 부분은 body 변수를 선언하고 request.on으로 data를 받아 더해가는 방식
* bodyParser를 이용하면 resquest.body;로 쉽게 받을 수 있다.
* update_process와 delete_process도 위와 같이 수정.

* 미들웨어중 compression를 이용해 본다.
* description부분의 양이 많을 경우 데이터를 압축시켜서 전달하면 효율적이다.
* npm install compression --save 명령으로 nodemudule에 compression modile을 넣어준다.
* app.use(compression()) 으로 사용. ( compression() 함수가 module을 return 해준다.)

## Express 미들웨어 만들기

* 코드에서 fs.readdir 로직을 반복적으로 사용하므로 이를 미들웨어로 만든다.
* app.use() 내의 함수 부분에 선언을 하고 3번째 매개변수로 next를 주어 next() 함수를 실행시킴으로써 미들웨어 동작.
* 코드 상 get부분만 fs.readdir 로직을 사용하므로 app.get("\*") 선언을 통해 미들웨어를 이용한다.




