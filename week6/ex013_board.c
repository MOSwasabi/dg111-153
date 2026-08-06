#include <stdio.h>
int main() {
    int rows = 3;
    int cols = 5;
    int count = 1;
    for (int i = 1; i <= rows; i++) {
        printf("+---+---+---+---+---+\n");
        printf("|");
        for (int j = 1; j <= cols; j++) {
            printf("%d |", count);
            count++;
        }
        printf("\n");
        }
         printf("+---+---+---+---+---+\n");
    }