// -----------------------------------------------------
// CSC371 Advanced Object-Oriented Programming (2024/25)
// 
// (c) Martin Porcheron
//     Thomas Reitmaier
//     thomas.reitmaier@swansea.ac.uk
// -----------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include "timestables.h"

/*
    Modify the main function in task2.c by removing the code that reads and validates the program argument.
    Instead, create an array for pointers on the stack. Your array must be large enough to gen‑
    erate the times tables 0, 1, 2, ..., 11, and 12 (i.e. it will generate 13 sets of times tables).
   
    5. Create a for loop that uses malloc inside it to allocate enough space for each times table
    in your main function in task2.c.
    Store the pointer from malloc in the array stored in stack memory at the correct index (i.e.
    at index 0 store the pointer to the location in heap memory allocated for the 0 times table, at
    index 1 store the pointer for the location in heap memory allocated for the 1 times table...).
   
    6. Modify the main function to call the printTables function.
   
    7. You may need to adjust how you free memory to be in an additional loop (i.e., to free each
    pointer!)
   
    8. From the command line compile your program to object files with the GCC compiler using꞉
    $ gcc ‑c task2.c ‑o task2.o
    $ gcc ‑c timestables.c ‑o timestables.o
   
    9. Link your two files꞉
    $ gcc timestables.o task2.o ‑o task2
*/



int main(int argc , char *argv[]) {
	//Create an array of stack pointers
	int* pointers[MAX_TABLE_SIZE];
	

	for (int i = 0; i<=MAX_TIMES_TABLE; i++){

		// allocate max timestable memory
		pointers[i] = (int *) malloc((MAX_TIMES_TABLE + 1) * sizeof(int));  
		
		if (pointers[i] == NULL) {
			printf("Memory allocation failed at index %d!\n", i);
			return 1;  // Exit on memory allocation failure
		}
		generateTable(i, pointers[i]);
	}

	//iterate over each index print then free it. 
	for (int i=0; i<=MAX_TIMES_TABLE; i++){
		printTables(pointers);
		free(pointers[i]);		
	}

	return 0;
}


