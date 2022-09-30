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
    bool isValidBST(TreeNode* root) {
        if (!root->left && !root->right) return true;
        return helper(root, INT_MIN-1LL, INT_MAX+1LL); //annoying leetcode test case
    }
    bool helper(TreeNode* root, long left, long right){
        // base case root is null
        if (!root) return true;
        // val outside of bounds
        if (!(root->val > left && root->val < right)) return false; 
        
        return helper(root->left, left, root->val) &&
               helper(root->right, root->val, right);
    }
};
