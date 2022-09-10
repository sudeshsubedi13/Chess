#ifndef CELL_H
#define CELL_h


#include <SFML/Graphics.hpp>
#include "piece.h"
#include "defaults.h"


class Cell : public sf::RectangleShape
{
public:
    Cell(int row, int col);

    int getRow() { return m_row; }
    int getCol() { return m_col; }

    void setWidth(double width) { m_width = width; }
    void setHeight(double height) { m_height = height; }
    void setPiece(Piece *piece) { m_piece = piece; }

private:
    int m_row, m_col;
    double m_width, m_height;
    Piece* m_piece;
};



#endif // CELL_H