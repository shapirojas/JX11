//
// Created by Jason on 12/18/2025.
//

#ifndef JX11_VOICE_H
#define JX11_VOICE_H
struct Voice {
    int note;
    int velocity;

    void reset() {
        note = 0;
        velocity = 0;
    }
};
#endif //JX11_VOICE_H