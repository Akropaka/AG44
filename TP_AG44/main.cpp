#include <iostream>
#include "graph.h"
#include "edge.h"
#include "vertex.h"

using namespace std;

int main()
{
    graph g(10,false);
    //g.printMatrix();
    g.toFileAdjList("AdjList");
    g.getAdjListFromFile("AdjList");
    g.printMatrix();
    return 0;
}
