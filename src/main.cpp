#include <iostream>

#include "grid.h"

int main(){
   Grid grid;

   while(true){
      grid.clear();
      std::cout << grid;
      grid.getCommand();
      std::cout<< std::getchar();
   }
}