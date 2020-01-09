# UltraSonicKeyboard

Turn distance into keyboard keys and send them to a midi controller.

* Download and import this C library : [FortySevenEffects/arduino_midi_library](https://github.com/FortySevenEffects/arduino_midi_library)

* Update the firmware on the arduino using the dfu-programmer command, here are some instructions: [Arduino Hacking DFU](https://www.arduino.cc/en/Hacking/DFUProgramming8U2)

* Instead of downloading the latest firmware .hex file you need to create a custom firmware .hex file.
This way your synthesizer sees the device as a MIDI controller.  Give it a name like "my sick air keyboard"

  - Create the firmware .hex using [this cool tool](https://moco-lufa-web-client.herokuapp.com/?fbclid=IwAR1aLxlGCeSg2yJhYIAy8dNwltufS-fH8UXQbumNyp7JzTfJLPoeURhBZwM#/)

* Once dfu-programmer has installed the custom firmware you need to jump some pins in order to get the Arduino IDE to recognize your device when you plug it in to usb.

  - Add a wire or a two pole toggle switch to the pins in the image below.  Connect the pins and boot the device when you want to connect the Arduino IDE to the device and deploy code.  Disconnect the pins and reboot the device to get it to be a midi controller.


![Image of Jumper Pins](https://raw.githubusercontent.com/ElliotTheGreek/UltraSonicKeyboard/master/ArduinoMidiPins.png)
