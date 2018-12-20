//  ##############################################################################
//  #
//  #   Author:     Geert Roks, 2018
//  #   Github:     www.github.com/GeertRoks/DSP_theory
//  #
//  #   License:    MIT License, see included LICENSE.md file
//  #
//  ##############################################################################

#ifndef BIQUADDFII_HPP
#define BIQUADDFII_HPP

#include <array>

class BiquadDFII {
public:
  BiquadDFII(double a0, double a1, double a2, double b1, double b2);
  virtual ~BiquadDFII();

  double process(double x);
  void reset();

private:
  void tick();
  void updateBuffer(double x);

  double a0, a1, a2, b1, b2 = 0;  //filtercoefficents

  std::array<double, 2> filterBuffer;
  unsigned int index = 0;

};//class

#endif//BIQUADDFII_HPP
