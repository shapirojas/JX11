//
// Created by Jason on 12/18/2025.
//

#ifndef JX11_NOISEGENERATOR_H
#define JX11_NOISEGENERATOR_H


class NoiseGenerator {
public:
    void reset();
    float nextValue();

private:
    unsigned int noiseSeed;
};


#endif //JX11_NOISEGENERATOR_H