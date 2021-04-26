# PhotoLife
### Conway's Game of Life, running in a Photo-frame, on an Arduino
 

#### Summary
 

This project is made from 12x MAX7219 8x8 LED matrices, set up in a 3x4 array. Written by Jack Machiela <jack@pobox.com> (c) 2021

Originally, no available MAX7219 libraries allowed the setup of a matrix other than 1*x - however, matdombrock modified his MatrixGL library just for this purpose. https://github.com/matdombrock/MatrixGL/

NB - At this time, MatrixGL's matrixability feature is in experimental mode only. I will update when MatrixGL goes live.

Conway's Game of Life code shamelessly lifted from gmussi
	https://create.arduino.cc/projecthub/gmussi/conway-s-game-of-life-79bb05

![](https://raw.githubusercontent.com/jackmachiela/PhotoLife/main/Images/Front%20view.JPG)

#### Ingredients

1x Arduino - I used a chinese Uno clone to test with, but it's big and bulky and won't fit into a standard photo-frame. I'll be changing it to a smaller unit next, a pro or a nano, or even a D1-Mini (and add a NTP clock or something).

3x MAX7219 1x4 LED matrices

Some wiring

#### Setup

Hook up the first MAX7219 block to the Arduino:

    LEDs - Arduino
    ---- - -------
    VCC  - MC 5v
    GND  - MC GND
    DIN  - MC Pin 11 (MOSI)
    CS   - MC Pin 10 (SS)
    CLK  - MC Pin 13 (SCK)
    
Next, hook the MAX7219 up to each other, using a zig-zag pattern:

![](https://raw.githubusercontent.com/jackmachiela/PhotoLife/main/Images/Rear%20view.JPG)

The next step is to load the code to the Arduino. The simulation should start working straight away.

![](https://github.com/jackmachiela/PhotoLife/blob/main/Images/Conway's%20Game%20of%20Life%20animated.gif)

The next step I've not completed yet - install it into a photo-frame. I'll be scouring the local second hand shops for a nice frame later this week, will update it here once I'm done.
