#pragma once
#include "Sorter.h"

class MergeSorter : public Sorter {
public:
    std::vector<Step> sort(std::vector<int> array) override;
    std::string getName() const override { return "Merge Sort"; }
private:
    void merge(std::vector<int>& array, int left, int middle, int right,
               int& compare_count, int& swap_count,
               std::vector<Step>& steps, std::vector<bool>& sorted);
    void sort_recursive(std::vector<int>& array, int left, int right,
                        int& compare_count, int& swap_count,
                        std::vector<Step>& steps, std::vector<bool>& sorted);
};
