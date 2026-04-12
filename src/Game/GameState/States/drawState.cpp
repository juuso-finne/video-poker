#include "../gameState.h"
#include <iostream>
#include "../../GameData/gameData.h"

DrawState DrawState::draw_state_;
DrawState::DrawState(){}
DrawState *DrawState::Instance(){ return &draw_state_; }

void DrawState::Init(){
    for (HoldButton &b: ButtonManager::hold_buttons_){
        b.enabled_ = true;
    }
    ButtonManager::deal_button_.enabled_ = true;
}

void DrawState::Deal(){
    std::vector<Card> new_hand;

    for (int i = 0; i < 5; i++){
        Card old_card = GameData::player_hand_[i];
        if(GameData::held_cards_[i]){
            new_hand.push_back(old_card);
        } else{
            Card new_card = GameData::deck_.DealOne();
            new_card.FaceUp();
            new_card.Move(old_card.GetPosition(), 500);
            new_hand.push_back(new_card);
        }
    }
    GameData::player_hand_ = new_hand;
    ChangeState(WinState::Instance());
}

void DrawState::Hold(int index){
    GameData::held_cards_[index] = !GameData::held_cards_[index];
    std::cout << "Cards held: ";
    for (int i = 0; i < 5; i++){
        if(GameData::held_cards_[i]){
            std::cout << i << ", ";
        }
    }
    std::cout << std::endl;
}


