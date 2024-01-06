/***************************************************/
/* Auther : Mohamed Samir                          */
/* Date   : 29 MAR 2023                            */
/* Verion : 01v                                    */
/***************************************************/
#include "Calculator_interface.h"


/*************************************************************************************************************************
*                                                                                                                        *
* n,z,s,d,i,k ===> Counters                                                                                              *
*                                                                                                                        *
* Pstate       ===> state of the (multiplying or dividing operation)                                                     *
* Sstate       ===> state of the (plus or minus operation)																 *
* Preset	   ===> reset P_fun counters                                                                                 *
* state	       ===> state of the (equal operation)                                                                       *
* 	                                                                                                                     *
* Pop          ===> point to how many times entered the P_fun                                                            *
* Sop          ===> point to how many times entered the S_fun                                                            *
*		                                                                                                                 *
* sign	       ===> if sign=1 the next number in (arr) become negative                                                   *
* 		                                                                                                                 *
* KPD_enter    ===> the key that entered by the user                                                                     *
* enteranceArr ===> the array that holding the entered numbers                                                           *
* keyPressed   ===> the numbers and oprations that displayed on first line at LCD after (equal) key pressed              *
*                                                                                                                        *
* cleanSc	   ===> if cleanSc=1 then the (equal) key pressed and waiting to erasing the screen after click on (C) key   *
*                                                                                                                        *
* x            ===> storing the integer number after converting it from ASCII                                             *
* arr      	   ===> storing the integer number after gathering the comblete number 	                                     *
*                                                                                                                        *
* opArr        ===> operation array holds the numbers that requiered to apply an operation on them                       *
*                                                                                                                        *
* sumArr       ===> sum array holds the result of suming or minus operation (result of S_fun)                            *
* MdArr        ===> Multiplying or Dividing array holds the result of the operation (result of P_fun)                    *
*                                                                                                                        *
*************************************************************************************************************************/
s8 n,z,s,d,Pstate,Pop,Sop,Sstate,state,sign,Preset ;
u8 keyPressed , cleanSc ;
u8 KPD_enter , enteranceArr[16],i=0,k;
f32 x ,arr[16] ,opArr[16] ,sumArr[16] ,MdArr[16];

// gathering the complete number
void NUM (void)
{
    n++ ;
    arr[n] = arr[n-1]*10 + x ;
	
	// to make the negative number  
    if (sign==1){arr[n]=arr[n]*(-1); sign=0;}

}

// Multiplying or Dividing operation function
void P_fun (Lcd_info* lcd)
{
    Pop ++ ;
    d++;
	// MdArr holding first and second number
    MdArr[d] = opArr[z] ;
	// doing the operation on two numbers
    if (Pop==2)
    {

        switch(Pstate)
        {
			// dividing operation	
			case 1 :
				// Exception for infinity loop (dividing by zero)
				if (MdArr[2]==0)
				{
					LCD_VoidGoToXY(1,0,lcd);
					LCD_VoidSendString("Math ERROR",lcd);
					i=17;
				}
				else
				// dividing operation	
				{
					MdArr[1]=MdArr[1] / MdArr[2] ;
				}
				break ;
				
			// multiplying operation	
			case 2 :
				MdArr[1]=MdArr[1] * MdArr[2] ;
				break ;
		}

        Pop = 1;
        d = 1;
        Pstate=0;
		
		// Exception to reset P_fun counters 
        if (Preset==1 ){ d=0; Pop=0; Preset=0; }
		// Exception to tell the S_fun to start calculating the all number pervious the equal operator
        if (state==1){Pstate=5;}

    }
}

// Summing or minus operation function
void S_fun (Lcd_info* lcd)
{
	Preset =1 ;
    Sop++;
    s++ ;
	// sumArr holding first and second number
    sumArr[s] = opArr[z] ;
	// if there is any previous multiplication or division operation have to be done first
    if (Pstate==1 || Pstate==2)
    {
        P_fun(lcd);
        sumArr[s] = MdArr[1];
    }
    if (Pstate==5 && state==1)
    {
        sumArr[s] = MdArr[1];
    }
	// doing the operation on two numbers
    if (Sop==2)
    {

        switch (Sstate)
        {
			// Summing operation
            case 1 : 
                sumArr[1]=sumArr[1] + sumArr[2] ;
                break ;
			// minus operation 	
            case 2 :
                sumArr[1]=sumArr[1] - sumArr[2] ;
                break ;
        }
        Sop=1;
        s=1;
        Pop=0;
        d=0;

    }

}

