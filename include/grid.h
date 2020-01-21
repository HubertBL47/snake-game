#ifndef GRID_H
#define GRID_H

#include <iostream>
#include <vector>

#include "pixel.h"
#include "snake.h"
#include "border.h"
#include "direction.h"
#include "inputHandler.h"


const int SIZE_X = 30, SIZE_Y =30;

class Grid{
    public:
        Grid(); 
        ~Grid();
        void mainLoop();


    private:
        void setNeighbours();
        void clear() const;
        void print();

        std::vector<std::vector<Pixel*>*> _grid;
        Snake* _snake;
        InputHandler inputHandler;

};
#endif // GRID_H