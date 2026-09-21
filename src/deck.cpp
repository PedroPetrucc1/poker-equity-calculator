#include "poker/deck.hpp"

using namespace std;

Deck::Deck(){
    for(int suit=0; suit < 4; suit++){
        for(int rank=2; rank < 15; rank++){
            card_.push_back(Card(rank, static_cast<Suit>(suit)));
            used_.push_back(false);
        }
    }
}

void Deck::removeCard(const Card& card){
    int suit = static_cast<int>(card.getSuit());
    int index = suit*13 + (card.getRank()-2);
    used_[index] = true;
}

Card Deck::sortCard(mt19937& rng){
    while(true){
        uniform_int_distribution<int> dist(0, 51);
        int index = dist(rng);

        if(used_[index]) continue;
        else{
            used_[index] = true;
            return card_[index];
        }
    }
}

int Deck::avaibleCards() const{
    int av = 0;
    for(int i=0; i < 52; i++) if(!used_[i]) av++;
    return av;
}