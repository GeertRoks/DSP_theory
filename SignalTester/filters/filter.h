/**
  Blueprint for filters based on a circular buffer.
*/
#ifndef FILTER_H_
#define FILTER_H_

class Filter {
public:
  Filter();
  ~Filter();

  void fillBuffer(float currentsample);
  void tick();

  virtual float filterFunction(float currentsample) =0;

  void setCutOff(float cutOff);
  void setResonance(float resonance);
  float getCutOff();
  float getResonance();

protected:
  float *filterBuffer;                //pointer to filterarray
  unsigned char bufferLength = 8;
  unsigned char writeIndex = 0;
  unsigned char readIndex = 7;

private:
  float cutOff = 1000;
  float resonance = 1;

};//class

#endif//FILTER_H_

/*TODO:
    - implement some IIR filters.

*/
