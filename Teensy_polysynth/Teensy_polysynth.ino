#include <MIDI.h>
#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

#include "audio_design.h"
#include "audio_setup.h"
#include "misc_setup.h"

//DEGUGS - Sends data over Serial
#define MIDI_DEBUG //received MIDI commands
//#define DEBUG_VOICES //Voice numbers
//#define DEBUG_RESOURCE //Teensy CPU/Mem usage
//#define DEBUG_EXP //Expression Pedal data

//#define DEBUG 1

#ifdef DEBUG_RESOURCE
  #define DEBUG_CYCLE_DURATION 50000
  unsigned int debugLastMicros = 0;
#endif

MIDI_CREATE_INSTANCE(HardwareSerial, Serial8, MIDI);
MIDI_CREATE_INSTANCE(HardwareSerial, Serial1, MIDI2);


//---------------------------------------------------------------------------------------------//
// Setup
//---------------------------------------------------------------------------------------------//
void setup() {
  AudioMemory(1024);

  //MIDI setup
  MIDI.begin(MIDI_CHANNEL_OMNI);
  MIDI.setHandleControlChange(controlChange);
  MIDI.setHandleNoteOn(turnNoteOn);
  MIDI.setHandleNoteOff(turnNoteOff);
  MIDI.setHandlePitchBend(pitchBend);
  MIDI.setHandleAfterTouchChannel(afterTouchChannel);
  MIDI2.begin(MIDI_CHANNEL_OMNI);
  MIDI2.setHandleControlChange(controlChange);
  MIDI2.setHandleNoteOn(turnNoteOn);
  MIDI2.setHandleNoteOff(turnNoteOff);
  MIDI2.setHandlePitchBend(pitchBend);
  MIDI2.setHandleAfterTouchChannel(afterTouchChannel);
  sgtl5000_1.enable();
  sgtl5000_1.volume(0.32);
  
  //initWaveshaper();
  loadControlVariables();
  for(int voice = 0; voice <=VOICES_ARRAY; voice++) { 
    loadSettings(voice);
  }

  initialiseSettings();
  startupJingle();
}

//---------------------------------------------------------------------------------------------//
// Main Loop
//---------------------------------------------------------------------------------------------//
void loop() {
  MIDI.read();
  MIDI2.read();

  #ifdef MIDI_DEBUG
    midiDebug(MIDI.getChannel(), MIDI.getType(), MIDI.getData1(), MIDI.getData2());
  #endif
  //checkMux();
  checkExpPedal();
  updateLFOLED();
  #ifdef DEBUG_RESOURCE
    //Report data every cycle duration
    int debugCurrentMicros = micros();
    if((debugCurrentMicros - debugLastMicros) > DEBUG_CYCLE_DURATION) {
      Serial.print("Audio CPU Usage: ");
      Serial.println(AudioProcessorUsageMax());
      Serial.print("Audio Memory Usage: ");
      Serial.println(AudioMemoryUsageMax());
      debugLastMicros = micros();
    }
  #endif
}

