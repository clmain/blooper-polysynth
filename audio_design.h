#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioAmplifier           leslieDetuneMaster; //xy=112.61363983154297,952.25
AudioSynthWaveformModulated lfo;            //xy=115.61363983154297,1590.25
AudioAnalyzePeak         lfoPeak;        //xy=162.61363983154297,1379.25
AudioAnalyzeRMS          secondardyLfoPos; //xy=369.61363983154297,3291.25
AudioAmplifier           lfoMaster7;     //xy=370.61363983154297,3115.25
AudioSynthWaveformModulated secondaryLfo;   //xy=374.61363983154297,3195.25
AudioAmplifier           lfoMaster0;     //xy=517.613639831543,91.25
AudioAmplifier           lfoMaster1;     //xy=528.613639831543,542.25
AudioAmplifier           lfoMaster2;     //xy=548.613639831543,986.25
AudioAmplifier           lfoMaster3;     //xy=548.613639831543,1425.25
AudioAmplifier           lfoMaster4;     //xy=568.613639831543,1863.25
AudioAmplifier           lfoMaster5;     //xy=573.613639831543,2303.25
AudioAmplifier           lfoMaster6;     //xy=587.613639831543,2741.25
AudioMixer4              mixerLfoMaster7; //xy=592.613639831543,3205.25
AudioAmplifier           bypassLeslie7;  //xy=599.613639831543,3311.25
AudioSynthWaveformDc     dcPitchOctaveA0; //xy=737.613639831543,145.25
AudioSynthWaveformDc     dcPitchOctaveB0; //xy=738.613639831543,175.25
AudioSynthWaveformDc     dcPitchDetuneA0; //xy=740.613639831543,235.25
AudioSynthWaveformDc     dcPitchDetuneB0; //xy=741.613639831543,268.25
AudioSynthWaveformDc     dcPitchBend0;   //xy=747.613639831543,116.25
AudioAmplifier           leslieDetune0;  //xy=747.613639831543,301.25
AudioSynthWaveformDc     dcPitchOctaveA1; //xy=747.613639831543,595.25
AudioSynthWaveformDc     dcPitchOctaveB1; //xy=748.613639831543,625.25
AudioSynthWaveformDc     dcPitchDetuneA1; //xy=750.613639831543,685.25
AudioSynthWaveformDc     dcPitchDetuneB1; //xy=751.613639831543,718.25
AudioSynthWaveformDc     dcPitchBend1;   //xy=757.613639831543,566.25
AudioAmplifier           leslieDetune1;  //xy=757.613639831543,751.25
AudioAmplifier           lfoFreq0;       //xy=765.613639831543,206.25
AudioSynthWaveformDc     dcPorta0;       //xy=765.613639831543,334.25
AudioSynthWaveformDc     dcPitchOctaveA2; //xy=767.613639831543,1040.25
AudioSynthWaveformDc     dcPitchOctaveB2; //xy=768.613639831543,1070.25
AudioSynthWaveformDc     dcPitchOctaveA3; //xy=767.613639831543,1478.25
AudioSynthWaveformDc     dcPitchOctaveB3; //xy=768.613639831543,1508.25
AudioSynthWaveformDc     dcPitchDetuneA2; //xy=770.613639831543,1130.25
AudioSynthWaveformDc     dcPitchDetuneB2; //xy=771.613639831543,1163.25
AudioSynthWaveformDc     dcPitchDetuneA3; //xy=770.613639831543,1568.25
AudioSynthWaveformDc     dcOscPWA0;      //xy=775.613639831543,449.25
AudioSynthWaveformDc     dcPitchDetuneB3; //xy=771.613639831543,1601.25
AudioAmplifier           lfoFreq1;       //xy=775.613639831543,656.25
AudioSynthWaveformDc     dcOscPWB0;      //xy=776.613639831543,481.25
AudioSynthWaveformDc     dcPitchBend2;   //xy=777.613639831543,1011.25
AudioAmplifier           leslieDetune2;  //xy=777.613639831543,1196.25
AudioSynthWaveformDc     dcPitchBend3;   //xy=777.613639831543,1449.25
AudioAmplifier           leslieDetune3;  //xy=777.613639831543,1634.25
AudioAmplifier           lfoPW0;         //xy=785.613639831543,418.25
AudioSynthWaveformDc     dcOscPWA1;      //xy=785.613639831543,900.25
AudioSynthWaveformDc     dcOscPWB1;      //xy=786.613639831543,932.25
AudioSynthWaveformDc     dcPitchOctaveA4; //xy=787.613639831543,1917.25
AudioSynthWaveformDc     dcPitchOctaveB4; //xy=788.613639831543,1947.25
AudioSynthWaveformDc     dcPitchDetuneA4; //xy=790.613639831543,2007.25
AudioAmplifier           lfoPW1;         //xy=795.613639831543,869.25
AudioSynthWaveformDc     dcPitchDetuneB4; //xy=791.613639831543,2040.25
AudioAmplifier           lfoFreq2;       //xy=795.613639831543,1101.25
AudioAmplifier           lfoFreq3;       //xy=795.613639831543,1539.25
AudioSynthWaveformDc     dcPitchOctaveA5; //xy=792.613639831543,2357.25
AudioSynthWaveformDc     dcPitchOctaveB5; //xy=793.613639831543,2387.25
AudioSynthWaveformDc     dcPitchBend4;   //xy=797.613639831543,1888.25
AudioSynthWaveformDc     dcPitchDetuneA5; //xy=795.613639831543,2447.25
AudioAmplifier           leslieDetune4;  //xy=797.613639831543,2073.25
AudioSynthWaveformDc     dcPitchDetuneB5; //xy=796.613639831543,2480.25
AudioSynthWaveformDc     dcOscPWA2;      //xy=805.613639831543,1345.25
AudioSynthWaveformDc     dcPitchBend5;   //xy=802.613639831543,2328.25
AudioSynthWaveformDc     dcOscPWB2;      //xy=806.613639831543,1377.25
AudioAmplifier           leslieDetune5;  //xy=802.613639831543,2513.25
AudioSynthWaveformDc     dcOscPWA3;      //xy=805.613639831543,1783.25
AudioSynthWaveformDc     dcOscPWB3;      //xy=806.613639831543,1815.25
AudioSynthWaveformDc     dcPitchOctaveA6; //xy=806.613639831543,2795.25
AudioSynthWaveformDc     dcPitchOctaveB6; //xy=807.613639831543,2825.25
AudioAmplifier           lfoPW2;         //xy=815.613639831543,1314.25
AudioSynthWaveformDc     dcPitchDetuneA6; //xy=809.613639831543,2885.25
AudioSynthWaveformDc     dcPitchDetuneB6; //xy=810.613639831543,2918.25
AudioAmplifier           lfoPW3;         //xy=815.613639831543,1752.25
AudioAmplifier           lfoFreq4;       //xy=815.613639831543,1978.25
AudioSynthWaveformDc     dcPitchOctaveA7; //xy=814.613639831543,3251.25
AudioSynthWaveformDc     dcPitchBend6;   //xy=816.613639831543,2766.25
AudioAmplifier           leslieDetune6;  //xy=816.613639831543,2951.25
AudioSynthWaveformDc     dcPitchOctaveB7; //xy=815.613639831543,3281.25
AudioAmplifier           lfoFreq5;       //xy=820.613639831543,2418.25
AudioSynthWaveformDc     dcPitchDetuneA7; //xy=817.613639831543,3341.25
AudioSynthWaveformDc     dcPitchDetuneB7; //xy=818.613639831543,3374.25
AudioSynthWaveformDc     dcOscPWA4;      //xy=825.613639831543,2222.25
AudioSynthWaveformDc     dcOscPWB4;      //xy=826.613639831543,2254.25
AudioSynthWaveformDc     dcPitchBend7;   //xy=824.613639831543,3222.25
AudioAmplifier           leslieDetune7;  //xy=824.613639831543,3407.25
AudioSynthWaveformDc     dcOscPWA5;      //xy=830.613639831543,2662.25
AudioSynthWaveformDc     dcOscPWB5;      //xy=831.613639831543,2694.25
AudioAmplifier           lfoPW4;         //xy=835.613639831543,2191.25
AudioAmplifier           lfoFreq6;       //xy=834.613639831543,2856.25
AudioAmplifier           lfoPW5;         //xy=840.613639831543,2631.25
AudioAmplifier           lfoFreq7;       //xy=842.613639831543,3312.25
AudioSynthWaveformDc     dcPorta7;       //xy=842.613639831543,3440.25
AudioSynthWaveformDc     dcOscPWA6;      //xy=844.613639831543,3100.25
AudioSynthWaveformDc     dcOscPWB6;      //xy=845.613639831543,3132.25
AudioSynthWaveformDc     dcOscPWA7;      //xy=852.613639831543,3556.25
AudioAmplifier           lfoPW6;         //xy=854.613639831543,3069.25
AudioSynthWaveformDc     dcOscPWB7;      //xy=853.613639831543,3588.25
AudioAmplifier           lfoPW7;         //xy=862.613639831543,3525.25
AudioMixer4              mixerOscAFreqModB0; //xy=990.613639831543,200.25
AudioMixer4              mixerOscAFreqModA0; //xy=992.613639831543,137.25
AudioMixer4              mixerOscBFreqModA0; //xy=993.613639831543,273.25
AudioMixer4              mixerOscBFreqModB0; //xy=995.613639831543,338.25
AudioMixer4              mixerOscAFreqModB1; //xy=1000.613639831543,650.25
AudioMixer4              mixerOscPWModB0; //xy=1002.613639831543,468.25
AudioMixer4              mixerOscAFreqModA1; //xy=1002.613639831543,587.25
AudioMixer4              mixerOscPWModA0; //xy=1004.613639831543,407.25
AudioMixer4              mixerOscBFreqModA1; //xy=1003.613639831543,723.25
AudioMixer4              mixerOscBFreqModB1; //xy=1005.613639831543,788.25
AudioMixer4              mixerOscPWModB1; //xy=1012.613639831543,919.25
AudioMixer4              mixerOscPWModA1; //xy=1014.613639831543,858.25
AudioMixer4              mixerOscAFreqModB2; //xy=1020.613639831543,1095.25
AudioMixer4              mixerOscAFreqModA2; //xy=1022.613639831543,1032.25
AudioMixer4              mixerOscAFreqModB3; //xy=1020.613639831543,1533.25
AudioMixer4              mixerOscBFreqModA2; //xy=1023.613639831543,1168.25
AudioMixer4              mixerOscAFreqModA3; //xy=1022.613639831543,1470.25
AudioMixer4              mixerOscBFreqModA3; //xy=1023.613639831543,1606.25
AudioMixer4              mixerOscBFreqModB2; //xy=1025.613639831543,1233.25
AudioMixer4              mixerOscBFreqModB3; //xy=1025.613639831543,1671.25
AudioMixer4              mixerOscPWModB2; //xy=1032.613639831543,1364.25
AudioMixer4              mixerOscPWModB3; //xy=1032.613639831543,1802.25
AudioMixer4              mixerOscPWModA2; //xy=1034.613639831543,1303.25
AudioMixer4              mixerOscPWModA3; //xy=1034.613639831543,1741.25
AudioMixer4              mixerOscAFreqModB4; //xy=1040.613639831543,1972.25
AudioMixer4              mixerOscAFreqModA4; //xy=1042.613639831543,1909.25
AudioMixer4              mixerOscBFreqModA4; //xy=1043.613639831543,2045.25
AudioMixer4              mixerOscBFreqModB4; //xy=1045.613639831543,2110.25
AudioMixer4              mixerOscAFreqModB5; //xy=1045.613639831543,2412.25
AudioMixer4              mixerOscAFreqModA5; //xy=1047.613639831543,2349.25
AudioMixer4              mixerOscBFreqModA5; //xy=1048.613639831543,2485.25
AudioMixer4              mixerOscBFreqModB5; //xy=1050.613639831543,2550.25
AudioMixer4              mixerOscPWModB4; //xy=1052.613639831543,2241.25
AudioMixer4              mixerOscPWModA4; //xy=1054.613639831543,2180.25
AudioMixer4              mixerOscPWModB5; //xy=1057.613639831543,2681.25
AudioMixer4              mixerOscPWModA5; //xy=1059.613639831543,2620.25
AudioMixer4              mixerOscAFreqModB6; //xy=1059.613639831543,2850.25
AudioMixer4              mixerOscAFreqModA6; //xy=1061.613639831543,2787.25
AudioMixer4              mixerOscBFreqModA6; //xy=1062.613639831543,2923.25
AudioMixer4              mixerOscBFreqModB6; //xy=1064.613639831543,2988.25
AudioMixer4              mixerOscAFreqModB7; //xy=1067.613639831543,3306.25
AudioMixer4              mixerOscAFreqModA7; //xy=1069.613639831543,3243.25
AudioMixer4              mixerOscPWModB6; //xy=1071.613639831543,3119.25
AudioMixer4              mixerOscBFreqModA7; //xy=1070.613639831543,3379.25
AudioMixer4              mixerOscPWModA6; //xy=1073.613639831543,3058.25
AudioMixer4              mixerOscBFreqModB7; //xy=1072.613639831543,3444.25
AudioMixer4              mixerOscPWModB7; //xy=1079.613639831543,3575.25
AudioMixer4              mixerOscPWModA7; //xy=1081.613639831543,3514.25
AudioSynthWaveformDc     dcFilterAft0;   //xy=1192.613639831543,134.25
AudioSynthWaveformDc     dcFilterEnv0;   //xy=1198.613639831543,170.25
AudioSynthWaveformDc     dcFilterKbd0;   //xy=1198.613639831543,203.25
AudioSynthWaveformDc     dcFilterVel0;   //xy=1202.613639831543,239.25
AudioSynthWaveformDc     dcFilterAft1;   //xy=1202.613639831543,585.25
AudioSynthWaveformModulated oscA0;          //xy=1205.613639831543,325.25
AudioAmplifier           lfoFilterFreq0; //xy=1206.613639831543,99.25
AudioSynthWaveformModulated oscB0;          //xy=1206.613639831543,366.25
AudioSynthWaveformDc     dcFilterEnv1;   //xy=1208.613639831543,621.25
AudioSynthWaveformDc     dcFilterKbd1;   //xy=1208.613639831543,654.25
AudioSynthNoisePink      pink0;          //xy=1210.613639831543,403.25
AudioSynthWaveformDc     dcFilterVel1;   //xy=1212.613639831543,690.25
AudioSynthWaveformModulated oscA1;          //xy=1215.613639831543,775.25
AudioAmplifier           lfoFilterFreq1; //xy=1216.613639831543,550.25
AudioSynthWaveformModulated oscB1;          //xy=1216.613639831543,816.25
AudioSynthNoisePink      pink1;          //xy=1220.613639831543,853.25
AudioSynthWaveformDc     dcFilterAft2;   //xy=1222.613639831543,1030.25
AudioSynthWaveformDc     dcFilterAft3;   //xy=1222.613639831543,1468.25
AudioSynthWaveformDc     dcFilterEnv2;   //xy=1228.613639831543,1066.25
AudioSynthWaveformDc     dcFilterKbd2;   //xy=1228.613639831543,1099.25
AudioSynthWaveformDc     dcFilterEnv3;   //xy=1228.613639831543,1504.25
AudioSynthWaveformDc     dcFilterKbd3;   //xy=1228.613639831543,1537.25
AudioSynthWaveformDc     dcFilterVel2;   //xy=1232.613639831543,1135.25
AudioSynthWaveformDc     dcFilterVel3;   //xy=1232.613639831543,1573.25
AudioSynthWaveformModulated oscA2;          //xy=1235.613639831543,1220.25
AudioAmplifier           lfoFilterFreq2; //xy=1236.613639831543,995.25
AudioSynthWaveformModulated oscB2;          //xy=1236.613639831543,1261.25
AudioSynthWaveformModulated oscA3;          //xy=1235.613639831543,1658.25
AudioAmplifier           lfoFilterFreq3; //xy=1236.613639831543,1433.25
AudioSynthWaveformModulated oscB3;          //xy=1236.613639831543,1699.25
AudioSynthNoisePink      pink2;          //xy=1240.613639831543,1298.25
AudioSynthNoisePink      pink3;          //xy=1240.613639831543,1736.25
AudioSynthWaveformDc     dcFilterAft4;   //xy=1242.613639831543,1907.25
AudioSynthWaveformDc     dcFilterEnv4;   //xy=1248.613639831543,1943.25
AudioSynthWaveformDc     dcFilterKbd4;   //xy=1248.613639831543,1976.25
AudioSynthWaveformDc     dcFilterAft5;   //xy=1247.613639831543,2347.25
AudioSynthWaveformDc     dcFilterVel4;   //xy=1252.613639831543,2012.25
AudioSynthWaveformDc     dcFilterEnv5;   //xy=1253.613639831543,2383.25
AudioSynthWaveformDc     dcFilterKbd5;   //xy=1253.613639831543,2416.25
AudioSynthWaveformModulated oscA4;          //xy=1255.613639831543,2097.25
AudioAmplifier           lfoFilterFreq4; //xy=1256.613639831543,1872.25
AudioSynthWaveformModulated oscB4;          //xy=1256.613639831543,2138.25
AudioSynthWaveformDc     dcFilterVel5;   //xy=1257.613639831543,2452.25
AudioSynthNoisePink      pink4;          //xy=1260.613639831543,2175.25
AudioSynthWaveformModulated oscA5;          //xy=1260.613639831543,2537.25
AudioAmplifier           lfoFilterFreq5; //xy=1261.613639831543,2312.25
AudioSynthWaveformModulated oscB5;          //xy=1261.613639831543,2578.25
AudioSynthWaveformDc     dcFilterAft6;   //xy=1261.613639831543,2785.25
AudioSynthNoisePink      pink5;          //xy=1265.613639831543,2615.25
AudioSynthWaveformDc     dcFilterEnv6;   //xy=1267.613639831543,2821.25
AudioSynthWaveformDc     dcFilterKbd6;   //xy=1267.613639831543,2854.25
AudioSynthWaveformDc     dcFilterAft7;   //xy=1269.613639831543,3241.25
AudioSynthWaveformDc     dcFilterVel6;   //xy=1271.613639831543,2890.25
AudioSynthWaveformModulated oscA6;          //xy=1274.613639831543,2975.25
AudioAmplifier           lfoFilterFreq6; //xy=1275.613639831543,2750.25
AudioSynthWaveformModulated oscB6;          //xy=1275.613639831543,3016.25
AudioSynthWaveformDc     dcFilterEnv7;   //xy=1275.613639831543,3277.25
AudioSynthWaveformDc     dcFilterKbd7;   //xy=1275.613639831543,3310.25
AudioSynthNoisePink      pink6;          //xy=1279.613639831543,3053.25
AudioSynthWaveformDc     dcFilterVel7;   //xy=1279.613639831543,3346.25
AudioSynthWaveformModulated oscA7;          //xy=1282.613639831543,3431.25
AudioAmplifier           lfoFilterFreq7; //xy=1283.613639831543,3206.25
AudioSynthWaveformModulated oscB7;          //xy=1283.613639831543,3472.25
AudioSynthNoisePink      pink7;          //xy=1287.613639831543,3509.25
AudioEffectEnvelope      envelopeFilter0; //xy=1361.613639831543,167.25
AudioEffectEnvelope      envelopeFilter1; //xy=1371.613639831543,618.25
AudioMixer4              mixerOsc0;      //xy=1375.613639831543,375.25
AudioMixer4              mixerOsc1;      //xy=1385.613639831543,825.25
AudioEffectEnvelope      envelopeFilter2; //xy=1391.613639831543,1063.25
AudioEffectEnvelope      envelopeFilter3; //xy=1391.613639831543,1501.25
AudioMixer4              mixerOsc2;      //xy=1405.613639831543,1270.25
AudioMixer4              mixerOsc3;      //xy=1405.613639831543,1708.25
AudioEffectEnvelope      envelopeFilter4; //xy=1411.613639831543,1940.25
AudioEffectEnvelope      envelopeFilter5; //xy=1416.613639831543,2380.25
AudioMixer4              mixerOsc4;      //xy=1425.613639831543,2147.25
AudioMixer4              mixerOsc5;      //xy=1430.613639831543,2587.25
AudioEffectEnvelope      envelopeFilter6; //xy=1430.613639831543,2818.25
AudioEffectEnvelope      envelopeFilter7; //xy=1438.613639831543,3274.25
AudioMixer4              mixerOsc6;      //xy=1444.613639831543,3025.25
AudioMixer4              mixerOsc7;      //xy=1452.613639831543,3481.25
AudioMixer4              mixerFilterFreqA0; //xy=1550.613639831543,122.25
AudioMixer4              mixerFilterFreqB0; //xy=1550.613639831543,183.25
AudioMixer4              mixerFilterRes0; //xy=1557.613639831543,243.25
AudioMixer4              mixerFilterFreqA1; //xy=1560.613639831543,573.25
AudioMixer4              mixerFilterFreqB1; //xy=1560.613639831543,634.25
AudioMixer4              mixerFilterRes1; //xy=1567.613639831543,694.25
AudioMixer4              mixerFilterFreqA2; //xy=1580.613639831543,1018.25
AudioMixer4              mixerFilterFreqB2; //xy=1580.613639831543,1079.25
AudioMixer4              mixerFilterFreqA3; //xy=1580.613639831543,1456.25
AudioMixer4              mixerFilterFreqB3; //xy=1580.613639831543,1517.25
AudioFilterLadder        ladder0;        //xy=1585.613639831543,388.25
AudioMixer4              mixerFilterRes2; //xy=1587.613639831543,1139.25
AudioMixer4              mixerFilterRes3; //xy=1587.613639831543,1577.25
AudioFilterLadder        ladder1;        //xy=1595.613639831543,839.25
AudioMixer4              mixerFilterFreqA4; //xy=1600.613639831543,1895.25
AudioMixer4              mixerFilterFreqB4; //xy=1600.613639831543,1956.25
AudioMixer4              mixerFilterFreqA5; //xy=1605.613639831543,2335.25
AudioMixer4              mixerFilterFreqB5; //xy=1605.613639831543,2396.25
AudioMixer4              mixerFilterRes4; //xy=1607.613639831543,2016.25
AudioFilterLadder        ladder2;        //xy=1615.613639831543,1284.25
AudioMixer4              mixerFilterRes5; //xy=1612.613639831543,2456.25
AudioFilterLadder        ladder3;        //xy=1615.613639831543,1722.25
AudioMixer4              mixerFilterFreqA6; //xy=1619.613639831543,2773.25
AudioMixer4              mixerFilterFreqB6; //xy=1619.613639831543,2834.25
AudioMixer4              mixerFilterRes6; //xy=1626.613639831543,2894.25
AudioMixer4              mixerFilterFreqA7; //xy=1627.613639831543,3229.25
AudioMixer4              mixerFilterFreqB7; //xy=1627.613639831543,3290.25
AudioFilterLadder        ladder4;        //xy=1635.613639831543,2161.25
AudioMixer4              mixerFilterRes7; //xy=1634.613639831543,3350.25
AudioFilterLadder        ladder5;        //xy=1640.613639831543,2601.25
AudioFilterLadder        ladder6;        //xy=1654.613639831543,3039.25
AudioFilterLadder        ladder7;        //xy=1662.613639831543,3495.25
AudioEffectEnvelope      envelopeVol0;   //xy=1741.613639831543,388.25
AudioEffectEnvelope      envelopeVol1;   //xy=1755.613639831543,834.25
AudioEffectEnvelope      envelopeVol2;   //xy=1789.613639831543,1284.25
AudioEffectEnvelope      envelopeVol3;   //xy=1801.613639831543,1722.25
AudioEffectEnvelope      envelopeVol5;   //xy=1798.613639831543,2603.25
AudioEffectEnvelope      envelopeVol6;   //xy=1805.613639831543,3039.25
AudioEffectEnvelope      envelopeVol4;   //xy=1817.613639831543,2164.25
AudioEffectEnvelope      envelopeVol7;   //xy=1818.613639831543,3492.25
AudioMixer4              mixerOscLeft1;  //xy=2018.613639831543,413.25
AudioMixer4              mixerOscRight1; //xy=2019.613639831543,471.25
AudioAmplifier           secondaryVol;   //xy=2008.613639831543,3481.25
AudioAmplifier           bypassFx7;      //xy=2011.613639831543,3387.25
AudioMixer4              mixerOscLeft2;  //xy=2034.613639831543,2183.25
AudioMixer4              mixerOscRight2; //xy=2038.613639831543,2247.25
AudioMixer4              mixerOscRightMaster; //xy=2250.613639831543,491.25
AudioMixer4              mixerOscLeftMaster; //xy=2251.613639831543,427.25
AudioEffectWaveshaper    waveshapeR;     //xy=2492.613639831543,528.25
AudioEffectWaveshaper    waveshapeL;     //xy=2502.613639831543,365.25
AudioMixer4              mixerWaveshapeR; //xy=2513.613639831543,478.25
AudioMixer4              mixerWaveshapeL; //xy=2515.613639831543,416.25
AudioAmplifier           wahAttenuatorR; //xy=2654.613639831543,582.25
AudioAmplifier           wahAttenuatorL; //xy=2667.613639831543,282.25
AudioFilterStateVariable filterL;        //xy=2815.613639831543,291.25
AudioFilterStateVariable filterR;        //xy=2817.613639831543,585.25
AudioMixer4              mixerWahR;      //xy=2848.613639831543,494.25
AudioMixer4              mixerWahL;      //xy=2856.613639831543,406.25
AudioMixer4              mixerPhaserR;   //xy=3016.613639831543,479.25
AudioMixer4              mixerPhaserL;   //xy=3017.613639831543,417.25
AudioMixer4              mixerChorusR;   //xy=3205.613639831543,482.25
AudioMixer4              mixerChorusL;   //xy=3206.613639831543,419.25
AudioSynthWaveformModulated tremoloLFO;     //xy=3349.613639831543,629.25
AudioSynthWaveformDc     dcTremoloOff;   //xy=3349.613639831543,660.25
AudioMixer4              mixerTremoloLFO; //xy=3355.613639831543,565.25
AudioEffectMultiply      tremoloL;       //xy=3400.613639831543,423.25
AudioEffectMultiply      tremoloR;       //xy=3403.613639831543,485.25
AudioMixer4              mixerPreDelayR; //xy=3580.613639831543,540.25
AudioMixer4              mixerPreDelayL; //xy=3582.613639831543,379.25
AudioEffectDelay         delayR;         //xy=3720.613639831543,623.25
AudioEffectDelay         delayL;         //xy=3730.613639831543,280.25
AudioAmplifier           delayFeedbackR; //xy=3805.613639831543,517.25
AudioAmplifier           delayFeedbackL; //xy=3812.613639831543,397.25
AudioSynthWaveformDc     dcPanPhase;     //xy=3811.613639831543,774.25
AudioMixer4              mixerDelayRA;   //xy=3862.613639831543,595.25
AudioMixer4              mixerDelayLA;   //xy=3870.613639831543,254.25
AudioSynthWaveformDc     dcPanOffL;      //xy=3977.613639831543,674.25
AudioSynthWaveformDc     dcPanOffR;      //xy=3979.613639831543,750.25
AudioSynthWaveformModulated panLFOL;        //xy=3980.613639831543,705.25
AudioSynthWaveformModulated panLFOR;        //xy=3981.613639831543,783.25
AudioMixer4              mixerDelayRB;   //xy=4027.613639831543,501.25
AudioMixer4              mixerDelayLB;   //xy=4030.613639831543,441.25
AudioMixer4              mixerPanR;      //xy=4150.613639831543,766.25
AudioMixer4              mixerPanL;      //xy=4151.613639831543,707.25
AudioEffectMultiply      panR;           //xy=4196.613639831543,508.25
AudioEffectMultiply      panL;           //xy=4197.613639831543,446.25
AudioEffectFreeverb      freeverbR;      //xy=4333.613639831543,572.25
AudioEffectFreeverb      freeverbL;      //xy=4339.613639831543,407.25
AudioMixer4              mixerReverbL;   //xy=4466.613639831543,458.25
AudioMixer4              mixerReverbR;   //xy=4466.613639831543,523.25
AudioMixer4              masterVolR;     //xy=4679.613639831543,537.25
AudioMixer4              masterVolL;     //xy=4680.613639831543,474.25
AudioOutputI2S           i2s1;           //xy=4847.613639831543,488.25
AudioConnection          patchCord1(leslieDetuneMaster, leslieDetune1);
AudioConnection          patchCord2(leslieDetuneMaster, leslieDetune0);
AudioConnection          patchCord3(leslieDetuneMaster, leslieDetune2);
AudioConnection          patchCord4(leslieDetuneMaster, leslieDetune3);
AudioConnection          patchCord5(leslieDetuneMaster, leslieDetune4);
AudioConnection          patchCord6(leslieDetuneMaster, leslieDetune5);
AudioConnection          patchCord7(leslieDetuneMaster, leslieDetune6);
AudioConnection          patchCord8(leslieDetuneMaster, bypassLeslie7);
AudioConnection          patchCord9(lfo, lfoMaster0);
AudioConnection          patchCord10(lfo, lfoMaster1);
AudioConnection          patchCord11(lfo, lfoMaster2);
AudioConnection          patchCord12(lfo, lfoMaster3);
AudioConnection          patchCord13(lfo, lfoMaster4);
AudioConnection          patchCord14(lfo, lfoMaster5);
AudioConnection          patchCord15(lfo, lfoMaster6);
AudioConnection          patchCord16(lfo, lfoMaster7);
AudioConnection          patchCord17(lfo, lfoPeak);
AudioConnection          patchCord18(lfoMaster7, 0, mixerLfoMaster7, 0);
AudioConnection          patchCord19(secondaryLfo, 0, mixerLfoMaster7, 1);
AudioConnection          patchCord20(secondaryLfo, secondardyLfoPos);
AudioConnection          patchCord21(lfoMaster0, lfoFreq0);
AudioConnection          patchCord22(lfoMaster0, lfoPW0);
AudioConnection          patchCord23(lfoMaster0, lfoFilterFreq0);
AudioConnection          patchCord24(lfoMaster1, lfoFreq1);
AudioConnection          patchCord25(lfoMaster1, lfoPW1);
AudioConnection          patchCord26(lfoMaster1, lfoFilterFreq1);
AudioConnection          patchCord27(lfoMaster2, lfoFreq2);
AudioConnection          patchCord28(lfoMaster2, lfoPW2);
AudioConnection          patchCord29(lfoMaster2, lfoFilterFreq2);
AudioConnection          patchCord30(lfoMaster3, lfoFreq3);
AudioConnection          patchCord31(lfoMaster3, lfoPW3);
AudioConnection          patchCord32(lfoMaster3, lfoFilterFreq3);
AudioConnection          patchCord33(lfoMaster4, lfoFreq4);
AudioConnection          patchCord34(lfoMaster4, lfoPW4);
AudioConnection          patchCord35(lfoMaster4, lfoFilterFreq4);
AudioConnection          patchCord36(lfoMaster5, lfoFreq5);
AudioConnection          patchCord37(lfoMaster5, lfoPW5);
AudioConnection          patchCord38(lfoMaster5, lfoFilterFreq5);
AudioConnection          patchCord39(lfoMaster6, lfoFreq6);
AudioConnection          patchCord40(lfoMaster6, lfoPW6);
AudioConnection          patchCord41(lfoMaster6, lfoFilterFreq6);
AudioConnection          patchCord42(mixerLfoMaster7, lfoFreq7);
AudioConnection          patchCord43(mixerLfoMaster7, lfoPW7);
AudioConnection          patchCord44(mixerLfoMaster7, lfoFilterFreq7);
AudioConnection          patchCord45(bypassLeslie7, leslieDetune7);
AudioConnection          patchCord46(dcPitchOctaveA0, 0, mixerOscAFreqModA0, 1);
AudioConnection          patchCord47(dcPitchOctaveB0, 0, mixerOscBFreqModA0, 1);
AudioConnection          patchCord48(dcPitchDetuneA0, 0, mixerOscAFreqModA0, 3);
AudioConnection          patchCord49(dcPitchDetuneB0, 0, mixerOscBFreqModA0, 3);
AudioConnection          patchCord50(dcPitchBend0, 0, mixerOscBFreqModA0, 0);
AudioConnection          patchCord51(dcPitchBend0, 0, mixerOscAFreqModA0, 0);
AudioConnection          patchCord52(leslieDetune0, 0, mixerOscAFreqModB0, 1);
AudioConnection          patchCord53(leslieDetune0, 0, mixerOscBFreqModB0, 1);
AudioConnection          patchCord54(dcPitchOctaveA1, 0, mixerOscAFreqModA1, 1);
AudioConnection          patchCord55(dcPitchOctaveB1, 0, mixerOscBFreqModA1, 1);
AudioConnection          patchCord56(dcPitchDetuneA1, 0, mixerOscAFreqModA1, 3);
AudioConnection          patchCord57(dcPitchDetuneB1, 0, mixerOscBFreqModA1, 3);
AudioConnection          patchCord58(dcPitchBend1, 0, mixerOscBFreqModA1, 0);
AudioConnection          patchCord59(dcPitchBend1, 0, mixerOscAFreqModA1, 0);
AudioConnection          patchCord60(leslieDetune1, 0, mixerOscAFreqModB1, 1);
AudioConnection          patchCord61(leslieDetune1, 0, mixerOscBFreqModB1, 1);
AudioConnection          patchCord62(lfoFreq0, 0, mixerOscAFreqModA0, 2);
AudioConnection          patchCord63(lfoFreq0, 0, mixerOscBFreqModA0, 2);
AudioConnection          patchCord64(dcPorta0, 0, mixerOscBFreqModB0, 3);
AudioConnection          patchCord65(dcPorta0, 0, mixerOscAFreqModB0, 3);
AudioConnection          patchCord66(dcPitchOctaveA2, 0, mixerOscAFreqModA2, 1);
AudioConnection          patchCord67(dcPitchOctaveB2, 0, mixerOscBFreqModA2, 1);
AudioConnection          patchCord68(dcPitchOctaveA3, 0, mixerOscAFreqModA3, 1);
AudioConnection          patchCord69(dcPitchOctaveB3, 0, mixerOscBFreqModA3, 1);
AudioConnection          patchCord70(dcPitchDetuneA2, 0, mixerOscAFreqModA2, 3);
AudioConnection          patchCord71(dcPitchDetuneB2, 0, mixerOscBFreqModA2, 3);
AudioConnection          patchCord72(dcPitchDetuneA3, 0, mixerOscAFreqModA3, 3);
AudioConnection          patchCord73(dcOscPWA0, 0, mixerOscPWModA0, 1);
AudioConnection          patchCord74(dcPitchDetuneB3, 0, mixerOscBFreqModA3, 3);
AudioConnection          patchCord75(lfoFreq1, 0, mixerOscAFreqModA1, 2);
AudioConnection          patchCord76(lfoFreq1, 0, mixerOscBFreqModA1, 2);
AudioConnection          patchCord77(dcOscPWB0, 0, mixerOscPWModB0, 1);
AudioConnection          patchCord78(dcPitchBend2, 0, mixerOscBFreqModA2, 0);
AudioConnection          patchCord79(dcPitchBend2, 0, mixerOscAFreqModA2, 0);
AudioConnection          patchCord80(leslieDetune2, 0, mixerOscAFreqModB2, 1);
AudioConnection          patchCord81(leslieDetune2, 0, mixerOscBFreqModB2, 1);
AudioConnection          patchCord82(dcPitchBend3, 0, mixerOscBFreqModA3, 0);
AudioConnection          patchCord83(dcPitchBend3, 0, mixerOscAFreqModA3, 0);
AudioConnection          patchCord84(leslieDetune3, 0, mixerOscAFreqModB3, 1);
AudioConnection          patchCord85(leslieDetune3, 0, mixerOscBFreqModB3, 1);
AudioConnection          patchCord86(lfoPW0, 0, mixerOscPWModA0, 0);
AudioConnection          patchCord87(lfoPW0, 0, mixerOscPWModB0, 0);
AudioConnection          patchCord88(dcOscPWA1, 0, mixerOscPWModA1, 1);
AudioConnection          patchCord89(dcOscPWB1, 0, mixerOscPWModB1, 1);
AudioConnection          patchCord90(dcPitchOctaveA4, 0, mixerOscAFreqModA4, 1);
AudioConnection          patchCord91(dcPitchOctaveB4, 0, mixerOscBFreqModA4, 1);
AudioConnection          patchCord92(dcPitchDetuneA4, 0, mixerOscAFreqModA4, 3);
AudioConnection          patchCord93(lfoPW1, 0, mixerOscPWModA1, 0);
AudioConnection          patchCord94(lfoPW1, 0, mixerOscPWModB1, 0);
AudioConnection          patchCord95(dcPitchDetuneB4, 0, mixerOscBFreqModA4, 3);
AudioConnection          patchCord96(lfoFreq2, 0, mixerOscAFreqModA2, 2);
AudioConnection          patchCord97(lfoFreq2, 0, mixerOscBFreqModA2, 2);
AudioConnection          patchCord98(lfoFreq3, 0, mixerOscAFreqModA3, 2);
AudioConnection          patchCord99(lfoFreq3, 0, mixerOscBFreqModA3, 2);
AudioConnection          patchCord100(dcPitchOctaveA5, 0, mixerOscAFreqModA5, 1);
AudioConnection          patchCord101(dcPitchOctaveB5, 0, mixerOscBFreqModA5, 1);
AudioConnection          patchCord102(dcPitchBend4, 0, mixerOscBFreqModA4, 0);
AudioConnection          patchCord103(dcPitchBend4, 0, mixerOscAFreqModA4, 0);
AudioConnection          patchCord104(dcPitchDetuneA5, 0, mixerOscAFreqModA5, 3);
AudioConnection          patchCord105(leslieDetune4, 0, mixerOscAFreqModB4, 1);
AudioConnection          patchCord106(leslieDetune4, 0, mixerOscBFreqModB4, 1);
AudioConnection          patchCord107(dcPitchDetuneB5, 0, mixerOscBFreqModA5, 3);
AudioConnection          patchCord108(dcOscPWA2, 0, mixerOscPWModA2, 1);
AudioConnection          patchCord109(dcPitchBend5, 0, mixerOscBFreqModA5, 0);
AudioConnection          patchCord110(dcPitchBend5, 0, mixerOscAFreqModA5, 0);
AudioConnection          patchCord111(dcOscPWB2, 0, mixerOscPWModB2, 1);
AudioConnection          patchCord112(leslieDetune5, 0, mixerOscAFreqModB5, 1);
AudioConnection          patchCord113(leslieDetune5, 0, mixerOscBFreqModB5, 1);
AudioConnection          patchCord114(dcOscPWA3, 0, mixerOscPWModA3, 1);
AudioConnection          patchCord115(dcOscPWB3, 0, mixerOscPWModB3, 1);
AudioConnection          patchCord116(dcPitchOctaveA6, 0, mixerOscAFreqModA6, 1);
AudioConnection          patchCord117(dcPitchOctaveB6, 0, mixerOscBFreqModA6, 1);
AudioConnection          patchCord118(lfoPW2, 0, mixerOscPWModA2, 0);
AudioConnection          patchCord119(lfoPW2, 0, mixerOscPWModB2, 0);
AudioConnection          patchCord120(dcPitchDetuneA6, 0, mixerOscAFreqModA6, 3);
AudioConnection          patchCord121(dcPitchDetuneB6, 0, mixerOscBFreqModA6, 3);
AudioConnection          patchCord122(lfoPW3, 0, mixerOscPWModA3, 0);
AudioConnection          patchCord123(lfoPW3, 0, mixerOscPWModB3, 0);
AudioConnection          patchCord124(lfoFreq4, 0, mixerOscAFreqModA4, 2);
AudioConnection          patchCord125(lfoFreq4, 0, mixerOscBFreqModA4, 2);
AudioConnection          patchCord126(dcPitchOctaveA7, 0, mixerOscAFreqModA7, 1);
AudioConnection          patchCord127(dcPitchBend6, 0, mixerOscBFreqModA6, 0);
AudioConnection          patchCord128(dcPitchBend6, 0, mixerOscAFreqModA6, 0);
AudioConnection          patchCord129(leslieDetune6, 0, mixerOscAFreqModB6, 1);
AudioConnection          patchCord130(leslieDetune6, 0, mixerOscBFreqModB6, 1);
AudioConnection          patchCord131(dcPitchOctaveB7, 0, mixerOscBFreqModA7, 1);
AudioConnection          patchCord132(lfoFreq5, 0, mixerOscAFreqModA5, 2);
AudioConnection          patchCord133(lfoFreq5, 0, mixerOscBFreqModA5, 2);
AudioConnection          patchCord134(dcPitchDetuneA7, 0, mixerOscAFreqModA7, 3);
AudioConnection          patchCord135(dcPitchDetuneB7, 0, mixerOscBFreqModA7, 3);
AudioConnection          patchCord136(dcOscPWA4, 0, mixerOscPWModA4, 1);
AudioConnection          patchCord137(dcOscPWB4, 0, mixerOscPWModB4, 1);
AudioConnection          patchCord138(dcPitchBend7, 0, mixerOscBFreqModA7, 0);
AudioConnection          patchCord139(dcPitchBend7, 0, mixerOscAFreqModA7, 0);
AudioConnection          patchCord140(leslieDetune7, 0, mixerOscAFreqModB7, 1);
AudioConnection          patchCord141(leslieDetune7, 0, mixerOscBFreqModB7, 1);
AudioConnection          patchCord142(dcOscPWA5, 0, mixerOscPWModA5, 1);
AudioConnection          patchCord143(dcOscPWB5, 0, mixerOscPWModB5, 1);
AudioConnection          patchCord144(lfoPW4, 0, mixerOscPWModA4, 0);
AudioConnection          patchCord145(lfoPW4, 0, mixerOscPWModB4, 0);
AudioConnection          patchCord146(lfoFreq6, 0, mixerOscAFreqModA6, 2);
AudioConnection          patchCord147(lfoFreq6, 0, mixerOscBFreqModA6, 2);
AudioConnection          patchCord148(lfoPW5, 0, mixerOscPWModA5, 0);
AudioConnection          patchCord149(lfoPW5, 0, mixerOscPWModB5, 0);
AudioConnection          patchCord150(lfoFreq7, 0, mixerOscAFreqModA7, 2);
AudioConnection          patchCord151(lfoFreq7, 0, mixerOscBFreqModA7, 2);
AudioConnection          patchCord152(dcPorta7, 0, mixerOscAFreqModB7, 3);
AudioConnection          patchCord153(dcPorta7, 0, mixerOscBFreqModB7, 3);
AudioConnection          patchCord154(dcOscPWA6, 0, mixerOscPWModA6, 1);
AudioConnection          patchCord155(dcOscPWB6, 0, mixerOscPWModB6, 1);
AudioConnection          patchCord156(dcOscPWA7, 0, mixerOscPWModA7, 1);
AudioConnection          patchCord157(lfoPW6, 0, mixerOscPWModA6, 0);
AudioConnection          patchCord158(lfoPW6, 0, mixerOscPWModB6, 0);
AudioConnection          patchCord159(dcOscPWB7, 0, mixerOscPWModB7, 1);
AudioConnection          patchCord160(lfoPW7, 0, mixerOscPWModA7, 0);
AudioConnection          patchCord161(lfoPW7, 0, mixerOscPWModB7, 0);
AudioConnection          patchCord162(mixerOscAFreqModB0, 0, oscA0, 0);
AudioConnection          patchCord163(mixerOscAFreqModA0, 0, mixerOscAFreqModB0, 0);
AudioConnection          patchCord164(mixerOscBFreqModA0, 0, mixerOscBFreqModB0, 0);
AudioConnection          patchCord165(mixerOscBFreqModB0, 0, oscB0, 0);
AudioConnection          patchCord166(mixerOscAFreqModB1, 0, oscA1, 0);
AudioConnection          patchCord167(mixerOscPWModB0, 0, oscB0, 1);
AudioConnection          patchCord168(mixerOscAFreqModA1, 0, mixerOscAFreqModB1, 0);
AudioConnection          patchCord169(mixerOscPWModA0, 0, oscA0, 1);
AudioConnection          patchCord170(mixerOscBFreqModA1, 0, mixerOscBFreqModB1, 0);
AudioConnection          patchCord171(mixerOscBFreqModB1, 0, oscB1, 0);
AudioConnection          patchCord172(mixerOscPWModB1, 0, oscB1, 1);
AudioConnection          patchCord173(mixerOscPWModA1, 0, oscA1, 1);
AudioConnection          patchCord174(mixerOscAFreqModB2, 0, oscA2, 0);
AudioConnection          patchCord175(mixerOscAFreqModA2, 0, mixerOscAFreqModB2, 0);
AudioConnection          patchCord176(mixerOscAFreqModB3, 0, oscA3, 0);
AudioConnection          patchCord177(mixerOscBFreqModA2, 0, mixerOscBFreqModB2, 0);
AudioConnection          patchCord178(mixerOscAFreqModA3, 0, mixerOscAFreqModB3, 0);
AudioConnection          patchCord179(mixerOscBFreqModA3, 0, mixerOscBFreqModB3, 0);
AudioConnection          patchCord180(mixerOscBFreqModB2, 0, oscB2, 0);
AudioConnection          patchCord181(mixerOscBFreqModB3, 0, oscB3, 0);
AudioConnection          patchCord182(mixerOscPWModB2, 0, oscB2, 1);
AudioConnection          patchCord183(mixerOscPWModB3, 0, oscB3, 1);
AudioConnection          patchCord184(mixerOscPWModA2, 0, oscA2, 1);
AudioConnection          patchCord185(mixerOscPWModA3, 0, oscA3, 1);
AudioConnection          patchCord186(mixerOscAFreqModB4, 0, oscA4, 0);
AudioConnection          patchCord187(mixerOscAFreqModA4, 0, mixerOscAFreqModB4, 0);
AudioConnection          patchCord188(mixerOscBFreqModA4, 0, mixerOscBFreqModB4, 0);
AudioConnection          patchCord189(mixerOscBFreqModB4, 0, oscB4, 0);
AudioConnection          patchCord190(mixerOscAFreqModB5, 0, oscA5, 0);
AudioConnection          patchCord191(mixerOscAFreqModA5, 0, mixerOscAFreqModB5, 0);
AudioConnection          patchCord192(mixerOscBFreqModA5, 0, mixerOscBFreqModB5, 0);
AudioConnection          patchCord193(mixerOscBFreqModB5, 0, oscB5, 0);
AudioConnection          patchCord194(mixerOscPWModB4, 0, oscB4, 1);
AudioConnection          patchCord195(mixerOscPWModA4, 0, oscA4, 1);
AudioConnection          patchCord196(mixerOscPWModB5, 0, oscB5, 1);
AudioConnection          patchCord197(mixerOscPWModA5, 0, oscA5, 1);
AudioConnection          patchCord198(mixerOscAFreqModB6, 0, oscA6, 0);
AudioConnection          patchCord199(mixerOscAFreqModA6, 0, mixerOscAFreqModB6, 0);
AudioConnection          patchCord200(mixerOscBFreqModA6, 0, mixerOscBFreqModB6, 0);
AudioConnection          patchCord201(mixerOscBFreqModB6, 0, oscB6, 0);
AudioConnection          patchCord202(mixerOscAFreqModB7, 0, oscA7, 0);
AudioConnection          patchCord203(mixerOscAFreqModA7, 0, mixerOscAFreqModB7, 0);
AudioConnection          patchCord204(mixerOscPWModB6, 0, oscB6, 1);
AudioConnection          patchCord205(mixerOscBFreqModA7, 0, mixerOscBFreqModB7, 0);
AudioConnection          patchCord206(mixerOscPWModA6, 0, oscA6, 1);
AudioConnection          patchCord207(mixerOscBFreqModB7, 0, oscB7, 0);
AudioConnection          patchCord208(mixerOscPWModB7, 0, oscB7, 1);
AudioConnection          patchCord209(mixerOscPWModA7, 0, oscA7, 1);
AudioConnection          patchCord210(dcFilterAft0, 0, mixerFilterFreqA0, 2);
AudioConnection          patchCord211(dcFilterEnv0, envelopeFilter0);
AudioConnection          patchCord212(dcFilterKbd0, 0, mixerFilterFreqA0, 3);
AudioConnection          patchCord213(dcFilterKbd0, 0, mixerFilterRes0, 0);
AudioConnection          patchCord214(dcFilterVel0, 0, mixerFilterFreqB0, 1);
AudioConnection          patchCord215(dcFilterVel0, 0, mixerFilterRes0, 1);
AudioConnection          patchCord216(dcFilterAft1, 0, mixerFilterFreqA1, 2);
AudioConnection          patchCord217(oscA0, 0, mixerOsc0, 0);
AudioConnection          patchCord218(lfoFilterFreq0, 0, mixerFilterFreqA0, 0);
AudioConnection          patchCord219(oscB0, 0, mixerOsc0, 1);
AudioConnection          patchCord220(dcFilterEnv1, envelopeFilter1);
AudioConnection          patchCord221(dcFilterKbd1, 0, mixerFilterFreqA1, 3);
AudioConnection          patchCord222(dcFilterKbd1, 0, mixerFilterRes1, 0);
AudioConnection          patchCord223(pink0, 0, mixerOsc0, 2);
AudioConnection          patchCord224(dcFilterVel1, 0, mixerFilterFreqB1, 1);
AudioConnection          patchCord225(dcFilterVel1, 0, mixerFilterRes1, 1);
AudioConnection          patchCord226(oscA1, 0, mixerOsc1, 0);
AudioConnection          patchCord227(lfoFilterFreq1, 0, mixerFilterFreqA1, 0);
AudioConnection          patchCord228(oscB1, 0, mixerOsc1, 1);
AudioConnection          patchCord229(pink1, 0, mixerOsc1, 2);
AudioConnection          patchCord230(dcFilterAft2, 0, mixerFilterFreqA2, 2);
AudioConnection          patchCord231(dcFilterAft3, 0, mixerFilterFreqA3, 2);
AudioConnection          patchCord232(dcFilterEnv2, envelopeFilter2);
AudioConnection          patchCord233(dcFilterKbd2, 0, mixerFilterFreqA2, 3);
AudioConnection          patchCord234(dcFilterKbd2, 0, mixerFilterRes2, 0);
AudioConnection          patchCord235(dcFilterEnv3, envelopeFilter3);
AudioConnection          patchCord236(dcFilterKbd3, 0, mixerFilterFreqA3, 3);
AudioConnection          patchCord237(dcFilterKbd3, 0, mixerFilterRes3, 0);
AudioConnection          patchCord238(dcFilterVel2, 0, mixerFilterFreqB2, 1);
AudioConnection          patchCord239(dcFilterVel2, 0, mixerFilterRes2, 1);
AudioConnection          patchCord240(dcFilterVel3, 0, mixerFilterFreqB3, 1);
AudioConnection          patchCord241(dcFilterVel3, 0, mixerFilterRes3, 1);
AudioConnection          patchCord242(oscA2, 0, mixerOsc2, 0);
AudioConnection          patchCord243(lfoFilterFreq2, 0, mixerFilterFreqA2, 0);
AudioConnection          patchCord244(oscB2, 0, mixerOsc2, 1);
AudioConnection          patchCord245(oscA3, 0, mixerOsc3, 0);
AudioConnection          patchCord246(lfoFilterFreq3, 0, mixerFilterFreqA3, 0);
AudioConnection          patchCord247(oscB3, 0, mixerOsc3, 1);
AudioConnection          patchCord248(pink2, 0, mixerOsc2, 2);
AudioConnection          patchCord249(pink3, 0, mixerOsc3, 2);
AudioConnection          patchCord250(dcFilterAft4, 0, mixerFilterFreqA4, 2);
AudioConnection          patchCord251(dcFilterEnv4, envelopeFilter4);
AudioConnection          patchCord252(dcFilterKbd4, 0, mixerFilterFreqA4, 3);
AudioConnection          patchCord253(dcFilterKbd4, 0, mixerFilterRes4, 0);
AudioConnection          patchCord254(dcFilterAft5, 0, mixerFilterFreqA5, 2);
AudioConnection          patchCord255(dcFilterVel4, 0, mixerFilterFreqB4, 1);
AudioConnection          patchCord256(dcFilterVel4, 0, mixerFilterRes4, 1);
AudioConnection          patchCord257(dcFilterEnv5, envelopeFilter5);
AudioConnection          patchCord258(dcFilterKbd5, 0, mixerFilterFreqA5, 3);
AudioConnection          patchCord259(dcFilterKbd5, 0, mixerFilterRes5, 0);
AudioConnection          patchCord260(oscA4, 0, mixerOsc4, 0);
AudioConnection          patchCord261(lfoFilterFreq4, 0, mixerFilterFreqA4, 0);
AudioConnection          patchCord262(oscB4, 0, mixerOsc4, 1);
AudioConnection          patchCord263(dcFilterVel5, 0, mixerFilterFreqB5, 1);
AudioConnection          patchCord264(dcFilterVel5, 0, mixerFilterRes5, 1);
AudioConnection          patchCord265(pink4, 0, mixerOsc4, 2);
AudioConnection          patchCord266(oscA5, 0, mixerOsc5, 0);
AudioConnection          patchCord267(lfoFilterFreq5, 0, mixerFilterFreqA5, 0);
AudioConnection          patchCord268(oscB5, 0, mixerOsc5, 1);
AudioConnection          patchCord269(dcFilterAft6, 0, mixerFilterFreqA6, 2);
AudioConnection          patchCord270(pink5, 0, mixerOsc5, 2);
AudioConnection          patchCord271(dcFilterEnv6, envelopeFilter6);
AudioConnection          patchCord272(dcFilterKbd6, 0, mixerFilterFreqA6, 3);
AudioConnection          patchCord273(dcFilterKbd6, 0, mixerFilterRes6, 0);
AudioConnection          patchCord274(dcFilterAft7, 0, mixerFilterFreqA7, 2);
AudioConnection          patchCord275(dcFilterVel6, 0, mixerFilterFreqB6, 1);
AudioConnection          patchCord276(dcFilterVel6, 0, mixerFilterRes6, 1);
AudioConnection          patchCord277(oscA6, 0, mixerOsc6, 0);
AudioConnection          patchCord278(lfoFilterFreq6, 0, mixerFilterFreqA6, 0);
AudioConnection          patchCord279(oscB6, 0, mixerOsc6, 1);
AudioConnection          patchCord280(dcFilterEnv7, envelopeFilter7);
AudioConnection          patchCord281(dcFilterKbd7, 0, mixerFilterFreqA7, 3);
AudioConnection          patchCord282(dcFilterKbd7, 0, mixerFilterRes7, 0);
AudioConnection          patchCord283(pink6, 0, mixerOsc6, 2);
AudioConnection          patchCord284(dcFilterVel7, 0, mixerFilterFreqB7, 1);
AudioConnection          patchCord285(dcFilterVel7, 0, mixerFilterRes7, 1);
AudioConnection          patchCord286(oscA7, 0, mixerOsc7, 0);
AudioConnection          patchCord287(lfoFilterFreq7, 0, mixerFilterFreqA7, 0);
AudioConnection          patchCord288(oscB7, 0, mixerOsc7, 1);
AudioConnection          patchCord289(pink7, 0, mixerOsc7, 2);
AudioConnection          patchCord290(envelopeFilter0, 0, mixerFilterFreqA0, 1);
AudioConnection          patchCord291(envelopeFilter1, 0, mixerFilterFreqA1, 1);
AudioConnection          patchCord292(mixerOsc0, 0, ladder0, 0);
AudioConnection          patchCord293(mixerOsc1, 0, ladder1, 0);
AudioConnection          patchCord294(envelopeFilter2, 0, mixerFilterFreqA2, 1);
AudioConnection          patchCord295(envelopeFilter3, 0, mixerFilterFreqA3, 1);
AudioConnection          patchCord296(mixerOsc2, 0, ladder2, 0);
AudioConnection          patchCord297(mixerOsc3, 0, ladder3, 0);
AudioConnection          patchCord298(envelopeFilter4, 0, mixerFilterFreqA4, 1);
AudioConnection          patchCord299(envelopeFilter5, 0, mixerFilterFreqA5, 1);
AudioConnection          patchCord300(mixerOsc4, 0, ladder4, 0);
AudioConnection          patchCord301(mixerOsc5, 0, ladder5, 0);
AudioConnection          patchCord302(envelopeFilter6, 0, mixerFilterFreqA6, 1);
AudioConnection          patchCord303(envelopeFilter7, 0, mixerFilterFreqA7, 1);
AudioConnection          patchCord304(mixerOsc6, 0, ladder6, 0);
AudioConnection          patchCord305(mixerOsc7, 0, ladder7, 0);
AudioConnection          patchCord306(mixerFilterFreqA0, 0, mixerFilterFreqB0, 0);
AudioConnection          patchCord307(mixerFilterFreqB0, 0, ladder0, 1);
AudioConnection          patchCord308(mixerFilterRes0, 0, ladder0, 2);
AudioConnection          patchCord309(mixerFilterFreqA1, 0, mixerFilterFreqB1, 0);
AudioConnection          patchCord310(mixerFilterFreqB1, 0, ladder1, 1);
AudioConnection          patchCord311(mixerFilterRes1, 0, ladder1, 2);
AudioConnection          patchCord312(mixerFilterFreqA2, 0, mixerFilterFreqB2, 0);
AudioConnection          patchCord313(mixerFilterFreqB2, 0, ladder2, 1);
AudioConnection          patchCord314(mixerFilterFreqA3, 0, mixerFilterFreqB3, 0);
AudioConnection          patchCord315(mixerFilterFreqB3, 0, ladder3, 1);
AudioConnection          patchCord316(ladder0, envelopeVol0);
AudioConnection          patchCord317(mixerFilterRes2, 0, ladder2, 2);
AudioConnection          patchCord318(mixerFilterRes3, 0, ladder3, 2);
AudioConnection          patchCord319(ladder1, envelopeVol1);
AudioConnection          patchCord320(mixerFilterFreqA4, 0, mixerFilterFreqB4, 0);
AudioConnection          patchCord321(mixerFilterFreqB4, 0, ladder4, 1);
AudioConnection          patchCord322(mixerFilterFreqA5, 0, mixerFilterFreqB5, 0);
AudioConnection          patchCord323(mixerFilterFreqB5, 0, ladder5, 1);
AudioConnection          patchCord324(mixerFilterRes4, 0, ladder4, 2);
AudioConnection          patchCord325(ladder2, envelopeVol2);
AudioConnection          patchCord326(mixerFilterRes5, 0, ladder5, 2);
AudioConnection          patchCord327(ladder3, envelopeVol3);
AudioConnection          patchCord328(mixerFilterFreqA6, 0, mixerFilterFreqB6, 0);
AudioConnection          patchCord329(mixerFilterFreqB6, 0, ladder6, 1);
AudioConnection          patchCord330(mixerFilterRes6, 0, ladder6, 2);
AudioConnection          patchCord331(mixerFilterFreqA7, 0, mixerFilterFreqB7, 0);
AudioConnection          patchCord332(mixerFilterFreqB7, 0, ladder7, 1);
AudioConnection          patchCord333(ladder4, envelopeVol4);
AudioConnection          patchCord334(mixerFilterRes7, 0, ladder7, 2);
AudioConnection          patchCord335(ladder5, envelopeVol5);
AudioConnection          patchCord336(ladder6, envelopeVol6);
AudioConnection          patchCord337(ladder7, envelopeVol7);
AudioConnection          patchCord338(envelopeVol0, 0, mixerOscLeft1, 0);
AudioConnection          patchCord339(envelopeVol0, 0, mixerOscRight1, 0);
AudioConnection          patchCord340(envelopeVol1, 0, mixerOscLeft1, 1);
AudioConnection          patchCord341(envelopeVol1, 0, mixerOscRight1, 1);
AudioConnection          patchCord342(envelopeVol2, 0, mixerOscRight1, 2);
AudioConnection          patchCord343(envelopeVol2, 0, mixerOscLeft1, 2);
AudioConnection          patchCord344(envelopeVol3, 0, mixerOscRight1, 3);
AudioConnection          patchCord345(envelopeVol3, 0, mixerOscLeft1, 3);
AudioConnection          patchCord346(envelopeVol5, 0, mixerOscLeft2, 1);
AudioConnection          patchCord347(envelopeVol5, 0, mixerOscRight2, 1);
AudioConnection          patchCord348(envelopeVol6, 0, mixerOscRight2, 2);
AudioConnection          patchCord349(envelopeVol6, 0, mixerOscLeft2, 2);
AudioConnection          patchCord350(envelopeVol4, 0, mixerOscLeft2, 0);
AudioConnection          patchCord351(envelopeVol4, 0, mixerOscRight2, 0);
AudioConnection          patchCord352(envelopeVol7, secondaryVol);
AudioConnection          patchCord353(mixerOscLeft1, 0, mixerOscLeftMaster, 0);
AudioConnection          patchCord354(mixerOscRight1, 0, mixerOscRightMaster, 0);
AudioConnection          patchCord355(secondaryVol, 0, masterVolL, 1);
AudioConnection          patchCord356(secondaryVol, 0, masterVolR, 1);
AudioConnection          patchCord357(secondaryVol, bypassFx7);
AudioConnection          patchCord358(bypassFx7, 0, mixerOscRight2, 3);
AudioConnection          patchCord359(bypassFx7, 0, mixerOscLeft2, 3);
AudioConnection          patchCord360(bypassFx7, 0, mixerOscLeftMaster, 2);
AudioConnection          patchCord361(bypassFx7, 0, mixerOscRightMaster, 2);
AudioConnection          patchCord362(mixerOscLeft2, 0, mixerOscLeftMaster, 1);
AudioConnection          patchCord363(mixerOscRight2, 0, mixerOscRightMaster, 1);
AudioConnection          patchCord364(mixerOscRightMaster, 0, mixerWaveshapeR, 0);
AudioConnection          patchCord365(mixerOscRightMaster, waveshapeR);
AudioConnection          patchCord366(mixerOscLeftMaster, 0, mixerWaveshapeL, 0);
AudioConnection          patchCord367(mixerOscLeftMaster, waveshapeL);
AudioConnection          patchCord368(waveshapeR, 0, mixerWaveshapeR, 1);
AudioConnection          patchCord369(waveshapeL, 0, mixerWaveshapeL, 1);
AudioConnection          patchCord370(mixerWaveshapeR, 0, mixerWahR, 0);
AudioConnection          patchCord371(mixerWaveshapeR, wahAttenuatorR);
AudioConnection          patchCord372(mixerWaveshapeL, 0, mixerWahL, 0);
AudioConnection          patchCord373(mixerWaveshapeL, wahAttenuatorL);
AudioConnection          patchCord374(wahAttenuatorR, 0, filterR, 0);
AudioConnection          patchCord375(wahAttenuatorL, 0, filterL, 0);
AudioConnection          patchCord376(filterL, 1, mixerWahL, 1);
AudioConnection          patchCord377(filterR, 1, mixerWahR, 1);
AudioConnection          patchCord378(mixerWahR, 0, mixerPhaserR, 0);
AudioConnection          patchCord379(mixerWahL, 0, mixerPhaserL, 0);
AudioConnection          patchCord380(mixerPhaserR, 0, mixerChorusR, 0);
AudioConnection          patchCord381(mixerPhaserL, 0, mixerChorusL, 0);
AudioConnection          patchCord382(mixerChorusR, 0, tremoloR, 0);
AudioConnection          patchCord383(mixerChorusL, 0, tremoloL, 0);
AudioConnection          patchCord384(tremoloLFO, 0, mixerTremoloLFO, 0);
AudioConnection          patchCord385(dcTremoloOff, 0, mixerTremoloLFO, 1);
AudioConnection          patchCord386(mixerTremoloLFO, 0, tremoloR, 1);
AudioConnection          patchCord387(mixerTremoloLFO, 0, tremoloL, 1);
AudioConnection          patchCord388(tremoloL, 0, mixerDelayLB, 0);
AudioConnection          patchCord389(tremoloL, 0, mixerPreDelayL, 0);
AudioConnection          patchCord390(tremoloR, 0, mixerDelayRB, 0);
AudioConnection          patchCord391(tremoloR, 0, mixerPreDelayR, 0);
AudioConnection          patchCord392(mixerPreDelayR, delayR);
AudioConnection          patchCord393(mixerPreDelayL, delayL);
AudioConnection          patchCord394(delayR, 0, mixerDelayRA, 0);
AudioConnection          patchCord395(delayR, 1, mixerDelayRA, 1);
AudioConnection          patchCord396(delayR, 2, mixerDelayRA, 2);
AudioConnection          patchCord397(delayR, 3, mixerDelayRA, 3);
AudioConnection          patchCord398(delayL, 0, mixerDelayLA, 0);
AudioConnection          patchCord399(delayL, 1, mixerDelayLA, 1);
AudioConnection          patchCord400(delayL, 2, mixerDelayLA, 2);
AudioConnection          patchCord401(delayL, 3, mixerDelayLA, 3);
AudioConnection          patchCord402(delayFeedbackR, 0, mixerPreDelayR, 1);
AudioConnection          patchCord403(delayFeedbackL, 0, mixerPreDelayL, 1);
AudioConnection          patchCord404(dcPanPhase, 0, panLFOR, 0);
AudioConnection          patchCord405(mixerDelayRA, 0, mixerDelayRB, 1);
AudioConnection          patchCord406(mixerDelayRA, delayFeedbackR);
AudioConnection          patchCord407(mixerDelayLA, 0, mixerDelayLB, 1);
AudioConnection          patchCord408(mixerDelayLA, delayFeedbackL);
AudioConnection          patchCord409(dcPanOffL, 0, mixerPanL, 0);
AudioConnection          patchCord410(dcPanOffR, 0, mixerPanR, 0);
AudioConnection          patchCord411(panLFOL, 0, mixerPanL, 1);
AudioConnection          patchCord412(panLFOR, 0, mixerPanR, 1);
AudioConnection          patchCord413(panLFOR, leslieDetuneMaster);
AudioConnection          patchCord414(mixerDelayRB, 0, panR, 0);
AudioConnection          patchCord415(mixerDelayLB, 0, panL, 0);
AudioConnection          patchCord416(mixerPanR, 0, panR, 1);
AudioConnection          patchCord417(mixerPanL, 0, panL, 1);
AudioConnection          patchCord418(panR, 0, mixerReverbR, 0);
AudioConnection          patchCord419(panR, freeverbR);
AudioConnection          patchCord420(panL, 0, mixerReverbL, 0);
AudioConnection          patchCord421(panL, freeverbL);
AudioConnection          patchCord422(freeverbR, 0, mixerReverbR, 1);
AudioConnection          patchCord423(freeverbL, 0, mixerReverbL, 1);
AudioConnection          patchCord424(mixerReverbL, 0, masterVolL, 0);
AudioConnection          patchCord425(mixerReverbR, 0, masterVolR, 0);
AudioConnection          patchCord426(masterVolR, 0, i2s1, 1);
AudioConnection          patchCord427(masterVolL, 0, i2s1, 0);
AudioControlSGTL5000     sgtl5000_1;     //xy=2024.613639831543,267.25
// GUItool: end automatically generated code
