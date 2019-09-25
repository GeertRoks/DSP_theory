
#include "plot.hpp"

Plot::Plot(std::string name) {
// open the given file
// TODO: add input restrictions (check for .dat or directroy existence or default to plot/data/)
    data.open("plot/" + name);
}

void Plot::writeToFile(std::vector<float> sig, double idxstep, double idxoffset) {
    double idx = 0.0;
    for(unsigned int i = idxoffset/idxstep; i < sig.size(); i++) {
        data << idx << " " << sig[i] << std::endl;
        idx += idxstep;
    }
    data << "\n";
    data << "\n";
}

void Plot::close() {
    data.close();
}
