## Task 1
Build static lib:
```bash
cd Task1/
```
```bash
gcc -c -Iinclude src/add.c src/sub.c src/mul.c src/div.c src/fact.c src/sqrt.c
```
```bash
ar rcs libcalc.a add.o sub.o mul.o div.o fact.o sqrt.o
```
```bash
gcc -Iinclude -o calc main.c -L. -lcalc -lm
```
### Run:
```bash
./calc
```

## Task 2
Build shared lib:
```bash
cd Task2/
```
```bash
gcc -fPIC -c convert.c -Iinclude
```
```bash
gcc -shared -o libconvert.so convert.o
```
```bash
gcc -o uper uper.c -Iinclude -L. -lconvert
```
```bash
gcc -o low  low.c  -Iinclude -L. -lconvert
```

### Run:

A: 
```bash
export LD_LIBRARY_PATH="$PWD:$LD_LIBRARY_PATH"` 
```
```bash
./low && ./uper
```

B: 
```bash
sudo cp libconvert.so /usr/local/lib/ && sudo ldconfig && export LD_LIBRARY_PATH=""
```
```bash
./low && ./uper 
```

## Task 3:
```bash
make          # build both Task1 and Task2
make task1    # only calculator
make task2    # only converter
make clean
make clean-all
```
For Task 2 before running choose either option A or B from above.



