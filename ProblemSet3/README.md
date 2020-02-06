## EP-353 Problem Set 3
### Project Name
Problem Set 3

### Submitted by
Zanne Hanna

### For Course
EP-353

### Due Date
9:00:00 AM on 2/12/2020

### Submission Date
12:00:00 PM on 2/06/2020

### Files Included
- README.md
- ProblemSet3.1.c
- ProblemSet3.2.c
- ProblemSet3.3.c

### Purpose

The purpose of this problem set was to familiarize myself with the use of operators in creating equations, conditional statements such as the switch statement, and looping with the for-loop statement as it relates to numerical configuration. 

### Description

For Problem Set 3.1, set the midiNote variable to 60 using a character data type, which I reviewed from the reading about the ASCII table in order to understand that a character variable in C can be an integer but it has a limited range of possible integers based on the ASCII table. Once I understood that, I created a float variable named frequency and set it equal to the equation that I read about in *The Audio Programming Book.* The way I understand the **pow** function is that the first value is x, the second value is y, and they are calculated as x to the value of y. I used A4 as the MIDI note and frequency reference: 69 and 440Hz. The midiNote is subtracted by the A4 note reference and divided by 12 semitones. It is then raised to the power of two to get it into the correct octave and multiplied by 440 to match the reference. This is how I understood it, but if I am misunderstanding it please tell me. 

For problem Set 3.2, I remembered from Max class that the pitch class from C to B is 0, 2, 4, 5, 7, 9, 11. So I set each case in the switch statement to a note value, and when the variable **pitchclass** matches a case, it will print the name of the note and its pitch class. 

For problem Set 3.3, I first declared the int variable **count** and set it to 11. I then created a simple for loop that starts int **i** at 1, and if it is less than **count**, then it will print the value and increment it up by two. 

### Build and Run Commands
To build Problem Set 3.1, use:

	clang ProblemSet3.1.c -o ProblemSet3.1

To run, use: 

	./ProblemSet3.1

To build Problem Set 3.2, use:

	clang ProblemSet3.2.c -o ProblemSet3.2

To run, use: 

	./ProblemSet3.2

To build Problem Set 3.3, use:

	clang ProblemSet3.3.c -o ProblemSet3.3

To run, use: 

	./ProblemSet3.3

### Acknolwedgement 

I used *The Audio Programming Book* to find the equation in Problem Set 3.1, and ***Zac Towbes*** helped me to understand the equation.

I used the Week 3 powerpoint and C examples to correctly format the switch statement in Problem Set 3.2, and the for loop in Problem Set 3.3. 