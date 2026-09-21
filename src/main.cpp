#include <iostream>
#include <random>
#include "poker/deck.hpp"

using namespace std;

int main() {
    mt19937 rng(std::random_device{}());

    Deck deck;
    deck.removeCard(Card(14, Suit::SPADES));
    deck.removeCard(Card(13, Suit::HEARTS));

    cout << "Disponiveis apos remover 2: " << deck.avaibleCards() << endl;

    for (int i = 0; i < 5; i++) {
        Card sorteada = deck.sortCard(rng);
        std::cout << "Sorteada: " << sorteada.toString() << endl;
    }

    cout << "Disponiveis apos sortear 5: " << deck.avaibleCards() << endl;

    return 0;
}