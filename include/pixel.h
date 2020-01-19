#ifndef PIXEL_H
#define PIXEL_H

#include "drawable.h"
#include <iostream>

class Pixel {
    
    public:
        Pixel(int x, int y);
        ~Pixel(){};
        friend std::ostream& operator<<(std::ostream &os, const Pixel &pixel);
        void setDisplayer(Drawable* drawable);
        

    private:
        Drawable* _dispayer;
        Pixel* up;
        Pixel* down;
        Pixel* left;
        Pixel* right;        
        int _x;
        int _y;

};

#endif //PIXEL_H