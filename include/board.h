#ifndef BOARD_H
#define BOARD_h


#include <vector>

#include "cell.h"


class Board
{
public:
    Board();

    Cell& getCell(int row, int col) { return m_cells.at(row).at(col); }
    void drawBoard(sf::RenderWindow& window);

private:
    void init_board();


private:
    std::vector<std::vector<Cell>> m_cells;
};



#endif // BOARD_H