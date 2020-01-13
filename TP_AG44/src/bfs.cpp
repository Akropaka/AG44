#include "graph.h"
#include <iostream>
#include <list>
#include <vector>

vector<int> graph::BFS(int startVertex)
{
    vector<int> *bfsTab = new vector<int>;

    for(vertex* vert : vVertex)
    {
        vert->visited=false;
    }

    list<int> queue;
    getVertexById(startVertex)->visited=true;
    queue.push_back(startVertex);

    vector<pair<vertex*,double>>::iterator i;

    while(queue.empty()==false)
    {
        startVertex = queue.front();
        bfsTab->push_back(startVertex);
        queue.pop_front();
        vertex* s = getVertexById(startVertex);
        vector<vertex*>::iterator iter = vVertex.begin();

        while(*iter != s)
        {
            iter++;
        }

        (*iter)->initNeighbour(vEdge);

        for (i = (*iter)->vNeighbour.begin(); i < (*iter)->vNeighbour.end(); i++ )
        {
            if(!(*i).first->visited)
            {
                (*i).first->visited = true;
                queue.push_back((*i).first->id);
            }
        }
    }
    return *bfsTab;
}

void printVectorInt(vector<int> tab)
{
    vector<int>::iterator i;
    cout << "| ";
    for(i = tab.begin(); i != tab.end(); i++)
    {
        cout << *i << " | ";
    }
}
