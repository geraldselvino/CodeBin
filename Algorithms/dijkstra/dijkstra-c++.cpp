/**********************************************
* Author: Gerald Selvino
* Description: Dijkstra's algorithm demo
* Language: C++
***********************************************/
#include <iostream>
#include <map>
#include <list>
#include <string>

using namespace std;

struct Vertex{
    Vertex(string name, int distance){
        _name = name;
        _distance = distance;
        _prev = NULL;
    }
    string _name;
    int _distance;
    struct Vertex* _prev;
};

struct Edge{
    Edge(int weight, Vertex* from, Vertex* to){
        _weight = weight;
        _from = from;
        _to = to;
    }
    int _weight;
    struct Vertex* _from;
    struct Vertex* _to;
};

const int MaxDistance = 1000;

struct Graph{
    Graph(){
        _vertices["0"] = new Vertex("0", 0);
        _vertices["1"] = new Vertex("1", MaxDistance);
        _vertices["7"] = new Vertex("7", MaxDistance);
        _vertices["2"] = new Vertex("2", MaxDistance);
        _vertices["8"] = new Vertex("8", MaxDistance);
        _vertices["6"] = new Vertex("6", MaxDistance);
        _vertices["5"] = new Vertex("5", MaxDistance);
        _vertices["3"] = new Vertex("3", MaxDistance);
        _vertices["4"] = new Vertex("4", MaxDistance);

        _edges.push_back(new Edge(4, _vertices["0"], _vertices["1"]));
        _edges.push_back(new Edge(8, _vertices["0"], _vertices["7"]));
        _edges.push_back(new Edge(11, _vertices["1"], _vertices["7"]));
        _edges.push_back(new Edge(8, _vertices["1"], _vertices["2"]));
        _edges.push_back(new Edge(7, _vertices["7"], _vertices["8"]));
        _edges.push_back(new Edge(1, _vertices["7"], _vertices["6"]));
        _edges.push_back(new Edge(2, _vertices["2"], _vertices["8"]));
        _edges.push_back(new Edge(6, _vertices["6"], _vertices["8"]));
        _edges.push_back(new Edge(4, _vertices["2"], _vertices["5"]));
        _edges.push_back(new Edge(7, _vertices["2"], _vertices["3"]));
        _edges.push_back(new Edge(14, _vertices["3"], _vertices["5"]));
        _edges.push_back(new Edge(9, _vertices["3"], _vertices["4"]));
        _edges.push_back(new Edge(2, _vertices["6"], _vertices["5"]));
        _edges.push_back(new Edge(10, _vertices["5"], _vertices["4"]));
    }

    map<string,Vertex*> _vertices;
    list<Edge*> _edges;
};

void exploreAdjacent(Vertex* pCurrent, list<Edge*> pEdge, map<string, Vertex*>& pU, map<string, Vertex*> pS);
Vertex* getMinVertex(map<string, Vertex*> pU);

map<string,Vertex*> dijkstra(Graph* rGraph){

    map<string, Vertex*> Undiscovered;
    map<string, Vertex*> ShortestPathTree;
    Vertex* CurrentNode = rGraph->_vertices["0"];
    Undiscovered[CurrentNode->_name] = CurrentNode;

    while (Undiscovered.size() > 0){
        ShortestPathTree[CurrentNode->_name] = CurrentNode;
        Undiscovered.erase(CurrentNode->_name);
        exploreAdjacent(CurrentNode, rGraph->_edges, Undiscovered, ShortestPathTree);
        Vertex* MinNode = getMinVertex(Undiscovered);
        CurrentNode = MinNode;
    }

    return ShortestPathTree;
}

void exploreAdjacent(Vertex* pCurrent, list<Edge*> pEdge, map<string, Vertex*>& pU, map<string, Vertex*> pS){
    for (list<Edge*>::iterator i = pEdge.begin(); i != pEdge.end(); i++){
        if (pCurrent == (*i)->_from && !pS[(*i)->_to->_name]){
            int prevDistance = (*i)->_from->_distance;

            if ((*i)->_weight + prevDistance < (*i)->_to->_distance){
                (*i)->_to->_distance = (*i)->_weight + prevDistance;
                (*i)->_to->_prev = (*i)->_from;

                if(pU[(*i)->_to->_name]){
                    if ((*i)->_to->_distance < pU[(*i)->_to->_name]->_distance){
                        pU[(*i)->_to->_name] = (*i)->_to;
                    }
                }
                else{
                    pU[(*i)->_to->_name] = (*i)->_to;
                }
            }
        }
    }
}

Vertex* getMinVertex(map<string, Vertex*> pU){
    Vertex* ret = new Vertex("", MaxDistance);

    for (map<string, Vertex*>::iterator i = pU.begin(); i != pU.end(); i++){
        if (i->second->_distance < ret->_distance){
            ret = i->second;
        }
    }

    return ret;
}

int main(int argc, char* argv[])
{
    Graph* g = new Graph();
    map<string, Vertex*> l_Spt = dijkstra(g);
    Vertex* endNode = l_Spt["4"];

    while (endNode){
        cout<<endNode->_name<<endl;
        endNode = endNode->_prev;
    }
}

