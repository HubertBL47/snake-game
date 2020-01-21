#ifndef CHERRY_H
#define CHERRY_H

#include "printable.h"

class Cherry : public Printable{
    public:

        Cherry();
        virtual ~Cherry();  
    private:
        virtual std::ostream& print(std::ostream &os) override {
            os << "*";
            return os;
        }
};

#endif // CHERRY_H