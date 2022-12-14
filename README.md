# blooper-polysynth
The Blooper - A Teensy Powered, Arduino Controlled 8 ( or 7+1) Voice polyphonic Synthesizer!

This project has two main components:

 - A Teensy 4.1 with Audio board providing the audio generation and processing
 - An Arduino Nano handling IO and communicating with the Teensy via MIDI


**Features**
TODO




**Acknowledgements**: 
I've dabbled in programming over the years but have never really done it seriously, and had never used an arduino-like microcontroller prior to taking this on so this project was/is an excellent way to learn about it. There are some fantastic resources out there to which I am very grateful: 


 - Notes and Volts - For the excellent tutorial series on the TS1 project. Those videos are a fantastic introduction to Teensy Audio and the Blooper is essentially a continuation of the ideas introduced there. https://www.youtube.com/watch?v=UJcZxyB5rVc&list=PL4_gPbvyebyHi4VRZEOG9RKOYq5Hre3a1&ab_channel=NotesandVolts
 - Analog Output, for the genius idea for making front panels: https://www.youtube.com/watch?v=-8sNB2UjLAo&ab_channel=AnalogOutput
 - hexeguitar's Hx Phaser - https://github.com/hexeguitar/t40fx/tree/main/Hx_Phaser
 - quarterturn Chorus Ensemble effect: https://github.com/quarterturn/teensy3-string-machine/blob/master/teensy3-string-synth/teensy3-string-synth.ino

 - troisiemetype's teensymoog. I don't think anything was directly lifted from this, but I studied the code & Audio Design while trying to work out a few concepts, most notably polyphony. https://github.com/troisiemetype/teensymoog

And finally Look Mum No Computer, both for the introduction to DIY synthesizers, and because the mantra "Don't be scared to try it" led me down this rabbit hole (albeit with computers)... https://www.youtube.com/@LOOKMUMNOCOMPUTER
