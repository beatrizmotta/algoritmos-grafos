#include <iostream>
#include <cstdlib>

/*
h - help
o - redireciona a saída pra um arquivo
f - indica o arquivo com o grafo de entrada 
s - mostra a solução 
i - indica o vértice inicial 
l - indica o vértice final 

*/

int main(int argc, char**argv) {
    int vertice_inicial, vertice_final; 
    for (int i = 0; i < argc; ++i) {
        
        // Means it's a flag
        if (argv[i][0] == '-') {
            char flag = argv[i][1];

            switch (flag)
            {
            case 'i':
                vertice_inicial = argv[i+1][0];
                std::cout << atoi(argv[i+1]) << '\n';
                // std::cout << vertice_inicial << "\n";
                break;
            case 'l':
                vertice_final = argv[i+1][0];
                std::cout << atoi(argv[i+1]);
                // std::cout << vertice_final;
                break;
            case 's':
                std::cout << "Você escolheu solve";
                break;
            default:
                break;
            }


        }
    }
    return 0;
}