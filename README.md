# PhotoLife
### Conway's Game of Life, running in a Photo-frame, on an Arduino
 

#### Summary
 

This project is made from 12x MAX7219 8x8 LED matrices, set up in a 3x4 array. Written by Jack Machiela <jack@pobox.com> (c) 2021

Originally, no available MAX7219 libraries allowed the setup of a matrix other than 1*x - however, matdombrock modified his MatrixGL library just for this purpose. https://github.com/matdombrock/MatrixGL/

NB - At this time, MatrixGL's matrixability feature is in experimental mode only. I will update when MatrixGL goes live.

Conway's Game of Life code shamelessly lifted from gmussi
	https://create.arduino.cc/projecthub/gmussi/conway-s-game-of-life-79bb05


#### Ingredients

1x Arduino - I used a chinese Uno clone to test with, but it's big and bulky and won't fit into a standard photoframe. I'll be changing it to a 
