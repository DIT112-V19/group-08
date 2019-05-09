function openBluetooth(){
	
console.log('Requesting Bluetooth Device...');
  navigator.bluetooth.requestDevice({
	  acceptAllDevices: true,
	  optionalServices: ['battery_service']})
  .then(device => {
    console.log('Connecting to GATT Server...');
    return device.gatt.connect();
  })
  .then(server => {
    console.log('Getting Battery Service...');
    return server.getPrimaryService('battery_service');
  })
  .then(service => {
    console.log('Getting Battery Level Characteristic...');
    return service.getCharacteristic('battery_level');
  })
  .then(characteristic => {
    console.log('Reading Battery Level...');
    return characteristic.readValue();
  })
  .then(value => {
    let batteryLevel = value.getUint8(0);
    console.log('> Battery Level is ' + batteryLevel + '%');
  })
  .catch(error => {
    console.log('Argh! ' + error);
  });
}


