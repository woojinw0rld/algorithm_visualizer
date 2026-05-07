#pragma once
#include <vector>
#include <string>
#include "sort_step.h"

class Sorter {
public:
    virtual ~Sorter() = default;
    virtual std::vector<Step> sort(std::vector<int> array) = 0;
    virtual std::string getName() const = 0;
};
