#include "gameRules.h"


HandValue EvaluateHand(const std::vector<Card> &hand){

    std::map<int, int> rank_histogram;
    std::map<Suit, int> suit_histogram;
    ConstructHistograms(rank_histogram, suit_histogram, hand);
    int jokers = CountJokers(hand);
    return HandValue::kNone;
}

void ConstructHistograms(
    std::map<int, int> &rank_histogram,
    std::map<Suit, int> &suit_histogram,
    const std::vector<Card> &hand
){
    for(Card card : hand){
        const Suit suit = card.GetSuit();
        const int rank = card.GetRank();

        if(rank > 0 && rank < 14){
            bool new_suit = suit_histogram.insert({suit, 0}).second;
            if (!new_suit){
                suit_histogram[suit]++;
            }

            bool new_rank = rank_histogram.insert({rank, 0}).second;
            if(!new_rank){
                rank_histogram[rank]++;
            }
        }
    }
}

int CountJokers(const std::vector<Card> &hand){
    int output = 0;
    for(Card card : hand){
        if(card.GetSuit() == Suit::kJoker){
            output++;
        }
    }
    return output;
}
