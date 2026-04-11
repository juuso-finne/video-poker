#pragma once
#include "../../Card/card.h"
#include <map>
#include <vector>

enum class HandValue{
    kFiveOfAKind,
    kStraightFlush,
    kFourOfAKind,
    kFullHouse,
    kFlush,
    kStraight,
    kThreeOfAKind,
    kTwoPairs,
    kNone
};

HandValue EvaluateHand(const std::vector<Card> &hand);
void ConstructHistograms(
    std::map<int, int> &rank_histogram,
    std::map<Suit, int> &suit_histogram,
    const std::vector<Card> &hand
);
int CountJokers(const std::vector<Card> &hand);