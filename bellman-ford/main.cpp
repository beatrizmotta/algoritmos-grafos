#include <iostream>
#include <vector>

using namespace std;
void bellmanford(vector<vector<int> > &adj, int s);

int main() {
    int vertices, edges; 
    cin >> vertices >> edges; 
    vector<vector<int> > adjacencia(edges, vector<int> (3, 0)); 

    for (int i = 0; i < edges; i++) {
        int u, v, peso; 
        cin >> u >> v >> peso;
        adjacencia[i] = {u, v, peso};
    }

    bellmanford(adjacencia, 0);

    return 0; 
}

void bellmanford(vector<vector<int> > &adj, int s) {

    int n = adj.size();
    int m = adj[0].size(); 
    vector<int> dist (n, INT_MAX);

    dist[s] = 0; 

    // Processo de relaxamento das arestas no máximo v - 1 vezes. 
    for (int i = 1; i < n - 1; i++) {

        for (int j = 0; j < m; j++) {

           if (
                dist[adj[j][0]] != INT_MAX &&
                dist[adj[j][0]] + adj[j][2] < dist[adj[j][1]]
           ) {
                dist[adj[j][1]] = dist[adj[j][0]] + adj[j][2];
           }

        }

    }

    // Checagem ciclo negativo

    for (int i = 0; i < m; i++) {
        int v1 = adj[i][0];
        int v2 = adj[i][1];
        int peso = adj[i][2];

        if (dist[v1] != INT_MAX && 
            dist[v1] + peso < dist[v2]
        ) {
            cout << "Esse grafo possui um ciclo negativo\n";
        }

    }

    for (int number : dist) {
        cout << number << '\n'; 
    }


}