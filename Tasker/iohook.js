'use strict';
var keyCounter  = 0;
var mouseCounter = 0;
var mousudragCounter = 0;
const ioHook = require('iohook');

ioHook.on('keydown', event => {
  console.log('kd'); // { type: 'mousemove', x: 700, y: 400 }
  keyCounter +=1;
  console.log(keyCounter);
});




ioHook.on('mousemove', event => {
  console.log('mm'); // { type: 'mousemove', x: 700, y: 400 }
  mouseCounter +=1;
  console.log(mouseCounter);
});
ioHook.on('mousedrag', event => {
  console.log('md'); // { type: 'mousemove', x: 700, y: 400 }
  mousudragCounter +=1;
  console.log(mousudragCounter);
});
// Register and start hook
ioHook.start();
// Alternatively, pass true to start in DEBUG mode.
// ioHook.start(true);
