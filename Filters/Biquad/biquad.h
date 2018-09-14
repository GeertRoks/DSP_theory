#ifndef BIQUAD_H
#define BIQUAD_H

class Biquad {
public:
  Biquad (double freq, double Q);
  virtual ~Biquad ();

  float process(float input);
  void fill(float ff, float fb);
  void tick();

private:
  float *filterBuffer;
  double freq;
  double Q;
  double gain;
  double ff0, ff1, ff2, fb0, fb1; //filtercoëfficients
  unsigned int ffindex, fbindex;

};//class

#endif//BIQUAD_H
