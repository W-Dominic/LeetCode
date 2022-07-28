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
    vector<int> rightSideView(TreeNode* root) {
        //Using BFS we can take the rightmost element at each level
        vector<int> result;
        if (root == nullptr){
            return result;
        }
        int level = 0;
        queue<pair<TreeNode *, int>> q;
        pair<TreeNode *, int> last_node; 
        
        q.push(make_pair(root, level));  
        result.push_back(root->val);
        
        while (!q.empty()){
            pair<TreeNode *, int> curr = q.front();
            q.pop();
            //check if at right side
            if (curr.second > level){
                level ++; 
                result.push_back(last_node.first->val);
            }
            //BFS
            if (curr.first->left != nullptr){
                pair<TreeNode *, int> child = make_pair(curr.first->left, level + 1); 
                q.push(child);
                last_node = child;
            }
            if (curr.first->right != nullptr){
                pair<TreeNode *, int> child = make_pair(curr.first->right, level + 1); 
                q.push(child);
                last_node = child;
            }
        }
        
        
        return result;
        
/*
        Pseudocode:
            vector<int> result
            queue<Pair(Treenode*, int)> Q
            Pair(Treenode*, int) last_node; 
            int level = 0
            
            Q.push( (root,level) )
            while ( Q not empty ){
                Pair(Treenode, int) curr = Q.front()
                
                if curr[1] > last_node[1] {
                    level ++ 
                    result.push_back(last_node[0]->val)
                }
                     
                Q.pop()
                if (curr[0].left not null){
                    Q.push( (curr[0].left, level + 1) )
                    last_node = (curr[0].left, level + 1)
                } 
                if (curr[0].right not null) {
                    Q.push ( (curr[0].right, level + 1) )
                    last_node = (curr[0].right, level + 1)
                }
            }
*/
    }
};
