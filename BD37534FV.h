#ifndef BD37534FV_H
#define BD37534FV_H

#define BD37534FV_address 0b1000000 

#define SETUP_1        0x01
#define SETUP_2        0x02
#define SETUP_3        0x03
#define INPUT_SELECT   0x05
#define INPUT_GAIN     0x06
#define VOLUME_GAIN    0x20
#define FADER_1_FRONT  0x28
#define FADER_2_FRONT  0x29
#define FADER_1_REAR   0x2A
#define FADER_2_REAR   0x2B
#define FADER_SUB      0x2C
#define MIXING         0x30
#define BASS_SETUP     0x41
#define MIDDLE_SETUP   0x44
#define TREBLE_SETUP   0x47
#define BASS_GAIN      0x51
#define MIDDLE_GAIN    0x54
#define TREBLE_GAIN    0x57
#define LOUDNESS_GAIN  0x75

#include <Arduino.h>
class BD37534FV
{
  public:
    BD37534FV();
    void setSetup_1(int sw_of, int sw_time, int time_mute); // default (1,2,0)
        void setSetup_2(int sub_f, int sub_out, int level_metr, int faza); 
                   // int sub_f ------ OFF 55Hz 85Hz 120Hz 160Hz = int 0...4
                   // int sub_out ---- LPF Front Rear Prohibition = int 0...3
                   // int level_metr - HOLD REST = int 0..1
                   // int faza ------- 0 180 = int 0...1
        void setLoudness_f(int loud_f); // 250Hz 400Hz 800Hz Prohibition = int 0...3
        void setIn(int in); // 0...2
        void setIn_gain(int in_gain, int mute); // in_gain -- 0...20 = 0...20 dB, mute -- 0 default 
        void setVol(int vol); // -79...+15 dB = int -79...15
        void setFront_1(int front_1); // -79...+15 dB = int -79...15
        void setFront_2(int front_2); // -79...+15 dB = int -79...15
        void setRear_1(int rear_1); // -79...+15 dB = int -79...15
        void setRear_2(int rear_2); // -79...+15 dB = int -79...15
        void setSub(int sub); // -79...+15 dB = int -79...15
        void mix();
        void setBass_setup(int bass_q, int bass_f); // 0.5 1.0 1.5 2.0 --- int 0...3, 60Hz 80Hz 100Hz 120Hz --- int 0...3
        void setMiddle_setup(int mid_q, int mid_f); // 0.75 1.0 1.25 1.5 --- int 0...3, 500Hz 1kHz 1.5kHz 2.5kHz --- int 0...3
        void setTreble_setup(int treb_q, int treb_f); // 0.75 1.25  --- int 0...1, 7.5kHz 10kHz 12.5kHz 15kHz --- int 0...3
        void setBass_gain(int bass_gain); // --20 ... +20 dB = int -20 ... 20    
        void setMiddle_gain(int mid_gain); // --20 ... +20 dB = int -20 ... 20
        void setTreble_gain(int treb_gain); // --20 ... +20 dB = int -20 ... 20        
        void setLoudness_gain(int loud_gain); // 0 ... 20 dB = int 0 ... 20

  private:
    void writeWire(char a, char b);
};
    
#endif //BD37534FV_H
