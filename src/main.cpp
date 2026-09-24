#include <iostream>
#include <random>
#include "poker/simulator.hpp"

int main() {
    std::mt19937 rng(std::random_device{}());
    Simulator sim;

    std::vector<Card> minhasCartas = {
        Card(14, Suit::SPADES), Card(14, Suit::HEARTS)  // AA
    };
    std::vector<Card> boardVazio = {};  // pre-flop, nada revelado ainda

    ResultSimulator resultado = sim.simulate(minhasCartas, boardVazio, 10000, rng);

    std::cout << "Vitorias: " << resultado.victories << "%" << std::endl;
    std::cout << "Empates: " << resultado.draw << "%" << std::endl;
    std::cout << "Derrotas: " << resultado.defeat << "%" << std::endl;

    return 0;
}