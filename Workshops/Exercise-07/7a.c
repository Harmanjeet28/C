#define _CRT_SECURE_NO_WARNINGS

// Path Size
#define maxPathSize 70
#define minPathSize 10
#define multiplier 5

// Move Size
#define maxMoveSize 26
#define minMoveSize 3

#include <stdio.h>

struct playerInfo {     //Structure for Player Config
    char playerSymbol;
    int playerLives;
    int playerTreasure;
    int playerHistory;
};

struct gameConfig {
    int pathSize;
    int pathMoves;
    int bombPlacement[maxPathSize];
    int treasurePlacement[maxPathSize];
};


int main(void)
{
    int flag, i;

    printf("================================\n");
    printf("         Treasure Hunt!\n");
    printf("================================\n\n");

    printf("PLAYER Configuration\n"); //Player Config
    printf("--------------------\n");

    struct playerInfo player1;

    printf("Enter a single character to represent the player: ");
    scanf("%c", &player1.playerSymbol);

    flag = 0;
    while ((player1.playerLives <= 0) || (player1.playerLives > 10))
    {
        printf("Set the number of lives: ");
        scanf("%d", &player1.playerLives);

        if ((player1.playerLives <= 0) || (player1.playerLives > 10))
        {
            printf("     Must be between 1 and 10!\n");
        }

    }
    
    printf("Player configuration set-up is complete\n\n"); //Player Config Complete

    struct gameConfig gameSettings;

    printf("GAME Configuration\n"); //Game Config
    printf("------------------\n");

    flag = 0;
    
    while (flag == 0)
    {
        printf("Set the path length (a multiple of 5 between 10-70): ");
        scanf("%d", &gameSettings.pathSize);

        if ((gameSettings.pathSize < minPathSize || gameSettings.pathSize > maxPathSize) || (gameSettings.pathSize % multiplier != 0))
        {
            printf("     Must be a multiple of 5 and between 10-70!!!\n");
        }
        else 
        {
            flag = 1;
        }
    } 

    flag = 0;

    while(flag == 0)
    {
        printf("Set the limit for number of moves allowed: ");
        scanf("%d", &gameSettings.pathMoves);

        if ((gameSettings.pathMoves > maxMoveSize) || (gameSettings.pathMoves < minMoveSize)) 
        {
            printf("    Value must be between 3 and 26\n");
        }
        else 
        {
            flag = 1;
        }
    }
    
    printf("\nBOMB Placement\n"); //Bomb Config
    printf("--------------\n");

    printf("Enter the bomb positions in sets of 5 where a value\n");
    printf("of 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are 35 to set!\n");

   

    /*printf("   Positions [ 1 - 5]: ");
    scanf("%d %d %d %d %d",&gamePathHolder[0], &gamePathHolder[1], &gamePathHolder[2], &gamePathHolder[3], &gamePathHolder[4]);

    printf("%d", gamePathHolder[1]);*/
    
    for (i = 0; i < gameSettings.pathSize; i+= 5) //Setting BOMB path of game
    {
        printf("   Positions [%2d-%2d]: ", i + 1,i + 5);
        scanf("%d %d %d %d %d", &gameSettings.bombPlacement[i], &gameSettings.bombPlacement[i + 1], &gameSettings.bombPlacement[i + 2], &gameSettings.bombPlacement[i + 3], &gameSettings.bombPlacement[i + 4]);
    }
    
    printf("BOMB placement set\n\n");

    printf("TREASURE Placement\n");
    printf("------------------\n");

    printf("Enter the treasure placements in sets of 5 where a value\n");
    printf("of 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are 35 to set!\n");

    

    for (i = 0; i < gameSettings.pathSize; i += 5) //Setting TREASURE path of game
    {
        printf("   Positions [%2d-%2d]: ", i + 1, i + 5);
        scanf("%d %d %d %d %d", &gameSettings.treasurePlacement[i], &gameSettings.treasurePlacement[i + 1], &gameSettings.treasurePlacement[i + 2], &gameSettings.treasurePlacement[i + 3], &gameSettings.treasurePlacement[i + 4]);
    }

    printf("TREASURE placement set\n\n");

    printf("GAME configuration set-up is complete...\n\n"); //Settings of both player and game completed

    printf("------------------------------------\n");
    printf("TREASURE HUNT Configuration Settings\n");
    printf("------------------------------------\n");


    printf("Player:\n"); //Confirm Player
    printf("   Symbol     : %c\n", player1.playerSymbol);
    printf("   Lives      : %d\n", player1.playerLives);
    printf("   Treasure   : [ready for gameplay]\n");
    printf("   History    : [ready for gameplay]\n\n");

    printf("Game:\n");
    printf("   Path Length: %d\n", gameSettings.pathSize);
    printf("   Bombs      : ");

    int j;

    for (j = 0; j < gameSettings.pathSize; j++) 
    {
        printf("%d", gameSettings.bombPlacement[j]);
    }

    printf("\n");

    printf("   Treasure   : ");

    int k;

    for (k = 0; k < gameSettings.pathSize; k++)
    {
        printf("%d", gameSettings.treasurePlacement[k]);
    }

    printf("\n\n");

    printf("====================================\n");
    printf("~ Get ready to play TREASURE HUNT! ~\n");
    printf("====================================\n");



    return 0;
}