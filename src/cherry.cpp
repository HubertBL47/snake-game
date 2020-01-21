#include "cherry.h"

Cherry::Cherry(): _alive(false){

}

Cherry::~Cherry(){

}

std::ostream& Cherry::print(std::ostream &os) {
    os << "*";
    return os;
}

bool Cherry::growIfEated() {
    return true; 
}

bool Cherry::looseIfMoovingOn() {
    return false;
}
