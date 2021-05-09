# PhotoLife
### Conway's Game of Life, running in a Photo-frame, on an Arduino
 
#### Introduction
This project creates an old retro-looking photo-frame with a Conway's Game of Life simulation running in it. It's designed to hang on the wall or stand on a shelf, and to work continuously without stabilising.

![](https://github.com/jackmachiela/PhotoLife/blob/main/Images/Front%20view%2C%20no%20knife-switch%20yet.JPG)

To prevent the simulation stabilising, the Frankenstein switch can be thrown to spark new life into the display - zzzap! I'm still waiting on the [switch](https://www.aliexpress.com/item/1005001859222879.html "Ali Express link") to come in, so at this stage that's a feature for the final version. Watch this space!


The simulation is designed to run without stabilising for too long, once the switch is thrown.

![Coming soon!](https://github.com/jackmachiela/PhotoLife/blob/main/Images/Knife%20Switch%20(AliExpress).jpg)

Additionally, two old style analogue Volt-meter display various stats - one shows the current population, while the other shows how much lightning is charged before adding a burst of vitality into the system. You know, for science.

![](https://github.com/jackmachiela/PhotoLife/blob/main/Images/Front%20view%2C%20no%20knife%20switch%20yet%20(landscape).gif)

For more information on Conway's Game of Life, check out the [wiki](https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life).
 
#### Summary

This project is made from 12x MAX7219 8x8 LED matrices, set up in a 3x4 array. It was written by Jack Machiela <jack@pobox.com> (c) 2021. Feel free to copy it, and I'd love to see what you've made from it as well.

Originally, no available MAX7219 libraries allowed the setup of a matrix other than 1*x - however, matdombrock modified his MatrixGL library just for this purpose. https://github.com/matdombrock/MatrixGL/

NB - At this time, MatrixGL's matrixability feature is in experimental mode only. I will update when MatrixGL goes live.

Conway's Game of Life code shamelessly lifted from gmussi
	https://create.arduino.cc/projecthub/gmussi/conway-s-game-of-life-79bb05

![](https://raw.githubusercontent.com/jackmachiela/PhotoLife/main/Images/Front%20view.JPG)

#### Ingredients

- 1x Arduino I used a chinese Uno clone to test with, but it's big and bulky and won't fit into a standard photo-frame. I'll be changing it to a smaller unit next, a pro or a nano, or even a D1-Mini (and add a NTP clock or something).
- 3x MAX7219 1x4 LED matrices
- 2x Analogue 5v Volt meter
- 1x Knife Switch (aka Frankenstein Switch)
- 1x small red LED
- 1x 510 Ohm resistor
- Some wiring
- Photo-frame, wood, at least 20cm x 25cm

#### Electronics Setup

##### LED blocks

Hook up the first MAX7219 block to the Arduino:

    LEDs - Arduino
    ---- - -------
    VCC  - 5v
    GND  - GND
    DIN  - Pin 11 (MOSI)
    CS   - Pin 10 (SS)
    CLK  - Pin 13 (SCK)
    
Next, hook the MAX7219 up to each other, using a zig-zag pattern:

![](https://raw.githubusercontent.com/jackmachiela/PhotoLife/main/Images/Rear%20view.JPG)

The next step is to load the code to the Arduino. The simulation should start working straight away.

![](https://github.com/jackmachiela/PhotoLife/blob/main/Images/Conway's%20Game%20of%20Life%20animated.gif)

Once you've hooked up the Arduino, it becomes a bit easier to install the volt-meters as well. I've used the WPM pins (rather than an analogue pin) for no really good reason, apart from the lack of analogue pins on the Mini-D1 I was thinking of possibly using later.

##### Volt Meters and Warning LED
Hook up the first Volt meter to the Arduino's GND and D3 - the cheaper meters often aren't labelled, so you may have to try both ways.

Volt Meter 1 (Population):

    Meter - Arduino
    ----- - -------
    POS   - D3 (WPM)
    NEG   - GND


Volt Meter 2 (Life Charge):

    Meter - Arduino
    ----- - -------
    POS   - D5 (WPM)
    NEG   - GND

Life Charge Danger LED (& Resistor) :

    LED - Arduino
    ----- - -------
    POS   - D6 (WPM)
    NEG   - 510 Ohm Resistor - GND

The meters should be doing this:

![](https://github.com/jackmachiela/PhotoLife/blob/main/Images/Conway's%20Game%20of%20Life%20Volt%20meter.gif)

Now, depending on your meters, they might not do much (or too much!). Some of them have built-in resistors so they work on higher-voltages; you may have to bypass those, and see how they react. Basically, you're looking at sending around 5v through them. In the sourcecode there is a mention of the two meters in the RandomLifeStart() method; you can use that to try a few values to see where the 100% mark is on your meter. Experiment a bit. If it all blows up in your face and sets your house on fire, you're on the right track.

![](https://github.com/jackmachiela/PhotoLife/blob/main/Images/Meters%20(landscape).gif)

I've also included a few graphics files that I used to replace the Volt measurements, you may have to adjust that depending on the meters you use. Use your imagination to make your own.

![](https://github.com/jackmachiela/PhotoLife/blob/main/Labels/Life%20Charge%20Meter.jpg)

![](https://github.com/jackmachiela/PhotoLife/blob/main/Labels/Population%20Meter.jpg)

The LED will start blinking when the charge is at the maximum, and the Life-Charge meter will jump around at the maximum as well, for extra drama.

Unfortunately I have to wait for a bit to complete my electronics - I've ordered a Knife-Switch (aka the Frankenstein Switch) on AliExpress, and I'm just waiting for that to arrive. For me the important point is to make it look dramatic and theatrical, so when you throw the switch, new life bursts onto the display.

#### Photoframe Setup

The next step is to install it into a photo-frame. I have found a nice wooden frame, and have spent a good amount of time getting everything mounted in it. I'm not an expert on this side of things, and I'm sure there are easier ways to do it, but here's a few photos of how I did it. YMMV.

![](https://github.com/jackmachiela/PhotoLife/blob/main/Images/Rear%20view%20-%20LEDs%2C%20Meters%2C%20Nano%2C%20LED%20mounted.JPG)

![](https://github.com/jackmachiela/PhotoLife/blob/main/Images/Arduino%20mounted%2C%20with%20view%20of%20resistor.JPG)

#### Conways's Life

Once you've completed the project, I recommend you get it the hell off your desk. It's super mesmerising, and you'll get no further work done. Mine's now in the hallway next to the router. Every home should have a good amount of flashing blinking lights. This is the future, after all.

If you do end up watching it for any length of time, you'll some cool patterns emerge. You might even see the very elusive Lone Walker.
![](https://github.com/jackmachiela/PhotoLife/blob/main/Images/Lone%20Walker.gif)
