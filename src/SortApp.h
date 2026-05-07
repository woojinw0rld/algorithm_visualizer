#pragma once
#include <vector>
#include <memory>
#include "Sorter.h"
#include "Visualizer.h"

class SortApp {
public:
    void run();
private:
    Visualizer visualizer;
    std::unique_ptr<Sorter> select_algorithm();
    int select_size();
    std::vector<int> generate_array(int size);
};
