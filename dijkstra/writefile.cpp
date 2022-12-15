#include <iostream> 
#include <string> 
#include <fstream>

using namespace std; 

int main(int argc, char**argv) {
    string filename = argv[1];

    cout << filename;
    ofstream outfile(filename.c_str());
    
    for (int i = 0; i < 9; i++) {
        outfile << i; 
    }

    outfile.close();
    
}