//---------------------------------------------------------------------------------------------//
// function controlChange
//---------------------------------------------------------------------------------------------//
void controlChange(byte channel, byte control, byte value) {
  switch(control) {
    //Attempting to use "undefined" MIDI CC Channels to minimise issues when using with multiple synced MIDI devices. Channels 100 and 101 are technically reserved so may need to change them if they cause conflicts   
    
    case CC_Portamento:
      if(secondaryControl&&secondaryEnabled) {
        secondPortamentoSpeed = (value * DIV127);
        secondPortamentoSpeed = (1000*pow(100,secondPortamentoSpeed-1));
      } else {
        portamentoSpeed = (value * DIV127);
        portamentoSpeed = (1000*pow(100,portamentoSpeed-1));
      }
      break;
    case CC_Polymode:
      if(value==0) {
        polyMode = true;
        for(int voice = 0; voice <numberOfVoices; voice++) { 
          oscillatorStop(voice);
          loadSettings(voice);
        }
      } else {
        polyMode=false;
      }
      for(int voice = 0; voice <numberOfVoices; voice++) { 
        oscillatorStop(voice);
        loadSettings(voice);
      }
      break;

    case CC_OscAWavetype:
      if(0<=value && value<=4) {
        if(secondaryControl&&secondaryEnabled) {
          secondOscAWaveform=value;
          switch(secondOscAWaveform) {
            case 0:
              oscA[secondaryVoice]->begin(WAVEFORM_SAWTOOTH);
              break;
            case 1:
              oscA[secondaryVoice]->begin(WAVEFORM_PULSE);
              break;
            case 2:
              oscA[secondaryVoice]->begin(WAVEFORM_TRIANGLE_VARIABLE);
              break;
            case 3:
              oscA[secondaryVoice]->begin(WAVEFORM_SINE);
              break;
            case 4:
              oscA[secondaryVoice]->begin(WAVEFORM_SAWTOOTH_REVERSE);
              break;
            }
        } else {
          oscAWaveform=value;
          for(int voice = 0; voice <numberOfVoices; voice++) {
            switch(oscAWaveform) {
            case 0:
              oscA[voice]->begin(WAVEFORM_SAWTOOTH);
              break;
            case 1:
              oscA[voice]->begin(WAVEFORM_PULSE);
              break;
            case 2:
              oscA[voice]->begin(WAVEFORM_TRIANGLE_VARIABLE);
              break;
            case 3:
              oscA[voice]->begin(WAVEFORM_SINE);
              break;
            case 4:
              oscA[voice]->begin(WAVEFORM_SAWTOOTH_REVERSE);
              break;
            }
          }
        }  
      }
      break;
    case CC_OscBWavetype:
      if(0<=value&& value<=4) {
        if(secondaryControl&&secondaryEnabled) {
          secondOscBWaveform=value;

          switch(secondOscBWaveform) {
            case 0:
              oscB[secondaryVoice]->begin(WAVEFORM_SAWTOOTH);
              break;
            case 1:
              oscB[secondaryVoice]->begin(WAVEFORM_PULSE);
              break;
            case 2:
              oscB[secondaryVoice]->begin(WAVEFORM_TRIANGLE_VARIABLE);
              break;
            case 3:
              oscB[secondaryVoice]->begin(WAVEFORM_SINE);
              break;
            case 4:
              oscB[secondaryVoice]->begin(WAVEFORM_SAWTOOTH_REVERSE);
              break; 
          }
        } else {
          oscBWaveform=value;

          for(int voice = 0; voice <=VOICES_ARRAY; voice++) { 
            switch(oscBWaveform) {
              case 0:
                oscB[voice]->begin(WAVEFORM_SAWTOOTH);
                break;
              case 1:
                oscB[voice]->begin(WAVEFORM_PULSE);
                break;
              case 2:
                oscB[voice]->begin(WAVEFORM_TRIANGLE_VARIABLE);
                break;
              case 3:
                oscB[voice]->begin(WAVEFORM_SINE);
                break;
              case 4:
                oscB[voice]->begin(WAVEFORM_SAWTOOTH_REVERSE);
                break; 
            }
          }
        }
      }
      break;
    case CC_OscADetune:
      if(secondaryControl&&secondaryEnabled) { 
        secondOscADetune = (((value * DIV127) - 0.5)*DETUNE_MAX);
        for(int voice = 0; voice <=VOICES_ARRAY; voice++) { 
          dcPitchDetuneA[secondaryVoice]->amplitude(secondOscADetune);
        } 
      }else {
        oscADetune = (((value * DIV127) - 0.5)*DETUNE_MAX);
        for(int voice = 0; voice <=VOICES_ARRAY; voice++) { 
          dcPitchDetuneA[voice]->amplitude(oscADetune);
        }
      }  
      break;
    case CC_OscBDetune:
      if(secondaryControl&&secondaryEnabled) { 
        secondOscBDetune = (((value * DIV127) - 0.5)*DETUNE_MAX);
        for(int voice = 0; voice <=VOICES_ARRAY; voice++) { 
          dcPitchDetuneB[secondaryVoice]->amplitude(secondOscBDetune);
        } 
      }else {
        oscBDetune = (((value * DIV127) - 0.5)*DETUNE_MAX);
        for(int voice = 0; voice <numberOfVoices; voice++) { 
          dcPitchDetuneB[voice]->amplitude(oscBDetune);
        }
      }
      break;
    case CC_OscVibrato:
      if(secondaryControl&&secondaryEnabled) { 
        secondOscLFOFreq = ((value * DIV127) * DETUNE_MAX);
        lfoFreq[secondaryVoice]->gain(secondOscLFOFreq);
      } else {
        oscLFOFreq = ((value * DIV127) * DETUNE_MAX);
          for(int voice = 0; voice <numberOfVoices; voice++) { 
            lfoFreq[voice]->gain(oscLFOFreq);
        }
      }
      break;
    case CC_OscAOctave:
      if(secondaryControl&&secondaryEnabled) { 
        switch(value) {
          case 0: //+2 Octave
            secondOscAOctave = 0.2;
            break;
          case 1: //+1 Octave
            secondOscAOctave = 0.1;
            break;
          case 2: //0 Octave
            secondOscAOctave = 0;
            break;
          case 3: //-1 Octave
            secondOscAOctave = -0.1;
            break;
          case 4: //-2 Octave
            secondOscAOctave = -0.2;
            break;
        }
        for(int voice = 0; voice <numberOfVoices; voice++) { 
          dcPitchOctaveA[secondaryVoice]->amplitude(secondOscAOctave);
        }
      } else {
        switch(value) {
          case 0: //+2 Octave
            oscAOctave = 0.2;
            break;
          case 1: //+1 Octave
            oscAOctave = 0.1;
            break;
          case 2: //0 Octave
            oscAOctave = 0;
            break;
          case 3: //-1 Octave
            oscAOctave = -0.1;
            break;
          case 4: //-2 Octave
            oscAOctave = -0.2;
            break;
        }
        for(int voice = 0; voice <numberOfVoices; voice++) { 
          dcPitchOctaveA[voice]->amplitude(oscAOctave);
        }
      }
      
      break;
    case CC_OscBOctave:
      if(secondaryControl&&secondaryEnabled) { 
        switch(value) {
          case 0: //+2 Octave
            secondOscBOctave = 0.2;
            break;
          case 1: //+1 Octave
            secondOscBOctave = 0.1;
            break;
          case 2: //0 Octave
            secondOscBOctave = 0;
            break;
          case 3: //-1 Octave
            secondOscBOctave = -0.1;
            break;
          case 4: //-2 Octave
            secondOscBOctave = -0.2;
            break;
        }
        for(int voice = 0; voice <numberOfVoices; voice++) { 
          dcPitchOctaveB[secondaryVoice]->amplitude(secondOscBOctave);
        }
      } else {
        switch(value) {
          case 0: //+2 Octave
            oscBOctave = 0.2;
            break;
          case 1: //+1 Octave
            oscBOctave = 0.1;
            break;
          case 2: //0 Octave
            oscBOctave = 0;
            break;
          case 3: //-1 Octave
            oscBOctave = -0.1;
            break;
          case 4: //-2 Octave
            oscBOctave = -0.2;
            break;
        }
        for(int voice = 0; voice <numberOfVoices; voice++) { 
          dcPitchOctaveB[voice]->amplitude(oscBOctave);
        }
      }
      break;
    
    case CC_OscAPulseWidth:
      if(secondaryControl&&secondaryEnabled) { 
        if(value!=0 || value!= 127) {
          secondOscAPulseWidth = ((value *DIV127)*2)-1;
          dcOscPWA[secondaryVoice]->amplitude(secondOscAPulseWidth);
        }
      } else {
        if(value!=0 || value!= 127) {
          oscAPulseWidth = ((value *DIV127)*2)-1;
          for(int voice = 0; voice <numberOfVoices; voice++) {
            dcOscPWA[voice]->amplitude(oscAPulseWidth);
          }
        }
      }
      break;
    case CC_OscBPulseWidth:
      if(secondaryControl&&secondaryEnabled) { 
        if(value!=0 || value!= 127) {
          secondOscBPulseWidth = ((value *DIV127)*2)-1;
          dcOscPWB[secondaryVoice]->amplitude(secondOscBPulseWidth);
        }
      } else {
        if(value!=0 || value!= 127) {
          oscBPulseWidth = ((value *DIV127)*2)-1;
          for(int voice = 0; voice <numberOfVoices; voice++) {
            dcOscPWB[voice]->amplitude(oscBPulseWidth);
          }
        }
      }
      break;
    case CC_OscPulseWidthMod:
      if(secondaryControl&&secondaryEnabled) { 
        secondOscPWM = (value * DIV127);
        lfoPW[secondaryVoice]->gain(secondOscPWM);
      } else {
        oscPWM = (value * DIV127);
        for(int voice = 0; voice <numberOfVoices; voice++) { 
          lfoPW[voice]->gain(oscPWM);
        }
      }
      break;
    case CC_MixerOscA:
      if(secondaryControl&&secondaryEnabled) { 
        secondOscAVol = (value * DIV127);
        mixerOsc[secondaryVoice]->gain(0,(mixerOscGain * secondOscAVol));
      }else {
        oscAVol = (value * DIV127);
        for(int voice = 0; voice <numberOfVoices; voice++) { 
          mixerOsc[voice]->gain(0,(mixerOscGain * oscAVol));
        }
      }
        
      break;
    case CC_MixerOscB: 
      if(secondaryControl&&secondaryEnabled) { 
        secondOscBVol = (value * DIV127);
        mixerOsc[secondaryVoice]->gain(1,(mixerOscGain * secondOscBVol));
      } else {
        oscBVol = (value * DIV127);
        for(int voice = 0; voice <numberOfVoices; voice++) { 
          mixerOsc[voice]->gain(1,(mixerOscGain * oscBVol));
        }
      }
      break;
    case CC_MixerPink: 
      if(secondaryControl&&secondaryEnabled) { 
        secondPinkVol = (value * DIV127);
        mixerOsc[secondaryVoice]->gain(2,(mixerOscGain * secondPinkVol));
      } else {
        pinkVol = (value * DIV127);
        for(int voice = 0; voice <numberOfVoices; voice++) { 
          mixerOsc[voice]->gain(2,(mixerOscGain * pinkVol));
        }
      }
      break;
    case CC_EnvVolumeAttack:
      //Conversion to logarithmic for more control over lower values
      if(secondaryControl&&secondaryEnabled) { 
        secondEnvelopeVolAttack = (value * DIV127);
        secondEnvelopeVolAttack = pow(100,(secondEnvelopeVolAttack-1));
        secondEnvelopeVolAttack = (3000 *secondEnvelopeVolAttack);  
        envelopeVol[secondaryVoice]->attack(secondEnvelopeVolAttack); 
      } else {
        envelopeVolAttack = (value * DIV127);
        envelopeVolAttack = pow(100,(envelopeVolAttack-1));
        envelopeVolAttack = (3000 *envelopeVolAttack);
        for(int voice = 0; voice <numberOfVoices; voice++) { 
          envelopeVol[voice]->attack(envelopeVolAttack);
        }
      }
      break;
    
    case CC_EnvVolumeDecay: 
      if(secondaryControl&&secondaryEnabled) { 
        secondEnvelopeVolDecay= (3000 * (value * DIV127));
        envelopeVol[secondaryVoice]->decay(secondEnvelopeVolDecay);
      } else {
        envelopeVolDecay= (3000 * (value * DIV127));
        for(int voice = 0; voice <numberOfVoices; voice++) { 
          envelopeVol[voice]->decay(envelopeVolDecay);
        }
      }
      break;
    case CC_EnvVolumeSustain:
      if(secondaryControl&&secondaryEnabled) { 
        secondEnvelopeVolSustain = (value * DIV127);
        envelopeVol[secondaryVoice]->sustain(secondEnvelopeVolSustain);
      } else {
        envelopeVolSustain = (value * DIV127);
        for(int voice = 0; voice <numberOfVoices; voice++) { 
          envelopeVol[voice]->sustain(envelopeVolSustain);
        }
      }
      
      break;
    case CC_EnvVolumeRelease:
      if(secondaryControl&&secondaryEnabled) { 
        secondEnvelopeVolRelease = (3000 * (value * DIV127));
        envelopeVol[secondaryVoice]->release(secondEnvelopeVolRelease);
      }else {
        envelopeVolRelease = (3000 * (value * DIV127));
        for(int voice = 0; voice <numberOfVoices; voice++) { 
          envelopeVol[voice]->release(envelopeVolRelease);
        }
      }
      break;

    case CC_EnvFilterDelay:
      if(secondaryControl&&secondaryEnabled) { 
        secondEnvelopeFilterDelay = (3000 * (value * DIV127));
        envelopeFilter[secondaryVoice]->delay(secondEnvelopeFilterDelay);
      }else {
        envelopeFilterDelay = (3000 * (value * DIV127));
        for(int voice = 0; voice <numberOfVoices; voice++) { 
          envelopeFilter[voice]->delay(envelopeFilterDelay);
        }
      }
        
      break;
    case CC_EnvFilterAttack:
      if(secondaryControl&&secondaryEnabled) { 
        secondEnvelopeFilterAttack = (3000 * (value * DIV127));
        envelopeFilter[secondaryVoice]->attack(secondEnvelopeFilterAttack);
      }else {
        envelopeFilterAttack = (3000 * (value * DIV127));
        for(int voice = 0; voice <numberOfVoices; voice++) { 
          envelopeFilter[voice]->attack(envelopeFilterAttack);
        }
      }
      
      break;
    case CC_EnvFilterDecay:
      if(secondaryControl&&secondaryEnabled) { 
        secondEnvelopeFilterDecay = (3000 * (value * DIV127));
        envelopeFilter[secondaryVoice]->decay(secondEnvelopeFilterDecay);
      } else {
        envelopeFilterDecay = (3000 * (value * DIV127));
        for(int voice = 0; voice <numberOfVoices; voice++) { 
          envelopeFilter[voice]->decay(envelopeFilterDecay);
        }
      }
      
      break;
    case CC_EnvFilterSustain:
      if(secondaryControl&&secondaryEnabled) { 
        secondEnvelopeFilterSustain = (value * DIV127);
        envelopeFilter[secondaryVoice]->sustain(secondEnvelopeFilterSustain);
      }else {
        envelopeFilterSustain = (value * DIV127);
        for(int voice = 0; voice <numberOfVoices; voice++) { 
          envelopeFilter[voice]->sustain(envelopeFilterSustain);
        }
      }
      
      break;
    case CC_EnvFilterRelease:
      if(secondaryControl&&secondaryEnabled) { 
        secondEnvelopeFilterRelease = (3000 * (value * DIV127));
        envelopeFilter[secondaryVoice]->release(secondEnvelopeFilterRelease);
      } else {
        envelopeFilterRelease = (3000 * (value * DIV127));
        for(int voice = 0; voice <numberOfVoices; voice++) { 
          envelopeFilter[voice]->release(envelopeFilterRelease);
        }
      }

      break;
    case CC_FilterFreq:
      if(secondaryControl&&secondaryEnabled) { 
        secondFilterFreq = (20000 * (value * DIV127));
        ladder[secondaryVoice]->frequency(secondFilterFreq);
      }else {
        filterFreq = (20000 * (value * DIV127));
        for(int voice = 0; voice <numberOfVoices; voice++) { 
          ladder[voice]->frequency(filterFreq);
        }
      }     
      break;
    case CC_FilterRes:
      if(secondaryControl&&secondaryEnabled) { 
        secondFilterRes = (1.8 * (value * DIV127));
        ladder[secondaryVoice]->resonance(secondFilterRes);
      } else {
        filterRes = (1.8 * (value * DIV127));
        for(int voice = 0; voice <numberOfVoices; voice++) { 
          ladder[voice]->resonance(filterRes);
        }
      }
      break;
    case CC_FilterEnv:
      if(secondaryControl&&secondaryEnabled) { 
        secondFilterEnvFreq = (value * DIV127);
        dcFilterEnv[secondaryVoice]->amplitude(secondFilterEnvFreq);
      } else {
        filterEnvFreq = (value * DIV127);
        for(int voice = 0; voice <numberOfVoices; voice++) {
          dcFilterEnv[voice]->amplitude(filterEnvFreq);
        }
      }
      
      break;
    case CC_FilterKeyboard:
      //Controls how much of the Kbd frequency change can effect the filter. 
      if(secondaryControl&&secondaryEnabled) { 
        secondFilterKbd = (value * DIV127);
        filterSetKbdVelControl(secondaryVoice);
      } else {
        filterKbd = (value * DIV127);
        for(int voice = 0; voice <numberOfVoices; voice++) { 
          filterSetKbdVelControl(voice);
        }
      }
      break;
    case CC_FilterVelocity:
       if(secondaryControl&&secondaryEnabled) { 
        secondFilterVel = (value * DIV127);
        filterSetKbdVelControl(secondaryVoice);
       } else {
        filterVel = (value * DIV127);
        for(int voice = 0; voice <numberOfVoices; voice++) {
          filterSetKbdVelControl(voice);
        }
       }
     
     break;
    case CC_FilterKBDVeloControl:
      if(secondaryControl&&secondaryEnabled) { 
        secondFilterKbdVelControl = value;
        filterSetKbdVelControl(secondaryVoice);       
      }else {
        filterKbdVelControl = value;
        for(int voice = 0; voice <numberOfVoices; voice++) {
          filterSetKbdVelControl(voice);       
        }
      }
      break;
    case CC_FilterLFO:
      if(secondaryControl&&secondaryEnabled) { 
        secondFilterLFOFreq = (value*DIV127);
        lfoFilterFreq[secondaryVoice]->gain(secondFilterLFOFreq);
      }else {
        filterLFOFreq = (value*DIV127);
        for(int voice = 0; voice <numberOfVoices; voice++) { 
          lfoFilterFreq[voice]->gain(filterLFOFreq);
        }
      }
      break;
    case CC_LFOWavetype:
      if(secondaryControl&&secondaryEnabled) { 
        secondLfoWaveform = value;
        switch(value) {
          case 0:
            secondaryLfo.begin(WAVEFORM_SINE);
            break;
          case 1:
            secondaryLfo.begin(WAVEFORM_PULSE);
            break;
          case 2:
            secondaryLfo.begin(WAVEFORM_TRIANGLE_VARIABLE);
            break;
          case 3:
            secondaryLfo.begin(WAVEFORM_SAWTOOTH);
            break;
          case 4:
            secondaryLfo.begin(WAVEFORM_SAWTOOTH_REVERSE);
            break;
        }
      } else {
        lfoWaveform = value;
        switch(value) {
          case 0:
            lfo.begin(WAVEFORM_SINE);
            break;
          case 1:
            lfo.begin(WAVEFORM_PULSE);
            break;
          case 2:
            lfo.begin(WAVEFORM_TRIANGLE_VARIABLE);
            break;
          case 3:
            lfo.begin(WAVEFORM_SAWTOOTH);
            break;
          case 4:
            lfo.begin(WAVEFORM_SAWTOOTH_REVERSE);
            break;
        }
      }
      break;
    case CC_LFOSpeed: //Voice settings End
      if(secondaryControl&&secondaryEnabled) { 
        secondLfoSpeed = (value * DIV127);
        secondLfoSpeed = (LFO_SPEED_MAX * pow(100,(secondLfoSpeed-1)));
        secondaryLfo.frequency(secondLfoSpeed);
      } else {
        lfoSpeed = (value * DIV127);
        lfoSpeed = (LFO_SPEED_MAX * pow(100,(lfoSpeed-1)));
        lfo.frequency(lfoSpeed);
      }
      
      break;
    case CC_ModWheel:
      modWheelPos = (value * DIV127);
      switch(modWheelSetting) {
        case 0: //Vibrato
          for(int voice = 0; voice <=VOICES_ARRAY; voice++) { 
            lfoFreq[voice]->gain(modWheelPos * DETUNE_MAX);
          }
          break;
        case 1: //LFO Speed
          lfo.frequency(modWheelPos * LFO_SPEED_MAX);
          break;
        case 2: //Porta
            portamentoSpeed = (1000*pow(100,modWheelPos-1));
          break;
        case 3: //Filter Frequency
          for(int voice = 0; voice <=VOICES_ARRAY; voice++) { 
            ladder[voice]->frequency(20000 * modWheelPos);
          }
          break;
        case 4: //Filter LFO
          for(int voice = 0; voice <=VOICES_ARRAY; voice++) { 
            lfoFilterFreq[voice]->gain(modWheelPos);
          }
          break; 
        
        case 5: //Volume
          masterVolL.gain(0, modWheelPos);
          masterVolR.gain(0, modWheelPos);
          break;
        //Note Controls only go up to 5 so this should never trigger, saving for if I decide to reimplement
        case 6: //Tremolo
          tremoloDepth = modWheelPos;
          updateTremolo();
          break;
      }
      break;
    case CC_ModWheelMode: 
      modWheelSetting = value;
      break;
    case CC_ExpPedalMode: 
      expPedalSetting = value;
      break;
    case CC_AftertouchMode:
      aftertouchSetting = value;
      break;
    case CC_PitchBendAmount:
      if(0<value && value <=12) {
        bendRange = value;
      }
      break;
    case CC_ChannelMain:
      midiChannelMain = value;
      break;
    case CC_SecondaryChannel:
      midiChannelSecondary = value;
      break;
    case CC_SecondaryEnable:
      if (value==0) {
        secondaryEnabled = false;
      } else {
        secondaryEnabled = true;
      }


      if(secondaryEnabled) {
        secondaryVol.gain(secondaryVolume);
        numberOfVoices = VOICES_SECONDARY;
        oscillatorStop(secondaryVoice);

        //Master LFO on voice 7, enable secondary
        mixerLfoMaster7.gain(0,0);
        mixerLfoMaster7.gain(1,1);


      } else {
        numberOfVoices = VOICES;
        secondaryVol.gain(1);

        //Re-engage Master LFO on voice 7
        mixerLfoMaster7.gain(0,1);
        mixerLfoMaster7.gain(1,0);
        loadSettings(secondaryVoice);
        oscillatorStop(secondaryVoice);
      }

      if(secondaryBypassFx && secondaryEnabled) {
        masterVolL.gain(1,1);
        masterVolR.gain(1,1);

        bypassFx7.gain(0);
        bypassLeslie7.gain(0);
      } else {
        masterVolL.gain(1,0);
        masterVolR.gain(1,0);

        bypassFx7.gain(1);
        bypassLeslie7.gain(1);
      }
      
      break;
    case CC_SecondaryControl:
      if(value ==0) {
        secondaryControl = false;
      } else {
        secondaryControl = true;
      }
      break;
    case CC_SecondaryBypass:
      if(value ==0) {
        secondaryBypassFx = false;
      } else {
        secondaryBypassFx = true;
      }

      if(secondaryBypassFx && secondaryEnabled) {
        masterVolL.gain(1,1);
        masterVolR.gain(1,1);

        bypassFx7.gain(0);
        bypassLeslie7.gain(0);
      } else {
        masterVolL.gain(1,0);
        masterVolR.gain(1,0);

        bypassFx7.gain(1);
        bypassLeslie7.gain(1);
      }
      break;
    case CC_PhaserWet: 
      phaserWet=(value * DIV127);
      mixerPhaserL.gain(0,1-phaserWet);
      mixerPhaserL.gain(1,phaserWet);
      mixerPhaserR.gain(0,1-phaserWet);
      mixerPhaserR.gain(1,phaserWet);
      if(phaserWet==0) {
        phaserL.bypass(true);
        phaserR.bypass(true);
      } else {
        phaserL.bypass(false);
        phaserR.bypass(false);
      }
      break;
    case CC_PhaserSpeed: 
      phaserSpeed = (value * DIV127);
      phaserSpeed = (PHASER_MAX_SPEED * pow(100,(phaserSpeed-1)));
      phaserL.lfo_rate(phaserSpeed);
      phaserR.lfo_rate(phaserSpeed);
      break;
    case CC_PhaserFeedback: 
      phaserFeedback = (value * DIV127);
      phaserL.feedback(PHASER_MAX_FBDB*phaserFeedback);
      phaserR.feedback(PHASER_MAX_FBDB*phaserFeedback);
      break;
    case CC_ChorusWet: 
      chorusWet = value * DIV127;
      mixerChorusL.gain(0,1-chorusWet);
      mixerChorusL.gain(1,chorusWet);
      mixerChorusR.gain(0,1-chorusWet);
      mixerChorusR.gain(1,chorusWet);
      break;
    case CC_TremoloWavetype: 
      tremoloWavetype = value;
      switch(tremoloWavetype) {
        case 0:
          tremoloLFO.begin(WAVEFORM_SINE);
          break;
        case 1:
          tremoloLFO.begin(WAVEFORM_PULSE);
          break;
        case 2:
          tremoloLFO.begin(WAVEFORM_TRIANGLE_VARIABLE);
          break;
        case 3:
          tremoloLFO.begin(WAVEFORM_SAWTOOTH);
          break;
        case 4:
          tremoloLFO.begin(WAVEFORM_SAWTOOTH_REVERSE);
          break;
      }
      break;
    case CC_TremoloSpeed: 
      tremoloSpeed = (value * DIV127);
      tremoloSpeed = (TREM_MAX_SPEED * pow(100,(tremoloSpeed-1)));
      updateTremolo();
      break;
    case CC_TremoloDepth: 
      tremoloDepth = (value * DIV127);
      updateTremolo();
      break;
    case CC_DelayLevel: 
      delayLevel = (value * DIV127);
      mixerDelayLB.gain(1,delayLevel);
      mixerDelayRB.gain(1,delayLevel);
      break;
    case CC_DelayInputLevel:
      delayInputLevel = (value * DIV127);
      mixerPreDelayL.gain(0,delayInputLevel);
      mixerPreDelayR.gain(0,delayInputLevel);
      break;
    case CC_DelayTime:
      delayTime = DELAY_MAX_TIME * (value  * DIV127);
      delayL.delay(0,delayTime);
      delayR.delay(0,delayTime);
      break;
    case CC_DelayFeedback:
      delayFeedback = (value * DIV127);
      delayFeedbackL.gain(delayFeedback);
      delayFeedbackR.gain(delayFeedback);
      break;

    case CC_ReverbSize:
      reverbRoomsize = (value * DIV127);
      freeverbL.roomsize(reverbRoomsize);
      freeverbR.roomsize(reverbRoomsize);
      break;
    case CC_ReverbDamping: 
      reverbDamping = (value * DIV127);
      freeverbL.damping(reverbDamping);
      freeverbR.damping(reverbDamping);
      break;
    case CC_ReverbWet: 
      reverbWet = (value * DIV127);
      //mixerReverbL.gain(0, 1-reverbWet);
      mixerReverbL.gain(1, reverbWet);
      //mixerReverbR.gain(0, 1-reverbWet);
      mixerReverbR.gain(1, reverbWet);
      break;
    case CC_LeslieSpeed:
      panSpeed = (value * DIV127);
      panSpeed = (PAN_MAX_SPEED * pow(100,(panSpeed-1)));
      updatePan();
      break;
    case CC_LeslieDepth: 
      panDepth = value * DIV127;
      updatePan();
      break;

    case CC_SecondaryVolume:
      if(secondaryEnabled) {
        secondaryVolume = (value * DIV127);
        secondaryVol.gain(secondaryVolume);
      }
      
      break;
    case CC_MasterVol:
      masterVolLeft = value * DIV127;
      masterVolRight = value * DIV127;
      masterVolL.gain(0, masterVolLeft);
      masterVolR.gain(0, masterVolRight);
      break;
  }
}

