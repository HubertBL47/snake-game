#ifndef SNAKE_H
#define SNAKE_H

#include <queue>

#include "pixel.h"
#include "snakePart.h"
#include "head.h"
#include "tail.h"
#include "direction.h"
#include "cherry.h"

class Snake {

    public:
        Snake();
        ~Snake();

        bool move(Direction direction);
        Head* head();
        int getBodyLength() const;

    private:

        void eat(Direction direction);
        unsigned _length;
        

        std::queue<Tail*> _tail;
        Head* _head;


};

#endif //SNAKE_H