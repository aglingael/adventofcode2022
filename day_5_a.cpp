//
// Created by Gael Aglin on 01/12/2022.
//
#include <fstream>
#include <iostream>
#include <deque>
#include <sstream>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {

    string filePath = "../puzzle_5.txt";
    ifstream inFile(filePath, ios_base::in);

    if (inFile.good()) {
        string line, dummy;
        vector<deque<char>> cols;
        bool move_start = false;
        int n_move, start_move, end_move;
        while (getline(inFile, line)) {
            if (line.size() != 0 and not move_start) {
                if (line.at(1) == '1') continue;
                for (int i = 0; i < INT_MAX; ++i) {
                    if (i * 4 + 1 <= line.size() - 1) {
                        if (i > int(cols.size()) - 1) cols.emplace_back();
                        if (line.at(i * 4 + 1) != ' ') cols[i].push_front(line.at(i * 4 + 1));
                    }
                    else break;
                }
            }
            else {
                if (not move_start) {
                    move_start = true;
                    continue;
                }
                // move 1 from 2 to 1
                stringstream ss(line);
                ss >> dummy >> n_move >> dummy >> start_move >> dummy >> end_move;
                for (int i = 0; i < n_move; ++i) {
                    cols[end_move - 1].push_back(cols[start_move - 1].back());
                    cols[start_move - 1].pop_back();
                }
            }
        }
        cout << "the top crates are : ";
        for (auto & col : cols) if (not col.empty()) cout << col.back();
        cout << endl;
    }
}