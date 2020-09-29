<<<<<<< HEAD
#pragma once
=======
 #ifndef GRAFO_H
#define GRAFO_H

>>>>>>> ec01cd08dc4a8aab7c726de5c8de49153692ce31
#include <vector>
#include <iostream> 
using namespace std;
class Grafo
{
public:
    Grafo(string nombrearchivo);
    Grafo(int nodos);
    vector< vector<int> > prim();
    vector< vector<int> > kruskal();
    vector< vector<int> > floyd();
    void imprimir(vector< vector<int> >);
private:
    int cn; //cantidad de nodos
    vector< vector<int> > ady; //matriz de adyacencia
};

#endif
