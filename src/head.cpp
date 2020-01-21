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

    Pixel* nextPixel = this->_pixel->getNeighbour(direction); // get the next pixel where the head should be
    this->_pixel->setDisplayer(nullptr); // remove the head from the current pixel
    nextPixel->setDisplayer(this); // add the head to the next pixel
    this->_pixel = nextPixel; // add the next pixel to the head
}