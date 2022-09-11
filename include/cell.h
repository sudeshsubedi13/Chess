#ifndef CELL_H
#define CELL_H


#include <SFML/Graphics.hpp>
#include <memory>
#include "piece.h"
#include "defaults.h"


class Cell : public sf::RectangleShape
{
public:
    Cell(int row, int col);

    int getRow() { return m_row; }
    int getCol() { return m_col; }
    std::shared_ptr<Piece> getPiece() { return m_piece; }

    void setWidth(double width) { m_width = width; }
    void setHeight(double height) { m_height = height; }
    void setPiece(std::shared_ptr<Piece> piece);

private:
    int m_row, m_col;
    double m_width, m_height;
    std::shared_ptr<Piece> m_piece;
};



#endif // CELL_H