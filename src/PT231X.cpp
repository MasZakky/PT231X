#include "PT231X.h"

int8_t PT2310::begin(int8_t pin_CLK,int8_t pin_DATA,int8_t pin_STB,int8_t pin_CS){
  pinMode(pin_CLK,OUTPUT);pinMode(pin_DATA,OUTPUT);pinMode(pin_STB,OUTPUT);pinMode(pin_CS,OUTPUT);
  _pin[0] = pin_CLK;  _pin[1] = pin_DATA;  _pin[2] = pin_STB;  _pin[3] = pin_CS;
  return Process_OK;
}

int8_t PT2310::Volume(int8_t val){
  val = Constrain(val,0,49);
  _Vol = val;
  return Process_OK;
}
int8_t PT2310::UseValue(int8_t val){
  _UPN = val;
  return Process_OK;
}
int16_t PT2310::Constrain(int16_t val,int16_t val2,int16_t val3){
  if(_UPN != Use_POSITIVE){
    return constrain(val,(-1*val3),val2);
  }
  else{
    return constrain(val,val2,val3);
  }
}
void PT2310::SendTrans(){
  for(int8_t a = 0; a <=13; a++){
    digitalWrite(_pin[0],HIGH);
    digitalWrite(_pin[0],LOW);
    switch(a){
      case 0 : digitalWrite(_pin[1],HIGH); break;
      case 1 : digitalWrite(_pin[1],HIGH); break;
      case 2 : digitalWrite(_pin[1],((_Vol>>0)&0x01)); break;
      case 3 : digitalWrite(_pin[1],((_Vol>>1)&0x01)); break;
      case 4 : digitalWrite(_pin[1],((_Vol>>2)&0x01)); break;
      case 5 : digitalWrite(_pin[1],((_Vol>>3)&0x01)); break;
      case 6 : digitalWrite(_pin[1],((_Vol>>4)&0x01)); break;
      case 7 : digitalWrite(_pin[1],((_Vol>>5)&0x01)); break;
      case 8 : digitalWrite(_pin[1],HIGH); break;
      case 9 : digitalWrite(_pin[1],_pin[3]); break;
      case 10: digitalWrite(_pin[1],LOW); break;
      case 11: digitalWrite(_pin[1],HIGH); break;
      case 12: digitalWrite(_pin[1],HIGH); break;
    }
  }
  digitalWrite(_pin[2],HIGH);
  digitalWrite(_pin[2],LOW);
  return Process_OK;
}

/////////////////////////////////////////////////////////////

int8_t PT2313::begin(){
  _Address = AddrPT2313;
  return Process_OK;
}

int8_t PT2313::Volume(int8_t val){
  val = Constrain(val,0,63);
  if((int8_t)_DATA[0] == val) return Process_OK;
  _DATA[0] = val;
  return PT2313::setWrite(_DATA[0]);
}
int8_t PT2313::Bass(int8_t val){
  val = constrain(val,-7,7);
  if((int8_t)(_DATA[6]&0x0F) == val) return Process_OK;
  _DATA[6] = val | (6<<4);
  return PT2313::setWrite(_DATA[6]);
}
int8_t PT2313::Treble(int8_t val){
  val = constrain(val,-7,7);
  if((int8_t)(_DATA[7]&0x0F) == val) return Process_OK;
  _DATA[7] = val | (7<<4);
  return PT2313::setWrite(_DATA[7]);  
}

int8_t PT2313::Input(int8_t val){
  val -= 1;
  val = constrain(val,0,3);
  if((int8_t)(_DATA[5]&0x03) == val) return Process_OK;
  _DATA[5] = (_DATA[5]&(~(0x03))) | val | (1<<6);
  return PT2313::setWrite(_DATA[5]);  
}

int8_t PT2313::Balance(int8_t val){
  PT2313::Balance(val,ATT_LR);
  PT2313::Balance(val,ATT_RR);
  PT2313::Balance(val,ATT_LF);
  return PT2313::Balance(val,ATT_RF);
}
int8_t PT2313::Balance(int8_t val,int8_t val2){
  val = Constrain(val,0,79);
  val2 = constrain(val2,0,3);
  switch(val2){
    case ATT_LF: if((_DATA[1]&0x1F) != val)return PT2313::setWrite((_DATA[5]= val) | (5<<5)); break;
    case ATT_RF: if((_DATA[2]&0x1F) != val)return PT2313::setWrite((_DATA[6]= val) | (6<<5)); break; 
    case ATT_LR: if((_DATA[3]&0x1F) != val)return PT2313::setWrite((_DATA[7]= val) | (7<<5)); break;
    case ATT_RR: if((_DATA[4]&0x1F) != val)return PT2313::setWrite((_DATA[8]= val) | (8<<5)); break;
  }
  return Process_OK;
}

int8_t PT2313::Loudness(int8_t val){
  val = constrain(val,0,3);
  if((int8_t)((_DATA[5]>>3)&0x03) == val) return Process_OK;
  _DATA[5] = (_DATA[5]&(~(0x01<<3))) | val | (1<<6);
  return PT2313::setWrite(_DATA[5]);  
}
int8_t PT2313::ModeLoudness(int8_t val){
  val = constrain(val,0,1);
  if((int8_t)((_DATA[5]>>2)&0x01) == val) return Process_OK;
  _DATA[5] = (_DATA[5]&(~(0x01<<2))) | val | (1<<6);
  return PT2313::setWrite(_DATA[5]);  
}

int16_t PT2313::Constrain(int16_t val,int16_t val2,int16_t val3){
  if(_UPN != Use_POSITIVE){
    return constrain(val,(-1*val3),val2);
  }
  else{
    return constrain(val,val2,val3);
  }
}
int8_t PT2313::UseValue(int8_t val){
  _UPN = val;
  return Process_OK;
}

/////////////////////////////////////////////////////////////

int8_t PT2314::Balance(int8_t val,int8_t val2){
  val = Constrain(val,0,79);
  val2 = constrain(val2,0,3);
  switch(val2){
    case ATT_LR: if((_DATA[3]&0x1F) != val)return PT2314::setWrite((_DATA[7]= val) | (7<<5)); break;
    case ATT_RR: if((_DATA[4]&0x1F) != val)return PT2314::setWrite((_DATA[8]= val) | (8<<5)); break;
  }
  return Process_OK;
}

