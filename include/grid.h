#ifndef GRID_H
#define GRID_H

#include <iostream>
#include <vector>
#include <cstdlib>

#include "pixel.h"
#include "snake.h"
#include "border.h"
#include "direction.h"
#include "inputHandler.h"
#include "cherry.h"

const int POINT_PER_CHERRY = 100; 
const float POINT_PER_FRAME = 0.2;
const int SIZE_X = 40, SIZE_Y = 20;

class Grid{
    public:
        Grid(); 
        ~Grid();
        void mainLoop();


    private:
        void setNeighbours();
        void clear() const;
        void print();
        void setCherry();

        Cherry* _cherry;
        std::vector<std::vector<Pixel*>*> _grid;
        Snake* _snake;
        InputHandler inputHandler;
        double _score;

};
#endif // GRID_H