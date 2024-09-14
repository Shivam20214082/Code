#include <bits/stdc++.h>

using namespace std;
using namespace std;

class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();
        
        // Directions: right, down, left, up
        vector<int> dir = {0, 1, 0, -1, 1, 0, -1, 0};
        
        // Distance matrix to track minimum health cost to reach each cell
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        queue<pair<int, int>> q;
        
        // Start at the top-left corner
        dist[0][0] = grid[0][0];
        q.push({0, 0});
        
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            
            for (int d = 0; d < 4; ++d) {
                int nx = x + dir[2 * d];
                int ny = y + dir[2 * d + 1];
                
                // Check if the next cell is within bounds
                if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                    int newDist = dist[x][y] + grid[nx][ny];
                    
                    // If the new path is better, update the distance and queue it
                    if (newDist < dist[nx][ny]) {
                        dist[nx][ny] = newDist;
                        q.push({nx, ny});
                    }
                }
            }
        }
        
        // Check if we can reach the bottom-right corner with the given health
        return health > dist[m - 1][n - 1];
    }
};