//---------------------------------------------------------------------------------------------//
// function turnNoteOn
//---------------------------------------------------------------------------------------------//
void turnNoteOn(byte channel, byte note, byte velocity) {
  //set upper & lower note limits. Outside of this range sounds bad

  if(channel==midiChannelMain|| channel==midiChannelSecondary) {
    if (note >MIN_NOTE && note <MAX_NOTE) {
      keyBuffer(channel, note, velocity, true);
    } 
  }
  
}

//---------------------------------------------------------------------------------------------//
// function turnNoteOff
//---------------------------------------------------------------------------------------------//
void turnNoteOff (byte channel, byte note, byte velocity) {
  if(channel==midiChannelMain|| channel==midiChannelSecondary) {
    if ( note > 23 && note < 108 ) {
      keyBuffer(channel, note, velocity, false);
    }
  }
}

//---------------------------------------------------------------------------------------------//
// function keyBuffer
//---------------------------------------------------------------------------------------------//
void keyBuffer(byte channel, byte note, float velocity, bool playNote) {

  if(channel==midiChannelMain) {
    if (polyMode) {
      static byte voices[VOICES];
      if(playNote) { //NOTE ON
        /*
        Checks if current voice note value is zero (ie not playing something). 
        If it is not, iterates through each voice until it finds an empty one. If all voices are playing then it overwrites the original current voice.
        This allows a note to be held indefitely as long as it doesn't run out of voices to assign new notes to, at which point it will overwrite the oldest voice.  
        */
        for(int findEmptyVoice = 0; findEmptyVoice <numberOfVoices; findEmptyVoice++) {
          if(voices[currentVoice]!=0) {
            currentVoice++;
            if(currentVoice>=numberOfVoices){
              currentVoice=0;
            } 
          } else {
            break;
          }
        }
        voices[currentVoice] = note;
        oscillatorPlay(note, currentVoice, velocity);
        filterSetKbdVel(currentVoice, note, velocity);
        #ifdef DEBUG_VOICES
          Serial.print("Voice: ");
          Serial.println(currentVoice);
        #endif
        currentVoice++;
        if(currentVoice>=numberOfVoices) {
          currentVoice=0;
        }
      
      } else if(playNote==false) { //NOTE OFF
        //Increment through voices[], check note disabled and turn off that voice
        for (byte found = 0; found <numberOfVoices; found ++) {
          if(voices[found]==note) {
            oscillatorStop(found);
            voices[found] = 0;
          }
        }
      }  
    } else {
      static byte monoBuffer[MONO_BUFFER];
      static float veloBuffer[MONO_BUFFER];
      static byte monoBufferSize =0;
      static float lastNote = 0;
      static float lastVelo = 0;
      if(velocity!=0) {
        oscVelocity = velocity;
      }
   
      //Add note to buffer
      if (playNote ==true &&(monoBufferSize < MONO_BUFFER)) {
        monoBuffer[monoBufferSize]=note;
        veloBuffer[monoBufferSize]=velocity;
        oscillatorPlayPorta(0, note, lastNote, velocity);
        lastNote = note;
        //oscillatorPlayPorta(0, note, monoBuffer[monoBufferSize-1], velocity);
        filterSetKbdVel(0, note, velocity);
        monoBufferSize++;
        return;
      }

      //Remove note
      else if(playNote == false && monoBufferSize!=0) {
        //increment through buffer looking for note, if match set to found
        for (byte found = 0; found <monoBufferSize; found ++) {
          if (monoBuffer[found] == note ) {
            //Once found, move remaining notes up in buffer, overwriting found value
            for (byte gap = found; gap < (monoBufferSize-1); gap++) {
              monoBuffer[gap]=monoBuffer[gap+1];
              veloBuffer[gap]=veloBuffer[gap+1];
            }
            monoBufferSize--;
            //Return to base, triggger last note in buffer
            if(monoBufferSize!=0) {
              //oscillatorPlayPorta(0, monoBuffer[monoBufferSize-1], monoBuffer[monoBufferSize], veloBuffer[monoBufferSize-1]);
              oscillatorPlayPorta(0, monoBuffer[monoBufferSize-1], lastNote, veloBuffer[monoBufferSize-1]);
              return;
            } 
            else {
              //buffer empty, stop oscillators
              oscillatorStop(0);
              return;
            }
          }
        }
      }
    } 
  }else if(channel==midiChannelSecondary&&secondaryEnabled) {
      static byte secondBuffer[SECOND_BUFFER];
      static float secondVeloBuffer[SECOND_BUFFER];
      static byte secondBufferSize =0;
      if(velocity!=0) {
        secondOscVelocity = velocity;
      }
   
      //Add note to buffer
      if (playNote ==true &&(secondBufferSize < SECOND_BUFFER)) {
        secondBuffer[secondBufferSize]=note;
        secondVeloBuffer[secondBufferSize]=velocity;
        oscillatorPlayPorta(secondaryVoice, note, secondBuffer[secondBufferSize-1], velocity);
        filterSetKbdVel(secondaryVoice, note, velocity);
        secondBufferSize++;
        return;
      }

      //Remove note
      else if(playNote == false && secondBufferSize!=0) {
        //increment through buffer looking for note, if match set to found
        for (byte found = 0; found <secondBufferSize; found ++) {
          if (secondBuffer[found] == note ) {
            //Once found, move remaining notes up in buffer, overwriting found value
            for (byte gap = found; gap < (secondBufferSize-1); gap++) {
              secondBuffer[gap]=secondBuffer[gap+1];
              secondVeloBuffer[gap]=secondVeloBuffer[gap+1];
            }
            secondBufferSize--;
            //Return to base, triggger last note in buffer
            if(secondBufferSize!=0) {
              oscillatorPlayPorta(secondaryVoice, secondBuffer[secondBufferSize-1], secondBuffer[secondBufferSize], secondVeloBuffer[secondBufferSize-1]);
              return;
            } 
            else {
              //buffer empty, stop oscillators
              oscillatorStop(secondaryVoice);
              return;
            }
          }
        }
      }
    }
  
}
//---------------------------------------------------------------------------------------------//
// function Oscillator Play
//---------------------------------------------------------------------------------------------//
void oscillatorPlay(byte note, int voice, float amplitude) {
  oscA[voice]->frequency(noteFreqs[note]);
  oscB[voice]->frequency(noteFreqs[note]);

  oscA[voice]->amplitude(amplitude * DIV127);
  oscB[voice]->amplitude(amplitude * DIV127);
  pink[voice]->amplitude(amplitude * DIV127);

  envelopeVol[voice]->noteOn();
  envelopeFilter[voice]->noteOn();
}

