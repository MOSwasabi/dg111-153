#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int number, guess, attempts = 0;
    srand(time(NULL));
    number = rand() % 100 + 1; 

    printf("เลือกเลข1-100 ):\n");

    do {
        printf("ไส่เลข: ");
        scanf("%d", &guess);
        attempts++;

        if (guess < number) {
            printf("ต่ำไปลองใหม่.\n");
        } else if (guess > number) {
            printf("สูงไปลองใหม่.\n");
        } else {
            printf("ยินดีด้วย คุณถา
                ยเลข %d ได้ใน %d ครั้ง.\n", number, attempts);
        }
    } while (guess != number);

    return 0;
}