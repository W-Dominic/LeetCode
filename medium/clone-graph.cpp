/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return NULL;
        
        unordered_map <Node*, Node*> hmap; //keep track of original and cloned nodes
        queue<Node*> q; //for bfs
        q.push(node);
        
        hmap[node] = new Node(node->val); // create clone of node
        
        while(!q.empty()) {
            Node * curr = q.front();
            vector<Node*> adj = curr->neighbors; 
            for (int i = 0; i<adj.size(); i++){
                // check if clone already exists
                if (hmap[adj[i]] == NULL){
                    // if not create new clone and map it
                    Node * new_neighbor = new Node(adj[i]->val);
                    hmap[adj[i]] = new_neighbor;
                    // push to q since not visited
                    q.push(adj[i]); 
                }
                hmap[curr]->neighbors.push_back(hmap[adj[i]]);
            }
            q.pop();
        }
        
        
        return hmap[node];
    }
};
