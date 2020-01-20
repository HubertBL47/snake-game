#include "inputHandler.h" 

#include <iostream>
Direction InputHandler::getDirection() const{
    int code = getKeyCode();
    int direction = 0b1111;
    int i =0;
    while( i < 3){
        
        // il faut faire un mask pour avoir la bonne fonction logique
        direction & this->isCodeIn(code, UP_ARROW, i) << Direction::Up;
        direction & this->isCodeIn(code, DOWN_ARROW, i) << Direction::Down;
        direction & this->isCodeIn(code, LEFT_ARROW, i) << Direction::Left;
        direction & this->isCodeIn(code, RIGHT_ARROW, i) << Direction::Right;
        
        if (direction == 0){ // none has been pressed, lets start over
            direction = 0b1111;
            i = 0;
        } else { // keep going
            ++i;
        }
    }
    // doit s'occuper du return aussi
    return Direction::Up;
}

int InputHandler::getKeyCode() const{
    // https://stackoverflow.com/questions/3276546/how-to-implement-getch-function-of-c-in-linux
    struct termios oldattr, newattr;
    int ch;
    tcgetattr( STDIN_FILENO, &oldattr );
    newattr = oldattr;
    newattr.c_lflag &= ~( ICANON | ECHO );
    tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
    ch = getchar();    
    tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
    return ch;
}

bool InputHandler::isCodeIn(int code, const int  neededCode[], int index) const{
    return code == neededCode[index];
}