#include "gameRules.h"

std::map<HandValue, int> payout_table = {
    {HandValue::kFiveOfAKind, 50},
    {HandValue::kStraightFlush, 30},
    {HandValue::kFourOfAKind, 15},
    {HandValue::kFullHouse, 8},
    {HandValue::kFlush, 4},
    {HandValue::kStraight, 3},
    {HandValue::kThreeOfAKind, 2},
    {HandValue::kTwoPairs, 2},
    {HandValue::kNone, 0}
};