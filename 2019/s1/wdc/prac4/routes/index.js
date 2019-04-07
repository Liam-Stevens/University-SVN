var express = require('express');
var router = express.Router();

var date = "";
var colorTag = 0;
var colorVis = "red";
var dateList = "";

/* GET home page. */
router.get('/', function(req, res, next) {
  res.render('index', { title: 'Express' });
});

router.get('/last.txt', function (req, res, next) {
  res.send(date);
  date = Date();
});



module.exports = router;
