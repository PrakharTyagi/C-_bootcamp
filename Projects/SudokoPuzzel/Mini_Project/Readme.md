Solving the sudoku
==================================

### How to run the code
#### Compile 
1. Navigate to the project root directory where the `Makefile` is located.
2. Build the program by running the command:
	```bash
	$ make
	```
3. An executable named `sudoku_main` will appear in the project root directory. 

#### Run
```bash
$ ./sudoku_main <PATH_TO_INPUT_FILE> <MODE> 

run ./sudoku_main inputfile location/filename.txt mode
mode 0: seq back tracking
mode 1: seq brute force

example :./sudoku_main Test/Easy.txt 0

