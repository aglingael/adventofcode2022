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
        int lbounds[2], ubounds[2], inclusion = 0;
        char character;
        while (getline(inFile, line)) {
            stringstream ss(line);
            ss >> lbounds[0] >> character >> ubounds[0] >> character >> lbounds[1] >> character >> ubounds[1];
            if (lbounds[0] == lbounds[1]) inclusion++;
            else {
                int max = lbounds[1] > lbounds[0]; // 1
                if (ubounds[max] <= ubounds[-max+1]) inclusion++;
            }
        }
        cout << "the number of including assignments is : " << inclusion << endl;
    }

}