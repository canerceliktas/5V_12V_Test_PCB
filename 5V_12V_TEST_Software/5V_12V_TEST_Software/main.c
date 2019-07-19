#include <16f876.h>
#FUSES XT, WDT, PUT,BROWNOUT, CPD, WRT, PROTECT        	//BROWN OUT D��ERSE RESETLER, POWER UP TIMER KALKI�TA BEL�RL� DE�ERE KADAR RESETL� TUTAR
#device	adc=10
#use delay(clock=4000000,RESTART_WDT) 


#include "Definitions.c"
#include "Subroutins.c"



///////////////////////////////////////////////////////////////

#int_TIMER0
void TIMER0_isr(void)
{
	set_timer0(148);			//Ka� sn de bir bu kesmeye ula�aca��n� belirledik.		
	++TIME_MAKER;				//Bu de�i�ken her d�ng� de 1 artar.
	DisplayDrive();
}
///////////////////////////////////////////////////////////////


void main(void)
{
	setup_timer_0(T0_INTERNAL|T0_DIV_2|T0_8_BIT); 
	setup_timer_1(T1_DISABLED);    
	setup_timer_2(T2_DISABLED,0,1); 
	setup_CCP1(CCP_OFF);            //port y�nleri            
	setup_CCP2(CCP_OFF);            //belirlenir
	setup_spi(SPI_SS_DISABLED);  
   
	setup_adc(adc_clock_div_8);
	setup_adc_ports(AN0_AN1_AN3);

	
	enable_interrupts(INT_TIMER0);
	enable_interrupts(GLOBAL);
	set_timer0(148);

	SET_TRIS_A(0b00110011);         		// A0,A1,A4,A5 pinleri giri� olarak ayarland�
	SET_TRIS_B(0b00000000);        			//B portu komple ��k��
	SET_TRIS_C(0b00000000);         		//C portu komple ��k��


	while(1)
	{
		restart_wdt();						//WatchDogTimer �n uyar� vermesini engellemek i�in
 		if(TIME_MAKER>=4)					//1ms lik i�ler
		{
			TIME_MAKER=0;
			++REG_10ms;
			///////
			READ_VOLTAGE();


			if (VOLT_A < VOLT_A_L)
			{
				BIT_SET(LED_A_L);			//UYGUN LED B�TLER� B PORTUNA ATANDI
				output_high(Buzzer); 		// BUZZER �IKI�I LOJ�K 1 YAPILDI
			}
			else
			{
				BIT_CLEAR(LED_A_L);			//UYGUN LED B�TLER� B PORTUNA ATANDI
				OUTPUT_LOW(Buzzer); 		// BUZZER �IKI�I LOJ�K 1 YAPILDI
			}
		
		    if (VOLT_A > VOLT_A_H)
			{
				BIT_SET(LED_A_H);
				output_high(Buzzer);
			}
			else
			{
				BIT_CLEAR(LED_A_H);			//UYGUN LED B�TLER� B PORTUNA ATANDI
				OUTPUT_LOW(Buzzer); 
			}
	
			if (VOLT_B < VOLT_B_L)
			{
				BIT_SET(LED_B_L);			//UYGUN LED B�TLER� B PORTUNA ATANDI
				output_high(Buzzer); 		// BUZZER �IKI�I LOJ�K 1 YAPILDI
			}
			else
			{
				BIT_CLEAR(LED_B_L);			//UYGUN LED B�TLER� B PORTUNA ATANDI
				OUTPUT_LOW(Buzzer); 		// BUZZER �IKI�I LOJ�K 1 YAPILDI
			}
		
		    if (VOLT_B > VOLT_B_H)
			{
				BIT_SET(LED_B_H);
				output_high(Buzzer);
			}
			else
			{
				BIT_CLEAR(LED_B_H);			//UYGUN LED B�TLER� B PORTUNA ATANDI
				OUTPUT_LOW(Buzzer); 
			}


		}
			
				


		if(REG_10ms>=10)					// 10 ms lik i�ler
		{
			REG_10ms=0;
			++REG_20ms;
			///////

			VOLT_OLCULEN_A = ((5*VOLT_A)/1024)*4.3*1000;
			ConvertBINARYtoBCD(VOLT_OLCULEN_A);	
			AssignDisplay1 ();
		
			VOLT_OLCULEN_B = ((5*VOLT_B)/1024)*11*1000;
			ConvertBINARYtoBCD(VOLT_OLCULEN_B);
			AssignDisplay2 ();
			
				
		}
	





		if(REG_20ms>=2)					// 20 ms lik i�ler
		{
			REG_20ms=0;
			++REG_200ms;
			///////
			
			if((BUTTON_1==1)&&(BUTTON_2==1))
				{
				 set_status=1;   			// AYAR MODUNA G�R�LD�
				 delay_ms(1000);
				 set_active_disp=1;			//BU DE���KEN�N DURUMUNA G�RE HANG� LED� YAKACA�INI B�LD�R�YOR
				 set_active_all=1;
				}
			while((BUTTON_1==1)&&(BUTTON_2==1))
				{
				 ++set_active_all;					//BU DE���KEN 300 E GELENE KADAR EKRANDA SETT YAZACAK			
				}
			if(set_active_all>=300)
				{
				 set_active_disp=0;                 // SETT ESNASSINDA LEDLER YANSIN 
				 set_active_all=0;				
				 ++set_active_a;
				}
			if((BUTTON_1==1)&&(BUTTON_2==0)&&(set_active_a==1)&&(set_active_b==0)) // VOLT A NIN ALT GER�L�M SINIRINI BEL�RLE
				{
				 set_active_disp=2;
				 ++set_active_a;
				 SETT_VOLT_A_L();
				}
			if((BUTTON_1==1)&&(BUTTON_2==0)&&(set_active_a==2)&&(set_active_b==0)) // VOLT A NIN �ST GER�L�M SINIRINI BEL�RLE
				{
				 set_active_disp=3;
				 set_active_a=0;
				 SETT_VOLT_A_H();
				 set_active_b=1;
				}
				
			if((BUTTON_2==1)&(BUTTON_1==0)&&(set_active_b==1)&&(set_active_a==0)) //  VOLT B N�N ALT GER�L�M SINIRINI BEL�RLE	 
				{
				 set_active_disp=4;
				 ++set_active_b;
				 SETT_VOLT_B_L();
				}
			if((BUTTON_2==1)&(BUTTON_1==0)&&(set_active_b==2)&&(set_active_a==0)) //  VOLT B N�N �ST GER�L�M SINIRINI BEL�RLE												 	
				{
				 set_active_disp=5;
				 set_active_b=0;
				 SETT_VOLT_B_H();
				}
			set_status=0; 		// AYAR MODU SONLANDI�INI B�LD�R	
			set_active_disp=0;	// 
			///////
		}



		if(REG_200ms>=11)              // 200 ms lik i�ler
		{
			REG_200ms=0;
		//	++REG_400ms;
		
			///////
			if(set_active_disp==1)
				 LED_NUM=(LED_NUM^0b10101010);
			else if(set_active_disp==2)
				 LED_NUM=(LED_NUM^0b10000000);
			else if(set_active_disp==3)
				 LED_NUM=(LED_NUM^0b00100000);
			else if(set_active_disp==4)
				 LED_NUM=(LED_NUM^0b00000010);
			else if(set_active_disp==5)
				 LED_NUM=(LED_NUM^0b0001000);
			else if(set_status==0)
				 output_low(LED_COM);

			///////
		
		}
	}
}