// Given a binary tree, imagine yourself standing on the right side of it, 
// return the values of the nodes you can see ordered from top to bottom.

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
    
    vector <int> res;
    
    // Modified Preorder traversal or recursion
    void dfs_recursion(TreeNode *root, int level){        
        if(!root)
            return;
        
        // We are chosing only one node from each level but level starts from 0 and size from 1
        if(level >= res.size()) 
            res.push_back(root->val);

        // preorder traversal but visit right node first        
        dfs_recursion(root->right, level+1);
        dfs_recursion(root->left, level+1);
    }
    
    
    vector<int> rightSideView(TreeNode* root) {
        
        dfs_recursion(root, 0);        
        return res;        
    }
};