//---------------------------------------------------------------------------------------------//
// function Oscillator Play, with Portamento
//---------------------------------------------------------------------------------------------//
void oscillatorPlayPorta(int voice, byte note, byte previousNote, float velocity) {
  if(previousNote!=0) {
    //Slide Note
    double slideValueNote = note - previousNote; //Number of semitones changed
    slideValueNote = 0-((slideValueNote * DIV12) * 0.1);     //Convert to 0.1 V/Oct

    if (voice==0) {
      dcPorta0.amplitude(slideValueNote);
      dcPorta0.amplitude(0, portamentoSpeed); 
    } else {
      dcPorta7.amplitude(slideValueNote);
      dcPorta7.amplitude(0, secondPortamentoSpeed); 
    }
       
  }
    
  oscA[voice]->frequency(noteFreqs[note]);
  oscB[voice]->frequency(noteFreqs[note]);

  oscA[voice]->amplitude(velocity * DIV127);
  oscB[voice]->amplitude(velocity * DIV127);
  pink[voice]->amplitude(velocity * DIV127);

  envelopeVol[voice]->noteOn();
  envelopeFilter[voice]->noteOn();

}

//---------------------------------------------------------------------------------------------//
// function Oscillator Stop
//---------------------------------------------------------------------------------------------//
void oscillatorStop(int voice) {
  envelopeVol[voice]->noteOff();
  envelopeFilter[voice]->noteOff();
}

