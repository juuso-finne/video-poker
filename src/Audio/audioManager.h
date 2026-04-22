#pragma once
#include <raylib.h>


class AudioManager{
    public:
        static Sound coin_sound_;
        static Sound shuffle_sound_;
        static Sound deal_sound_;
};

void LoadSounds();
void UnloadSounds();