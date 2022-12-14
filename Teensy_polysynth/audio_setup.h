//---------------------------------------------------------------------------------------------//
//Audio Setup Configs and variable declarations
//---------------------------------------------------------------------------------------------//

//Custom Audio Objects
AudioEffectPhaser phaserL;
AudioEffectPhaser phaserR;
AudioEffectEnsemble ensembleL;
AudioEffectEnsemble ensembleR;

AudioConnection          patchCord426(mixerWaveshapeL, 0, phaserL, 0);
AudioConnection          patchCord427(mixerWaveshapeR, 0, phaserR, 0);
AudioConnection          patchCord428(phaserL, 0, mixerPhaserL, 1);
AudioConnection          patchCord429(phaserR, 0, mixerPhaserR, 1);
AudioConnection          patchCord430(mixerPhaserL, 0, ensembleL, 0);
AudioConnection          patchCord431(mixerPhaserR, 0, ensembleR, 0);
AudioConnection          patchCord432(ensembleL, 0, mixerChorusL, 1);
AudioConnection          patchCord433(ensembleR, 0, mixerChorusR, 1);
//AudioConnection          patchCord410(panLFOR, 0, phaserR, 1); //Connection to Leslie LFO
//AudioConnection          patchCord411(panLFOL, 0, phaserL, 1); //Connection to Leslie LFO

#define VOICES 8
#define VOICES_ARRAY 7 //Arrays start from 0, but array declarations start from 1 \shrugs
#define VOICES_SECONDARY 7
#define VOICES_ARRAY_SECONDARY 6
#define MIN_NOTE 23 //Lowest Midi note playable
#define MAX_NOTE 108 //Highest Midi note playable
#define LFO_SPEED_MAX 20 //LFO Max Freq 
#define DETUNE_MAX 0.05 //Max amount an oscillator can be detuned
#define MONO_BUFFER 8 //Size of Mono buffer
#define SECOND_BUFFER 8 //Size of secondary buffer
#define TREM_MAX_SPEED 100
#define DELAY_MAX_TIME 500 //Longest delay time possible. To calculate, multiply (AudioMemory() * 2.9ms)/Number of Delays in system. 
#define PAN_MAX_SPEED 8
#define PHASER_MAX_SPEED 8
#define PHASER_MAX_FBDB 0.8
#define EXP_MIN_VALUE 0.2 //Lowest value for Expression pedal
#define EXP_MIN_MULTIPLIER (1/(1-EXP_MIN_VALUE)) //Value used to to return value to 0-1 range after truncating the min value

//GLOBAL VARIABLES

int currentVoice = 0;
bool polyMode = true;
int midiChannelMain;
int midiChannelSecondary;
int numberOfVoices;
int secondaryVoice = 7;
bool secondaryEnabled;
bool secondaryControl;
bool secondaryBypassFx;
float secondaryVolume;

//---START AUDIO---//

//Oscillators
float oscAVol;
float oscBVol;
float pinkVol;
float mixerOscGain;

int oscAWaveform;
int oscBWaveform;
float oscVelocity;
float portamentoSpeed;

float oscAOctave;
float oscBOctave;
float oscLFOFreq;
float oscADetune;
float oscBDetune;

float oscPWM;
float oscAPulseWidth;
float oscBPulseWidth;


//Filter
float filterFreq;
float filterRes;
float filterOctave;

int filterKbdVelControl; //Used by mixers to determine what the note/velocity are controlling
float filterLFOFreq;
float filterAft;
float filterEnvFreq;
float filterKbd;
float filterVel;

float envelopeFilterDelay;
float envelopeFilterAttack;
float envelopeFilterDecay;
float envelopeFilterSustain;
float envelopeFilterRelease;


//LFO
int lfoWaveform;
float lfoSpeed;

// Secondary voice -----------------

//Oscillators - secondary
float secondOscAVol;
float secondOscBVol;
float secondPinkVol;

int secondOscAWaveform;
int secondOscBWaveform;
float secondOscVelocity;
float secondPortamentoSpeed;

float secondOscAOctave;
float secondOscBOctave;
float secondOscLFOFreq;
float secondOscADetune;
float secondOscBDetune;

float secondOscPWM;
float secondOscAPulseWidth;
float secondOscBPulseWidth;


//Filter - secondary
float secondFilterFreq;
float secondFilterRes;
float secondFilterOctave;

int secondFilterKbdVelControl;
float secondFilterLFOFreq;
float secondFilterAft;
float secondFilterEnvFreq;
float secondFilterKbd;
float secondFilterVel;

