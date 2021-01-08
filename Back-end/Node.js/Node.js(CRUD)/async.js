var fs = require('fs');

console.log('A');
fs.readFile('syntax/sample.txt','utf8',function(err,result){
  console.log(result);
});
console.log('C');
