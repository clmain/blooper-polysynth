#include <Wire.h>
#include <Waveshare_LCD1602_RGB.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <MIDI.h>
#include "cc_defs.h"
#include "display_strings.h"

/*PINOUT

LEFT
----

D13
3v3
AREF
A0 - MUX A
A1 - MUX B
A2 - MUX C
A3 - MUX D
A4 - LCD SDA
A5 - LCD SCL 
A6
A7
5V - Ext Power
RESET
GND
VIN

RIGHT
-----

D12 - MUX CTL S3
D11 - MUX CTL S2
D10 - MUX CTL S1
D9 - MUX CTL S0
D8 - MUX CTL En
D7 - LEFT
D6 - RIGHT
D5 - UP
D4 - DOWN
D3 - BACK
D2 - ENTER
GND
RESET
RX
TX - MIDI -> Teensy
*/
const float DIV127 = (1.0 /127.0);
static unsigned long timeoutMillis = 0;
bool ftrVelo = 0;
bool ftrKbd = 0;

//Screen & Control Variables
int booted = 0;
int stateLeft = 0;
int stateRight = 0;
int stateUp = 0;
int stateDown = 0;
int stateBack = 0;
int stateEnter = 0;

int horizPos = 0;
int primaryMidiPos = 0;
int secondaryMidiPos = 1;
int primarySlotPos = 4;
int secondarySlotPos = 3;

char stringBuffer[16];

#define horizLength (sizeof(horizMenu)/sizeof(horizMenu[0]))-1
#define midiLength (sizeof(midiMenu)/sizeof(midiMenu[0]))-1
#define slotLength (sizeof(slotMenu)/sizeof(slotMenu[0]))-1
int sure = 0;

char buffer0 [SCREEN_LENGTH]="BLOOPER";
char buffer1 [SCREEN_LENGTH]="Screen TBC :(";

char &line0 = *buffer0;
char &line1 = *buffer1;

Waveshare_LCD1602_RGB lcdWav(16,2);  //16 characters and 2 lines of show
int r,g,b=0;
MIDI_CREATE_DEFAULT_INSTANCE();

//---------------------------------------------------------------------------------------------//
// function setup
//Arduino initial Setup Function
//---------------------------------------------------------------------------------------------//
void setup() {
  //Serial.begin(9600);
  Serial.begin(31250);
  //delay(500);
  // lcdWav.init();
  // lcdWav.setCursor(0,0);
  // lcdWav.send_string(&line0);
  // lcdWav.setCursor(0,1);
  // lcdWav.send_string(&line1);

  pinMode(pinLeft, INPUT);
  pinMode(pinRight, INPUT);
  pinMode(pinUp, INPUT);
  pinMode(pinDown, INPUT);
  pinMode(pinBack, INPUT);
  pinMode(pinEnter, INPUT);
  pinMode(pinMuxA_Sig, INPUT);
  pinMode(pinMux_En, OUTPUT);
  pinMode(pinMux_S0, OUTPUT);
  pinMode(pinMux_S1, OUTPUT);
  pinMode(pinMux_S2, OUTPUT);
  pinMode(pinMux_S3, OUTPUT);
  while (!Serial);  // wait for serial port to connect. Needed for native USB
  //delay(1500);
  // for(int i=0; i<=15; i++) {
  //   checkMuxs();
  //   delay(102);
  // }
  MIDI.turnThruOff();
  // updateHorizPos();
  // strcpy_P(stringBuffer, (char *)pgm_read_word(&(horizMenu[0])));
  // updateScreen(0,stringBuffer);
  booted=1;
}

//---------------------------------------------------------------------------------------------//
// function loop
//Main Arduino Loop function
//---------------------------------------------------------------------------------------------//
void loop() {
  //checkInputs();
  checkMux();
  //screenTimeout();

  //DEBUG

  // static long currentMillis;
  // bool on;
  // if (millis() - currentMillis >= 1000) {
  //   if(on) {
  //       MIDI.sendNoteOff(40,0,1);
  //       on=false;
  //   } else {
  //     MIDI.sendNoteOn(40,100,1);
  //     on=true;
  //   }
  //   currentMillis = millis();
  // }
}

