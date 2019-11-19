#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include "edge.h"
#include "vertex.h"
#include <string>

using namespace std;

class graph
{
    public:
        friend edge;
        friend vertex;

        graph(int nbrVertex=DEFAULT_VERTEX);
        //graph(const graph& other);
        //graph(int nbrVertex=DEFAULT_VERTEX);  CPY
        virtual ~graph();
        graph& operator=(graph& other);
        void printAll();
        void printMatrix();
        void printAdjList();
        void toFileAdjList(const string);
        void getAdjListFromFile(const string);
    protected:

    private:
        vector<vertex> vVertex;
        vector<edge> vEdge;
        enum {DEFAULT_VERTEX = 10};
};

int getNumberSize(int);

#endif // GRAPH_H
