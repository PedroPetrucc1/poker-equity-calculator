#include "poker/handEvaluator.hpp"
#include "poker/card.hpp"

using namespace std;

int HandEvaluator::evaluator(const vector<Card>& cards) const{
    vector <int> RankEvaluator(15, 0);
    vector <int> SuitEvaluator(4, 0);
    for(int i=0; i < 7; i++){
        RankEvaluator[(cards[i].getRank())]++; //freq dos ranks
        SuitEvaluator[(static_cast<int>(cards[i].getSuit()))]++; //freq dos suits
    }

    int pair = 0, three = 0, four = 0;
    int currentseq = 0, first = 1;
    bool flush = false, straight = false, royal = false;
    for(int i=1; i < 15; i++){
        if(RankEvaluator[i] == 2) pair++;
        if(RankEvaluator[i] == 3) three++;
        if(RankEvaluator[i] == 4) four++;
        
    }

    RankEvaluator[1] = RankEvaluator[14];
    int lastA = -1;
    for(int i=1; i < 15; i++){
        if(RankEvaluator[i] >= 1) currentseq++;
        
        if(currentseq >= 5){
            straight = true;
            lastA = i;
        }
        
        if(RankEvaluator[i] == 0) currentseq = 0;
    }
    if(lastA == 14) royal = true;

    for(int i=0; i < 4; i++){
        if(SuitEvaluator[i] >= 5) flush = true;
    }

    if(pair == 1 && three != 1) return 2;
    else if(pair == 2) return 3;
    else if(three == 1) return 4;
    else if(straight && !flush) return 5;
    else if(flush && !straight && pair != 1) return 6;
    else if(pair == 1 && three == 1) return 7;
    else if(four == 1) return 8;
    else if(straight && flush && !royal) return 9;
    else if(straight && flush && royal) return 10;
    else return 1;

}