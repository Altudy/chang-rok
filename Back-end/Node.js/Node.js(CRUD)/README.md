# Node.js를 통해 CRUD 시스템 구현하는 실습

**main.js(node.js의 웹서버 구현)**
```
1. request.url로 url 정보를 얻는다.
2. response.end()로 결과를 실행.
```

**url_parse.js(url를 parsing한 data를 이용)**
```
1. url.parse().query method를 이용하여 queryData 값을 얻는다.
1-1) option으로 true를 주면 Object로 반환한다.
2. response.end(queryData.id)로 결과 확인.
```

**dynamic_web.js(동적으로 웹페이지 구현)**
```
1. url query의 id에 동적으로 값을 준다.
2. 그 값을 title 변수에 저장하여 template에 이용한다.
3. ${title} 형식으로 query id 값에 따라 동적으로 웹페이지 구현.
```

**read_file.js(파일 읽기)**
```
1. 같은 디렉토리 내에 파일을 만들어두고 그 값을 읽는다.
2. fs 변수 선언해주고 readFile method를 통해 파일을 읽는다.
```

**read_file2.js(파일 읽어서 본문 구현)**
```
1. url의 id값에 변화를 주면서 페이지를 로드한다.
2. cmd창에서 node read_file2.js 명령을 재실행 하지 않고도 data 디렉토리 안의 내용을 바꿔도 바로 반영이 된다.
```

**console_input.js(콘솔창에서의 입력)**
```
1. process.argv를 통해 사용자 입력을 받는다.
2. index 2부터 사용자 입력을 받게 됨을 주의한다.
```

**not_found.js(Not Found 오류 구현)**
```
1. url.parse().pathname을 이용하여 '/'가 아닌 다른 경로로 들어온다면 'Not Found' message가 보이게 한다. 
```

**homepage.js(홈페이지 구현)**
```
1. not_found.js에서의 구현을 보면 '/'로 들어오면 title과 descripttion이 undefined로 실행된다.
1-1. 또 다른 조건문을 주어 id의 값이 없을때 homepage가 나오도록 구현하였다.
```

**read_dir.js(파일 목록 알아내기)**
```
1. homepage.js에서 template 부분의 ul의 li는 유동적으로 바뀔수 있다.
1-1. 그러기 위해서 data folder의 파일 목록을 알아낸다면 적용시킬 수 있다.
```

**read_dir2.js(글목록 출력하기)**
```
1. read_dir.js에서 이용한 readdir method를 통해 실제로 적용시켜본다.
2. data folder에 Node.js를 추가하면 재실행하지 않고도 새로고침을 통해 페이지가 동적으로 변한 것을 확인 할 수 있다.
```

**function.js(함수를 이용해서 정리 정돈하기)**
```
1. 전체적으로 반복되는 코드가 많아서 전체 코드의 길이가 길어진다.
1-1. function을 이용하여 길어진 코드를 보기 깔끔하게 수정한다.
```

**sync.js(동기적 수행)**
```
1. 동기적으로 수행하여 A, B, C 순으로 출력한다.
```

**async.js(비동기적 수행)**
```
1. 비동기적으로 수행하여 A, C, B 순으로 출력한다.
```

**callback.js(콜백함수)**
```
1. node.js에서는 함수도 값이라는 점.
2. 비동기적 수행을 위해 콜백함수를 사용.
2-1. slowfunc에서 callback함수를 부르는데 slowfunc(a); 를 실행시키면 slowfunc안의 callback 함수로 a가 실행된다.
```

**Package Manager**
```
1. npm install pm2 -g 로 설치
2. pm2를 이용하면 js파일 수정시 다시 껐다가 켤 필요없지 자동으로 해준다.
3. pm2 start main.js 로 시작
3-1. --watch 옵션을 주면 자세히 볼 수 있다.
4. pm2 stop main 으로 멈춤
5. pm2 log 를통해 error나 바뀐 정보를 알 수 있다.
6. pm2 monit 을 통해 pm2에 의해 실행중은 process가 보임.
7. pm2 list 를 통해 실행중인 list를 확인 가능하다.
```

