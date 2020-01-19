#ifndef SNAKE_H
#define SNAKE_H

#include <vector>

#include "snakePart.h"
#include "head.h"
#include "tail.h"

class Snake {

    public:
        Snake();
        ~Snake();

        void move(Direction direction);
        void eat(Direction direction);
        Head* head();

    private:
        unsigned _length;
        

        std::vector<Tail*> _tail;
        Head *_head;


};

#endif //SNAKE_H