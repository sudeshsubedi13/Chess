#include "cell.h"

Cell::Cell(int row, int col)
    :m_row(row), m_col(col)
{
    m_piece = nullptr;
    m_width = cell_width;
    m_height = cell_height;
    this->setSize( sf::Vector2f(m_width, m_height) );
    this->setPosition( origin_x_offset + m_col * m_width, origin_y_offset + m_row * m_height);
    this->setOutlineColor(sf::Color::Black);
    this->setOutlineThickness(3);
    this->setFillColor( sf::Color::White );
    if( (row + col) % 2 != 0 )
        this->setFillColor( sf::Color(45, 222, 75) );
}