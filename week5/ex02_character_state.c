#include <stdio.h>
    int main() {
        int max_hp;
    int damage;
    int poisoned_input;
    _Bool is_poisoned;
    int attack_count;
    int hp;

    /* รับข้อมูลทีละตัว */
    printf("Max HP: ");
    scanf("%d", &max_hp);

    printf("Damage Taken: ");
    scanf("%d", &damage);

    printf("Poisoned (0/1): ");
    scanf("%d", &poisoned_input);
    is_poisoned = poisoned_input;

    printf("Attack Count: ");
    scanf("%d", &attack_count);

    /* คำนวณ HP */
    hp = max_hp - damage;
    if (hp < 0)
        hp = 0;

    /* แสดงผล */
    printf("=== Character Status ===\n");

    /* ตัดสินสถานะตามลำดับความสำคัญ */
    if (hp == 0)
    {
        printf("State: DEAD\n");
    }
    else if (hp <= max_hp / 4)
    {
        printf("State: CRITICAL\n");
    }
    else if (is_poisoned)
    {
        printf("State: POISONED\n");
    }
    else
    {
        printf("State: NORMAL\n");
    }

    /* Ultimate Ready */
    if (attack_count > 0 && attack_count % 5 == 0)
    {
        printf("Ultimate Ready!\n");
    }

    return 0;
    }
 