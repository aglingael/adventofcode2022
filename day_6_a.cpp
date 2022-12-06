//
// Created by Gael Aglin on 01/12/2022.
//
#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {

    string filePath = "../puzzle_6.txt";
    ifstream inFile(filePath, ios_base::in);

    if (inFile.good()) {
        string line;
        getline(inFile, line);
        for (int i = 0; i < line.size(); ++i) {
            int mask = 0; // assuming all character are lowercase, 26 bits are needed at most. So an int is perfect
            bool found = true;
            for (int j = i; j < i + 4; ++j) {
                int shift = line.at(j) - 'a';
                if ((mask & (1 << shift)) > 0) {
                    found = false;
                    break;
                }
                mask |= 1 << shift;
            }
            if (found) {
                cout << "pos = " << i + 4 << endl;
                break;
            }
        }
    }

}