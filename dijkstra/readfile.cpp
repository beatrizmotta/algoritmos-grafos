#include <iostream>
#include <fstream>
#include <vector> 
#include <string> 

using namespace std;

int main(int argc, char**argv) {
    ifstream file;
    string filename = argv[1];

    file.open(filename);

    int u, v, peso = INT_MAX; 

    vector<vector<int> > adj(5, vector<int> (5, 0)); ;

    int vertices, arestas; 
    int counter = 0; 
    if (file.is_open()) {
        while (!file.eof()) {
            if (counter == 0) {
                file >> vertices >> arestas;
                counter++;
            }
            file >> u >> v >> peso; 
            adj[u][v] = peso; 
        }
    }

    cout << vertices << " " << arestas;

    file.close(); 
    
    
    
    // string filename = "bia.txt";
    // ifstream file(filename);

    // vector<vector<int> > adj (10, vector <int> ());

    // int u, v;
    // string line;  
    // while (getline(file, line)) {
    //     line >> u >> v;
    // }
    // return 0; 


    // ifstream file;
    // file.open(filename);

    // if (file.fail()) {
    //     return 1; 
    // }

    // int i = 0;
    // string line; 
    // while (!file.eof()) {
    //     i++;
    //     getline(file, line);
         
    // }
    
    // file.close();





    // for (int i = 0; i < names.size(); i++) {
    //     cout << names[i] << endl;
    // }

    // for (int i = 0; i < argc; i++) {
    //     char * file;
    //     file = argv[i];
        
    //     cout << file; 

    //     ifstream fileReader; 
    //     fileReader.open(file);

    //     if (!fileReader.is_open()) {
    //         exit(EXIT_FAILURE);
    //     } else {
    //         char word[50];
    //         fileReader >> word;
    //         while(fileReader.good()) {
    //             cout << word << " ";
    //             fileReader >> word; 
    //         }
    //         system("pause");
    
    //     }
    // }


}