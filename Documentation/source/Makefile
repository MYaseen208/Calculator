CXX = g++ -std=c++11

%.o: %.cpp %.h

main.x : tokenizer.o parser.o main.o
	$(CXX) $^ -o $@

clean : 
	rm -f *.o main.x

