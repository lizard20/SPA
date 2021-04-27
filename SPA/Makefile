
CC := gcc
CFLAGS := -Wall -Wextra -std=c11 -pedantic -fmax-errors=10
LIBS := -lm

SRCS := $(wildcard *.c)
OBJS := $(patsubst %.c, %.o, $(SRCS))
HDRS := $(wildcard *.h)
BIN := pointing

all: $(BIN)

$(BIN): $(OBJS)
	@echo "Compiling ..." 
	$(CC) $(CFLAGS) $(OBJS) -o $@ $(LIBS)

%.o: %.c
	@echo "Compiling ..." 
	$(CC) $(CFLAGS) -c $< -o $@ $(LIBS)

run: ${BIN}
	./${BIN}

clean:
	@echo "Cleaning ..." 
	$(RM) -r ${BIN} ${OBJS}


:PHONY: all run



