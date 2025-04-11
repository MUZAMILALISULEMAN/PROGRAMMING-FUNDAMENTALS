#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SPECIES 10
#define MAX_NAME_LENGTH 50
#define MAX_SUPPLIES 10

typedef struct {
    char* name;
    char** supplies;
    int supplyCount;
} Species;

void addSpecies(Species* inventory, int* speciesCount);
void addSupply(Species* inventory, int speciesIndex);
void updateSupply(Species* inventory, int speciesIndex);
void removeSpecies(Species* inventory, int* speciesCount, int speciesIndex);
void displayInventory(Species* inventory, int speciesCount);
void freeInventory(Species* inventory, int speciesCount);

int main() {
    Species inventory[MAX_SPECIES];
    int speciesCount = 0;
    int choice;

    do {
    printf("\n--- Pets in Heart Inventory Management ---\n");
    printf("1. Add Species\n");
    printf("2. Add Supplies\n");
    printf("3. Update Supply\n");
    printf("4. Remove Species\n");
    printf("5. Display Inventory\n");
    printf("6. Exit\n");
        printf("Choose an option: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            fflush(stdin);
            continue;
        }
        fflush(stdin);

        int speciesIndex;
        switch (choice) {
            case 1:
                addSpecies(inventory, &speciesCount);
                break;
            case 2:
                printf("Select species index (0 to %d): ", speciesCount - 1);
                if (scanf("%d", &speciesIndex) != 1 || speciesIndex < 0 || speciesIndex >= speciesCount) {
                    printf("Invalid species index.\n");
                    while (getchar() != '\n'); 
                    break;
                }fflush(stdin);
				 addSupply(inventory, speciesIndex);
                break;
            case 3:
                printf("Select species index (0 to %d): ", speciesCount - 1);
                if (scanf("%d", &speciesIndex) != 1 || speciesIndex < 0 || speciesIndex >= speciesCount) {
                    printf("Invalid species index.\n");
                    while (getchar() != '\n');
                    break;
                }
                fflush(stdin);
                updateSupply(inventory, speciesIndex);
                break;
            case 4:
                printf("Select species index to remove (0 to %d): ", speciesCount - 1);
                if (scanf("%d", &speciesIndex) != 1 || speciesIndex < 0 || speciesIndex >= speciesCount) {
                    printf("Invalid species index.\n");
                    fflush(stdin);
                    break;
                }
                fflush(stdin);
                removeSpecies(inventory, &speciesCount, speciesIndex);
                break;
            case 5:
                displayInventory(inventory, speciesCount);
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while (choice != 6);

    freeInventory(inventory, speciesCount);
    return 0;
}

void addSpecies(Species* inventory, int* speciesCount) {
    if (*speciesCount >= MAX_SPECIES) {
        printf("Maximum species limit reached.\n");
        return;
    }
    inventory[*speciesCount].name = (char*)malloc(MAX_NAME_LENGTH * sizeof(char));
    if (inventory[*speciesCount].name == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    printf("Enter species name: ");
    fgets(inventory[*speciesCount].name, MAX_NAME_LENGTH, stdin);
    inventory[*speciesCount].name[strcspn(inventory[*speciesCount].name, "\n")] = 0; 
    inventory[*speciesCount].supplies = NULL; 
    inventory[*speciesCount].supplyCount = 0;
    (*speciesCount)++;
}

void addSupply(Species* inventory, int speciesIndex) {
    if (inventory[speciesIndex].supplyCount >= MAX_SUPPLIES) {
        printf("Maximum supplies limit reached for this species.\n");
        return;
    }
    inventory[speciesIndex].supplies = (char **)realloc(inventory[speciesIndex].supplies,
        (inventory[speciesIndex].supplyCount + 1) * sizeof(char*));
    if (inventory[speciesIndex].supplies == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    inventory[speciesIndex].supplies[inventory[speciesIndex].supplyCount] = (char*)malloc(MAX_NAME_LENGTH * sizeof(char));
    if (inventory[speciesIndex].supplies[inventory[speciesIndex].supplyCount] == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    printf("Enter supply name: ");
    fflush(stdin);
    fgets(inventory[speciesIndex].supplies[inventory[speciesIndex].supplyCount], MAX_NAME_LENGTH, stdin);
    inventory[speciesIndex].supplies[inventory[speciesIndex].supplyCount][strcspn(
        inventory[speciesIndex].supplies[inventory[speciesIndex].supplyCount], "\n")] = 0; 
    inventory[speciesIndex].supplyCount++;
}

void updateSupply(Species* inventory, int speciesIndex) {
    if (inventory[speciesIndex].supplyCount <= 0) {
        printf("No supplies available for this species.\n");
        return;
    }
    printf("Select supply index to update (0 to %d): ", inventory[speciesIndex].supplyCount - 1);
    int supplyIndex;
    if (scanf("%d", &supplyIndex) != 1 || supplyIndex < 0 || supplyIndex >= inventory[speciesIndex].supplyCount) {
        printf("Invalid supply index.\n");
        fflush(stdin);
        return;
    }
    fflush(stdin);
    printf("Enter new supply name: ");
    fgets(inventory[speciesIndex].supplies[supplyIndex], MAX_NAME_LENGTH, stdin);
    inventory[speciesIndex].supplies[supplyIndex][strcspn(inventory[speciesIndex].supplies[supplyIndex], "\n")] = 0; 
}

void removeSpecies(Species* inventory, int* speciesCount, int speciesIndex) {
    free(inventory[speciesIndex].name);
    for (int i = 0; i < inventory[speciesIndex].supplyCount; i++) {
        free(inventory[speciesIndex].supplies[i]);
    }
    free(inventory[speciesIndex].supplies);
    for (int i = speciesIndex; i < *speciesCount - 1; i++) {
        inventory[i] = inventory[i + 1];
    }
    (*speciesCount)--;
}

void displayInventory(Species* inventory, int speciesCount) {
    if (speciesCount == 0) {
        printf("No species in inventory.\n");
        return;
    }
    for (int i = 0; i < speciesCount; i++) {
        printf("Species %d: %s\n", i, inventory[i].name);
        if (inventory[i].supplyCount > 0) {
            printf("  Supplies:\n");
            for (int j = 0; j < inventory[i].supplyCount; j++) {
                printf("    - %s\n", inventory[i].supplies[j]);
            }
        } else {
            printf("  No supplies available.\n");
        }
    }
}

void freeInventory(Species* inventory, int speciesCount) {
    for (int i = 0; i < speciesCount; i++) {
        free(inventory[i].name);
        for (int j = 0; j < inventory[i].supplyCount; j++) {
            free(inventory[i].supplies[j]);
        }
        free(inventory[i].supplies);
    }
}
