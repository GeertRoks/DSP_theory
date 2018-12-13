
#ifndef SINE_HPP
#define SINE_HPP

#include <vector>
#include <math.h>

class Sine {
public:
    Sine(double freq);
    Sine(double freq, double samplerate);

    std::vector<double> getSine(const unsigned int length_ms);

    void setSamplerate(const unsigned int samplerate);
    void setFreq(double freq);

private:
    unsigned int samplerate = 48000;    //Hz
    double freq = 440;                  //Hz

    double generateSine();
    void calcPhasestep();

    static constexpr double twoPi = 2 * M_PI;
    double phase = 0.0;                 //radians
    double phasestep = 0.0;             //radians

    unsigned int n = 10;                //detail of Taylor series
};

#endif //SINE_HPP
