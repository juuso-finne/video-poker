#pragma once
#include <raylib.h>


class AudioManager{
    public:
        static Sound coin_sound_;
        static Sound shuffle_sound_;
        static Sound flip_sound_;
        static Sound crash_sound_;

        static Music victory_music_;
        static Music double_music_;
};

void LoadSounds();
void UnloadSounds();
void UpdateMusic();