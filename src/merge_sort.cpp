#include <vector>
#include "sort_step.h"
void merge(std::vector<int>& array, int left, int middle, int right, int& compare_count, int& swap_count, std::vector<Step>& resultStep, std::vector<bool>& sorted){
    // left~right 구간을 임시 배열에 복사
    std::vector<int> temp(array.begin() + left, array.begin() + right + 1);

    int i = 0;                      // temp의 왼쪽 파트 포인터
    int j = middle - left + 1;      // temp의 오른쪽 파트 포인터
    int left_end  = middle - left;
    int right_end = right - left;
    int k = left;                   // array에 쓰는 포인터

    while (i <= left_end && j <= right_end) {
        compare_count++;

        Step compare_step;
        compare_step.array         = array;
        compare_step.compare_left  = left + i;
        compare_step.compare_right = left + j;
        compare_step.sorted        = sorted;
        compare_step.compare_count = compare_count;
        compare_step.swap_count    = swap_count;
        resultStep.push_back(compare_step);

        if (temp[i] <= temp[j]) {
            array[k] = temp[i++];
        } else {
            array[k] = temp[j++];
        }
        swap_count++;

        Step place_step;
        place_step.array         = array;
        place_step.swap_left     = k;   // 배치된 위치 노란색 표시
        place_step.sorted        = sorted;
        place_step.compare_count = compare_count;
        place_step.swap_count    = swap_count;
        resultStep.push_back(place_step);

        k++;
    }

    // 왼쪽 나머지
    while (i <= left_end) {
        array[k] = temp[i++];
        swap_count++;

        Step place_step;
        place_step.array         = array;
        place_step.swap_left     = k;
        place_step.sorted        = sorted;
        place_step.compare_count = compare_count;
        place_step.swap_count    = swap_count;
        resultStep.push_back(place_step);

        k++;
    }

    // 오른쪽 나머지
    while (j <= right_end) {
        array[k] = temp[j++];
        swap_count++;

        Step place_step;
        place_step.array         = array;
        place_step.swap_left     = k;
        place_step.sorted        = sorted;
        place_step.compare_count = compare_count;
        place_step.swap_count    = swap_count;
        resultStep.push_back(place_step);

        k++;
    }

    // 이 구간 정렬 완료 표시 (초록색)
    for (int idx = left; idx <= right; idx++) {
        sorted[idx] = true;
    }
}
void merge_sort_recursive(std::vector<int>& array, int left, int right, int& compare_count, int& swap_count, std::vector<Step>& resultStep, std::vector<bool>& sorted){
    int middle;
    if(left<right){
        middle = (left+right)/2;
        merge_sort_recursive(array, left, middle, compare_count, swap_count, resultStep, sorted);
        merge_sort_recursive(array, middle+1, right, compare_count, swap_count, resultStep, sorted);
        merge(array, left, middle, right, compare_count, swap_count, resultStep, sorted);
    }
    

    

}
std::vector<Step> merge_sort(std::vector<int> array){
    std::vector<Step> resulteStep;
    int size = array.size();
    std::vector<bool> sorted(size, false);
    int compare_count = 0;
    int swap_count = 0;


    merge_sort_recursive(array, 0, size-1, compare_count, swap_count, resulteStep, sorted);

    Step final_step;
    final_step.array         = array;
    final_step.sorted        = sorted;
    final_step.compare_count = compare_count;
    final_step.swap_count    = swap_count;
    resulteStep.push_back(final_step);

    return resulteStep;

}
