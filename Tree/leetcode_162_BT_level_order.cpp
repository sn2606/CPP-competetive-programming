# include <iostream>
# include <vector>
# include <queue>
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        queue<TreeNode*> q; 
        q.push(root);
        while (!q.empty())
        {
            int n = q.size();
            vector<int> currentLevel;
            
            for (int i = 0; i < n; i++)
            {
                TreeNode* t = q.front(); 
                q.pop();
                if (t != nullptr)
                {
                    currentLevel.push_back(t->val);
                    q.push(t->left);
                    q.push(t->right);
                }
            }
            
            if (currentLevel.size() > 0) 
                result.push_back(currentLevel);
        }
        
        return result;
    }
};