#pragma once
#include <vector>

//모든 cpp파일이 이 구조체를 활용하여 현재 상태 표시.
struct Step{
	std::vector<int> array;				//기본 비교할 배열.
	int compare_left = -1, compare_right = -1;	//비교 중인 인덱스(빨강)
	int swap_left = -1, swap_right = -1;		//스왑 인덱스(노랑)
	std::vector<bool> sorted;			//완료된 인덱스(초록)
	int compare_count = 0;
	int swap_count = 0;
};