//---------------------------------------------------------------------------------------------//
// function pitchBend
//---------------------------------------------------------------------------------------------//
void pitchBend(byte channel, int bend) {
 float bendFactor=bend;
  //"DC" Frequency modulation is set to 0.1v/Oct, so divide by 0.1, then multiply bendRange/12 to shift by the desired number of semitones
  //Pitch bend info comes in as +-8192 rather than 0 - 16383
  bendFactor = bendFactor/8192;
  bendFactor = ((bendFactor * 0.1)/12)*bendRange; 
  
  for(int voice=0; voice <=VOICES_ARRAY; voice ++) {
    dcPitchBend[voice]->amplitude(bendFactor);
  }
}

//---------------------------------------------------------------------------------------------//
// function aftertouch (Channel wide)
//---------------------------------------------------------------------------------------------//
void afterTouchChannel(byte channel, byte pressure) {
  float aftertouchPressure = (pressure * DIV127);
  switch(aftertouchSetting) {
    case 0: //Disable
        
      break;
    case 1: //Vibrato
      for(int voice = 0; voice <=VOICES_ARRAY; voice++) {
          lfoFreq[voice]->gain(0.005*aftertouchPressure);
        }
      break;
    case 2: //Filter LFO
      for(int voice = 0; voice <=VOICES_ARRAY; voice++) {
          lfoFilterFreq[voice]->gain(0.5*aftertouchPressure);
        }
      break;
    case 3: //Filter Freq
      for(int voice = 0; voice <=VOICES_ARRAY; voice++) {
        dcFilterAft[voice]->amplitude(aftertouchPressure);
      }
      break;
    case 4: //Delay Level
      aftertouchPressure = aftertouchPressure * (1-delayInputLevel);

      mixerPreDelayL.gain(0,delayInputLevel+aftertouchPressure);
      mixerPreDelayR.gain(0,delayInputLevel+aftertouchPressure);
      break;
    case 5: 
      
      break;      
  }
}

//---------------------------------------------------------------------------------------------//
// function filterSetKbdVel
//---------------------------------------------------------------------------------------------//
//Note that ordinarily modulation is performed on the DC, in this case the controls dictate mixer gain and DC is instead modulated by note/velocity. 
void filterSetKbdVel(int voice, byte note, float velocity) {
  
  if(voice==secondaryVoice&& secondaryEnabled) {

    //Calculate as 0-1 range, then extendto +-1 range;
    float kbdAmount =DIV85 * (note-MIN_NOTE);
    kbdAmount = (kbdAmount-0.5);

    dcFilterKbd[voice]->amplitude(kbdAmount);
    if(secondFilterKbdVelControl==0 || secondFilterKbdVelControl==1) {
      //Controls Filter
      dcFilterVel[voice]->amplitude(((velocity * DIV127)-1));
    } else {
      //Control Resonance
      dcFilterVel[voice]->amplitude((velocity * DIV127));
    }
  }else {
    //Calculate as 0-1 range, then extendto +-1 range;
    float kbdAmount =DIV85 * (note-MIN_NOTE);
    kbdAmount = (kbdAmount-0.5);

    dcFilterKbd[voice]->amplitude(kbdAmount);
    if(filterKbdVelControl==0 || filterKbdVelControl==1) {
      //Controls Filter
      dcFilterVel[voice]->amplitude(((velocity * DIV127)-1));
    } else {
      //Control Resonance
      dcFilterVel[voice]->amplitude((velocity * DIV127));
    }
  }
  
}

//---------------------------------------------------------------------------------------------//
// function filterSetKbdVelControl
//---------------------------------------------------------------------------------------------//
void filterSetKbdVelControl(int voice) {
  
  int control;
  if (secondaryEnabled) {
    switch (secondFilterKbdVelControl) {
      case 0: //KBD Freq, Vel Freq
        mixerFilterFreqA[voice]->gain(3,secondFilterKbd);
        mixerFilterFreqB[voice]->gain(1,secondFilterVel);
        mixerFilterRes[voice]->gain(0,0);
        mixerFilterRes[voice]->gain(1,0);
        break;
      case 1: //KBD Res, Vel Freq
        mixerFilterFreqA[voice]->gain(3,0);
        mixerFilterFreqB[voice]->gain(1,secondFilterVel);
        mixerFilterRes[voice]->gain(0,secondFilterKbd);
        mixerFilterRes[voice]->gain(1,0);
        break;
      case 2: //KBD Freq, Vel Res
        mixerFilterFreqA[voice]->gain(3,secondFilterKbd);
        mixerFilterFreqB[voice]->gain(1,0);
        mixerFilterRes[voice]->gain(0,0);
        mixerFilterRes[voice]->gain(1,secondFilterVel);
        break;
      case 3: //KBD Res, Vel Res
        mixerFilterFreqA[voice]->gain(3,0);
        mixerFilterFreqB[voice]->gain(1,0);
        mixerFilterRes[voice]->gain(0,secondFilterKbd);
        mixerFilterRes[voice]->gain(1,secondFilterVel);
        break;
      }
  } else {
    switch (filterKbdVelControl) {
      case 0: //KBD Freq, Vel Freq
        mixerFilterFreqA[voice]->gain(3,filterKbd);
        mixerFilterFreqB[voice]->gain(1,filterVel);
        mixerFilterRes[voice]->gain(0,0);
        mixerFilterRes[voice]->gain(1,0);
        break;
      case 1: //KBD Res, Vel Freq
        mixerFilterFreqA[voice]->gain(3,0);
        mixerFilterFreqB[voice]->gain(1,filterVel);
        mixerFilterRes[voice]->gain(0,filterKbd);
        mixerFilterRes[voice]->gain(1,0);
        break;
      case 2: //KBD Freq, Vel Res
        mixerFilterFreqA[voice]->gain(3,filterKbd);
        mixerFilterFreqB[voice]->gain(1,0);
        mixerFilterRes[voice]->gain(0,0);
        mixerFilterRes[voice]->gain(1,filterVel);
        break;
      case 3: //KBD Res, Vel Res
        mixerFilterFreqA[voice]->gain(3,0);
        mixerFilterFreqB[voice]->gain(1,0);
        mixerFilterRes[voice]->gain(0,filterKbd);
        mixerFilterRes[voice]->gain(1,filterVel);
        break;
      }
  }
  
  
}

//---------------------------------------------------------------------------------------------//
// function updateTremolo
//---------------------------------------------------------------------------------------------//
void updateTremolo() {
  if(tremoloDepth==0 || tremoloSpeed==0) {
    //Trem off, allows dc through to keep the VCA fully on
    mixerTremoloLFO.gain(0,0);
    mixerTremoloLFO.gain(1,1);
  } else {
    mixerTremoloLFO.gain(0,1);
    mixerTremoloLFO.gain(1,0);
    tremoloLFO.frequency(tremoloSpeed);
    tremoloLFO.amplitude(tremoloDepth);
  }
}

//---------------------------------------------------------------------------------------------//
// function updatePan
//---------------------------------------------------------------------------------------------//
void updatePan() {
  if(panDepth ==0) {
    mixerPanL.gain(0,1);
    mixerPanL.gain(1,0);
    mixerPanR.gain(0,1);
    mixerPanR.gain(1,0);
    leslieDetuneMaster.gain(0.000);

  } else {
    mixerPanL.gain(0,0);
    mixerPanL.gain(1,1);
    mixerPanR.gain(0,0);
    mixerPanR.gain(1,1);

    leslieDetuneMaster.gain(0.005);
    panLFOL.amplitude(panDepth);
    panLFOL.frequency(panSpeed);
    panLFOR.amplitude(panDepth);
    panLFOR.frequency(panSpeed);
  }
}

