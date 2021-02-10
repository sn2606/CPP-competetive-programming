// Given the root of a Binary Search Tree (BST), convert it to a Greater Tree 
// such that every key of the original BST is changed to the original key plus 
// sum of all keys greater than the original key in BST.

// As a reminder, a binary search tree is a tree that satisfies these constraints:

// The left subtree of a node contains only nodes with keys less than the node's key.
// The right subtree of a node contains only nodes with keys greater than the node's key.
// Both the left and right subtrees must also be binary search trees.



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
    void modifiedInorder(TreeNode *root, int *sum){
        
        if(!root)
            return;        
        
        // root->val += sum;
        
        modifiedInorder(root->right, sum);
        
        (*sum) += root->val;
        root->val = (*sum);
        
        modifiedInorder(root->left, sum);        
        
    }
    
    
    TreeNode* convertBST(TreeNode* root) {
        
        int sum = 0;        
        modifiedInorder(root, &sum);
        return root;        
    }
};