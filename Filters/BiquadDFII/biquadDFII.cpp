//  ##############################################################################
//  #
//  #   Author:     Geert Roks, 2018
//  #   Github:     www.github.com/GeertRoks/DSP_theory
//  #
//  #   License:
//  #
//  ##############################################################################

#include "biquadDFII.hpp"
#include <iostream>

BiquadDFII::BiquadDFII(double a0, double a1, double a2, double b1, double b2) {
    std::vector<double> filterBuffer = {0,0};
    this->a0 = a0;
    this->a1 = a1;
    this->a2 = a2;
    this->b1 = b1;
    this->b2 = b2;
}

BiquadDFII::~BiquadDFII() {

}

double BiquadDFII::process(double x) {
//  Calculates the filtered sample
//  x is input (x[n]) and y is output (y[n])
//  w is a variable to split the calculation in two for the feedbackpart.
//  Equation: y[n] = a0 * x[n] + a1 * x[n-1] + a2 * x[n-2] - b1 * y[n-1] + b2 * y[n-2]

    double w = x - this->b1 * filterBuffer[!index] - this->b2 * filterBuffer[index];
    double y = this->a0 * w + this->a1 * filterBuffer[!index] + this->a2 * filterBuffer[index];
    updateBuffer(w);
    return y;
}

void BiquadDFII::updateBuffer(double x) {
//  Fill the buffer with the new sample

    filterBuffer[index] = x;
    tick();
}

void BiquadDFII::tick(){
//  Increase the index of the buffer (0 or 1, because of 2 variable array)

    index = !index;
}
