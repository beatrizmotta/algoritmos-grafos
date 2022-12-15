#include <iostream>
#include <vector> 

using namespace std; 

int main() {
    int vertices, edges; 
    cin >> vertices >> edges; 
    vector<vector<int> > adjacencia(vertices, vector<int> (vertices, -1));

    for (int i = 0; i < edges; i++) {
        int u, v, peso; 
        cin >> u >> v >> peso;
        adjacencia[i][i] = 0;
        adjacencia[u][v] = peso;
    }

    return 0;
}

int min(vector<int> &key, vector<bool> visited) {
    
    int minimum = INT_MAX;
    int index; 
    int n = visited.size();

    for (int i = 0; i < n; i++) {
        if (visited[i] == false &&
            key[i] < minimum) {
                minimum = key[i];
                index = i; 
            }
    }

    return index; 
}

void prim(vector<vector<int> > &adj, int s) {
    int n = adj.size();

    vector<int> pai(n, -1);
    vector<int> key(n, INT_MAX);
    vector<bool> visited(n, false);

    key[s] = 0;
    pai[0] = -1;

    for (int i = 0; i < n - 1; i++) {

        int u = min(key, visited);
        visited[u] = true; 

        for (int j = 0; j < n; j++) {
            if (adj[u][j] != 0 && visited[j] == false
            && adj[u][j] < key[j]) {
                pai[j] = u;
                key[j] = adj[u][j];
            }
        }

    }


}