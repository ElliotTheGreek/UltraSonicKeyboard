# UltraSonicKeyboard

Turn distance into keyboard keys and send them to a midi controller.

Download and import this C library :https://github.com/FortySevenEffects/arduino_midi_library 

Update the firmware on the arduino using the dfu-programmer command, here are some instructions:
https://www.arduino.cc/en/Hacking/DFUProgramming8U2

Instead of downloading the latest firmware .hex file you need to create a custom firmware .hex file.
This way your synthesizer sees the device as a MIDI controller.  Give it a name like "my sick air keyboard"

Here is a cool tool to create the firmware .hex for you: https://moco-lufa-web-client.herokuapp.com/?fbclid=IwAR1aLxlGCeSg2yJhYIAy8dNwltufS-fH8UXQbumNyp7JzTfJLPoeURhBZwM#/

Once dfu-programmer has installed the custom firmware you need to jump some pins in order to get the Arduino IDE to recognize your device when you plug it in to usb.
