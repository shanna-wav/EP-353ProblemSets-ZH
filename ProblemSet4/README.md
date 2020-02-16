## EP-353 Problem Set 4
### Project Name
Problem Set 4

### Submitted by
Zanne Hanna

### For Course
EP-353

### Due Date
9:00:00 AM on 2/19/2020

### Submission Date
12:00:00 PM on 2/16/2020

### Files Included
- README.md
- ProblemSet4.1.c
- ProblemSet4.2.c
- ProblemSet4.3.c
- LoremIpsum.txt

### Purpose

The purpose of this problem set was to practice using I/O formatting with text files, to familiarize myself with creating and using functions, and to work on using global and local variables to understand variable scope. 

### Description

For Problem Set 4.1, I first declared the file variable, and opened LoremIpsum.txt in read mode using **fopen**. I created two integer variables **count** and **line** to use in a while loop. In the while loop, for each space that is read by **fgetc**, the program will print the line number and then increment the value of **line** until all the lines are counted. 

For problem Set 4.2, I used an if-else statement in the min3 function with comparison opperators to determine which variable is the smallest. If more than one value is the smallest, it will indicate that there is no "smallest" value but it does not say which two values are tied. In the main function, i included scanf so that all three variables can be typed at once, and then I called the min3 function. 

For problem Set 4.3, I created a function which includes float variable **MIDI** which is set to the equation from the frequency to MIDI conversion website. It then prints the result of the logarithmic equation. Since I declared the float variable **freq** in the freq2midi function, I was able to declare another float variable named **freq** in the main function. This helped me understand where the float value was being inputted into the freq2midi function; however, it is possible that naming variables the same thing even if they are local within their functions may not be a good practice.  

### Build and Run Commands
To build Problem Set 4.1, use:

	clang ProblemSet4.1.c -o ProblemSet4.1

To run, use: 

	./ProblemSet4.1

To build Problem Set 4.2, use:

	clang ProblemSet4.2.c -o ProblemSet4.2

To run, use: 

	./ProblemSet4.2

To build Problem Set 4.3, use:

	clang ProblemSet4.3.c -o ProblemSet4.3

To run, use: 

	./ProblemSet4.3

### Acknolwedgement 

I used ***Zac Towbes*** to help me with correctly indenting and using **scanf()**.

I used google to help with Problem 4.1 so that I could use **fgetc()** correctly. 

I used the Week 4 powerpoint to review I/O and variable scope. 