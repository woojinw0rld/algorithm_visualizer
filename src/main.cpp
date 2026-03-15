#include <iostream>
#include "sort_step.h"
#include <vector>

std::vector<Step> bubble_sort(std::vector<int> array);

int main(){
	std::vector<int> array = {9, 7, 5, 3, 1};
	std::vector<Step> steps = bubble_sort(array);
	std::cout << "총 스텝 수: " << steps.size() << std::endl;
	return 0;
}

