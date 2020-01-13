#ifndef VERTEX_H
#define VERTEX_H

#include <vector>

using namespace std;

class edge;
class vertex
{
    public:
        bool visited;
        vertex();
        vertex(int id, int x, int y);
        virtual ~vertex();
        int id;
        int x,y;
        vector<pair<vertex*,double>> vNeighbour;
        void initNeighbour(vector<edge*>);
    protected:
};

#endif // VERTEX_H
