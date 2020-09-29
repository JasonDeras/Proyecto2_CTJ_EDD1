#ifndef TDA_TREE_H
#define TDA_TREE_H

#include <vector>
#include "Tree_Node.h"

using std::vector;

class TDA_Tree{

    public:

        TDA_Tree(int n_Nodos);
        
        TDA_Tree(vector<Tree_Node*> arbol);
        
        Tree_Node* Padre(Tree_Node* t_Node);

        Tree_Node* Hijo_Izquierdo(Tree_Node* t_Node);

        Tree_Node* Hijo_Derecho(Tree_Node* t_Node);

        Tree_Node* Crear(string etiqueta, int nodo = -1 ,int izquierdo = -1, int derecho = -1);

        Tree_Node* Raiz();

        void Anula();

        static TDA_Tree* leerDeArchivo(string nombre);

        void PreOrder(Tree_Node* t_Node);

        void InOrder(Tree_Node* A);

        void PostOrder(Tree_Node* raiz);

        string Ruta(string etiqueta);

        ~TDA_Tree();

    protected:

        vector<Tree_Node*> nodes;

        int root;

};
#endif