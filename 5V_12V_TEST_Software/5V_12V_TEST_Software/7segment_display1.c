
//-----------------------DISPLAY KODLARI (7 SEGMENT CONVERT)------------------------
//----------------------------------------------------------------------------------

//Port sýrasý    7  6  5  4  3  2  1  0 
//Segmentler	 a  f  b  e  d  dp c  g
	
void Convert7Segment(ref)	
{
	switch (ref)
	{
	case 0:
	DIGIT_VAL = (0b11111010);
	break;

	case 1:
	DIGIT_VAL = (0b00100010);
	break;
	
 	case 2:
	DIGIT_VAL = (0b10111001);
	break;

	case 3:
	DIGIT_VAL = (0b10101011);
	break;

	case 4:
	DIGIT_VAL = (0b01100011);
	break;

	case 5: 
	DIGIT_VAL = (0b11001011);
	break;
	
	case 6:
	DIGIT_VAL = (0b11011011);
	break;

	case 7:
	DIGIT_VAL = (0b10100010);
	break;

	case 8:
	DIGIT_VAL = (0b11111011);
	break;

	case 9: 
	DIGIT_VAL = (0b11101011);
	break;	
	{
}


///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////














































































////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////  ESKÝ KODLAR////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
const int digitdot[10]={0xFE, 0x26, 0xBD, 0xAF, 0x67, 0xCF, 0xDF, 0xA6, 0xFF, 0xEF}; // 0-9 arasý sayýlar(nokta içerir)
const int digit[10]={0xFA, 0x22, 0xB9, 0xAB, 0x65, 0xCB, 0xDB, 0xA2, 0xFB, 0xEB} // 0-9 arasý sayýlar___
  
 
void main(){
    
   output_low(ADigit1); //Displayleri pasif duruma aldýk
   output_low(ADigit2);
   output_low(ADigit3);
   output_low(ADigit4);



     while(1) {
	      
	     


     output_high(ADigit1); //1.digit aktif edildi
     output_b(digit[onlar]); // 1. digite onlar basamaðýný yazdýr
     delay_ms(2);
     
     output_low(ADigit1);  //2. digite birler basamaðý (yanýnda nokta ile)
     output_high(ADigit2);
     output_b(digitdot[birler]);
     delay_ms(2);

     output_low(ADigit2); //3. digite virgülden sonraki ilk rakamý yazdýr
     output_high(ADigit3);
     output_b(digit[o_onlar]);
     delay_ms(2);

     output_low(ADigit3); //4. digite virgülden sonraki 2. rakamý yazdýr
     output_high(ADigit4);
     output_b(digit[o_birler]);
     delay_ms(2);
     output_low(ADigit4);


	    }
}  