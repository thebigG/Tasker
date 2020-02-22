'use strict';
var counter  = 0;
const ioHook = require('iohook');

ioHook.on('keydown', event => {
  console.log('k'); // { type: 'mousemove', x: 700, y: 400 }
  counter +=1;
  console.log(counter);
});

// Register and start hook
ioHook.start();
// Alternatively, pass true to start in DEBUG mode.
// ioHook.start(true);
