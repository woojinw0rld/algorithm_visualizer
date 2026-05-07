#include "QuickSorter.h"

int QuickSorter::partition(std::vector<int>& array, int left, int right,
                           std::vector<Step>& steps, std::vector<bool>& sorted,
                           int& compare_count, int& swap_count) {
    int pivot = array[right];
    int i = left - 1;

    for (int j = left; j < right; j++) {
        compare_count++;

        Step compare_step;
        compare_step.array = array;
        compare_step.compare_left = j;
        compare_step.compare_right = right;
        compare_step.sorted = sorted;
        compare_step.compare_count = compare_count;
        compare_step.swap_count = swap_count;
        steps.push_back(compare_step);

        if (array[j] <= pivot) {
            i++;
            std::swap(array[i], array[j]);
            swap_count++;

            Step swap_step;
            swap_step.array = array;
            swap_step.swap_left = i;
            swap_step.swap_right = j;
            swap_step.sorted = sorted;
            swap_step.compare_count = compare_count;
            swap_step.swap_count = swap_count;
            steps.push_back(swap_step);
        }
    }

    std::swap(array[i + 1], array[right]);
    swap_count++;
    sorted[i + 1] = true;

    Step pivot_step;
    pivot_step.array = array;
    pivot_step.swap_left = i + 1;
    pivot_step.swap_right = right;
    pivot_step.sorted = sorted;
    pivot_step.compare_count = compare_count;
    pivot_step.swap_count = swap_count;
    steps.push_back(pivot_step);

    return i + 1;
}

void QuickSorter::sort_recursive(std::vector<int>& array, int left, int right,
                                 std::vector<Step>& steps, std::vector<bool>& sorted,
                                 int& compare_count, int& swap_count) {
    if (left >= right) {
        if (left == right) sorted[left] = true;
        return;
    }

    int pivot_index = partition(array, left, right, steps, sorted, compare_count, swap_count);
    sort_recursive(array, left, pivot_index - 1, steps, sorted, compare_count, swap_count);
    sort_recursive(array, pivot_index + 1, right, steps, sorted, compare_count, swap_count);
}

std::vector<Step> QuickSorter::sort(std::vector<int> array) {
    std::vector<Step> steps;
    int size = array.size();
    std::vector<bool> sorted(size, false);
    int compare_count = 0;
    int swap_count = 0;

    sort_recursive(array, 0, size - 1, steps, sorted, compare_count, swap_count);

    Step final_step;
    final_step.array = array;
    final_step.sorted = sorted;
    final_step.compare_count = compare_count;
    final_step.swap_count = swap_count;
    steps.push_back(final_step);

    return steps;
}