//---------------------------------------------------------------------------------------------//
// function loadVariableSettings
//---------------------------------------------------------------------------------------------//
void loadControlVariables() {
  //Eventually this will be used to load a preset, but for the time being is just storing init values
  
  //General
  midiChannelMain = 1;
  midiChannelSecondary = 2;
  secondaryEnabled = false;
  secondaryControl = false;
  secondaryBypassFx = false;
  secondaryVolume = 1;
  numberOfVoices = VOICES;

  //PRIMARY VOICES ----------------------
  //Oscillators
  oscAVol = 0.75;
  oscBVol = 0.75;
  pinkVol = 0.2;
  mixerOscGain = 0.5;

  oscAWaveform = 0;
  oscBWaveform = 0;
  oscVelocity = 1;
  portamentoSpeed = 0; //Milliseconds

  oscAOctave = 0;
  oscBOctave = 0;
  oscLFOFreq = 0;
  oscADetune = 0;
  oscBDetune = 0;

  oscPWM = 0;
  oscAPulseWidth = 0;
  oscBPulseWidth = 0;

  
  //Filter
  filterFreq = 20000;
  filterRes = 0;
  filterOctave = 7;

  filterKbdVelControl = 0; //Used by mixers to determine what the note/velocity are controlling
  filterLFOFreq = 0;
  filterAft = 0;
  filterEnvFreq = 0;
  filterKbd = 0;
  filterVel = 0;

  envelopeFilterDelay = 0;
  envelopeFilterAttack = 0;
  envelopeFilterDecay = 0;
  envelopeFilterSustain = 0;
  envelopeFilterRelease = 0;


  //LFO
  lfoWaveform = 0;
  lfoSpeed = 1;

  //Audio envelope
  envelopeVolAttack = 2;
  envelopeVolDecay = 0;
  envelopeVolSustain = 1;
  envelopeVolRelease = 100;

  //SECONDARY VOICES-----------------------------

	//Oscillators - secondary
	secondOscAVol = oscAVol;
	secondOscBVol = oscBVol;
	secondPinkVol = pinkVol;
	
	secondOscAWaveform = oscAWaveform;
	secondOscBWaveform = oscBWaveform;
	secondOscVelocity = oscVelocity;
	secondPortamentoSpeed = portamentoSpeed;
	
	secondOscAOctave = oscAOctave;
	secondOscBOctave = oscBOctave;
	secondOscLFOFreq = oscLFOFreq;
	secondOscADetune = oscADetune;
	secondOscBDetune = oscBDetune;
	
	secondOscPWM = oscPWM;
	secondOscAPulseWidth = oscAPulseWidth;
	secondOscBPulseWidth = oscBPulseWidth;
	
	
	//Filter - secondary
	secondFilterFreq = filterFreq;
	secondFilterRes=filterRes;
	secondFilterOctave = filterOctave;
	
	secondFilterKbdVelControl = filterKbdVelControl;
	secondFilterLFOFreq = filterLFOFreq;
	secondFilterAft = filterAft;
	secondFilterEnvFreq = filterEnvFreq;
	secondFilterKbd = filterKbd;
	secondFilterVel = filterVel;
	
	secondEnvelopeFilterDelay = envelopeFilterDelay;
	secondEnvelopeFilterAttack = envelopeFilterAttack;
	secondEnvelopeFilterDecay = envelopeFilterDecay;
	secondEnvelopeFilterSustain = envelopeFilterSustain;
	secondEnvelopeFilterRelease = envelopeFilterRelease;
	
	
	//LFO - secondary
	secondLfoWaveform = lfoWaveform;
	secondLfoSpeed = lfoSpeed;
	
	//Audio Envelope  - secondary
	secondEnvelopeVolAttack = envelopeVolAttack;
	secondEnvelopeVolDecay = envelopeVolDecay;
	secondEnvelopeVolSustain = envelopeVolSustain;
	secondEnvelopeVolRelease = envelopeVolRelease;

  //FX--------------------------------------  

  //Wheels & Exp Pedal
  bendRange = 2;
  modWheelSetting = 0;
  expPedalSetting = 0;
  
  //Wah
  wahQ = 5;
  wahAttenuation = 2;
  wahMaxFreq = 1500;
  wahMinFreq = 375;

  //Phaser
  phaserWet = 0;
  phaserSpeed = 0.5;
  phaserFeedback = 0.5;

  //Chorus
  chorusWet = 0;

  //Tremolo
  tremoloWavetype = 0;
  tremoloSpeed = 0;
  tremoloDepth = 0;

  //Delay
  delayLevel = 1;
  delayInputLevel = 0;
  delayTime = 0.1;
  delayRepeats = 8;
  delayFalloffAmount = 0.1;
  delayPingPong= false;
  delayFeedback = 0.5;

  //Reverb
  reverbRoomsize = 0;
  reverbDamping = 0;
  reverbWet = 0;

  //Pan
  panSpeed = 1;
  panDepth = 0;

  //Master Volume
  masterVolLeft = 0.33;
  masterVolRight = 0.33;
}

