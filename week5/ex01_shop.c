#include <stdio.h>

int main() {
    int gold = 1000;
    int choice;
    int total = 0;

    while (1) {
        printf("\n===== ITEM SHOP =====\n");
        printf("Gold: %d\n", gold);
        printf("1. Health Potion - 50 Gold\n");
        printf("2. Mana Potion - 80 Gold\n");
        printf("3. Iron Sword - 500 Gold\n");
        printf("4. Leather Armor - 300 Gold\n");
        printf("5. ไม่ซื้อแล้วออก\n");
        printf("6. ชำระเงิน\n");

        printf("เลือกสินค้า: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                total += 50;
                printf("เพิ่ม Health Potion\n");
                break;

            case 2:
                total += 80;
                printf("เพิ่ม Mana Potion\n");
                break;

            case 3:
                total += 500;
                printf("เพิ่ม Iron Sword\n");
                break;

            case 4:
                total += 300;
                printf("เพิ่ม Leather Armor\n");
                break;

            case 5:
                printf("ยกเลิกการซื้อ\n");
                printf("Gold คงเหลือ: %d\n", gold);
                return 0;

            case 6:
                printf("\nราคารวม = %d Gold\n", total);

                if (total == 0) {
                    printf("คุณยังไม่ได้เลือกสินค้า\n");
                }
                else if (gold >= total) {
                    gold -= total;
                    printf("Purchase successful!\n");
                    printf("Gold คงเหลือ: %d\n", gold);
                }
                else {
                    printf("Gold ไม่พอ!\n");
                }
                return 0;

            default:
                printf("กรุณาเลือก 1-6 เท่านั้น\n");
        }
    }

    return 0;
}