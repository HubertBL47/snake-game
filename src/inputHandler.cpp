#include "inputHandler.h" 

#include <iostream>

InputHandler::InputHandler(): _getInput(true){
    this->_direction = Direction::Up;
    this->_thread = std::thread(&InputHandler::readDirection, this);
}

InputHandler::~InputHandler(){
    this->_getInput = false;
    this->_thread.join();
}

Direction InputHandler::getDirection(){
    // get curret time
    std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now(); 

    // wait for the right amount of time
    while(std::chrono::steady_clock::now() - start < std::chrono::milliseconds(FRAME_TIME)){
    }
    return this->_direction;
}


// need refactoring, make a class key that has a validator
void InputHandler::readDirection(){
    while (this->_getInput){
        int code;
        bool direction[Direction::NDirections] = {true, true, true, true};
        int i =0;
        while( i < 3 && this->_getInput){ // 3 because all array has a max size of 3
            code = this->getKeyCode();
            //https://stackoverflow.com/questions/12207684/how-do-i-terminate-a-thread-in-
            // il faut faire un mask pour avoir la bonne fonction logique
            direction[Direction::Up] &= code == UP_ARROW[i];
            direction[Direction::Right] &= code == RIGHT_ARROW[i];
            direction[Direction::Down] &= code == DOWN_ARROW[i];
            direction[Direction::Left] &= code == LEFT_ARROW[i];
            
            // verified if there is a match
            bool match = false;
            for (int i = Direction::Up; i != Direction::NDirections; ++i){
                match |= direction[i];
            }
            if (match){ //keep going
                ++i;
            } else { // none is currently matching. retry
                for (int i = Direction::Up; i != Direction::NDirections; ++i){
                    direction[i] = true;
                }
                i = 0;
            }
        }
        
        for (int i = Direction::Up; i != Direction::NDirections; ++i){
            if(direction[i]){
                this->_direction = static_cast<Direction>(i);
            }   
        }
    }
}

int InputHandler::getKeyCode() const {
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
