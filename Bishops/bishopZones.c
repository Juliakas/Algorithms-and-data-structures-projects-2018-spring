#include <stdio.h>
#include "chess.h"

int main() {

    int grid[gridSize][gridSize];
    bishopGrid(grid);
    printGrid(grid, fileName);

    return 0;
}