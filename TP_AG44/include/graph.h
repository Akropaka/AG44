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
        friend class edge;
        friend class vertex;

        graph(int nbrVertex);
        graph(int nbrVertex,bool directed);
        //graph(const graph& other);
        //graph(int nbrVertex=DEFAULT_VERTEX);  CPY
        virtual ~graph();
        graph& operator=(graph& other);
        void printAll();
        void printMatrix();
        void printAdjList();
        void toFileAdjList(const string);
        void getGraphFromFile(const string);
        void toFileMatrix(const string);
        vertex* getVertexById(int id);
        void printAdjToVertex(int id);
        vector<int> BFS(int startVertex);
        vector<int> DFS(int startVertex);
        vector<int> recursiveForDFS(vertex* V, vector<int>);
    protected:

    private:
        bool directedGraph;
        vector<vertex*> vVertex;
        vector<edge*> vEdge;
        enum {DEFAULT_VERTEX = 10};
};

int getNumberSize(int);
void printVectorInt(vector<int>);

#endif // GRAPH_H
