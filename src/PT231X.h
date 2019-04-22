#ifndef _PT231X_H_
#define _PT231X_H_

#include "Arduino.h"
#include "SendTrans.h"

 #if defined(Surr_SIMULATED) || defined(Surr_MUSIC) || defined(Surr_MOVIE) || defined(Surr_OFF)
   #undef Surr_SIMULATED 
   #undef Surr_MUSIC     
   #undef Surr_MOVIE     
   #undef Surr_OFF      
 #endif

 #if defined(ATT_LR)|| defined(ATT_RR) || defined(ATT_LF) || defined(ATT_RF)
   #undef ATT_LR
   #undef ATT_RR
   #undef ATT_LF
   #undef ATT_RF
  #endif
    #define ATT_LR 2
    #define ATT_RR 3
    #define ATT_LF 0
    #define ATT_RF 1
  
  #if defined(REAR_ACTIVE) || defined(REAR_OFF)
   #undef REAR_ACTIVE
   #undef REAR_OFF
  #endif
  
  #if defined(NATURALBASE_ACTIVE) || defined(NATURALBASE_OFF)
   #undef NATURALBASE_ACTIVE
   #undef NATURALBASE_OFF
  #endif
  
  #if defined(VOICECANCELLER_OFF) || defined(VOICECANCELLER_ON)
   #undef VOICECANCELLER_OFF
   #undef VOICECANCELLER_ON
  #endif
  
  #if defined(Out_3BAND) || defined(Out_SURR) || defined(Out_REAR) || defined(Out_FLAT)
   #undef Out_3BAND
   #undef Out_SURR
   #undef Out_REAR
   #undef Out_FLAT
   #undef Out_OFF
  #endif

  #if defined(RecOut_L) || defined(RecOut_R)
   #undef RecOut_L
   #undef RecOut_R
  #endif
  
  #if defined(Use_NEGATIVE) || defined(Use_POSITIVE)
    #undef Use_NEGATIVE 
    #undef Use_POSITIVE 
  #endif
    #define Use_NEGATIVE -1
    #define Use_POSITIVE 1

  #if defined(MUTE_OFF) || defined(MUTE_ON)
    #undef MUTE_OFF  
    #undef MUTE_ON 
  #endif
    #define MUTE_OFF  0
    #define MUTE_ON   1
  
  #if defined(Loudness_ON) || defined(Loudness_OFF)
    #undef Loudness_ON
    #undef Loudness_OFF
  #endif
    #define Loudness_ON 0
    #define Loudness_OFF 1

  #if defined(Yes_ExtendedBassRange) || defined(Not_ExtendedBassRange)
    #undef Yes_ExtendedBassRange
    #undef Not_ExtendedBassRange
  #endif

  #if defined(Yes_SymmetricalBassCut) || defined(Not_SymmetricalBassCut)
    #undef Not_SymmetricalBassCut
    #undef Yes_SymmetricalBassCut
  #endif
  
  #define AddrPT2313 0x88
  
class PT2310{
  public:
    int8_t begin(int8_t pin_CLK,int8_t pin_DATA,int8_t pin_STB,int8_t pin_CS);
    int8_t Volume(int8_t val);

    int8_t UseValue(int8_t val = Use_POSITIVE);
    
  protected:
    int16_t Constrain(int16_t val,int16_t val2,int16_t val3);
    int8_t _pin[4],_UPN;
    byte _Vol;
    void SendTrans();  
};

class PT2313 :public SendTransI2C{
  public: 
    int8_t begin();
    
    int8_t Volume(int8_t val = 0);
    int8_t Bass(int8_t val = 7);
    int8_t Treble(int8_t val = 7);

    int8_t UseValue(int8_t val);
    
    int8_t Balance(int8_t val = 0);           //Value
    int8_t Balance(int8_t val,int8_t val2);   //Value,channel

    int8_t Input(int8_t val = 1);

    int8_t Loudness(int8_t val = 3);
    int8_t ModeLoudness(int8_t val = Loudness_ON);
  protected:
    byte _DATA[8];
    int16_t Constrain(int16_t val,int16_t val2,int16_t val3);
    int8_t MaxInput(int8_t val = 3);
    int8_t _UPN,_MInput;
};

class PT2314 :public PT2313{
  public:
    int8_t Balance(int8_t val,int8_t val2);   //Value,channel
  protected:
};

#endif
