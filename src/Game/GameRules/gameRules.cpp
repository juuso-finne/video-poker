#include "gameRules.h"
#include <algorithm>


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
            bool new_suit = suit_histogram.insert({suit, 1}).second;
            if (!new_suit){
                suit_histogram[suit]++;
            }

            bool new_rank = rank_histogram.insert({rank, 1}).second;
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

bool HasStraight(const std::map<int, int> &rank_histogram, int jokers){
    if(rank_histogram.size() + jokers < 5){
        return false;
    }
    std::vector<int> ranks = {};

    for(std::map<int, int>::const_iterator it = rank_histogram.begin(); it != rank_histogram.end(); it++){
        ranks.push_back(it -> first);
    }

    std::sort(ranks.begin(), ranks.end());

    // Check for high-end straights
    if(ranks[0] == 1 && ranks[1] >= 10){
        return true;
    }

    for(int i = 0; i < 4; i++){
        int gap = ranks[i + 1] - ranks[i];
        jokers -= gap - 1;
        if (jokers < 0){
            return false;
        }
    }

    return true;
}
