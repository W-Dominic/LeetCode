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
#include <queue>
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result; 
        if (root == NULL) return result;
        
        //BFS for binary tree
        queue< pair<TreeNode*, int> > q; //
        vector<int> level; 
        int height = 0;
        
        q.push( make_pair(root, height));
        
        while(!q.empty()){
            pair<TreeNode*,int> tmp = q.front();
            cout << tmp.first->val << " height: " << tmp.second << endl; 
            cout << level.size() << endl;
            if (tmp.first->left != NULL) q.push( make_pair(tmp.first->left, tmp.second+1) );
            if (tmp.first->right != NULL) q.push( make_pair(tmp.first->right, tmp.second+1) );
            
            if(tmp.second > height){
                //TODO
                height ++;
                result.push_back(level);
                level.clear();
                level.push_back(tmp.first->val);
            }
            else {
                level.push_back(tmp.first->val);
            }
            q.pop();
        }   
        //push back whatever is left in level
        result.push_back(level);
        //return result
        return result;
    }
};
