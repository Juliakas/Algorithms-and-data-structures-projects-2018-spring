#include <stdlib.h>
#include <time.h>
#include "bishop.h"

void firstBishop(int grid[][gridSize], int *direction)
{
    int i, j;
    int x, y;
    int minimumIndex = gridSize / 2 - 1;
    for(i = 0; i < gridSize; i++)
        for(j = 0; j < gridSize; j++)
            grid[i][j] = 0;
    srand((unsigned int)time(NULL));
    *direction = rand() % 2;
    if(*direction == 0)
    {
        x = 0;
        do {
            y = rand() % gridSize;
        } while(y < minimumIndex || y > gridSize - minimumIndex - 1);
    }
    else
    {
        y = 0;
        do {
            x = rand() % gridSize;
        } while(x < minimumIndex || x > gridSize - minimumIndex - 1);
    }
    grid[x][y] = 1;
}

void remainingBishops(int grid[][gridSize], int direction)
{
    int i, j;
    if(direction == 0)
    {
        for(i = 0; i < gridSize; i++)
            if (grid[0][i] == 1) break;
        for(j = 0; j < gridSize; j++)
            grid[j][i] = 1;
    }
    else
    {
        for (i = 0; i < gridSize; i++)
            if (grid[i][0] == 1) break;
        for (j = 0; j < gridSize; j++)
            grid[i][j] = 1;
    }
}