## EP-353 Problem Set 7
### Project Name
Problem Set 7

### Submitted by
Zanne Hanna

### For Course
EP-353

### Due Date
9:00:00 AM on 3/11/2020

### Submission Date
10:30:00 PM on 3/07/2020

### Files Included
- README.md
- ProblemSet7.1.c
- ProblemSet7.2.c

### Purpose

The purpose of this problem set was to familiarize myself with malloc and realloc, and to learn to use secondary datatypes including typedef and struct. The purpose of this problem set was also to recap pointer variables. 

### Description

For Problem Set 7.1, I first created a variable for the **input** from scanf and a variable to count the number of integers called **counter** and set it to zero. Then, I created an array using malloc starting at 1 to store the integers. Then, I created a while loop with scanf that is stored in **array**, and I am using **counter** and realloc to change the size of the array each time a new integer is stored. Then, I created a for loop to print out the integers in **array** and freed **array**. 

For problem Set 7.2, I first created struct **Note** to hold three unsigned char variables, and I used typedef to rename it to Note. Then, in the main function I declared **note** as a pointer variable using malloc to store memory address. Outside the main function, I created printNote function which takes in the pointer variable and prints out the variable of each element in struct using the **->** operator. Then, in the main function, I used scanf and unsigned char specifier **%hhu** and the reference operator to assign each value to their respective element. Then, I called printNote function and freed **note**. 

### Build and Run Commands
To build Problem Set 7.1, use:

	clang ProblemSet7.1.c -o ProblemSet7.1

To run, use: 

	./ProblemSet7.1

To build Problem Set 7.2, use:

	clang ProblemSet7.2.c -o ProblemSet7.2

To run, use: 

	./ProblemSet7.2

### Acknowledgement 

***Zac Towbes*** helped me to understand the order of operations in my while loop. 

I used google to find the unsigned char specifier. 

I used notes, the slideshow, and C examples from EP-353 folder to understand struct, struct pointer, malloc, realloc, and typedef. 