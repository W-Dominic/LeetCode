/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <stack>
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // return root if it's null or equals either p or q        
        if (!root || root == p || root == q) return root;
        // recurse down left and right subtrees
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        // return right if left is null
        // else return left if right is null
        // else return root
        return !left ? right : !right ? left : root;
        
        /*
        pair<stack<TreeNode*>, int> p_info = DFS(root, p);
        pair<stack<TreeNode*>, int> q_info = DFS(root, q);
        
        //cout << p_info.first.top()->val << " " << q_info.first.top()->val << endl;
        //cout << p_info.second << " " << q_info.second << endl;
        
        //make stacks equal
        while (p_info.second != q_info.second){
            if (p_info.second > q_info.second){
                p_info.first.pop();
                p_info.second --;
            }
            else {
                q_info.first.pop();
                q_info.second --;
            }
        }
        // pop until match
        while (p_info.first.top() != q_info.first.top()){
            p_info.first.pop();
            q_info.first.pop();
        }
        return p_info.first.top();
        */
    }
    /*
    //helper function
    pair<stack<TreeNode*>, int> DFS(TreeNode* root, TreeNode* target){
        stack<TreeNode*> call_stack;
        stack<TreeNode*> return_stack;
        call_stack.push(root);
        
        int size = 0;
        
        if (root->val == target->val) {
            size ++;
            return make_pair(call_stack, size);
        }
        while(!call_stack.empty()){
            TreeNode* tmp = call_stack.top();
            call_stack.pop();
            //if the node is not found on the left side, clear the tree before continuing
            if (tmp == root->right){
                size = 0;
            }
            return_stack.push(tmp);
            size ++;
            //right child
            if(tmp->right != NULL){
                if (tmp->right->val == target->val) {
                    return_stack.push(tmp->right);
                    size ++;
                    break;
                }
                call_stack.push(tmp->right);
            }
            //left child
            if(tmp->left != NULL){
                if (tmp->left->val == target->val) {
                    return_stack.push(tmp->left);
                    size ++; 
                    break;
                }
                call_stack.push(tmp->left);
            }
        }
        return make_pair(return_stack, size);
    }
    */
};
