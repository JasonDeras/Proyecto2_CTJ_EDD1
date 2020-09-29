#include "Grafo.h"
#include "Arista.h"
#include <fstream>
#include <iostream>
#include <climits>

using namespace std;

Grafo::Grafo(string nombrearchivo){
     
    ifstream ifs(nombrearchivo);
    if(ifs.is_open())
    {
        int nVertices;
        ifs >> nVertices;
        ifs.ignore(100,'\n');

        ady.clear();
        ady.resize(nVertices,vector<int>(nVertices,0));
		cn = nVertices;
        string linea;

        for (int i = 0; i < nVertices; i++)
        {
            getline(ifs,linea);
            vector<string> aristas = Split(linea,',');

            for (int j = 0; j < nVertices; j++)
            {
                Crear_Aristas(i,j,stoi(aristas[j]));
            }

        }
        
    }
}
 
 vector<string> Grafo::Split(string linea, char delim)
{
    vector<string> retornar;
    string temp = "";

    for (char c : linea)
    {
        if (c != delim)
        {
            temp.push_back(c);
        }
        else
        {
            retornar.push_back(temp);
            temp = "";
        }
        
    }

    if (temp.size() > 0)
    {
        retornar.push_back(temp);
    }
    
    return retornar;
    
}

Grafo::Grafo(int nodos)
{
    this->cn = nodos;
        this->ady = vector< vector<int> > (cn);
 
        for(int i = 0; i < cn; i++)
            ady[i] = vector<int> (cn, INF);
}
 
void Grafo::imprimir(vector< vector<int> > mat)
{
    for(int i=0;i<mat.size();i++){
        for(int j=0;j<mat[i].size();j++){
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }   
}

void Grafo::Crear_Aristas(int origen, int destino, int peso)
{
    ady[origen][destino] = peso;
} 
 
vector< vector<int> > Grafo :: floyd(){
    vector< vector<int> > path = this->ady;
    
    for(int i = 0; i < cn; i++)
        path[i][i] = 0;
    for(int k = 0; k < cn; k++)
        for(int i = 0; i < cn; i++)
         for(int j = 0; j < cn; j++){
          int dt = path[i][k] + path[k][j];
          if(path[i][j] > dt)
          path[i][j] = dt;
        }
        
    return path;
 } 
 
vector< vector<int> > Grafo :: kruskal(){
    vector< vector<int> > adyacencia = this->ady;
    vector< vector<int> > arbol(cn);
    vector<int> pertenece(cn); // indica a que árbol pertenece el nodo
    
    for(int i = 0; i < cn; i++){
		arbol[i] = vector<int> (cn, 0);
        pertenece[i] = i;
    }

    int nodoA;
    int nodoB;
    int arcos = 1;
    while(arcos < cn){
        
        int min = INF;
        for(int i = 0; i < cn; i++)
            for(int j = 0; j < cn; j++)
                if(min > adyacencia[i][j] && adyacencia[i][j]!=0 && pertenece[i] != pertenece[j]){
                    min = adyacencia[i][j];
                    nodoA = i;
                    nodoB = j;
                }
        
        if(pertenece[nodoA] != pertenece[nodoB]){
            arbol[nodoA][nodoB] = min;
            arbol[nodoB][nodoA] = min;

            int temp = pertenece[nodoB];
            pertenece[nodoB] = pertenece[nodoA];
            for(int k = 0; k < cn; k++)
                if(pertenece[k] == temp)
                    pertenece[k] = pertenece[nodoA];
            
            arcos++;
        }
    }
    return arbol;
}
 
vector< vector<int> > Grafo :: prim(){
    vector< vector<int> > adyacencia = this->ady;
    vector< vector<int> > arbol(cn);
    vector<int> markedLines;
    vector<int> :: iterator itVec;
 

    for(int i = 0; i < cn; i++){
    	arbol[i] = vector<int> (cn,0);
	}
 
    int padre = 0;
    int hijo = 0;
    while(markedLines.size() + 1 < cn){
        padre = hijo;
        
        markedLines.push_back(padre);
        for(int i = 0; i < cn; i++)
            adyacencia[i][padre] = INF;
 
        int min = INF;
        for(itVec = markedLines.begin(); itVec != markedLines.end(); itVec++)
            for(int i = 0; i < cn; i++)
                if(min > adyacencia[*itVec][i]){
                    min = adyacencia[*itVec][i];
                    padre = *itVec;
                    hijo = i;
                }
 
        arbol[padre][hijo] = min;
        arbol[hijo][padre] = min;
    }
    return arbol;
}
