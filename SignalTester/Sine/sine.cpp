
#include "sine.hpp"

Sine::Sine(double freq) {
    this->freq = freq;
    calcPhasestep();
}

Sine::Sine(double freq, double samplerate) {
    this->freq = freq;
    this->samplerate = samplerate;
    calcPhasestep();
}

std::vector<double> Sine::getSine(const unsigned int length_ms) {
    calcPhasestep();
    std::vector<double> sine = {};
    for (unsigned int i = 0; i < length_ms * 0.001 * samplerate; i++) {
        sine.push_back(generateSine());
    }
    return sine;
}

void Sine::setSamplerate(const unsigned int samplerate) {
    this->samplerate = samplerate;
}

void Sine::setFreq(double freq) {
    this->freq = freq;
}

double Sine::generateSine() {
    //approximation of sin()
    //Equation: x - (x^3)/3! + (x^5)/5! - (x^7)/7! + (x^9)/9! = (x^2n+1)/(2n+1)!
    //This creates a sine between -pi and pi
    double sig = phase - pow(phase, 3)/6 + pow(phase, 5)/120 - pow(phase, 7)/5040 + pow(phase, 9)/362880;
    phase += phasestep;
    if (phase >= M_PI) {
        phase = phase - twoPi;
    }
    return sig;
}

void Sine::calcPhasestep() {
    phase = 0.0;
    phasestep = (twoPi / samplerate) * freq;
}

double Sine::getPhasestep() const {
    return phasestep;
}
