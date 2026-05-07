#pragma once
#include "Sorter.h"

class BubbleSorter : public Sorter {
public:
    std::vector<Step> sort(std::vector<int> array) override;
    std::string getName() const override { return "Bubble Sort"; }
};
