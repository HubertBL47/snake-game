#include "pixel.h"


Pixel::Pixel(int x, int y): _x(x),_y(y) {

}

Pixel::~Pixel(){
    if (!this->_dispayer){
        delete this->_dispayer;
    }
}

std::ostream& operator<<(std::ostream &os, const Pixel &pixel){
    if (pixel._dispayer){
        os << *pixel._dispayer;
    } else {
        os << " ";
    }
    return os;
}

void Pixel::setDisplayer(Printable* displayer){
    this->_dispayer = displayer;
}

Pixel* Pixel::getNeighbour(Direction direction) {
    
    switch (direction)
    {
    case Direction::Up:
        return this->_up;
    case Direction::Down:
        return this->_down;
    case Direction::Left:
        return this->_left;
    case Direction::Right:
        return this->_right;
    default:
        return nullptr;
   }
}

void Pixel::setNeighbour(Direction direction, Pixel* neighbour){
   switch (direction)
    {
    case Direction::Up:
        this->_up = neighbour;
        break;
    case Direction::Down:
        this->_down = neighbour;
        break;
    case Direction::Left:
        this->_left = neighbour;
        break;
    case Direction::Right:
        this->_right = neighbour;
        break;
    default:
        break;
   }
}