
#include "schrodingersReverb.h"

SchrodingersReverb::SchrodingersReverb(int reverbTime) {
  this->reverbTime = reverbTime;

}//SchrodingersReverb()

SchrodingersReverb::~SchrodingersReverb() {

}//~SchrodingersReverb()


float SchrodingersReverb::process(float x) {

  float comb = (comb1.process(x) + comb2.process(x) + comb3.process(x) + comb3.process(x)) * 0.25;
  float apf1 = allpass1.process(comb);
  float y = allpass2.process(apf1);
  return y;
}//process()
