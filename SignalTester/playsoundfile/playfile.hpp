#ifndef PLAYFILE_H
#define PLAYFILE_H

#include <vector>
#include <array>
#include "exported/sizes.h"

class Playfile {

public:
  Playfile();
  Playfile(std::string file);

  std::vector<float> getSamples(const unsigned int num_samples);

private:

};

#endif
