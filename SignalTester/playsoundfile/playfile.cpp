
#include "playfile.hpp"

Playfile::Playfile() {
}

Playfile::Playfile(std::string file) {

}

std::vector<double> Playfile::getSamples(const unsigned int num_samples) {
  std::vector<double> file = {};
  for (unsigned int i = 0; i < num_samples; i++) {
      file.push_back(sample0[i]);
  }
  return file;
}
