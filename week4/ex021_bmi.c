#include <stdio.h>
int main()
{
int kg;
int cm;
printf("Enter your weight (kg): "); 
scanf("%d", &kg);
printf("Enter your height (cm): ");
scanf("%d", &cm);
    float height_m = cm / 100.0;
    float bmi = kg / (height_m * height_m);
    if (bmi < 18.5) {
        printf("Your BMI is %.2f, --> Underweight\n", bmi);
    } else if (bmi >= 18.5 && bmi < 24.9) {
        printf("Your BMI is %.2f, --> Normal weight\n", bmi);
    } else if (bmi >= 25 && bmi < 29.9) {
        printf("Your BMI is %.2f, --> Overweight\n", bmi);
    } else {
        printf("Your BMI is %.2f, --> Obese\n", bmi);
    }
return 0;

}