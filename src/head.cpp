#include "head.h"


Head::Head() : _direction(Direction::Up){
    
}

Head::~Head(){
    
}

std::ostream& Head::operator<<(std::ostream &os){
    os << HEAD_TYPE[this->_direction];
    return os;
}