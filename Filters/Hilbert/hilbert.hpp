//  ##############################################################################
//  #
//  #   Author:     Geert Roks, 2018
//  #   Github:     www.github.com/GeertRoks/DSP_theory
//  #   Reference:  http://www.katjaas.nl/hilbert/hilbert.html Polyphase IIR
//  #
//  #   License:    MIT License, see included LICENSE.md file
//  #
//  ##############################################################################

#ifndef HILBERT_HPP
#define HILBERT_HPP

#include "../BiquadDFII/biquadDFII.hpp"

class Hilbert {
public:
    Hilbert();
    virtual ~Hilbert ();

    std::array<double, 2> process(double input);
    double processReal(double input);
    double processImg(double input);

private:
    double a0, a1 = 0;

    BiquadDFII *biquadr1, *biquadr2, *biquadr3, *biquadr4 = nullptr;
    BiquadDFII *biquadi1, *biquadi2, *biquadi3, *biquadi4 = nullptr;

    double delayedInput = 0;
};

#endif //HILBERT_HPP
