#include <ncurses.h>
#include "visualizer.h"

#define COLOR_DEFAULT 1
#define COLOR_COMPARE 2
#define COLOR_SWAP    3
#define COLOR_SORTED  4

void play(const std::vector<Step>& steps, const std::string& title){
	initscr();		//ncurses 시작
	noecho();		//키 입력 화면에 출력 안함
	cbreak();		//엔터 없이 바로 키입력
	keypad(stdscr, TRUE);	//방향키 사용 가능하게 
	start_color();		//색상 사용 가능.
	
	//색상 초기화 (번호, 글자색, 배경색)
	init_pair(COLOR_DEFAULT, COLOR_WHITE, COLOR_BLACK); 
	init_pair(COLOR_COMPARE, COLOR_RED, COLOR_BLACK);
	init_pair(COLOR_SWAP, COLOR_YELLOW, COLOR_BLACK);
	init_pair(COLOR_SORTED, COLOR_GREEN, COLOR_BLACK);

	int current_step = 0;
	int total_steps = steps.size();
	bool is_paused = false;
	int delay_ms = 100;

	while(true){
		const Step& step = steps[current_step];
		clear();

		mvprintw(0, 0, "%s", title.c_str());
		mvprintw(1, 0, "Step: %d / %d ||| 비교: %d  스왑: %d",
				current_step + 1, total_steps,
				step.compare_count, step.swap_count);
	}
}

