#include <stdio.h>

int main(void)
{
    FILE *grids = fopen("grids.txt", "r");

    if (grids == NULL)
    {
        printf("Error when trying to read the file.\n");
        return 1;
    }

    char row[4];
    while ( fgets(row, sizeof(row), grids) != NULL)
    { 
        // Read row
    }
    return 0;
}