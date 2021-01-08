var http = require('http');
var fs = require('fs');
var app = http.createServer(function(request,response){
    var url = request.url;
    if(request.url == '/'){
      url = '/index.html';
    }
    if(request.url == '/favicon.ico'){
      return response.writeHead(404);
    }
    response.writeHead(200);
    //지정된 경로에서 시작
    response.end(fs.readFileSync(__dirname + url));

});

//port num 3000으로 server start
app.listen(3000);
