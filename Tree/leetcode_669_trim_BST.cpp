// Given the root of a binary search tree and the lowest and highest boundaries 
// as low and high, trim the tree so that all its elements lies in [low, high]. 
// Trimming the tree should not change the relative structure of the elements 
// that will remain in the tree (i.e., any node's descendant should remain a descendant). 
// It can be proven that there is a unique answer.
// Return the root of the trimmed binary search tree. 
// Note that the root may change depending on the given bounds.

# include <iostream>
using namespace std;


//  Definition for a binary tree node.
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
    TreeNode* trimBST(TreeNode* root, int low, int high, bool top=true) {
        // TreeNode *temp;
        
        if(root == NULL)
            return NULL;
        
        root->left = trimBST(root->left, low, high, false);
        root->right = trimBST(root->right, low, high, false);
        
        if(root->val >= low && root->val <= high)
            return root;
        
        TreeNode *res = root->val < low ? root->right : root->left;
        
        if(!top)
            delete root;
        
        return res;
    }
};