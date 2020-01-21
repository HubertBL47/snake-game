#ifndef HEAD_H
#define HEAD_H

#include <iostream>

#include "snakePart.h"
#include "direction.h"

const char HEAD_TYPE[] = {'^', '>', 'v', '<'};

class Head : public SnakePart{

    public:
        Head();
        virtual~Head() override;
        bool move(Direction direction);
        bool grow() const;
        void consume();

    protected:
        virtual std::ostream& print(std::ostream &os) override;

    
    private :
        Direction _direction;
        SnakePart* _previous;
        bool _grow;

};

#endif // HEAD_H