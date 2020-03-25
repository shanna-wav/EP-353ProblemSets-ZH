## EP-353 Problem Set 8
### Project Name
Problem Set 8

### Submitted by
Zanne Hanna

### For Course
EP-353

### Due Date
9:00:00 AM on 3/25/2020

### Submission Date
7:00:00 AM on 3/25/2020

### Files Included
- README.md
- ProblemSet8.1.c
- ProblemSet8.2.c
- MIDINotes.bin
- 00-calung1.wav
- 05-gangsahi.wav
- 10-gangsamid1.wav

### Purpose

The purpose of this problem set was to familiarize myself with navigating files in binary format and using commands with libsndfile.

### Description

For Problem Set 8.1, I used a while loop to check for the Note structures in the MIDINotes.bin file. I initialized an array with malloc to hold the structure values, and in my while loop, used realloc to include each new Note structure in the array. The **arraylength** integer is a count that adds each note to the array with each loop. The while loop exits when fread returns 0 to indicate the end of the file. 

For problem Set 8.2, I followed along with the **1.AudioFileInfo.c** and **ReadWriteAudioFile.c** files to set up the for loop with an array of strings called **array** that included the names of the three sound files. The for loop includes opening each file in the array, exit code if the file cannot be opened, print functions for each of the details documented in the example programs, and an if statement to close the files. I am rather surprised as to how easy it was, but I suppose the point of libsndfile is to make it easier?

### Build and Run Commands
To build Problem Set 8.1, use:

	clang ProblemSet8.1.c -o ProblemSet8.1

To run, use: 

	./ProblemSet8.1

To build Problem Set 8.2, use:

	clang ProblemSet8.2.c -o ProblemSet8.2 -lsndfile

To run, use: 

	./ProblemSet8.2

### Acknowledgement 

***Zac Towbes*** helped me to clean up the while loop in ProblemSet8.1.c. 