float secondEnvelopeFilterDelay;
float secondEnvelopeFilterAttack;
float secondEnvelopeFilterDecay;
float secondEnvelopeFilterSustain;
float secondEnvelopeFilterRelease;


//LFO - secondary
int secondLfoWaveform;
float secondLfoSpeed;

//Audio Envelope  - secondary
float secondEnvelopeVolAttack;
float secondEnvelopeVolDecay;
float secondEnvelopeVolSustain;
float secondEnvelopeVolRelease;

//END VOICES-------------------

//Audio envelope
float envelopeVolAttack;
float envelopeVolDecay;
float envelopeVolSustain;
float envelopeVolRelease;

//Wheels/Exp Pedal
int bendRange;
float modWheelPos;
int modWheelSetting;
int expPedalSetting;
int aftertouchSetting;

//Waveshape (Distortion)
//int distType;
//int waveshapeLength = 257;
//float ODShape[9] = {-1.0, -0.9, -0.7, -0.4, 0.0, 0.42, 0.75, 0.95, 1.0};
//float DSShape[9] = {-0.9, -1.0, -0.9, -0.5, 0.0, 0.53, 0.95, 1.0, 0.94};
//float FZShape[9] = {-1.0, -1.0, -1.0, -0.5, 0.0, 0.5, 1.0, 1.0, 1.0};
//float FZShape[256] = {0.0266731690, 0.0366527185, 0.0466627865, 0.0599993710, 0.0733359555, 0.0933255730, 0.1133457090, 0.1333353265, 0.1733450800, 0.2099977985, 0.2399974840, 0.2766807210, 0.3466596415, 0.4000059795, 0.4966580690, 0.6800132170, 0.7666552385, 0.8200015765, 0.8366646775, 0.8300116445, 0.8266546095, 0.8266546095, 0.8233280930, 0.8266546095, 0.8266546095, 0.8266546095, 0.8300116445, 0.8300116445, 0.8300116445, 0.8366646775, 0.8366646775, 0.8366646775, 0.8366646775, 0.8333381610, 0.8333381610, 0.8300116445, 0.8266546095, 0.8233280930, 0.8166750600, 0.8133180250, 0.8066649920, 0.8033384755, 0.8000119590, 0.7966549240, 0.7900018910, 0.7866753745, 0.7833183395, 0.7799918230, 0.7766653065, 0.7766653065, 0.7733387900, 0.7700122735, 0.7700122735, 0.7666552385, 0.7633287220, 0.7600022055, 0.7600022055, 0.7600022055, 0.7566756890, 0.7499921375, 0.7499921375, 0.7499921375, 0.7466656210, 0.7433391045, 0.7400125880, 0.7366555530, 0.7366555530, 0.7366555530, 0.7366555530, 0.7366555530, 0.7333290365, 0.7333290365, 0.7333290365, 0.7333290365, 0.7333290365, 0.7333290365, 0.7333290365, 0.7333290365, 0.7333290365, 0.7333290365, 0.7300025200, 0.7300025200, 0.7233189685, 0.7233189685, 0.7233189685, 0.7199924520, 0.7166659355, 0.7166659355, 0.7100129025, 0.7100129025, 0.7066558675, 0.7033293510, 0.7033293510, 0.6966763180, 0.6966763180, 0.6933192830, 0.6933192830, 0.6866662500, 0.6866662500, 0.6833397335, 0.6833397335, 0.6800132170, 0.6766561820, 0.6733296655, 0.6733296655, 0.6700031490, 0.6666766325, 0.6633195975, 0.6566665645, 0.6566665645, 0.6533400480, 0.6500135315, 0.6500135315, 0.6466564965, 0.6433299800, 0.6400034635, 0.6400034635, 0.6366769470, 0.6366769470, 0.6333199120, 0.6299933955, 0.6299933955, 0.6266668790, 0.6233403625, 0.6233403625, 0.6200138460, 0.6166568110, 0.6166568110, 0.6133302945, 0.6133302945, 0.6100037780, 0.6066772615, 0.6033202265, 0.5999937100, 0.5999937100, 0.5966671935, 0.5933406770, 0.5933406770, 0.5900141605, 0.5866571255, 0.5866571255, 0.5833306090, 0.5833306090, 0.5800040925, 0.5766775760, 0.5733205410, 0.5733205410, 0.5699940245, 0.5666675080, 0.5633409915, 0.5600144750, 0.5566574400, 0.5566574400, 0.5533309235, 0.5500044070, 0.5466778905, 0.5466778905, 0.5433208555, 0.5399943390, 0.5399943390, 0.5399943390, 0.5366678225, 0.5233312380, 0.5166782050, 0.5099946535, 0.5066681370, 0.5000151040, 0.4966580690, 0.4933315525, 0.4900050360, 0.4833214845, 0.4799949680, 0.4766684515, 0.4733419350, 0.4699849000, 0.4699849000, 0.4666583835, 0.4666583835, 0.4633318670, 0.4633318670, 0.4633318670, 0.4633318670, 0.4633318670, 0.4633318670, 0.4666583835, 0.4733419350, 0.4766684515, 0.4766684515, 0.4766684515, 0.4766684515, 0.4733419350, 0.4699849000, 0.4633318670, 0.4566788340, 0.4499952825, 0.4433422495, 0.4333321815, 0.4166690805, 0.3966794630, 0.3733328105, 0.3533431930, 0.3233435075, 0.2833337540, 0.1866816645, 0.1399883595, 0.0933255730, 0.0366527185, -0.0566728545, -0.0933255730, -0.1300088100, -0.2066712820, -0.4000059795, -0.5366678225, -0.7033293510, -0.8300116445, -0.8800009475, -0.9033476000, -0.9200107010, -0.9366738020, -0.9433268350, -0.9500103865, -0.9533369030, -0.9566634195, -0.9566634195, -0.9566634195, -0.9566634195, -0.9566634195, -0.9566634195, -0.9533369030, -0.9433268350, -0.9366738020, -0.9299902505, -0.9200107010, -0.9066741165, -0.8833274640, -0.8533277785, -0.8166750600, -0.7433391045, -0.6700031490, -0.6100037780, -0.5766775760, -0.5366678225, -0.5033416205, -0.4733419350, -0.4366586980, -0.4000059795, -0.3733328105, -0.3299965405, -0.2899867870, -0.2500075520, -0.2099977985, -0.1600084955, -0.1166722255, -0.0733359555, -0.0400097535, 0.0000000000};

