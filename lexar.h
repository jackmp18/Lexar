#include <algorithm>
#include <fstream>
#include <iostream>
#include <regex>
#include <vector>

bool isNumber(std::string const &str) {
    // forgot what I was trying to do here but it works.
    return std::regex_match(str, std::regex("^(-?)(0|([1-9][0-9]*))(\\.[0-9]+)?$"));
}

char isSeperators(std::string str) {
    char cstr = str[0];
    return cstr;
}

char isOperators(std::string str) {
    char cstr = str[0];
    return cstr;
}

void lexar(std::ofstream& oFile, std::string lexeme) {
    std::vector<std::string>::iterator checkKeywords;
    std::vector<char>::iterator checkSeperators;
    std::vector<char>::iterator checkOperators;
    
    // vector of possible keywords, seperators, and operators
    std::vector<std::string> keywords {"bool", "break", "case", "char", "double", 
                                        "float", "if", "int", "void", "while", "last"};
    std::vector<char> seperators {'(', ')', '{', '}', ';'};
    std::vector<char> operators {'+', '-', '*', '/', '='};

    // identifies individual lexeme 
    checkKeywords = std::find(keywords.begin(), keywords.end(), lexeme);
    checkSeperators = std::find(seperators.begin(), seperators.end(), isSeperators(lexeme));
    checkOperators = std::find(operators.begin(), operators.end(), isOperators(lexeme));

    if (checkKeywords != keywords.end()) {
        oFile << "Keyword" << "              " << lexeme << "\n";
    } else if (isNumber(lexeme)) {
        oFile << "Real" << "                 " << lexeme << "\n";
    } else if (checkSeperators != seperators.end()) {
        oFile << "Seperator" << "            " << lexeme << "\n";
    } else if (checkOperators != operators.end()) {
        oFile << "Operator" << "             " << lexeme << "\n";
    } else {
        oFile << "Identifier" << "           " << lexeme << "\n";
    }
}
