#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
int n, k;
int max_assigned;

bool isValid(const vector<int>& freq) {
    for (int u = 0; u < n; u++) {
        if (freq[u] == -1) continue;
        
        for (int v : adj[u]) {
            if (freq[v] != -1 && freq[v] == freq[u]) {
                return false;
            }
        }
        
        for (int v : adj[u]) {
            for (int w : adj[v]) {
                if (w != u && freq[w] != -1 && freq[u] != -1 && 
                    abs(freq[w] - freq[u]) < 2) {
                    return false;
                }
            }
        }
    }
    return true;
}

void backtrack(int u, vector<int>& freq, int assigned, vector<bool>& used_freq) {
    if (u == n) {
        if (isValid(freq)) {
            max_assigned = max(max_assigned, assigned);
        }
        return;
    }
    
    if (assigned + (n - u) <= max_assigned) {
        return;
    }
    
    // Option 1: Skip this device
    freq[u] = -1;
    backtrack(u + 1, freq, assigned, used_freq);
    
    // Option 2: Try all possible frequencies for this device
    for (int f = 1; f <= k; f++) {
        if (used_freq[f] && used_freq[max(1, f-1)] && used_freq[min(k, f+1)]) {
            continue;
        }
        
        freq[u] = f;
        
        bool valid = true;
        
        for (int v : adj[u]) {
            if (v < u && freq[v] != -1 && freq[v] == f) {
                valid = false;
                break;
            }
        }
        
        if (!valid) continue;
        
        for (int v : adj[u]) {
            for (int w : adj[v]) {
                if (w < u && w != u && freq[w] != -1 && abs(freq[w] - f) < 2) {
                    valid = false;
                    break;
                }
            }
            if (!valid) break;
        }
        
        if (valid) {
            used_freq[f] = true;
            backtrack(u + 1, freq, assigned + 1, used_freq);
            used_freq[f] = false;
        }
    }
    
    freq[u] = -1;
}

int bruteForce(int n, int k, const vector<pair<int, int>>& edges) {
    ::n = n;
    ::k = k;
    
    adj.assign(n, vector<int>());
    for (auto& edge : edges) {
        int u = edge.first - 1;
        int v = edge.second - 1;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    vector<int> order(n);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&](int a, int b) {
        return adj[a].size() > adj[b].size();
    });
    
    vector<vector<int>> new_adj(n);
    vector<int> mapping(n);
    for (int i = 0; i < n; i++) {
        mapping[order[i]] = i;
    }
    for (int i = 0; i < n; i++) {
        for (int v : adj[i]) {
            new_adj[mapping[i]].push_back(mapping[v]);
        }
    }
    adj = new_adj;
    
    max_assigned = 0;
    vector<int> freq(n, -1);
    vector<bool> used_freq(k + 1, false);
    
    backtrack(0, freq, 0, used_freq);
    
    return max_assigned;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m, k;
    cin >> n >> m >> k;
    
    vector<pair<int, int>> edges(m);
    for (int i = 0; i < m; i++) {
        cin >> edges[i].first >> edges[i].second;
    }
    
    if (n > 12) {
        cerr << "Brute-force not feasible for n > 12" << endl;
        cout << "Brute-force not feasible for n > 12" << endl;
        return 0;
    }
    
    if (k > 10) {
        k = 10; // Limit frequencies for brute force
    }
    
    int result = bruteForce(n, k, edges);
    cout << result << endl;
    
    return 0;
}