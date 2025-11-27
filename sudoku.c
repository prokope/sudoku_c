#include <stdio.h>
#include <string.h>

int main(void)
{
    FILE *grids = fopen("grids.txt", "r"); // Opening file with grids

    if (grids == NULL) // If the file can't be read, exit
    {
        printf("Error when trying to read the file.\n");
        return 1; 
    }

    char read_row[32], grid[4][16]; // Creating a string for rows and an array of strings for the grid
    int i = 0;

    while (fgets(read_row, sizeof(read_row), grids) != NULL)
    {
        strcpy(grid[i], read_row);
        // printf("%s", grid[i]);
        i++;
    }
    fclose(grids);

    int move_row, move_column, clean_row = 1, clean_column = 1;
    char number;

    printf("Enter your number: ");
    scanf(" %c", &number);

    printf("Enter the row of your move: ");
    scanf("%i", &move_row);

    printf("Enter the column of your move: ");
    scanf("%i", &move_column);

    printf("Number: %c\nMove Row: %i\nMove column: %i\n", number, move_row, move_column);
    
    for (int grid_column = 0; grid_column < 7; grid_column++)
    {   
        if (number == grid[move_row][grid_column])
        {
            printf("There is already a number on this row.\n");
            clean_row = 0;
            break;
        }
    }

    for (int grid_row = 0; grid_row < 3; grid_row++)
    {
        if (number == grid[grid_row][move_column])
        {
            printf("There is already a number on this column.\n");
            clean_column = 0;
            break;
        }
    }

    if ( (clean_row == 1) && (clean_column == 1) )
    {
        printf("Success.");
    }

    else
    {
        printf("Mistake.");
    }

    return 0;
}