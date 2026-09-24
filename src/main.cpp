#include <iostream>
#include "poker/handEvaluator.hpp"
#include "poker/card.hpp"

using namespace std;

int main() {
    HandEvaluator eval;

    //par de Reis
    vector<Card> mao1 = {
        Card(13, Suit::SPADES), Card(13, Suit::HEARTS),
        Card(2, Suit::CLUBS), Card(5, Suit::DIAMONDS),
        Card(9, Suit::CLUBS), Card(11, Suit::HEARTS), Card(4, Suit::SPADES)
    };
    cout << "Par de Reis: " << eval.evaluator(mao1) << std::endl;  //213

    //flush de espadas, carta alta Q
    vector<Card> mao2 = {
        Card(12, Suit::SPADES), Card(9, Suit::SPADES),
        Card(7, Suit::SPADES), Card(4, Suit::SPADES),
        Card(2, Suit::SPADES), Card(11, Suit::HEARTS), Card(3, Suit::CLUBS)
    };
    cout << "Flush Q alta: " << eval.evaluator(mao2) << std::endl;  //612

    //full house, trinca de 8, par de 3
    vector<Card> mao3 = {
        Card(8, Suit::SPADES), Card(8, Suit::HEARTS), Card(8, Suit::CLUBS),
        Card(3, Suit::SPADES), Card(3, Suit::HEARTS),
        Card(2, Suit::CLUBS), Card(5, Suit::DIAMONDS)
    };
    cout << "Full house 8/3: " << eval.evaluator(mao3) << std::endl;  //708

    return 0;
}