//---------------------------------------------------------------------------------------------//
// function Initialise Settings
//Loads Settings that may be changed by the user
//---------------------------------------------------------------------------------------------//
void loadSettings(int voice) {
  //General
  if(secondaryBypassFx && secondaryEnabled) {
    masterVolL.gain(1,1);
    masterVolR.gain(1,1);

    bypassFx7.gain(0);
    bypassLeslie7.gain(0);
  } else {
    masterVolL.gain(1,0);
    masterVolR.gain(1,0);

    bypassFx7.gain(1);
    bypassLeslie7.gain(1);
  }
  if(secondaryEnabled) {
    secondaryVol.gain(secondaryVolume);
    numberOfVoices = VOICES_SECONDARY;

    mixerLfoMaster7.gain(0,0);
    mixerLfoMaster7.gain(1,1);
  } else {
    secondaryVol.gain(1);
    numberOfVoices = VOICES;

    mixerLfoMaster7.gain(0,1);
    mixerLfoMaster7.gain(1,0);
  }

  //Oscillators
  mixerOsc[voice]->gain(0,(mixerOscGain * oscAVol));
  mixerOsc[voice]->gain(1,(mixerOscGain * oscBVol));
  mixerOsc[voice]->gain(2,(mixerOscGain * pinkVol));

  switch(oscAWaveform) {
    case 0:
      oscA[voice]->begin(WAVEFORM_SAWTOOTH);
      break;
    case 1:
      oscA[voice]->begin(WAVEFORM_PULSE);
      break;
    case 2:
      oscA[voice]->begin(WAVEFORM_TRIANGLE_VARIABLE);
      break;
    case 3:
      oscA[voice]->begin(WAVEFORM_SINE);
      break;
    case 4:
      oscA[voice]->begin(WAVEFORM_SAWTOOTH_REVERSE);
      break;
  }
  switch(oscBWaveform) {
    case 0:
      oscB[voice]->begin(WAVEFORM_SAWTOOTH);
      break;
    case 1:
      oscB[voice]->begin(WAVEFORM_PULSE);
      break;
    case 2:
      oscB[voice]->begin(WAVEFORM_TRIANGLE_VARIABLE);
      break;
    case 3:
      oscB[voice]->begin(WAVEFORM_SINE);
      break;
    case 4:
      oscB[voice]->begin(WAVEFORM_SAWTOOTH_REVERSE);
      break;
  }

  if(voice ==secondaryVoice &&secondaryEnabled) {
    //Secondary Voice settings
    oscA[voice]->frequency(((voice+1)*32.7032));
    oscA[voice]->amplitude(secondOscVelocity);
    oscB[voice]->frequency(((voice+1)*33.7032));
    oscB[voice]->amplitude(secondOscVelocity);
    pink[voice]->amplitude(secondOscVelocity);
    
    dcPitchOctaveA[voice]->amplitude(secondOscAOctave);
    dcPitchOctaveB[voice]->amplitude(secondOscAOctave);
    lfoFreq[voice]->gain(secondOscLFOFreq);
    dcPitchDetuneA[voice]->amplitude(secondOscADetune);
    dcPitchDetuneB[voice]->amplitude(secondOscBDetune);

    lfoPW[voice]->gain(secondOscPWM);
    dcOscPWA[voice]->amplitude(secondOscAPulseWidth);
    dcOscPWB[voice]->amplitude(secondOscBPulseWidth);

    //Filter
    ladder[voice]->frequency(secondFilterFreq);
    ladder[voice]->resonance(secondFilterRes);
    ladder[voice]->octaveControl(secondFilterOctave);

    filterSetKbdVelControl(voice); //Set Mixer levels depending on filterKbdVelControl

    lfoFilterFreq[voice]->gain(secondFilterLFOFreq);
    dcFilterAft[voice]->amplitude(secondFilterAft);
    dcFilterEnv[voice]->amplitude(secondFilterEnvFreq);
    dcFilterKbd[voice]->amplitude(secondFilterKbd);
    dcFilterVel[voice]->amplitude(secondFilterVel);

    envelopeFilter[voice]->delay(secondEnvelopeFilterDelay);
    envelopeFilter[voice]->attack(secondEnvelopeFilterAttack);
    envelopeFilter[voice]->decay(secondEnvelopeFilterDecay);
    envelopeFilter[voice]->sustain(secondEnvelopeFilterSustain);
    envelopeFilter[voice]->release(secondEnvelopeFilterRelease);


    //Audio Envelope
    envelopeVol[voice]->attack(secondEnvelopeVolAttack);
    envelopeVol[voice]->decay(secondEnvelopeVolDecay);
    envelopeVol[voice]->sustain(secondEnvelopeVolSustain);
    envelopeVol[voice]->release(secondEnvelopeVolRelease);
  } else {
    oscA[voice]->frequency(((voice+1)*32.7032));
    oscA[voice]->amplitude(oscVelocity);
    oscB[voice]->frequency(((voice+1)*33.7032));
    oscB[voice]->amplitude(oscVelocity);
    pink[voice]->amplitude(oscVelocity);
    
    dcPitchOctaveA[voice]->amplitude(oscAOctave);
    dcPitchOctaveB[voice]->amplitude(oscAOctave);
    lfoFreq[voice]->gain(oscLFOFreq);
    dcPitchDetuneA[voice]->amplitude(oscADetune);
    dcPitchDetuneB[voice]->amplitude(oscBDetune);

    lfoPW[voice]->gain(oscPWM);
    dcOscPWA[voice]->amplitude(oscAPulseWidth);
    dcOscPWB[voice]->amplitude(oscBPulseWidth);

    //Filter
    ladder[voice]->frequency(filterFreq);
    ladder[voice]->resonance(filterRes);
    ladder[voice]->octaveControl(filterOctave);

    filterSetKbdVelControl(voice); //Set Mixer levels depending on filterKbdVelControl

    lfoFilterFreq[voice]->gain(filterLFOFreq);
    dcFilterAft[voice]->amplitude(filterAft);
    dcFilterEnv[voice]->amplitude(filterEnvFreq);
    dcFilterKbd[voice]->amplitude(filterKbd);
    dcFilterVel[voice]->amplitude(filterVel);

    envelopeFilter[voice]->delay(envelopeFilterDelay);
    envelopeFilter[voice]->attack(envelopeFilterAttack);
    envelopeFilter[voice]->decay(envelopeFilterDecay);
    envelopeFilter[voice]->sustain(envelopeFilterSustain);
    envelopeFilter[voice]->release(envelopeFilterRelease);


    //Audio Envelope
    envelopeVol[voice]->attack(envelopeVolAttack);
    envelopeVol[voice]->decay(envelopeVolDecay);
    envelopeVol[voice]->sustain(envelopeVolSustain);
    envelopeVol[voice]->release(envelopeVolRelease);
  }
  


  //LFO
  switch(lfoWaveform) {
    case 0:
      lfo.begin(WAVEFORM_SINE);
      break;
    case 1:
      lfo.begin(WAVEFORM_PULSE);
      break;
    case 2:
      lfo.begin(WAVEFORM_TRIANGLE_VARIABLE);
      break;
    case 3:
      lfo.begin(WAVEFORM_SAWTOOTH);
      break;
    case 4:
      lfo.begin(WAVEFORM_SAWTOOTH_REVERSE);
      break;
  }
  switch(secondLfoWaveform) {
    case 0:
      secondaryLfo.begin(WAVEFORM_SINE);
      break;
    case 1:
      secondaryLfo.begin(WAVEFORM_PULSE);
      break;
    case 2:
      secondaryLfo.begin(WAVEFORM_TRIANGLE_VARIABLE);
      break;
    case 3:
      secondaryLfo.begin(WAVEFORM_SAWTOOTH);
      break;
    case 4:
      secondaryLfo.begin(WAVEFORM_SAWTOOTH_REVERSE);
      break;
  }
  lfo.frequency(lfoSpeed);
  secondaryLfo.frequency(secondLfoSpeed);
  //Wheel & Exp Pedal - None


  //Wah
  mixerWahL.gain(1,0);
  mixerWahR.gain(1,0);
  filterL.resonance(wahQ);
  filterR.resonance(wahQ);
  wahAttenuatorL.gain(wahAttenuation);
  wahAttenuatorR.gain(wahAttenuation);

  //Phaser
  phaserL.lfo_rate(phaserSpeed);
  phaserR.lfo_rate(phaserSpeed);
  phaserL.feedback(PHASER_MAX_FBDB*phaserFeedback);
  phaserR.feedback(PHASER_MAX_FBDB*phaserFeedback);
  
  mixerPhaserL.gain(0,1-phaserWet);
  mixerPhaserL.gain(1,phaserWet);
  mixerPhaserR.gain(0,1-phaserWet);
  mixerPhaserR.gain(1,phaserWet);
  if(phaserWet==0) {
    phaserL.bypass(true);
    phaserR.bypass(true);
  } else {
    phaserL.bypass(false);
    phaserR.bypass(false);
  }

  //Chorus
  mixerChorusL.gain(0,1-chorusWet);
  mixerChorusL.gain(1,chorusWet);
  mixerChorusR.gain(0,1-chorusWet);
  mixerChorusR.gain(1,chorusWet);

  //Tremolo
  switch(tremoloWavetype) {
    case 0:
      tremoloLFO.begin(WAVEFORM_SAWTOOTH);
      break;
    case 1:
      tremoloLFO.begin(WAVEFORM_PULSE);
      break;
    case 2:
      tremoloLFO.begin(WAVEFORM_TRIANGLE_VARIABLE);
      break;
    case 3:
      tremoloLFO.begin(WAVEFORM_SINE);
      break;
    case 4:
      tremoloLFO.begin(WAVEFORM_SAWTOOTH_REVERSE);
      break;
  }   
  updateTremolo();

  //Delay
  mixerPreDelayL.gain(0, delayInputLevel);
  mixerPreDelayR.gain(0, delayInputLevel);
  mixerDelayLB.gain(1,delayLevel);
  mixerDelayRB.gain(1,delayLevel);
  delayFeedbackL.gain(delayFeedback);
  delayFeedbackR.gain(delayFeedback);

  if(delayPingPong==true) {
    mixerDelayLA.gain(1,0);
    mixerDelayLA.gain(3,0);

    mixerDelayRA.gain(0,0);
    mixerDelayRA.gain(2,0);
  } else {
    mixerDelayLA.gain(1,1);
    mixerDelayLA.gain(3,1);

    mixerDelayRA.gain(0,1);
    mixerDelayRA.gain(2,1);
  }

  delayL.delay(0,500);
  delayR.delay(0,500);


  //Reverb
  freeverbL.roomsize(reverbRoomsize);
  freeverbR.roomsize(reverbRoomsize);
  freeverbL.damping(reverbDamping);
  freeverbR.damping(reverbDamping);
  //mixerReverbL.gain(0, 1-reverbWet);
  mixerReverbL.gain(1, reverbWet);
  //mixerReverbR.gain(0, 1-reverbWet);
  mixerReverbR.gain(1, reverbWet);

  //Pan
  updatePan();

  //Master Volume
  masterVolL.gain(0,masterVolLeft);
  masterVolR.gain(0,masterVolRight);
}


//---------------------------------------------------------------------------------------------//
// function Initialise Settings
//Settings that will be set on init and never need changing
//---------------------------------------------------------------------------------------------//
void initialiseSettings() {
  //Affects all voices, regardless of whether secondary is enabled
  for(int voice = 0; voice <VOICES; voice++) {
    //Oscillators
    oscA[voice]->frequencyModulation(10);
    oscB[voice]->frequencyModulation(10);

    dcPitchBend[voice]->amplitude(0);
  }

  //LFO
  lfo.amplitude(1);
  secondaryLfo.amplitude(1);

  //Tremolo
  tremoloLFO.offset(1);
  dcTremoloOff.amplitude(1);

  //Phaser
  phaserL.depth(0.1f, 1.0f);
  phaserR.depth(0.1f, 1.0f); 
  phaserL.mix(0.5);
  phaserR.mix(0.5);
  phaserL.stages(4);
  phaserR.stages(4);
  

  //Pan
  panLFOL.offset(1);
  panLFOR.offset(1);
  panLFOR.phaseModulation(180);
  dcPanOffL.amplitude(1);
  dcPanOffR.amplitude(1);
  dcPanPhase.amplitude(1);
  leslieDetuneMaster.gain(0.005);
}

//---------------------------------------------------------------------------------------------//
// function startupJingle
// Plays a brief tune to confirm Teensy has flashed/booted correctly and audio is working.
// If it plays and then nothing works, its probably a MIDI problem! 
//---------------------------------------------------------------------------------------------//
void startupJingle() {
  delay(250);
  for(int voice = 0; voice <=VOICES_ARRAY; voice++) { 
    envelopeVol[voice]->noteOn();
    delay(50);
    envelopeVol[voice]->noteOff();
    delay(50);
  }
}

