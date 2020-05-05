## Auditory Analysis by Critical Bandwidth

 This program creates an FFT from an audio file, and compares the frequency bins to critical bandwidths to determine the relative energy between the bandwidths.

### Files Included
- PreProposal folder
- Proposal folder
- Status report folder
- README.md
- DESIGN.md
- main.c
- Sine250.wav
- Sine500.wav
- Sine1000.wav
- Sine2000.wav
- FinalResults.txt
- Presentation.pdf

### Header Files Required
- stdio.h
- stdlib.h
- memory.h
- math.h
- string.h
- sndfile.h

### Purpose

The purpose of this program is to advance FFT data a step further into the realm of human perception. This program reads an audiofile, and turns the samples into frequency-domain information using a "divide and conquer" FFT algorithm that quickly computes the data and identifies the subsequent frequency bins. The bins are then organized into "barks" which are specific ranges of critical bandwidths. These critical bands have been developed from the human hearing theory of tonotopicity, which describes how humans organize frequencies by their placement on the basilar membrane inside of the cochlea. This is where music is turned from a mechanical vibration into an electromagnetic signal for the auditory cortex to understand and respond. Therefore, this program allows the user to read the FFT data from the perspective of critical bands, providing insight on which barks are most impacted by the audio. 

### Use Cases

Developing understand of how critical bandwidths intercept information about pitch perception is impactful for multiple musical fields. For example pitch perception can differ between instruments with varying timbres, and critical bands can offer information that can be considered for recording and mixing software tools for audio engineers and music producers. Furthermore, this kind of auditory analysis can provide insight on patterns of pitch perception in speech, which is useful for speech therapy and hearing loss devices.

### Installation

1.Download and install homebrew by going to [Brew.sh](brew.sh) or by copying the following line in your CLI:

/usr/bin/ruby -e "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/
install/master/install)"

2.Once installed, execute this command in the CLI:
brew install libsndfile

3.Once you have installed the sound file library above, clone this repository, and open in your GitHub desktop folder. 

4.Open the main.c file. 

5.Choose which sine wave you would like to test by changing FILENAME to any one of the following.

- "Sine250.wav"
- "Sine500.wav"
- "Sine1000.wav"
- "Sine2000.wav"

6.To use your own audiofile, add the file to the same directory as the main.c file. 

7.In the CLI, to build use:

	clang main.c -o main -lsndfile

8.To run, use: 

	./main
	
9.The CLI will inform you when the program is completed.

10.To open the existing directory and open FinalResults.txt, use the command:

open .

11.Open FinalResults.txt to read audiofile information, FFT values, and FFT bin placement within critical bandwidth "barks." 
	
### Bugs and Limitations

- Continous waveforms work more effectively than transient waveforms. 
- Nan and inf issues have not been completely solved yet. 
- This does not officially support Windows.

### Acknowledgements

- [Video Explaining DFT](https://www.youtube.com/watch?v=mkGsMWi_j4Q)
- [Reference for critical bandwidth barks](https://community.sw.siemens.com/s/article/critical-bands-in-human-hearing)
- [Reference for DFT implementation](https://www.sanfoundry.com/c-program-compute-discrete-fourier-transform-using-naive-approach/)
- [DFT Definition](https://en.wikipedia.org/wiki/Discrete_Fourier_transform)
- [Frequency Bin Definition](https://dsp.stackexchange.com/questions/26927/what-is-a-frequency-bin)
- [Reference for FFT implementation](https://gist.github.com/phoemur/151ca1999a76478ed6d74cbbb5d5e1c9)
- [FFT Cooley Turkey Definition](https://en.wikipedia.org/wiki/Cooley%E2%80%93Tukey_FFT_algorithm)
- Zachary Lewis-Towbes was my tutor during this project. He helped me a lot.
- Notes and references to how critical bandwidths work are from my notes in LMSC-307 Introduction to Psychoacoustics with Susan Rogers