//---------------------------------------------------------------------------------------------//
// function checkMux
//Checks inputs wired via Mux to Arduino. For Inputs attached directly, see checkInputs()
//---------------------------------------------------------------------------------------------//
void checkMux() {
  static byte channel = 0;
  static int muxAValues[muxA_MaxPins] = {};
  static int muxBValues[muxB_MaxPins] = {};
  static int muxCValues[muxC_MaxPins] = {};
  static int muxDValues[muxD_MaxPins] = {};

  unsigned long currentMicros = micros();
  static unsigned long lastMicros = 0;

  if(currentMicros-lastMicros >=1000) {
    lastMicros = currentMicros;

    //Mux A
    int muxRead;
    
    muxRead = analogRead(pinMuxA_Sig);
    //Tolerance to avoid minor noise/value changes affecting vaue
    if (muxRead > (muxAValues[channel] + 7) || muxRead < (muxAValues[channel] - 7)) {
      timeoutMillis = millis();
      muxAValues[channel] = muxRead;
      muxRead = (muxRead >> 3); //Change range to 0-127

      if(booted==1) { //Can be run to build up an array of controller positions on boot without making any changes 
        //Mux A
        switch(channel) {
          case mux_ModSetting:
            break;
          case mux_ExpSetting:
            break;
          case mux_AftSetting:
            break;
          case mux_AftEnv:
            break;
          case mux_BendAmount:
            muxRead=(muxRead * DIV127)*12;
            MIDI.sendControlChange(CC_PitchBendAmount, int(muxRead), 1);
            break;
          case mux_Osc1Dtn:
            MIDI.sendControlChange(CC_OscADetune, muxRead, 1);
            break;
          case mux_Osc2Dtn:
            MIDI.sendControlChange(CC_OscBDetune, muxRead, 1);
            break;
          case mux_Osc1Wav:
            switch (muxRead) {
              case 0 ...15:
                muxRead =0;
                break;
              case 16 ...45:
                muxRead =1;
                break;
              case 46 ...80:
                muxRead =2;
                break;
              case 81 ...115:
                muxRead =3;
                break;
              case 116 ...127:
                muxRead =4;
                break;
            }
            MIDI.sendControlChange(CC_OscAWavetype, int(muxRead), 1);
            break;
          case mux_Osc2Wav:
            switch (muxRead) {
              case 0 ...15:
                muxRead =0;
                break;
              case 16 ...45:
                muxRead =1;
                break;
              case 46 ...80:
                muxRead =2;
                break;
              case 81 ...115:
                muxRead =3;
                break;
              case 116 ...127:
                muxRead =4;
                break;
            }
            MIDI.sendControlChange(CC_OscBWavetype, int(muxRead), 1);
            break;
          case mux_Osc1Oct:
            switch (muxRead) {
              case 0 ...15:
                muxRead =0;
                break;
              case 16 ...45:
                muxRead =1;
                break;
              case 46 ...80:
                muxRead =2;
                break;
              case 81 ...115:
                muxRead =3;
                break;
              case 116 ...127:
                muxRead =4;
                break;
            }
            MIDI.sendControlChange(CC_OscAOctave, int(muxRead), 1);
            break;
          case mux_Osc2Oct:
            switch (muxRead) {
              case 0 ...15:
                muxRead =0;
                break;
              case 16 ...45:
                muxRead =1;
                break;
              case 46 ...80:
                muxRead =2;
                break;
              case 81 ...115:
                muxRead =3;
                break;
              case 116 ...127:
                muxRead =4;
                break;
            }
            MIDI.sendControlChange(CC_OscBOctave, int(muxRead), 1);
            break;
          case mux_Osc1Pw:
            MIDI.sendControlChange(CC_OscAPulseWidth, muxRead, 1);
            break;
          case mux_Osc2Pw:
            MIDI.sendControlChange(CC_OscBPulseWidth, muxRead, 1);
            break;
          case mux_OscVib:
            MIDI.sendControlChange(CC_OscVibrato, muxRead, 1);
            break;
          case mux_OscPwm:
            //MIDI.sendControlChange(CC_OscPulseWidthMod, muxRead, 1);
            break;
          case mux_Porta:
            MIDI.sendControlChange(CC_Portamento, muxRead, 1);
            break;
        }
      }
    }
    
    //Mux B
    //muxRead = analogRead(pinMuxB_Sig);
    // if (muxRead > (muxBValues[channel] + 7) || muxRead < (muxBValues[channel] - 7)) {
    //   timeoutMillis = millis();
    //   muxBValues[channel] = muxRead;
    //   muxRead = (muxRead >> 3); //Change range to 0-127
      
    //   if(booted==1) { //Can be run to build up an array of controller positions on boot without making any changes 
    //     switch(channel) {
    //       case mux_SecondaryEnable:
    //         if(muxRead>60) {
    //           muxRead=0;
    //         }else {
    //           muxRead=1;
    //         }
    //         //MIDI.sendControlChange(CC_SecondaryEnable, muxRead, 1);
    //         break;
    //       case mux_Poly:
    //         if(muxRead>60) {
    //           muxRead=0;
    //         } else {
    //           muxRead=1;
    //         }
    //         //MIDI.sendControlChange(CC_Polymode, muxRead, 1);
    //       case mux_SecondaryCtrl:
    //         if(muxRead>60) {
    //           muxRead=0;
    //         }else {
    //           muxRead=1;
    //         }
    //         //MIDI.sendControlChange(CC_SecondaryControl, muxRead, 1);
    //         break;
    //       case mux_SecondaryBypass:
    //         if(muxRead>60) {
    //           muxRead=0;
    //         }else {
    //           muxRead=1;
    //         }
    //         //MIDI.sendControlChange(CC_SecondaryBypass, muxRead, 1);
    //         break;   
    //       case mux_FtrFreq:
    //         MIDI.sendControlChange(CC_FilterFreq, muxRead, 1);
    //         break;      
    //       case mux_FtrKbdCtrl:
    //         //Written from switch position rather than voltage reading - if the switch is over the left pin, then centre and right are connected. 
    //         //This statement looks backwards as a result. 
    //         if(muxRead>60) {
    //           ftrKbd=0;
    //         }else {
    //           ftrKbd=1;
    //         }
    //         updateFtrKbdVelo();
    //         break;
    //       case mux_Ftrkbd:
    //         MIDI.sendControlChange(CC_FilterKeyboard, muxRead, 1);
    //         break;        
    //       case mux_FtrVelCtrl:
    //         //See mux_FtrKbdCtrl for why this is backwards
    //         if(muxRead>60) {
    //           ftrVelo=0;
    //         }else {
    //           ftrVelo=1;
    //         }
    //         updateFtrKbdVelo();
    //         break; 
    //       case mux_FtrEnv:
    //         MIDI.sendControlChange(CC_FilterEnv, muxRead, 1);
    //         break;   
    //       case mux_FtrRes:
    //         MIDI.sendControlChange(CC_FilterRes, muxRead, 1);
    //         break;
    //       case mux_FtrVel:
    //         MIDI.sendControlChange(CC_FilterVelocity, muxRead, 1);
    //         break;
    //       case mux_FtrLFO:
    //         MIDI.sendControlChange(CC_FilterLFO, muxRead, 1);
    //         break;       
    //       case mux_LFOShape:
    //         switch (muxRead) {
    //           case 0 ...15:
    //             muxRead =0;
    //             break;
    //           case 16 ...45:
    //             muxRead =1;
    //             break;
    //           case 46 ...80:
    //             muxRead =2;
    //             break;
    //           case 81 ...115:
    //             muxRead =3;
    //             break;
    //           case 116 ...127:
    //             muxRead =4;
    //             break;
    //         }
    //         MIDI.sendControlChange(CC_LFOWavetype, muxRead, 1);
    //         break; 
    //       case mux_DelayInput:
    //         MIDI.sendControlChange(CC_DelayInputLevel, muxRead, 1);
    //         break;  
    //       case mux_LFOSpeed:
    //         MIDI.sendControlChange(CC_LFOSpeed, muxRead, 1);
    //         break;  
    //       case mux_DelayTime:
    //         MIDI.sendControlChange(CC_DelayTime, muxRead, 1);
    //         break;                                     
    //     }
    //   }
    // }
    
    //Mux C
    //muxRead = analogRead(pinMuxC_Sig);
    // if (muxRead > (muxCValues[channel] + 7) || muxRead < (muxCValues[channel] - 7)) {
    //   timeoutMillis = millis();
    //   muxCValues[channel] = muxRead;
    //   muxRead = (muxRead >> 3); //Change range to 0-127
      
    //   if(booted==1) { //Can be run to build up an array of controller positions on boot without making any changes 
    //     switch(channel) {
    //       case mux_VolEnvDecay:
    //         MIDI.sendControlChange(CC_EnvVolumeDecay, muxRead, 1);
    //         MIDI.sendControlChange(CC_FilterFreq, muxRead, 1);
    //         break;
    //       case mux_VolEnvAttack:
    //         Serial.print("Attack: ");
    //         Serial.print(muxRead);
    //         Serial.println(" - END");
    //         MIDI.sendControlChange(CC_EnvVolumeAttack, muxRead, 1);    
    //         break; 
    //       case mux_FtrEnvDelay:
    //         MIDI.sendControlChange(CC_EnvFilterDelay, muxRead, 1);
    //         break; 
    //       case mux_FtrEnvAttack:
    //         MIDI.sendControlChange(CC_EnvFilterAttack, muxRead, 1);
    //         break;     
    //       case mux_FtrEnvDecay:
    //         MIDI.sendControlChange(CC_EnvFilterDecay, muxRead, 1);
    //         break; 
    //       case mux_FtrEnvSustain:
    //         MIDI.sendControlChange(CC_EnvFilterSustain, muxRead, 1);
    //         break;                       
    //       case mux_FtrEnvRelease:
    //         MIDI.sendControlChange(CC_EnvFilterRelease, muxRead, 1);
    //         break;  
    //       case mux_MixPink:
    //         MIDI.sendControlChange(CC_MixerPink, muxRead, 1);
    //         break;     
    //       case mux_VolSecondary:
    //         MIDI.sendControlChange(CC_SecondaryVolume, muxRead, 1);
    //         break;  
    //       case mux_VolMaster:
    //         MIDI.sendControlChange(CC_MasterVol, muxRead, 1);
    //         break;
    //       case mux_MixOsc1:
    //         MIDI.sendControlChange(CC_MixerOscA, muxRead, 1);
    //         break;
    //       case mux_MixOsc2:
    //         MIDI.sendControlChange(CC_MixerOscB, muxRead, 1);
    //         break;
    //       case mux_VolEnvRelease:
    //         MIDI.sendControlChange(CC_EnvVolumeRelease, muxRead, 1);
    //         break; 
    //       case mux_VolEnvSustain:
    //         MIDI.sendControlChange(CC_EnvVolumeSustain, muxRead, 1);
    //         break;            
    //     }        
    //   }
    // }
    
    //Mux D
    // if(channel<=muxD_MaxPins) {

    //   //muxRead = analogRead(pinMuxD_Sig);

    //   if (muxRead > (muxDValues[channel] + 7) || muxRead < (muxDValues[channel] - 7)) {
    //     timeoutMillis = millis();

    //     muxDValues[channel] = muxRead;
    //     muxRead = (muxRead >> 3); //Change range to 0-127
      
    //     if(booted==1) { //Can be run to build up an array of controller positions on boot without making any changes 
    //       switch(channel) {
    //         case mux_DelayLevel:
    //           MIDI.sendControlChange(CC_DelayLevel, muxRead, 1);
    //           break;
    //         case mux_TremSpeed:
    //           MIDI.sendControlChange(CC_TremoloSpeed, muxRead, 1);
    //           break;            
    //         case mux_DelayFbdk:
    //           MIDI.sendControlChange(CC_DelayFeedback, muxRead, 1);
    //           break;
    //         case mux_TremDepth:
    //           MIDI.sendControlChange(CC_TremoloDepth, muxRead, 1);
    //           break;               
    //         case mux_LeslieDepth:
    //           MIDI.sendControlChange(CC_LeslieDepth, muxRead, 1);
    //           break;
    //         case mux_PhaserWet:
    //           MIDI.sendControlChange(CC_PhaserWet, muxRead, 1);
    //           break;
    //         case mux_ReverbWet:
    //           MIDI.sendControlChange(CC_ReverbWet, muxRead, 1);
    //           break;
    //         case mux_ReverbTime:
    //           MIDI.sendControlChange(CC_ReverbSize, muxRead, 1);
    //           break;
    //         case mux_ReverbDamp:
    //           MIDI.sendControlChange(CC_ReverbDamping, muxRead, 1);
    //           break;
    //         case mux_PhaserSpeed:
    //           MIDI.sendControlChange(CC_PhaserSpeed, muxRead, 1);
    //           break;
    //         case mux_PhaserFbdk:
    //           MIDI.sendControlChange(CC_PhaserFeedback, muxRead, 1);
    //           break;
    //         case mux_LeslieSpeed:
    //           MIDI.sendControlChange(CC_LeslieSpeed, muxRead, 1);
    //           break;    
    //         case mux_ChorusWet:
    //           MIDI.sendControlChange(CC_ChorusWet, muxRead, 1);
    //           break;   
    //         case mux_TremShape:
    //           switch (muxRead) {
    //             case 0 ...15:
    //               muxRead =0;
    //               break;
    //             case 16 ...45:
    //               muxRead =1;
    //               break;
    //             case 46 ...80:
    //               muxRead =2;
    //               break;
    //             case 81 ...115:
    //               muxRead =3;
    //               break;
    //             case 116 ...127:
    //               muxRead =4;
    //               break;
    //           }
    //           MIDI.sendControlChange(CC_TremoloWavetype, muxRead, 1);            
    //           break;                             
    //       }
    //     }
    //   }
    //}
    
    channel++;
    //Reset to 0 if exceeds max number of pins in use on Mux
    if(channel > muxA_MaxPins)  {
      channel = 0;
    }


    //Don't fully understand this, but the combination of Input number and the bits seems to output the correct HIGH/LOW valeus
    //for the relevant pins to iterate through the Mux, so I'm not going to change it
    digitalWrite(pinMux_S0, channel & B0001);
    digitalWrite(pinMux_S1, channel & B0010);
    digitalWrite(pinMux_S2, channel & B0100);
    digitalWrite(pinMux_S3, channel & B1000);   
  }
}


