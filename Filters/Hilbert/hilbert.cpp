//  ##############################################################################
//  #
//  #   Author:     Geert Roks, 2018
//  #   Github:     www.github.com/GeertRoks/DSP_theory
//  #   Reference:  http://www.katjaas.nl/hilbert/hilbert.html Polyphase IIR
//  #
//  #   License:
//  #
//  ##############################################################################


#include "hilbert.hpp"

Hilbert::Hilbert() {
//  Initialize the biquads. Coëfficients by Olli Niemitalo (see reference)
    this->biquadr1 = new BiquadDFII(0.161758, 0.0, -1.0, 0.0, -0.161758);
    this->biquadr2 = new BiquadDFII(0.733029, 0.0, -1.0, 0.0, -0.733029);
    this->biquadr3 = new BiquadDFII(0.94535,  0.0, -1.0, 0.0, -0.94535);
    this->biquadr4 = new BiquadDFII(0.990598, 0.0, -1.0, 0.0, -0.990598);

    this->biquadi1 = new BiquadDFII(0.479401, 0.0, -1.0, 0.0, -0.479401);
    this->biquadi2 = new BiquadDFII(0.876218, 0.0, -1.0, 0.0, -0.876218);
    this->biquadi3 = new BiquadDFII(0.976599, 0.0, -1.0, 0.0, -0.976599);
    this->biquadi4 = new BiquadDFII(0.9975,   0.0, -1.0, 0.0, -0.9975);
}

Hilbert::~Hilbert() {

}

std::vector<double> Hilbert::process(double input) {
//  Output both the real and Imaginary signals in a vector

    double realsig = this->biquadr1->process(input);
    realsig = this->biquadr2->process(realsig);
    realsig = this->biquadr3->process(realsig);
    realsig = this->biquadr4->process(realsig);

    double imgsig = this->biquadi1->process(delayedInput);
    imgsig = this->biquadi2->process(imgsig);
    imgsig = this->biquadi3->process(imgsig);
    imgsig = this->biquadi4->process(imgsig);

    this->delayedInput = input;

    std::vector<double> hilbert = {realsig, imgsig};
    return hilbert;
}

double Hilbert::processReal(double input) {
//  Output only the real signal

    double realsig = this->biquadr1->process(input);
    realsig = this->biquadr2->process(realsig);
    realsig = this->biquadr3->process(realsig);
    realsig = this->biquadr4->process(realsig);
    return realsig;
}

double Hilbert::processImg(double input) {
// Output only the imaginary signal

    double imgsig = this->biquadi1->process(this->delayedInput);
    imgsig = this->biquadi2->process(imgsig);
    imgsig = this->biquadi3->process(imgsig);
    imgsig = this->biquadi4->process(imgsig);
    this->delayedInput = input;
    return imgsig;
}
