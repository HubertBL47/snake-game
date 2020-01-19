#include "snake.h"

Snake::Snake():_length(1){
    this->_head = new Head();
}

Snake::~Snake(){
    delete this->_head;
}

Head* Snake::head(){
    return this->_head;
}

void Snake::move(Direction direction){
    
    this->_head->move(direction);
    
    switch (direction){
        case Direction::Up:

            break;

        case Direction::Right:

            break;

        case Direction::Down:

            break;

        case Direction::Left:

            break;
    }
}