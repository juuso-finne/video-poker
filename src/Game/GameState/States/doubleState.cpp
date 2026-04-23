#include "../gameState.h"
#include "../../GameData/gameData.h"

DoubleState DoubleState::double_state_;
DoubleState::DoubleState(){}
DoubleState *DoubleState::Instance(){ return &double_state_; }

void DoubleState::Init(){
    PlayMusicStream(AudioManager::double_music_);
    ButtonManager::small_button_.enabled_ = true;
    ButtonManager::big_button_.enabled_ = true;
}

void DoubleState::Resolve(bool success){
    StopMusicStream(AudioManager::double_music_);
    Gui::animations_.push(std::make_shared<RevealAnimation>());
    GameData::player_hand_[0].FaceUp();
    int rank = GameData::player_hand_[0].GetRank();

    if (rank == 14){ //joker
        Win();
        return;
    }

    if(rank == 7){
        ResolveSeven();
        return;
    }

    if (success){
        Win();
        return;
    }

    Lose();
}

void DoubleState::Big(){
    Resolve(GameData::player_hand_[0].GetRank() > 7);
}

void DoubleState::Small(){
    Resolve(GameData::player_hand_[0].GetRank() < 7);
}

void DoubleState::Win(){

    if(GameData::current_winnings_ > 10000){

        Gui::animations_.push(std::make_shared<TransferToTotalWinnings>(GameData::current_winnings_));
        ChangeState(InitialState::Instance());
        return;
    }

    ChangeState(WinState::Instance());
}

void DoubleState::Lose(){
    ChangeState(InitialState::Instance());
}

void DoubleState::ResolveSeven(){
    Suit suit = GameData::player_hand_[0].GetSuit();

    if( suit == Suit::kDiamonds || suit == Suit::kHearts){
        Gui::animations_.push(std::make_shared<TransferToTotalWinnings>(GameData::current_winnings_ / 2));
    }

    Lose();
}