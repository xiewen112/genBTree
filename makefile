main: main.o
	g++ -o main main.o
main.o: main.cpp genBST.h
	g++ -c main.cpp

clean:
	rm -rf *.o main