void checkMuxs() {
  static byte channel = 0;
  static int muxAValues[muxA_MaxPins] = {};
  static int muxBValues[muxB_MaxPins] = {};
  static int muxCValues[muxC_MaxPins] = {};
  static int muxDValues[muxD_MaxPins] = {};

  unsigned long currentMicros = micros();
  static unsigned long lastMicros = 0;
  
  int muxRead;

  if(currentMicros-lastMicros >=100000) {
    lastMicros = currentMicros;

    digitalWrite(pinMux_S0, muxChannel[channel][0]);
    digitalWrite(pinMux_S1, muxChannel[channel][1]);
    digitalWrite(pinMux_S2, muxChannel[channel][2]);
    digitalWrite(pinMux_S3, muxChannel[channel][3]);

    


    //Mux A
    muxRead = analogRead(pinMuxA_Sig);
    if (muxRead > (muxAValues[channel] + 7) || muxRead < (muxAValues[channel] - 7)) {
      timeoutMillis = millis();
      muxAValues[channel] = muxRead;
      muxRead = (muxRead >> 3); //Change range to 0-127
      Serial.print("Channel ");
      Serial.print(channel);
      Serial.print(", Value: ");
      Serial.println(muxRead);
    }

    channel++;
    if(channel>muxMaxChannels) {
      channel=0;
    }
  }
}


