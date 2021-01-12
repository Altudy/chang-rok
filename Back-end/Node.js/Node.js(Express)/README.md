# Node.js Express를 실습

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

