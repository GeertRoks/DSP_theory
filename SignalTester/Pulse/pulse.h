#ifndef PULSE_H_
#define PULSE_H_

#ifndef AMOUNT_OF_SAMPLES
#define AMOUNT_OF_SAMPLES 40
#define PULSE_SAMPLE 10
#endif //variables


class Pulse {
public:
  Pulse ();
  virtual ~Pulse ();

  float *fire();
  void plot(float *input);

  int getAmountOfSamples();
  int getPulseSample();
private:
};//class

#endif//PULSE_H_
