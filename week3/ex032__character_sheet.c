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
printf("╔══════════════════════════════╗\n");
printf("║Name: %-24s║\n", name);
printf("╠══════════════════════════════╣\n");
printf("║Level: %-23d║\n", Level);
printf("║Attack Power: %-16d║\n", AttackPower);
printf("║Defense: %-21d║\n", Defense);
printf("╠══════════════════════════════╣\n");
printf("║HP BAR:[████████] %-12d║\n", MaxHP);
printf("║Power Score: %-17d║\n", AttackPower * 2 + Defense + MaxHP / 10);
printf("╚══════════════════════════════╝\n");
return 0;
}
