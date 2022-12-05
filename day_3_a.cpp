//
// Created by Gael Aglin on 01/12/2022.
//
#include <fstream>
#include <iostream>
#include <unordered_set>

using namespace std;

int main(int argc, char* argv[]) {

    string filePath = "../puzzle_3.txt";
    ifstream inFile(filePath, ios_base::in);

    if (inFile.good()) {
        string line;
        int priorities = 0;
        while (getline(inFile, line)) {
            unordered_set<char> chars;
            for (int i = 0; i < line.size() / 2; ++i) {
                chars.insert(line.at(i));
            }
            for (int i = line.size()/2; i < line.size(); ++i) {
                char c = line.at(i);
                if (chars.find(c) != chars.end()){
                    if (int(c) < 97) priorities += int(c) - 64 + 26; //uppercase
                    else priorities += int(c) - 96; //lowercase
                    break;
                }
            }
        }
        cout << "the total of priorities is : " << priorities << endl;
    }

}