#include "pixel.h"


Pixel::Pixel(int x, int y): _x(x),_y(y) {

}

std::ostream& operator<<(std::ostream &os, const Pixel &pixel){
    os << *pixel._dispayer;
    return os;
}

void Pixel::setDisplayer(Drawable* displayer){
    this->_dispayer = displayer;
}