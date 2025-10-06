// Qwen Attempt 2 - Enhanced with triangle detection (will fail)
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
    
    bool has_triangle = false;
    for (int u = 1; u <= n; u++) {
        for (int v : adj[u]) {
            if (v > u) {
                for (int w : adj[u]) {
                    if (w > v && find(adj[v].begin(), adj[v].end(), w) != adj[v].end()) {
                        has_triangle = true;
                        break;
                    }
                }
                if (has_triangle) break;
            }
        }
        if (has_triangle) break;
    }
    
    if (has_triangle && k < 3) {
        cout << n - 1 << endl;
        return 0;
    }
    
    vector<int> freq(n + 1, 0);
    vector<bool> assigned(n + 1, false);
    int count = 0;
    
    for (int i = 1; i <= n; i++) {
        if (assigned[i]) continue;
        
        queue<int> q;
        q.push(i);
        assigned[i] = true;
        
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            
            vector<bool> used(k + 1, false);
            for (int v : adj[u]) {
                if (freq[v] != 0) {
                    used[freq[v]] = true;
                    if (freq[v] > 1) used[freq[v] - 1] = true;
                    if (freq[v] < k) used[freq[v] + 1] = true;
                }
            }
            
            int chosen = -1;
            for (int f = 1; f <= k; f++) {
                if (!used[f]) {
                    chosen = f;
                    break;
                }
            }
            
            if (chosen != -1) {
                freq[u] = chosen;
                count++;
            }
            
            for (int v : adj[u]) {
                if (!assigned[v]) {
                    assigned[v] = true;
                    q.push(v);
                }
            }
        }
    }
    
    cout << count << endl;
    return 0;
}