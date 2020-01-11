#include <time.h>
#include <cstdlib>
#include "graph.h"
#include <vector>
#include <iterator>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

graph::graph(int nbrVertex)
{
    srand(time(0));
    int id = 0;
    directedGraph = true;
    for(int i=0;i<nbrVertex;++i){
        vVertex.push_back(new vertex(i,i,i));
    }
    for((auto) it=vVertex.begin(); it!=vVertex.end(); ++it)
    {
        for(auto it2=vVertex.begin(); it2!=vVertex.end(); ++it2)
        {
            int test = rand()%3;
            if(test == 1){
                this->vEdge.push_back(new edge(id,*it,*it2,1.));
                ++id;
                //(*it).vNeighbour.push_back((*it2));
            }
        }
    }
}

graph::graph(int nbrVertex, bool directed)
{
    srand(time(0));
    int id = 0;
    directedGraph = directed;
    for(int i=0;i<nbrVertex;++i){
        vVertex.push_back(new vertex(i,i,i));
    }
    for(auto it=vVertex.begin(); it!=vVertex.end(); ++it)
    {
        for(auto it2=vVertex.begin(); it2!=vVertex.end(); ++it2)
        {
            bool exist = false;
            int test = rand()%3;
            if(test == 1){
                for(edge* e : vEdge)
                {
                    if(e->from->id == (*it)->id && e->to->id == (*it2)->id)
                    {
                        exist = true;
                    }
                }
                if(!exist)
                {
                    this->vEdge.push_back(new edge(id,*it,*it2,1.));
                    if(!directedGraph)
                    {
                        this->vEdge.push_back(new edge(id,*it2,*it,1.));
                    }
                    ++id;
                }
                (*it)->vNeighbour.push_back(make_pair((*it2),vEdge[id-1]->cost));
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
    for(auto it=other.vVertex.begin(); it!=other.vVertex.end(); ++it)
    {
        this->vVertex.push_back(*it);
    }
    for(auto it=other.vEdge.begin(); it!=other.vEdge.end(); ++it)
    {
        this->vEdge.push_back(*it);
    }
    return *this;
}

void graph::printAll(){
    for(auto it=vVertex.begin(); it!=vVertex.end(); ++it)
    {
        cout << "Vertex | ID : " << (*it)->id << " | X : " << (*it)->x << " | Y : " << (*it)->y << endl;
    }
    for(auto it=vEdge.begin(); it!=vEdge.end(); ++it)
    {
        cout << "Edge | ID : " << (*it)->id << " | From Vertex ID : " << (*it)->from->id << " | To Vertex ID : " << (*it)->to->y << endl;
    }
}

void graph::printMatrix(){
    cout << "    ";
    for(auto it=vVertex.begin(); it!=vVertex.end(); ++it)
    {
        cout << (*it)->id << " ";
    }
    cout << endl;
    for(auto itx=vVertex.begin(); itx!=vVertex.end(); ++itx)
    {
        cout << (*itx)->id;
        for(int i=0;i<(4-getNumberSize((*itx)->id));++i)
        {
            cout << " ";
        }
        for(auto ity=vVertex.begin(); ity!=vVertex.end(); ++ity)
        {
            bool space = true;
            for(edge* e : vEdge)
            {
                if(e->from->id == (*itx)->id && e->to->id == (*ity)->id){
                    cout << "X";
                    for(int i=0;i<getNumberSize((*ity)->id);++i)
                    {
                        cout << " ";
                    }
                    space = false;
                }
            }
            if(space){
                cout << " ";
                for(int i=0;i<getNumberSize((*ity)->id);++i)
                {
                    cout << " ";
                }
            }
        }
        cout << endl;
    }
}

void graph::printAdjList(){
    for(auto it=vVertex.begin(); it!=vVertex.end(); ++it){
        cout << (*it)->id << " : ";
        for(edge* e : vEdge)
        {
            if(e->from->id == (*it)->id){
                cout << e->to->id << "|";
            }
        }
        cout << endl;
    }
}

void graph::toFileAdjList(const string path)
{
    ofstream fStream(path);
    int nbr = 0;
    for(vertex* v : vVertex)
    {
        nbr++;
    }
    fStream << nbr << endl;
    nbr=0;
    for(edge* e : vEdge)
    {
        nbr++;
    }
    if(directedGraph)
    {
        fStream << 'o' << endl;
    }
    else
    {
        fStream << 'n' << endl;
    }
    fStream << 'l' << endl;
    for(auto it=vVertex.begin(); it!=vVertex.end(); ++it){
        fStream << (*it)->id << " ";
        for(edge* e : vEdge)
        {
            if(e->from->id == (*it)->id){
                fStream << e->to->id << " ";
            }
        }
        fStream << endl;
    }
}

void graph::toFileMatrix(const string path)
{
    ofstream fStream(path);
    int nbr = 0;
    for(vertex* v : vVertex)
    {
        nbr++;
    }
    fStream << nbr << endl;
    nbr=0;
    for(edge* e : vEdge)
    {
        nbr++;
    }
    if(directedGraph)
    {
        fStream << 'o' << endl;
    }
    else
    {
        fStream << 'n' << endl;
    }
    fStream << 'm' << endl;
    for(auto itx=vVertex.begin(); itx!=vVertex.end(); ++itx)
    {
        for(auto ity=vVertex.begin(); ity!=vVertex.end(); ++ity)
        {
            bool found = false;
            for(edge* e : vEdge)
            {
                if((*itx)->id == e->from->id && (*ity)->id == e->to->id)
                {
                    fStream << e->cost << " ";
                    found = true;
                }
            }
            if(!found)
            {
                fStream << 0 << " ";
            }
        }
        fStream << endl;
    }
}

void graph::getGraphFromFile(const string path)
{
    ifstream fStream(path);
    this->vEdge.clear();
    this->vVertex.clear();
    char c;
    int sizeVertex = 0, sizeEdge = 0;
    fStream >> sizeVertex;
    fStream >> c;
    //fStream >> c;
    string temp;
    int fromId;
    int toId;
    fStream >> c;
    if(c == 'l')
    {
        for(int i=0;i<=sizeVertex;++i){
            string s;
            stringstream ss;
            getline(fStream,s);
            ss << s;
            int turn = 0;
            double weight=0.0;
            vertex* from;
            vertex* to;
            while(!ss.eof()){
                if(turn==0)
                {
                    ss >> temp;
                    if(stringstream(temp) >> fromId)
                    {
                        from = new vertex(fromId,0,0);
                        vVertex.push_back(from);
                    }
                }
                else
                {
                    ss >> temp;
                    if(stringstream(temp) >> toId)
                    {
                        to = new vertex(toId,0,0);
                        to->vNeighbour.push_back(make_pair(from,weight));
                        vEdge.push_back(new edge((turn-1)*i,from,to,0));
                    }
                    temp ="";
                }
                turn++;
            }
        }
    }
    else if(c == 'm')
    {
        for(int i=0;i<sizeVertex;++i)
        {
            vVertex.push_back(new vertex(i,0,0));
        }
        int posY = 0;
        for(int i=-1;i<sizeVertex;++i)
        {
            string s;
            stringstream ss;
            getline(fStream,s);
            ss << s;
            int posX = 0;
            int weight;
            while(!ss.eof())
            {
                ss >> temp;
                if(stringstream(temp) >> weight)
                {
                    if(weight>0)
                    {
                        vEdge.push_back(new edge((sizeVertex)*i+posX,getVertexById(i),getVertexById(posX),weight));
                        getVertexById(i)->vNeighbour.push_back(make_pair(getVertexById(posX),weight));
                    }
                    ++posX;
                }
                temp = "";
            }
        }
    }
}

void graph::printAdjToVertex(int id)
{
    for(vertex* v : vVertex){
        if(v->id == id)
        {
            for(pair<vertex*,double> vAdj : v->vNeighbour){
                cout << vAdj.first->id << " | ";
            }
            cout << endl;
        }
    }
}

vertex* graph::getVertexById(int id)
{
    for(vertex* v : vVertex){
        if(v->id == id){
            return v;
        }
    }
}

int getNumberSize(int n)
{
    int res = 1;
    while(n/10 > 0)
    {
        n=n/10;
        res++;
    }
    return res;
}
