
// PhotoLife v1.1 - Photoframe-sized Conway's Game of Life, made from 12x MAX7219 8x8 LED matrices, set up in a 3x4 array.
//
//           Written by Jack Machiela <jack@pobox.com> (c) 2021
//           
//           Originally, no available MAX7219 libraries allowed the setup of a matrix other than 1*x - however, matdombrock
//           modified his MatrixGL library just for this purpose. https://github.com/matdombrock/MatrixGL/
//
//           NB - At this time, MatrixGL's matrixability feature is in experimental mode only. I will update when MatrixGL goes live.
//
//           Conway's Game of Life code shamelessly lifted from gmussi - https://create.arduino.cc/projecthub/gmussi/conway-s-game-of-life-79bb05
// 


/*
 * Matrix VCC - MC 5v
 * Matrix GND - MC GND
 * Matrix DIN - MC Pin 11 or MOSI
 * Matrix CS  - MC Pin 10 or SS
 * Matrix CLK - MC Pin 13 or SCK
 */
 
#include <MatrixGL.h>

#define CLK_PIN   13  // SCK  //13    white  CLK
#define DATA_PIN  11  // MOSI //11    purple DIN
#define CS_PIN    10  // SS   //10    grey   CS

#define MAX_DEVICES 12
#define MDX 4 //Amount of matrices on the X axis
#define MDY 3 //Amount of matrices on the Y axis

MatrixGL matrix(CLK_PIN,DATA_PIN,CS_PIN,MAX_DEVICES,MDX,MDY);

const int COLS = (MDX*8);
const int ROWS = (MDY*8);
boolean current_state[ROWS][COLS]; // stores the current state of the cells
int lastR = 0; // last cursor row
int lastC = 0; // last cursor column

float iteration = 0;

void setup(){

  randomSeed(analogRead(0));
  RandomLifeStart();
  

}

void loop(){

  NextLife();
  
  iteration++;
  int num = random(1, 1000);
  if ((iteration/num) == int(iteration/num)){       // this becomes increasingly unlikely as iterations get higher
    RandomMutation();                               // Conway's Life tends to stabilise - this sends a random spark every so often to destabilise things again
  }

}


void RandomMutation() {
  int num;
  boolean value;
  matrix.lock();
  
  for (int r = 0; r < ROWS; r++) {
    for (int c = 0; c < COLS; c++) {
      num = random(1, 100);

      value = num >= 95;
      if (value == 1) {              // only add new points, don't remove any
        current_state[r][c] = value;
        matrix.drawPoint(c, r, value);
      }
    }
  }
  matrix.unlock();

}

void RandomLifeStart() {
  int num;
  boolean value;
  matrix.lock();
  
  for (int r = 0; r < ROWS; r++) {
    for (int c = 0; c < COLS; c++) {
      num = random(1, 100);

      // value = num >= slider;       // use this line to read a potentiometer instead
      value = num >= 40;           // 40
      current_state[r][c] = value;
      
      matrix.drawPoint(c, r, value);
      
    }
  }
  matrix.unlock();
}

void NextLife(){
  int x;
  int y;
  boolean value;
  boolean next[ROWS][COLS]; // stores the next state of the cells
  
//  matrix.lock();           // run this to speed things up

  for (int r = 0; r < ROWS; r++) {     // for each row
    for (int c = 0; c < COLS; c++) {   // and each column
                                       // count how many live neighbors this cell has
      int liveNeighbors = 0;
      for (int i = -1; i < 2; i++) {
        y = r + i;
        if (y == -1) {
          y = (ROWS-1);
        } else if (y == ROWS) {
          y = 0;
        }
        for (int j = -1; j < 2; j++) {
          if (i != 0 || j != 0) {
            x = c + j;
            if (x == -1) {
              x = (COLS-1);
            } else if (x == COLS) {
              x = 0;
            }

            if (current_state[y][x]) {
              liveNeighbors++;
            }
          }
        }
      }

      // apply the rules
      if (current_state[r][c] && liveNeighbors >= 2 && liveNeighbors <= 3) { // live cells with 2 or 3 neighbors remain alive
        value = true;
      } else if (!current_state[r][c] && liveNeighbors == 3) { // dead cells with 3 neighbors become alive
        value = true;
      } else {
        value = false;
      }

      next[r][c] = value;
      
      matrix.drawPoint(c, r, value);

    }
  }
//  matrix.unlock();           // run this to speed things up

  // discard the old state and keep the new one
  memcpy(current_state, next, sizeof next);
  
}
