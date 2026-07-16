#include <stdio.h>
int main()
{
int a = 10 / 3; 
printf("a = %f\n", (float)a);
float b = 10.0 / 3;
printf("b = %f\n", b); 
float c = 10.0 / 3;
printf("c = %f\n", c);
int d = 10 % 3; 
printf("d = %f\n", (float)d);
int e = -7 % 3;
printf("e = %f\n", (float)e);
int f = 7 % -3;
printf("f = %f\n", (float)f);

int x = 5;
printf("x++ = %d\n", x++);
printf("x = %d\n", x);
x = 5;
printf("++x = %d\n", ++x);
printf("x = %d\n", x);

printf("2 + 3 * 4 = %d\n", 2 + 3 * 4);
printf("(2 + 3) * 4 = %d\n", (2 + 3) * 4);
printf("10 - 2 - 3 = %d\n", 10 - 2 - 3);
printf("2*3 + 4*5 = %d\n", 2 * 3 + 4 * 5);
return 0;


}