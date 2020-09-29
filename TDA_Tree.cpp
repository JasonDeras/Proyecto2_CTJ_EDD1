#include "TDA_Tree.h"
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

TDA_Tree::TDA_Tree(int Nodos){
    
    this->root = 0;

    for (int i = 0; i < Nodos; i++){
        nodes.push_back(new Tree_Node(nullptr,nullptr,nullptr,""));
    }
    
}

TDA_Tree::TDA_Tree(vector<Tree_Node*> arbol){
    this->nodes = arbol;
}


Tree_Node* TDA_Tree::Crear(string etiqueta,int nodo, int izquierdo, int derecho) {

    if(izquierdo != -1){
        nodes[nodo]->setIzquierdo(nodes[izquierdo]);
        nodes[izquierdo]->setPadre(nodes[nodo]);
    }
        
    if (derecho != -1)
    {
        nodes[nodo]->setDerecho(nodes[derecho]);
        nodes[derecho]->setPadre(nodes[nodo]);
    }

    nodes[nodo]->setEtiqueta(etiqueta);

    return nodes[nodo];
}

Tree_Node* TDA_Tree::Padre(Tree_Node* t_Node) {
    return t_Node->getPadre();
}

Tree_Node* TDA_Tree::Hijo_Izquierdo(Tree_Node* t_Node){
    return t_Node->getIzquierdo();
}

Tree_Node* TDA_Tree::Hijo_Derecho(Tree_Node* t_Node){
    return t_Node->getDerecho();
}

Tree_Node* TDA_Tree::Raiz(){
    return nodes[0];
}

void TDA_Tree::Anula() {

    for(Tree_Node* t_Node : nodes){
        delete t_Node;
    }
    nodes.clear();
}

vector<string> Split(string line, char delimiter = ',') {
    vector<string> vect;
    string temp = "";
    for (int i = 0; i < line.length(); i++) {
        if (line.at(i) == delimiter) {
            vect.push_back(temp);
            temp = "";
        } else {
            temp += line.at(i);
        }
    }
    if(temp != "")
        vect.push_back(temp);
    return vect;
}

TDA_Tree* TDA_Tree::leerDeArchivo(string nombre) {

    ifstream archivo;
    archivo.open(nombre, ios::in);
    if (archivo.is_open()) {
        vector<vector<string>> lineas;
        string linea;
        getline(archivo, linea);
        int nLin = stoi(linea);
        for(int i = 0; i < nLin; i++) {
            if (getline(archivo, linea)) {
                lineas.push_back(Split(linea));
            } else {
                lineas.push_back(Split(""));
            }        
        }

        TDA_Tree* Arbol = new TDA_Tree(nLin);
        for (int i = 0; i < lineas.size(); i++) {
            if (lineas.at(i).size() == 2) {
                Arbol->Crear(to_string(i), i, stoi(lineas.at(i).at(0)), stoi(lineas.at(i).at(1)));
            } else if(lineas.at(i).size() == 1) {
                Arbol->Crear(to_string(i), i, stoi(lineas.at(i).at(0)));
            } else {
                Arbol->Crear(to_string(i), i);
            }
        }
        //cout << Arbol->raiz()->getIzq()->getEtiqueta();
        archivo.close();
        cout << "Arbol Cargado!\n\n\n";
        return Arbol;
    } else {
        cout << "No fue posible leer el archivo!! Arbol no cargado!\n\n\n";
        return nullptr;
    }
}

void TDA_Tree::PostOrder(Tree_Node* raiz) {
    if (raiz != NULL) {
        PostOrder(raiz->getIzquierdo());
        PostOrder(raiz->getDerecho());
        cout << raiz->toString() << " - ";
    }
}

void TDA_Tree::InOrder(Tree_Node* A){

    if(A==nullptr){
        return;
    }else{
        InOrder(A->getIzquierdo());
        cout<<A->getEtiqueta()<<" - ";
        InOrder(A->getDerecho());
    }

    if(A == nodes[0])
        cout << endl;
}

void TDA_Tree::PreOrder(Tree_Node* t_Node){
    
    cout << t_Node->toString() << ",";
    if(t_Node->getIzquierdo() != nullptr)
        PreOrder(t_Node->getIzquierdo());
    if (t_Node->getDerecho() != nullptr)
        PreOrder(t_Node->getDerecho());

    if(t_Node == nodes[0])
        cout << endl;
}

string TDA_Tree::Ruta(string etiqueta){

    Tree_Node* target = nullptr;
    
    for (Tree_Node* t_Node : nodes){

        if (t_Node->getEtiqueta() == etiqueta){
            target = t_Node;
            break;
        }

    }
    if(target == nullptr)
        return "";

    //Creamos la ruta
    
    string route;
    while (target != Raiz())
    {
        Tree_Node* padre = target->getPadre();
        if (padre->getIzquierdo() == target)
        {
            route = "0" + route;
        }
        else
        {
            route = "1" + route;
        }
        target = padre;
        
    }

    return route;
}

TDA_Tree::~TDA_Tree() {
    Anula();
}