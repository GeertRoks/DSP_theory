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

#include <array>

class TKEO {
public:
    TKEO();
    virtual ~TKEO();

    double process(double x);
    void reset();

private:
    void tick();
    void updateBuffer(double x);

    std::array<double, 2> filterBuffer;
    unsigned int index = 0;
};

#endif //TKEO_H_
