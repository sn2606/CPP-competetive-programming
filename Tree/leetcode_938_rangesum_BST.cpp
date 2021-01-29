// Given the root node of a binary search tree, 
// return the sum of values of all nodes with 
// a value in the range [low, high].

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
//     int res = 0;
//     int inorder(TreeNode *root, int L, int H){ 
        
//         if(root){
//             inorder(root->left, L, H);
//             if(root->val >= L && root->val <= H)
//                 res += root->val;
//             inorder(root->right, L, H);
//         }
        
//         return res;        
//     }
    
    int rangeSumBST(TreeNode* root, int L, int R) {
        
        if(!root)
            return 0;
        // else
        //     return inorder(root, L, R);
        
        if(root->val >= L && root->val <= R){
            return root->val + rangeSumBST(root->left,L,R) + rangeSumBST(root->right,L,R);
        }
        else if(root->val < L){
            return rangeSumBST(root->right,L,R);
        }
        else {
            return rangeSumBST(root->left,L,R);
        }
    }
};