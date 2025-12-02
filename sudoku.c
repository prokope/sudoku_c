#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    FILE *grids = fopen("grids.txt", "r"); // Opening file with grids and saving into a pointer grids

    if (grids == NULL) // If the file can't be read, exit
    {
        printf("Error when trying to read the file.\n");
        return 1; 
    }

    srand(time(NULL));
    int randNum = rand() % 6 + 1;
    char setting[5];
    switch (randNum)
    {
        case 1:
            strcpy(setting, "game1\n");
            break;
        case 2:
            strcpy(setting, "game2\n");
            break;
        case 3:
            strcpy(setting, "game3\n");
            break;
        case 4:
            strcpy(setting, "game4\n");
            break;
        case 5:
            strcpy(setting, "game5\n");
            break;
        case 6:
            strcpy(setting, "game6\n");
            break;
        default:
            break;
    }

    printf("Setting: %s\n", setting);

    char read_row[512], grid[4][16]; // Creating a string for rows and an array of strings for the grid
    int row = 0, column = 0, scoreToWin = 0, isTargetGrid = 0;
    while (fgets(read_row, sizeof(read_row), grids) != NULL)
    {
        if ( strcmp(read_row, setting) == 0 )
        {
            isTargetGrid = 1;
            continue;
        }

        if (isTargetGrid == 1)
        {
            if ( strcmp(read_row, "e\n") == 0 )
            {
                break;
            }
            strcpy(grid[row], read_row);
            for (int idx = 0; idx < 8; idx++)
            {
                if (read_row[idx] == '-')
                {
                    scoreToWin += 1;
                }
            }
            row++;
        }
    }
    fclose(grids);

    printf("Blanks: %i\n", scoreToWin);

    int gameEnded = 0, score = 0;

    while (gameEnded == 0)
    {
        for (row = 0; row < 4; row++)
        {
            for (column = 0; column < 8; column++)
            {
                printf("%c", grid[row][column]);
            }
            printf("");
        }

        if (score == scoreToWin)
        {
            printf("\nGame won!\n");
            gameEnded = 1;
            break;
        }

        int move_row, move_column, clean_row = 1, clean_column = 1;
        char number;

        printf("\nEnter your number: ");
        scanf(" %c", &number);

        printf("Enter the row of your move: ");
        scanf("%i", &move_row);

        while ( move_row > 4 || move_row < 1 )
        {
            printf("Error. Enter the row of your move: ");
            scanf("%i", &move_row);
        }

        printf("Enter the column of your move: ");
        scanf("%i", &move_column);
        
        while ( move_column > 4 || move_column < 1 )
        {
            printf("Error. Enter the column of your move: ");
            scanf("%i", &move_column);
        }

        move_column = (move_column - 1) * 2;
        move_row -= 1;
        
        if ( grid[move_row][move_column] != '-' && grid[move_row][move_column] != ' ' && grid[move_row][move_column] != '\n')
        {
            printf("There is already a number on this position (%c)\n", grid[move_row][move_column]);
            clean_row = 0;
        }

        else
        {
            for (int grid_column = 0; grid_column < 7; grid_column++)
            {   
                if (number == grid[move_row][grid_column])
                {
                    printf("This number is already on this row.\n");
                    clean_row = 0;
                    break;
                }
            }

            for (int grid_row = 0; grid_row < 4; grid_row++)
            {
                if (number == grid[grid_row][move_column])
                {
                    printf("There is already a number on this column.\n");
                    clean_column = 0;
                    break;
                }
            }
        }

        if ( (clean_row == 1) && (clean_column == 1) )
        {
            printf("Success.\n");
            score += 1;
            printf("Score: %i\n", score);
            grid[move_row][move_column] = number;
        }

        else
        {
            printf("Mistake.\n");
        }
    }
    return 0;
}