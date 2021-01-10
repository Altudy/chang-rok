var mysql = require('mysql');
var db = mysql.createConnection({
  host: 'localhost',
  user: 'rok',
  password: 'rok',
  database: 'opentutorials'
});
db.connect();

module.exports = db;