//Wah
float wahQ;
float wahAttenuation;
float wahMaxFreq; 
float wahMinFreq; 

//Phaser
float phaserSpeed;
float phaserFeedback;
float phaserWet;

//Chorus
float chorusWet;

//tremolo
int tremoloWavetype;
float tremoloSpeed;
float tremoloDepth;

//Delay
float delayLevel;
float delayInputLevel;
float delayTime;
int delayRepeats;
float delayFalloffAmount;
bool delayPingPong;
float delayFeedback;

//Reverb
float reverbRoomsize;
float reverbDamping;
float reverbWet;

//Pan
float panSpeed;
float panDepth;

//Master Volume
float masterVolLeft;
float masterVolRight;
//---END AUDIO---//

//CONSTANTS
const float noteFreqs[128] = {8.176, 8.662, 9.177, 9.723, 10.301, 10.913, 11.562, 12.25, 12.978, 13.75, 14.568, 15.434, 16.352, 17.324, 18.354, 19.445, 20.602, 21.827, 23.125, 24.5, 25.957, 27.5, 29.135, 30.868, 32.703, 34.648, 36.708, 38.891, 41.203, 43.654, 46.249, 48.999, 51.913, 55, 58.27, 61.735, 65.406, 69.296, 73.416, 77.782, 82.407, 87.307, 92.499, 97.999, 103.826, 110, 116.541, 123.471, 130.813, 138.591, 146.832, 155.563, 164.814, 174.614, 184.997, 195.998, 207.652, 220, 233.082, 246.942, 261.626, 277.183, 293.665, 311.127, 329.628, 349.228, 369.994, 391.995, 415.305, 440, 466.164, 493.883, 523.251, 554.365, 587.33, 622.254, 659.255, 698.456, 739.989, 783.991, 830.609, 880, 932.328, 987.767, 1046.502, 1108.731, 1174.659, 1244.508, 1318.51, 1396.913, 1479.978, 1567.982, 1661.219, 1760, 1864.655, 1975.533, 2093.005, 2217.461, 2349.318, 2489.016, 2637.02, 2793.826, 2959.955, 3135.963, 3322.438, 3520, 3729.31, 3951.066, 4186.009, 4434.922, 4698.636, 4978.032, 5274.041, 5587.652, 5919.911, 6271.927, 6644.875, 7040, 7458.62, 7902.133, 8372.018, 8869.844, 9397.273, 9956.063, 10548.08, 11175.3, 11839.82, 12543.85};
const float DIV127 = (1.0 /127.0);
const float DIV1023 = (1/1023);
const float DIV85 = (1.0/85.0);
const float DIV12 = (1.0/12);
const float DIV_32767 = 0.0000305185;

