#ifndef PIXEL_H
#define PIXEL_H

#include <iostream>
#include <vector>

#include "printable.h"
#include "direction.h"

class Pixel {
    
    public:
        Pixel(int x, int y);
        ~Pixel();
        friend std::ostream& operator<<(std::ostream &os, const Pixel &pixel);
        void setDisplayer(Printable* printable);
        Pixel* getNeighbour(Direction Direction);
        void setNeighbour(Direction direction, Pixel* neighbour);

    private:
        Printable* _dispayer;
        Pixel* _up;
        Pixel* _down;
        Pixel* _left;
        Pixel* _right;
        int _x;
        int _y;

};

#endif //PIXEL_H