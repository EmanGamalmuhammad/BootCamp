/*
 * test.c
 *
 * Created: 2/23/2019 5:07:43 PM
 *  Author: AVE-LABS-50
 */ 

#if 0
	DIO_SetPinDirection(PushButt1 ,INPUT);
	DIO_WritePin(PushButt1 ,HIGH);
	
	DIO_SetPinDirection(LED1 ,OUTPUT);
	DIO_SetPinDirection(LED2 ,OUTPUT);
	DIO_SetPinDirection(LED3 ,OUTPUT);
	
	Timer0_CTC_Init();
	EXTI2_INIT();
	Timer1_PWM_Phase_Correct_Init();
	//Timer1_Fast_PWM_Init();
	Duty_Cycle(30);
	Timer_Delay(2000);
	Duty_Cycle(90);
	uint8 i;
	extern uint16 counter;
	extern uint8 Flag;
	
	while (1)
	{
		DIO_WritePin(LED1 ,HIGH);
		for (i=NUM_0 ;i<NUM_20 ;i++)
		{
			/* timer_delay(50); */
			while((counter < NUM_50));
			counter = NUM_0 ;
			while(Flag == NUM_1)
			{
				Flag = NUM_0;
				DIO_WritePin(LED2 ,LOW);
				DIO_WritePin(LED1 ,LOW);
				DIO_WritePin(LED3 ,HIGH);
				while((counter < NUM_1000));
				counter = NUM_0;
				DIO_WritePin(LED3 ,LOW);
				
			}
		}
		
		DIO_WritePin(LED1 ,LOW);
		DIO_WritePin(LED3 ,HIGH);
		for (i=NUM_0 ;i<NUM_20 ;i++)
		{
			/* timer_delay(50); */
			while((counter < NUM_50));
			counter = NUM_0 ;
			while(Flag == NUM_1)
			{
				Flag = NUM_0 ;
				DIO_WritePin(LED2 ,LOW);
				DIO_WritePin(LED1,LOW);
				DIO_WritePin(LED3 ,HIGH);
				/* timer_delay(1000); */
				while((counter < NUM_1000));
				counter = NUM_0;
				DIO_WritePin(LED3 ,LOW);
				
			}
		}
		DIO_WritePin(LED3 ,LOW);
		DIO_WritePin(LED2 ,HIGH);
		for (i=NUM_0 ;i<NUM_20 ;i++)
		{
			/* timer_delay(50); */
			while((counter < NUM_50));
			counter= NUM_0;
			while(Flag == NUM_1)
			{
				Flag = NUM_0 ;
				DIO_WritePin(LED2 ,LOW);
				DIO_WritePin(LED1 ,LOW);
				DIO_WritePin(LED3 ,HIGH);
				/* timer_delay(1000); */
				while((counter < NUM_1000));
				counter = NUM_0 ;
				DIO_WritePin(LED3 ,LOW);
				
			}
		}
		DIO_WritePin(LED2 ,LOW);
		
		

	}
	#endif