#define Buzzer_C PORTA.A2

Buzzer:

while(1) {
 
  output_high(pin_a2); //A2 yi lojik 1 yap 
  delay(5);       //
    
  output_low(pin_a2);
  delay(5);

}