void muxTest() {
  static int channel = 0;
  int channelValue;

  static int muxAValues[muxA_MaxPins] = {};
  static int muxBValues[muxB_MaxPins] = {};
  static int muxCValues[muxC_MaxPins] = {};
  static int muxDValues[muxD_MaxPins] = {};

  unsigned long currentMicros = micros();
  static unsigned long lastMicros = 0;
  
  if(currentMicros-lastMicros >=1000) {
    lastMicros = currentMicros;

    digitalWrite(pinMux_S0, muxChannel[channel][0]);
    digitalWrite(pinMux_S1, muxChannel[channel][1]);
    digitalWrite(pinMux_S2, muxChannel[channel][2]);
    digitalWrite(pinMux_S3, muxChannel[channel][3]);

    //<--------------MUX A-------------------->
    channelValue = analogRead(pinMuxA_Sig);

    //First check channel read is within channels in use on Mux
    if(channel<muxA_MaxPins) {
      //Check value is sufficiently different to last read, to eliminate minor noise/jitter
      if (channelValue > (muxAValues[channel] + 7) || channelValue < (muxAValues[channel] - 7)) {
        //Reduce range from 1024 -> 127 for MIDI Compliance
        channelValue = (channelValue >>3);
        muxAValues[channel] = channelValue;
        
        if(booted==1) { //Can be run to build up an array of controller positions on boot without making any changes 
          switch(channel) {
            case mux_ModSetting:
              break;
            case mux_ExpSetting:
              break;
            case mux_AftSetting:
              break;
            case mux_AftEnv:
              break;
            case mux_BendAmount:
              channelValue=(channelValue * DIV127)*12;
              MIDI.sendControlChange(CC_PitchBendAmount, int(channelValue), 1);
              break;
            case mux_Osc1Dtn:
              MIDI.sendControlChange(CC_OscADetune, channelValue, 1);
              break;
            case mux_Osc2Dtn:
              MIDI.sendControlChange(CC_OscBDetune, channelValue, 1);
              break;
            case mux_Osc1Wav:
              switch (channelValue) {
                case 0 ...15:
                  channelValue =0;
                  break;
                case 16 ...45:
                  channelValue =1;
                  break;
                case 46 ...80:
                  channelValue =2;
                  break;
                case 81 ...115:
                  channelValue =3;
                  break;
                case 116 ...127:
                  channelValue =4;
                  break;
              }
              MIDI.sendControlChange(CC_OscAWavetype, int(channelValue), 1);
              break;
            case mux_Osc2Wav:
              switch (channelValue) {
                case 0 ...15:
                  channelValue =0;
                  break;
                case 16 ...45:
                  channelValue =1;
                  break;
                case 46 ...80:
                  channelValue =2;
                  break;
                case 81 ...115:
                  channelValue =3;
                  break;
                case 116 ...127:
                  channelValue =4;
                  break;
              }
              MIDI.sendControlChange(CC_OscBWavetype, int(channelValue), 1);
              break;
            case mux_Osc1Oct:
              switch (channelValue) {
                case 0 ...15:
                  channelValue =0;
                  break;
                case 16 ...45:
                  channelValue =1;
                  break;
                case 46 ...80:
                  channelValue =2;
                  break;
                case 81 ...115:
                  channelValue =3;
                  break;
                case 116 ...127:
                  channelValue =4;
                  break;
              }
              MIDI.sendControlChange(CC_OscAOctave, int(channelValue), 1);
              break;
            case mux_Osc2Oct:
              switch (channelValue) {
                case 0 ...15:
                  channelValue =0;
                  break;
                case 16 ...45:
                  channelValue =1;
                  break;
                case 46 ...80:
                  channelValue =2;
                  break;
                case 81 ...115:
                  channelValue =3;
                  break;
                case 116 ...127:
                  channelValue =4;
                  break;
              }
              MIDI.sendControlChange(CC_OscBOctave, int(channelValue), 1);
              break;
            case mux_Osc1Pw:
              MIDI.sendControlChange(CC_OscAPulseWidth, channelValue, 1);
              break;
            case mux_Osc2Pw:
              MIDI.sendControlChange(CC_OscBPulseWidth, channelValue, 1);
              break;
            case mux_OscVib:
              MIDI.sendControlChange(CC_OscVibrato, channelValue, 1);
              break;
            case mux_OscPwm:
              //MIDI.sendControlChange(CC_OscPulseWidthMod, channelValue, 1);
              break;
            case mux_Porta:
              MIDI.sendControlChange(CC_Portamento, channelValue, 1);
              break;
          }
        }
      }
    }
    
    //<--------------MUX B-------------------->
    channelValue = analogRead(pinMuxB_Sig);

    //See muxA for more details
    if(channel<muxB_MaxPins) {
      if (channelValue > (muxBValues[channel] + 7) || channelValue < (muxBValues[channel] - 7)) {
        channelValue = (channelValue >>3);
        muxBValues[channel] = channelValue;

        if(false) { //DEBUG - disabled
        //if(booted==1) { //Can be run to build up an array of controller positions on boot without making any changes 
          switch(channel) {
            case mux_SecondaryEnable:
              if(channelValue>60) {
                channelValue=0;
              }else {
                channelValue=1;
              }
              //MIDI.sendControlChange(CC_SecondaryEnable, channelValue, 1);
              break;
            case mux_Poly:
              if(channelValue>60) {
                channelValue=0;
              } else {
                channelValue=1;
              }
              //MIDI.sendControlChange(CC_Polymode, channelValue, 1);
            case mux_SecondaryCtrl:
              if(channelValue>60) {
                channelValue=0;
              }else {
                channelValue=1;
              }
              //MIDI.sendControlChange(CC_SecondaryControl, channelValue, 1);
              break;
            case mux_SecondaryBypass:
              if(channelValue>60) {
                channelValue=0;
              }else {
                channelValue=1;
              }
              //MIDI.sendControlChange(CC_SecondaryBypass, channelValue, 1);
              break;   
            case mux_FtrFreq:
              MIDI.sendControlChange(CC_FilterFreq, channelValue, 1);
              break;      
            case mux_FtrKbdCtrl:
              //Written from switch position rather than voltage reading - if the switch is over the left pin, then centre and right are connected. 
              //This statement looks backwards as a result. 
              if(channelValue>60) {
                ftrKbd=0;
              }else {
                ftrKbd=1;
              }
              updateFtrKbdVelo();
              break;
            case mux_Ftrkbd:
              MIDI.sendControlChange(CC_FilterKeyboard, channelValue, 1);
              break;        
            case mux_FtrVelCtrl:
              //See mux_FtrKbdCtrl for why this is backwards
              if(channelValue>60) {
                ftrVelo=0;
              }else {
                ftrVelo=1;
              }
              updateFtrKbdVelo();
              break; 
            case mux_FtrEnv:
              MIDI.sendControlChange(CC_FilterEnv, channelValue, 1);
              break;   
            case mux_FtrRes:
              MIDI.sendControlChange(CC_FilterRes, channelValue, 1);
              break;
            case mux_FtrVel:
              MIDI.sendControlChange(CC_FilterVelocity, channelValue, 1);
              break;
            case mux_FtrLFO:
              MIDI.sendControlChange(CC_FilterLFO, channelValue, 1);
              break;       
            case mux_LFOShape:
              switch (channelValue) {
                case 0 ...15:
                  channelValue =0;
                  break;
                case 16 ...45:
                  channelValue =1;
                  break;
                case 46 ...80:
                  channelValue =2;
                  break;
                case 81 ...115:
                  channelValue =3;
                  break;
                case 116 ...127:
                  channelValue =4;
                  break;
              }
              MIDI.sendControlChange(CC_LFOWavetype, channelValue, 1);
              break; 
            case mux_DelayInput:
              MIDI.sendControlChange(CC_DelayInputLevel, channelValue, 1);
              break;  
            case mux_LFOSpeed:
              MIDI.sendControlChange(CC_LFOSpeed, channelValue, 1);
              break;  
            case mux_DelayTime:
              MIDI.sendControlChange(CC_DelayTime, channelValue, 1);
              break;                                     
          }
        }
      }
    }

    //<--------------MUX C-------------------->
    channelValue = analogRead(pinMuxC_Sig);

    //See muxA for more details
    if(channel<muxC_MaxPins) {
      if (channelValue > (muxCValues[channel] + 7) || channelValue < (muxCValues[channel] - 7)) {
        channelValue = (channelValue >>3);
        muxCValues[channel] = channelValue;

        if(false) { //DEBUG - Disabled
        // if(booted==1) {
          switch(channel) {
            case mux_VolEnvDecay:
              MIDI.sendControlChange(CC_EnvVolumeDecay, channelValue, 1);
              MIDI.sendControlChange(CC_FilterFreq, channelValue, 1);
              break;
            case mux_VolEnvAttack:
              Serial.print("Attack: ");
              Serial.print(channelValue);
              Serial.println(" - END");
              MIDI.sendControlChange(CC_EnvVolumeAttack, channelValue, 1);    
              break; 
            case mux_FtrEnvDelay:
              MIDI.sendControlChange(CC_EnvFilterDelay, channelValue, 1);
              break; 
            case mux_FtrEnvAttack:
              MIDI.sendControlChange(CC_EnvFilterAttack, channelValue, 1);
              break;     
            case mux_FtrEnvDecay:
              MIDI.sendControlChange(CC_EnvFilterDecay, channelValue, 1);
              break; 
            case mux_FtrEnvSustain:
              MIDI.sendControlChange(CC_EnvFilterSustain, channelValue, 1);
              break;                       
            case mux_FtrEnvRelease:
              MIDI.sendControlChange(CC_EnvFilterRelease, channelValue, 1);
              break;  
            case mux_MixPink:
              MIDI.sendControlChange(CC_MixerPink, channelValue, 1);
              break;     
            case mux_VolSecondary:
              MIDI.sendControlChange(CC_SecondaryVolume, channelValue, 1);
              break;  
            case mux_VolMaster:
              MIDI.sendControlChange(CC_MasterVol, channelValue, 1);
              break;
            case mux_MixOsc1:
              MIDI.sendControlChange(CC_MixerOscA, channelValue, 1);
              break;
            case mux_MixOsc2:
              MIDI.sendControlChange(CC_MixerOscB, channelValue, 1);
              break;
            case mux_VolEnvRelease:
              MIDI.sendControlChange(CC_EnvVolumeRelease, channelValue, 1);
              break; 
            case mux_VolEnvSustain:
              MIDI.sendControlChange(CC_EnvVolumeSustain, channelValue, 1);
              break;            
          }
        }
      }
    }

    //<--------------MUX D-------------------->
    channelValue = analogRead(pinMuxD_Sig);

    //See muxA for more details
    if(channel<muxD_MaxPins) {
      if (channelValue > (muxDValues[channel] + 7) || channelValue < (muxDValues[channel] - 7)) {
        channelValue = (channelValue >>3);
        muxDValues[channel] = channelValue;

        if(false) { //DEBUG - Disabled
        //if(booted==1) { //Can be run to build up an array of controller positions on boot without making any changes 
          switch(channel) {
            case mux_DelayLevel:
              MIDI.sendControlChange(CC_DelayLevel, channelValue, 1);
              break;
            case mux_TremSpeed:
              MIDI.sendControlChange(CC_TremoloSpeed, channelValue, 1);
              break;            
            case mux_DelayFbdk:
              MIDI.sendControlChange(CC_DelayFeedback, channelValue, 1);
              break;
            case mux_TremDepth:
              MIDI.sendControlChange(CC_TremoloDepth, channelValue, 1);
              break;               
            case mux_LeslieDepth:
              MIDI.sendControlChange(CC_LeslieDepth, channelValue, 1);
              break;
            case mux_PhaserWet:
              MIDI.sendControlChange(CC_PhaserWet, channelValue, 1);
              break;
            case mux_ReverbWet:
              MIDI.sendControlChange(CC_ReverbWet, channelValue, 1);
              break;
            case mux_ReverbTime:
              MIDI.sendControlChange(CC_ReverbSize, channelValue, 1);
              break;
            case mux_ReverbDamp:
              MIDI.sendControlChange(CC_ReverbDamping, channelValue, 1);
              break;
            case mux_PhaserSpeed:
              MIDI.sendControlChange(CC_PhaserSpeed, channelValue, 1);
              break;
            case mux_PhaserFbdk:
              MIDI.sendControlChange(CC_PhaserFeedback, channelValue, 1);
              break;
            case mux_LeslieSpeed:
              MIDI.sendControlChange(CC_LeslieSpeed, channelValue, 1);
              break;    
            case mux_ChorusWet:
              MIDI.sendControlChange(CC_ChorusWet, channelValue, 1);
              break;   
            case mux_TremShape:
              switch (channelValue) {
                case 0 ...15:
                  channelValue =0;
                  break;
                case 16 ...45:
                  channelValue =1;
                  break;
                case 46 ...80:
                  channelValue =2;
                  break;
                case 81 ...115:
                  channelValue =3;
                  break;
                case 116 ...127:
                  channelValue =4;
                  break;
              }
              MIDI.sendControlChange(CC_TremoloWavetype, channelValue, 1);            
                break;                             
          }
        }
      }
    }

    channel=channel+1;
    if(channel>muxMaxChannels) {
      channel=0;
    }
  }
}


