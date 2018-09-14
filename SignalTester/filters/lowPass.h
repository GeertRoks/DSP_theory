/**
  A simple lowpass filter based on filter.cpp
*/
#ifndef LOWPASS_H_
#define LOWPASS_H_

#include <iostream>
#include "filter.h"

class LowPass : public Filter {
public:
  LowPass();
  ~LowPass();

  float filterFunction(float currentsample) override;

};//class

#endif//LOWPASS_H_
