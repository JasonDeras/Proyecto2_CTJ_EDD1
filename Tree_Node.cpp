#include "Tree_Node.h"
#include <iostream>

TreeNode::TreeNode(){
    parent = nullptr;
}

TreeNode::TreeNode(string nTag, TreeNode* nParent){
    tag = nTag;
    parent = nParent;
}

TreeNode::~TreeNode(){
   
    if(children.size() != 0){
        
        for(int i = 0;i < children.size();i++){
            delete children[i];
        }
    }
    
    children.clear();
    parent = nullptr;
    delete parent;
}

void TreeNode::setChildren(vector<TreeNode*> nChildren){
    children = nChildren;
}

vector<TreeNode*> TreeNode::getChildren(){
    return children;
}

void TreeNode::addChild(TreeNode* nChild){
    nChild->setParent(this);
    children.push_back(nChild);
}

TreeNode* TreeNode::getChild(int p){
    return children[p];
}

void TreeNode::setParent(TreeNode* node){
    parent = node;
}

TreeNode* TreeNode::getParent(){
    return parent;
}

void TreeNode::setTag(string nTag){
    tag = nTag;
}

string TreeNode::getTag(){
    return tag;
}

bool TreeNode::equals(Object* x){
    
    if(dynamic_cast<TreeNode*>(x)){
        return this->getTag() == dynamic_cast<TreeNode*>(x)->getTag() && this->getChildren() == dynamic_cast<TreeNode*>(x)->getChildren();
    }
    
    return false; 
}

string TreeNode::toString(){
    
}