#include "Tree_Node.h"

Tree_Node::Tree_Node(Tree_Node* padre, Tree_Node* hijo_izquierdo, Tree_Node* hijo_derecho, string etiqueta){
    this->padre = padre;
    this->hijo_derecho = hijo_derecho;
    this->hijo_izquierdo = hijo_izquierdo;
    this->etiqueta = etiqueta;

}

Tree_Node* Tree_Node::getPadre(){
    return this->padre;
}

void Tree_Node::setPadre(Tree_Node* padre){
    this->padre = padre;
}

Tree_Node* Tree_Node::getDerecho(){
    return this->hijo_derecho;
}

void Tree_Node::setDerecho(Tree_Node* hijo_derecho){
    this->hijo_derecho = hijo_derecho;
}

Tree_Node* Tree_Node::getIzquierdo(){
    return this->hijo_izquierdo;
}

void Tree_Node::setIzquierdo(Tree_Node* hijo_izquierdo){
    this->hijo_izquierdo = hijo_izquierdo;
}

string Tree_Node::getEtiqueta(){
    return this->etiqueta;
}

void Tree_Node::setEtiqueta(string etiqueta){
    this->etiqueta = etiqueta;
}

int Tree_Node::Comparar(Object* x) {

    Tree_Node* otro = dynamic_cast<Tree_Node*>(x);
    
    if(otro){
        if (otro->getEtiqueta() == this->etiqueta){
            return 1;
        }
    }
    return 0;
}

string Tree_Node::toString(){
    return etiqueta;
}

//DESTRUCTOR
Tree_Node::~Tree_Node(){
    
}