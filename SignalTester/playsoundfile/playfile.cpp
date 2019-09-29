#include "playfile.hpp"

Playfile::Playfile() {
}

Playfile::Playfile(std::string file) {

}

float Playfile::getSample(const unsigned int num_sample) 
{
    float sample = sample0[num_sample];
    
    return sample;
}
