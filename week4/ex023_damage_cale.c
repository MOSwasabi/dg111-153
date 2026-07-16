#include <stdio.h>
#include <math.h>
int main()
{
    int player_attack;
    int enemy_defense;
    int Defense;
    int HitNumber;
    printf("=== Damage Calculator ===\n");
    printf("Enter player attack value: ");
    scanf("%d", &player_attack);
    printf("Enter player defense value: ");
    scanf("%d", &Defense);
    printf("Enter enemy defense value: ");
    scanf("%d", &enemy_defense);
    printf("Enter hit number: ");
    scanf("%d", &HitNumber);

    int base_damage = player_attack - Defense;
    int critical_hit=HitNumber % 5 == 0;
    int critical_damage = (int)ceil((float)base_damage * 1.5f);
   
   
    if (critical_hit) {
        printf("Critical Hit! Damage: %d\n", critical_damage);
    } else {
        printf("Normal Hit! Damage: %d\n", base_damage);
    }
    return 0;
}