//Arrays for addressing specific elements of each of the 8 voices

//Oscilllators
AudioMixer4 *mixerOsc[VOICES] = {&mixerOsc0, &mixerOsc1, &mixerOsc2, &mixerOsc3, &mixerOsc4, &mixerOsc5, &mixerOsc6, &mixerOsc7};
AudioSynthWaveformModulated *oscA[VOICES] = {&oscA0, &oscA1, &oscA2, &oscA3, &oscA4, &oscA5, &oscA6, &oscA7};
AudioSynthWaveformModulated *oscB[VOICES] = {&oscB0, &oscB1, &oscB2, &oscB3, &oscB4, &oscB5, &oscB6, &oscB7};
AudioSynthNoisePink *pink[VOICES] = {&pink0, &pink1, &pink2, &pink3, &pink4, &pink5, &pink6, &pink7};
//Freq Modulation
AudioMixer4 *mixerOscAFreqModA[VOICES] = {&mixerOscAFreqModA0, &mixerOscAFreqModA1, &mixerOscAFreqModA2, &mixerOscAFreqModA3, &mixerOscAFreqModA4, &mixerOscAFreqModA5, &mixerOscAFreqModA6, &mixerOscAFreqModA7};
AudioMixer4 *mixerOscAFreqModB[VOICES] = {&mixerOscAFreqModB0, &mixerOscAFreqModB1, &mixerOscAFreqModB2, &mixerOscAFreqModB3, &mixerOscAFreqModB4, &mixerOscAFreqModB5, &mixerOscAFreqModB6, &mixerOscAFreqModB7};
AudioMixer4 *mixerOscBFreqModA[VOICES] = {&mixerOscBFreqModA0, &mixerOscBFreqModA1, &mixerOscBFreqModA2, &mixerOscBFreqModA3, &mixerOscBFreqModA4, &mixerOscBFreqModA5, &mixerOscBFreqModA6, &mixerOscBFreqModA7};
AudioMixer4 *mixerOscBFreqModB[VOICES] = {&mixerOscBFreqModB0, &mixerOscBFreqModB1, &mixerOscBFreqModB2, &mixerOscBFreqModB3, &mixerOscBFreqModB4, &mixerOscBFreqModB5, &mixerOscBFreqModB6, &mixerOscBFreqModB7};

AudioSynthWaveformDc *dcPitchBend[VOICES] = {&dcPitchBend0, &dcPitchBend1, &dcPitchBend2, &dcPitchBend3, &dcPitchBend4, &dcPitchBend5, &dcPitchBend6, &dcPitchBend7};
AudioSynthWaveformDc *dcPitchOctaveA[VOICES] = {&dcPitchOctaveA0, &dcPitchOctaveA1, &dcPitchOctaveA2, &dcPitchOctaveA3, &dcPitchOctaveA4, &dcPitchOctaveA5, &dcPitchOctaveA6, &dcPitchOctaveA7};
AudioSynthWaveformDc *dcPitchOctaveB[VOICES] = {&dcPitchOctaveB0, &dcPitchOctaveB1, &dcPitchOctaveB2, &dcPitchOctaveB3, &dcPitchOctaveB4, &dcPitchOctaveB5, &dcPitchOctaveB6, &dcPitchOctaveB7};
AudioAmplifier *lfoFreq[VOICES] = {&lfoFreq0, &lfoFreq1, &lfoFreq2, &lfoFreq3, &lfoFreq4, &lfoFreq5, &lfoFreq6, &lfoFreq7};
AudioSynthWaveformDc *dcPitchDetuneA[VOICES] = {&dcPitchDetuneA0, &dcPitchDetuneA1, &dcPitchDetuneA2, &dcPitchDetuneA3, &dcPitchDetuneA4, &dcPitchDetuneA5, &dcPitchDetuneA6, &dcPitchDetuneA7};
AudioSynthWaveformDc *dcPitchDetuneB[VOICES] = {&dcPitchDetuneB0, &dcPitchDetuneB1, &dcPitchDetuneB2, &dcPitchDetuneB3, &dcPitchDetuneB4, &dcPitchDetuneB5, &dcPitchDetuneB6, &dcPitchDetuneB7};

