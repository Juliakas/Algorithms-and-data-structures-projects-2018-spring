#ifndef BISHOPS_CHESS_H
#define BISHOPS_CHESS_H
enum gridSize { gridSize = 8 };
static const char* fileName = "grid.txt";

void bishopGrid(int [][gridSize]);
void printGrid(int [][gridSize], const char* fileName);

#endif //BISHOPS_CHESS_H
