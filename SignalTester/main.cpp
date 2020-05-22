
#include <iostream>
#include <iomanip>

#include "DiracPulse/diracpulse.h"
#include "Sine/sine.hpp"
#include "playsoundfile/playfile.hpp"
#include "plot/plot.hpp"

//Add filters and effects to be tested here:
#include "../Filters/TKEO/tkeo.hpp"
#include "../Filters/Hilbert/hilbert.hpp"

int main() {
//Initialize all possible test signals
    const Dirac pulse(40, 10);
    Sine sine(50);
    Playfile file("test");

// Initialize systems/filters to be tested.
    //TKEO tkeo;
    Hilbert hilbert;

// // Print Labels
//     std::cout << std::setw(20) << std::left << "Input" << "| ";
//     std::cout << std::setw(20) << std::left << "Output 1" << "| ";
//     std::cout << std::setw(20) << std::left << "Output 2" << std::endl;
//
// // Print data per signal
//     for(auto i : sine.getSine(1)) {
//         std::cout << std::setw(20) << std::left << i << "| ";
//         std::cout << std::setw(20) << std::left << hilbert.processReal(i) << "| ";
//         std::cout << std::setw(20) << std::left << hilbert.processImg(i) << std::endl;
//    }

// Extract the data to a .dat file for gnuplot
    // std::vector<double> hilbertSineReal, hilbertSineImg = {};
    // for(auto i : sine.getSine(500)) {
    //     hilbertSineReal.push_back(hilbert.processReal(i));
    //     hilbertSineImg.push_back(hilbert.processImg(i));
    // }
    //
    // Plot plot("sineplot/sinetest.dat");
    // plot.writeToFile(sine.getSine(500), sine.getPhasestep(), 5.29 * M_PI);
    // plot.writeToFile(hilbertSineReal, sine.getPhasestep(),  5.29 * M_PI);
    // plot.writeToFile(hilbertSineImg, sine.getPhasestep(),  5.29 * M_PI);
    // plot.close();

// generate a vector with the signal
    std::vector<double> envelopeFolower = {};
    for(auto i : file.getSamples(209455)) {
      envelopeFolower.push_back(sqrt(pow(hilbert.processReal(i), 2) - pow(hilbert.processImg(i), 2)));
    }

    Plot plot("envelopefolower/envelope.dat");
    plot.comment("sig1: kick file, sig2: hilbert transform of kick sample");
    plot.writeToFile(file.getSamples(209455), 1, 0);
    plot.writeToFile(envelopeFolower, 1, 0);
    plot.close();

  return 0;
}
