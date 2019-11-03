var express = require('express')
var app = express()

app.get('/', function (req, res) {
  res.send('The minimal NodeJS container is running!')
})

app.listen(8081, function () {
  console.log('Start listenning 8081 port')
})
