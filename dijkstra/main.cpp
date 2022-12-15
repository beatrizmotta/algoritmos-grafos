#include <iostream>
#include <vector>
// -s: print a solução para o usuário
// -i: indica vértice inicial
// -l: indica vértice final

using namespace std;
int dijkstra(vector<vector<int> > &adj, int s);

int main() {
    int vertices, edges; 
    cin >> vertices >> edges; 
    vector<vector<int> > adjacencia(vertices, vector<int> (vertices, 0)); 

    for (int i = 0; i < edges; i++) {
        int u, v, peso; 
        cin >> u >> v >> peso;

        // Grafo não direcionado e não serve pesos negativos

        adjacencia[u][v] = peso; 
        adjacencia[v][u] = peso; 
    }

    dijkstra(adjacencia, 0);

    return 0;
}

// Função para achar o vértice com menor distância atual
// que ainda não foi visitado
int min(vector<int> &dist, vector<bool> &visited) {

    int mininum = INT_MAX;
    int index; 

    for (int i = 0; i < dist.size(); i++) {

        if (visited[i] == false && dist[i] <= mininum) {
            mininum = dist[i];
            index = i; 
        }

    }

    return index; 

}

int dijkstra(vector<vector<int> > &adj, int s) {
    int size = adj.size();
    vector<int> dist (size, INT_MAX); 
    vector<bool> visited (size, false); 

    dist[s] = 0; 

    for (int i = 0; i < size; i++) {
        int m = min(dist, visited);
        visited[m] = true; 

        for (int j = 0; j < size; j++) {

            if (!visited[j] &&
                adj[m][j] && dist[m] != INT_MAX
                && dist[m] + adj[m][j] < dist[j]
            ){
                dist[j] = dist[m] + adj[m][j];
            }

        }

    }

    for (int i = 0; i < size; i++) {
        cout << dist[i] << "\n";
    }

}