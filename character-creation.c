#include <stdio.h>

int main(void) {
    int classChoice, weaponChoice, focusChoice;
    int health = 0, strength = 0, intelligence = 0;

    printf("Choose your class:\n1. Warrior\n2. Mage\n3. Rogue\nEnter your choice: ");
    scanf("%d", &classChoice);

    if (classChoice == 1) {
        printf("You have chosen: Warrior. Strong fighters with great endurance.\n");
        printf("\nChoose your weapon:\n1. Sword\n2. Axe\nEnter your choice: ");
        scanf("%d", &weaponChoice);
        printf("\nEnter your focus:\n1. Attack\n2. Defense\nEnter your choice: ");
        scanf("%d", &focusChoice);
        if (focusChoice == 1) { health = 150; strength = 120; intelligence = 40; }
        else { health = 200; strength = 90; intelligence = 40; }
    } else if (classChoice == 2) {
        printf("You have chosen: Mage. Masters of the arcane, mages wield powerful spells.\n");
        printf("\nChoose your weapon:\n1. Staff\n2. Wand\nEnter your choice: ");
        scanf("%d", &weaponChoice);
        printf("\nEnter your focus:\n1. Attack\n2. Defense\nEnter your choice: ");
        scanf("%d", &focusChoice);
        if (focusChoice == 1) { health = 80; strength = 30; intelligence = 150; }
        else { health = 100; strength = 20; intelligence = 120; }
    } else {
        printf("You have chosen: Rogue. Silent and deadly masters of agility.\n");
        printf("\nChoose your weapon:\n1. Daggers\n2. Bow\nEnter your choice: ");
        scanf("%d", &weaponChoice);
        printf("\nEnter your focus:\n1. Attack\n2. Defense\nEnter your choice: ");
        scanf("%d", &focusChoice);
        if (focusChoice == 1) { health = 100; strength = 80; intelligence = 60; }
        else { health = 120; strength = 60; intelligence = 60; }
    }

    printf("\nCharacter Creation Complete!\nClass: ");
    if (classChoice == 1) printf("Warrior\n");
    else if (classChoice == 2) printf("Mage\n");
    else printf("Rogue\n");

    printf("Weapon: ");
    if (classChoice == 1) { if (weaponChoice == 1) printf("Sword\n"); else printf("Axe\n"); }
    else if (classChoice == 2) { if (weaponChoice == 1) printf("Staff\n"); else printf("Wand\n"); }
    else { if (weaponChoice == 1) printf("Daggers\n"); else printf("Bow\n"); }

    printf("Focus: ");
    if (focusChoice == 1) printf("Attack\n"); else printf("Defense\n");
    printf("Starting Attributes: Health: %d Strength: %d Intelligence: %d\n", health, strength, intelligence);
    return 0;
}
