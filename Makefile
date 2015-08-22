HDR_DIR = header
HEADER = $(addprefix -I,$(HDR_DIR))
CCOPTION = Wall std=gnu++11 D__USE_MINGW_ANSI_STDIO=1
FLAGS = $(addprefix -,$(CCOPTION))
CC = g++
OBJ_DIR = obj
OBJ = main.o 
BUILD_DIR = build
SRC_DIR = S:\Test\Clipper\src

$(BUILD_DIR)\Clipper.exe: $(addprefix $(OBJ_DIR)\,$(OBJ)) 
	 $(CC) $(FLAGS) $(addprefix $(OBJ_DIR)\,$(OBJ)) -o $(BUILD_DIR)\Clipper.exe 

$(OBJ_DIR)\main.o: $(SRC_DIR)\main.cpp 
	 $(CC) $(FLAGS) -c $(SRC_DIR)\main.cpp -o $(OBJ_DIR)\main.o $(HEADER)


clean: 
	del /Q $(OBJ_DIR)\*.o
	del /Q $(BUILD_DIR)\*.exe
