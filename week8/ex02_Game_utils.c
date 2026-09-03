#include <stdio.h>

int clamp(int value, int min, int max)
float lerp(float a, float b, float t);
int randomRange(int min, int max);
float percentOf(int current, int total);

int main(void) {
    srand((unsigned int)time(NULL));

    int hp = 150;
    int safeHP = clamp(hp, 0, 100);
    printf("hp original = %d\n", hp);
    printf(" safeHP = %d\n", safeHP);

    float t = 0.5f;
    float pos = lerp(0, 100, t);
    printf("t in main = %.2f\n", t);
    printf("pos in main = %.2f\n", pos);

    int diceMin = 1;
    for (int i = 0; i < 5; i++) {
        printf("Dice roll %d: %d\n", i + 1, randomRange(diceMin, 6));
    }
    printf("diceMin original = %d\n", diceMin);

    int score = 35 , total = 100;
    float percentage = percentOf(score, total);
    printf("scpore / total = %d/%d\n", score, total);
    printf("percentage = %.1f%%\n", percentage);
    
    return 0;

    }
    
