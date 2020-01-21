#ifndef CHERRY_H
#define CHERRY_H

#include "printable.h"

class Cherry : public Printable{
    public:

        Cherry();
        virtual ~Cherry();  

        virtual bool growIfEated() override;
        virtual bool looseIfMoovingOn() override;

    private:
        virtual std::ostream& print(std::ostream &os) override ;

        bool _alive;
};

#endif // CHERRY_H