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

std::map<HandValue, int> payout_table;

HandValue EvaluateHand(const std::vector<Card> &hand);

void ConstructHistograms(
    std::map<int, int> &rank_histogram,
    std::map<Suit, int> &suit_histogram,
    const std::vector<Card> &hand
);

int CountJokers(const std::vector<Card> &hand);
bool HasStraight(const std::map<int, int> &rank_histogram, int jokers);
bool HasFlush(const std::map<Suit, int> &suit_histogram);
int MaxSameRank(const std::map<int, int> &rank_histogram, int jokers);
bool HasFullHouse(const std::map<int, int> &rank_histogram, int max_same_rank);
bool HasTwoPairs(const std::map<int, int> &rank_histogram, int max_same_rank);