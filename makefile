EXE_FILE := snake.exe
SRC_DIR := ./src
OBJ_DIR := ./obj
SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp) # contain te name of each cpp file in SRC_DIR
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES)) # replace the name of the .cpp file with a .o for all SRC_FILE
LDFLAGS := -lncurses 
CPPFLAGS := -Werror -Wall 
CXXFLAGS := -I ./include/


all: $(EXE_FILE)

run: $(EXE_FILE)
	./$(EXE_FILE)

# the .exe depend on all obj (*.o) file
$(EXE_FILE): $(OBJ_FILES)
	g++ $(LDFLAGS) -o $@ $^ 

# rule for all the obj (*.o) file
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp 
	g++ $(CPPFLAGS) $(CXXFLAGS) -c -o $@ $< 

clean: 
	rm ./*/*.o *.exe