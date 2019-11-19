#ifndef VERTEX_H
#define VERTEX_H

#include <vector>

using namespace std;

class vertex
{
    public:
        vertex();
        vertex(int id, int x, int y);
        virtual ~vertex();
        int id;
        int x,y;
        vector<vertex> vNeighbour;
    protected:
};

#endif // VERTEX_H
