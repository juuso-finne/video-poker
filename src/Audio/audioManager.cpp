#include "audioManager.h"

Sound AudioManager::coin_sound_ = Sound{};

void LoadSounds(){
    InitAudioDevice();

    AudioManager::coin_sound_ = LoadSound("assets/sounds/coin.wav");
    SetSoundVolume(AudioManager::coin_sound_, 0.15);


}

void UnloadSounds(){
    UnloadSound(AudioManager::coin_sound_);
    CloseAudioDevice();
}
