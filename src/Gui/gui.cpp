#include "gui.h"
#define RAYGUI_IMPLEMENTATION
#include <raygui.h>
#include <iostream>

Gui::Gui(const std::vector<Button*> &buttons){
    buttons_ = buttons;
}

void Gui::Update(){
    for (Button *button : buttons_){
        if (button->enabled_){
            GuiEnable();
        } else{
            GuiDisable();
        }
        button->clicked_ = GuiButton(button->bounds_, button->text_);
    }
}
