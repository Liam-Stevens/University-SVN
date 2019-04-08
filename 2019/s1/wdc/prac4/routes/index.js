var express = require('express');
var router = express.Router();

var date = "";
var colorTag = 0;
var colorTag2 = 0;
var colorVis = ["red", "yellow", "green", "blue", "red", "yellow", "green", "blue"];
var dateList = "";

/* GET home page. */
router.get('/', function(req, res, next) {
  res.render('index', { title: 'Express' });
});

router.get('/last.txt', function (req, res, next) {
  res.send(date);
  date = Date();
});

router.get('/colour.html', function (req, res, next) {
  
  res.send('<!DOCTYPE html> \
			<html lang="en"> \
			<head> \
			<meta charset="UTF-8"> \
			<title>  \
			Colour Stuff \
			</title> \
			</head> \
			<body> \
			<h1 style="color:' + colorVis[colorTag] + '">' + colorVis[colorTag] + '</h1> \
			</body> \
			</html>'); 
  colorTag = colorTag + 1;
});

router.get('/log.html', function (req, res, next) {
  var dateAdd = "<li>" + Date() + "</li>";
  dateList = dateList.concat(dateAdd);
  res.send('<!DOCTYPE html> \
			<html lang="en"> \
			<head> \
			<meta charset="UTF-8"> \
			<title>  \
			Colour Stuff \
			</title> \
			</head> \
			<body><ul>' + dateList + '</ul></body> \
			</html>');
});

router.get('/colour.txt', function (req, res, next) {
  
  res.send(colorVis[colorTag2]); 
  colorTag2 = colorTag2 + 1;
});

router.get('/contact.ajax', function (req, res, next) {
  res.send('<a href="a1742143@student.adelaide.edu.au">Link to my Email</a>');
});

router.get('/search.ajax', function (req, res, next) {
  res.send('<input type="text"> \
  			<button>Search</button>');
});

module.exports = router;
