#include <iostream>
#include "poker/card.hpp"

using namespace std;

int main(){
    Card c1(14, Suit::SPADES);
    Card c2(13, Suit::DIAMONDS);

    cout << "Carta 1: " << c1.toString() << endl;
    cout << "Carta 2: " << c2.toString() << endl;
    cout << "Rank da carta 2:" << c2.getRank() << endl;

    return 0;
}