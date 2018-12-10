#ifndef TKEO_H_
#define TKEO_H_

class TKEO {
public:
    TKEO ();
    virtual ~TKEO ();

    float process(float x);
private:
    void tick();
    void updateBuffer(float x);

    float *filterBuffer;
    unsigned int index = 0;
};

#endif //TKEO_H_
