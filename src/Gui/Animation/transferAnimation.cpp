#include "animation.h"
#include "../../Game/GameData/gameData.h"
TransferAnimation::TransferAnimation(int amount){

    //stagger_timer_ = Timer(0.2);
    amount_ = amount;

    if (amount > 500){
        stagger_timer_ = Timer(0.1);
    } else{
        stagger_timer_ = Timer(0.2);
    }
}

bool TransferAnimation::IsPlaying(){
    return amount_ > 0;
}

void TransferAnimation::Update(){
    stagger_timer_.Tick();

    if(stagger_timer_.current_seconds_ >= 0 || amount_ <= 0){
        return;
    }

    stagger_timer_.Reset();

    if(amount_ > 500){
        Transfer(500);
        return;
    }

    if(amount_ >= 100){
        Transfer(100);
        return;
    }

    Transfer(20);
}

TransferToCurrentWinningsAnimation::TransferToCurrentWinningsAnimation(int amount): TransferAnimation(amount){}

void TransferToCurrentWinningsAnimation::Transfer(int x){
    amount_ -= x;
    GameData::current_winnings_ += x;
}

TransferToTotalWinnings::TransferToTotalWinnings(int amount): TransferAnimation(amount){}

void TransferToTotalWinnings::Transfer(int x){
    amount_ -= x;
    GameData::current_winnings_ -= x;
    GameData::total_winnings_ += x;
}
