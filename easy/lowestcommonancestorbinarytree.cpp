/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <bits/stdc++.h>
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //base case
        if (root == NULL) return NULL;
        //check if root matches either p or q
        if(p->val == root->val || q->val == root->val) return root;
        
        //traverse the left and right subtree
        TreeNode* left_subtree = lowestCommonAncestor(root->left, p, q);
        TreeNode* right_subtree = lowestCommonAncestor(root->right, p, q);
        
        //if left and right both return nonNull, then we return root
        // since p and q must be in different subtrees
        if (left_subtree && right_subtree) return root;
        //if one is null, then we traverse down that tree
        if (left_subtree && (right_subtree == NULL) ) {
            return lowestCommonAncestor(left_subtree, p, q);
        }
        return lowestCommonAncestor(right_subtree, p, q);
    }
};
