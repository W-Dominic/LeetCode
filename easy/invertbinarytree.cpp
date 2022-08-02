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
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        helper(root);
        return root;
        
    }
    void helper(TreeNode* curr){
        //base case
        if(curr == nullptr) return;
        //swap
        TreeNode* tmp = curr->left;
        curr->left = curr->right;
        curr->right = tmp;
        //recurse
        helper(curr->left);
        helper(curr->right);
    }
};
