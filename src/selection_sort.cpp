#include <vector>
#include "sort_step.h"

std::vector<Step> selection_sort(std::vector<int> array){
    std::vector<Step> resultSteps;
    int size = array.size();
    std::vector<bool> sorted(size, false);
    
    int compare_count = 0;
    int swap_count = 0;
    int current_min;



    for(int i = 0; i < size -1; i++){
        current_min = i;

        for(int j = i+1; j < size; j++){
            compare_count++;

            Step compare_step;
            compare_step.array = array;
            compare_step.compare_left = j;
            compare_step.compare_right = current_min;
            compare_step.sorted = sorted;
            compare_step.compare_count = compare_count;
            compare_step.swap_count = swap_count;

            resultSteps.push_back(compare_step);

            if(array[j]<array[current_min]){
                current_min = j;
            } 
                
        }

        if(i != current_min){
            std::swap(array[i], array[current_min]);
            swap_count++;

            Step swap_steps;
            swap_steps.array = array;
            swap_steps.compare_left = i;
            swap_steps.compare_right = current_min;
            swap_steps.swap_left = i;
            swap_steps.swap_right = current_min;
            swap_steps.sorted = sorted;
            swap_steps.compare_count = compare_count;
            swap_steps.swap_count = swap_count;
            resultSteps.push_back(swap_steps);
        }
        sorted[i] = true;
    }
    sorted[size-1] = true;

    Step final_step;
    final_step.array = array;
    final_step.sorted = sorted;
    
    resultSteps.push_back(final_step);

    return resultSteps;
}