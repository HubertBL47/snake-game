#include "tail.h"


std::ostream& Tail::operator<< (std::ostream &os){
    os << TAIL;
    return os;
}