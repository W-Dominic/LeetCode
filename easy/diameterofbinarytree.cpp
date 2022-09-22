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
    int diameterOfBinaryTree(TreeNode* root) {
        //find the height of the left subtree plus the height of the right subtree +2 
        
        //case: root has 1 node
        if (root->left == NULL && root->right == NULL) return 0;
        
        int diameter = 0;
        helper(root, diameter);
        return diameter;
        
        
    }
    int helper(TreeNode* root, int &diameter){
        if (root == NULL) return 0;
        int left_diameter = helper(root->left, diameter);
        int right_diameter = helper(root->right, diameter);
        diameter = max(diameter, left_diameter+right_diameter);
        return 1 + max(left_diameter, right_diameter);
    
    }

};
