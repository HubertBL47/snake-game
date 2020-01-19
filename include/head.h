#ifndef HEAD_H
#define HEAD_H

#include <iostream>

#include "snakePart.h"

const char HEAD_TYPE[] = {'^', '>', 'v', '<'};

class Head : public SnakePart{

    public:
        Head();
        virtual~Head() override;

        void move(Direction direction);

    protected:
        virtual std::ostream& print(std::ostream &os) override;

    
    private :
        Direction _direction;
        SnakePart* _previous;

};

#endif // HEAD_H