#include <stdio.h>
int main() {
 int i = 1;
do {
      printf("\n%d", i);
      i++;
   } while (i <= 10);
  
     
 for (int i = 1; i <= 10; i++) {
      printf("\n%d", i);
   } 
while (i <= 10) {
      printf("\n%d", i);
      i++;
   }
  
 int sum = 0;
 for (int i = 1; i <= 10; i++) {
      sum += i;
   }
   printf("\nSum: %d", sum);
   return 0;
}

