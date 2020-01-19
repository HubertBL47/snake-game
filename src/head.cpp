#include "head.h"
#include "pixel.h"


Head::Head() : _direction(Direction::Up){
    
}

Head::~Head(){
    
}

std::ostream& Head::print(std::ostream &os){
    os << HEAD_TYPE[this->_direction];
    return os;
}

void Head::move(Direction direction){
    this->_direction = direction;
    Pixel* nextPixel = this->_pixel->getNeighbour(direction);
    
    this->_pixel->setDisplayer(nullptr);
    nextPixel->setDisplayer(this);
}