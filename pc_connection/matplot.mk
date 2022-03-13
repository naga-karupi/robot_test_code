TARGET = matplot
CC     = g++
CFLAGS = -O2 -std=c++2a -Wall
SRCS   = matplot.cpp
OBJS   = $(SRCS:%.cpp=%.o)
INC    = -I/usr/include/python3.8 -I ~/project/includes/
LIB    = -lpython3.8
.PHONY: all clean

all:$(TARGET)

$(TARGET):$(OBJS)
	$(CC) $^ -o $@ $(LIB) $(CFLAGS) $(INC)

.cpp.o:
	$(CC) -c $^ $(LIB) $(INC) $(CFLAGS)

clean:
	rm -f matplot *.o
