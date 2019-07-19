   	
#define ADigit1 PIN_C0  //Display 1 in digitlerini 
#define ADigit2 PIN_C1  //topraklamak için gereken 
#define ADigit3 PIN_C2  //sinyalin alýndýðý 
#define ADigit4 PIN_C3  //portlar tanýmlandý
  
#define BDigit1 PIN_C7  //Display 2 nin digitlerini 
#define BDigit2 PIN_C6  //topraklamak için gereken 
#define BDigit3 PIN_C5  //sinyalin alýndýðý 
#define BDigit4 PIN_C4  //portlar tanýmlandý

#define Buzzer 	PIN_A2
#define LED_COM PIN_A3

#define	adc_sample	100

#define LED_A_L	LED_NUM,7
#define LED_A_H	LED_NUM,5
#define LED_B_L	LED_NUM,1
#define LED_B_H	LED_NUM,3

#define BUTTON_1 PIN_A4
#define BUTTON_2 PIN_A5	

int	DIGIT_1,DIGIT_2,DIGIT_3,DIGIT_4,DIGIT_5,DIGIT_6,DIGIT_7,DIGIT_8,LED_NUM; 	
int TIME_MAKER,REG_10ms,REG_20ms,REG_200ms, adc_counter,DigitOrder, DIGIT_VAL;							//////17.23 ise  1=onlar, 7=birler, 2=o_onlar, 3=o_birler////
int BCD_1000, BCD_100, BCD_10, BCD_1;
int set_active_all,set_active_a,set_active_b,set_active_disp,set_status;

int SET_B_L, SET_B_H, SET_A_L, SET_A_H ;

int VOLT_A_L = 214;																						
int VOLT_A_H = 316;
int VOLT_B_L = 233;
int VOLT_B_H = 243;

int16 VOLT_A, VOLT_B, VOLT_OLCULEN_A, VOLT_OLCULEN_B;

int32 adc_temp1, adc_temp2;
