#include <stdio.h>
#include "chess.h"
#include "bishop.h"

void bishopGrid(int grid[][gridSize])
{
    int direction;
    firstBishop(grid, &direction);
    remainingBishops(grid, direction);
}

void printGrid(int grid[][gridSize], const char* fileName)
{
    int i, j;
    FILE *handle = fopen(fileName, "w");
    for(i = 0; i < gridSize; i++)
    {
        for (j = 0; j < gridSize; j++)
            if (grid[i][j] == 1) fputs("x ", handle);
            else fputs("- ", handle);
        fputs("\n", handle);
    }
    fclose(handle);
}