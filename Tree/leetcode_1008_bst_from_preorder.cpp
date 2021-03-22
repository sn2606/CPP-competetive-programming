// Given an array of integers preorder, which represents the preorder traversal of a BST 
// (i.e., binary search tree), construct the tree and return its root.
// It is guaranteed that there is always possible to find a binary search tree with the 
// given requirements for the given test cases.
// A binary search tree is a binary tree where for every node, any descendant of 
// Node.left has a value strictly less than Node.val, and any descendant of 
// Node.right has a value strictly greater than Node.val.
// A preorder traversal of a binary tree displays the value of the node first, 
// then traverses Node.left, then traverses Node.right.

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

// O(n^2) solution
class Solution {
public:
    
    TreeNode* buildBST(TreeNode *&root, int x){
        if(!root){
            root = new TreeNode(x);
        }else if(root->val > x){
            root->left = buildBST(root->left, x);
        }else{
            root->right = buildBST(root->right, x);
        }
        
        return root;
    }
    
    
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
        TreeNode *root = nullptr;
        
        for(int x : preorder){
            buildBST(root, x);
        }
        
        return root;
    }
};

// O(N) solution

class Solution {
public:    
    
    int idx = 0;
    TreeNode* bstFromPreorder(vector<int>& preorder, int p_val = INT_MAX) {
        if (idx >= preorder.size() || preorder[idx] > p_val)
            return nullptr;
        TreeNode* n = new TreeNode(preorder[idx++]);
        n->left = bstFromPreorder(preorder, n->val);
        n->right = bstFromPreorder(preorder, p_val);
        return n;
    }
};