#include "vertex.h"
#include "edge.h"

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

void vertex::initNeighbour(vector<edge*> Edge)
{

    for(edge* ed : Edge)
    {
        if(ed->from == this)
        {
            vNeighbour.push_back(make_pair(ed->to,0.));
        }
    }

}
