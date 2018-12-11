//  ##############################################################################
//  #
//  #   Author:     Geert Roks, 2018
//  #   Github:     www.github.com/GeertRoks/DSP_theory
//  #
//  #   License:    MIT License, see included LICENSE.md file
//  #
//  ##############################################################################

#include "tkeo.hpp"

TKEO::TKEO() {
    filterBuffer = new float[2];
    for(unsigned int i = 0; i < 2; i++) {
      filterBuffer[i] = 0;
    }//for
}

TKEO::~TKEO(){
    delete filterBuffer;
    filterBuffer = nullptr;
}

float TKEO::process(float x) {
/*
 *  Calculates the filtered sample
 */

  //x is input (x[n]) and y is output (y[n])
  // y[t] = x^2[t] - x[t-1] * x[t+1]
  float y = filterBuffer[(index - 1) % 2] * filterBuffer[(index - 1) % 2] - filterBuffer[index] * x;
  updateBuffer(y);
  return y;
}//process()

void TKEO::updateBuffer(float input) {
/*
 *  Fill the buffer with the new sample
 */
  filterBuffer[index] = input;
  tick();
}//updateBuffer()

void TKEO::tick(){
/*
 *  Increase the index of the buffer
 */
  index++;
  index = (index % 2);
}//tick()