//---------------------------------------------------------------------------------------------//
// function updateScreen
//
//---------------------------------------------------------------------------------------------//
void updateScreen(int line, char text[]) {
  int textLength = strlen(text);

  if(line==0) {
    for(int i=0; i<=textLength; i++) {
      buffer0[i] = text[i];
    }
    //Fill remaining characters with spaces to zero out rest of line
    for (int i = textLength; i<SCREEN_LENGTH; i++) {
      buffer0[i] = ' ';
    }
    lcdWav.setCursor(0,0);
    lcdWav.send_string(&line0);
  } else {
    for(int i=0; i<=textLength; i++) {
      buffer1[i] = text[i];
    }
    //Fill remaining characters with spaces to zero out rest of line
    for (int i = textLength; i<SCREEN_LENGTH; i++) {
      buffer1[i] = ' ';
    }
    lcdWav.setCursor(0,1);
    lcdWav.send_string(&line1);
  }
  
}

//---------------------------------------------------------------------------------------------//
// function screenTimeout
//
//---------------------------------------------------------------------------------------------//
void screenTimeout() {

    // Serial.println("currentMillis-timeoutMillis");
    // Serial.print(currentMillis);
    // Serial.print(" - ");
    // Serial.println(timeoutMillis);
  unsigned long currentMillis = millis();

  if(currentMillis-timeoutMillis>=2000) {
    getCurrentPos(0);

    int textLength = strlen(stringBuffer);
    //Fill remaining characters with spaces to zero out rest of line
    for (int i = textLength; i<SCREEN_LENGTH; i++) {
      stringBuffer[i] = ' ';
    }

    if(buffer0!=stringBuffer) {
        //Serial.println(buffer0); //Has whitespace breaking it - TODO
        //Serial.println(stringBuffer);
        //updateHorizPos();
      }
    }

  if(currentMillis-timeoutMillis<3000) {
    r=255;
    g=255;
    b=255;
  } else {
    r=127;
    g=127;
    b=127;
  }
  lcdWav.setRGB(r,g,b);
}