//---------------------------------------------------------------------------------------------//
// function checkExpPedal
// Updates various settings depending on Expression Pedal Position
//---------------------------------------------------------------------------------------------//
void checkExpPedal() {
  static int expReadingLast = 0;
  unsigned long currentMicros = micros();
  static unsigned long lastMicros = 0;
  static int expSettingLast = expPedalSetting;


  // if(currentMicros-lastMicros >=10000) {
  //   lastMicros = currentMicros;
    
  //   int expReading = analogRead(ExpPedalPin);

  //   if(expReading<3) {
  //     //Pedal disabled
  //     for(int i=0;i<6; i++) {
  //       //Reset all parameters back to dial setting 
  //       expReset(i);
  //     }   
  //     return;
  //   }
  //   if(expSettingLast!=expPedalSetting) {
  //     expReset(expSettingLast);
  //     expSettingLast = expPedalSetting;
  //   }


  //   #ifdef DEBUG_EXP
  //     //Serial.print("Exp Pedal: ");
  //     //Serial.println(expReading);
  //   #endif

  // //Tolerance to avoid minor noise/value changes affecting reading
  // if (expReading > (expReadingLast + 7) || expReading < (expReadingLast - 7)) {
  //     expReadingLast = expReading;
  //     float pedalValue;
      
  //     if(expPedalSetting!=4) {
  //       expReading = (expReading >> 3); //Convert to 0-127
  //       pedalValue = expReading * DIV127; //Convert to 0-1
  //     }
      
      
  //     // Serial.print("exp Pedal ");
  //     // Serial.println(pedalValue);
  //     // pedalValue = (pedalValue-EXP_MIN_VALUE);
  //     // Serial.print("exp Pedal min ");
  //     // Serial.println(pedalValue);
  //     // pedalValue = pedalValue * EXP_MIN_MULTIPLIER; 
  //     // Serial.print("exp Pedal multiplied ");
  //     // Serial.println(pedalValue);
      
  //     switch(expPedalSetting) {
  //       case 0://Wah
  //         mixerWahL.gain(0,0);
  //         mixerWahL.gain(1,1);
  //         mixerWahR.gain(0,0);
  //         mixerWahR.gain(1,1);
  //         filterL.frequency(wahMinFreq+((wahMaxFreq-wahMinFreq)*pedalValue));
  //         filterR.frequency(wahMinFreq+((wahMaxFreq-wahMinFreq)*pedalValue));
  //         break;
  //       case 1: //Filter Freq
  //         //pedalValue=pedalValue-0.5;
  //         for(int voice = 0; voice <=VOICES_ARRAY; voice++) { 
  //           ladder[voice]->frequency(20000 * pedalValue);
  //         }
  //         break;
  //       case 2:  //Delay fbdk
  //         delayFeedbackL.gain(pedalValue);
  //         delayFeedbackR.gain(pedalValue);
  //         break;
  //       case 3: //Leslie Speed
  //         panSpeed = (PAN_MAX_SPEED * pow(100,(pedalValue-1)));
  //         updatePan();
  //         break; 
  //       case 4: //Whammy
        
  //         pedalValue = pedalValue/1023;
  //         pedalValue = ((pedalValue * 0.1)/12)*bendRange; 
  
  //         for(int voice=0; voice <numberOfVoices; voice ++) {
  //           dcPitchBend[voice]->amplitude(pedalValue);
  //         }
  //         break;
  //       case 5: //Volume
  //         //Don't exceed max volume setting
  //         pedalValue = masterVolLeft*pedalValue;
  //         masterVolL.gain(0, pedalValue);
  //         masterVolR.gain(0, pedalValue);
  //         break;
  //     }
  //   }
  // }
}

//---------------------------------------------------------------------------------------------//
// function expReset
// Resets values modified by checkExpPedal
//---------------------------------------------------------------------------------------------//
void expReset(int control) {
  switch(control) {
    case 0://Wah
      mixerWahL.gain(0,1);
      mixerWahL.gain(1,0);
      mixerWahR.gain(0,1);
      mixerWahR.gain(1,0);
      break;
    case 1: //Filter Freq
      for(int voice = 0; voice <=VOICES_ARRAY; voice++) { 
        ladder[voice]->frequency(filterFreq);
      }
      break;
    case 2:  //Delay fbdk
      delayFeedbackL.gain(delayFeedback);
      delayFeedbackR.gain(delayFeedback);
      break;
    case 3: //Leslie Speed
      panSpeed = (PAN_MAX_SPEED * pow(100,(panSpeed-1)));
      updatePan();
      break; 
    case 4: //Whammy
      break;
    case 5: //Volume
      masterVolL.gain(0,masterVolLeft);
      masterVolR.gain(0,masterVolRight);
      break;
   }
}

//---------------------------------------------------------------------------------------------//
// function updateLFOLED
//---------------------------------------------------------------------------------------------//
void updateLFOLED() {
  if(lfoPeak.available()) {
    float pos = lfoPeak.read();
    analogWrite(LEDPin, pos*255);
  }
}

//---------------------------------------------------------------------------------------------//
// function midiDebug
//Prints recieved midi info
//---------------------------------------------------------------------------------------------//
void midiDebug(byte channel, byte type, byte data1, byte data2)  {
    static byte channel_val, type_val, data1_val, data2_val;

    if(channel!=channel_val||type!=type_val||data1!=data1_val||data2!=data2_val) {

        channel_val = channel;
        type_val = type;
        data1_val= data1;
        data2_val = data2;
        String data1_text, type_text;

        switch (type_val) {
            case midi::ControlChange:
                type_text="CC";
                switch(data1_val) {
                    case 14:
                        data1_text="CC_ChannelMain";
                        break;
                    case 15:
                        data1_text="CC_SecondaryChannel";
                        break;
                    case 16:
                        data1_text="CC_SecondaryEnable";
                        break;
                    case 17:
                        data1_text="CC_SecondaryControl";
                        break;
                    case 18:
                        data1_text="CC_SecondaryBypass";
                        break;
                    case 19:
                        data1_text="CC_SecondaryVolume";
                        break;
                    case 84:
                        data1_text="CC_Polymode";
                        break;
                    case 90:
                        data1_text="CC_Portamento";
                        break;
                    case 24:
                        data1_text="CC_OscAWavetype";
                        break;
                    case 25:
                        data1_text="CC_OscBWavetype";
                        break;
                    case 20:
                        data1_text="CC_OscADetune";
                        break;
                    case 21:
                        data1_text="CC_OscBDetune";
                        break;
                    case 58:
                        data1_text="CC_OscVibrato";
                        break;
                    case 22:
                        data1_text="CC_OscAOctave";
                        break;
                    case 23:
                        data1_text="CC_OscBOctave";
                        break;
                    case 26:
                        data1_text="CC_OscAPulseWidth";
                        break;
                    case 27:
                        data1_text="CC_OscBPulseWidth";
                        break;
                    case 60:
                        data1_text="CC_OscPulseWidthMod";
                        break;
                    case 47:
                        data1_text="CC_FilterFreq";
                        break;
                    case 48:
                        data1_text="CC_FilterRes";
                        break;
                    case 52:
                        data1_text="CC_FilterEnv";
                        break;
                    case 49:
                        data1_text="CC_FilterKeyboard";
                        break;
                    case 50:
                        data1_text="CC_FilterVelocity";
                        break;
                    case 63:
                        data1_text="CC_FilterLFO";
                        break;
                    case 51:
                        data1_text="CC_FilterKBDVeloControl";
                        break;
                    case 28:
                        data1_text="CC_EnvVolumeAttack";
                        break;
                    case 29:
                        data1_text="CC_EnvVolumeDecay";
                        break;
                    case 30:
                        data1_text="CC_EnvVolumeSustain";
                        break;
                    case 31:
                        data1_text="CC_EnvVolumeRelease";
                        break;
                    case 53:
                        data1_text="CC_EnvFilterDelay";
                        break;
                    case 54:
                        data1_text="CC_EnvFilterAttack";
                        break;
                    case 55:
                        data1_text="CC_EnvFilterDecay";
                        break;
                    case 56:
                        data1_text="CC_EnvFilterSustain";
                        break;
                    case 57:
                        data1_text="CC_EnvFilterRelease";
                        break;
                    case 1:
                        data1_text="CC_ModWheel";
                        break;
                    case 88:
                        data1_text="CC_ModWheelMode";
                        break;
                    case 89:
                        data1_text="CC_ExpPedalMode";
                        break;
                    case 114:
                        data1_text="CC_AftertouchMode";
                        break;
                    case 46:
                        data1_text="CC_PitchBendAmount";
                        break;
                    case 61:
                        data1_text="CC_LFOWavetype";
                        break;
                    case 62:
                        data1_text="CC_LFOSpeed";
                        break;
                    case 102:
                        data1_text="CC_ReverbSize";
                        break;
                    case 103:
                        data1_text="CC_ReverbDamping";
                        break;
                    case 104:
                        data1_text="CC_ReverbWet";
                        break;
                    case 110:
                        data1_text="CC_DelayLevel";
                        break;
                    case 111:
                        data1_text="CC_DelayInputLevel";
                        break;
                    case 112:
                        data1_text="CC_DelayTime";
                        break;
                    case 113:
                        data1_text="CC_DelayFeedback";
                        break;
                    case 85:
                        data1_text="CC_MixerOscA";
                        break;
                    case 86:
                        data1_text="CC_MixerOscB";
                        break;
                    case 87:
                        data1_text="CC_MixerPink";
                        break;
                    case 59:
                        data1_text="CC_MasterVol";
                        break;
                    case 107:
                        data1_text="CC_TremoloWavetype";
                        break;
                    case 108:
                        data1_text="CC_TremoloSpeed";
                        break;
                    case 109:
                        data1_text="CC_TremoloDepth";
                        break;
                    case 105:
                        data1_text="CC_ChorusWet";
                        break;
                    case 115:
                        data1_text="CC_LeslieSpeed";
                        break;
                    case 116:
                        data1_text="CC_LeslieDepth";
                        break;
                    case 118:
                        data1_text="CC_PhaserSpeed";
                        break;
                    case 119:
                        data1_text="CC_PhaserFeedback";
                        break;
                    case 117:
                        data1_text="CC_PhaserWet";
                        break;
                    case 9:
                        data1_text="Debug_1";
                        break;
                    case 10:
                        data1_text="Debug_2";
                        break;
                    case 11:
                        data1_text="Debug_3";
                        break;
                    case 12:
                        data1_text="Debug_4";
                        break;
                    case 13:
                        data1_text="Debug_5";
                        break;

                }
                Serial.print("CH ");
                Serial.print(channel_val);
                Serial.print(". Type: ");
                Serial.print(type_text);
                Serial.print(" - ");
                Serial.print(data1_text);
                Serial.print(" - ");
                Serial.println(data2_val);
                break;
        }
    }
}