
#include <iostream>

#include "DiracPulse/diracpulse.h"

//Add filters and effects to be tested here:
#include "../Filters/AllpassDFII/allpassDFII.h"
#include "../Filters/Comb/comb.h"
#include "../Reverb/SchrodingersReverb/schrodingersReverb.h"
#include "../Filters/TKEO/tkeo.hpp"
#include "../Filters/BiquadDFII/biquadDFII.hpp"
#include "../Filters/Hilbert/hilbert.hpp"

int main(int argc, char const *argv[]) {
  Dirac pulse;

  //AllpassDFII allpass(8, 0.167772);
  //SchrodingersReverb reverb(60);
  //TKEO tkeo;
  //BiquadDFII biquad(0.0,0.0,0.055437245465,-1.357645019878,0.9216);
  Hilbert hilbert;

//Put testsignal in buffer
  float *output;
  output = pulse.fire();

//Plot Test Signal
  std::cout << "Test Signaal" << '\n';
  for (int i = 0; i < pulse.getAmountOfSamples(); i++) {
    std::cout << "output " << i << ": " << *(output + i) << '\n';
  }//for


//Give the signal to the filter
  for (int j = 0; j < pulse.getAmountOfSamples(); j++) {
    //output[j] = allpass.process(output[j]);
    //output[j] = reverb.process(output[j]);
    //output[j] = tkeo.process(output[j]);
    //output[j] = biquad.process(output[j]);
    output[j] = hilbert.processReal(output[j]);
  }//for


//Plot the impulse Response
  std::cout << "Signaal na systeem" << '\n';
  for (int i = 0; i < pulse.getAmountOfSamples(); i++) {
    std::cout << "output " << i << ": " << output[i] << '\n';
  }//for

  return 0;
}//main
