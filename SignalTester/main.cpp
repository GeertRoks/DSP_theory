#include <iostream>
#include <iomanip>

#include "DiracPulse/diracpulse.h"
#include "Sine/sine.hpp"
#include "playsoundfile/playfile.hpp"
#include "plot/plot.hpp"
//Add filters and effects to be tested here:
#include "../Filters/TKEO/tkeo.hpp"
#include "../Filters/Hilbert/hilbert.hpp"
#include "playsoundfile/exported/sizes.h"
#include "gnuplotter/gnuplotter.h"

int main() {

    FILE* gnu;

    gnu = open_gnu_plot_file();

    const Dirac pulse(40, 10);
    Sine sine(50);
    Playfile file("test");

    // Initialize systems/filters to be tested.
    //TKEO tkeo;
    Hilbert hilbert;
    SampleSizes samples;

    // Print Labels
    //std::cout << std::setw(20) << std::left << "Input" << "| ";
    //std::cout << std::setw(20) << std::left << "Output 1" << "| ";
    //std::cout << std::setw(20) << std::left << "Output 2" << std::endl;

    // Print data per signal
    //for(auto i : sine.getSine(1)) {
    for (int i = 0; i < samples.getSize(0); i++) 
    {
        float sample = file.getSample(i);
        print_to_gnu_plot((float)i, hilbert.processImg(sample), gnu);
        print_to_gnu_plot((float)i, hilbert.processReal(sample), gnu);
    }

    // Extract the data to a .dat file for gnuplot
    //std::vector<double> hilbertSineReal, hilbertSineImg = {};
    //for(auto i : sine.getSine(500)) {
    //    hilbertSineReal.push_back(hilbert.processReal(i));
    //    hilbertSineImg.push_back(hilbert.processImg(i));
    //}

    refresh_gnu_plot(gnu);

  return 0;
}
