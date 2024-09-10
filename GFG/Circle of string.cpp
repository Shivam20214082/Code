#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    void dfs(int v, vector<vector<int>>& adj, vector<bool>& visited) {
        visited[v] = true;
        for (int u : adj[v]) {
            if (!visited[u]) {
                dfs(u, adj, visited);
            }
        }
    }
    
    bool isConnected(vector<vector<int>>& adj, vector<vector<int>>& reverseAdj, int start, vector<bool>& visited) {
        // Perform DFS on the original graph
        dfs(start, adj, visited);
        
        // Check if all nodes with edges are visited
        for (int i = 0; i < 26; i++) {
            if (!visited[i] && !adj[i].empty()) {
                return false;
            }
        }
        
        // Reset visited array
        visited.assign(26, false);
        
        // Perform DFS on the reverse graph
        dfs(start, reverseAdj, visited);
        
        // Check again if all nodes with edges are visited in the reverse graph
        for (int i = 0; i < 26; i++) {
            if (!visited[i] && !reverseAdj[i].empty()) {
                return false;
            }
        }
        
        return true;
    }

    int isCircle(vector<string> &arr) {
        vector<int> in(26, 0), out(26, 0); // Arrays to store in-degrees and out-degrees
        vector<vector<int>> adj(26), reverseAdj(26); // Adjacency lists for graph and reverse graph

        // Construct the graph and reverse graph
        for (string& s : arr) {
            int start = s[0] - 'a';
            int end = s.back() - 'a';
            adj[start].push_back(end);
            reverseAdj[end].push_back(start);
            out[start]++;
            in[end]++;
        }

        // Check if in-degree equals out-degree for all nodes
        for (int i = 0; i < 26; i++) {
            if (in[i] != out[i]) {
                return 0; // If in-degree != out-degree, it's not possible to form a circle
            }
        }

        // Find a starting node with a non-zero degree
        int start = -1;
        for (int i = 0; i < 26; i++) {
            if (!adj[i].empty()) {
                start = i;
                break;
            }
        }

        // If there's no starting node, it means there are no edges
        if (start == -1) {
            return 0;
        }

        // Check if the graph is strongly connected
        vector<bool> visited(26, false);
        if (!isConnected(adj, reverseAdj, start, visited)) {
            return 0; // Not strongly connected
        }

        return 1; // All conditions are satisfied, so a circle can be formed
    }
};
