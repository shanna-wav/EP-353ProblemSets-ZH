# Zanne's Proposal

### 1. What will (likely) be the title of your project?

Auditory Analysis by Critical Bandwidth

### 2. In just a sentence or two, summarize your project. (E.g., "A real-time FM Synthesizer with MIDI control.")

My project is a CLI application that takes in audio files and analyzes the frequencies, critical bandwidths, and first-order beating using my own Fast Fourier Transform (FFT) implementation.

### 3. In a paragraph or more, detail your project. What will your software do? What features will it have? How will it be executed?

In human hearing, frequency information is sorted into critical bandwidths that help us determine what the frequency is and whether two frequencies are dissonant or consonant. In the case of first-order beating, two frequencies in the same critical bandwidth experience this beating effect through phase differences and are perceived as "sensory dissonant," meaning this dissonance is a mechanical phenomenon and not a neural phenomenon. 

In my project, I want to analyze audio files of simple or complex waveforms and identify the frequencies, critical bandwidths, and first-order beatings in these audio files. In order to achieve this, I will need to implement my own FFT function that converts audio data into the frequency domain. I will also need to build a function that weighs the critical bandwidths to determine which critical bandwidths are more present in a complex waveform. I will need to use libsndfile and libsamplerate in order to read the audiofile and convert the audio data. 

I am interested in these concepts because I have learned a lot about psychoacoustics from Berklee faculty member Dr. Susan Rogers, and she has inspired me to pursue an AuD/PhD after graduating from Berklee. This is one topic that I learned in her class, and I want to apply this knowledge to my new C skills. 

### 4. In the world of software, most everything takes longer to implement than you expect. And so it's not uncommon to accomplish less in a fixed amount of time than you hope. In a sentence (or list of features), define a GOOD outcome for your final project. I.e., what WILL you accomplish no matter what?

I will have at least my own Discrete Fourier Transform (DFT) implementation that can analyze the frequency of a sine wave and which critical bandwidth it is in.  

### 6. In a sentence (or list of features), define a BETTER outcome for your final project. I.e., what do you THINK you can accomplish before the final project's deadline?

I think that I can implement my own FFT that will analyze the frequencies of two different sine waves, identify their critical bandwidths, and model the first-order beating between the two frequencies. 

### 7. In a sentence (or list of features), define a BEST outcome for your final project. I.e., what do you HOPE to accomplish before the final project's deadline?

I hope that I can implement my own FFT that will analyze the frequencies, critical bandwidths, and first-order beating of complex waves.

### 8. In a paragraph or more, outline your next steps. What new skills will you need to acquire? What topics will you need to research?

I will need to research the FFT algorithm and possibly search for existing implementations to reference. I can also look at the FFTW library website as a reference as well. I will need to research ranges and weights of critical bandwidths in human hearing and review how first-order beating occurs. My first step in building my program will be to create a function for a DFT. 
