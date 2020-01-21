#include "grid.h"

Grid::Grid(){
    for( int i = 0; i < SIZE_Y ; ++i){
        this->_grid.push_back(new std::vector<Pixel*>);
        for (int j = 0; j < SIZE_X; ++j){
            this->_grid[i]->push_back(new Pixel(i, j));
        }
    }

    // setting the border
    for (int i =1; i < SIZE_X -1; ++i){
        (*this->_grid[0])[i]->setDisplayer(new Border(BorderType::Horizontal));
        (*this->_grid[SIZE_Y -1])[i]->setDisplayer(new Border(BorderType::Horizontal));
    }
    for (int i = 1; i < SIZE_Y; ++i){
        (*this->_grid[i])[0]->setDisplayer(new Border(BorderType::Vertical));
        (*this->_grid[i])[SIZE_X - 1]->setDisplayer(new Border(BorderType::Vertical));
    }

    // setting the neighbour of all pixel
    this->setNeighbours();

    //setting the snake
    this->_snake = new Snake();

    // set the pixel for the head and the head for the pixel
    this->_snake->head()->setPixel((*this->_grid[SIZE_Y/2])[SIZE_X/2]); 
    (*this->_grid[SIZE_Y/2])[SIZE_X/2]->setDisplayer(this->_snake->head());

    this->_cherry = new Cherry();
    this->setCherry();
}

Grid::~Grid(){
    for( int i = 0; i < SIZE_Y ; ++i){
        for (int j = 0; j < SIZE_X; ++j){
            delete (*this->_grid[i])[j];
        }
        delete this->_grid[i];
    }
    delete this->_snake;
    delete this->_cherry;
}

void Grid::print(){
    for(auto line : this->_grid){
        for(Pixel* pixel : *line){
            std::cout << *pixel;
        }
        std::cout << '\n';
    }
}

void Grid::setNeighbours(){
    // set the neighbour of each pixels
    // the broder pixel does not need neighbour beacause the game end when the head enter a border
    for( int i = 1; i < SIZE_Y - 1 ; ++i){
        for (int j = 1; j < SIZE_X - 1; ++j){
            (*this->_grid[i])[j]->setNeighbour(Direction::Up, (*this->_grid[i-1])[j]);
            (*this->_grid[i])[j]->setNeighbour(Direction::Down, (*this->_grid[i+1])[j]);
            (*this->_grid[i])[j]->setNeighbour(Direction::Left, (*this->_grid[i])[j-1]);
            (*this->_grid[i])[j]->setNeighbour(Direction::Right, (*this->_grid[i])[j+1]);
        }
    }
}

void Grid::clear()const {
    // clear the console
    // need to change it depend on the os

    //windows
    #ifdef _WIN32
    std::system("cls");

    // linux
    #else
    std::system("clear");
    
    #endif
}

void Grid::mainLoop(){
    int snakeLength = this->_snake->getBodyLength();
    bool again;
    do{
        this->clear();
        this->print();
        if (snakeLength < this->_snake->getBodyLength()){
            snakeLength = this->_snake->getBodyLength();
            this->setCherry();
        }
        again = this->_snake->move(this->inputHandler.getDirection());
    }while( again );
    
    this->clear();
    this->print();

    std::cout << "Game Over !!\nPress Any Key to continue\n";
    
}

void Grid::setCherry(){
    int position = rand() %  ((SIZE_X - 2) * (SIZE_Y -2) - this->_snake->getBodyLength()); 
    // minus the number of snake pixel and border
    
    int y = 1, x = 0; // 0 because x is increment at the beginning

    while(position != 0){
        ++x;
        if (x >= SIZE_X -1){ // if x reference a border
            ++y;
            x = 1;
        }

        if ((*this->_grid[y])[x]->canHaveCherry()){
            --position;
        }

    }

    (*this->_grid[y])[x]->setDisplayer(this->_cherry);
}