#pragma once
#include "Sorter.h"

class QuickSorter : public Sorter {
public:
    std::vector<Step> sort(std::vector<int> array) override;
    std::string getName() const override { return "Quick Sort"; }
private:
    int partition(std::vector<int>& array, int left, int right,
                  std::vector<Step>& steps, std::vector<bool>& sorted,
                  int& compare_count, int& swap_count);
    void sort_recursive(std::vector<int>& array, int left, int right,
                        std::vector<Step>& steps, std::vector<bool>& sorted,
                        int& compare_count, int& swap_count);
};
