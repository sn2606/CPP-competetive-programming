// Given the root of a binary tree, flatten the tree into a "linked list":
// The "linked list" should use the same TreeNode class where the right child pointer 
// points to the next node in the list and the left child pointer is always null.
// The "linked list" should be in the same order as a pre-order traversal of the binary tree.

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
    
    vector<int> pre;
    
    void preorder(TreeNode* root){
        if(!root)
            return;
        
        pre.push_back(root->val);
        
        preorder(root->left);
        preorder(root->right);        
    }
    
    
    void flatten(TreeNode* root) {
        
        if(!root)
            return;
        
        preorder(root);
        
//         if(root->left != NULL)
//             free(root->left);
        
//         if(root->right != NULL)
//             free(root->right);
        
        root->left = NULL;
        TreeNode *current = root;
        
        for(int i = 1; i < pre.size(); i++){
            TreeNode *temp = new TreeNode(pre[i]);
            current->right = temp;
            temp->left = NULL;
            current = temp;            
        }
        
    }
};

// other solution
void flatten(TreeNode *root) {
	while (root) {
		if (root->left && root->right) {
			TreeNode* t = root->left;
			while (t->right)
				t = t->right;
			t->right = root->right;
		}

        if(root->left)
		    root->right = root->left;
		root->left = NULL;
		root = root->right;
	}
}