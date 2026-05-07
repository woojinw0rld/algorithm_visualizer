CXX      = g++
CXXFLAGS = -Wall -std=c++17 -I/ucrt64/include/ncurses
LIBS     = -lncursesw
TARGET   = sort_vis
SRCS     = src/main.cpp \
           src/visualizer.cpp \
           src/SortApp.cpp \
           src/BubbleSorter.cpp \
           src/SelectionSorter.cpp \
           src/InsertionSorter.cpp \
           src/QuickSorter.cpp \
           src/MergeSorter.cpp

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) $(SRCS) $(LIBS) -o $(TARGET)

clean:
	rm -f $(TARGET)
