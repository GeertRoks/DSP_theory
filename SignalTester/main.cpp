
#include <iostream>

#include "Pulse/pulse.h"

//Add filters and effects to be tested here:
#include "../Filters/AllpassDFII/allpassDFII.h"
#include "../Filters/Comb/comb.h"
#include "../Reverb/SchrodingersReverb/schrodingersReverb.h"

int main(int argc, char const *argv[]) {
  Pulse test;

  //AllpassDFII allpass(8, 0.167772);
  SchrodingersReverb reverb(60);


//Put testsignal in buffer
  float *output;
  output = test.fire();

//Plot Test Signal
  std::cout << "Test Signaal" << '\n';
  for (int i = 0; i < test.getAmountOfSamples(); i++) {
    std::cout << "output " << i << ": " << *(output + i) << '\n';
  }//for


//Give the signal to the filter
  for (int j = 0; j < test.getAmountOfSamples(); j++) {
    //output[j] = allpass.process(output[j]);
    output[j] = reverb.process(output[j]);
  }//for


//Plot the impulse Response
  std::cout << "Signaal na systeem" << '\n';
  for (int i = 0; i < test.getAmountOfSamples(); i++) {
    std::cout << "output " << i << ": " << output[i] << '\n';
  }//for

  return 0;
}//main
