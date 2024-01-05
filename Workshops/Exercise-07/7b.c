/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #7 (P2)
Full Name  : Harmanjeet Singh Hara
Student ID#: 118624220
Email      : hhara@myseneca.ca
Section    : ZAA

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

// Path Size
#define maxPathSize 70
#define minPathSize 10
#define multiplier 5

// Move Size
#define maxMoveSize 15
#define minMoveSize 3

#include <stdio.h>

struct playerInfo {     //Structure for Player Config
    char playerSymbol;
    int playerLives;
    int playerTreasure;
    int playerHistory[maxPathSize];
};

struct gameConfig {
    int pathSize;
    int pathMoves;
    int bombPlacement[maxPathSize];
    int treasurePlacement[maxPathSize];
};


int main(void)
{
    int flag, i, j, k, l;

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
            printf("    Value must be between 3 and 15\n");
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
    printf("(Example: 1 0 0 1 1) NOTE: there are 20 to set!\n");

   

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
    printf("(Example: 1 0 0 1 1) NOTE: there are 20 to set!\n");

    

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

    for (j = 0; j < gameSettings.pathSize; j++) 
    {
        printf("%d", gameSettings.bombPlacement[j]);
    }

    printf("\n");

    printf("   Treasure   : ");


    for (k = 0; k < gameSettings.pathSize; k++)
    {
        printf("%d", gameSettings.treasurePlacement[k]);
    }

    printf("\n\n");

    printf("====================================\n");
    printf("~ Get ready to play TREASURE HUNT! ~\n");
    printf("====================================\n");

    int movesLeft, livesLeft, playerInput = maxPathSize + 1;

    movesLeft = gameSettings.pathMoves;
    livesLeft = player1.playerLives;
    char playerBoard [maxPathSize]; // Gameboard overview
    char blankSpace [maxPathSize]; // Top part (player position)
    int playerSymbolCount = 0; //
    player1.playerTreasure = 0;
    int loop = 1;
    
    

    for (j = 0; j < gameSettings.pathSize; j++)
    {
        player1.playerHistory[j] = 0;
    }
    for (k = 0; k < gameSettings.pathSize; k++)
    {
        playerBoard[k] = '-';
    }
    for (l = 0; l < gameSettings.pathSize; l++)
    {
        blankSpace[l] = ' ';
    }
    do {
        for (l = 0; l < gameSettings.pathSize; l++)
        {
            if (blankSpace[l] == 'V')
            {
                playerSymbolCount++;
            }
        }
        if (playerSymbolCount == 0)
        {
            printf("\n");
        }
        else
        {
            flag = 0;
            printf("  ");
            for (l = 0; l < gameSettings.pathSize && !flag; l++)
            {
                if (blankSpace[l] == player1.playerSymbol)
                {
                    printf("%c\n", blankSpace[l]);
                    flag = 1;
                }
                else
                {
                    printf("%c", blankSpace[l]);
                }
            }
        }
        for (l = 0; l < gameSettings.pathSize; l++)
        {
            blankSpace[l] = ' ';
        }
        printf("  ");
        for (l = 0; l < gameSettings.pathSize; l++)
        {
            printf("%c", playerBoard[l]);
        }
        printf("\n");
        printf("  ");
        for (i = 1; i <= gameSettings.pathSize; i++)
        {
            if (i % 10 == 0)
            {
                printf("%d", (int)i / 10);
            }
            else
            {
                printf("|");
            }
        }
        printf("\n");
        printf("  ");
        for (i = 0; i < gameSettings.pathSize; i += 10)
        {
            printf("1234567890");
        }
        printf("\n");
        printf("+---------------------------------------------------+\n");
        printf("  Lives: %2d  | Treasures: %2d  |  Moves Remaining: %2d\n", livesLeft, player1.playerTreasure, movesLeft);
        printf("+---------------------------------------------------+\n");
        if (livesLeft == 0)
        {
            loop = 0;
        }
        if (movesLeft == 0)
        {
            loop = 0;
        }
        if (loop)
        {
            do {
                printf("Next Move [1-%d]: ", gameSettings.pathSize);
                scanf("%d", &playerInput);
                if (playerInput < 1 || playerInput > gameSettings.pathSize)
                {
                    printf("  Out of Range!!!\n");
                }
            } while (playerInput < 1 || playerInput > gameSettings.pathSize);
            printf("\n");
            if (player1.playerHistory[playerInput - 1] == 1)
            {
                printf("===============> Dope! You've been here before!\n\n");
                blankSpace[playerInput - 1] = player1.playerSymbol;
                movesLeft++;
            }
            else if (gameSettings.bombPlacement[playerInput - 1] == 1 && gameSettings.treasurePlacement[playerInput - 1] == 1)
            {
                printf("===============> [&] !!! BOOOOOM !!! [&]\n");
                printf("===============> [&] $$$ Life Insurance Payout!!! [&]\n\n");
                playerBoard[playerInput - 1] = '&';
                blankSpace[playerInput - 1] = player1.playerSymbol;
                livesLeft--;
                player1.playerTreasure++;
            }
            else if (gameSettings.bombPlacement[playerInput - 1] == 1)
            {
                printf("===============> [!] !!! BOOOOOM !!! [!]\n\n");
                playerBoard[playerInput - 1] = '!';
                blankSpace[playerInput - 1] = player1.playerSymbol;
                livesLeft--;
            }
            else if (gameSettings.treasurePlacement[playerInput - 1] == 1)
            {
                printf("===============> [$] $$$ Found Treasure! $$$ [$]\n\n");
                playerBoard[playerInput - 1] = '$';
                blankSpace[playerInput - 1] = player1.playerSymbol;
                player1.playerTreasure++;
            }
            else
            {
                printf("===============> [.] ...Nothing found here... [.]\n\n");
                playerBoard[playerInput - 1] = '.';
                blankSpace[playerInput - 1] = player1.playerSymbol;
            }
            if (livesLeft == 0)
            {
                printf("No more LIVES remaining!\n\n");
            }
            if (movesLeft == 0)
            {
                printf("No more MOVES remaining!\n\n");
            }
            player1.playerHistory[playerInput - 1] = 1;
            movesLeft--;
        }
    } while (movesLeft >= 0 && livesLeft >= 0 && loop);

    printf("\n");
    printf("##################\n");
    printf("#   Game over!   #\n");
    printf("##################\n");
    printf("\n");
    printf("You should play again and try to beat your score!\n");
    printf("\n");

    return 0;
}

        

        
        

    // Printing the final table
    /*do {
        
            for (k = 0; k < gameSettings.pathSize; k++)
            {
                if (blankSpace[k] == player1.playerSymbol)
                {
                    playerSymbolCount++;
                }
            }
            if (playerSymbolCount == 0)
            {
                printf("\n");
            }
            else
            {
                printf("  ");
            
                for (k = 0; k < gameSettings.pathSize; k++)
                {
                    
                    while(flag ==0)
                    {
                        if (blankSpace[k] == player1.playerSymbol)
                        {
                            printf("%c\n", blankSpace[k]);
                            flag =1;
                        }
                    else
                        {
                            printf("%c", blankSpace[k]);
                            break;
                        }
                    }
                
                }
            }

        
            for (k = 0; k < gameSettings.pathSize; k++)
            {
                blankSpace[k] = ' ';
            }

        
            printf("  ");
            for (k = 0; k < gameSettings.pathSize; k++)
            {
                printf("%c", playerBoard[k]);
            }
            printf("\n");

        
            printf("  ");
            for (i = 1; i <= gameSettings.pathSize; i++)
            {
                if ( i % 10 == 0)
                {
                    printf("%d", (int) i / 10);
                }
                else
                {
                    printf("|");
                }
            }
            printf("\n");

        
            printf("  ");
            for (i = 0; i < gameSettings.pathSize; i += 10)
            {
                printf("1234567890");
            }
            printf("\n");

        
            printf("+---------------------------------------------------+\n");
            printf("  Lives: %2d  | Treasures: %2d  |  Moves Remaining: %2d\n", livesLeft, player1.playerTreasure, movesLeft);
            printf("+---------------------------------------------------+\n");

        } while (movesLeft > 0 && livesLeft > 0);*/


    

    

    /*do
    {
        for(l =0; l < gameSettings.pathSize; l++)
        {
            if (blankSpace[l] == player1.playerSymbol)
            {
                playerSymbolCount++;
            }
        }
        if (playerSymbolCount == 0)
        {
            printf("\n");
        }
        else 
        {
            printf("  ");
            for(l =0; l < gameSettings.pathSize; l++)
            {
                flag = 0;
                if ((flag = 0) && (blankSpace[l] == player1.playerSymbol))
                {
                    printf("%c\n", blankSpace[k]);
                    flag = 1;
                }
                else 
                {
                    printf("%c", blankSpace[k]);
                }
            }
        }

    } while ((gameSettings.pathMoves > 0) || (player1.playerLives > 0)); */
    

    /*int player1Input;
    player1Input = 0;

    do
    {
        
        while(player1Input <= 0)
        {
            for (l=0;l < gameSettings.pathSize;l++)
            {
                printf("%c", blankSpace[l]);
            }
            
        }
        
        
    } while ((gameSettings.pathMoves > 0) || (player1.playerLives > 0));*/
    

    
 