#ifndef DIRAC_H_
#define DIRAC_H_

#ifndef AMOUNT_OF_SAMPLES
#define AMOUNT_OF_SAMPLES 40
#define PULSE_SAMPLE 10
#endif //variables


class Dirac {
public:
  Dirac ();
  virtual ~Dirac ();

  float *fire();
  void plot(float *input);

  int getAmountOfSamples();
  int getPulseSample();
private:
};//class

#endif//DIRAC_H_
