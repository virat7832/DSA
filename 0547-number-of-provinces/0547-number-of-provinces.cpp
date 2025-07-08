class Solution {
public:

    void usingDFS(int src, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adjList) {
        // mark visited
        visited[src] = true;

        // call for nbrs
        for (auto nbr : adjList[src]) {
            // nbr not visited
            if (!visited[nbr]) {
                usingDFS(nbr, visited, adjList);
            }
        }
    }

    void usingBFS(int &src, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adjList) {
        
        queue<int> q;
        // init.
        q.push(src);
        visited[src] = true;

        while (!q.empty()) {
            
            // access front
            int frontNode = q.front();
            q.pop();

            // insert nbr of curr node
            for (auto nbr : adjList[frontNode]) {
                // not visited
                if (!visited[nbr]) {
                    q.push(nbr);
                    // mark visited
                    visited[nbr] = true;
                }
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();

        // make adjList
        unordered_map<int, list<int>> adjList;
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                adjList[row];
                adjList[col];
                // not with own node
                if (row != col) {
                    // connected
                    if (isConnected[row][col]) {
                        adjList[row].push_back(col);
                    }
                }
            }
        }

        int provinces = 0;
        
        unordered_map<int, bool> visited;
        // for disconnected component
        for (int i = 0; i < n; i++) {
            // not visited
            if (!visited[i]) {
                // 01 approach - using dfs
                // usingDFS(i, visited, adjList);

                // 02 approach - using bfs
                usingBFS(i, visited, adjList);

                provinces++;
            }
        }
        return provinces;  
    }
};