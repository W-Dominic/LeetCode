class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int num_rows = mat.size();
        int num_cols = mat[0].size();
        queue<pair<int,int>> q;
        // first find all of the zeros in the matrix
        for (int row = 0; row < num_rows; row ++){
            for (int col = 0; col < num_cols; col ++){
                if (mat[row][col] == 0) {
                    q.push(make_pair(row,col));
                }
                else {
                    // mark each 1 so that we can search later
                    mat[row][col] = -1;
                }
            }
        }
        // for each zero find the closest 1 to it, and update its distance
        pair<int,int> neighbors[4] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        while(!q.empty()) {
            pair<int, int> curr = q.front();
            
            //check all of curr's neighbors
            for (int i = 0; i<4; i++){
                int new_row = neighbors[i].first + curr.first;
                int new_col = neighbors[i].second + curr.second; 
                
                // check if the new coordinates are in bounds
                // check that the neighbor is a 1
                if ( (0 <= new_row) && 
                     (new_row < num_rows) && 
                     (0 <= new_col) && 
                     (new_col < num_cols) ) {
                    if (mat[new_row][new_col] == -1) {
                        mat[new_row][new_col] = mat[curr.first][curr.second] + 1;
                        q.push(make_pair(new_row,new_col));
                    }
                }
            }
            q.pop();
        }
        // finally return the result 
        return mat;
    }
};
