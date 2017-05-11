demo : hash.o main.o
	clang++ -o demo hash.o main.o

hash.o : hash.cpp hashing.h
	clang++ -c hash.cpp

main.o : main.cpp hashing.h
	clang++ -c main.cpp

.PHONY:
	clean
clean:
	rm -rf demo hash.o main.o
