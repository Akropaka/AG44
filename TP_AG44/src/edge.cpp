#include "edge.h"

edge::edge() : id(), from(), to(), cost()
{
    //ctor
}

edge::edge(int id, vertex* from, vertex* to, float cost){
    this->id = id;
    this->from = from;
    this->to = to;
    this->cost = cost;
}

edge::~edge()
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
