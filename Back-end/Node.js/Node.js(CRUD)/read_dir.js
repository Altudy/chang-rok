var folder = './data';
var fs = require('fs');

fs.readdir(folder,function(err,filelist){
  console.log(filelist);
})
