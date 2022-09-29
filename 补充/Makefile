SOURCE = $(wildcard *.cpp)
TARGETS = $(patsubst %.cpp, %, $(SOURCE))

CC = g++-11.2
CFLAGS = -Wall -g -std=c++20

all:$(TARGETS)

$(TARGETS):%:%.cpp
		$(CC) $< $(CFLAGS) -o $@

.PHONY:clean all wclean
clean:
	rm $(TARGETS)
wclean:
	rm *.exe
