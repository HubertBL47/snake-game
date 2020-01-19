#include "grid.h"

Grid::Grid(){
    for( int i = 0; i < SIZE_Y ; ++i){
        this->_grid.push_back(new std::vector<Pixel*>);
        for (int j = 0; j < SIZE_X; ++j){
            this->_grid[i]->push_back(new Pixel(i, j));
        }
    }

    this->_snake = new Snake();
    (*this->_grid[SIZE_Y/2])[SIZE_X/2]->setDisplayer(this->_snake->head());
}

Grid::~Grid(){
    for( int i = 0; i < SIZE_Y ; ++i){
        for (int j = 0; j < SIZE_X; ++j){
            delete (*this->_grid[i])[j];
        }
        delete this->_grid[i];
    }
    delete this->_snake;
}

std::ostream& operator<<(std::ostream &os, const Grid& grid){
    for(auto line : grid._grid){
        for(Pixel* pixel : *line){
            os << *pixel;
        }
        os << '\n';
    }
    return os;
}