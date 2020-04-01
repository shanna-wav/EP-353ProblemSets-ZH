## EP-353 Problem Set 9
### Project Name
Problem Set 9

### Submitted by
Zanne Hanna

### For Course
EP-353

### Due Date
9:00:00 AM on 4/01/2020

### Submission Date
10:30:00 PM on 3/31/2020

### Files Included
- README.md
- ProblemSet9.1.c
- ProblemSet9.2.c
- sine.wav
- sineInverted.wav
- MyTremolo.wav

### Purpose

The purpose of this problem set was to familiarize myself with creating sound files and manipulating wave shapes using trigonometric equations and techniques involving phase, such as inverting.

### Description

For Problem Set 9.1, I expanded on `ReadWriteAudioFile.c` by creating a function called **invert** that takes in pointer values of **buffer** array and **numsamples** to multiply each sample by -1, thus inverting it. Next, I included this function in the while loop that reads through **inFile** and copies into **outFile** by having the invert function read the **buffer** variable and compare the iterations to **readcount**. This created the file sineInverted.wav. 

For problem Set 9.2, I expanded on `1.SineWave.c` by changing the kFileName constant to MyTremolo.wav. Then, I created two new double variables for the amplitude (0.5) and frequency (250) of the LFO. Then, in the for loop, I created an equation for the lfo and assigned it to the variable **LFO**. The phase of this equation is shifted by 90 degrees or pi/2 radians and becomes unipolar by the addition of 0.5 at the end of the equation. Then, I assigned the multiplication of the sine wave and LFO equations to **tremolo**. 

### Build and Run Commands
To build Problem Set 9.1, use:

	clang ProblemSet9.1.c -o ProblemSet9.1 -lsndfile

To run, use: 

	./ProblemSet9.1

To build Problem Set 9.2, use:

	clang ProblemSet9.2.c -o ProblemSet9.2 -lsndfile

To run, use: 

	./ProblemSet9.2

### Acknowledgement 

***Zac Towbes*** helped me understand **readcount** and **buffer** in ProblemSet9.1.c.

***Zac Towbes*** helped me to understand calculating the phase shift of my LFO using Desmos in ProblemSet9.2.c. 

***Zac Towbes*** made me make my brackets look pretty. 

