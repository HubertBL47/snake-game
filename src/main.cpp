#include <iostream>
#include <cstdlib>

#include "grid.h"

int main(){

   std::srand(time(NULL));

   Grid grid;
   grid.mainLoop();

   return 0;

}