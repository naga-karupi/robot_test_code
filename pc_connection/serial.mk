TARGET = serial
CC     = g++
CFLAGS = -O2 -std=c++2a -Wall
SRCS   = serial.cpp
OBJS   = $(SRCS:%.cpp=%.o)
INC    =  -I ~/project/includes/
LIB    = -lserial
.PHONY: all clean

all:$(TARGET)

$(TARGET):$(OBJS)
	$(CC) -o $@ $^ $(LIB) $(CFLAGS) $(INC)

.cpp.o:
	$(CC) -c $^ $(LIB) $(INC) $(CFLAGS)

clean:
	rm -f serial *.o
