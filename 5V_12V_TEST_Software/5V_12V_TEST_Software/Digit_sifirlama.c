//-----------------------------------------------------------------//
//------------------------DISPLAY DRIVE----------------------------//

void DisplayDrive()
{
	OUTPUT_B(0); 			// C PORTUNUN BÜTÜN ÇIKIÞLARI LOJÝK 0 YAPILDI
	OUTPUT_BIT(PIN_A3,0); 	//A portunun a3 pini 0 yapýldý
}

switch (DigitOrder)
{
	case 0;
	++DigitOrder;
	OUTPUT_B(DIGIT_1);
	OUTPUT_HIGH(ADigit1);
	break;
	
	case 1;
	++DigitOrder;
	OUTPUT_B(DIGIT_2);-
	OUTPUT_HIGH(ADigit2);
	break;

	case 2;
	++DigitOrder;
	OUTPUT_B(DIGIT_3);
	OUTPUT_HIGH(ADigit3);
	break;
	
	case 3;
	++DigitOrder;
	OUTPUT_B(DIGIT_4);
	OUTPUT_HIGH(ADigit4)
	
	case 4;
	++DigitOrder;
	OUTPUT_B(DIGIT_5);
	OUTPUT_HIGH(BDigit1);
	
	case 5; 
	++DigitOrder;
	OUTPUT_B(DIGIT_6);
	OUTPUT_HIGH(BDigit2);
 	break; 
	
	case 6;
	++DigitOrder;
	OUTPUT_B(DIGIT_7);
	OUTPUT_HIGH(BDigit3);
	break;
	
	case 7;
	++DigitOrder;
	OUTPUT_B(DIGIT_8)
	OUTPUT_HIGH(BDigit4);
	break;
	
	case 8;
	OUTPUT_B(LED_NUM);
	OUTPUT_HIGH(LED_COM);
	DigitOrder=0;
	break;
	
}