// Qwen Attempt 3 - Maximum independent set on conflict graph (will fail)
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    vector<vector<bool>> conflict(n + 1, vector<bool>(n + 1, false));
    
    for (int u = 1; u <= n; u++) {
        for (int v : adj[u]) {
            conflict[u][v] = true;
            conflict[v][u] = true;
        }
        
        for (int v = 1; v <= n; v++) {
            if (u == v) continue;
            for (int w : adj[u]) {
                if (find(adj[v].begin(), adj[v].end(), w) != adj[v].end()) {
                    conflict[u][v] = true;
                    conflict[v][u] = true;
                    break;
                }
            }
        }
    }
    
    vector<bool> inSet(n + 1, true);
    vector<int> degree(n + 1, 0);
    
    for (int u = 1; u <= n; u++) {
        for (int v = 1; v <= n; v++) {
            if (conflict[u][v]) degree[u]++;
        }
    }
    
    bool changed = true;
    while (changed) {
        changed = false;
        int max_degree = -1, max_node = -1;
        for (int u = 1; u <= n; u++) {
            if (inSet[u] && degree[u] > max_degree) {
                max_degree = degree[u];
                max_node = u;
            }
        }
        
        if (max_node != -1) {
            inSet[max_node] = false;
            changed = true;
            for (int v = 1; v <= n; v++) {
                if (conflict[max_node][v] && inSet[v]) {
                    degree[v]--;
                }
            }
        }
    }
    
    int count = 0;
    for (int u = 1; u <= n; u++) {
        if (inSet[u]) count++;
    }
    
    cout << count << endl;
    return 0;
}