#include <iostream>
#include <vector>

using namespace std; 
void print_solve(vector<vector<int> > &matriz);
void floydwarshall(vector<vector<int> > &adj);

int main() {
    int vertices, edges; 
    cin >> vertices >> edges; 
    vector<vector<int> > adjacencia(vertices, vector<int> (vertices, INT_MAX));



    for (int i = 0; i < edges; i++) {
        int u, v, peso; 
        cin >> u >> v >> peso;
        adjacencia[i][i] = 0;
        adjacencia[u][v] = peso;
    }

    // for (int i = 0; i < vertices; i++) {
    //     for (int j = 0; j < vertices; j++) {
    //         cout << adjacencia[i][j] << " ";
    //     }
    //     cout << '\n';
    // }

    floydwarshall(adjacencia);

    return 0; 
}

void floydwarshall(vector<vector<int> > &adj) {
    int i, j, k;
    int n = adj.size();
    vector<vector<int> > matriz(n, vector<int> (n));

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            matriz[i][j] = adj[i][j]; // Copiando 
        }
    }

    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {

                if (matriz[i][k] != INT_MAX && matriz[k][j] != INT_MAX
                && matriz[i][k] + matriz[k][j] < matriz[i][j]) {
                    matriz[i][j] = matriz[i][k] + matriz[k][j];
                }

                // if (matriz[i][k] + matriz[k][j] < matriz[i][j]) {
                //     matriz[i][j] = matriz[i][k] + matriz[k][j];
                // }

            }
        }
    }


    for (i = 0; i < n; i++) {
        if (matriz[i][i] < 0) {
            cout << "Esse grafo possui um ciclo negativo\n";
            break; 
        }
    }

    print_solve(matriz);
   
}

void print_solve(vector<vector<int> > &matriz) {
    int n = matriz.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matriz[i][j] == INT_MAX) {
                cout << "inf ";
            } else {
                cout << matriz[i][j] << " ";
            }
        }
        cout << '\n';
    }
    
}