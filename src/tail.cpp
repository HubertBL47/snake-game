#include "tail.h"


std::ostream& Tail::print(std::ostream &os){
    os << TAIL;
    return os;
}

Tail::Tail(){

}

Tail::Tail(Pixel* pixel){
    this->_pixel = pixel;
}

Tail::~Tail(){
    
}