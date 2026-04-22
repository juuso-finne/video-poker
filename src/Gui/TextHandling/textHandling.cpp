#include "../gui.h"
#include <string>
#include "../../Game/GameData/gameData.h"
#include "textHandling.h"
#include <raymath.h>

const char *ConvertToDecimal(int value){
    return TextFormat("%d.%02d", abs(value/100), abs(value%100));
}

void PrintTexts(){
    PrintPayouts(TextSettings(30, 30, 10, 100, 10, 3, 5));
    PrintBet(TextSettings(30, 32, 10, 10, 10, 3, 5));
    PrintTotalWins(TextSettings());
    PrintTotalBets(TextSettings());
    PrintCurrentWinnings(TextSettings());
    PrintNetProfit(TextSettings());
}

void PrintTotalBets(const TextSettings &text_settings){

    const char* total_bets_text = ConvertToDecimal(GameData::total_bets_);

    std::string output = std::string("TOTAL BETS: ") + std::string(total_bets_text);
    float text_width = text_settings.MeasureWidth("TOTAL BETS: XXX.XX");

    float x = ScreenConstants::screen_width_ - text_width - text_settings.margin_x_ - text_settings.padding_;
    float y = text_settings.margin_y_ + text_settings.padding_;

    DrawTextEx(text_settings.font_, output.c_str(), {x, y}, text_settings.font_size_, text_settings.text_spacing_, WHITE);
    DrawTextBox({x, y}, text_width, text_settings.font_size_, text_settings.padding_);
}

void PrintTotalWins(const TextSettings &text_settings){
    const char* total_bets_text = ConvertToDecimal(GameData::total_winnings_);

    std::string output = std::string("TOTAL WINNINGS: ") + std::string(total_bets_text);
    float text_width = text_settings.MeasureWidth("TOTAL WINNINGS: XXX.XX");

    float x = text_settings.margin_x_ + text_settings.padding_;
    float y = text_settings.margin_y_ + text_settings.padding_;

    DrawTextEx(text_settings.font_, output.c_str(), {x, y}, text_settings.font_size_, text_settings.text_spacing_, WHITE);
    DrawTextBox({x, y}, text_width, text_settings.font_size_, text_settings.padding_);
}

void PrintBet(const TextSettings &text_settings){

    const char* text = ConvertToDecimal(GameData::bet_);
    float text_width = text_settings.MeasureWidth("x.xx");

    Vector2 origin = {(float)text_settings.MeasureWidth(text) / 2, (float)text_settings.font_size_ / 2};

    float radius = text_width / 2 + text_settings.padding_;
    float x = ScreenConstants::screen_width_ / 2;
    float y = text_settings.margin_y_ + radius;

    Color dark_yellow = {140, 100, 0 ,255};
    DrawCircle(x + 5, y, radius, dark_yellow);
    DrawCircle(x, y, radius, GOLD);
    DrawTextPro(text_settings.font_, text, {x, y}, origin, 0, text_settings.font_size_, text_settings.text_spacing_, BLACK);
}

void DrawTextBox(Vector2 text_position, float text_width, int text_height, float padding){

    float x = text_position.x - padding;
    float y = text_position.y - padding;

    float width = text_width + 2 * padding;
    float height = text_height + 2 * padding;

    Rectangle dest{x, y, width, height};
    DrawRectangleRoundedLines(dest, .1, 1, LIGHTGRAY);
}

void PrintNetProfit(const TextSettings &text_settings){
    int net_profit = GameData::total_winnings_ - GameData::total_bets_;

    std::string output = std::string(net_profit < 0 ? "NET: -" : "NET: ") + std::string(ConvertToDecimal(net_profit));

    float x = 4 * (ScreenConstants::button_width_ + ScreenConstants::button_gap_) + ScreenConstants::button_gap_ + text_settings.padding_;
    float y = ScreenConstants::screen_height_ - ScreenConstants::button_gap_ - ScreenConstants::button_height_ + text_settings.padding_;

    float text_width = text_settings.MeasureWidth("NET: -XXX.XX");

    DrawTextEx(text_settings.font_, output.c_str(), {x, y}, text_settings.font_size_, text_settings.text_spacing_, WHITE);
    DrawTextBox({x, y}, text_width, text_settings.font_size_, text_settings.padding_);
}

void PrintPayouts(const TextSettings &text_settings){
    std::string name_column_string;
    std::string value_column_string;

    Color default_color = WHITE;
    Color highlight_color = RED;

    const std::vector<std::pair<const char*, HandValue>> list = GetNameValuePairs();

    int screen_width = ScreenConstants::screen_width_;

    float value_column_width = text_settings.MeasureWidth("XX.XX");
    float name_column_width = text_settings.MeasureWidth("STRAIGHT FLUSH");

    int value_column_x_pos = screen_width - value_column_width - text_settings.margin_x_ - text_settings.padding_;
    int name_column_x_pos = value_column_x_pos - text_settings.column_gap_ - name_column_width;

    float y_offset = text_settings.margin_y_ + text_settings.padding_;
    float total_width = name_column_width + value_column_width + text_settings.column_gap_;
    float total_height = list.size() * text_settings.font_size_ + (list.size() - 1) * text_settings.row_spacing_;

    DrawTextBox({(float)name_column_x_pos, y_offset}, total_width, total_height, text_settings.padding_);

    for (size_t row = 0; row < list.size(); row++){

        const char* kName = list[row].first;
        HandValue hand_value = list[row].second;

        bool highlight =
            GameData::current_winnings_ > 0 &&
            EvaluateHand(GameData::player_hand_) == hand_value;

        Color color = highlight ? highlight_color : default_color;

        int payout = payout_table[hand_value] * GameData::bet_;
        const char* kPayoutAsText = ConvertToDecimal(payout);

        int y = y_offset + row * (text_settings.font_size_ + text_settings.row_spacing_);

        DrawTextEx(text_settings.font_, kName, {(float)name_column_x_pos, (float)y}, text_settings.font_size_, text_settings.text_spacing_, color);
        DrawTextEx(text_settings.font_, kPayoutAsText, {(float)value_column_x_pos, (float)y}, text_settings.font_size_, text_settings.text_spacing_, color);
    }
}

void PrintCurrentWinnings(const TextSettings &text_settings){

    if(GameData::current_winnings_ == 0){
        return;
    }

    float text_width = text_settings.MeasureWidth("POT: XXX.XX");
    float text_height = text_settings.font_size_;

    float x = ScreenConstants::GetCardSlots()[2].x + ScreenConstants::card_width_ / 2;
    float y =
        ScreenConstants::screen_height_ - 2 * ScreenConstants::button_height_ - 3 * ScreenConstants::button_gap_
        - ScreenConstants::card_height_ - text_settings.margin_y_ - text_settings.padding_
        ;

    const char* text = std::string(std::string("POT: ") + ConvertToDecimal(GameData::current_winnings_)).c_str();


    Vector2 origin = {text_width / 2, text_height};

    DrawTextPro(text_settings.font_, text, {x, y}, origin, 0, text_height, text_settings.text_spacing_, WHITE);
    DrawTextBox(Vector2Subtract({x, y}, origin), text_width, text_height, text_settings.padding_);
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