#include <iostream>
#include <string>

using namespace std;

void change(int argc, char**argv, int config[6][2]) {
    string current_command;
    for (int i = 1; i < argc; i++)
    {

        current_command = argv[i];

        if (current_command == "-i")
        {
            config[4][0] = 1;
            config[4][1] = i + 1;
        }
        else if (current_command == "-l")
        {
            config[5][0] = 1;
            config[5][1] = i + 1;
            // vertice_final = atoi(argv[i+1]);
        }
        else if (current_command == "-s")
        {
            config[0][0] = 1;
        }
        else if (current_command == "-h")
        {
            config[1][0] = 1;
        }
        else if (current_command == "-o")
        {
            config[2][0] = 1;
            config[2][1] = i + 1;
        }
        else if (current_command == "-f")
        {
            config[3][0] = 1;
            config[3][1] = i + 1;
        }
    }
}

int main(int argc, char **argv)
{

    int options[6][2];
    change(argc, argv, options);

    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 2; j++) {
            cout << options[i][j] << " "; 
        }
        cout << "\n";
    }
}