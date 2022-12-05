//
// Created by Gael Aglin on 01/12/2022.
//
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

int main(int argc, char* argv[]) {

    string filePath = "../puzzle_4.txt";
    ifstream inFile(filePath, ios_base::in);

    if (inFile.good()) {
        string line;
        int lbounds[2], ubounds[2], overlap = 0;
        char character;
        while (getline(inFile, line)) {
            stringstream ss(line);
            ss >> lbounds[0] >> character >> ubounds[0] >> character >> lbounds[1] >> character >> ubounds[1];
            if (lbounds[0] == lbounds[1]) overlap++;
            else {
                int min = lbounds[1] < lbounds[0]; // 1
                if (ubounds[min] >= lbounds[-min+1]) overlap++;
            }
        }
        cout << "the number of overlapping assignments is : " << overlap << endl;
    }
}