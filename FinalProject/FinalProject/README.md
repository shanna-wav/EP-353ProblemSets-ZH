## EP-353 Final Project
### Project Name

Auditory Analysis by Critical Bandwidth

### Files Included
- README.md
- DESIGN.md
- main.c
- sine.wav
- eBass.wav
- 00-calung1.wav
- results.txt
- Presentation.pdf

### Header Files Required
- stdio.h
- stdlib.h
- memory.h
- math.h
- string.h
- sndfile.h

### Run Commands

To build, use:

	clang main.c -o main -lsndfile

To run, use: 

	./main

### Acknowledgement 

https://www.youtube.com/watch?v=mkGsMWi_j4Q (video explaining DFT)
https://community.sw.siemens.com/s/article/critical-bands-in-human-hearing (reference for CB barks)
https://www.sanfoundry.com/c-program-compute-discrete-fourier-transform-using-naive-approach/ (DFT implementation reference)
https://en.wikipedia.org/wiki/Discrete_Fourier_transform (DFT definition)
https://dsp.stackexchange.com/questions/26927/what-is-a-frequency-bin (bin definition)
https://github.com/misc0110/libattopng (for creating PNG)
https://gist.github.com/phoemur/151ca1999a76478ed6d74cbbb5d5e1c9 (FFT)
https://en.wikipedia.org/wiki/Cooley%E2%80%93Tukey_FFT_algorithm (FFT)

