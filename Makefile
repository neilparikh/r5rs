CCFLAGS=-std=c++11 -Weverything -Wno-c++98-compat -Wno-missing-prototypes


all:
	clang++ $(CCFLAGS) main.cpp tokenizer.cpp -o main
