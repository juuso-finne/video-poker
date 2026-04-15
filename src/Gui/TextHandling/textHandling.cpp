#include "../gui.h"
#include <string>
#include "../../Game/GameData/gameData.h"
#include "textHandling.h"

const char *ConvertToDecimal(int value){
    return TextFormat("%d.%02d", value/100, value%100);
}

void PrintTexts(){
    PrintPayouts(TextSettings{30, 30, 10, 100, 5, 3, 5});
    PrintBet(TextSettings());
    PrintTotalWins(TextSettings());
    PrintTotalBets(TextSettings());
}

void PrintTotalBets(const TextSettings &text_settings){

    const char* total_bets_text = ConvertToDecimal(GameData::total_bets_);

    std::string output = std::string("TOTAL BETS: ") + std::string(total_bets_text);

    float x = ScreenConstants::screen_width_ - text_settings.MeasureWidth(output.c_str()) - text_settings.margin_x_ - text_settings.padding_;
    float y = text_settings.margin_y_;

    DrawTextEx(text_settings.font_, output.c_str(), {x, y}, text_settings.font_size_, text_settings.text_spacing_, WHITE);
}

void PrintTotalWins(const TextSettings &text_settings){
    const char* total_bets_text = ConvertToDecimal(GameData::total_winnings_);

    std::string output = std::string("TOTAL WINNINGS: ") + std::string(total_bets_text);

    float x = text_settings.margin_x_ + text_settings.padding_;
    float y = text_settings.margin_y_;

    DrawTextEx(text_settings.font_, output.c_str(), {x, y}, text_settings.font_size_, text_settings.text_spacing_, WHITE);
}

void PrintBet(const TextSettings &text_settings){

    const char* text = ConvertToDecimal(GameData::bet_);

    Vector2 origin = {text_settings.MeasureWidth(text) / 2, text_settings.font_size_ / 2};

    float radius = text_settings.MeasureWidth("x.xx") / 2 + text_settings.padding_;
    float x = ScreenConstants::screen_width_ / 2;
    float y = text_settings.margin_y_ + radius;

    Color dark_yellow = {140, 100, 0 ,255};
    DrawCircle(x + 5, y, radius, dark_yellow);
    DrawCircle(x, y, radius, YELLOW);
    DrawTextPro(text_settings.font_, text, {x, y}, origin, 0, text_settings.font_size_, text_settings.text_spacing_, BLACK);
}

void PrintPayouts(const TextSettings &text_settings){
    std::string name_column_string;
    std::string value_column_string;

    Color default_color = WHITE;
    Color highlight_color = RED;

    const std::vector<std::pair<const char*, HandValue>> list = GetNameValuePairs();

    int screen_width = ScreenConstants::screen_width_;

    int value_column_x_pos = screen_width - MeasureTextEx(text_settings.font_ ,"xx.xx", text_settings.font_size_, text_settings.text_spacing_).x - text_settings.column_gap_;
    int name_column_x_pos = value_column_x_pos - text_settings.column_gap_ - MeasureTextEx(text_settings.font_, "STRAIGHT FLUSH", text_settings.font_size_, text_settings.text_spacing_).x;

    for (size_t row = 0; row < list.size(); row++){

        const char* kName = list[row].first;
        HandValue hand_value = list[row].second;

        bool highlight =
            GameData::current_winnings_ > 0 &&
            EvaluateHand(GameData::player_hand_) == hand_value;

        Color color = highlight ? highlight_color : default_color;

        int payout = payout_table[hand_value] * GameData::bet_;
        const char* kPayoutAsText = ConvertToDecimal(payout);

        int y = text_settings.margin_y_ + row * (text_settings.font_size_ + text_settings.row_spacing_);

        DrawTextEx(text_settings.font_, kName, {(float)name_column_x_pos, (float)y}, text_settings.font_size_, text_settings.text_spacing_, color);
        DrawTextEx(text_settings.font_, kPayoutAsText, {(float)value_column_x_pos, (float)y}, text_settings.font_size_, text_settings.text_spacing_, color);
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