#include "inputHandler.h" 

InputHandler::InputHandler(){
    this->_direction = Direction::Up;
}

InputHandler::~InputHandler(){

}

Direction InputHandler::getDirection(){
    // get curret time
    std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now(); 
    while(std::chrono::steady_clock::now() - start < std::chrono::milliseconds(FRAME_TIME)){
        readDirection();
    }
    return this->_direction;
}


// need refactoring, make a class key that has a validator
void InputHandler::readDirection(){
    int code;
    bool direction[Direction::NDirections] = {true, true, true, true};
    int i =0;
    while( i < 3){ // 3 because all array has a max size of 3
        code = this->getKeyCode();
        
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