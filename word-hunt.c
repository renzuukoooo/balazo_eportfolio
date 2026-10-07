#include <stdio.h>

void displayGrid(char grid[5][5], int x, int y) {
    printf("\nGrid:\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (i == x && j == y)
                printf("[%c] ", grid[i][j]); // Show player position
            else
                printf(" %c  ", grid[i][j]);
        }
        printf("\n");
    }
}

int main() {
    char originalGrid[5][5] = {
        {'e', 'd', 'c', 'b', 'a'},
        {'1', '2', '3', '4', '5'},
        {'f', 'g', 'h', 'i', 'j'},
        {'0', '9', '8', '7', '6'},
        {'p', 'o', 'n', 'm', 'p'}
    };

    char playAgain;

    do {
        char grid[5][5];
        // Copy original grid to reset for each game
        for (int i = 0; i < 5; i++)
            for (int j = 0; j < 5; j++)
                grid[i][j] = originalGrid[i][j];

        int lives = 3;
        int x = 0, y = 0; // Start position
        char move;
        char targetChar;
        int found = 0;

        printf("\nWelcome to Word Hunt Navigation!\n");
        displayGrid(grid, x, y);

        printf("\nChoose a character to hunt: "); 
        scanf(" %c", &targetChar);

        printf("\nUse 8=up, 2=down, 4=left, 6=right, s=stop\n");

        while (lives > 0 && !found) {
            displayGrid(grid, x, y);
            printf("\nLives: %d | Current: (%d,%d) - %c\n", lives, x, y, grid[x][y]);
            printf("Enter move: ");
            scanf(" %c", &move);

            if (move == 's') {
                break;
            }

            int newX = x, newY = y;

            if (move == '8') newX--;
            else if (move == '2') newX++;
            else if (move == '4') newY--;
            else if (move == '6') newY++;
            else {
                printf("Cause 3: Invalid Input! Use 8,2,4,6,s only.\n");
                lives--;
                continue;
            }

            if (newX == x && newY == y) {
                printf("Cause 2: Same Place! You didn’t move.\n");
                lives--;
                continue;
            }

            if (newX >= 0 && newX < 5 && newY >= 0 && newY < 5) {
                // Replace the current position with '0' before moving
                grid[x][y] = '0';

                x = newX;
                y = newY;

                if (grid[x][y] == targetChar) {
                    printf("You found the character '%c'!\n", targetChar);
                    found = 1;
                    grid[x][y] = '0'; // Replace the found target as well
                }
            } else {
                printf("Cause 1: Out of Boundary! Can't move there.\n");
                lives--;
            }
        }

        if (found) {
            printf("\nCongratulations! You won the game!\n");
        } else {
            printf("\nGame Over! You're out of lives or stopped.\n");
        }

        printf("\nDo you want to play again? (y/n): ");
        scanf(" %c", &playAgain);

    } while (playAgain == 'y' || playAgain == 'Y');

    printf("\nThank you for playing Word Hunt Navigation!\n");
    return 0;
}