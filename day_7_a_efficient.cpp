//
// Created by Gael Aglin on 01/12/2022.
//
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int size = 0;
    Node* parent;
    vector<Node*> children;

    Node(){
        parent = nullptr;
    }

    explicit Node(Node* parent, int size = 0) {
        this->parent = parent;
        this->size = size;
    }
};

void add_sizes(Node* node, int* val) {
    for (const auto& child : node->children) {
        add_sizes(child, val);
        node->size += child->size;
    }
    if (not node->children.empty()) {
        if (node->size <= 100000) *val += node->size;
    }
}

int main(int argc, char* argv[]) {

    string filePath = "../puzzle_7.txt";
    ifstream inFile(filePath, ios_base::in);

    if (inFile.good()) {
        string line;
        getline(inFile, line);
        Node* root = new Node();
        Node* current = root;
        while (getline(inFile, line)) {
            if (line == "$ ls" or line.substr(0, 3) == "dir") continue;
            else if(line.substr(0, 4) == "$ cd") {
                if (line == "$ cd ..") current = current->parent;
                else { // cd dir
                    Node* child = new Node(current);
                    current = current->children.emplace_back(child);
                }
            }
            else { // file found
                Node* child = new Node(current, stoi(line.substr(0, line.find(' '))));
                current->children.push_back(child);
            }
        }
        int val = 0;
        add_sizes(root, &val);
        cout << "total sum is: " << val << endl;
    }

}