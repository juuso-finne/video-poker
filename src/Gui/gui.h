#pragma once
#include <vector>
#include "../Button/button.h"

class Gui{
    public:
        Gui(const std::vector<Button*> &buttons);
        void Update();
    private:
        std::vector<Button*> buttons_;
};