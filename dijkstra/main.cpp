#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include "../argument_handler.cpp"
// -s: print a solução para o usuário
// -i: indica vértice inicial
// -l: indica vértice final

using namespace std;
int dijkstra(vector<vector<int> > &adj, int s);

int main(int argc, char** argv) {
    int vertices, edges;     
    int options[6][2]; 
    handle_flags(argc, argv, options);
    // 0 = print solve | 1 = show help | 2 = output | 3 = input | 4 = vertice inicial | 5 = vertice final
    cout << options[3][0];
    if (options[3][0] == 1) {
        ifstream file;
        string filename = argv[options[3][1]];

        file.open(filename);

        int u, v, peso = INT_MAX; 

        vector<vector<int> > adj(5, vector<int> (5, 0)); ;

        int vertices, arestas; 
        int counter = 0; 

        int fonte = atoi(argv[options[4][1]]);
        int final = atoi(argv[options[5][1]]);

        if (file.is_open()) {
            while (!file.eof()) {
                if (counter == 0) {
                    file >> vertices >> arestas;
                    adj.resize(vertices, vector<int> (vertices, 0));
                    counter++;
                }
                file >> u >> v >> peso; 
                if (peso == INT_MAX) {
                    adj[u][v] = 1; 
                } else {
                    adj[u][v] = peso;
                }
            }
        }

        file.close();

        cout << "Pega porra";

        dijkstra(adj, fonte);



    }

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