// Displaying the final result
void Equal_fun (Lcd_info* lcd)
{

	cleanSc = 1 ;

    if (Pstate==1 || Pstate==2 )
    {
        P_fun (lcd);
		// Exception for infinity loop (dividing by zero)
        if(i==17){}
        else
		// printing the result
        {
			LCD_VoidGoToXY (1,0,lcd);
			LCD_VoidSendFloat(MdArr[1],lcd);
        }

    }
    if (Sstate==1 || Sstate==2 )
    {
        S_fun (lcd);
		// Exception for infinity loop (dividing by zero)
        if(i==17){}
		else
		// printing the result
		{
			LCD_VoidGoToXY (1,0,lcd);
			LCD_VoidSendFloat(sumArr[1],lcd);
		}
    }

}

// Receiving the operations
void operat (Lcd_info* lcd)
{
    z++;
    opArr[z]=arr[n];
    n++;
    arr[n]=0 ;

    switch (keyPressed)
    {

        case '/':

            P_fun (lcd);
            Pstate=1;
            break;
        case '*':

            P_fun (lcd);
            Pstate=2;
            break;
        case '+':

            S_fun (lcd);
            Sstate=1;
            break;
        case '-':

            S_fun (lcd);
            Sstate=2;
            break;
        case '=':
            state=1;

            Equal_fun (lcd);
            break;

    }
}

// resting all variables
void reset(void)
{
	arr[0]=0; x=0;
	n=0; z=0; s=0; d=0; opArr[0]=0;
	Pop=0; Sop=0; sumArr[0]=0; MdArr[0]=0;
	Sstate=0;state=0;Pstate=0; i=0;

}




//*****************************************************************************************************
// the main function receives and displays the key pressed
void CalculatorMode (Lcd_info* lcd)
{
	KPD_enter = KPD_u8GetPressedKey();
	if(KPD_enter != 0xff)
	{
		// exception for erasing the screen after click on (C) key
		if ( (KPD_enter == 'C') && (cleanSc == 1) )
		{
			cleanSc =0;
			LCD_VoidSendCommand(LCD_ClearDisplay,lcd);
			
		}



		if (KPD_enter != 'C')
		{
			// exception for entering two operations next to each other
			if ( ((KPD_enter == '/') || (KPD_enter == '*')|| (KPD_enter == '+')|| (KPD_enter == '-')) && ((enteranceArr[i-1] == '/') || (enteranceArr[i-1] == '*')|| (enteranceArr[i-1] == '+')|| (enteranceArr[i-1] == '-')) )
			{
				i--;
			}
			// storing and displaying the entered key
			LCD_VoidGoToXY(0,i,lcd);
			LCD_VoidSendChar(KPD_enter,lcd);
			enteranceArr[i++] = KPD_enter ;
		}
		
		// clearing the previous cell
		if (KPD_enter == 'C')
		{
			if(i != 0)
			{
				i--;
				LCD_VoidGoToXY(0,i,lcd);
				LCD_VoidSendChar(CLR_Cell,lcd);
			}

		}
//*****************************************************************************************************		
		/*if (KPD_enter == '=') // Test enteranceArr <<used for Debuging>>
		{
			k = i ;
			LCD_voidPos (1,0);
			for(i=0 ; i <= k ; i++)
			{

				LCD_voidSendData   (enteranceArr[i]);
			}
		}*/

	}
	
	// Calculating the result and reading the entire line of entered number and operations
	if (KPD_enter == '=')
	{
		k = i ;
		LCD_VoidGoToXY(1,0,lcd);
		for(i=0 ; i <= k ; i++)
		{
			keyPressed = enteranceArr[i];
			
			// making exception for negative number
			if ( (n==0) && (keyPressed== '-') ) {sign = 1; }
			
			// determining either operation or number  
			else if ((keyPressed == '/') || (keyPressed == '*')|| (keyPressed == '+')|| (keyPressed == '-')|| (keyPressed == '='))
			{

				operat (lcd);
			}
			else
			{
				x=keyPressed - 48 ;

				NUM () ;
			}

		}
		reset();
	}
}



	
	





