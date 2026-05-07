#include "SortApp.h"
#include "BubbleSorter.h"
#include "SelectionSorter.h"
#include "InsertionSorter.h"
#include "QuickSorter.h"
#include "MergeSorter.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

void SortApp::run() {
    setlocale(LC_ALL, "");
    auto sorter = select_algorithm();
    if (!sorter) {
        std::cout << "Not implemented." << std::endl;
        return;
    }
    int size = select_size();
    std::vector<int> array = generate_array(size);
    std::vector<Step> steps = sorter->sort(array);
    visualizer.play(steps, sorter->getName());
}

std::unique_ptr<Sorter> SortApp::select_algorithm() {
    std::cout << "\n=== Select Sorting Algorithm ===" << std::endl;
    std::cout << "1. Bubble Sort" << std::endl;
    std::cout << "2. Selection Sort" << std::endl;
    std::cout << "3. Insertion Sort" << std::endl;
    std::cout << "4. Quick Sort" << std::endl;
    std::cout << "5. Merge Sort" << std::endl;
    std::cout << "Select: ";

    int choice;
    std::cin >> choice;

    switch (choice) {
        case 1: return std::make_unique<BubbleSorter>();
        case 2: return std::make_unique<SelectionSorter>();
        case 3: return std::make_unique<InsertionSorter>();
        case 4: return std::make_unique<QuickSorter>();
        case 5: return std::make_unique<MergeSorter>();
        default: return nullptr;
    }
}

int SortApp::select_size() {
    std::cout << "\n=== Select Array Size ===" << std::endl;
    std::cout << "1. 10" << std::endl;
    std::cout << "2. 20" << std::endl;
    std::cout << "3. 50" << std::endl;
    std::cout << "Select: ";

    int choice;
    std::cin >> choice;

    if (choice == 1) return 10;
    if (choice == 2) return 20;
    if (choice == 3) return 50;
    return 10;
}

std::vector<int> SortApp::generate_array(int size) {
    std::vector<int> array;
    srand(time(0));
    for (int i = 0; i < size; i++) {
        array.push_back(rand() % 100 + 1);
    }
    return array;
}
