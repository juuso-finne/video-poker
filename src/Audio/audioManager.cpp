#include "audioManager.h"

Sound AudioManager::coin_sound_ = Sound{};
Sound AudioManager::shuffle_sound_ = Sound{};
Sound AudioManager::deal_sound_ = Sound{};

void LoadSounds(){
    InitAudioDevice();

    AudioManager::coin_sound_ = LoadSound("assets/sounds/coin.wav");
    SetSoundVolume(AudioManager::coin_sound_, 0.15);

    AudioManager::shuffle_sound_ = LoadSound("assets/sounds/shuffle.mp3");
    AudioManager::deal_sound_ = LoadSound("assets/sounds/deal.mp3");


}

void UnloadSounds(){
    UnloadSound(AudioManager::coin_sound_);
    UnloadSound(AudioManager::shuffle_sound_);
    UnloadSound(AudioManager::deal_sound_);
    CloseAudioDevice();
}
