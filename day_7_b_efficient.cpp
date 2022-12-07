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

void add_sizes(Node* node) {
    for (const auto& child : node->children) {
        add_sizes(child);
        node->size += child->size;
    }
}

void get_size(Node* node, int least_val, int* best_val) {
    for (const auto& child : node->children) {
        if (node->size >= least_val and node->size < *best_val) *best_val = node->size;
        get_size(child, least_val, best_val);
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
        add_sizes(root);
        int best = INT_MAX;
        get_size(root, 30000000 - (70000000 - root->size), &best);
        cout << "the size to delete is : " << best << endl;
    }

}