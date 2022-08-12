#include <queue>
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        queue<pair<int,int>> q;
        pair<int, int> root;
        root.first = sr;
        root.second = sc; 
        q.push(root);
        
        int boundaryr = image[0].size();
        int boundaryc = image.size();
        
        int starting_color = image[root.first][root.second];
        
        if (starting_color == color){
            return image;
        }
        
        while (!q.empty()){
            pair<int, int> current = q.front();
            
            //change the color
            image[current.first][current.second] = color;
            cout << "current: " << current.first << "," << current.second << " Color: " << image[current.first][current.second] << endl;
            q.pop();
       
            //get the "children"
            int up = current.first - 1;
            int down = current.first + 1;
            int left = current.second - 1;
            int right = current.second + 1; 
            
            //up
            if (up >= 0 && up < boundaryc  && (image[up][current.second] == starting_color)){
                pair<int, int> child;
                child.first = up;
                child.second = current.second;
                q.push(child);
                cout << child.first << "," << child.second << " Color: " << image[child.first][child.second] << endl;
            }
            //down
            if (down >= 0 && down < boundaryc && (image[down][current.second] == starting_color)){
                pair<int, int> child;
                child.first = down;
                child.second = current.second;
                q.push(child);
                cout << child.first << "," << child.second << " Color: " << image[child.first][child.second] << endl;
            }
            //left
            if (left >= 0 && left < boundaryr && (image[current.first][left] == starting_color)){
                pair<int, int> child;
                child.first = current.first;
                child.second = left;
                q.push(child);
                cout << child.first << "," << child.second << " Color: " << image[child.first][child.second] << endl;
            }
            //right
            if (right >= 0 && right < boundaryr && (image[current.first][right] == starting_color)){
                pair<int, int> child;
                child.first = current.first;
                child.second = right;
                q.push(child);
                cout << child.first << "," << child.second << " Color: " << image[child.first][child.second] << endl;
            }
        }
        return image; 
    }
};
