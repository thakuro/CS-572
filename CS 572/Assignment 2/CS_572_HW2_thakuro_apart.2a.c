#include <stdio.h>
#include <math.h>
#include <stdlib.h>


#define E_MASK 0x7FF0000000000000
#define E_SHIFT 52
#define M_MASK 0X007FFFFF
#define M_SHIFT 0
#define S_MASK 0X80000000
#define S_SHIFT 63

float yes;
unsigned int exponent,val,sign;
double mantissa;
int e;
int i;
double x, result;



int main(int argc, char *argv[])
{
        yes = -11.4f;

        val = *((unsigned long int *)&yes); 
                           
       mantissa = ( val & M_MASK);                               //Mantissa mask is loaded
     
       val = val >> E_SHIFT;
                                                                 //Exp shift is loaded
       exponent = ( val  & E_MASK);
                                                                   // Exp mask is loaded
       val = val >> S_SHIFT;  
                                                                   // Sign shift is loaded
       sign = ( val & S_MASK);                                      // sign mask is loaded

	

        
	
	int i = 0, e;

	x = 55;		
	

	result = frexp(x, &e);

	
	
	
	if(x < 0.5 && x > 0){
		while(x < 0.5){
			x = x * 2;
			i = i - 1;
		}


		printf("Your mantissa is %lf \n and exponent is %d\n", x ,i);
		

	} else if(x < 0){
		x = abs(x);
		while(x >= 1){
			x = x / 2;
			i = i - 1;
		}


		printf("Your mantissa is %lf \n and exponent is %d\n", x ,i);
		
	} else if(x >= 1){
		while(x >= 1){
			x = x / 2;
			i = i + 1;
		}


		printf("Your mantissa is %lf and exponent is %d\n", x ,i);
		
	
                } else if(x >= 0.5 || x < 1){
		printf("Your mantissa is %lf and exponent is %d\n", x ,i);
		
	}

	return 0;
}                                                                                     //end of program

