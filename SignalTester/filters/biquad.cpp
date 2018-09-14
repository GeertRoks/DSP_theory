
#include <iostream>
#include "biquad.h"

Biquad::Biquad(double ff0, double ff1, double ff2, double fb1, double fb2) {
  this->ff0 = ff0;
  this->ff1 = ff1;
  this->ff2 = ff2;
  this->fb1 = fb1;
  this->fb2 = fb2;

  this->ffindex = 0;
  this->fbindex = 2;

  filterBuffer = new float[16];
  for(int i = 0; i < 16; i++) {
    filterBuffer[i] = 0;
  }//for
}//Biquad()

Biquad::~Biquad() {
  delete filterBuffer;
  filterBuffer = nullptr;
}//~Biquad()

float Biquad::process(float input) {
  double output;
  output = ff0 * input + ff1 * filterBuffer[ffindex] + ff2 * filterBuffer[(ffindex - 7) % 16] - fb1 * filterBuffer[fbindex] - fb2 * filterBuffer[(fbindex - 7) % 16];
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

  ffindex = ffindex % 16;
  fbindex = fbindex % 16;
}//tick()
