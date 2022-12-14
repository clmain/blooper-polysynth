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

//<-----Mux Definitions ------------->
#define SCREEN_LENGTH 17 //16 characters, plus termination
const int muxChannel[16][4]={
    {0,0,0,0}, //channel 0
    {1,0,0,0}, //channel 1
    {0,1,0,0}, //channel 2
    {1,1,0,0}, //channel 3
    {0,0,1,0}, //channel 4
    {1,0,1,0}, //channel 5
    {0,1,1,0}, //channel 6
    {1,1,1,0}, //channel 7
    {0,0,0,1}, //channel 8
    {1,0,0,1}, //channel 9
    {0,1,0,1}, //channel 10
    {1,1,0,1}, //channel 11
    {0,0,1,1}, //channel 12
    {1,0,1,1}, //channel 13
    {0,1,1,1}, //channel 14
    {1,1,1,1}  //channel 15
};
const int muxMaxChannels = 15;

#define pinLeft 7
#define pinRight 6
#define pinUp 5
#define pinDown 4
#define pinBack 3
#define pinEnter 2
#define pinMux_En 8
#define pinMux_S0 9
#define pinMux_S1 10
#define pinMux_S2 11
#define pinMux_S3 12
#define pinMuxA_Sig A0
#define pinMuxB_Sig A1
#define pinMuxC_Sig A2
#define pinMuxD_Sig A3

// Mux A
#define muxA_MaxPins 15
#define mux_ModSetting 0
#define mux_ExpSetting 1
#define mux_AftSetting 2
#define mux_AftEnv 3
#define mux_BendAmount 4
#define mux_Osc1Dtn 5
#define mux_Osc2Dtn 6
#define mux_Osc1Wav 7
#define mux_Osc2Wav 8
#define mux_Osc1Oct 9
#define mux_Osc2Oct 10
#define mux_Osc1Pw 11
#define mux_Osc2Pw 12
#define mux_OscVib 13
#define mux_OscPwm 14
#define mux_Porta 15

//Mux B
#define muxB_MaxPins 15
#define mux_SecondaryEnable 0
#define mux_Poly  1
#define mux_SecondaryCtrl 2
#define mux_SecondaryBypass 3
#define mux_FtrFreq 4
#define mux_FtrKbdCtrl 5
#define mux_Ftrkbd 6
#define mux_FtrVelCtrl 7
#define mux_FtrEnv 8
#define mux_FtrRes 9
#define mux_FtrVel 10
#define mux_FtrLFO 11
#define mux_LFOShape 12
#define mux_DelayInput 13
#define mux_LFOSpeed 14
#define mux_DelayTime 15

//Mux C
#define muxC_MaxPins 13
#define mux_VolEnvDecay 0
#define mux_VolEnvAttack 1
#define mux_FtrEnvDelay 2
#define mux_FtrEnvAttack 3
#define mux_FtrEnvDecay 4
#define mux_FtrEnvSustain 5
#define mux_FtrEnvRelease 6
#define mux_MixPink 7
#define mux_VolSecondary 8
#define mux_VolMaster 9
#define mux_MixOsc1 10
#define mux_MixOsc2 11
#define mux_VolEnvRelease 12
#define mux_VolEnvSustain 13

//Mux D
#define muxD_MaxPins 13
#define mux_DelayLevel 0
#define mux_TremSpeed 1
#define mux_DelayFbdk 2
#define mux_TremDepth 3
#define mux_LeslieDepth 4
#define mux_PhaserWet 5
#define mux_ReverbWet 6
#define mux_ReverbDamp 7
#define mux_ReverbTime 8
#define mux_PhaserFbdk 9
#define mux_PhaserSpeed 10
#define mux_LeslieSpeed 11
#define mux_ChorusWet 12
#define mux_TremShape 13