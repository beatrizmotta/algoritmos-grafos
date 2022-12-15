#include <iostream>
#include <string>
#include <cstdlib>
#include "../argument_handler.cpp"

/*
h - help
o - redireciona a saída pra um arquivo
f - indica o arquivo com o grafo de entrada 
s - mostra a solução 
i - indica o vértice inicial 
l - indica o vértice final 
*/
using namespace std; 

// void handle_flags(int argc, char**argv) {
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

int main(int argc, char**argv) {
    
    handle_flags(argc, argv);


}