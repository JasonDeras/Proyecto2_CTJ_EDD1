#ifndef TDATREE_H
#define TDATREE_H

#include "Object.h"
#include "Tree_Node.h"
#include <vector>

class TDATree : public Object{
    
    private:
        
        TreeNode* root;
        
        vector<TreeNode*> nodes;
    
    public:
        
        TDATree();
        
        TDATree(string);
        
        ~TDATree();
        
        TreeNode* getParent(int);
        
        TreeNode* getLefmosttChild(TreeNode*);
        
        TreeNode* getNextChild(TreeNode*);
        
        string getTag(int);
        
        void create(string, vector<TDATree*>);
        
        void clear();
        
        void print(TreeNode*);
        
        bool equals(Object*);
        
        string toString();
        
        TreeNode* getRoot();
        
        vector<TreeNode*> getNodes();
        
        void addNode(TreeNode*);
        
        void addNodes(vector<TreeNode*>);
};
#endif
