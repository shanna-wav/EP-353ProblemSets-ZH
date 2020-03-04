## EP-353 Problem Set 6
### Project Name
Problem Set 6

### Submitted by
Zanne Hanna

### For Course
EP-353

### Due Date
9:00:00 AM on 3/04/2020

### Submission Date
2:00:00 PM on 3/03/2020

### Files Included
- README.md
- ProblemSet6.1.c
- ProblemSet6.2.c

### Purpose

The purpose of this problem set was to familiarize myself with pointers using previously learned concepts in C and applying them to pointer variables and arithmetic equations. 

### Description

For Problem Set 6.1, I first set up scanf to take in integer values for **na**, **nb**, and **nc** in the main function. Then, I built a swap function that takes in pointer inputs and swaps the values that the pointers are pointing to (or so I think). Nonetheless, they do swap. Then, I created the sorting function that uses if statements with the swap function to put the values from smallest to largest in the first to last address. Then, I called the function in the main function. 

For problem Set 6.2, I made two char variables, **c** and ***str**  and used scanf to input values in the variables. Then, I made the numChars function with a while loop that checks if each character in the string matches the inputted character, and then increments up the **count** variable and the *s* pointer variable. 

I was having a strange issue where once I typed in the string I wanted in the terminal, then the code would execute and count would always be zero, and the scanf for the character variable was skipped over. I really didn't understand why this was happening, and Zac helped me by finding out that I needed to put **%*c** after **%s** and **%c** in scanf so that it would ignore the "new line" command. I am not sure if I actually understand why that was happening.  

### Build and Run Commands
To build Problem Set 6.1, use:

	clang ProblemSet6.1.c -o ProblemSet6.1

To run, use: 

	./ProblemSet6.1

To build Problem Set 6.2, use:

	clang ProblemSet6.2.c -o ProblemSet6.2

To run, use: 

	./ProblemSet6.2

### Acknowledgement 

***Zac Towbes*** helped me build my sort function and helped me solve the weird issue happening with 6.2. 
I followed along with my notes and the Pointers slideshow as well.