var express = require('express');
var router = express.Router();

var posts = [];

/* GET users listing. */
router.get('/', function(req, res, next) {
    res.send('respond with a resource');
});

router.post('/addpost', function (req, res, next) {

    posts.push({title:req.body.title,
                content:req.body.content });

    res.end();
});

router.get('/getposts', function (req, res, next) {
    res.json(posts);
});

module.exports = router;
