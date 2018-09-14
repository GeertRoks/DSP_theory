
#include <iostream>
#include "biquad.h"

Biquad::Biquad(double freq, double Q) {
  this->freq = freq;
  this->Q = Q;
  this->ffindex = 0;
  this->fbindex = 2;

  filterBuffer = new float[4];
  for(int i = 0; i < 4; i++) {
    filterBuffer[i] = 0;
  }//for
}//Biquad()

Biquad::~Biquad() {

  delete filterBuffer;
  filterBuffer = nullptr;
}//~Biquad()

float Biquad::process(float input) {
  double output = input * ff0 + filterBuffer[ffindex] * ff1 + filterBuffer[ffindex - 1] * ff2 + filterBuffer[fbindex] * fb0 + filterBuffer[fbindex - 1] * fb1;
  fill(input, output);
  return output;
}//process()

void Biquad::fill(float ff, float fb) {
  tick();
  filterBuffer[ffindex] = ff;
  filterBuffer[fbindex] = fb;
}//fill

void Biquad::tick() {
  ffindex++;
  fbindex++;
  
  ffindex = ffindex % 4;
  fbindex = fbindex % 4;
}//tick()
