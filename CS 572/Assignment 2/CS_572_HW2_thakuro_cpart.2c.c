#include<stdio.h>
#include<float.h>
#include<math.h>
#include<stdlib.h>

int pi=3.14;
int m = 9;
double fraction;
int e;

union blob
{
double df;
long l;
char c[8];
int i[2];
float ff[2];
} ;

int main(int argc, char **argv)
{ 
union blob b;
b.df = m-pi;

fraction = frexp(b.df, &e);

printf("frexp%d",fraction);
printf("For double = %.2lf = %.2lf * 2^%d\n", b.df, fraction, e);
fraction = frexp(b.l, &e);
printf("For long = %.2lf = %.2lf * 2^%d\n", b.l, fraction, e);

printf("double is %lf\n ",b.df);
printf("long is %ld\n ",b.l);
printf("char is %ls\n",b.c);
printf("int is %ld\n",b.i[0]);
printf("int is %ld\n",b.i[1]);
printf("float is %9.6f\n",b.ff[0]);
printf("float is %9.6f\n",b.ff[1]);
}
