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
    // this->setOutlineThickness(3);
    this->setFillColor( sf::Color::White );
    if( (row + col) % 2 != 0 ) {
        // this->setFillColor( sf::Color(45, 222, 75) );
        this->setFillColor( sf::Color::Black );
    }
}

void Cell::setPiece(std::shared_ptr<Piece> piece) {
    m_piece = piece;
    auto piece_size = m_piece.get()->getTexture()->getSize();
    auto cell_pos = this->getPosition();
    m_piece.get()->setOrigin( piece_size.x / 2.0, piece_size.y / 2.0 );
    m_piece.get()->setPosition(cell_pos.x+cell_width/2, cell_pos.y+cell_height/2);
}