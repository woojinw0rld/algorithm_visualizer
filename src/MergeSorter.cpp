#include "MergeSorter.h"

void MergeSorter::merge(std::vector<int>& array, int left, int middle, int right,
                        int& compare_count, int& swap_count,
                        std::vector<Step>& steps, std::vector<bool>& sorted) {
    std::vector<int> temp(array.begin() + left, array.begin() + right + 1);

    int i = 0;
    int j = middle - left + 1;
    int left_end  = middle - left;
    int right_end = right - left;
    int k = left;

    while (i <= left_end && j <= right_end) {
        compare_count++;

        Step compare_step;
        compare_step.array = array;
        compare_step.compare_left  = left + i;
        compare_step.compare_right = left + j;
        compare_step.sorted = sorted;
        compare_step.compare_count = compare_count;
        compare_step.swap_count = swap_count;
        steps.push_back(compare_step);

        if (temp[i] <= temp[j]) {
            array[k] = temp[i++];
        } else {
            array[k] = temp[j++];
        }
        swap_count++;

        Step place_step;
        place_step.array = array;
        place_step.swap_left = k;
        place_step.sorted = sorted;
        place_step.compare_count = compare_count;
        place_step.swap_count = swap_count;
        steps.push_back(place_step);

        k++;
    }

    while (i <= left_end) {
        array[k] = temp[i++];
        swap_count++;

        Step place_step;
        place_step.array = array;
        place_step.swap_left = k;
        place_step.sorted = sorted;
        place_step.compare_count = compare_count;
        place_step.swap_count = swap_count;
        steps.push_back(place_step);

        k++;
    }

    while (j <= right_end) {
        array[k] = temp[j++];
        swap_count++;

        Step place_step;
        place_step.array = array;
        place_step.swap_left = k;
        place_step.sorted = sorted;
        place_step.compare_count = compare_count;
        place_step.swap_count = swap_count;
        steps.push_back(place_step);

        k++;
    }

    for (int idx = left; idx <= right; idx++) {
        sorted[idx] = true;
    }
}

void MergeSorter::sort_recursive(std::vector<int>& array, int left, int right,
                                 int& compare_count, int& swap_count,
                                 std::vector<Step>& steps, std::vector<bool>& sorted) {
    if (left < right) {
        int middle = (left + right) / 2;
        sort_recursive(array, left, middle, compare_count, swap_count, steps, sorted);
        sort_recursive(array, middle + 1, right, compare_count, swap_count, steps, sorted);
        merge(array, left, middle, right, compare_count, swap_count, steps, sorted);
    }
}

std::vector<Step> MergeSorter::sort(std::vector<int> array) {
    std::vector<Step> steps;
    int size = array.size();
    std::vector<bool> sorted(size, false);
    int compare_count = 0;
    int swap_count = 0;

    sort_recursive(array, 0, size - 1, compare_count, swap_count, steps, sorted);

    Step final_step;
    final_step.array = array;
    final_step.sorted = sorted;
    final_step.compare_count = compare_count;
    final_step.swap_count = swap_count;
    steps.push_back(final_step);

    return steps;
}
