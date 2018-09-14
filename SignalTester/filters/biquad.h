#ifndef BIQUAD_H
#define BIQUAD_H

class Biquad {
public:
  Biquad (double ff0, double ff1, double ff2, double fb1, double fb2);
  virtual ~Biquad ();

  float process(float input);
  void fill(float ff, float fb);
  void tick();

private:
  float *filterBuffer;

  double ff0, ff1, ff2, fb1, fb2 = 0; //filtercoëfficients
  unsigned int ffindex, fbindex;

};//class

#endif//BIQUAD_H
