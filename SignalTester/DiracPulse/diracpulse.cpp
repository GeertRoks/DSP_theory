
#include "diracpulse.h"


Dirac::Dirac(const unsigned int amountOfSamples, const unsigned int pulseSample) {
// Initialize the pulse vector based on the parameters.
    if (amountOfSamples >= 2 && pulseSample < amountOfSamples && pulseSample > 0) {
        for (unsigned int i = 0; i < amountOfSamples; i++) {
            this->pulse.push_back(0.0);
        }
        this->pulse[pulseSample - 1] = 1.0;
    } else {
        std::cout << "Error: Invalid parameters for Dirac. Choose a pulseSample lower than the amountOfSamples." << std::endl;
        std::cout << "Dirac <name>(amountOfSamples, pulseSample)" << std::endl;
        exit(1);
    }
}

std::vector<double> Dirac::getPulse() const {
    return this->pulse;
}

void Dirac::getInfo() const {
    auto pulseSample = std::find(pulse.begin(), pulse.end(), 1.0);
    std::cout << "The length of the pulse array is: ";
    std::cout << std::distance(pulse.begin(), pulse.end()) << std::endl;
    std::cout << "The pulse is at sample: ";
    std::cout << std::distance(pulse.begin(), pulseSample) + 1 << std::endl;
}
