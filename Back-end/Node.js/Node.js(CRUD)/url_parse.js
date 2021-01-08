var http = require('http');
var fs = require('fs');
var url = require('url');

var app = http.createServer(function(request,response){
  var _url = request.url;
  //url parsing
  var queryData = url.parse('http://localhost:3000/?id=5', true).query;

  if(_url == '/'){
    _url = './index.html';
  }
  if(_url == '/favicon.ico'){
    response.writeHead(404);
    response.end();
    return;
  }

  response.writeHead(200);
  //5 출력
  response.end(queryData.id);
});

//port num 3000으로 server start
app.listen(3000);
