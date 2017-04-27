#include <stdio.h>
#include <math.h>

int main()
{
int a, b, c;
unsigned int tick1, tick2;
unsigned g,d;
double time_diff;
int e;




a = 0;
b = 0;
float m,n;
float num;
n=0.0001;
double fraction;
int e;
num = 7;


asm volatile("rdtsc" : "=a" (g), "=d" (d));  //assembly code running the instruction                        
                                                                  //rdtsc

tick1 = (((unsigned int)c) | (((unsigned int)d) << 32)); // calculating the tick value.

printf("time %llu",tick1);
for(m=0;m<num;m=m+n)
{
if((m*m)>num)
{
m=m-n;
break;
}
}
printf("%.2f",m);

asm volatile("rdtsc" : "=a" (c), "=d" (d));  //assembly code running the instruction                        
                                                                  //rdtsc

tick2 = (((unsigned int)c) | (((unsigned int)d) << 32)); // calculating the tick value.

printf("time 2 %llu",tick2);

time_diff = difftime(tick1, tick2);
printf("time difference%d\n",time_diff);


for(a=0;a<1000000;a++) // for loop for simple addition

{
b=10;
b = a + b;
printf("%d\n",a);
}

asm volatile("rdtsc" : "=a" (c), "=d" (d));  //assembly code running the instruction                        
                                                                  //rdtsc

tick1 = (((unsigned int)c) | (((unsigned int)d) << 32)); // calculating the tick value.

printf("time %llu",tick1);

time_diff = difftime(tick1, tick2);
printf("time difference%d\n",time_diff);
for(a=0;a<2000000;a++)    // for loop for simple substraction

{

b = 5;
b--;
c = a - b;
printf("The substraction is%d\n",c);
}

asm volatile("rdtsc" : "=a" (c), "=d" (d));  //assembly code running the instruction                        
                                                                  //rdtsc

tick1 = (((unsigned int)c) | (((unsigned int)d) << 32)); // calculating the tick value.

printf("time %llu",tick2);
time_diff = difftime(tick1, tick2);
printf("time difference%d\n",time_diff);

for(a=0;a<3000000;a++)     // for loop for division

{

b = 10;
b++;
c = a/b;
printf("The division is%d\n",c);
}
asm volatile("rdtsc" : "=a" (c), "=d" (d));  //assembly code running the instruction                        
                                                                  //rdtsc

tick1 = (((unsigned int)c) | (((unsigned int)d) << 32)); // calculating the tick value.

printf("time %llu",tick1);

time_diff = difftime(tick1, tick2);
printf("time difference%d\n",time_diff);
for(a=0;a<4000000;a++)      // for loop for multiplication

{
b =10 ;
b++;
c = a*b;
printf("The multiplication is %d\n",c);
printf("%.2f\n",m);
}
asm volatile("rdtsc" : "=a" (c), "=d" (d));  //assembly code running the instruction                        
                                                                  //rdtsc

tick1 = (((unsigned int)c) | (((unsigned int)d) << 32)); // calculating the tick value.

printf("time %llu",tick2);
time_diff = difftime(tick1, tick2);
printf("time difference%d\n",time_diff);
for(a=0;a<12;a++)      // for loop for addition

{
for(a=0;a<1000000;a++)
{  
   fraction = frexp(a, &e);
   c = fraction + 2.8;
   printf("x = %lf = %.2lf * 2^%d\n", a, fraction, e);
   printf("The FP addition is %lf",c);
   
   
}

asm volatile("rdtsc" : "=a" (c), "=d" (d));  //assembly code running the instruction                        
                                                                  //rdtsc

tick1 = (((unsigned int)c) | (((unsigned int)d) << 32)); // calculating the tick value.

printf("time %llu",tick1);
time_diff = difftime(tick1, tick2);
printf("time difference%d\n",time_diff);
}

for(a=0;a<2000000;a++)                            // floating point substraction
{  
   fraction = frexp(a, &e);
   c = fraction - 2.9;
   printf("x = %lf = %d * 2^%d\n", a, fraction, e);
   printf("The FP substraction  is %lf",c);
   
   
}
asm volatile("rdtsc" : "=a" (c), "=d" (d));  //assembly code running the instruction                        
                                                                  //rdtsc

tick1 = (((unsigned int)c) | (((unsigned int)d) << 32)); // calculating the tick value.

printf("time %llu",tick2);
time_diff = difftime(tick1, tick2);
printf("time difference%d\n",time_diff);

for(a=0;a<3000000;a++)                                // floating point division
{  
   fraction = frexp(a, &e);
   c = fraction / 3.7;
   printf("x = %lf = %d * 2^%d\n", a, fraction, e);
   printf("The FP division  is %lf",c);
   
   
}
asm volatile("rdtsc" : "=a" (c), "=d" (d));  //assembly code running the instruction                        
                                                                  //rdtsc

tick1 = (((unsigned int)c) | (((unsigned int)d) << 32)); // calculating the tick value.

printf("time %llu",tick2);
time_diff = difftime(tick1, tick2);
printf("time difference%d\n",time_diff);

for(a=0;a<4000000;a++)                           //floating point multiplication
{  
   fraction = frexp(a, &e);
   c = fraction * 3.3;
   printf("x = %lf = %d * 2^%d\n", a, fraction, e);
   printf("The FP multiplication  is %lf",c);
   
   
}
asm volatile("rdtsc" : "=a" (c), "=d" (d));  //assembly code running the instruction                        
                                                                  //rdtsc

tick1 = (((unsigned int)c) | (((unsigned int)d) << 32)); // calculating the tick value.

printf("time %llu",tick2);
time_diff = difftime(tick1, tick2);
printf("time difference%d\n",time_diff);






}






