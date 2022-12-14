#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioAmplifier           leslieDetuneMaster; //xy=200.02842712402344,940.0227320194244
AudioSynthWaveformModulated lfo;            //xy=203.02842712402344,1578.0227320194244
AudioAnalyzePeak         lfoPeak;          //xy=250.0071144104004,1367.8479862213135
AudioAmplifier           lfoMaster7;     //xy=458.02842712402344,3103.0227320194244
AudioAnalyzeRMS          secondardyLfoPos; //xy=457.5071105957031,3279.77978515625
AudioSynthWaveformModulated secondaryLfo;   //xy=462.02842712402344,3183.0227320194244
AudioAmplifier           lfoMaster0;     //xy=605.0284271240234,79.02273201942444
AudioAmplifier           lfoMaster1;     //xy=616.0284271240234,530.0227320194244
AudioAmplifier           lfoMaster2;     //xy=636.0284271240234,974.0227320194244
AudioAmplifier           lfoMaster3;     //xy=636.0284271240234,1413.0227320194244
AudioAmplifier           lfoMaster4;     //xy=656.0284271240234,1851.0227320194244
AudioAmplifier           lfoMaster5;     //xy=661.0284271240234,2291.0227320194244
AudioAmplifier           lfoMaster6;     //xy=675.0284271240234,2729.0227320194244
AudioMixer4              mixerLfoMaster7; //xy=680.0284271240234,3193.0227320194244
AudioAmplifier           bypassLeslie7;  //xy=687.0284271240234,3299.0227320194244
AudioSynthWaveformDc     dcPitchOctaveA0; //xy=825.0284271240234,133.02273201942444
AudioSynthWaveformDc     dcPitchOctaveB0; //xy=826.0284271240234,163.02273201942444
AudioSynthWaveformDc     dcPitchDetuneA0; //xy=828.0284271240234,223.02273201942444
AudioSynthWaveformDc     dcPitchDetuneB0; //xy=829.0284271240234,256.02273201942444
AudioSynthWaveformDc     dcPitchBend0;   //xy=835.0284271240234,104.02273201942444
AudioAmplifier           leslieDetune0;  //xy=835.0284271240234,289.02273201942444
AudioSynthWaveformDc     dcPitchOctaveA1; //xy=835.0284271240234,583.0227320194244
AudioSynthWaveformDc     dcPitchOctaveB1; //xy=836.0284271240234,613.0227320194244
AudioSynthWaveformDc     dcPitchDetuneA1; //xy=838.0284271240234,673.0227320194244
AudioSynthWaveformDc     dcPitchDetuneB1; //xy=839.0284271240234,706.0227320194244
AudioSynthWaveformDc     dcPitchBend1;   //xy=845.0284271240234,554.0227320194244
AudioAmplifier           leslieDetune1;  //xy=845.0284271240234,739.0227320194244
AudioAmplifier           lfoFreq0;       //xy=853.0284271240234,194.02273201942444
AudioSynthWaveformDc     dcPorta0;       //xy=853.0284271240234,322.02273201942444
AudioSynthWaveformDc     dcPitchOctaveA2; //xy=855.0284271240234,1028.0227320194244
AudioSynthWaveformDc     dcPitchOctaveB2; //xy=856.0284271240234,1058.0227320194244
AudioSynthWaveformDc     dcPitchOctaveA3; //xy=855.0284271240234,1466.0227320194244
AudioSynthWaveformDc     dcPitchOctaveB3; //xy=856.0284271240234,1496.0227320194244
AudioSynthWaveformDc     dcPitchDetuneA2; //xy=858.0284271240234,1118.0227320194244
AudioSynthWaveformDc     dcPitchDetuneB2; //xy=859.0284271240234,1151.0227320194244
AudioSynthWaveformDc     dcPitchDetuneA3; //xy=858.0284271240234,1556.0227320194244
AudioSynthWaveformDc     dcOscPWA0;      //xy=863.0284271240234,437.02273201942444
AudioSynthWaveformDc     dcPitchDetuneB3; //xy=859.0284271240234,1589.0227320194244
AudioAmplifier           lfoFreq1;       //xy=863.0284271240234,644.0227320194244
AudioSynthWaveformDc     dcOscPWB0;      //xy=864.0284271240234,469.02273201942444
AudioSynthWaveformDc     dcPitchBend2;   //xy=865.0284271240234,999.0227320194244
AudioAmplifier           leslieDetune2;  //xy=865.0284271240234,1184.0227320194244
AudioSynthWaveformDc     dcPitchBend3;   //xy=865.0284271240234,1437.0227320194244
AudioAmplifier           leslieDetune3;  //xy=865.0284271240234,1622.0227320194244
AudioAmplifier           lfoPW0;         //xy=873.0284271240234,406.02273201942444
AudioSynthWaveformDc     dcOscPWA1;      //xy=873.0284271240234,888.0227320194244
AudioSynthWaveformDc     dcOscPWB1;      //xy=874.0284271240234,920.0227320194244
AudioSynthWaveformDc     dcPitchOctaveA4; //xy=875.0284271240234,1905.0227320194244
AudioSynthWaveformDc     dcPitchOctaveB4; //xy=876.0284271240234,1935.0227320194244
AudioSynthWaveformDc     dcPitchDetuneA4; //xy=878.0284271240234,1995.0227320194244
AudioAmplifier           lfoPW1;         //xy=883.0284271240234,857.0227320194244
AudioSynthWaveformDc     dcPitchDetuneB4; //xy=879.0284271240234,2028.0227320194244
AudioAmplifier           lfoFreq2;       //xy=883.0284271240234,1089.0227320194244
AudioAmplifier           lfoFreq3;       //xy=883.0284271240234,1527.0227320194244
AudioSynthWaveformDc     dcPitchOctaveA5; //xy=880.0284271240234,2345.0227320194244
AudioSynthWaveformDc     dcPitchOctaveB5; //xy=881.0284271240234,2375.0227320194244
AudioSynthWaveformDc     dcPitchBend4;   //xy=885.0284271240234,1876.0227320194244
AudioSynthWaveformDc     dcPitchDetuneA5; //xy=883.0284271240234,2435.0227320194244
AudioAmplifier           leslieDetune4;  //xy=885.0284271240234,2061.0227320194244
AudioSynthWaveformDc     dcPitchDetuneB5; //xy=884.0284271240234,2468.0227320194244
AudioSynthWaveformDc     dcOscPWA2;      //xy=893.0284271240234,1333.0227320194244
AudioSynthWaveformDc     dcPitchBend5;   //xy=890.0284271240234,2316.0227320194244
AudioSynthWaveformDc     dcOscPWB2;      //xy=894.0284271240234,1365.0227320194244
AudioAmplifier           leslieDetune5;  //xy=890.0284271240234,2501.0227320194244
AudioSynthWaveformDc     dcOscPWA3;      //xy=893.0284271240234,1771.0227320194244
AudioSynthWaveformDc     dcOscPWB3;      //xy=894.0284271240234,1803.0227320194244
AudioSynthWaveformDc     dcPitchOctaveA6; //xy=894.0284271240234,2783.0227320194244
AudioSynthWaveformDc     dcPitchOctaveB6; //xy=895.0284271240234,2813.0227320194244
AudioAmplifier           lfoPW2;         //xy=903.0284271240234,1302.0227320194244
AudioSynthWaveformDc     dcPitchDetuneA6; //xy=897.0284271240234,2873.0227320194244
AudioSynthWaveformDc     dcPitchDetuneB6; //xy=898.0284271240234,2906.0227320194244
AudioAmplifier           lfoPW3;         //xy=903.0284271240234,1740.0227320194244
AudioAmplifier           lfoFreq4;       //xy=903.0284271240234,1966.0227320194244
AudioSynthWaveformDc     dcPitchOctaveA7; //xy=902.0284271240234,3239.0227320194244
AudioSynthWaveformDc     dcPitchBend6;   //xy=904.0284271240234,2754.0227320194244
AudioAmplifier           leslieDetune6;  //xy=904.0284271240234,2939.0227320194244
AudioSynthWaveformDc     dcPitchOctaveB7; //xy=903.0284271240234,3269.0227320194244
AudioAmplifier           lfoFreq5;       //xy=908.0284271240234,2406.0227320194244
AudioSynthWaveformDc     dcPitchDetuneA7; //xy=905.0284271240234,3329.0227320194244
AudioSynthWaveformDc     dcPitchDetuneB7; //xy=906.0284271240234,3362.0227320194244
AudioSynthWaveformDc     dcOscPWA4;      //xy=913.0284271240234,2210.0227320194244
AudioSynthWaveformDc     dcOscPWB4;      //xy=914.0284271240234,2242.0227320194244
AudioSynthWaveformDc     dcPitchBend7;   //xy=912.0284271240234,3210.0227320194244
AudioAmplifier           leslieDetune7;  //xy=912.0284271240234,3395.0227320194244
AudioSynthWaveformDc     dcOscPWA5;      //xy=918.0284271240234,2650.0227320194244
AudioSynthWaveformDc     dcOscPWB5;      //xy=919.0284271240234,2682.0227320194244
AudioAmplifier           lfoPW4;         //xy=923.0284271240234,2179.0227320194244
AudioAmplifier           lfoFreq6;       //xy=922.0284271240234,2844.0227320194244
AudioAmplifier           lfoPW5;         //xy=928.0284271240234,2619.0227320194244
AudioAmplifier           lfoFreq7;       //xy=930.0284271240234,3300.0227320194244
AudioSynthWaveformDc     dcPorta7;       //xy=930.0284271240234,3428.0227320194244
AudioSynthWaveformDc     dcOscPWA6;      //xy=932.0284271240234,3088.0227320194244
AudioSynthWaveformDc     dcOscPWB6;      //xy=933.0284271240234,3120.0227320194244
AudioSynthWaveformDc     dcOscPWA7;      //xy=940.0284271240234,3544.0227320194244
AudioAmplifier           lfoPW6;         //xy=942.0284271240234,3057.0227320194244
AudioSynthWaveformDc     dcOscPWB7;      //xy=941.0284271240234,3576.0227320194244
AudioAmplifier           lfoPW7;         //xy=950.0284271240234,3513.0227320194244
AudioMixer4              mixerOscAFreqModB0; //xy=1078.0284271240234,188.02273201942444
AudioMixer4              mixerOscAFreqModA0; //xy=1080.0284271240234,125.02273201942444
AudioMixer4              mixerOscBFreqModA0; //xy=1081.0284271240234,261.02273201942444
AudioMixer4              mixerOscBFreqModB0; //xy=1083.0284271240234,326.02273201942444
AudioMixer4              mixerOscAFreqModB1; //xy=1088.0284271240234,638.0227320194244
AudioMixer4              mixerOscPWModB0; //xy=1090.0284271240234,456.02273201942444
AudioMixer4              mixerOscAFreqModA1; //xy=1090.0284271240234,575.0227320194244
AudioMixer4              mixerOscPWModA0; //xy=1092.0284271240234,395.02273201942444
AudioMixer4              mixerOscBFreqModA1; //xy=1091.0284271240234,711.0227320194244
AudioMixer4              mixerOscBFreqModB1; //xy=1093.0284271240234,776.0227320194244
AudioMixer4              mixerOscPWModB1; //xy=1100.0284271240234,907.0227320194244
AudioMixer4              mixerOscPWModA1; //xy=1102.0284271240234,846.0227320194244
AudioMixer4              mixerOscAFreqModB2; //xy=1108.0284271240234,1083.0227320194244
AudioMixer4              mixerOscAFreqModA2; //xy=1110.0284271240234,1020.0227320194244
AudioMixer4              mixerOscAFreqModB3; //xy=1108.0284271240234,1521.0227320194244
AudioMixer4              mixerOscBFreqModA2; //xy=1111.0284271240234,1156.0227320194244
AudioMixer4              mixerOscAFreqModA3; //xy=1110.0284271240234,1458.0227320194244
AudioMixer4              mixerOscBFreqModA3; //xy=1111.0284271240234,1594.0227320194244
AudioMixer4              mixerOscBFreqModB2; //xy=1113.0284271240234,1221.0227320194244
AudioMixer4              mixerOscBFreqModB3; //xy=1113.0284271240234,1659.0227320194244
AudioMixer4              mixerOscPWModB2; //xy=1120.0284271240234,1352.0227320194244
AudioMixer4              mixerOscPWModB3; //xy=1120.0284271240234,1790.0227320194244
AudioMixer4              mixerOscPWModA2; //xy=1122.0284271240234,1291.0227320194244
AudioMixer4              mixerOscPWModA3; //xy=1122.0284271240234,1729.0227320194244
AudioMixer4              mixerOscAFreqModB4; //xy=1128.0284271240234,1960.0227320194244
AudioMixer4              mixerOscAFreqModA4; //xy=1130.0284271240234,1897.0227320194244
AudioMixer4              mixerOscBFreqModA4; //xy=1131.0284271240234,2033.0227320194244
AudioMixer4              mixerOscBFreqModB4; //xy=1133.0284271240234,2098.0227320194244
AudioMixer4              mixerOscAFreqModB5; //xy=1133.0284271240234,2400.0227320194244
AudioMixer4              mixerOscAFreqModA5; //xy=1135.0284271240234,2337.0227320194244
AudioMixer4              mixerOscBFreqModA5; //xy=1136.0284271240234,2473.0227320194244
AudioMixer4              mixerOscBFreqModB5; //xy=1138.0284271240234,2538.0227320194244
AudioMixer4              mixerOscPWModB4; //xy=1140.0284271240234,2229.0227320194244
AudioMixer4              mixerOscPWModA4; //xy=1142.0284271240234,2168.0227320194244
AudioMixer4              mixerOscPWModB5; //xy=1145.0284271240234,2669.0227320194244
AudioMixer4              mixerOscPWModA5; //xy=1147.0284271240234,2608.0227320194244
AudioMixer4              mixerOscAFreqModB6; //xy=1147.0284271240234,2838.0227320194244
AudioMixer4              mixerOscAFreqModA6; //xy=1149.0284271240234,2775.0227320194244
AudioMixer4              mixerOscBFreqModA6; //xy=1150.0284271240234,2911.0227320194244
AudioMixer4              mixerOscBFreqModB6; //xy=1152.0284271240234,2976.0227320194244
AudioMixer4              mixerOscAFreqModB7; //xy=1155.0284271240234,3294.0227320194244
AudioMixer4              mixerOscAFreqModA7; //xy=1157.0284271240234,3231.0227320194244
AudioMixer4              mixerOscPWModB6; //xy=1159.0284271240234,3107.0227320194244
AudioMixer4              mixerOscBFreqModA7; //xy=1158.0284271240234,3367.0227320194244
AudioMixer4              mixerOscPWModA6; //xy=1161.0284271240234,3046.0227320194244
AudioMixer4              mixerOscBFreqModB7; //xy=1160.0284271240234,3432.0227320194244
AudioMixer4              mixerOscPWModB7; //xy=1167.0284271240234,3563.0227320194244
AudioMixer4              mixerOscPWModA7; //xy=1169.0284271240234,3502.0227320194244
AudioSynthWaveformDc     dcFilterAft0;   //xy=1280.0284271240234,122.02273201942444
AudioSynthWaveformDc     dcFilterEnv0;   //xy=1286.0284271240234,158.02273201942444
AudioSynthWaveformDc     dcFilterKbd0;   //xy=1286.0284271240234,191.02273201942444
AudioSynthWaveformDc     dcFilterVel0;   //xy=1290.0284271240234,227.02273201942444
AudioSynthWaveformDc     dcFilterAft1;   //xy=1290.0284271240234,573.0227320194244
AudioSynthWaveformModulated oscA0;          //xy=1293.0284271240234,313.02273201942444
AudioAmplifier           lfoFilterFreq0; //xy=1294.0284271240234,87.02273201942444
AudioSynthWaveformModulated oscB0;          //xy=1294.0284271240234,354.02273201942444
AudioSynthWaveformDc     dcFilterEnv1;   //xy=1296.0284271240234,609.0227320194244
AudioSynthWaveformDc     dcFilterKbd1;   //xy=1296.0284271240234,642.0227320194244
AudioSynthNoisePink      pink0;          //xy=1298.0284271240234,391.02273201942444
AudioSynthWaveformDc     dcFilterVel1;   //xy=1300.0284271240234,678.0227320194244
AudioSynthWaveformModulated oscA1;          //xy=1303.0284271240234,763.0227320194244
AudioAmplifier           lfoFilterFreq1; //xy=1304.0284271240234,538.0227320194244
AudioSynthWaveformModulated oscB1;          //xy=1304.0284271240234,804.0227320194244
AudioSynthNoisePink      pink1;          //xy=1308.0284271240234,841.0227320194244
AudioSynthWaveformDc     dcFilterAft2;   //xy=1310.0284271240234,1018.0227320194244
AudioSynthWaveformDc     dcFilterAft3;   //xy=1310.0284271240234,1456.0227320194244
AudioSynthWaveformDc     dcFilterEnv2;   //xy=1316.0284271240234,1054.0227320194244
AudioSynthWaveformDc     dcFilterKbd2;   //xy=1316.0284271240234,1087.0227320194244
AudioSynthWaveformDc     dcFilterEnv3;   //xy=1316.0284271240234,1492.0227320194244
AudioSynthWaveformDc     dcFilterKbd3;   //xy=1316.0284271240234,1525.0227320194244
AudioSynthWaveformDc     dcFilterVel2;   //xy=1320.0284271240234,1123.0227320194244
AudioSynthWaveformDc     dcFilterVel3;   //xy=1320.0284271240234,1561.0227320194244
AudioSynthWaveformModulated oscA2;          //xy=1323.0284271240234,1208.0227320194244
AudioAmplifier           lfoFilterFreq2; //xy=1324.0284271240234,983.0227320194244
AudioSynthWaveformModulated oscB2;          //xy=1324.0284271240234,1249.0227320194244
AudioSynthWaveformModulated oscA3;          //xy=1323.0284271240234,1646.0227320194244
AudioAmplifier           lfoFilterFreq3; //xy=1324.0284271240234,1421.0227320194244
AudioSynthWaveformModulated oscB3;          //xy=1324.0284271240234,1687.0227320194244
AudioSynthNoisePink      pink2;          //xy=1328.0284271240234,1286.0227320194244
AudioSynthNoisePink      pink3;          //xy=1328.0284271240234,1724.0227320194244
AudioSynthWaveformDc     dcFilterAft4;   //xy=1330.0284271240234,1895.0227320194244
AudioSynthWaveformDc     dcFilterEnv4;   //xy=1336.0284271240234,1931.0227320194244
AudioSynthWaveformDc     dcFilterKbd4;   //xy=1336.0284271240234,1964.0227320194244
AudioSynthWaveformDc     dcFilterAft5;   //xy=1335.0284271240234,2335.0227320194244
AudioSynthWaveformDc     dcFilterVel4;   //xy=1340.0284271240234,2000.0227320194244
AudioSynthWaveformDc     dcFilterEnv5;   //xy=1341.0284271240234,2371.0227320194244
AudioSynthWaveformDc     dcFilterKbd5;   //xy=1341.0284271240234,2404.0227320194244
AudioSynthWaveformModulated oscA4;          //xy=1343.0284271240234,2085.0227320194244
AudioAmplifier           lfoFilterFreq4; //xy=1344.0284271240234,1860.0227320194244
AudioSynthWaveformModulated oscB4;          //xy=1344.0284271240234,2126.0227320194244
AudioSynthWaveformDc     dcFilterVel5;   //xy=1345.0284271240234,2440.0227320194244
AudioSynthNoisePink      pink4;          //xy=1348.0284271240234,2163.0227320194244
AudioSynthWaveformModulated oscA5;          //xy=1348.0284271240234,2525.0227320194244
AudioAmplifier           lfoFilterFreq5; //xy=1349.0284271240234,2300.0227320194244
AudioSynthWaveformModulated oscB5;          //xy=1349.0284271240234,2566.0227320194244
AudioSynthWaveformDc     dcFilterAft6;   //xy=1349.0284271240234,2773.0227320194244
AudioSynthNoisePink      pink5;          //xy=1353.0284271240234,2603.0227320194244
AudioSynthWaveformDc     dcFilterEnv6;   //xy=1355.0284271240234,2809.0227320194244
AudioSynthWaveformDc     dcFilterKbd6;   //xy=1355.0284271240234,2842.0227320194244
AudioSynthWaveformDc     dcFilterAft7;   //xy=1357.0284271240234,3229.0227320194244
AudioSynthWaveformDc     dcFilterVel6;   //xy=1359.0284271240234,2878.0227320194244
AudioSynthWaveformModulated oscA6;          //xy=1362.0284271240234,2963.0227320194244
AudioAmplifier           lfoFilterFreq6; //xy=1363.0284271240234,2738.0227320194244
AudioSynthWaveformModulated oscB6;          //xy=1363.0284271240234,3004.0227320194244
AudioSynthWaveformDc     dcFilterEnv7;   //xy=1363.0284271240234,3265.0227320194244
AudioSynthWaveformDc     dcFilterKbd7;   //xy=1363.0284271240234,3298.0227320194244
AudioSynthNoisePink      pink6;          //xy=1367.0284271240234,3041.0227320194244
AudioSynthWaveformDc     dcFilterVel7;   //xy=1367.0284271240234,3334.0227320194244
AudioSynthWaveformModulated oscA7;          //xy=1370.0284271240234,3419.0227320194244
AudioAmplifier           lfoFilterFreq7; //xy=1371.0284271240234,3194.0227320194244
AudioSynthWaveformModulated oscB7;          //xy=1371.0284271240234,3460.0227320194244
AudioSynthNoisePink      pink7;          //xy=1375.0284271240234,3497.0227320194244
AudioEffectEnvelope      envelopeFilter0; //xy=1449.0284271240234,155.02273201942444
AudioEffectEnvelope      envelopeFilter1; //xy=1459.0284271240234,606.0227320194244
AudioMixer4              mixerOsc0;      //xy=1463.0284271240234,363.02273201942444
AudioMixer4              mixerOsc1;      //xy=1473.0284271240234,813.0227320194244
AudioEffectEnvelope      envelopeFilter2; //xy=1479.0284271240234,1051.0227320194244
AudioEffectEnvelope      envelopeFilter3; //xy=1479.0284271240234,1489.0227320194244
AudioMixer4              mixerOsc2;      //xy=1493.0284271240234,1258.0227320194244
AudioMixer4              mixerOsc3;      //xy=1493.0284271240234,1696.0227320194244
AudioEffectEnvelope      envelopeFilter4; //xy=1499.0284271240234,1928.0227320194244
AudioEffectEnvelope      envelopeFilter5; //xy=1504.0284271240234,2368.0227320194244
AudioMixer4              mixerOsc4;      //xy=1513.0284271240234,2135.0227320194244
AudioMixer4              mixerOsc5;      //xy=1518.0284271240234,2575.0227320194244
AudioEffectEnvelope      envelopeFilter6; //xy=1518.0284271240234,2806.0227320194244
AudioEffectEnvelope      envelopeFilter7; //xy=1526.0284271240234,3262.0227320194244
AudioMixer4              mixerOsc6;      //xy=1532.0284271240234,3013.0227320194244
AudioMixer4              mixerOsc7;      //xy=1540.0284271240234,3469.0227320194244
AudioMixer4              mixerFilterFreqA0; //xy=1638.0284271240234,110.02273201942444
AudioMixer4              mixerFilterFreqB0; //xy=1638.0284271240234,171.02273201942444
AudioMixer4              mixerFilterRes0; //xy=1645.0284271240234,231.02273201942444
AudioMixer4              mixerFilterFreqA1; //xy=1648.0284271240234,561.0227320194244
AudioMixer4              mixerFilterFreqB1; //xy=1648.0284271240234,622.0227320194244
AudioMixer4              mixerFilterRes1; //xy=1655.0284271240234,682.0227320194244
AudioMixer4              mixerFilterFreqA2; //xy=1668.0284271240234,1006.0227320194244
AudioMixer4              mixerFilterFreqB2; //xy=1668.0284271240234,1067.0227320194244
AudioMixer4              mixerFilterFreqA3; //xy=1668.0284271240234,1444.0227320194244
AudioMixer4              mixerFilterFreqB3; //xy=1668.0284271240234,1505.0227320194244
AudioFilterLadder        ladder0;        //xy=1673.0284271240234,376.02273201942444
AudioMixer4              mixerFilterRes2; //xy=1675.0284271240234,1127.0227320194244
AudioMixer4              mixerFilterRes3; //xy=1675.0284271240234,1565.0227320194244
AudioFilterLadder        ladder1;        //xy=1683.0284271240234,827.0227320194244
AudioMixer4              mixerFilterFreqA4; //xy=1688.0284271240234,1883.0227320194244
AudioMixer4              mixerFilterFreqB4; //xy=1688.0284271240234,1944.0227320194244
AudioMixer4              mixerFilterFreqA5; //xy=1693.0284271240234,2323.0227320194244
AudioMixer4              mixerFilterFreqB5; //xy=1693.0284271240234,2384.0227320194244
AudioMixer4              mixerFilterRes4; //xy=1695.0284271240234,2004.0227320194244
AudioFilterLadder        ladder2;        //xy=1703.0284271240234,1272.0227320194244
AudioMixer4              mixerFilterRes5; //xy=1700.0284271240234,2444.0227320194244
AudioFilterLadder        ladder3;        //xy=1703.0284271240234,1710.0227320194244
AudioMixer4              mixerFilterFreqA6; //xy=1707.0284271240234,2761.0227320194244
AudioMixer4              mixerFilterFreqB6; //xy=1707.0284271240234,2822.0227320194244
AudioMixer4              mixerFilterRes6; //xy=1714.0284271240234,2882.0227320194244
AudioMixer4              mixerFilterFreqA7; //xy=1715.0284271240234,3217.0227320194244
AudioMixer4              mixerFilterFreqB7; //xy=1715.0284271240234,3278.0227320194244
AudioFilterLadder        ladder4;        //xy=1723.0284271240234,2149.0227320194244
AudioMixer4              mixerFilterRes7; //xy=1722.0284271240234,3338.0227320194244
AudioFilterLadder        ladder5;        //xy=1728.0284271240234,2589.0227320194244
AudioFilterLadder        ladder6;        //xy=1742.0284271240234,3027.0227320194244
AudioFilterLadder        ladder7;        //xy=1750.0284271240234,3483.0227320194244
AudioEffectEnvelope      envelopeVol0;   //xy=1829.0284271240234,376.02273201942444
AudioEffectEnvelope      envelopeVol1;   //xy=1843.0284271240234,822.0227320194244
AudioEffectEnvelope      envelopeVol2;   //xy=1877.0284271240234,1272.0227320194244
AudioEffectEnvelope      envelopeVol3;   //xy=1889.0284271240234,1710.0227320194244
AudioEffectEnvelope      envelopeVol5;   //xy=1886.0284271240234,2591.0227320194244
AudioEffectEnvelope      envelopeVol6;   //xy=1893.0284271240234,3027.0227320194244
AudioEffectEnvelope      envelopeVol4;   //xy=1905.0284271240234,2152.0227320194244
AudioEffectEnvelope      envelopeVol7;   //xy=1906.0284271240234,3480.0227320194244
AudioMixer4              mixerOscLeft1;  //xy=2106.0284271240234,401.02273201942444
AudioMixer4              mixerOscRight1; //xy=2107.0284271240234,459.02273201942444
AudioAmplifier           secondaryVol;   //xy=2096.0284271240234,3469.0227320194244
AudioAmplifier           bypassFx7;      //xy=2099.0284271240234,3375.0227320194244
AudioMixer4              mixerOscLeft2;  //xy=2122.0284271240234,2171.0227320194244
AudioMixer4              mixerOscRight2; //xy=2126.0284271240234,2235.0227320194244
AudioMixer4              mixerOscRightMaster; //xy=2338.0284271240234,479.02273201942444
AudioMixer4              mixerOscLeftMaster; //xy=2339.0284271240234,415.02273201942444
AudioEffectWaveshaper    waveshapeR;     //xy=2580.0284271240234,516.0227320194244
AudioEffectWaveshaper    waveshapeL;     //xy=2590.0284271240234,353.02273201942444
AudioMixer4              mixerWaveshapeR; //xy=2601.0284271240234,466.02273201942444
AudioMixer4              mixerWaveshapeL; //xy=2603.0284271240234,404.02273201942444
AudioAmplifier           wahAttenuatorR; //xy=2742.0284271240234,570.0227320194244
AudioAmplifier           wahAttenuatorL; //xy=2755.0284271240234,270.02273201942444
AudioFilterStateVariable filterL;        //xy=2903.0284271240234,279.02273201942444
AudioFilterStateVariable filterR;        //xy=2905.0284271240234,573.0227320194244
AudioMixer4              mixerWahR;      //xy=2936.0284271240234,482.02273201942444
AudioMixer4              mixerWahL;      //xy=2944.0284271240234,394.02273201942444
AudioMixer4              mixerPhaserR;   //xy=3104.0284271240234,467.02273201942444
AudioMixer4              mixerPhaserL;   //xy=3105.0284271240234,405.02273201942444
AudioMixer4              mixerChorusR;   //xy=3293.0284271240234,470.02273201942444
AudioMixer4              mixerChorusL;   //xy=3294.0284271240234,407.02273201942444
AudioSynthWaveformModulated tremoloLFO;     //xy=3437.0284271240234,617.0227320194244
AudioSynthWaveformDc     dcTremoloOff;   //xy=3437.0284271240234,648.0227320194244
AudioMixer4              mixerTremoloLFO; //xy=3443.0284271240234,553.0227320194244
AudioEffectMultiply      tremoloL;       //xy=3488.0284271240234,411.02273201942444
AudioEffectMultiply      tremoloR;       //xy=3491.0284271240234,473.02273201942444
AudioMixer4              mixerPreDelayR; //xy=3668.0284271240234,528.0227320194244
AudioMixer4              mixerPreDelayL; //xy=3670.0284271240234,367.02273201942444
AudioEffectDelay         delayR;         //xy=3808.0284271240234,611.0227320194244
AudioEffectDelay         delayL;         //xy=3818.0284271240234,268.02273201942444
AudioAmplifier           delayFeedbackR; //xy=3893.0284271240234,505.02273201942444
AudioAmplifier           delayFeedbackL; //xy=3900.0284271240234,385.02273201942444
AudioSynthWaveformDc     dcPanPhase;     //xy=3899.0284271240234,762.0227320194244
AudioMixer4              mixerDelayRA;   //xy=3950.0284271240234,583.0227320194244
AudioMixer4              mixerDelayLA;   //xy=3958.0284271240234,242.02273201942444
AudioSynthWaveformDc     dcPanOffL;      //xy=4065.0284271240234,662.0227320194244
AudioSynthWaveformDc     dcPanOffR;      //xy=4067.0284271240234,738.0227320194244
AudioSynthWaveformModulated panLFOL;        //xy=4068.0284271240234,693.0227320194244
AudioSynthWaveformModulated panLFOR;        //xy=4069.0284271240234,771.0227320194244
AudioMixer4              mixerDelayRB;   //xy=4115.028427124023,489.02273201942444
AudioMixer4              mixerDelayLB;   //xy=4118.028427124023,429.02273201942444
AudioMixer4              mixerPanR;      //xy=4238.028427124023,754.0227320194244
AudioMixer4              mixerPanL;      //xy=4239.028427124023,695.0227320194244
AudioEffectMultiply      panR;           //xy=4284.028427124023,496.02273201942444
AudioEffectMultiply      panL;           //xy=4285.028427124023,434.02273201942444
AudioEffectFreeverb      freeverbR;      //xy=4421.028427124023,560.0227320194244
AudioEffectFreeverb      freeverbL;      //xy=4427.028427124023,395.02273201942444
AudioMixer4              mixerReverbL;   //xy=4554.028427124023,446.02273201942444
AudioMixer4              mixerReverbR;   //xy=4554.028427124023,511.02273201942444
AudioMixer4              masterVolR;     //xy=4767.028427124023,525.0227320194244
AudioMixer4              masterVolL;     //xy=4768.028427124023,462.02273201942444
AudioOutputI2S           i2s1;           //xy=4935.028427124023,476.02273201942444
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
AudioConnection          patchCord360(mixerOscLeft2, 0, mixerOscLeftMaster, 1);
AudioConnection          patchCord361(mixerOscRight2, 0, mixerOscRightMaster, 1);
AudioConnection          patchCord362(mixerOscRightMaster, 0, mixerWaveshapeR, 0);
AudioConnection          patchCord363(mixerOscRightMaster, waveshapeR);
AudioConnection          patchCord364(mixerOscLeftMaster, 0, mixerWaveshapeL, 0);
AudioConnection          patchCord365(mixerOscLeftMaster, waveshapeL);
AudioConnection          patchCord366(waveshapeR, 0, mixerWaveshapeR, 1);
AudioConnection          patchCord367(waveshapeL, 0, mixerWaveshapeL, 1);
AudioConnection          patchCord368(mixerWaveshapeR, 0, mixerWahR, 0);
AudioConnection          patchCord369(mixerWaveshapeR, wahAttenuatorR);
AudioConnection          patchCord370(mixerWaveshapeL, 0, mixerWahL, 0);
AudioConnection          patchCord371(mixerWaveshapeL, wahAttenuatorL);
AudioConnection          patchCord372(wahAttenuatorR, 0, filterR, 0);
AudioConnection          patchCord373(wahAttenuatorL, 0, filterL, 0);
AudioConnection          patchCord374(filterL, 1, mixerWahL, 1);
AudioConnection          patchCord375(filterR, 1, mixerWahR, 1);
AudioConnection          patchCord376(mixerWahR, 0, mixerPhaserR, 0);
AudioConnection          patchCord377(mixerWahL, 0, mixerPhaserL, 0);
AudioConnection          patchCord378(mixerPhaserR, 0, mixerChorusR, 0);
AudioConnection          patchCord379(mixerPhaserL, 0, mixerChorusL, 0);
AudioConnection          patchCord380(mixerChorusR, 0, tremoloR, 0);
AudioConnection          patchCord381(mixerChorusL, 0, tremoloL, 0);
AudioConnection          patchCord382(tremoloLFO, 0, mixerTremoloLFO, 0);
AudioConnection          patchCord383(dcTremoloOff, 0, mixerTremoloLFO, 1);
AudioConnection          patchCord384(mixerTremoloLFO, 0, tremoloR, 1);
AudioConnection          patchCord385(mixerTremoloLFO, 0, tremoloL, 1);
AudioConnection          patchCord386(tremoloL, 0, mixerDelayLB, 0);
AudioConnection          patchCord387(tremoloL, 0, mixerPreDelayL, 0);
AudioConnection          patchCord388(tremoloR, 0, mixerDelayRB, 0);
AudioConnection          patchCord389(tremoloR, 0, mixerPreDelayR, 0);
AudioConnection          patchCord390(mixerPreDelayR, delayR);
AudioConnection          patchCord391(mixerPreDelayL, delayL);
AudioConnection          patchCord392(delayR, 0, mixerDelayRA, 0);
AudioConnection          patchCord393(delayR, 1, mixerDelayRA, 1);
AudioConnection          patchCord394(delayR, 2, mixerDelayRA, 2);
AudioConnection          patchCord395(delayR, 3, mixerDelayRA, 3);
AudioConnection          patchCord396(delayL, 0, mixerDelayLA, 0);
AudioConnection          patchCord397(delayL, 1, mixerDelayLA, 1);
AudioConnection          patchCord398(delayL, 2, mixerDelayLA, 2);
AudioConnection          patchCord399(delayL, 3, mixerDelayLA, 3);
AudioConnection          patchCord400(delayFeedbackR, 0, mixerPreDelayR, 1);
AudioConnection          patchCord401(delayFeedbackL, 0, mixerPreDelayL, 1);
AudioConnection          patchCord402(dcPanPhase, 0, panLFOR, 0);
AudioConnection          patchCord403(mixerDelayRA, 0, mixerDelayRB, 1);
AudioConnection          patchCord404(mixerDelayRA, delayFeedbackR);
AudioConnection          patchCord405(mixerDelayLA, 0, mixerDelayLB, 1);
AudioConnection          patchCord406(mixerDelayLA, delayFeedbackL);
AudioConnection          patchCord407(dcPanOffL, 0, mixerPanL, 0);
AudioConnection          patchCord408(dcPanOffR, 0, mixerPanR, 0);
AudioConnection          patchCord409(panLFOL, 0, mixerPanL, 1);
AudioConnection          patchCord410(panLFOR, 0, mixerPanR, 1);
AudioConnection          patchCord411(panLFOR, leslieDetuneMaster);
AudioConnection          patchCord412(mixerDelayRB, 0, panR, 0);
AudioConnection          patchCord413(mixerDelayLB, 0, panL, 0);
AudioConnection          patchCord414(mixerPanR, 0, panR, 1);
AudioConnection          patchCord415(mixerPanL, 0, panL, 1);
AudioConnection          patchCord416(panR, 0, mixerReverbR, 0);
AudioConnection          patchCord417(panR, freeverbR);
AudioConnection          patchCord418(panL, 0, mixerReverbL, 0);
AudioConnection          patchCord419(panL, freeverbL);
AudioConnection          patchCord420(freeverbR, 0, mixerReverbR, 1);
AudioConnection          patchCord421(freeverbL, 0, mixerReverbL, 1);
AudioConnection          patchCord422(mixerReverbL, 0, masterVolL, 0);
AudioConnection          patchCord423(mixerReverbR, 0, masterVolR, 0);
AudioConnection          patchCord424(masterVolR, 0, i2s1, 1);
AudioConnection          patchCord425(masterVolL, 0, i2s1, 0);
AudioControlSGTL5000     sgtl5000_1;     //xy=2112.0284271240234,255.02273201942444
// GUItool: end automatically generated code
