#ifndef BORDER_H
#define BORDER_H

#include <iostream>
#include "printable.h"

enum BorderType{Horizontal, Vertical};
const char BORDER[] = {'_', '|'};


class Border: public Printable{

    public:
        Border(BorderType type):_type(type){};
        virtual ~Border() override{};

    protected:
        virtual std::ostream& print(std::ostream& os) override {os << BORDER[this->_type]; return os;};

    private:
        BorderType _type;

};



#endif // BORDER_H