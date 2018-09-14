
#include "pulse.h"

Pulse::Pulse() {

}//Pulse()

Pulse::~Pulse() {

}//~Pulse()


float *Pulse::fire() {
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

void Pulse::plot(float *input) {

}//plot()

int Pulse::getAmountOfSamples() {
  return AMOUNT_OF_SAMPLES;
}//getAmountOfSamples()

int Pulse::getPulseSample() {
  return PULSE_SAMPLE;
}//getPulseSample()
