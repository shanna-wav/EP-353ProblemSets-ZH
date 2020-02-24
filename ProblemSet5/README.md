## EP-353 Problem Set 5
### Project Name
Problem Set 5

### Submitted by
Zanne Hanna

### For Course
EP-353

### Due Date
9:00:00 AM on 2/26/2020

### Submission Date
3:00:00 PM on 2/24/2020

### Files Included
- README.md
- ProblemSet5.1.c
- ProblemSet5.2.c
- ProblemSet5.3.c

### Purpose

The purpose of this problem set was to familiarize myself with arrays, to relate my previous understanding of strings to this new perspective of strings as character arrays, and to practice using command-line arguments. 

### Description

For Problem Set 5.1, i first initialized the array **nums1** with a for loop to add each element value to the array and print it out. I then created another for loop to initialize **nums2** using two variables so that **i** counts the index value and **j** counts the element value going in the opposite direction. I then created a for loop that adds the two arrays together and prints the result. 

For problem Set 5.2, I first set up **scanf** to take a character value in the terminal. I then initialized the array **alphabets[53]** with two different for loops to include first uppercase then lowercase letters of the alphabet into the array. I created a third loop to print out the values in the array to make sure it worked. I then created the function characterExists using a for loop to check each value in the array, and then comparing each element value to the inputed letter from **scanf** to tell if the character value was a letter. 

For problem Set 5.3, I first set up the main function with **(int argc, char *argv[])**. I then created a variable called sum, and in a for loop, each argument is added to the value of sum after converting the string into an integer with atoi. I then checked that an argument was added by creating an if statement that checks if argc is 1, which means only the ./a.out argument was inputted. 

### Build and Run Commands
To build Problem Set 5.1, use:

	clang ProblemSet5.1.c -o ProblemSet5.1

To run, use: 

	./ProblemSet5.1

To build Problem Set 5.2, use:

	clang ProblemSet5.2.c -o ProblemSet5.2

To run, use: 

	./ProblemSet5.2

To build Problem Set 5.3, use:

	clang ProblemSet5.3.c -o ProblemSet5.3

To run, use: 

	./ProblemSet5.3 Arg1 Arg2 Arg3 etc...

### Acknowledgement 

I used previous slideshows to assist me with these problem sets. I used google to understand the atoi function. I double-checked all my problem sets with Zac Towbes who improved my syntax. 