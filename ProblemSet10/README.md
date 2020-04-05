## EP-353 Problem Set 10
### Project Name
Problem Set 10

### Submitted by
Zanne Hanna

### For Course
EP-353

### Due Date
9:00:00 AM on 4/08/2020

### Submission Date
10:30:00 PM on 4/04/2020

### Files Included
- README.md
- ProblemSet10.1.c
- ProblemSet10.2.c
- ProblemSet10.3.c
- TriangleWave.wav
- eBass.wav
- BitReduction.wav
- BassBooster.wav

### Purpose

The purpose of this problem set was to familiarize myself with building complex wave forms using additive synthesis techniques, and to understand and implement DSP. 

### Description

For Problem Set 10.1, I expanded on *2.SawtoothWave.c* by adjusting the amplitude in the algorith to be divided by i squared instead of just divided by i, because the source explains that 1/x**2 is the way that a triangle wave is formed additively. Then, I inluded an if statement that makes every other odd harmonic negative, as explained in the wikipedia page for the triangle wave. 

For Problem Set 10.2, I expanded on *0.Template.c* by including the bit reduction function above the main function, and implementing it in the process function with a for loop. I also included a float variable **scale** which I understand as "z-mapping" from bit to integer.

For Problem Set 10.3, I expanded on *0.Template.c* by including the bass booster function above the main function. Then, I adjusted it by creating the saturate function and giving values to **selectivity**, **ratio** and **gain2** variables according to the parameters described by the original source. Then, I implemented the function in the process function.  

### Build and Run Commands

To build Problem Set 10.1, use:

	clang ProblemSet10.1.c -o ProblemSet10.1 -lsndfile

To run, use: 

	./ProblemSet10.1

To build Problem Set 10.2, use:

	clang ProblemSet10.2.c -o ProblemSet10.2 -lsndfile

To run, use: 

	./ProblemSet10.2

To build Problem Set 10.3, use:

	clang ProblemSet10.3.c -o ProblemSet10.3 -lsndfile

To run, use: 

	./ProblemSet10.3

### Acknowledgement 

Zac shared [this](https://en.wikibooks.org/wiki/Sound_Synthesis_Theory/Additive_Synthesis) resource with me so that I could understand using 1/x**2. I used the [Triangle wave](https://en.wikipedia.org/wiki/Triangle_wave) resource for ProblemSet10.1.c. Also, Zac helped me to understand the scaling feature in ProblemSet10.2.c.