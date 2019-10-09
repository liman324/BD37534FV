#include <Arduino.h>
#include <Wire.h>
#include "BD37534FV.h"

BD37534FV::BD37534FV(){
    Wire.begin();
}

void BD37534FV::setSetup_1(int sw_of, int sw_time, int time_mute){
           switch(sw_of){
               case 0: sw_of = 0b00000000;break;
               case 1: sw_of = 0b10000000;break;
   }
           switch(sw_time){
               case 0: sw_time = 0b00000000;break;
               case 1: sw_time = 0b00010000;break;
               case 2: sw_time = 0b00100000;break;
               case 3: sw_time = 0b00110000;break;        
   }
           switch(time_mute){
               case 0: time_mute = 0b00000000;break;
               case 1: time_mute = 0b00000001;break;
               case 2: time_mute = 0b00000010;break;
               case 3: time_mute = 0b00000011;break;        
   }
           int set1_sum = 0b00000100 + sw_of + sw_time + time_mute;
           writeWire(SETUP_1, set1_sum); 
   }

void BD37534FV::setSetup_2(int sub_f, int sub_out, int level_metr, int faza){
            switch(sub_f){
               case 0: sub_f = 0b00000000;break;
               case 1: sub_f = 0b00000001;break;
               case 2: sub_f = 0b00000010;break;
               case 3: sub_f = 0b00000011;break;  
               case 4: sub_f = 0b00000100;break; 
   }
            switch(sub_out){
               case 0: sub_out = 0b00000000;break;
               case 1: sub_out = 0b00010000;break;
               case 2: sub_out = 0b00100000;break;
               case 3: sub_out = 0b00110000;break;  
   }
            switch(level_metr){
               case 0: level_metr = 0b00000000;break;
               case 1: level_metr = 0b01000000;break;
   }
            switch(faza){
               case 0: faza = 0b00000000;break;
               case 1: faza = 0b10000000;break;
   }
            int set2_sum =  sub_f + sub_out + level_metr + faza;
            writeWire(SETUP_2, set2_sum); 
   }
   
void BD37534FV::setLoudness_f(int loud_f){
            switch(loud_f){
               case 0: loud_f = 0b00000001;break;
               case 1: loud_f = 0b00001001;break;
               case 2: loud_f = 0b00010001;break;
               case 3: loud_f = 0b00011001;break;  
   }
            writeWire(SETUP_3, loud_f); 
   }

void BD37534FV::setIn(int in){
            writeWire(INPUT_SELECT, in); 
   }


void BD37534FV::setIn_gain(int in_gain, int mute){
            switch(mute){
               case 0: mute = 0b00000000;break;
               case 1: mute = 0b10000000;break;
   }
            int sum_in_gain = in_gain + mute;
            writeWire(INPUT_GAIN, sum_in_gain); 
   }

void BD37534FV::setVol(int vol){
            if(vol > 0){vol = 128 - vol;}
            if(vol <= 0){vol = abs(vol) + 128;}
            writeWire(VOLUME_GAIN, vol); 
   }

void BD37534FV::setFront_1(int front_1){
            if(front_1 > 0){front_1 = 128 - front_1;}
            if(front_1 <= 0){front_1 = abs(front_1) + 128;}
            writeWire(FADER_1_FRONT, front_1); 
   }

void BD37534FV::setFront_2(int front_2){
            if(front_2 > 0){front_2 = 128 - front_2;}
            if(front_2 <= 0){front_2 = abs(front_2) + 128;}
            writeWire(FADER_2_FRONT, front_2); 
   }

void BD37534FV::setRear_1(int rear_1){
            if(rear_1 > 0){rear_1 = 128 - rear_1;}
            if(rear_1 <= 0){rear_1 = abs(rear_1) + 128;}
            writeWire(FADER_1_REAR, rear_1); 
   }

void BD37534FV::setRear_2(int rear_2){
            if(rear_2 > 0){rear_2 = 128 - rear_2;}
            if(rear_2 <= 0){rear_2 = abs(rear_2) + 128;}
            writeWire(FADER_2_REAR, rear_2); 
   }

void BD37534FV::setSub(int sub){
            if(sub > 0){sub = 128 - sub;}
            if(sub <= 0){sub = abs(sub) + 128;}
            writeWire(FADER_SUB, sub); 
   }

void BD37534FV::mix(){
            writeWire(MIXING, 0b11111111); 
   }

void BD37534FV::setBass_setup(int bass_q, int bass_f){
            switch(bass_q){
               case 0: bass_q = 0b00000000;break;
               case 1: bass_q = 0b00000001;break;
               case 2: bass_q = 0b00000010;break;
               case 3: bass_q = 0b00000011;break;  
   }
            switch(bass_f){
               case 0: bass_f = 0b00000000;break;
               case 1: bass_f = 0b00010000;break;
               case 2: bass_f = 0b00100000;break;
               case 3: bass_f = 0b00110000;break;  
   }
            int bass_s_sum = bass_q + bass_f;
            writeWire(BASS_SETUP, bass_s_sum); 
   }

void BD37534FV::setTreble_setup(int treb_q, int treb_f){
            switch(treb_q){
               case 0: treb_q = 0b00000000;break;
               case 1: treb_q = 0b00000001;break; 
   }
            switch(treb_f){
               case 0: treb_f = 0b00000000;break;
               case 1: treb_f = 0b00010000;break;
               case 2: treb_f = 0b00100000;break;
               case 3: treb_f = 0b00110000;break;  
   }
            int treb_s_sum = treb_q + treb_f;
            writeWire(TREBLE_SETUP, treb_s_sum); 
   }

void BD37534FV::setBass_gain(int bass_gain){
                 if(bass_gain>0){bass_gain = bass_gain + 0b00000000;}                     
                 if(bass_gain<=0){bass_gain = abs(bass_gain) + 0b10000000;}  
               writeWire(BASS_GAIN, bass_gain);   
   }

void BD37534FV::setMiddle_gain(int mid_gain){
                 if(mid_gain>0){mid_gain = mid_gain + 0b00000000;}                     
                 if(mid_gain<=0){mid_gain = abs(mid_gain) + 0b10000000;}  
               writeWire(MIDDLE_GAIN, mid_gain);   
   }

void BD37534FV::setTreble_gain(int treb_gain){
                 if(treb_gain>0){treb_gain = treb_gain + 0b00000000;}                     
                 if(treb_gain<=0){treb_gain = abs(treb_gain) + 0b10000000;}  
               writeWire(TREBLE_GAIN, treb_gain);   
   }

void BD37534FV::setLoudness_gain(int loud_gain){
               writeWire(LOUDNESS_GAIN, loud_gain);  
   }


void BD37534FV::setMiddle_setup(int mid_q, int mid_f){
            switch(mid_q){
               case 0: mid_q = 0b00000000;break;
               case 1: mid_q = 0b00000001;break;
               case 2: mid_q = 0b00000010;break;
               case 3: mid_q = 0b00000011;break;  
   }
            switch(mid_f){
               case 0: mid_f = 0b00000000;break;
               case 1: mid_f = 0b00010000;break;
               case 2: mid_f = 0b00100000;break;
               case 3: mid_f = 0b00110000;break;  
   }
            int mid_s_sum = mid_q + mid_f;
            writeWire(MIDDLE_SETUP, mid_s_sum); 
   }



void BD37534FV::writeWire(char a, char b){
  Wire.beginTransmission(BD37534FV_address);
  Wire.write (a);
  Wire.write (b);
  Wire.endTransmission();
}
