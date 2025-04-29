# noapatito123@gmail.com
# Folder paths
SRC_DIR = src
INC_DIR = include
TEST_DIR = tests

# Source files
SRC = $(SRC_DIR)/main.cpp \
      $(SRC_DIR)/graph.cpp \
      $(SRC_DIR)/algorithms.cpp \
      $(SRC_DIR)/queue.cpp \
      $(SRC_DIR)/min_heap.cpp \
      $(SRC_DIR)/union_find.cpp

# Header files
HDR = $(INC_DIR)/graph.hpp \
      $(INC_DIR)/algorithms.hpp \
      $(INC_DIR)/queue.hpp \
      $(INC_DIR)/min_heap.hpp \
      $(INC_DIR)/union_find.hpp

# Test source files
TEST_SRC = $(TEST_DIR)/test_graph.cpp \
           $(TEST_DIR)/test_algorithms.cpp \
           $(TEST_DIR)/test_queue.cpp \
           $(TEST_DIR)/test_min_heap.cpp \
           $(TEST_DIR)/test_union_find.cpp

# Test executables
TEST_EXE = $(TEST_SRC:.cpp=.out)

# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -I$(INC_DIR)

# Main executable name
EXE = Main

# Valgrind command
VALGRIND = valgrind --leak-check=full --track-origins=yes

# Default target: compile and run Main
.PHONY: all
all: Main

# Compile and run the main program always
.PHONY: Main
Main:
	$(CXX) $(CXXFLAGS) -o $(EXE) $(SRC)
	@echo "Running Main..."
	./$(EXE)

# Compile each test source into an executable
%.out: %.cpp $(SRC) $(HDR)
	$(CXX) $(CXXFLAGS) -o $@ $< $(filter-out $(SRC_DIR)/main.cpp, $(SRC))

# Run all test executables
test: $(TEST_EXE)
	@echo "Running all test files..."
	@for test in $(TEST_EXE); do ./$$test; done

# Run valgrind on all test executables
valgrind-tests: $(TEST_EXE)
	@for test in $(TEST_EXE); do echo "==> $$test"; $(VALGRIND) ./$$test; done

# Run valgrind on Main
valgrind: $(EXE)
	$(VALGRIND) ./$(EXE)

# Clean build artifacts
clean:
	rm -f $(EXE) $(TEST_EXE) *.o
