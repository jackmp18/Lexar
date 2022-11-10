#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

//global vector
vector<string> g1;

//used to write to output.txt
void output()
{
    //get vector size
    int vectorsize = g1.size();

    try {
        cout << "\nWriting  array contents to file...";
        //open file for writing
        ofstream fw("C:\\Users\\Jack\\source\\repos\\ConsoleApplication1\\ConsoleApplication1\\output.txt", std::ofstream::out);
        //check if file was successfully opened for writing
        //headers
        fw << "token     lexeme" << "\n";
        int runs = 1;
        if (fw.is_open())
        {
            //store array contents to text file
            for (int i = 0; i < vectorsize; i++) {
                fw << g1[i] << " ";
                if (runs % 2 == 0 && i!= 0) {
                    fw << "\n";
                }
                runs++;
            }
            fw.close();
        }
        else cout << "Problem with opening file";
    }
    catch (const char* msg) {
        cerr << msg << endl;
        cerr << msg << endl;
    }
    cout << "\nDone!";
    cout << "\nPress any key to exit...";
    getchar();
}

void lexer() {
    read();
    int sum = 0;
    int x;
    ifstream inFile;

    inFile.open("test.txt");
    if (!inFile) {
        cout << "Unable to open file";
        exit(1); // terminate with error
    }

    while (inFile >> x) {
        sum = sum + x;
    }

    inFile.close();
    cout << "Sum = " << sum << endl;
}


void read() {
    int sum = 0;
    int x;
    ifstream inFile;

    inFile.open("test.txt");
    if (!inFile) {
        cout << "Unable to open file";
        exit(1); // terminate with error
    }

    while (inFile >> x) {
        sum = sum + x;
    }

    inFile.close();
    cout << "Sum = " << sum << endl;
}

int main() {
    lexer();
    output();
}
