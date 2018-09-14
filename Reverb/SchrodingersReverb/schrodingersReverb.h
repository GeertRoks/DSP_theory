#ifndef SCHRODINGERSREVERB_H_
#define SCHRODINGERSREVERB_H_

#include "filters/allpassDFII.h"
#include "filters/comb.h"

class SchrodingersReverb {

public:
  SchrodingersReverb(int reverbTime);
  ~SchrodingersReverb();

  float process(float x);

private:
  int reverbTime = 0; //ms ???

  AllpassDFII allpass1 = AllpassDFII(8, 0.167772);
  AllpassDFII allpass2 = AllpassDFII(16, 0.167772);

  Comb comb1 = Comb(3, 0.6);
  Comb comb2 = Comb(5, 0.4);
  Comb comb3 = Comb(7, 0.3);
  Comb comb4 = Comb(8, 0.2);
};//class

#endif//SCHRODINGERSREVERB_H_

/**
  TODO:
    - array of filter pointers.
    - parameter control.
    - Combine ticks.
    - Combine fillbuffer.

*/
