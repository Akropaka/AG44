#include <iostream>
#include "graph.h"
#include "edge.h"
#include "vertex.h"

using namespace std;

int main()
{
    graph g(10,true);
    g.printMatrix();
    g.toFileAdjList("AdjList");
    //g.toFileMatrix("Matrix");
    //sg.getGraphFromFile("Matrix");
    //g.printMatrix();
    //g.printAdjToVertex(2);
    printVectorInt(g.BFS(0));
    return 0;
}
