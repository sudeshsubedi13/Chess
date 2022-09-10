#include "board.h"


Board::Board() {
    init_board();
}

void Board::init_board() {
    for(int j=0; j<8; j++) {
        std::vector<Cell> temp_row;
        for(int i=0; i<8; i++) {
            temp_row.push_back( Cell(j, i) );
        }
        m_cells.push_back( temp_row );
    }
}


void Board::drawBoard(sf::RenderWindow& window) {
    for(auto cellrow: m_cells) {
        for(auto cell: cellrow) {
            window.draw(cell);
        }
    }
}