//PWM Modulation
AudioMixer4 *mixerOscPWModA[VOICES] = {&mixerOscPWModA0, &mixerOscPWModA1, &mixerOscPWModA2, &mixerOscPWModA3, &mixerOscPWModA4, &mixerOscPWModA5, &mixerOscPWModA6, &mixerOscPWModA7};
AudioMixer4 *mixerOscPWModB[VOICES] = {&mixerOscPWModB0, &mixerOscPWModB1, &mixerOscPWModB2, &mixerOscPWModB3, &mixerOscPWModB4, &mixerOscPWModB5, &mixerOscPWModB6, &mixerOscPWModB7};
AudioAmplifier *lfoPW[VOICES] = {&lfoPW0, &lfoPW1, &lfoPW2, &lfoPW3, &lfoPW4, &lfoPW5, &lfoPW6, &lfoPW7};
AudioSynthWaveformDc *dcOscPWA[VOICES] = {&dcOscPWA0, &dcOscPWA1, &dcOscPWA2, &dcOscPWA3, &dcOscPWA4, &dcOscPWA5, &dcOscPWA6, &dcOscPWA7};
AudioSynthWaveformDc *dcOscPWB[VOICES] = {&dcOscPWB0, &dcOscPWB1, &dcOscPWB2, &dcOscPWB3, &dcOscPWB4, &dcOscPWB5, &dcOscPWB6, &dcOscPWB7};

//Filter
AudioFilterLadder *ladder[VOICES] = {&ladder0, &ladder1, &ladder2, &ladder3, &ladder4, &ladder5, &ladder6, &ladder7};

AudioMixer4 *mixerFilterFreqA[VOICES] = {&mixerFilterFreqA0, &mixerFilterFreqA1, &mixerFilterFreqA2, &mixerFilterFreqA3, &mixerFilterFreqA4, &mixerFilterFreqA5, &mixerFilterFreqA6, &mixerFilterFreqA7};
AudioMixer4 *mixerFilterFreqB[VOICES] = {&mixerFilterFreqB0, &mixerFilterFreqB1, &mixerFilterFreqB2, &mixerFilterFreqB3, &mixerFilterFreqB4, &mixerFilterFreqB5, &mixerFilterFreqB6, &mixerFilterFreqB7};
AudioMixer4 *mixerFilterRes[VOICES] = {&mixerFilterRes0, &mixerFilterRes1, &mixerFilterRes2, &mixerFilterRes3, &mixerFilterRes4, &mixerFilterRes5, &mixerFilterRes6, &mixerFilterRes7};

AudioAmplifier *lfoFilterFreq[VOICES] = {&lfoFilterFreq0, &lfoFilterFreq1, &lfoFilterFreq2, &lfoFilterFreq3, &lfoFilterFreq4, &lfoFilterFreq5, &lfoFilterFreq6, &lfoFilterFreq7};
AudioSynthWaveformDc *dcFilterAft[VOICES] = {&dcFilterAft0, &dcFilterAft1, &dcFilterAft2, &dcFilterAft3, &dcFilterAft4, &dcFilterAft5, &dcFilterAft6, &dcFilterAft7};
AudioSynthWaveformDc *dcFilterEnv[VOICES] = {&dcFilterEnv0, &dcFilterEnv1, &dcFilterEnv2, &dcFilterEnv3, &dcFilterEnv4, &dcFilterEnv5, &dcFilterEnv6, &dcFilterEnv7};
AudioEffectEnvelope *envelopeFilter[VOICES] = {&envelopeFilter0, &envelopeFilter1, &envelopeFilter2, &envelopeFilter3, &envelopeFilter4, &envelopeFilter5, &envelopeFilter6, &envelopeFilter7};
AudioSynthWaveformDc *dcFilterKbd[VOICES] = {&dcFilterKbd0, &dcFilterKbd1, &dcFilterKbd2, &dcFilterKbd3, &dcFilterKbd4, &dcFilterKbd5, &dcFilterKbd6, &dcFilterKbd7};
AudioSynthWaveformDc *dcFilterVel[VOICES] = {&dcFilterVel0, &dcFilterVel1, &dcFilterVel2, &dcFilterVel3, &dcFilterVel4, &dcFilterVel5, &dcFilterVel6, &dcFilterVel7};

//Audio Effects
AudioEffectEnvelope *envelopeVol[VOICES] = {&envelopeVol0, &envelopeVol1, &envelopeVol2, &envelopeVol3, &envelopeVol4, &envelopeVol5, &envelopeVol6, &envelopeVol7};