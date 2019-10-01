
#ifndef PLOT_HPP
#define PLOT_HPP

#include <fstream>
#include <string>
#include <vector>

class Plot {
public:
    Plot(std::string filepath);

    void comment(std::string comment);
    void writeToFile(std::vector<double> sig, double idxstep = 1.0, double idxoffset = 0.0);
    void close();

private:
    std::ofstream data;

};

#endif //PLOT_HPP
