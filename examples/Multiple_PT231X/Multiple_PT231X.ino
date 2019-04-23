#include "PT231X.h"

PT2313 uPA[8];
//PT2314 uPA[8];

/*   ___________    ___________      _____________       _____________          ___________
 *  | uC / uP   |  |+5V / +3.3V|    |             |     | +5V / +3.3V |        | PT231X [0]| SALVE 1 ~ n
 *  |       SCL |==|   PulUp   |===>| SCL    SCL0 |=====|  PulUp      |=======>| SCL       |
 *  |       SDA |<=|   PulUp   |===>| SDA    SDA0 |<====|  PulUp      |=======>| SDA       |
 *  |           |  |___________|    |             |     |_____________|        |___________|
 *  |           |                   |    T        |     | +5V / +3.3V |        | PT231X [1]| SALVE 1 ~ n
 *  |___________|                   |    C   SCL1 |=====|  PulUp      |=======>| SCL       |
 *                                  |    A   SDA1 |<====|  PulUp      |=======>| SDA       |
 *                                  |    9        |     |_____________|        |___________|
 *                                  |    5        |     | +5V / +3.3V |        | PT231X [2]| SALVE 1 ~ n
 *                                  |    4   SCL2 |=====|  PulUp      |=======>| SCL       |
 *                                  |    8   SDA2 |<====|  PulUp      |=======>| SDA       |
 *                                  |    A        |     |_____________|        |___________|
 *                                  |             |     | +5V / +3.3V |        | PT231X [3]| SALVE 1 ~ n
 *                                  |        SCL3 |=====|  PulUp      |=======>| SCL       |
 *                                  |        SDA3 |<====|  PulUp      |=======>| SDA       |
 *                                  |             |     |_____________|        |___________|
 *                                  |             |     | +5V / +3.3V |        | PT231X [4]| SALVE 1 ~ n
 *                                  |        SCL4 |=====|  PulUp      |=======>| SCL       |
 *                                  |        SDA4 |<====|  PulUp      |=======>| SDA       |
 *                                  |             |     |_____________|        |___________|
 *                                  |             |     | +5V / +3.3V |        | PT231X [5]| SALVE 1 ~ n
 *                                  |        SCL5 |=====|  PulUp      |=======>| SCL       |
 *                                  |        SDA5 |<====|  PulUp      |=======>| SDA       |
 *                                  |             |     |_____________|        |___________|
 *                                  |             |     | +5V / +3.3V |        | PT231X [6]| SALVE 1 ~ n
 *                                  |        SCL6 |=====|  PulUp      |=======>| SCL       |
 *                                  |        SDA6 |<====|  PulUp      |=======>| SDA       |
 *                                  |             |     |_____________|        |___________|
 *                                  |             |     | +5V / +3.3V |        | PT231X [7]| SALVE 1 ~ n
 *                                  |        SCL7 |=====|  PulUp      |=======>| SCL       |
 *                                  |        SDA7 |<====|  PulUp      |=======>| SDA       |
 *                                  |_____________|     |_____________|        |___________|
 */



void setup() {
  Wire.begin();
  for(int a = 0; a <= 8; a++){
   uPA[a].begin();
   uPA[a].InstalWire(&Wire);
   // Instal Wire

   uPA[a].setMultiPlexer(Yes_UseSwitch,Use_TCA9548A);
   //                 Value        ,Name IC
   // Default => No_UseSwitch 
   // Value   => No_UseSwitch or Yes_UseSwitch
  
   uPA[a].setAddressMultiPlexer(0x70   ,0 ,0 ,0 ,0);
   //                        Address,A0,A1,A2,0
  
   uPA[a].setChannel(a);
   //             Value
   // Value => 0 ~ 7 
 } 


}

void loop() {
 for(int a = 0; a <= 8; a++) {
  for(int b = 0; b <= 80; b++){
   uPA[a].Volume(b);
   delay(10);
  } 
  for(int b = 80; b >= 0; b--){
   uPA[a].Volume(b);
   delay(10);
  } 
  for(int b = 7; b >= -8; b--){
   uPA[a].Treble(b);
   delay(10);
  } 
  for(int b = - 7; b <= 8; b++){
   uPA[a].Treble(b);
   delay(10);
  } 
  for(int b = 7; b >= -8; b--){
   uPA[a].Bass(b);
   delay(10);
  } 
  for(int b = - 7; b <= 8; b++){
   uPA[a].Bass(b);
   delay(10);
  } 
 } 
}
