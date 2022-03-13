TARGET = main
CC     = g++
CFLAGS = -Wall -O2 -std=c++2a
SRCS   = main.cpp 
OBJS   = $(SRCS:%.cpp=%.o)
INC    = -I ~/project/includes/ \
		 -I/usr/include/python3.8 \
		 -I ~/project/cpp/src/libserial/src/libserial/
LIB    = -lpython3.8 -lserial
.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $@ $^ $(LIB) $(CFLAGS) $(INC)

.cpp.o:
	$(CC) -c $^ $(INC)  $(LIB) $(CFLAGS)

clean:
	rm -f *exe *.o