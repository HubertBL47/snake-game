#ifndef SNAKEPART_H
#define SNAKEPART_H

#include "printable.h"


class SnakePart :public Printable{
    public :
        virtual ~SnakePart(){};

        virtual bool growIfEated() override { return false; };
        virtual bool looseIfMoovingOn() override { return true; };

    protected:
        Direction _direction;
        virtual std::ostream& print(std::ostream& os) = 0;
};

#endif //SNAKEPART_H