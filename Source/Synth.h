//
// Created by Jason on 12/18/2025.
//

#ifndef JX11_SYNTH_H
#define JX11_SYNTH_H
// #include <cstdint>
#include <JuceHeader.h>
#include "Voice.h"
#include "NoiseGenerator.h"

class Synth {
public:
    Synth();

    void allocateResources(double sampleRate_, int samplesPerBlock);
    void deallocateResources();
    void reset();
    void render(float** outputBuffers, int sampleCount);
    void midiMessages(uint8_t data0, uint8_t data1, uint8_t data2);

private:
    float sampleRate;
    Voice voice;
    NoiseGenerator noiseGen;

    void noteOn(int note, int velocity);
    void noteOff(int note);
};


#endif //JX11_SYNTH_H