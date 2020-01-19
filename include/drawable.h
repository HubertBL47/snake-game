#ifndef DRAWABLE_H
#define DRAWABLE_H

#include <iostream>

enum Direction{Up, right, down, left};

class Drawable{

    public:
        virtual std::ostream& operator<<(std::ostream& os){os << 'a'; return os;};

};

#endif //DRAWABLE_H