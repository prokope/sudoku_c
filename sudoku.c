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

    char row[8], grid[4][16]; // Creating a string for rows and an array of strings for the grid
    int i = 0;

    while (fgets(row, sizeof(row), grids) != NULL)
    {
        strcpy(grid[i], row);
        printf("%s", grid[i]);
        i++;
    }

    fclose(grids);
    return 0;
}