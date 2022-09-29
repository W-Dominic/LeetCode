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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // handling case due to leetcode bug
        if (preorder.size() == 1){
            cout << "handling case manually" << endl;
            return new TreeNode(preorder[0]);
        }
        return helper(preorder, inorder, 0, preorder.size()-1);
        
    }
    TreeNode* helper(vector<int> &preorder, vector<int> &inorder, int start, int end){ 
        //base case 
        if (start > end) return NULL;
        
        static int preorder_index = 0;
        TreeNode* root = new TreeNode(preorder[preorder_index ++]);
        
        //base case 2: root has no children
        if (start == end) return root;
        
        int root_index = finder(root->val, inorder);
        root->left = helper(preorder, inorder, start, root_index -1);
        root->right = helper(preorder, inorder, root_index + 1, end);
        return root; 
            
    }
    int finder(int target, vector<int> vec){
        for (int i = 0; i < vec.size(); i++){
            if (vec[i] == target){
                return i;
            }
        }
        return -1;
    }
    
};
