#ifndef GRID_H
#define GRID_H

#include <iostream>
#include <vector>
#include <curses.h>

#include "pixel.h"
#include "snake.h"
#include "border.h"

const int SIZE_X = 30, SIZE_Y =30;

class Grid{
    public:
        Grid(); 
        ~Grid();
        friend std::ostream& operator<<(std::ostream &os, const Grid& grid);
        void clear() const;
        void getCommand();


    private:
        void setNeighbours();

        std::vector<std::vector<Pixel*>*> _grid;
        Snake* _snake;

};
#endif // GRID_H