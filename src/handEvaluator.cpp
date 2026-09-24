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
    int Rankpair = -1, Rankthree = -1, Rankfour = -1;
    int currentseq = 0, first = 1;
    bool flush = false, straight = false;
    for(int i=1; i < 15; i++){
        if(RankEvaluator[i] == 2) pair++, Rankpair = max(Rankpair, i);
        if(RankEvaluator[i] == 3) three++, Rankthree = i;
        if(RankEvaluator[i] == 4) four++, Rankfour = i;
        
    }

    RankEvaluator[1] = RankEvaluator[14];
    //int lastA = -1;
    int RankStraight = -1, Rankflush = -1;
    for(int i=1; i < 15; i++){
        if(RankEvaluator[i] >= 1) currentseq++;
        
        if(currentseq >= 5){
            straight = true;
            RankStraight = i;
        }
        
        if(RankEvaluator[i] == 0) currentseq = 0;
    }
    
    for(int i=0; i < 4; i++){
        if(SuitEvaluator[i] >= 5) {
            flush = true;
            for(int j=0; j < 7; j++){
                if(static_cast<int>(cards[j].getSuit()) == i) Rankflush = max(Rankflush, cards[j].getRank());
            }
        }
    }
    
    bool straight_flush = false, royal_straight_flush = false;
    int LastRank_StraightFlush = -1;

    for(int suit=0; suit < 4; suit++){
        if(SuitEvaluator[suit] < 5) continue; //nao tem flush

        vector<int> RankSuit(15, 0);
        for(int i=0; i < 7; i++){
            if(static_cast<int>(cards[i].getSuit()) == suit) RankSuit[cards[i].getRank()]++;
        }

        int seq = 0, LastRank = -1;
        RankSuit[1] = RankSuit[14];
        for(int i=1; i < 15; i++){
            if(RankSuit[i] >= 1) seq++;
            else seq = 0;

            if(seq >= 5) straight_flush = true, LastRank_StraightFlush = i;
        }

        if(LastRank_StraightFlush == 14) royal_straight_flush = true;
    }

    

    if(royal_straight_flush) return 1000;
    else if(straight_flush) return 900 + LastRank_StraightFlush;
    else if(four == 1) return 800 +  Rankfour;
    else if(pair == 1 && three == 1) return 700 + Rankthree;
    else if(flush) return 600 + Rankflush;
    else if(straight) return 500 + RankStraight;
    else if(three == 1) return 400 + Rankthree;
    else if(pair == 2) return 300 + Rankpair;
    else if(pair == 1) return 200 + Rankpair;
    else return 100;
}