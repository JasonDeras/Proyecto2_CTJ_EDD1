#include "TDA_Tree.h"
#include "Grafo.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <climits>

using namespace std;

Grafo* grafo;

//Capturar el nombre del archivo
string nombreArchivo() {
    string nombre;
    cout << "Ingrese el nombre del archivo: ";
    cin >> nombre;
    return nombre;
}//fin del metodo para obtener el nombre del archivo

//Codificador en codigo huffman
void Code_Huffman(string nombre){

    ifstream ifs(nombre);
    
    if(ifs.is_open()){
        ostringstream oss;
        oss<<ifs.rdbuf();

        string strf = oss.str();

        vector<int> freq(256,0);

        for (unsigned char c : strf)
        {
            freq[c]++;
        }

        vector<pair<Tree_Node*,int>> nodes;
        nodes.push_back(make_pair(nullptr,0));

        for(int c = 0; c < 256 ;c++)
        {
            if (freq[c] > 0)
            {
                Tree_Node* tNode = new Tree_Node(nullptr,nullptr,nullptr,string(1,c));
                nodes.push_back(make_pair(tNode,freq[c]));
            }

        }

       
        int nodos_rest = nodes.size();
        while (nodos_rest > 2)
        {
            int p1 = 0;
            int p2 = 0;
            int f1 = INT_MAX;
            int f2 = INT_MAX;
            nodos_rest = 0;
            for (int i = 1; i < nodes.size(); i++)
            {
                Tree_Node* tNode = nodes[i].first;
                int nf = nodes[i].second;
                if (tNode->getPadre() == nullptr)
                {
                    if(nf < f1)
                    {
                        p2 = p1;
                        f2 = f1;
                        p1 = i;
                        f1 = nf;
                    }
                    else if (nf < f2)
                    {
                        p2 = i;
                        f2 = nf;
                    }
                    nodos_rest++;
                }
                
            }

            Tree_Node* tNode = new Tree_Node(nullptr,nodes[p1].first,nodes[p2].first,"");
            int newF = f1 + f2;
            nodes[p1].first->setPadre(tNode);
            nodes[p2].first->setPadre(tNode);

            if (nodos_rest == 2)
            {
                nodes[0] = make_pair(tNode,newF);
            }
            else
            {
                nodes.push_back(make_pair(tNode,newF));
            }
            
        }

        //Adaptar la estructura

        vector<Tree_Node*> arbol;

        for (int i = 0; i < nodes.size(); i++){
            arbol.push_back(nodes[i].first);
        }

        //Crear el arbol

        TDA_Tree* tree = new TDA_Tree(arbol);

        //Crear el archivo con el codigo

        ofstream ofsc(nombre + ".hfc");
        if(ofsc.is_open())
        {
            cout << endl << "Codigo de Huffman: ";
            for (char c : strf)
            {
                string et = string(1,c);
                string route = tree->Ruta(et);
                cout << route;
                ofsc << route;
            }
            cout << endl << "Arbol: ";
            tree->PreOrder(tree->Raiz());
            cout << endl;

            ofsc.close();
        }

        //Crear el archivo con el arbol

        ofstream ofst(nombre + ".hft");
        if (ofst.is_open())
        {
            ofst << arbol.size() << endl;
            for (int i = 0; i < arbol.size(); i++)
            {
                Tree_Node* tNode = arbol[i];
                if (tNode->getIzquierdo() != nullptr)
                {
                    string etiqueta = tNode->getIzquierdo()->getEtiqueta();
                    if (etiqueta == "," )
                    {
                        etiqueta = "cm";
                    }
                    else if (etiqueta == ";")
                    {
                        etiqueta = "pc";
                    }
                
                    ofst << etiqueta << ",";

                    for (int j = 0; j < arbol.size(); j++)
                    {
                        if (tNode->getIzquierdo() == arbol[j])
                        {
                            ofst << j << ";";
                            break;
                        }
                        
                    }

                    if (tNode->getDerecho() != nullptr)
                    {
                        string etiquetaD = tNode->getDerecho()->getEtiqueta();
                        if (etiquetaD == "," )
                        {
                            etiquetaD = "cm";
                        }
                        else if (etiquetaD == ";")
                        {
                            etiquetaD = "pc";
                        }
                        ofst << etiquetaD << ",";

                        for (int k = 0; k < arbol.size(); k++)
                        {
                            if (tNode->getDerecho() == arbol[k])
                            {
                                ofst << k;
                                break;
                            }
                        
                        }
                        
                    }
                }
                else
                {
                    ofst << ",;,";
                }
                
                ofst << endl;
            }
            ofst.close();
        }
    }

}//fib de metodo de codificacion de huffman


