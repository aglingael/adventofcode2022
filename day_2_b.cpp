//
// Created by Gael Aglin on 01/12/2022.
//
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char* argv[]) {

    string filePath = "../puzzle_2_b.txt";
    ifstream inFile(filePath, ios_base::in);

    int score = 0;

    if (inFile.good()) {
        string line;

        while (getline(inFile, line)) {

            if (line.at(0) == 'A') {
                if (line.at(2) == 'Z')  score += 2 + 6;
                else if (line.at(2) == 'X') score += 3 + 0;
                else score += 1 + 3;
            }
            else if (line.at(0) == 'B') {
                if (line.at(2) == 'Z')  score += 3 + 6;
                else if (line.at(2) == 'X') score += 1 + 0;
                else score += 2 + 3;
            }
            else { // first plays C
                if (line.at(2) == 'Z')  score += 1 + 6;
                else if (line.at(2) == 'X') score += 2 + 0;
                else score += 3 + 3;
            }
        }

        cout << "the total score is : " << score << endl;

    }

}