**create.js(글생성 UI 만들기)**
```
1. create anchor tag를 만들어서 클릭시 title, description를 입력할 수 있는 form page로 이동
2. 입력 후 제출시 processss_create로 이동.
```

**form_post.js(post방식으로 전송된 데이터 받기)**
```
1. request.on('data',function(data)) 로 data를 받는다.
2. request.on('end',function()) 로 data 받는 것이 끝난 다음을 처리해준다.
2-1. node.js의 내장모듈인 require('querystring')을 이용하여 qs.parse(body)로 data를 읽는다.
2-2. 읽은 data의 input tag의 name값에 맞추어서 값을 읽는다.
```

**write.js(파일생성과 리다이렉션)**
```
1. form으로 입력받은 데이터를 writeFile method를 통해 data folder에 저장한다.
2. 저장 후, 입력받은 데이터를 보여주는 페이지로 리다이렉트한다.
2-1. redirect는 response.writeHead(302);
```

**update.js(글수정)**
```
1. 수정 링크 생성
1-1. '/'가 아닌 다른 path에서는 update를 할 수 있게 한다.
2. 수정할 정보 전송
2-1. form형식을 통해 update_process로 데이터를 전송한다.
2-2. 기존에 있던 title이 바뀔 수도 있으므로 id값을 hidden 옵션을 주어 같이 전송한다.
2-3. 전송된 id(기존의 파일 이름)을 title(새로바뀐 파일 이름)로 파일을 rename한다.
2-4. 그 후 writeFile 한다.
3. 수정된 내용 저장
```

**delete.js(글삭제)**
```
1. '/'가 아닌 경로에 delete 버튼을 생성.
2. 버튼 클릭시 특정 url로 이동하는 것이 아닌 바로 삭제할 것이라 form 형식으로 구성
3. fs.unlink method를 이용하여 파일 삭제, 삭제 후에는 '/'로 redirect
```

**Object.js(객체를 이용해서 템플릿 기능 정돈)**
```
1. 코드가 길어진다면 templateList, templateHTML을 읽는데 어려움을 겪을 수 있다.
2. template이라는 객체를 이용하여 각각의 함수를 객체화 하여 관리한다.
```

**muse.js , mpart.js(모듈의 형식)**
```
1. 모듈은 객체를 관리
2. module.exports에 객체 값을 부여하면 다른 js파일에서 require를 이용하여 사용 가능
```

**module.js , template.js(모듈의 활용)**
```
1. 기존 코드에 있던 template 변수에 할당된 값들을 모듈 형식을 이용하여 구조를 바꾸어본다.
2. template 부분을 template.js로 옮기고 module.exports = template; 을 통해 외부에서 참조 가능하게 한다.
3. 기존 코드에서는 require('./lib/template.js'); 을 통해 모듈 불러온다.
```

**security.js(입력정보에 대한 보안)**
```
1. url을 통해 id값으로 '../password.js'를 찾으면 그에 해당 정보가 보여진다.
1-1. user의 개인정보라고 가정했을때 이를 위해 보안의 개념을 도입하도록 한다.
2. 1의 입력에도 해당 정보가 보여지지 않도록 하기 위해 path.parse().base를 이용한다.
2-1. 그러면 ../password.js 입력에도 password.js로 path를 찾게되어 url을 통해 서버의 디렉토리 구조에 접근 할 수 없다.
```

**sanitized.js(출력정보에 대한 보안)**
```
1. 기존 코드에서 create시 description부분에 <script>alert('merong')</script>을 주면 문자열로 나타나는 것이 아닌. 실제 javascript로 동작한다.
2. 이것을 막기 위해 npm의 sanitize-html을 이용한다.
2-1. npm init후, npm install -S sanitize-html
3. 그후 title,description을 사용자 입력 받아 sanitize하면 script부분은 사라진다.
4. 이를 허용하기 위해 2번째 인자로 allowedTags 옵션을 주어 허용 가능
```
