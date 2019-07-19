
//-------------------------------------------------------------------------------
//---------ÖLÇÜLEN DEÐERLERÝ KARÞILAÞTIRMA FONKSÝYONU----------------------------

void READ_VOLTAGE(void)	//karþýlaþtýrma kodlarýný içeren fonksiyon
{															 
	set_adc_channel(0);
	delay_us(5);					// Kanal seçiminde sonra bu bekleme süresi verilmelidir    
	adc_temp1=adc_temp1+read_adc();
	set_adc_channel(1);    	  
	delay_us(5);
	adc_temp2=adc_temp2+read_adc(); // adc_temp : 100 adet sample ý depoladýðýmýz deðiþken
	++adc_counter;          		// adc_counter : bu deðiþken 100 e ulaþtýðýnda toplam sample lar aldýðýmýz örnek sayýsýna bölünüp 
									// ilgili deðþkenlere aktarýlýr
	if (adc_counter == adc_sample) 
	{
		adc_counter = 0;   			//adc_counter, yeteri kadar sample aldýðýnda adc sýfýrlanýr			
		VOLT_A = (adc_temp1/adc_sample);
		VOLT_B = (adc_temp2/adc_sample);
	}
}
//////////////////////////////////////////////////////////////////////



//-----------------------DISPLAY KODLARI (7 SEGMENT CONVERT)------------------------
//----------------------------------------------------------------------------------

//Pin sýrasý     7  6  5  4  3  2  1  0 
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
	}	
}


///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////


//-----------------------------------------------------------------//
//------------------------DISPLAY DRIVE----------------------------//

void DisplayDrive(void)
{
	OUTPUT_B(0); 			// C PORTUNUN BÜTÜN ÇIKIÞLARI LOJÝK 0 YAPILDI
	OUTPUT_BIT(PIN_A3,0); 	//A portunun a3 pini 0 yapýldý (LED_COM)


	switch (DigitOrder)
	{
		case 0:
		++DigitOrder;
		OUTPUT_B(DIGIT_1);
		OUTPUT_HIGH(ADigit1);
		break;
	
		case 1:
		++DigitOrder;
		OUTPUT_B(DIGIT_2);-
		OUTPUT_HIGH(ADigit2);
		break;

		case 2:
		++DigitOrder;
		OUTPUT_B(DIGIT_3);
		OUTPUT_HIGH(ADigit3);
		break;
	
		case 3:
		++DigitOrder;
		OUTPUT_B(DIGIT_4);
		OUTPUT_HIGH(ADigit4);
	
		case 4:
		++DigitOrder;
		OUTPUT_B(DIGIT_5);
		OUTPUT_HIGH(BDigit1);
	
		case 5:
		++DigitOrder;
		OUTPUT_B(DIGIT_6);
		OUTPUT_HIGH(BDigit2);
	 	break;
	
		case 6:
		++DigitOrder;
		OUTPUT_B(DIGIT_7);
		OUTPUT_HIGH(BDigit3);
		break;
	
		case 7:
		++DigitOrder;
		OUTPUT_B(DIGIT_8);
		OUTPUT_HIGH(BDigit4);
		break;
	
		case 8:
		OUTPUT_B(LED_NUM);
		OUTPUT_HIGH(LED_COM);
		DigitOrder=0;
		break;
	}

}

////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////

//---------------------------------------------------------------------------------------
//---------------------------DISPLAYE YAZDIRMA FONKSÝYONLARI-----------------------------

void AssignDisplay1 ()
{
	Convert7Segment(BCD_1000);
	DIGIT_1 = DIGIT_VAL;	
	Convert7Segment(BCD_100);
	DIGIT_2 = DIGIT_VAL;
	Convert7Segment(BCD_10);
	DIGIT_3 = DIGIT_VAL;
	Convert7Segment(BCD_1);
	DIGIT_4 = DIGIT_VAL;
	
}

void AssignDisplay2()
{
	Convert7Segment(BCD_1000);
	DIGIT_5 = DIGIT_VAL;
	Convert7Segment(BCD_100);
	DIGIT_6 = DIGIT_VAL;
	Convert7Segment(BCD_10);
	DIGIT_7 = DIGIT_VAL;
	Convert7Segment(BCD_1);
	DIGIT_8 = DIGIT_VAL;
	
}

/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////

/*#######################################################################*/
/*#######################################################################*/
void ConvertBINARYtoBCD(int16 VOLT_OLCULEN)
	{
	BCD_1000=(VOLT_OLCULEN/1000);
	BCD_100=((VOLT_OLCULEN-(BCD_1000*1000))/100);
	BCD_10=((VOLT_OLCULEN-(BCD_1000*1000)-(BCD_100*100))/10);
	BCD_1=(VOLT_OLCULEN-(BCD_1000*1000)-(BCD_100*100)-(BCD_10*10));
	}
/*#######################################################################*/
/*#######################################################################*/



//********************************************************************************//
//*********************SETT DISPLAY 1-2*********************************************//

void SETT_VOLT_B_L(void)
	{
	 while(input(BUTTON_2))	
		{
		 delay_ms(10);
		 ++VOLT_B_L;
		}
	 while(input(BUTTON_1))
		{
		 delay_ms(10);
		 --VOLT_B_L;
		}
	SET_B_L=((5*VOLT_B_L)/1024)*1000;
	ConvertBINARYtoBCD(SET_B_L);
	AssignDisplay2();
	}

////////////////////////////////////////////////////////////////////////////////////////
void SETT_VOLT_B_H(void)
	{
	 while(input(BUTTON_2))
		{
		 delay_ms(10);
		 ++VOLT_B_H;
		}	
	 while(input(BUTTON_1))
		{
		 delay_ms(10);
		 --VOLT_B_H;
		}
	
	SET_B_H=((5*VOLT_B_H)/1024)*1000;
	ConvertBINARYtoBCD(SET_B_H);
	AssignDisplay2();
	}

////////////////////////////////////////////////////////////////////////////////////////
void SETT_VOLT_A_L(void)
	{
	while(input(BUTTON_2))
		{
		 delay_ms(10);
		 ++VOLT_A_L;
		}	
	while(input(BUTTON_1))
		{
		 delay_ms(10);
		 --VOLT_A_L;
		}
	SET_A_L=((5*VOLT_A_L)/1024)*1000;
	ConvertBINARYtoBCD(SET_A_L);
	AssignDisplay1();
	}
////////////////////////////////////////////////////////////////////////////////////////

void SETT_VOLT_A_H(void)
	{
	 while(input(BUTTON_2))// VOLT A NIN ÜST GERÝLÝM SINIRINI BELÝRLE
		{
		 delay_ms(10);
		 ++VOLT_A_H;
		}
	 while(input(BUTTON_1))
		{
		 delay_ms(10);
		 --VOLT_A_H;
		}
	SET_A_H=((5*VOLT_A_H)/1024)*1000;
	ConvertBINARYtoBCD(SET_A_H);
	AssignDisplay1();
	}

///////////////////////////////////////////////////////////////////////////////////////


//void SETT_VOLT_B_L(void)
//	{
//	 if (BUTTON_2 == 1)	
//		{
//		 delay_ms(10);
//		 ++VOLT_B_L;
//		}
//	 if (BUTTON_1 == 1)
//		{
//		 delay_ms(10);
//		 --VOLT_B_L;
//		}
//	SET_B_L=((5*VOLT_B_L)/1024)*1000;
//	ConvertBINARYtoBCD(SET_B_L);
//	AssignDisplay2();
//	}