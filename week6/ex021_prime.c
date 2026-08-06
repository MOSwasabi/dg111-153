#include <stdio.h>

int main() {
    int n, isPrime = 1, divisor = 0;

    printf("ไส่เลข: ");
    scanf("%d", &n);

    if (n <= 1) {
        printf("%d ไม่ใช่เลขเฉพาะ\n", n);
        return 0;
    }

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            isPrime = 0;
            divisor = i;
            break;
        }
    }

    if (isPrime) {
        printf("%d เป็นเลขเฉพาะ\n", n);
    } else {
        printf("%d ไม่ใช่เลขเฉพาะ (หารด้วย %d)\n", n, divisor);
    }

    return 0;
}