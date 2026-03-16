#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "sort_step.h"
#include "visualizer.h"

std::vector<Step> bubble_sort(std::vector<int> array);
std::vector<Step> selection_sort(std::vector<int> array);

//랜덤한 배열을 만드는 함수(1~100)
std::vector<int> generate_array(int size){
	std::vector<int> array;
	srand(time(0));
	for(int i = 0; i <size; i++){
		array.push_back(rand() % 100 +1);
	}
	return array;
}

int select_algorithm(){
	std::cout << "\n=== 정렬 알고리즘 선택 ===" << std::endl;
	std::cout << "1. 버블 정렬" << std::endl;
	std::cout << "2. 선택 정렬" << std::endl;
    std::cout << "3. 삽입 정렬" << std::endl;
	std::cout << "4. 퀵 정렬" << std::endl;
	std::cout << "5. 병합 정렬" << std::endl;
	std::cout << "선택: ";

	int choice;
	std::cin >> choice;
	return choice;

}

int select_size() {
      std::cout << "\n=== 배열 크기 선택 ===" << std::endl;
      std::cout << "1. 10개" << std::endl;
      std::cout << "2. 20개" << std::endl;
      std::cout << "3. 50개" << std::endl;
      std::cout << "크기 선택: ";

      int choice;
      std::cin >> choice;

      if (choice == 1) return 10;
      if (choice == 2) return 20;
      if (choice == 3) return 50;
      return 10;
}

int main(){
	// std::vector<int> array = {9, 7, 5, 3, 1};
	// std::vector<Step> steps = bubble_sort(array);
	// std::cout << "총 스텝 수: " << steps.size() << std::endl;

	setlocale(LC_ALL, "");
	int algorithm = select_algorithm();
	int size = select_size();

	std::vector<int> array = generate_array(size);
	std::vector<Step> steps;
	std::string title;

	if(algorithm == 1){
		steps = bubble_sort(array);
		title = "Bubble Sort";
	} else if(algorithm == 2){
		steps = selection_sort(array);
		title = "Selection Sort";
	} else {
		std::cout << "아직 구현 안함. "<< std::endl;
		return 0;
	}
	play(steps, title);

	return 0;
}

