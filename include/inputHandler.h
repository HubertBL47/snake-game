#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include <boost/signals2.hpp>
#include <termios.h>
#include <unistd.h>
#include <stdio.h>

#include "direction.h"

const int UP_ARROW[] = {27, 91, 65} ;
const int DOWN_ARROW[] = {27, 91, 66} ;
const int LEFT_ARROW[] = {27, 91, 68} ;
const int RIGHT_ARROW[] = {27, 91, 67} ;

class InputHandler /*: public boost::signals2::signal_base*/{
    public:
        InputHandler(){};
        ~InputHandler(){};
        Direction getDirection() const;
    private:
        int getKeyCode() const;
        bool isCodeIn(int code, const int neededCode[], int index) const;
};


#endif // INPUTHANDLER_H