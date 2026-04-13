#include "gui.h"
#include <string>
#include "../Game/GameData/gameData.h"

const char *ConvertToDecimal(int value){
    return TextFormat("%d.%02d", value/100, value%100);
}

void PrintPayouts(int margin, int font_size){
    std::string name_column_string;
    std::string value_column_string;

    const int row_spacing = 5;
    Color default_color = WHITE;
    Color highlight_color = RED;

    const std::vector<std::pair<const char*, HandValue>> list = GetNameValuePairs();

    int value_column_x_pos = ScreenConstants::screen_width_ - MeasureText("xx.xx", font_size) - margin;
    int name_column_x_pos = value_column_x_pos - margin - MeasureText("STRAIGHT FLUSH", font_size);

    for (size_t row = 0; row < list.size(); row++){

        const char* name = list[row].first;
        const HandValue hand_value = list[row].second;

        bool highlight =
            GameData::current_winnings_ > 0 &&
            EvaluateHand(GameData::player_hand_) == hand_value;

        Color color = highlight ? highlight_color : default_color;

        const int payout = payout_table[hand_value] * GameData::bet_;
        const char* payout_chars = ConvertToDecimal(payout);

        int y = margin + row * (font_size + row_spacing);

        DrawText(name, name_column_x_pos, y, font_size, color);
        DrawText(payout_chars, value_column_x_pos, y, font_size, color);
    }
}

std::vector<std::pair<const char*, HandValue>> GetNameValuePairs(){
    return std::vector<std::pair<const char*, HandValue>>{
        {"5 OF A KIND", HandValue::kFiveOfAKind},
        {"STRAIGHT FLUSH", HandValue::kStraightFlush},
        {"4 OF A KIND", HandValue::kFourOfAKind},
        {"FULL HOUSE", HandValue::kFullHouse},
        {"FLUSH", HandValue::kFlush},
        {"STRAIGHT", HandValue::kStraight},
        {"3 OF A KIND", HandValue::kThreeOfAKind},
        {"2 PAIRS", HandValue::kTwoPairs}
    };
}