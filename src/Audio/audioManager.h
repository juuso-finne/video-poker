#pragma once
#include <raylib.h>


class AudioManager{
    public:
        static Sound coin_sound_;
};

void LoadSounds();
void UnloadSounds();