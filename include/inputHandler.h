#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

//#include <boost/signals2.hpp>
#include <termios.h>
#include <unistd.h>
#include <stdio.h>
#include <stdexcept>
#include <chrono>

#include "direction.h"

const int UP_ARROW[] = {27, 91, 65} ;
const int DOWN_ARROW[] = {27, 91, 66} ;
const int LEFT_ARROW[] = {27, 91, 68} ;
const int RIGHT_ARROW[] = {27, 91, 67} ;

const int FRAME_TIME = (1000.0/1.0); // 60 frame per second in ms

class InputHandler /*: public boost::signals2::signal_base*/{
    public:
        InputHandler();
        ~InputHandler();
        Direction getDirection();

    private:
        int getKeyCode() const;
        void readDirection();
        bool isCodeIn(int code, const int neededCode[], int index) const;

        Direction _direction;
};


#endif // INPUTHANDLER_H