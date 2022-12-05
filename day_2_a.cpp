//
// Created by Gael Aglin on 01/12/2022.
//
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char* argv[]) {

    string filePath = "../puzzle_2.txt";
    ifstream inFile(filePath, ios_base::in);

    int score = 0;

    if (inFile.good()) {
        string line;

        while (getline(inFile, line)) {

            if (line.at(2) == 'X') {
                if (line.at(0) == 'C')  score += 1 + 6;
                else if (line.at(0) == 'B') score += 1 + 0;
                else score += 1 + 3;
            }
            else if (line.at(2) == 'Y') {
                if (line.at(0) == 'A')  score += 2 + 6;
                else if (line.at(0) == 'C') score += 2 + 0;
                else score += 2 + 3;
            }
            else { // play Z
                if (line.at(0) == 'B')  score += 3 + 6;
                else if (line.at(0) == 'A') score += 3 + 0;
                else score += 3 + 3;
            }
        }

        cout << "the total score is : " << score << endl;

    }

}