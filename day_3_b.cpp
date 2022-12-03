//
// Created by Gael Aglin on 01/12/2022.
//
#include <fstream>
#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[]) {

    string filePath = "../puzzle_3_b.txt";
    ifstream inFile(filePath, ios_base::in);

    if (inFile.good()) {
        int priorities = 0;
        vector<string> lines;
        lines.reserve(3);
        int line_num = 0;
        string line;
        while (getline(inFile, line)) {
            line_num++;
            if (line_num % 3 != 0) lines.push_back(line);
            else {
                lines.push_back(line);
                unordered_set<char> chars;
                unordered_set<char> chars2;
                for (char c : lines[0]) chars.insert(c);
                for (char c : lines[1]) if (chars.find(c) != chars.end()) chars2.insert(c);
                for (char c : lines[2]) {
                    if (chars2.find(c) != chars2.end()){
                        if (int(c) < 97) priorities += int(c) - 64 + 26; //uppercase
                        else priorities += int(c) - 96; //lowercase
                        break;
                    }
                }
                lines.clear();
            }
        }
        cout << "the total of priorities is : " << priorities << endl;
    }
}