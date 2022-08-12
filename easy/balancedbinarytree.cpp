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
    bool isBalanced(TreeNode* root) {
        if (root == NULL) return true;   
        int left_height = height(root->left);
        int right_height = height(root->right);
        if (abs(right_height - left_height) < 2){
            return isBalanced(root->left) && isBalanced(root->right);
        } 
        return false;
    }
    int height(TreeNode* root){
        if (root == NULL) return 0;
        return 1 + max( height(root->left), height(root->right) );
    }
};
