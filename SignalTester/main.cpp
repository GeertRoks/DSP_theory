
#include <iostream>
#include <iomanip>

#include "DiracPulse/diracpulse.h"

//Add filters and effects to be tested here:
#include "../Filters/TKEO/tkeo.hpp"
#include "../Filters/Hilbert/hilbert.hpp"

int main() {
    const Dirac pulse(40, 10);

// Initialize systems/filters to be tested.
    //TKEO tkeo;
    Hilbert hilbert;

// Print Labels
    std::cout << std::setw(20) << std::left << "Input" << "| ";
    std::cout << std::setw(20) << std::left << "Output 1" << "| ";
    std::cout << std::setw(20) << std::left << "Output 2" << std::endl;

// Print data per signal
    for(auto i : pulse.getPulse()) {
        std::cout << std::setw(20) << std::left << i << "| ";
        std::cout << std::setw(20) << std::left << hilbert.processReal(i) << "| ";
        std::cout << std::setw(20) << std::left << hilbert.processImg(i) << std::endl;
    }

  return 0;
}
