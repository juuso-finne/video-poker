#include "../gui.h"
#include <string>
#include "../../Game/GameData/gameData.h"

const char *ConvertToDecimal(int value){
    return TextFormat("%d.%02d", value/100, value%100);
}

void PrintPayouts(const TextSettings &text_settings){
    std::string name_column_string;
    std::string value_column_string;

    Font font = GetFontDefault();

    Color default_color = WHITE;
    Color highlight_color = RED;

    const std::vector<std::pair<const char*, HandValue>> list = GetNameValuePairs();

    int screen_width = ScreenConstants::screen_width_;

    int value_column_x_pos = screen_width - MeasureTextEx(font ,"xx.xx", text_settings.font_size_, text_settings.text_spacing_).x - text_settings.column_gap_;
    int name_column_x_pos = value_column_x_pos - text_settings.column_gap_ - MeasureTextEx(font, "STRAIGHT FLUSH", text_settings.font_size_, text_settings.text_spacing_).x;

    for (size_t row = 0; row < list.size(); row++){

        const char* kName = list[row].first;
        HandValue hand_value = list[row].second;

        bool highlight =
            GameData::current_winnings_ > 0 &&
            EvaluateHand(GameData::player_hand_) == hand_value;

        Color color = highlight ? highlight_color : default_color;

        int payout = payout_table[hand_value] * GameData::bet_;
        const char* kPayoutAsText = ConvertToDecimal(payout);

        int y = text_settings.column_gap_ + row * (text_settings.font_size_ + text_settings.row_spacing_);

        DrawTextEx(font, kName, {(float)name_column_x_pos, (float)y}, text_settings.font_size_, text_settings.text_spacing_, color);
        DrawTextEx(font, kPayoutAsText, {(float)value_column_x_pos, (float)y}, text_settings.font_size_, text_settings.text_spacing_, color);
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