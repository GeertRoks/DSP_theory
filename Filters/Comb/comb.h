#ifndef COMB_H
#define COMB_H

class Comb {
public:
  Comb (unsigned int z, double g);
  virtual ~Comb ();

  float process(float x);

private:
  void tick();
  void updateBuffer(float x);

  double g = 0;               //feedback gain
  unsigned int z = 0;         //amount of delay samples

  float *filterBuffer;
  unsigned int index = 0;
};//class

#endif
