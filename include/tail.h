#ifndef TAIL_H
#define TAIL_H

#include "snakePart.h"

const char TAIL = 'o';

class Tail: public SnakePart {
    public:
    virtual ~Tail() override{};
        
    protected:
        virtual std::ostream& print(std::ostream &os) override;

    private:
        SnakePart* _next;
        SnakePart* _previous;

};


#endif //TAIL_H