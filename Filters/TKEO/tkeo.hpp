//  ##############################################################################
//  #
//  #   Author:     Geert Roks, 2018
//  #   Github:     www.github.com/GeertRoks/DSP_theory
//  #
//  #   License:    MIT License, see included LICENSE.md file
//  #
//  ##############################################################################

#ifndef TKEO_H_
#define TKEO_H_

class TKEO {
public:
    TKEO ();
    virtual ~TKEO ();

    float process(float x);
private:
    void tick();
    void updateBuffer(float x);

    float *filterBuffer;
    unsigned int index = 0;
};

#endif //TKEO_H_
