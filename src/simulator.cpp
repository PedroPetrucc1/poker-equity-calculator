#include "poker/simulator.hpp"
#include "poker/deck.hpp"
#include "poker/handEvaluator.hpp"

using namespace std;

ResultSimulator Simulator::simulate(
    const std::vector<Card>& myCards,
    const std::vector<Card>& boardAvailable,
    int numRounds,
    std::mt19937& rng
) const{
    HandEvaluator evaluate;
    int victories = 0, draw = 0, defeat = 0;
    int missingCards = 5 - boardAvailable.size();

    for(int round = 0; round < numRounds; round++){
        Deck deck;

        //remove as cartas pra nao sortear as mesmas
        for(const Card& c : myCards) deck.removeCard(c);
        for(const Card& c : boardAvailable) deck.removeCard(c);

        //carta aleatorio do oponente
        vector<Card> enemyCards;
        enemyCards.push_back(deck.sortCard(rng));
        enemyCards.push_back(deck.sortCard(rng));


        //sorteia o resto da mesa
        vector <Card> missingBoardCards;
        for(int i=0 ; i< missingCards; i++) missingBoardCards.push_back(deck.sortCard(rng));

        vector<Card> FinishBoard = boardAvailable;
        FinishBoard.insert(FinishBoard.end(), missingBoardCards.begin(), missingBoardCards.end());


        vector <Card> myHand = myCards;
        myHand.insert(myHand.end(), FinishBoard.begin(), FinishBoard.end());

        vector <Card> oponentHand = enemyCards;
        oponentHand.insert(oponentHand.end(), FinishBoard.begin(), FinishBoard.end());

        int myPower = evaluate.evaluator(myHand);
        int oponentPower = evaluate.evaluator(oponentHand);

        if(myPower > oponentPower) victories++;
        else if(myPower == oponentPower) draw++;
        else defeat++;
    }

    ResultSimulator result;
    result.victories = (double)victories / numRounds * 100.0;
    result.draw = (double)draw / numRounds * 100.0;
    result.defeat = (double)defeat / numRounds * 100.0;

    return result;
}
