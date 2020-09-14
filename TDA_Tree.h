#ifndef TDATREE_H
#define TDATREE_H

#include "Object.h"
#include "TreeNode.h"
#include <vector>

class TDATree : public Object{
    
    private:
        
        TreeNode* root;
        
        vector<TreeNode*> nodes;
    
    public:
        
        TDATree();
        
        ~TDATree();
        
        TreeNode* getParent(int);
        
        TreeNode* getLefmosttChild(int);
        
        TreeNode* getNextChild(TreeNode*);
        
        string getTag(int);
        
        TreeNode* create(string, vector<TreeNode*>);
        
        void clear();
        
        void print(TreeNode*);
        
        bool equals(Object*);
        
        string toString();
        
        TreeNode* getRoot();
};
#endif