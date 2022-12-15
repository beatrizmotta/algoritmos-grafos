#include <iostream>
#include <string>

int* handle_flags(int argc, char**argv) {
    using namespace std; 
    string current_command; 

    int vertice_inicial = -1, vertice_final = -1;
    string grafo_entrada, grafo_saida; 

    // Print Solve - Show Help - Output file - Input file 
    static int options[4] = {0, 0, 0, 0};
    for (int i = 1; i < argc; i++) {
        current_command = argv[i];

        if (current_command == "-i") {
            vertice_inicial = atoi(argv[i+1]);
        } else if (current_command == "-l") {
            vertice_final = atoi(argv[i+1]);
        } else if (current_command == "-s") {
            options[0] = 1;
        } else if (current_command == "-h") {
            options[1] = 1; 
        } else if (current_command == "-o") {
            options[2] = 1;
        } else if (current_command == "-f") {
            options[3] = 1;
        }

        
    }


    return options;

        // cout << "Vertice inicial " << vertice_inicial << endl;
        // cout << "Vertice inicial " << vertice_final << endl;
        // cout << "Grafo entrada " << grafo_entrada.length() << endl;
        // cout << "Grafo saida " << grafo_saida.length() << endl;
}

// void handle_flags(int argc, char**argv) {
//     using namespace std; 
//     string current_command; 

//     int vertice_inicial = -1, vertice_final = -1;
//     string grafo_entrada, grafo_saida; 

//     for (int i = 1; i < argc; i++) {
//         current_command = argv[i];

//         if (current_command == "-i") {
//             vertice_inicial = atoi(argv[i+1]);
//         } else if (current_command == "-l") {
//             vertice_final = atoi(argv[i+1]);
//         } else if (current_command == "-s") {
//             cout << "Mostro a solução!" << endl;
//         } else if (current_command == "-h") {
//             cout << "Mostro o help!" << endl;
//         } else if (current_command == "-o") {
//             grafo_saida = argv[i+1];
//         } else if (current_command == "-f") {
//             grafo_entrada = argv[i+1];
//         }

//     }

//         cout << "Vertice inicial " << vertice_inicial << endl;
//         cout << "Vertice inicial " << vertice_final << endl;
//         cout << "Grafo entrada " << grafo_entrada.length() << endl;
//         cout << "Grafo saida " << grafo_saida.length() << endl;
// }