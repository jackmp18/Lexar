// WIP; works if space is in between in input
// clang++ -std=c++11 -o lexar lexar.cpp
// ./lexar
#include "lexar.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main () {
    std::string filename = "input_scode.txt";
    std::fstream file;
    std::ofstream outputFile;
    std::string word;

    file.open(filename.c_str());
    outputFile.open("output.txt");

    outputFile << "Token" << "                " << "Lexeme" << "\n";
    outputFile << "---------------------------------------" << "\n";

    while (file >> word) {
        lexar(outputFile, word);
    }

    outputFile.close();
    
    return 0;
}