CC = gcc
CFLAGS = -Wall

# Task 1
T1 = Task1
T1_INC = -I$(T1)/include
T1_OBJS = $(T1)/src/add.o $(T1)/src/sub.o $(T1)/src/mul.o \
           $(T1)/src/div.o $(T1)/src/fact.o $(T1)/src/sqrt.o
T1_LIB = $(T1)/libcalc.a
T1_BIN = $(T1)/calc

# Task 2 
T2 = Task2
T2_INC = -I$(T2)/include
T2_OBJ = $(T2)/convert.o
T2_LIB = $(T2)/libconvert.so
T2_BINS = $(T2)/low $(T2)/uper

.PHONY: all task1 task2 clean clean-all

all: task1 task2

# --------------
# Task 1
task1: $(T1_BIN)

$(T1_BIN): $(T1_LIB) $(T1)/main.c
	$(CC) $(CFLAGS) $(T1_INC) -o $@ $(T1)/main.c -L$(T1) -lcalc -lm

$(T1_LIB): $(T1_OBJS)
	ar rcs $@ $^

$(T1)/src/%.o: $(T1)/src/%.c $(T1)/include/calc.h
	$(CC) $(CFLAGS) $(T1_INC) -c -o $@ $<

# Task 2
task2: $(T2_BINS)

$(T2_LIB): $(T2_OBJ)
	$(CC) -shared -o $@ $^

$(T2_OBJ): $(T2)/convert.c $(T2)/include/convert.h
	$(CC) $(CFLAGS) $(T2_INC) -fPIC -c -o $@ $<

$(T2)/low: $(T2)/low.c $(T2_LIB)
	$(CC) $(CFLAGS) $(T2_INC) -o $@ $(T2)/low.c -L$(T2) -lconvert

$(T2)/uper: $(T2)/uper.c $(T2_LIB)
	$(CC) $(CFLAGS) $(T2_INC) -o $@ $(T2)/uper.c -L$(T2) -lconvert

# Cleaning
clean:
	rm -f $(T1_OBJS) $(T1_LIB) $(T1_BIN) $(T2_OBJ) $(T2_LIB) $(T2_BINS)

clean-all: clean # recursively
	find . -type f \( -name '*.o' -o -name '*.a' -o -name '*.so' \) -delete 
