#pragma once
#include "Sorter.h"

class SelectionSorter : public Sorter {
public:
    std::vector<Step> sort(std::vector<int> array) override;
    std::string getName() const override { return "Selection Sort"; }
};
