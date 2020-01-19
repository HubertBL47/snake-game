#include "snake.h"

Snake::Snake():_length(1){
    this->_head = new Head();
    this->_tail = new Tail();
}

Snake::~Snake(){
    delete this->_head;
    delete this->_tail;
}

Head* Snake::head(){
    return this->_head;
}