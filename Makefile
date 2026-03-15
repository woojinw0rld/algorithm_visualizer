CXX		=	g++
CSSFLAGS	=	-Wall -std=c++17
LIBS		=	-lncurses
TARGET		=	sort_vis
SRCS		=	src/main.cpp \
			src/visualizer.cpp \
			src/bubble_sort.cpp \
			src/selection_sort.cpp \
			src/insertion_sort.cpp \
			src/quick_sort.cpp \
			src/quick_sort.cpp \
			src/merge_sort.cpp
$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) $(SRCS) $(LIBS) -o $(TARGET)

clean:
	rm -f $(TARGET)
