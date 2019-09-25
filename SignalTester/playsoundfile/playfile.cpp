
#include "playfile.hpp"

Playfile::Playfile() {
}

Playfile::Playfile(std::string file) {

}

std::vector<float> Playfile::getSamples(const unsigned int num_samples) {
  std::vector<float> file = {};
  for (unsigned int i = 0; i < num_samples; i++) {
      file.push_back(sample0[i]);
  }
  return file;
}
