// 1379. Find a Corresponding Node of a Binary Tree in a Clone of That Tree
// Given two binary trees original and cloned and given a reference to a node target in the original tree.
// The cloned tree is a copy of the original tree.
// Return a reference to the same node in the cloned tree.

// Note that you are not allowed to change any of the two trees or the target node and 
// the answer must be a reference to a node in the cloned tree.

// Follow up: Solve the problem if repeated values on the tree are allowed.

# include <iostream>
# include <vector>
using namespace std;

 // Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    
    TreeNode* res = NULL;
    
    void preorderFind(TreeNode* cloned, TreeNode* target){
        
        if(!cloned)
            return;
        
        if(cloned->val == target->val){
            res = cloned;
            return;
        }
        
        preorderFind(cloned->left, target);
        preorderFind(cloned->right, target);
    }
    
// Case when all given nodes' values are unique    
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        
        preorderFind(cloned, target);
        
        return res;
    }

// Case when given nodes' values are not unique

    string path = "";
    
    // Not working rn
    // should be dfsPath instead of preorderPath
    void preorderPath(TreeNode* original, TreeNode* target, int dir){
        
        if(dir == 1){
            path += 'r';
        }else if(dir == 0){
            path += 'l';
        }
        
        if(!original)
            return;
        
        if(original->val == target->val){
            return;
        }
        
        preorderPath(original->left, target, 0);
        preorderPath(original->right, target, 1);
        
    }
    
    void pathFind(TreeNode* cloned, TreeNode* target){
        
        cout << path;
        
        for(int i = 0; i < path.size()-1; i++){
            
            if(!cloned)
                continue;
            
            if(cloned->val == target->val){
                res = cloned;
                return;
            }
            
            if(path[i] == 'l'){
                cloned = cloned->left;
            }else if(path[i] == 'r'){
                cloned = cloned->right;
            }            
        }
    }
    
    
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        
        preorderPath(original, target, -1);
        pathFind(cloned, target);
        
        return res;
    }

};