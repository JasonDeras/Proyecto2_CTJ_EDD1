#include "TDA_Tree.h"
#include <iostream>

using namespace std;

TDATree::TDATree(){
    root = nullptr;
}

TDATree::TDATree(string t){
    root = new TreeNode(t, nullptr);
}

TDATree::~TDATree(){
    delete root;
    nodes.clear();
}

TreeNode *TDATree::getParent(int p){
    return nodes[p]->getParent();
}

TreeNode* TDATree::getLefmosttChild(TreeNode* n){
    
    int p = -1;
    
    for(int i = 0;i < nodes.size();i++){
        if(n->equals(nodes[i])){
            p = i;
            break;
        }
    }
    if(p > -1){
        if(nodes[p]->getChildren().size() != 0)
            return nodes[p]->getChild(0);
        else
            return nullptr;
    }else
        return nullptr;
}

TreeNode* TDATree::getNextChild(TreeNode* n){
    
    TreeNode* temp = nullptr;
    
    for(TreeNode* t : nodes){
        if(t->equals(n)){
            temp = n->getParent();
            break;
        }
    }
    
    if(temp){
        int i = 0;
        for(TreeNode* x : temp->getChildren()){
            if(x->equals(n)){
                if(i+1 <= temp->getChildren().size())
                    return temp->getChild(i+1);
            }
            i++;
        }
    }
    return nullptr;
}

string TDATree::getTag(int p){
    return nodes[p]->getTag();
}

void TDATree::create(string tag, vector<TDATree*> children){
    
    TDATree* nTree = new TDATree(tag);
    
    if(children.size() > 0){
        
        for(int i = 0;i < children.size();i++){
            children[i]->getRoot()->setParent(nTree->getRoot());
            nTree->getRoot()->addChild(children[i]->getRoot());
            
            if(children[i]->getNodes().size() != 0)
               nTree->addNodes(children[i]->getNodes());
            else
                nTree->addNode(children[i]->getRoot());
        }
    }
    root = nTree->getRoot();
    nodes = nTree->getNodes();
}

void TDATree::clear(){
    delete root;
    nodes.clear();
    root = nullptr;
}

void TDATree::print(TreeNode* v){
   
}

bool TDATree::equals(Object *){

}

string TDATree::toString(){

}

TreeNode* TDATree::getRoot(){
    return root;
}

vector<TreeNode*> TDATree::getNodes(){
    return nodes;
}

void TDATree::addNode(TreeNode* n){
    nodes.push_back(n);
}

void TDATree::addNodes(vector<TreeNode*> n){
    nodes.insert(nodes.end(), n.begin(), n.end());
}