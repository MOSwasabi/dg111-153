#include <stdio.h>
int main() 
{
int age;
float gpa;
char name[1000] ="";
char FavoriteSubject[1000] ="";
printf("=== Enter Data ===\n");
printf("Enter your name: ");
scanf("%s", name);
printf("Enter your age: ");
scanf("%d", &age);
printf("Enter your gpa: "); 
scanf("%f", &gpa);
printf("Enter your favorite subject: ");
scanf("%s", FavoriteSubject);
printf("=== Personal Info ===\n");
printf("Name: %s\n", name);
printf("Age: %d years old\n", age);
printf("GPA: %.2f\n", gpa);
printf("Favorite Subject: %s\n", FavoriteSubject);
return 0;
}
