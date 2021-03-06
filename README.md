# UltraSonicKeyboard

Turn distance into keyboard keys and send them to a midi controller.

* Download and import this C library : [FortySevenEffects/arduino_midi_library](https://github.com/FortySevenEffects/arduino_midi_library)

* You need to update the device firmware.  Instead of downloading the latest firmware .hex file you need to create a custom firmware .hex file. This way your synthesizer sees the device as a MIDI controller.  Give it a name like "my sick air keyboard"

  - Create the firmware .hex using [this cool tool](https://moco-lufa-web-client.herokuapp.com/?fbclid=IwAR1aLxlGCeSg2yJhYIAy8dNwltufS-fH8UXQbumNyp7JzTfJLPoeURhBZwM#/)
  
* Update the firmware on the arduino with the .hex you created using the dfu-programmer command, here are some instructions: [Arduino Hacking DFU](https://www.arduino.cc/en/Hacking/DFUProgramming8U2)


* Once dfu-programmer has installed the custom firmware you need to jump some pins in order to get the Arduino IDE to recognize your device again when you plug it in to usb.

  - Add a wire or a two pole toggle switch to the pins in the image below.  Connect the pins and boot the device when you want to connect the Arduino IDE to the device and deploy code.  Disconnect the pins and reboot the device to get it to be a midi controller.

![Image of Jumper Pins](https://raw.githubusercontent.com/ElliotTheGreek/UltraSonicKeyboard/master/ReferenceImages/ArduinoMidiPins.png)

* With the pins connected, connect the device to your computer and deploy DistanceNotes.h to it using the Arduino IDE.

* Once it is finished disconnect the device from power and disconnect the jumper pins from the image above.

* Now when you plug the device back in over usb it will be available as a MIDI instrument to any sythesizer on your computer.
