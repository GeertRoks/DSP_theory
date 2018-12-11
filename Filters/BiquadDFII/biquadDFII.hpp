//  ##############################################################################
//  #
//  #   Author:     Geert Roks, 2018
//  #   Github:     www.github.com/GeertRoks/DSP_theory
//  #
//  #   License:
//  #
//  ##############################################################################

#ifndef BIQUADDFII_H
#define BIQUADDFII_H

class BiquadDFII {
public:
  BiquadDFII (double a0, double a1, double a2, double b1, double b2);
  virtual ~BiquadDFII ();

  double process(double x);

private:
  void tick();
  void updateBuffer(double x);

  double a0, a1, a2, b1, b2 = 0;  //filtercoefficents

  std::vector<double> filterBuffer;
  unsigned int index = 0;

};//class

#endif//BIQUADDFII_H
