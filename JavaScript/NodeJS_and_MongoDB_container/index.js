var mongodb = require("mongodb").MongoClient
mongodb.connect("mongodb://localhost/test_database", function(error, db) {
	if (!error) console.log("MongoDB works !")
	else console.log("MongoDB error !")
})

// Start express
var express = require('express')
var app = express()

app.get('/', function (req, res) {
	res.send('The minimal NodeJS and MongoDB container is running!')
})

app.listen(8081, function () {
	console.log('Start listenning 8081 port')
})
