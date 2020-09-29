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
    void Crear_Aristas(int origen, int destino, int peso);
     
 	vector<string> Split(string linea, char deliminator);
    vector< vector<int> > prim();
    vector< vector<int> > kruskal();
    vector< vector<int> > floyd();
    void imprimir(vector< vector<int> >);
private:
    int cn; //cantidad de nodos
    const int INF=-1;
    vector< vector<int> > ady; //matriz de adyacencia
};

#endif
