
CPP := g++
CFLAGS := -Wall -Wextra -std=c++11 -pedantic -fmax-errors=10
LIBS := -lm

SRCS := $(wildcard *.cpp)
OBJS := $(patsubst %.cpp, %.o, $(SRCS))
HDRS := $(wildcard *.h)
BIN := pointing

all: $(BIN)

$(BIN): $(OBJS)
	@echo "Compiling ..." 
	$(CPP) $(CFLAGS) $(OBJS) -o $@ $(LIBS)

%.o: %.cpp
	@echo "Compiling ..." 
	$(CPP) $(CFLAGS) -c $< -o $@ $(LIBS)

run: ${BIN}
	./${BIN}

clean:
	@echo "Cleaning ..." 
	$(RM) -r ${BIN} ${OBJS}


:PHONY: all run



