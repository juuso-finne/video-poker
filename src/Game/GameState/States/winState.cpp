#include "../gameState.h"
#include "../../GameData/gameData.h"


WinState::WinState(){}
WinState WinState::win_state_;
WinState *WinState::Instance(){ return &win_state_;}

void WinState::Init(){
    PlayMusicStream(AudioManager::victory_music_);
    ButtonManager::cash_out_button_.enabled_ = true;
    ButtonManager::double_button_.enabled_ = true;
}

void WinState::Double(){

    StopMusicStream(AudioManager::victory_music_);

    GameData::deck_.Reset();

    Vector2 middle_slot = ScreenConstants::GetCardSlots()[2];

    Gui::animations_.push(std::make_shared<TransferToCurrentWinningsAnimation>(GameData::current_winnings_));
    Gui::animations_.push(std::make_shared<CollectionAnimation>());
    Gui::animations_.push(std::make_shared<ShuffleAnimation>());
    Gui::animations_.push(std::make_shared<DealAnimation>(std::vector<Vector2>{middle_slot}));

    ChangeState(DoubleState::Instance());
}

void WinState::CashOut(){
    StopMusicStream(AudioManager::victory_music_);
    Gui::animations_.push(std::make_shared<TransferToTotalWinnings>(GameData::current_winnings_));
    ChangeState(InitialState::Instance());
}