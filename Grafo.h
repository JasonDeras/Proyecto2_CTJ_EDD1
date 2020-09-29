 #ifndef GRAFO_H
#define GRAFO_H

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
