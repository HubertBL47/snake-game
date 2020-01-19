#ifndef SNAKEPART_H
#define SNAKEPART_H

#include "drawable.h"


class SnakePart :public Drawable{
    public :
        virtual ~SnakePart(){};
        virtual std::ostream& operator<<(std::ostream& os) = 0;

    protected:
        Direction _direction;
};

#endif //SNAKEPART_H