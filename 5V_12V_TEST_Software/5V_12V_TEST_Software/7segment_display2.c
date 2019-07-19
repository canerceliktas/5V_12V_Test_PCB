// 4 digit 7 segment display kodlar�

	#define ADigit1 PIN_C0  //Display 1 in digitlerini 
  	#define ADigit2 PIN_C1  //topraklamak i�in gereken 
  	#define ADigit3 PIN_C2  //sinyalin al�nd��� 
 	#define ADigit4 PIN_C3  //portlar tan�mland�
  
  	#define BDigit1 PIN_C7  //Display 2 nin digitlerini 
  	#define BDigit2 PIN_C6  //topraklamak i�in gereken 
  	#define BDigit3 PIN_C5  //sinyalin al�nd��� 
  	#define BDigit4 PIN_C4  //portlar tan�mland�
  
  	float voltaj_olculenB=0;
  	float ondalikB=0;
  	char onlarB=0, birlerB=0, o_birlerB=0, o_onlarB=0;
  	voltaj_olculenB= VOLT_B*4.3;  //�l��len voltaj�n de�eri

	const int digitdot[10]={0xFE, 0x26, 0xBD, 0xAF, 0x67, 0xCF, 0xDF, 0xA6, 0xFF, 0xEF}; // 0-9 aras� say�lar(nokta i�erir)
	const int digit[10]={0xFA, 0x22, 0xB9, 0xAB, 0x65, 0xCB, 0xDB, 0xA2, 0xFB, 0xEB} // 0-9 aras� say�lar___
  
 
	void main(){
    
   	output_low(BDigit1); //Displayleri pasif duruma ald�k
   	output_low(BDigit2);
   	output_low(BDigit3);
  	output_low(BDigit4);



	while(1) {
	      
	birlerB=voltaj_olculenB%10;
	onlarB=voltaj_olculenB/10;
	int onluk_kisimB = (birlerB + onlarB * 10);
	ondalikB = (voltaj_olculenB / onluk_kisimB)*100;
	o_birler=ondalikB%10;
	o_onlar=ondalikB/10;


    output_high(BDigit1); //1.digit aktif edildi
    output_b(digit[onlarB]); // 1. digite onlar basama��n� yazd�r
    delay_ms(2);
     
    output_low(BDigit1);  //2. digite birler basama�� (yan�nda nokta ile)
    output_high(BDigit2);
    output_b(digitdot[birlerB]);
    delay_ms(2);

    output_low(BDigit2); //3. digite virg�lden sonraki ilk rakam� yazd�r
    output_high(BDigit3);
    output_b(digit[o_onlarB]);
    delay_ms(2);

    output_low(BDigit3); //4. digite virg�lden sonraki 2. rakam� yazd�r
    output_high(BDigit4);
    output_b(digit[o_birlerB]);
    delay_ms(2);
    output_low(BDigit4);


	    }
		
			}  