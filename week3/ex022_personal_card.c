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
printf("\n=== PERSONAL CARD ===\n");
printf("┌─────────────────────────┐\n");
printf("│ Name: %-18s│\n", name);
printf("│ Age : %-8d years old│\n", age);
printf("│ GPA : %-18.2f│\n", gpa);
printf("│ Favorite Subject: %-6s│\n", FavoriteSubject);
printf("└─────────────────────────┘\n");
return 0;
}
