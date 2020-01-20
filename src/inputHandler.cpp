#include "inputHandler.h" 

#include <iostream>
Direction InputHandler::getDirection(){
    getKeyCode();
    return Direction::Up;
}

int* InputHandler::getKeyCode(){
    // https://stackoverflow.com/questions/3276546/how-to-implement-getch-function-of-c-in-linux
    struct termios oldattr, newattr;
    int ch;
    tcgetattr( STDIN_FILENO, &oldattr );
    newattr = oldattr;
    newattr.c_lflag &= ~( ICANON | ECHO );
    tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
    
    ch = getchar();
    std::cout << ch <<std::endl;
    ch = getchar();    
    std::cout << ch <<std::endl;

    ch = getchar();    
    std::cout << ch <<std::endl;
    
    tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
    return ch;
}