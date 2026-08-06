#include <stdio.h>
int main() {
  printf("Pattern 1:\n");
  for (int row = 1; row <= 4; row++) {
  for (int col = 1; col <= row; col++) {
    printf("*");
}
printf("\n");

}
  printf("Pattern 2:\n");
for (int row = 1; row <= 4; row++) {
  for (int col = 1; col <= 4; col++) {
    printf("*");
}
printf("\n");
}
  printf("Pattern 3:\n");
 int n = 3;
 for (int row = 1; row <= n; row++) {
    
        for (int space = 1; space <= n - row; space++) {
            printf(" ");
        }
        
        for (int col = 1; col <= (2 * row - 1); col++) {
            printf("*");
        }
        printf("\n");
    }
    for (int row = n - 1; row >= 1; row--) {
        
        for (int space = 1; space <= n - row; space++) {
            printf(" ");
        }
        
        for (int col = 1; col <= (2 * row - 1); col++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
  }