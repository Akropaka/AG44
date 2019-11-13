#include "graph.h"
#include <vector>
#include <iterator>
#include <iostream>

using namespace std;

graph::graph(int nbrVertex)
{
    srand(time(0));
    int id = 0;
    for(int i=0;i<nbrVertex;++i){
        vVertex.push_back(vertex(i,i,i));
    }
    for(vector<vertex>::iterator it=vVertex.begin(); it!=vVertex.end(); ++it)
    {
        for(vector<vertex>::iterator it2=vVertex.begin(); it2!=vVertex.end(); ++it2)
        {
            int test = rand()%2;
            if(test == 1){
                this->vEdge.push_back(edge(id,*it,*it2,1.));
                ++id;
            }
        }
    }
}

graph::~graph()
{
    vVertex.clear();
    vEdge.clear();
}

graph& graph::operator=(graph& other){
    vVertex.clear();
    vEdge.clear();
    for(vector<vertex>::iterator it=other.vVertex.begin(); it!=other.vVertex.end(); ++it)
    {
        this->vVertex.push_back(*it);
    }
    for(vector<edge>::iterator it=other.vEdge.begin(); it!=other.vEdge.end(); ++it)
    {
        this->vEdge.push_back(*it);
    }
    return *this;
}

void graph::printAll(){
    for(vector<vertex>::iterator it=vVertex.begin(); it!=vVertex.end(); ++it)
    {
        cout << "Vertex | ID : " << (*it).id << " | X : " << (*it).x << " | Y : " << (*it).y << endl;
    }
    for(vector<edge>::iterator it=vEdge.begin(); it!=vEdge.end(); ++it)
    {
        cout << "Edge | ID : " << (*it).id << " | From Vertex ID : " << (*it).from.id << " | To Vertex ID : " << (*it).to.y << endl;
    }
}

void graph::printTable(){
    for(vector<vertex>::iterator it=vVertex.begin(); it!=vVertex.end(); ++it)
    {
        cout << "  " << (*it).id;
    }
    cout << endl;
    int last = 0;
    for(vector<vertex>::iterator itv=vVertex.begin(); itv!=vVertex.end(); ++itv)
    {
        cout << (*itv).id;
        for(vector<edge>::iterator ite=vEdge.begin(); ite!=vEdge.end(); ++ite)
        {
            if((*ite).from.id == (*itv).id)
            {
                for(int i=0; i < (*ite).to.id - last - 1; ++i)
                {
                    cout << "   ";
                }
                last = (*ite).to.id;
                cout << " " << (*ite).to.id << " ";
            }
        }
        cout << endl;
        last = 0;
    }
}
