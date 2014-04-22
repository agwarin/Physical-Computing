
//button and pot
// old stuff
var connect = require('connect'),
	fs = require('fs'),
	util = require('util'),
	io = require('socket.io').listen(9001), // WS port
	port = 9000, // HTTP port
	
	// new stuff
	// define a class
	//using the name of the file
	SerialPort = require("serialport").SerialPort,
	// ls /dev/tty.*
	//sPort = "/dev/tty.usbserial-AM01PK24", old one
	sPort = "/dev/tty.usbserial-AM01PK11",
	// create an instance (object)
	arduino = new SerialPort(sPort, {
		baudrate: 9600
	});



// create web server using connect 
connect.createServer(
	connect.static(__dirname + '/public') // two underscores
).listen(port);
util.log('the server is running on port: ' + port);



// init socket.io
io.set('log level', 1);
//The amount of detail that the server should output to the logger.0 - error, 1 - warn, 2 - info, 3 - debug
//log requests with the given options or a format string
io.sockets.on('connection', function(socket) {
	util.log('Ooooooh, someone just poked me :)');
	socket.on('led', function(data) {
		// sending binary data
		//Buffers are instances of the Buffer class in node, which is designed to handle raw binary data, 
		//Buffers act like arrays of integers
		//the "integers" in a buffer each represent a byte and so are limited to values from 0 to 255

		var ledOn = new Buffer(1), // Buffer is an array and Buffer(1) means 1 index array,--> contains 1 byte?
			ledOff = new Buffer(1);
		ledOn[0] = 0x01; // 1
		ledOff[0] = 0x00; // 0
		// shorthand ledOn = new Buffer([0x01])



		//this is data coming from the index file, look at the boolean
		if(data === true) {
			// turn on
			arduino.write(ledOn);
			util.log('LED ON'); //writing to terminal
		} else {
			// turn off
			arduino.write(ledOff);
			util.log('LED OFF');
		}
	});

});

// function that converts int to hexadecimal
// we communicate to Arduino using hex (binary) 

// serial port
var receivedData, sendData;
var receivedDataButton, sendDataButton;

arduino.on('open', function() {
	console.log('opening port');
	//  console.log((11).toString(16));
	// setInterval(toggle, 1000);
});

// receive data, the measurements from the potentiometer
arduino.on('data', function(data) { // data comes in Buffer <   >
	// try removing toString()
	
	//util.log(data);
	//this is for the pot
	receivedData += data;
	// basically says if there're 'E' and 'B' signals
	if (receivedData.indexOf('E') >= 0 && receivedData.indexOf('B') >= 0) {
		// save the data between 'B' and 'E'
		sendData = receivedData.substring(receivedData.indexOf('B') + 1, receivedData.indexOf('E'));
		receivedData = ''; ///define and assign later, like empty string
		util.log("the received data is="+receivedData);
		util.log(sendData);
		// parse data to browser
		io.sockets.emit('pot', sendData); //emit is to send
		// socket.io
		// emit, on, broadcast.emit, io.sockets.emit
		}

		
	//now with analog button
	util.log("The data coming out is="+data);
	receivedDataButton+=data;
		if (receivedDataButton.indexOf('J') >= 0 && receivedDataButton.indexOf('K') >= 0) {
				sendDataButton=receivedDataButton.substring(receivedDataButton.indexOf('J') + 1, receivedDataButton.indexOf('K'));
				receivedDataButton = '';
				//util.log(sendDataButton);
				util.log("dataButton="+sendDataButton);
				// parse data to browser
				io.sockets.emit('ardButton', sendDataButton); //emit is to send

		}//end of if button
		


});