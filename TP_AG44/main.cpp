#include <iostream>
#include "graph.h"
#include "edge.h"
#include "vertex.h"

using namespace std;

int main()
{
    graph g(10,true);
    //g.printMatrix();
    g.toFileAdjList("AdjList");
    g.toFileMatrix("Matrix");
    g.getAdjListFromFile("AdjList");
    g.printMatrix();
    return 0;
}
