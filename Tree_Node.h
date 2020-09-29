#ifndef TREE_NODE_H
#define TREE_NODE_H

#include "Object.h"

class Tree_Node : public Object{

    public:

    //CONSTRUCTOR
    Tree_Node(Tree_Node* padre, Tree_Node* hijo_izquierdo, Tree_Node* hijo_derecho, string etiqueta);

    //MUTADORES
    Tree_Node* getPadre();
    void setPadre(Tree_Node* padre);

    Tree_Node* getIzquierdo();
    void setIzquierdo(Tree_Node* hijo_izquierdo);

    Tree_Node* getDerecho();
    void setDerecho(Tree_Node* hijo_derecho);

    string getEtiqueta();
    void setEtiqueta(string etiqueta);

    //METODOS
    virtual int Comparar(Object*);
    virtual string toString();

    //DESTRUCTOR
    ~Tree_Node();

    protected:

    Tree_Node *padre;
    Tree_Node *hijo_izquierdo;
    Tree_Node *hijo_derecho;
    string etiqueta;

};
#endif