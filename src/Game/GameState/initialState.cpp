#include "gameState.h"
#include <iostream>
bool InitialState::DealButtonEnabled() { return true; }
void InitialState::DealButtonClick(){
    std::cout << "Deal" << std::endl;
}

bool InitialState::BetButtonEnabled() { return true; }
void InitialState::BetButtonClick(){
    std::cout << "Increase bet" << std::endl;
}