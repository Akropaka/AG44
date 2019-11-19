#include <iostream>
#include "graph.h"
#include "edge.h"
#include "vertex.h"

using namespace std;

int main()
{
    graph g(25);
    //g.printMatrix();
    //g.toFileAdjList("AdjList");
    g.getAdjListFromFile("AdjList");
    g.printAdjList();
    return 0;
}
