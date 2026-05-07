#pragma once
#include <vector>
#include <string>
#include "sort_step.h"

class Visualizer {
public:
    void play(const std::vector<Step>& steps, const std::string& title);
private:
    void draw_frame(const Step& step, const std::string& title, int current_step, int total_steps);
};
