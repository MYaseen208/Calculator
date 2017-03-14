CXX = g++ -std=c++11

%.o: %.cpp %.h

all : main.x main_arg.x

main.x : error.o tokenizer.o parser.o main.o
	$(CXX) $^ -o $@

main_arg.x : error.o tokenizer.o parser.o main_arg.o
	$(CXX) $^ -o $@

clean : 
	rm -f *.o *.x

