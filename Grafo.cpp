Grafo::Grafo()
{
 
}
 
Grafo::Grafo(int nodos)
{
    this->cn = nodos;
        this->ady = vector< vector<int> > (cn);
 
        for(int i = 0; i < cn; i++)
            ady[i] = vector<int> (cn, INF);
}
 
vector< vector<int> > Grafo :: prim(){

    vector< vector<int> > adyacencia = this->ady;
    vector< vector<int> > arbol(cn);
    vector<int> markedLines;
    vector<int> :: iterator itVec;
 

    for(int i = 0; i < cn; i++)
        arbol[i] = vector<int> (cn, INF);
 
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