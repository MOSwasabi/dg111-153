#include <stdio.h>
int main() 
{
    int score;
    printf("Enter your score: ");
    scanf("%d", &score);

    if (score >= 80) {
    printf("Grade: A (4.0) --> passed\n");
    } else if (score >= 75){
    printf("Grade: B+ (3.5) --> passed\n"); 
    }else if (score >= 70){
        printf("Grade: B (3.0) --> passed\n");
    } else if (score >= 65){
        printf("Grade: C+ (2.5) --> failed\n");
    } else if (score >=60){
        printf("Grade: C (2.0) --> failed\n");
    } else if (score >= 55){10
        printf("Grade: D+ (1.5) --> failed\n");
    } else if (score >= 50){
        printf("Grade: D (1.0) --> failed\n");
    }else if (score >= 49){
        printf("Grade: F (0.0) --> failed\n");
    } 
    return 0;
}