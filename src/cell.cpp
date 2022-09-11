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
    base_color = sf::Color{255, 255, 255};
    // this->setOutlineThickness(3);
    if( (row + col) % 2 != 0 ) {
        // this->setFillColor( sf::Color(45, 222, 75) );
        base_color = sf::Color{30, 30, 30};
    }
    this->setFillColor(base_color);
}

void Cell::setPiece(std::shared_ptr<Piece> piece) {
    m_piece = piece;
    if (piece) {
        auto piece_size = m_piece.get()->getTexture()->getSize();
        auto cell_pos = this->getPosition();
        m_piece.get()->setOrigin( piece_size.x / 2.0, piece_size.y / 2.0 );
        m_piece.get()->setPosition(cell_pos.x+cell_width/2, cell_pos.y+cell_height/2);
    }
    // if( m_piece.get()->is_white() == false ) {
    //     auto temp_color = m_piece.get()->getColor();
    //     temp_color.a = 223;
    //     m_piece.get()->setColor(temp_color);
    // }
        
}