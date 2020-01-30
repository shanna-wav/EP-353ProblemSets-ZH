## EP-353 Problem Set 2
### Project Name
Problem Set 2

### Submitted by
Zanne Hanna

### For Course
EP-353

### Due Date
9:00:00 AM on 2/05/2020

### Submission Date
11:00:00 AM on 1/30/2020

### Files Included
- README.md
- ProblemSet2.1.c
- ProblemSet2.2.c
- ProblemSet2.3.c

### Purpose

The purpose of this problem set was to familiarize myself with the printf function and initializing and printing variables in the printf syntax using placeholders. 

### Description

For Problem Set 2.1, I used the **printf** function with **\n** that creates a new line for each part of the phrase "Hello World!!". 

For problem Set 2.2, I  used the **int** data type and assigned the MIDI note value, velocity, and channel to their respective variables. I then used the **printf** function and included **\t** for tabs and **\n** for new line to achieve the correct indentation. I used the **%d** placeholder for integers. 

For problem Set 2.3, I  used the **float** datatype to assign frequency and decibel values to their respective variables. I used the **printf** function with **\n** to create new lines. I also used **%f** placeholders for float values. In order get the correct number of values after the decimal point for the frequency, I used **%0.3f** to ensure that there were three places after the decimal to represent the whole value. For the decibel value, I used **%0.1f** because I only needed one number after the decimal point to represent the entire value. I originally forgot to make these specifications and saw when running the program that there were many zeros after the numbers. I then implemented the decimals in the floating point placeholders. 

### Build and Run Commands
To build Problem Set 2.1, use:

	clang ProblemSet2.1.c -o ProblemSet2.1

To run, use: 

	./ProblemSet2.1

To build Problem Set 2.2, use:

	clang ProblemSet2.2.c -o ProblemSet2.2

To run, use: 

	./ProblemSet2.2

To build Problem Set 2.3, use:

	clang ProblemSet2.3.c -o ProblemSet2.3

To run, use: 

	./ProblemSet2.3

### Acknolwedgement 

I used the Week 2 powerpoint to guide myself on setting the decimel places for floating points and to check my printf syntax. 
