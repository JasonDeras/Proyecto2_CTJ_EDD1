#ifndef TDA_TREE_H
#define TDA_TREE_H

#include <vector>
#include "Tree_Node.h"

using std::vector;

class TDA_Tree{

    public:

        //CONSTRUCTOR
        TDA_Tree(int n_Nodos);
        TDA_Tree(vector<Tree_Node*> arbol);
        
        //METODOS

        //Devuelve el padre del nodo
        Tree_Node* Padre(Tree_Node* t_Node);

        //Delvuelve el a la izquierda del nodo
        Tree_Node* Hijo_Izquierdo(Tree_Node* t_Node);

        //Devuelve el a la derecha del nodo
        Tree_Node* Hijo_Derecho(Tree_Node* t_Node);

        //Crea un  nuevo nodo
        Tree_Node* Crear(string etiqueta, int nodo = -1 ,int izquierdo = -1, int derecho = -1);

        //Devuelve el nodo raiz
        Tree_Node* Raiz();

        //Borra todos los elementos del arbol
        void Anula();

        //Se le debe indicar el nombre de un archivo de texto a partir del cual se leerá el árbol
        static TDA_Tree* leerDeArchivo(string nombre);

        //Mostrará en pantalla el resultado de realizar el recorrido en orden previo
        void PreOrder(Tree_Node* t_Node);

        //Mostrará en pantalla el resultado de realizar el recorrido en orden simétrico 
        void InOrder(Tree_Node* A);

        //Mostrará en pantalla el resultado de realizar el recorrido en orden posterior
        void PostOrder(Tree_Node* raiz);

        //Devuelve el codigo de un nodo
        string Ruta(string etiqueta);

        //DESTRUCTOR
        ~TDA_Tree();


    protected:

        //Lista de listas de nodos
        vector<Tree_Node*> nodes;

        //Raiz del arbol
        int root;

};
#endif