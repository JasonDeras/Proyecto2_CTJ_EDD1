#ifndef TREENODE_H
#define TREENODE_H

#include "Object.h"
#include <string>
#include <vector>

using namespace std;

class TreeNode : public Object{
    
    private:
        
        string tag;
        
        TreeNode* parent;
        
        vector<TreeNode*> children;
    
    public:
        
        TreeNode();
        
        TreeNode(string, TreeNode*);
        
        ~TreeNode();
        
        void setChildren(vector<TreeNode*>);
        
        vector<TreeNode*> getChildren();
        
        void addChild(TreeNode*);
        
        TreeNode* getChild(int);
        
        void setParent(TreeNode*);
        
        TreeNode* getParent();
        
        void setTag(string);
        
        string getTag();
        
        bool equals(Object*);
        
        string toString();
};
#endif
