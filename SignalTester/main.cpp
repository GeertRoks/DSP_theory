#include <iostream>
#include <iomanip>

#include "DiracPulse/diracpulse.h"
#include "Sine/sine.hpp"
#include "playsoundfile/playfile.hpp"
#include "plot/plot.hpp"
#include "gnuplotter/gnuplotter.h"
//Add filters and effects to be tested here:
#include "../Filters/TKEO/tkeo.hpp"
#include "../Filters/Hilbert/hilbert.hpp"
#include "playsoundfile/exported/sizes.h"

int main() {

    FILE* gnu;

    gnu = open_gnu_plot_file();

    Playfile file("test");

    // Initialize systems/filters to be tested.
    //TKEO tkeo;
    Hilbert hilbert;
    SampleSizes samples;

    for (int i = 0; i < samples.getSize(0); i++) 
    {
        float sample = file.getSample(i);
        float realSig = hilbert.processReal(sample);
        float imgSig = hilbert.processImg(sample);
        float transient = sqrt(abs(pow(realSig, 2) - pow(imgSig, 2)));
        print_to_gnu_plot((float)i, transient, gnu);
        //print_to_gnu_plot((float)i, hilbert.processReal(sample), gnu);
    }

    refresh_gnu_plot(gnu);

    return 0;
}
