#ifndef DIRAC_H_
#define DIRAC_H_

#ifndef AMOUNT_OF_SAMPLES
#define AMOUNT_OF_SAMPLES 40
#define PULSE_SAMPLE 10
#endif //variables

#include <iostream>
#include <vector>
#include <algorithm>

class Dirac {
public:
    Dirac(const unsigned int amountOfSamples, const unsigned int pulseSample);

    std::vector<double> getPulse() const;
    void getInfo() const;

private:
    std::vector<double> pulse = {};
};

#endif//DIRAC_H_
