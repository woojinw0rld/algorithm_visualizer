#include <ncurses.h>
#include <algorithm>
#include "visualizer.h"

#define COLOR_DEFAULT 1
#define COLOR_COMPARE 2
#define COLOR_SWAP    3
#define COLOR_SORTED  4

void Visualizer::draw_frame(const Step& step, const std::string& title, int current_step, int total_steps) {
    clear();
    mvprintw(0, 0, "%s", title.c_str());
    mvprintw(1, 0, "Step: %d / %d ||| Compare: %d  Swap: %d",
             current_step + 1, total_steps, step.compare_count, step.swap_count);

    int max_value = *std::max_element(step.array.begin(), step.array.end());

    int screen_height, screen_width;
    getmaxyx(stdscr, screen_height, screen_width);

    int bar_height = screen_height - 6;

    for (int i = 0; i < (int)step.array.size(); i++) {
        int height = (step.array[i] * bar_height) / max_value;

        int color;
        if (i == step.swap_left || i == step.swap_right)
            color = COLOR_SWAP;
        else if (i == step.compare_left || i == step.compare_right)
            color = COLOR_COMPARE;
        else if (step.sorted[i])
            color = COLOR_SORTED;
        else
            color = COLOR_DEFAULT;

        attron(COLOR_PAIR(color));
        for (int row = 0; row < height; row++) {
            mvprintw(screen_height - 3 - row, i * 3, " █ ");
        }
        attroff(COLOR_PAIR(color));
        mvprintw(screen_height - 2, i * 3, "%3d", step.array[i]);
    }

    mvprintw(screen_height - 1, 0, "[SPACE] Pause  [<-][->] Step  [+][-] Speed  [Q] Quit");
    refresh();
}

void Visualizer::play(const std::vector<Step>& steps, const std::string& title) {
    initscr();
    noecho();
    cbreak();
    keypad(stdscr, TRUE);
    start_color();

    init_pair(COLOR_DEFAULT, COLOR_WHITE, COLOR_BLACK);
    init_pair(COLOR_COMPARE, COLOR_RED,   COLOR_BLACK);
    init_pair(COLOR_SWAP,    COLOR_YELLOW, COLOR_BLACK);
    init_pair(COLOR_SORTED,  COLOR_GREEN,  COLOR_BLACK);

    int current_step = 0;
    int total_steps = steps.size();
    bool is_paused = false;
    int delay_ms = 100;

    while (true) {
        draw_frame(steps[current_step], title, current_step, total_steps);

        timeout(is_paused ? -1 : delay_ms);
        int key = getch();

        if      (key == 'q' || key == 'Q') break;
        else if (key == ' ')               is_paused = !is_paused;
        else if (key == KEY_RIGHT)         current_step = std::min(current_step + 1, total_steps - 1);
        else if (key == KEY_LEFT)          current_step = std::max(current_step - 1, 0);
        else if (key == '+')               delay_ms = std::max(delay_ms - 20, 20);
        else if (key == '-')               delay_ms = std::min(delay_ms + 20, 500);
        else if (!is_paused)               current_step++;

        if (current_step >= total_steps) {
            current_step = total_steps - 1;
            is_paused = true;
        }
    }
    endwin();
}
