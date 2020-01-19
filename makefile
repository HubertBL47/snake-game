appName = snake
lib = -I ./include/ 
CPPFLAG = -Werror -Wall

all: compile
	

run: compile
	./$(appName).out

# compiling src code -I is to include a lib
compile:
	g++ ./src/*.cpp $(lib) $(CPPFLAG) -o $(appName).out

clean:
	rm *.out