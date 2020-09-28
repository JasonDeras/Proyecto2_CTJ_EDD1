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
 
vector< vector<Object> > Grafo :: floyd(){
	vector< vector<Object> > path = this->ady;
	
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
 
 vector< vector<Object> > Grafo :: kruskal(){
    vector< vector<Object> > adyacencia = this->ady;
    vector< vector<Object> > arbol(cn);
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
 
vector< vector<Object> > Grafo :: prim(){

    vector< vector<Object> > adyacencia = this->ady;
    vector< vector<Object> > arbol(cn);
    vector<Object> markedLines;
    vector<Object> :: iterator itVec;

    for(int i = 0; i < cn; i++)
        arbol[i] = vector<Object> (cn, INF);
 
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
