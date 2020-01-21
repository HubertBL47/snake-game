#include "snake.h"

Snake::Snake():_length(1){
    this->_head = new Head();
}

Snake::~Snake(){
    // delete this->_head;
    // while(this->_tail.size()){
    //     delete this->_tail.front();
    // }
}

Head* Snake::head(){
    return this->_head;
}

bool Snake::move(Direction direction){
    
    Pixel* oldHeadPixel = this->_head->getPixel();
    if (this->_head->grow()){
        this->_head->consume();
        this->eat(direction);
    } else {
        if(!this->_head->move(direction)){
            return false;
        }
        // moove the tail
        if (!this->_tail.empty()){ 

        // the last taile become the first and all the other does not move
        Tail* lastTail = this->_tail.front();
        this->_tail.pop();

        
        oldHeadPixel->setDisplayer(lastTail); // the lastTail now take the old position of the head
        lastTail->getPixel()->setDisplayer(nullptr); // the pixel of the lastTail now point on nothing
        lastTail->setPixel(oldHeadPixel); // set the new pixel to the last tail
        this->_tail.push(lastTail); // add the last tail at the end of queue. it is now the first
        }
    }
    return true;
}

int Snake::getBodyLength() const {
    return this->_tail.size() + 1;
    // + 1 because the head
}

void Snake::eat(Direction direction){
    Pixel* headPixel = this->_head->getPixel();
    this->_head->move(direction);

    //add tail
    Tail* newTail = new Tail(headPixel);
    headPixel->setDisplayer(newTail); // add the new tail where the tail was
    this->_tail.push(newTail);

}