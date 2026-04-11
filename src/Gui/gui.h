#pragma once
#include <vector>
#include "Button/button.h"

class Gui{
    public:
        static DealButton deal_button_;
        static std::vector<HoldButton> hold_buttons_;
        static BetButton bet_button_;
        static CashOutButton cash_out_button_;
        static DoubleButton double_button_;
        static SmallButton small_button_;
        static BigButton big_button_;

        static void DisableButtons();
        static void DrawButtons();
};