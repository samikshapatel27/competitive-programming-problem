#include <bits/stdc++.h>
using namespace std;

int main() {
    srand(time(0));
    
    int test_cases = 6;
    
    for (int tc = 1; tc <= test_cases; tc++) {
        string filename = "test_cases/" + to_string(tc) + ".in";
        ofstream out(filename);
        
        if (tc == 1) {
            // Cycle of length 4
            out << "4 4 3\n1 2\n2 3\n3 4\n4 1\n";
        } else if (tc == 2) {
            // Path graph
            out << "5 4 2\n1 2\n2 3\n3 4\n4 5\n";
        } else if (tc == 3) {
            // Triangle
            out << "3 3 2\n1 2\n2 3\n1 3\n";
        } else if (tc == 4) {
            // Complex graph with triangle
            out << "6 7 4\n1 2\n1 3\n2 3\n2 4\n3 5\n4 5\n5 6\n";
        } else if (tc == 5) {
            // Minimal case with k=1
            out << "2 1 1\n1 2\n";
        } else if (tc == 6) {
            // Single node
            out << "1 0 5\n";
        }
        
        out.close();
    }
    
    return 0;
}