#include "gui.h"
#define RAYGUI_IMPLEMENTATION
#include <raygui.h>

Gui::Gui(std::shared_ptr<GameState> game_state){
    game_state_ = game_state;
}

void Gui::Update(){
    std::vector<std::shared_ptr<Button>> buttons = GenerateButtons();
    for (size_t i = 0; i < buttons.size(); i++){
        if (buttons[i] -> enabled_){
            GuiEnable();
        } else{
            GuiDisable();
        }

        if(GuiButton(buttons[i] -> bounds_, buttons[i] -> text_)){
            buttons[i] -> OnClick();
        }
    }
}

std::vector<std::shared_ptr<Button>> Gui::GenerateButtons(){
    std::vector<std::shared_ptr<Button>> output = {};

    output.push_back(std::make_shared<DealButton>(game_state_));
    output.push_back(std::make_shared<BetButton>(game_state_));
    output.push_back(std::make_shared<CashOutButton>(game_state_));
    output.push_back(std::make_shared<DoubleButton>(game_state_));
    output.push_back(std::make_shared<SmallButton>(game_state_));
    output.push_back(std::make_shared<BigButton>(game_state_));

     for(int i = 0; i < 5; i++){
        output.push_back(std::make_shared<HoldButton>(i, game_state_));
    }

    return output;
}
