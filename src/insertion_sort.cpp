#include <vector>
#include "sort_step.h"

std::vector<Step> insertion_sort(std::vector<int> array){
    std::vector<Step> resultStep;
    int size = array.size();
    std::vector<bool> sorted(size, false);
    int compeare_count = 0;
    int swap_count = 0;

    for(int i=1; i<size; i++){
        int current_min = array[i];
        int j = i-1;
        while(j >= 0){
            compeare_count++;

            Step compeare_step;
            compeare_step.array = array;
            compeare_step.compare_left = j;
            compeare_step.compare_right = i;
            compeare_step.sorted = sorted;
            compeare_step.compare_count = compeare_count;
            compeare_step.swap_count = swap_count;
            resultStep.push_back(compeare_step);

            if(array[j] > current_min){
                swap_count++;
                array[j+1] = array[j];
                
                Step swap_step;
                swap_step.array = array;
                swap_step.swap_left = j;
                swap_step.swap_right = j+1;
                swap_step.sorted = sorted;
                swap_step.compare_count = compeare_count;
                swap_step.swap_count = swap_count;
                resultStep.push_back(swap_step);
                
                j--;
            }else{
                break;
            }
        }
        //sorted[i-1] = true;
        array[j+1] = current_min;
    }
//    sorted[size-1] = true;

    for(int i = 0; i < size; i++){
        sorted[i] = true;
    }

    Step final_step;
    final_step.array = array;
    final_step.sorted = sorted;

    resultStep.push_back(final_step);

    return resultStep;
}