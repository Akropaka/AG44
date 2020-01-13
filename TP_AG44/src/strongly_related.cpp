#include "graph.h"
#include <iostream>

void graph::showStrongly_Related()
{
    stack<int> Stack;

    resetVisitedVertices();


    for(vertex* vert : vVertex)
    {
        if(vert->visited == false)
        {
            orderForST(vert, Stack);
        }
    }

    graph gr = reverseGraph();

    resetVisitedVertices();

    while(Stack.empty()== false)
    {
        int v = Stack.top();
        Stack.pop();
        vertex* V = getVertexById(v);
        if(V->visited == false)
        {
            vector<int> tab;
            printVectorInt(gr.recursiveForDFS(V, tab));
            cout << endl;
        }
    }
}

void graph::orderForST(vertex* V, stack<int> &S)
{
    V->visited=true;

    for(pair<vertex*,double> neigh : V->vNeighbour)
    {
        if(neigh.first->visited == false)
        {
            orderForST(neigh.first, S);
        }
    }
    S.push(V->id);
}

graph graph::reverseGraph()
{
    graph reverse = *this ;
    for(edge* ed : reverse.vEdge)
    {
        vertex* tmp = ed->from;
        ed->from = ed->to;
        ed->to = tmp;
    }
    return reverse;
}
