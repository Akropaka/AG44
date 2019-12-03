#ifndef EDGE_H
#define EDGE_H

#include "vertex.h"

class edge
{
    public:
        edge();
        edge(int id,vertex* from, vertex* to, float cost);
        virtual ~edge();
        friend vertex;
        friend class graph;
        int id;
        vertex* from;
        vertex* to;
    protected:

    private:
        float cost; //w
};

#endif // EDGE_H
