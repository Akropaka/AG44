#include <vector>
#include <iostream>
#include "graph.h"

vector<int> graph::DFS(int startVertex)
{
    vector<int> *dfsTab = new vector<int>;

    for(vertex* vert : vVertex)
    {
        vert->visited=false;
    }

    *dfsTab = recursiveForDFS(getVertexById(startVertex), *dfsTab);

    return *dfsTab;
}

vector<int> graph::recursiveForDFS(vertex* V,vector<int> dfsTab)
{
    V->visited= true;
    dfsTab.push_back(V->id);

    vector<vertex*>::iterator iter = vVertex.begin();

    while(*iter != V)
    {
        iter++;
    }

    (*iter)->initNeighbour(vEdge);

    vector<pair<vertex*,double>>::iterator i;

    for (i = (*iter)->vNeighbour.begin(); i < (*iter)->vNeighbour.end(); i++ )
    {
        if(!(*i).first->visited)
        {
            dfsTab = recursiveForDFS((*i).first, dfsTab);
        }
    }
    return dfsTab;
}
