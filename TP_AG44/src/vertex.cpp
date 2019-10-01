#include "vertex.h"

vertex::vertex() : id(), x(), y()
{
    //ctor
}

vertex::vertex(int id, int x, int y){
    this->id = id;
    this->x = x;
    this->y = y;
}

vertex::~vertex()
{
    //dtor
}
