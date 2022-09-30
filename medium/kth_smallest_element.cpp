/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <stack>
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<TreeNode*> inorder;
        traverse(root, inorder);
        
        return inorder[k-1]->val;
    }
    void traverse(TreeNode* root, vector<TreeNode*> &s){
        if (root) {
            traverse(root->left, s);
            s.push_back(root);
            traverse(root->right, s);
        }
    }
};