//Decodificado de huffman
void Decode_Huffman(string mensaje,string arbol){

    //Obtener el arbol
    ifstream ifst(arbol);
    if (ifst.is_open())
    { 
        int sizeN;
        ifst >> sizeN;
        ifst.ignore(100,'\n');

        vector<Tree_Node*> nodos(sizeN,nullptr);
        for (int i = 0; i < sizeN; i++){
            nodos[i] = new Tree_Node(nullptr,nullptr,nullptr,"");
        }

        for (int i = 0; i < sizeN; i++){
            string etiqueta;
            getline(ifst,etiqueta,',');

            if (etiqueta == "cm")
            {
                etiqueta = ",";
            }
            else if (etiqueta == "pc")
            {
                etiqueta = ";";
            }

            string n_izquierdo;
            getline(ifst,n_izquierdo,';');

            if(n_izquierdo != ""){
                Tree_Node* izquierdo = nodos[stoi(n_izquierdo)];
                izquierdo->setEtiqueta(etiqueta);
                izquierdo->setPadre(nodos[i]);
                nodos[i]->setIzquierdo(izquierdo);

            }

            string etiquetaD;
            getline(ifst,etiquetaD,',');

            if (etiquetaD == "cm"){
                etiquetaD = ",";
            }else if (etiquetaD == "pc"){
                etiquetaD = ";";
            }

            string n_derecho;
            getline(ifst,n_derecho);

            if (n_derecho != ""){
                Tree_Node* derecho = nodos[stoi(n_derecho)];
                derecho->setEtiqueta(etiquetaD);
                derecho->setPadre(nodos[i]);
                nodos[i]->setDerecho(derecho);
            }
        }

        TDA_Tree* tree = new TDA_Tree(nodos);

        //Decodificar el mensaje

        ifstream ifsc(mensaje);
        if (ifsc.is_open()){
            char c;
            Tree_Node* actual = tree->Raiz();

            cout << endl << "Mensaje decodificado\n";

            while (ifsc.get(c)){
                if(c == '0'){
                    actual = actual->getIzquierdo();
                }
                else{
                    actual = actual->getDerecho();
                }

                if(actual->getEtiqueta() != ""){
                    cout << actual->getEtiqueta();
                    actual = tree->Raiz();
                }
                
            }

            cout << endl;
        }
    }
    
}//fin del metodo de decodificado de huffman

//Método que valida que la entrada es del tipo de dato correcto (entero)
int Validar_Opcion() {
	
	int ingreso;
	cin >> ingreso;
	
	while (cin.fail()) {
		cin.clear();
		cin.ignore();
		cout << "Debe de ingresar un número entero.\n";
		cout<<"Ingréselo nuevamente: ";
		cin >> ingreso;
	}
	
	return ingreso;

}//fin del metodo para validar el ingreso del usuario

