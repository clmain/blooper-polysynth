//Midi CC Definitions
//Undefined blocks are 21 - 31, 46 - 63, 84 - 90, 102 - 119 
#define CC_ChannelMain 14
#define CC_SecondaryChannel 15
#define CC_SecondaryEnable 16
#define CC_SecondaryControl 17
#define CC_SecondaryBypass 18
#define CC_SecondaryVolume 19
#define CC_Polymode 84
#define CC_Portamento 90
#define CC_OscAWavetype 24
#define CC_OscBWavetype 25
#define CC_OscADetune 20
#define CC_OscBDetune 21
#define CC_OscVibrato 58
#define CC_OscAOctave 22
#define CC_OscBOctave 23
#define CC_OscAPulseWidth 26
#define CC_OscBPulseWidth 27
#define CC_OscPulseWidthMod 60

#define CC_FilterFreq 47
#define CC_FilterRes 48
#define CC_FilterEnv 52
#define CC_FilterKeyboard 49
#define CC_FilterVelocity 50
#define CC_FilterLFO 63
#define CC_FilterKBDVeloControl 51

#define CC_EnvVolumeAttack 28
#define CC_EnvVolumeDecay 29
#define CC_EnvVolumeSustain 30
#define CC_EnvVolumeRelease 31
#define CC_EnvFilterDelay 53
#define CC_EnvFilterAttack 54
#define CC_EnvFilterDecay 55
#define CC_EnvFilterSustain 56
#define CC_EnvFilterRelease 57

#define CC_ModWheel 1
#define CC_ModWheelMode 88
#define CC_ExpPedalMode 89
#define CC_AftertouchMode 114
#define CC_PitchBendAmount 46

#define CC_LFOWavetype 61
#define CC_LFOSpeed 62

#define CC_ReverbSize 102 
#define CC_ReverbDamping 103
#define CC_ReverbWet 104

#define CC_DelayLevel 110
#define CC_DelayInputLevel 111
#define CC_DelayTime 112
#define CC_DelayFeedback 113

#define CC_MixerOscA 85
#define CC_MixerOscB 86
#define CC_MixerPink 87
#define CC_MasterVol 59

#define CC_TremoloWavetype 107
#define CC_TremoloSpeed 108
#define CC_TremoloDepth 109

#define CC_ChorusWet 105

#define CC_LeslieSpeed 115
#define CC_LeslieDepth 116

#define CC_PhaserSpeed 118
#define CC_PhaserFeedback 119
#define CC_PhaserWet 117

#define CC_UNUSED 106



/*
TEENSY 4.1 PINOUT REFERENCE
LEFT
    GND
    0 RX1   MIDI In (5 pin port)
    1 
    2 
    3
    4
    5
    6       Memory Chip
    7       Audio Data
    8       Audio Data
    9
    10      SD Card, Memory Chip
    11      SD Card, Memory Chip
    12      SD Card, Memory Chip
    3.3V
    24
    25
    26
    27/A13  MuxA Sig
    28      MuxA Engage
    29      MuxA S3
    30      MuxA S2
    31      MuxA S1
    32      MuxA S0
*/

#define ExpPedalPin 38
#define LEDPin 13

// #define MuxA_MaxPins 16 //Max number of pins in use 
// #define MuxA_S0 32
// #define MuxA_S1 31
// #define MuxA_S2 30
// #define MuxA_S3 29
// #define MuxA_Engage 28
// #define MuxA_Sig A13

// /*

// RIGHT
//     VIn
//     Gnd
//     3.3v
//     23
//     22      Audio Data
//     21      Audio Data
//     20      Audio Data
//     19      Audio Control
//     18      Audio Control
//     17
//     16
//     15      Volume
//     14
//     13      SD Card
//     GND
//     41
//     40
//     39
//     38/A14  Exp Pedal
//     37
//     36
//     35
//     34
//     33

// */



// //Mux Pin Definitions

// #define MUX_Polymode //Switch
// #define MUX_OscAWavetype //Multiswitch 
// #define MUX_OscBWavetype //Multiswitch
// #define MUX_OscADetune 
// #define MUX_OscBDetune 
// #define MUX_OscVibrato
// #define MUX_OscAOctave 
// #define MUX_OscBOctave 
// #define MUX_OscAPulseWidth 
// #define MUX_OscBPulseWidth 
// #define MUX_OscPulseWidthMod 

// #define MUX_FilterFreq 
// #define MUX_FilterRes  
// #define MUX_FilterEnv 
// #define MUX_FilterKeyboard 
// #define MUX_FilterVelocity 
// #define MUX_FilterLFO 
// #define MUX_FilterKBDVeloControl //Switch x2

// #define MUX_EnvVolumeAttack 
// #define MUX_EnvVolumeDecay 
// #define MUX_EnvVolumeSustain 
// #define MUX_EnvVolumeRelease 
// #define MUX_EnvFilterDelay
// #define MUX_EnvFilterAttack 
// #define MUX_EnvFilterDecay 
// #define MUX_EnvFilterSustain 
// #define MUX_EnvFilterRelease 
 
// #define MUX_ExpPedal
// #define MUX_ModWheelMode //Multiswitch
// #define MUX_ExpPedalMode //Multiswitch
// #define MUX_AftertouchMode //Multiswitch
// #define MUX_PitchBendAmount //Multiswitch
 
// #define MUX_LFOWavetype 
// #define MUX_LFOSpeed 
 
// #define MUX_ReverbTime 
// #define MUX_ReverbDamp 
// #define MUX_ReverbWet 
 
// #define MUX_DelayLevel 
// #define MUX_DelayInputLevel 
// #define MUX_DelayTime 
// #define MUX_DelayFeedback 
 
// #define MUX_MixerOscA 
// #define MUX_MixerOscB 
// #define MUX_MixerPink 
// #define MUX_MasterVol 
 
// #define MUX_TremoloWavetype 
// #define MUX_TremoloSpeed 
// #define MUX_TremoloDepth 
 
// #define MUX_ChorusWet 
 
// #define MUX_LeslieSpeed 
// #define MUX_LeslieDepth 
 
// #define MUX_PhaserSpeed 
// #define MUX_PhaserFeedback 
// #define MUX_PhaserWet 