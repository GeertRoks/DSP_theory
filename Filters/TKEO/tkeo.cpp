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
    this->filterBuffer = {0,0};
}

TKEO::~TKEO(){
}

double TKEO::process(double x) {
// Calculates the filtered sample

  //x is input (x[n]) and y is output (y[n])
  // y[t] = x^2[t] - x[t-1] * x[t+1]
  // y[t] = x^2[t-1] - x[t-2] * x[t]
  double y = filterBuffer[!index] * filterBuffer[!index] - filterBuffer[index] * x;
  updateBuffer(x);
  return y;
}

void TKEO::updateBuffer(double input) {
// Fill the buffer with the new sample

  filterBuffer[index] = input;
  tick();
}

void TKEO::tick(){
// Increase the index of the buffer

  index = !index;
}

void TKEO::reset() {
    filterBuffer = {0.0, 0.0};
}
