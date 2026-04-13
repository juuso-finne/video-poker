#include "gui.h"
#include <string>
#include "../Game/GameData/gameData.h"

const char *ConvertToDecimal(int value){
    return TextFormat("%d.%02d", value/100, value%100);
}

void PrintPayouts(int margin, int font_size){
    std::string name_column_string;
    std::string value_column_string;

    ConstructColums(name_column_string, value_column_string);

    const char * name_column = name_column_string.c_str();
    const char * value_column = value_column_string.c_str();

    int value_column_x_pos = ScreenConstants::screen_width_ - MeasureText("xx.xx", font_size) - margin;
    int name_column_x_pos = value_column_x_pos - margin - MeasureText(name_column, font_size);

    DrawText(name_column, name_column_x_pos, margin, font_size, WHITE);
    DrawText(value_column, value_column_x_pos, margin, font_size, WHITE);
}

void ConstructColums(std::string &name_column, std::string &value_column){
    for (std::pair<const char*, HandValue> pair: GetNameValuePairs()){

        const char* name = pair.first;
        const HandValue hand_value = pair.second;

        name_column += name + std::string("\n");

        int payout = GameData::bet_ * payout_table[hand_value];
        value_column += ConvertToDecimal(payout) + std::string("\n");
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