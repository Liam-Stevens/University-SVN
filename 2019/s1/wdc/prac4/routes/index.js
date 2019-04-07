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

router.get('/colour.html', function (req, res, next) {
  
  res.send('<h1 style="color:'+colorVis+'">'+colorVis+'</h1>');
	
  colorTag++;
  if (colorTag > 3)
  {
  	colorTag = 0;
  }
  if (colorTag == 0)
  {
  	colorVis = "red";
  }
  else if (colorTag == 1)
  {
  	colorVis = "yellow";
  }
  else if (colorTag == 2)
  {
  	colorVis = "green";
  }
  else if (colorTag == 3)
  {
  	colorVis = "blue";
  }
});

router.get('/log.html', function (req, res, next) {
  var dateAdd = "<li>"+Date()+"</li>";
  dateList = dateList.concat(dateAdd);
  res.send(dateList);
});

module.exports = router;