//---------------------------------------------------------------------------------------------//
// function checkInputs
//Checks inputs wired directly to Arduino. For Inputs attached via Mux, see checkMux()
//---------------------------------------------------------------------------------------------//
void checkInputs() {

  stateLeft = digitalRead(pinLeft);
  stateRight = digitalRead(pinRight);
  stateUp = digitalRead(pinUp);
  stateDown = digitalRead(pinDown);
  stateBack = digitalRead(pinBack);
  stateEnter = digitalRead(pinEnter);

  if(stateLeft==HIGH) { //LEFT
    timeoutMillis = millis();
    sure=0;
    horizPos--;
    if(horizPos<0) {
      horizPos=horizLength;
    }
    updateHorizPos();
    return;
  }

  if(stateRight==HIGH) { //RIGHT
    timeoutMillis = millis();
    sure=0;
    horizPos++;

    if(horizPos>horizLength) {
      horizPos=0;
    }
    updateHorizPos();
    return;
  }

  if(stateUp==HIGH) { //UP 
    timeoutMillis = millis();
    sure=0;
    switch(horizPos) {
      case 0: //Primary MIDI
        primaryMidiPos++;
        if(primaryMidiPos>midiLength) {
          primaryMidiPos=0;
        }
        strcpy_P(stringBuffer, (char *)pgm_read_word(&(midiMenu[primaryMidiPos])));
        updateScreen(1,stringBuffer);
        break;
      case 1: //Secondary MIDI
        secondaryMidiPos++;
        if(secondaryMidiPos>midiLength) {
          secondaryMidiPos=0;
        }
        strcpy_P(stringBuffer, (char *)pgm_read_word(&(midiMenu[secondaryMidiPos])));
        updateScreen(1,stringBuffer);
        break;
      case 2: //Primary Save
        primarySlotPos++;
        if(primarySlotPos>slotLength) {
          primarySlotPos=0;
        }
        strcpy_P(stringBuffer, (char *)pgm_read_word(&(slotMenu[primarySlotPos])));
        updateScreen(1,stringBuffer);
        break;
      case 3: //Primary Load
        primarySlotPos++;
        if(primarySlotPos>slotLength) {
          primarySlotPos=0;
        }
        strcpy_P(stringBuffer, (char *)pgm_read_word(&(slotMenu[primarySlotPos])));
        updateScreen(1,stringBuffer);
        break;
      case 4: //Secondary Save
        secondarySlotPos++;
        if(secondarySlotPos>slotLength) {
          secondarySlotPos=0;
        }
        strcpy_P(stringBuffer, (char *)pgm_read_word(&(slotMenu[secondarySlotPos])));
        updateScreen(1,stringBuffer);
        break;
      case 5: //Secondary Load
        secondarySlotPos++;
        if(secondarySlotPos>slotLength) {
          secondarySlotPos=0;
        }
        strcpy_P(stringBuffer, (char *)pgm_read_word(&(slotMenu[secondarySlotPos])));
        updateScreen(1,stringBuffer);
        break;
    }
    return;
  }

  if(stateDown==HIGH) { //DOWN
    timeoutMillis = millis();
    sure=0;
    switch(horizPos) {
      case 0: //Primary MIDI
        primaryMidiPos--;
        if(primaryMidiPos<0) {
          primaryMidiPos=midiLength;
        }
        strcpy_P(stringBuffer, (char *)pgm_read_word(&(midiMenu[primaryMidiPos])));
        updateScreen(1,stringBuffer);
        break;
      case 1: //Secondary MIDI
        secondaryMidiPos--;
        if(secondaryMidiPos<0) {
          secondaryMidiPos=midiLength;
        }
        strcpy_P(stringBuffer, (char *)pgm_read_word(&(midiMenu[secondaryMidiPos])));
        updateScreen(1,stringBuffer);
        break;
      case 2: //Primary Save
        primarySlotPos--;
        if(primarySlotPos<0) {
          primarySlotPos=slotLength;
        }
        strcpy_P(stringBuffer, (char *)pgm_read_word(&(slotMenu[primarySlotPos])));
        updateScreen(1,stringBuffer);
        break;
      case 3: //Primary Load
        primarySlotPos--;
        if(primarySlotPos<0) {
          primarySlotPos=slotLength;
        }
        strcpy_P(stringBuffer, (char *)pgm_read_word(&(slotMenu[primarySlotPos])));
        updateScreen(1,stringBuffer);
        break;
      case 4: //Secondary Save
        secondarySlotPos--;
        if(secondarySlotPos<0) {
          secondarySlotPos=slotLength;
        }
        strcpy_P(stringBuffer, (char *)pgm_read_word(&(slotMenu[secondarySlotPos])));
        updateScreen(1,stringBuffer);
        break;
      case 5: //Secondary Load
        secondarySlotPos--;
        if(secondarySlotPos<0) {
          secondarySlotPos=slotLength;
        }
        strcpy_P(stringBuffer, (char *)pgm_read_word(&(slotMenu[secondarySlotPos])));
        updateScreen(1,stringBuffer);
        break;
    }
    return;
  }

  if(stateBack==HIGH) { //BACK
    timeoutMillis = millis();
    if(sure==1) {
      sure=0;
      updateHorizPos();
    }
    return;
  }

  if(stateEnter==HIGH) { //ENTER
    timeoutMillis = millis();
    if(sure==0) {
      getCurrentPos(1);
      strcat(stringBuffer, " - Sure?");
      updateScreen(1,stringBuffer);
      sure=1;
      return;
    }

    if(sure==1) {
      sure=0;
      strcpy(stringBuffer, "Done!");
      updateScreen(1,stringBuffer);
      delay(300);
      getCurrentPos(1);
      updateScreen(1,stringBuffer);
      return;
    }
    
  }
  return;
}

