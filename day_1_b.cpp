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

    int first_load = -1, second_load = -1, third_load = -1;

    if (inFile.good()) {
        string line;
        int load = 0;

        while (getline(inFile, line)) {
            if (line.length() != 0) {
                load += stoi(line);
            }
            if (line.length() == 0 or inFile.eof()) {
                if (load > first_load) {
                    third_load = second_load;
                    second_load = first_load;
                    first_load = load;
                }
                else if (load > second_load and load != first_load) {
                    third_load = second_load;
                    second_load = load;
                }
                else if (load > third_load and load != second_load) {
                    third_load = load;
                }
                load = 0;
            }
        }

        cout << "the total load of top 3 loaded elves is : " << first_load + second_load + third_load << " calories" << endl;

    }

}