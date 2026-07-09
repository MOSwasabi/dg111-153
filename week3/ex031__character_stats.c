#include <stdio.h>
int main() 
{
int Defense;  
int Level ;
int AttackPower;
int MaxHP;
char name[1000] ="";
char FavoriteSubject[1000] ="";
printf("===  Create Character ===\n");
printf("Character Name: ");
scanf("%s", name);
printf("Character Level: ");
scanf("%d", &Level);
printf("Character Attack Power: ");
scanf("%d", &AttackPower);
printf("Character Defense: ");
scanf("%d", &Defense);
printf("Character Max HP: ");
scanf("%d", &MaxHP);
printf("\n=== Character Summary ===\n");
printf(" Name: %s \n", name);
printf(" Level: %d \n", Level);
printf(" HP: %d \n", MaxHP);
printf(" Attack Power: %d \n", AttackPower);
printf(" Defense: %d \n", Defense);

return 0;
}
