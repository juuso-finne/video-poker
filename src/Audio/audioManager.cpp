#include "audioManager.h"

Sound AudioManager::coin_sound_ = Sound{};
Sound AudioManager::shuffle_sound_ = Sound{};
Sound AudioManager::deal_sound_ = Sound{};
Sound AudioManager::crash_sound_ = Sound{};

Music AudioManager::victory_music_ = Music{};
Music AudioManager::double_music_ = Music{};

void LoadSounds(){
    InitAudioDevice();

    AudioManager::coin_sound_ = LoadSound("assets/sounds/coin.wav");
    SetSoundVolume(AudioManager::coin_sound_, 0.15);

    AudioManager::crash_sound_ = LoadSound("assets/sounds/crash.wav");
    SetSoundVolume(AudioManager::crash_sound_, 0.15);

    AudioManager::shuffle_sound_ = LoadSound("assets/sounds/shuffle.mp3");
    AudioManager::deal_sound_ = LoadSound("assets/sounds/deal.mp3");

    AudioManager::victory_music_ = LoadMusicStream("assets/sounds/victory_music.mp3");
    SetMusicVolume(AudioManager::victory_music_, 0.10);

    AudioManager::double_music_ = LoadMusicStream("assets/sounds/double_music.mp3");
    SetMusicVolume(AudioManager::double_music_, 0.10);


}

void UnloadSounds(){
    UnloadSound(AudioManager::coin_sound_);
    UnloadSound(AudioManager::shuffle_sound_);
    UnloadSound(AudioManager::deal_sound_);
    CloseAudioDevice();
}

void UpdateMusic(){
    UpdateMusicStream(AudioManager::victory_music_);
    UpdateMusicStream(AudioManager::double_music_);
}
