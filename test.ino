#include <Wire.h> 
#include <BD37534FV.h>
BD37534FV tda; 

void setup(){
   Wire.begin();
   audio();
}

void loop(){}

void audio(){
   tda.setSetup_1(1,2,0); // default (1,2,0)
   tda.setSetup_2(0,0,0,0); 
                   // int sub_f ------ OFF 55Hz 85Hz 120Hz 160Hz = int 0...4
                   // int sub_out ---- LPF Front Rear Prohibition = int 0...3
                   // int level_metr - HOLD REST = int 0..1
                   // int faza ------- 0 180 = int 0...1
   tda.setLoudness_f(0); // 250Hz 400Hz 800Hz Prohibition = int 0...3
   tda.setIn(0); // 0...2
   tda.setIn_gain(0,0); // in_gain -- 0...20 = 0...20 dB, mute -- 0 default 
   tda.setVol(0); // -79...+15 dB = int -79...15
   tda.setFront_1(0); // -79...+15 dB = int -79...15
   tda.setFront_2(0); // -79...+15 dB = int -79...15
   tda.setRear_1(0); // -79...+15 dB = int -79...15
   tda.setRear_2(0); // -79...+15 dB = int -79...15
   tda.setSub(0); // -79...+15 dB = int -79...15
   tda.mix();
   tda.setBass_setup(0,0); // 0.5 1.0 1.5 2.0 --- int 0...3, 60Hz 80Hz 100Hz 120Hz --- int 0...3
   tda.setMiddle_setup(0,0); // 0.75 1.0 1.25 1.5 --- int 0...3, 500Hz 1kHz 1.5kHz 2.5kHz --- int 0...3
   tda.setTreble_setup(0,0); // 0.75 1.25  --- int 0...1, 7.5kHz 10kHz 12.5kHz 15kHz --- int 0...3
   tda.setBass_gain(0); // --20 ... +20 dB = int -20 ... 20  
   tda.setMiddle_gain(0); // --20 ... +20 dB = int -20 ... 20
   tda.setTreble_gain(0); // --20 ... +20 dB = int -20 ... 20   
   tda.setLoudness_gain(0); // 0 ... 20 dB = int 0 ... 20
  }
