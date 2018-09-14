/**
  A simple highpass filter based on filter.cpp
*/
#ifndef HIGHPASS_H_
#define HIGHPASS_H_

#include <iostream>

#include "filter.h"

class HighPass : public Filter {
public:
  HighPass();
  ~HighPass();

  float filterFunction(float currentsample) override;
private:

};

#endif//HIGHPASS_H_