//---------------------------------------------------------------------------------------------//
// function updateHorizPos
//
//---------------------------------------------------------------------------------------------//
void updateHorizPos() {
  getCurrentPos(0);
  updateScreen(0,stringBuffer);
  getCurrentPos(1);
  updateScreen(1,stringBuffer);
}

//---------------------------------------------------------------------------------------------//
// function getCurrentPos
//Returns the current position
//---------------------------------------------------------------------------------------------//
void getCurrentPos(int line) {
  if(line==0) {
    strcpy_P(stringBuffer, (char *)pgm_read_word(&(horizMenu[horizPos])));
  } else {
    switch(horizPos) {
      case 0:
        strcpy_P(stringBuffer, (char *)pgm_read_word(&(midiMenu[primaryMidiPos])));
        break;
      case 1:
        strcpy_P(stringBuffer, (char *)pgm_read_word(&(midiMenu[secondaryMidiPos])));
        break;
      case 2:
        strcpy_P(stringBuffer, (char *)pgm_read_word(&(slotMenu[primarySlotPos])));
        break;
      case 3:
        strcpy_P(stringBuffer, (char *)pgm_read_word(&(slotMenu[primarySlotPos])));
        break;
      case 4:
        strcpy_P(stringBuffer, (char *)pgm_read_word(&(slotMenu[secondarySlotPos])));
        break;
      case 5:
        strcpy_P(stringBuffer, (char *)pgm_read_word(&(slotMenu[secondarySlotPos])));
        break;
    }
  }
}

void updateFtrKbdVelo() {
  int result = 0;
  //0 is freq, 1 is Res 
  if(ftrKbd==false && ftrVelo==false) {
    result = 0;
  }
  if(ftrKbd==true && ftrVelo==false) { 
    result = 1;
  }
  if(ftrKbd==false && ftrVelo==true) {
    result = 2;
  }
  if(ftrKbd==true && ftrVelo==true) {
    result = 3;
  }
  MIDI.sendControlChange(CC_FilterKBDVeloControl, result, 1);
}