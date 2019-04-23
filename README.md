# PT231X
<h3>Library</h3>
<ul> 
  <li><a href="https://www.digchip.com/datasheets/parts/datasheet/380/PT2310L-pdf.php"        >PT2310 </a>OK</li>
  <li><a href="http://read.pudn.com/downloads28/sourcecode/windows/csharp/88554/PT2313_e.pdf" >PT2313 </a>OK</li>
  <li><a href="http://www.turuta.md/DSHEETS/PT2314_3.pdf"                                     >PT2314 </a>OK</li>
</ul>

<h3>PT2310</h3>
<h4>Command</h4>

    1. int8_t begin(int8_t pin_CLK,int8_t pin_DATA,int8_t pin_STB,int8_t pin_CS);
          pin_CLK  = Clock
          pin_DATA = Data
          pin_STB  = STB
          pin_CS   = CS => HIGH or LOW
          
    2. int8_t Volume(int8_t val);
         Default => 0 (0dB)
         UserValue == Use_POSITIVE => Volume 0 ~ 39  => 0dB ~ -79dB (2dB Step)
         UserValue == Use_NEGATIVE => Volume -39 ~ 0 => -79dB ~ 0dB (2dB Step)
    
    3. int8_t UseValue(int8_t val); 
         Default => Use_POSITIVE 
         Value   => Use_POSITIVE or Use_NEGATIVE
         
         
<h3> Main (only PT2313 & PT2314)</h3>
<h4><a href="https://github.com/MasZakky/SendTrans" target="_blank"> Command </a>: </h4>
      
    1. int8_t InstalWire(TwoWire *val);
         Default => NULL
         Syntax:
         - InstalWire(&Wire);
         - InstalWire(&Wire1);
         - InstalWire(&Wire2);
         
    // additional
    2. int8_t setMultiPlexer(int8_t val,int8_t val2);
                       Value     ,IC MuliPlexer
         Default => Not_UseSwitch & Use_TCA9548A 
         Value   => Not_UseSwitch or Yes_UseSwitch
         IC      => Use_TCA9548A
    
    3. int8_t setAddressMultiPlexer(byte Address,byte val1,byte val2,byte val3,byte val4);
                                 Value       ,A0       ,A1       ,A2       ,A3 or 0
         Default     => _AddressTCA9548A & A0 = 0 & A1 = 0 & A2 = 0 & A3 = 0                           
         Value       => Address IC MuliPlexer
         pinAddr     => A0,A1,A2,A3/0
    
    4. int8_t setChannel(int8_t val);
                      Channel
         Default => 0
         Channel => 0 ~ 7
         
<h3>PT2313 & PT2314</h3>
<h4>Command</h4>
    
    1. int8_t begin();
    
    2. int8_t Volume(int8_t val);
         Default => 0 (0dB)
         UserValue == Use_POSITIVE => Volume 0 ~ 63  => 0dB ~ -78.75dB (1.25dB Step)
         UserValue == Use_NEGATIVE => Volume -63 ~ 0 => -78.75dB ~ 0dB (1.25dB Step)
         
    3. int8_t Bass(int8_t val);
         Default => 7 (14dB)
         Value   => -7 ~ 7 => -14dB ~ 14dB (2dB Step)
         
    4. int8_t Treble(int8_t val);
         Default => 7 (14dB)
         Value   => -7 ~ 7 => -14dB ~ 14dB (2dB Step)
    
    5. int8_t UseValue(int8_t val); 
         Default => Use_POSITIVE 
         Value   => Use_POSITIVE or Use_NEGATIVE 
         
    6. int8_t Balance(int8_t val);
    7. int8_t Balance(int8_t val,int8_t val2);   
                   Value     ,Channel 
         Default => 0dB  
         UserValue == Use_POSITIVE => Balance 0 ~ 31  => 0dB ~ -38.75dB (1.25dB Step)
         UserValue == Use_NEGATIVE => Balance -31 ~ 0 => -38.75dB ~ 0dB (1.25dB Step)
         PT2314 => Channel => ATT_LR or ATT_RR
         PT2313 => Channel => ATT_LR,ATT_RR,ATT_LF, or ATT_RF 
    
    8. int8_t Input(int8_t val); 
         Default  => 1
         PT2313 maks Input => 3       (3 Stereo)
         PT2313 maks Input => 3       (3 Stereo)
         
    9. int8_t Loudness(int8_t val);          
          Default => 3 (0dB)
 
    10. int8_t ModeLoudness(int8_t val);      
          Default => Loudness_ON
          Value   => Loudness_ON or Loudness_OFF
          
          
<h4>Notice</h4>
<pre><h5> 
    if  defined(__AVR_AT90Mega169__)  or defined(__AVR_ATmega169__)   or
        defined(__AVR_AT90Mega165__)  or defined(__AVR_ATmega165__)   or
        defined(__AVR_ATmega325__)    or defined(__AVR_ATmega3250__)  or
        defined(__AVR_ATmega645__)    or defined(__AVR_ATmega6450__)  or
        defined(__AVR_ATmega329__)    or defined(__AVR_ATmega3290__)  or
        defined(__AVR_ATmega649__)    or defined(__AVR_ATmega6490__)  or
        defined(__AVR_ATtiny25__)     or defined(__AVR_ATtiny45__)    or defined(__AVR_ATtiny85__) or
        defined(__AVR_AT90Tiny26__)   or defined(__AVR_ATtiny26__)    or
        defined(__AVR_ATtiny84__)     or defined(__AVR_ATtiny44__)    or
        defined(__AVR_AT90Tiny2313__) or defined(__AVR_ATtiny2313__)
            Automatic disable "InstalWire" and "Wire" will be replaced with "TinyWireM" 
            Download<a href="https://github.com/adafruit/TinyWireM" target="_blank"> TinyWireM library </a>
        
        
        
</h5></pre>
