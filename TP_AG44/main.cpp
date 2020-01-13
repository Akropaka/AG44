#include <iostream>
#include "graph.h"
#include "edge.h"
#include "vertex.h"

using namespace std;

int main()
{
    graph g(5,true);
    //g.toFileAdjList("AdjList");
    //g.toFileMatrix("Matrix");
    g.getGraphFromFile("Matrix");
    g.printMatrix();
    //g.printAdjToVertex(2);
    /*printVectorInt(g.BFS(0));
    cout << endl;
    printVectorInt(g.DFS(0));
    cout << endl;*/
    g.showStrongly_Related();
    return 0;
}
