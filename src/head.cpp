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

bool Head::move(Direction direction){
    this->_direction = direction;

    Pixel* nextPixel = this->_pixel->getNeighbour(direction); // get the next pixel where the head should be
    if (nextPixel->looseIfMoovingOn()){
        return false;
    }
    

    this->_grow |= nextPixel->growIfEated(); // indicate if there is a cherry

    this->_pixel->setDisplayer(nullptr); // remove the head from the current pixel
    nextPixel->setDisplayer(this); // add the head to the next pixel
    this->_pixel = nextPixel; // add the next pixel to the head
    return true;
}

bool Head::grow() const {
    return this->_grow;
}

void Head::consume(){
    this->_grow = false;
}