//Menu de las opciones de los arboles
void M_Arboles(){

	TDA_Tree* tree = nullptr;
	int opcion;
	bool operaciones=true;
	while(operaciones){

		cout<<"Algoritmos sobre Árboles\n\n";
    	cout<<"1. Leer árbol de un archivo\n";
    	cout<<"2. Imprimir recorrido pre-order\n";
    	cout<<"3. Imprimir recorrido in-order\n";
    	cout<<"4. Imprimir recorrido post-order\n";
    	cout<<"5. Codificador de Huffman\n";
    	cout<<"6. Decodificador de Huffman\n";
    	cout<<"7. Regresar al Menú Principal\n\n"; 
    	cout<<"Ingrese una opcion: ";
    	opcion=Validar_Opcion();
    	cout<<"\n\n";

    	switch(opcion){

    		//Caso para Leer un arbol desde un archivo
    		case 1:{
				if (tree != nullptr) {
                        delete tree;
                        tree = nullptr;
                    }
                    tree = TDA_Tree::leerDeArchivo(nombreArchivo());
    		break;}
    		
    		//Caso para Imprimir recorrido preorder
    		case 2:{
                cout<<"Arbol en preorder\n";
                tree->PreOrder(tree->Raiz());
                cout<<endl;
    		break;}
    		
    		//Caso para Imprimir recorrido in-order
    		case 3:{
                cout<<"Arbol en in order\n";
                tree->InOrder(tree->Raiz());
                cout<<endl;
    		break;}
    		
    		//Caso para Imprimir recorrido post-order
    		case 4:{
                cout<<"Arbol en post order\n";
				tree->PostOrder(tree->Raiz());
                cout<<"\n\n";
    		break;}
    		
    		//Caso para Codificador de Huffman
    		case 5:{
    			string nombre;
    			cout << "Ingrese el nombre del archivo: ";
        		cin >> nombre;
        		Code_Huffman(nombre);
    		break;}
    		
    		//Caso para Decodificador de Huffman
    		case 6:{
                string nombre;
                cout << "Ingrese el nombre del archivo: ";
                cin >> nombre;
                Decode_Huffman(nombre + ".hfc", nombre + ".hft");
    		break;}
    		
    		//Caso para volver al menu principal desde arboles
    		case 7:
    			cout<<"Volviendo al menu principal\n\n\n";
    			operaciones=false;
    		break;
    		
    		//Caso para las opciones no validas
    		default:{
    			cout<<"Opcion no valida\n\n\n";
    		break;}

    	}//fin de los caso de las operaciones con los arboles
	
	}//while repetitivo de las operaciones con los arboles
	

}//fin del metodo del menu de los arboles

//Menu de las opciones de los grafos
void M_Grafos(){
	
	int opcion;
	bool operaciones=true;

	while(operaciones){
		
		cout<<"Algoritmos sobre Grafos\n\n";
    	cout<<"1. Leer grafo de un archivo\n";
    	cout<<"2. Prim\n";
    	cout<<"3. Kruskal\n";
    	cout<<"4. Floyd\n";
    	cout<<"5. Regresar al Menú principal\n\n"; 
		cout<<"Ingrese una opcion: ";
		opcion=Validar_Opcion();
		cout<<"\n\n";
		
		switch(opcion){

			//Caso para leer un grafo desde un archivo
			case 1:{
                string nombre;
                cout<<"Ingrese el nombre del archivo: ";
                cin>>nombre;
				grafo= new Grafo(nombre+".txt");
			break;}

			//Caso para prim
			case 2:{
				grafo->imprimir(grafo->prim());
			break;}
			
			//Caso para Krustal
			case 3:{
				grafo->imprimir(grafo->kruskal());
			break;}
			
			//Caso para floyd
			case 4:{
				grafo->imprimir(grafo->floyd());
			break;}
			
			//Caso para regresar al menu pirncipal desde grafos
			case 5:{
				cout<<"Volviendo al menu principal\n\n\n";
				operaciones=false;
			break;}
			
			//Caso para las opciones no validas
			default:{
				cout<<"Opcion no valida\n\n\n";
			}
		}//fin de las opciones de los grafos

	}//fin del while repetitivo de las opciones de los grafos 


}//fin del metodo del menu para los grafos

int main() {

	bool usuario=true;

	while(usuario){
		
		int opcion;
	
		cout<<"Menú Principal\n\n"; 
    	cout<<"1. Algoritmos sobre Árboles\n";
    	cout<<"2. Algoritmos sobre Grafos\n";
    	cout<<"3. Salir\n\n"; 
    	cout<<"Ingrese una opcion: ";
    	opcion=Validar_Opcion();
    	cout<<"\n\n";
		
		switch(opcion){

			//Caso para el menu de los arboles 
			case 1:{
				M_Arboles();			
			break;}

			//Caso para el menu de grafos
			case 2:{
				M_Grafos();
			break;}

			//Caso para salir del programa
			case 3:{
				usuario=false;
			break;}
			
			//Caso para una opcion no valida
			default:{
				cout<<"Opcion no valida\n\n\n";
			break;}

		}//fin del swith del menu principal

	}//fin del while repetitivo del usuario
	cout<<"Salio del programa\n\n";
	return 0;
}//fin del main del proyecto
