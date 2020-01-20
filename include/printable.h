#ifndef PRINTABLE_H
#define PRINTABLE_H

#include <iostream>

#include "direction.h"
class Pixel;

class Printable{

    public:
        Printable(){};
        virtual ~Printable(){};
        friend std::ostream& operator<<(std::ostream& os, Printable& printable){printable.print(os); return os;};
        void setPixel(Pixel* pixel){this->_pixel = pixel;};


    protected:
        virtual std::ostream& print(std::ostream &os) = 0;
        Pixel* _pixel;

};

#endif //PRINTABLE_H