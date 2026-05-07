#include "InsertionSorter.h"

std::vector<Step> InsertionSorter::sort(std::vector<int> array) {
    std::vector<Step> steps;
    int size = array.size();
    std::vector<bool> sorted(size, false);
    int compare_count = 0;
    int swap_count = 0;

    for (int i = 1; i < size; i++) {
        int current_value = array[i];
        int j = i - 1;

        while (j >= 0) {
            compare_count++;

            Step compare_step;
            compare_step.array = array;
            compare_step.compare_left = j;
            compare_step.compare_right = i;
            compare_step.sorted = sorted;
            compare_step.compare_count = compare_count;
            compare_step.swap_count = swap_count;
            steps.push_back(compare_step);

            if (array[j] > current_value) {
                swap_count++;
                array[j + 1] = array[j];

                Step swap_step;
                swap_step.array = array;
                swap_step.swap_left = j;
                swap_step.swap_right = j + 1;
                swap_step.sorted = sorted;
                swap_step.compare_count = compare_count;
                swap_step.swap_count = swap_count;
                steps.push_back(swap_step);

                j--;
            } else {
                break;
            }
        }
        array[j + 1] = current_value;
    }

    for (int i = 0; i < size; i++) {
        sorted[i] = true;
    }

    Step final_step;
    final_step.array = array;
    final_step.sorted = sorted;
    steps.push_back(final_step);

    return steps;
}
