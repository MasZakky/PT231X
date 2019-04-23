#include "PT231X.h"

PT2313 uPA;

void setup(){
  Wire.begin();
  uPA.begin();
  uPA.InstalWire(&Wire);
  
  uPa.Volume(0);
  //   UserValue == Use_POSITIVE => Volume 0 ~ 63  => 0dB ~ -78.75dB (1.25dB Step)
  //   UserValue == Use_NEGATIVE => Volume -63 ~ 0 => -78.75dB ~ 0dB (1.25dB Step)
     
  uPA.Bass(7); 
  //   Value   => -7 ~ 7 => -14dB ~ 14dB (2dB Step)
     
  uPA.Treble(7);
  //   Value   => -7 ~ 7 => -14dB ~ 14dB (2dB Step)

  uPA.UseValue(Use_POSITIVE); 
  uPA.UseValue(Use_NEGATIVE); 
       
  uPA.Balance(0);
//  uPA.Balance(0,ATT_LR);  // 0 dB Output ATT_LR
//  uPA.Balance(0,ATT_RR);  // 0 dB Output ATT_RR
//  uPA.Balance(0,ATT_LF);  // 0 dB Output ATT_LF
//  uPA.Balance(0,ATT_RF);  // 0 dB Output ATT_RF
  //             Value     ,Channel 
  //   UserValue == Use_POSITIVE => Balance 0 ~ 31  => 0dB ~ -38.75dB (1.25dB Step)
  //   UserValue == Use_NEGATIVE => Balance -31 ~ 0 => -38.75dB ~ 0dB (1.25dB Step)
  //   PT2313 => Channel => ATT_LR,ATT_RR,ATT_LF, or ATT_RF 

  uPA.Input(1); 
  //   PT2313 maks Input => 3       (3 Stereo)
     
  uPA.Loudness(0);  // 11.25 dB
//  uPA.Loudness(0);  // 7.5   dB
//  uPA.Loudness(0);  // 3.75  dB
//  uPA.Loudness(0);  // 0     dB
            

  uPA.ModeLoudness(Loudness_ON);      
//  uPA.ModeLoudness(Loudness_OFF);  

}

void loop() {
  // put your main code here, to run repeatedly:

}
