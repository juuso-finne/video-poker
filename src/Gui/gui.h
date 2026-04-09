#pragma once
#include "../Button/button.h"
#include <memory>

class Gui{
    public:
        Gui(std::shared_ptr<GameState> game_state);
        void Update();
    private:
        std::vector<Button> buttons_;
        std::vector<std::shared_ptr<Button>> GenerateButtons();
        std::shared_ptr<GameState> game_state_;
};