#ifndef SampleSizes_h
#define SampleSizes_h

#include "sample0.h"
#include "sample1.h"
#include "sample2.h"

class SampleSizes {
public:
    SampleSizes(){};
    ~SampleSizes(){};
    int getSize(int sample);
protected:
    int sampleSizes[3] = {209455,209455,209455};
};

inline int SampleSizes::getSize(int sample) 
{
    return sampleSizes[sample];
}

#endif
