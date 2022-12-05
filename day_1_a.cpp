//
// Created by Gael Aglin on 01/12/2022.
//
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char* argv[]) {

    string filePath = "../puzzle_1.txt";
    ifstream inFile(filePath, ios_base::in);

    int highest_load = -1;

    if (inFile.good()) {
        string line;
        int load = 0;

        while (getline(inFile, line)) {
            if (line.length() != 0) {
                load += stoi(line);
            }
            if (line.length() == 0 or inFile.eof()) {
                if (load > highest_load) {
                    highest_load = load;
                }
                load = 0;
            }
        }

        cout << "the most loaded elf carries " << highest_load << " calories" << endl;

    }

}