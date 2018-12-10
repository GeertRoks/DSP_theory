
#include "diracpulse.h"

Dirac::Dirac() {

}//Dirac()

Dirac::~Dirac() {

}//~Dirac()


float *Dirac::fire() {
  static float signalArray[AMOUNT_OF_SAMPLES];
  for (int i = 0; i < AMOUNT_OF_SAMPLES; i++) {
    if (i == PULSE_SAMPLE) {
      signalArray[i] = 1.0000;
    } else {
      signalArray[i] = 0.0000;
    }//else
  }//for
  return signalArray;
}//fire()

void Dirac::plot(float *input) {

}//plot()

int Dirac::getAmountOfSamples() {
  return AMOUNT_OF_SAMPLES;
}//getAmountOfSamples()

int Dirac::getPulseSample() {
  return PULSE_SAMPLE;
}//getPulseSample()
