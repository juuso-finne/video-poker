#include "animation.h"
#include <random>
#include <raymath.h>
#include "../ScreenConstants/screenConstants.h"
#include "../gui.h"

std::vector<Card> Animation::animation_cards_;
Animation::Animation(){
    is_initialized_ = false;
}

void Animation::Play(){
    if(!is_initialized_){
        is_initialized_ = true;
        Init();
    }

    Update();
}

void Animation::Init(){}

void Animation::Update(){}
