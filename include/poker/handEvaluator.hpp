#pragma once
#include <vector>
#include "poker/card.hpp"

class HandEvaluator{
    public:
        int evaluator(const std::vector<Card>& cards) const; 
};