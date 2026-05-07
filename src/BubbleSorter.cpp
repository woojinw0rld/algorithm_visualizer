#include "BubbleSorter.h"

std::vector<Step> BubbleSorter::sort(std::vector<int> array) {
    std::vector<Step> steps;
    int size = array.size();
    std::vector<bool> sorted(size, false);
    int compare_count = 0;
    int swap_count = 0;

    for (int end = size - 1; end > 0; end--) {
        for (int current = 0; current < end; current++) {
            compare_count++;

            Step compare_step;
            compare_step.array = array;
            compare_step.compare_left = current;
            compare_step.compare_right = current + 1;
            compare_step.sorted = sorted;
            compare_step.compare_count = compare_count;
            compare_step.swap_count = swap_count;
            steps.push_back(compare_step);

            if (array[current] > array[current + 1]) {
                std::swap(array[current], array[current + 1]);
                swap_count++;

                Step swap_step;
                swap_step.array = array;
                swap_step.compare_left = current;
                swap_step.compare_right = current + 1;
                swap_step.swap_left = current;
                swap_step.swap_right = current + 1;
                swap_step.compare_count = compare_count;
                swap_step.swap_count = swap_count;
                swap_step.sorted = sorted;
                steps.push_back(swap_step);
            }
        }
        sorted[end] = true;
    }
    sorted[0] = true;

    Step final_step;
    final_step.array = array;
    final_step.sorted = sorted;
    steps.push_back(final_step);

    return steps;
}
