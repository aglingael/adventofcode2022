//
// Created by Gael Aglin on 01/12/2022.
//
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>

using namespace std;

struct Node {
    int size = 0;
    Node* parent;
    map<string,Node*> children;

    Node(){
        parent = nullptr;
    }

    explicit Node(Node* parent) {
        this->parent = parent;
    }
};

void add_sizes(Node* node) {
    for (const auto& child : node->children) {
        add_sizes(child.second);
        node->size += child.second->size;
    }
}

void get_size(Node* node, const string& name, int least_val, int* best_val) {
    for (const auto& child : node->children) {
        if (node->size >= least_val and node->size < *best_val) *best_val = node->size;
        get_size(child.second, child.first, least_val, best_val);
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
            if (line == "$ ls") continue;
            else if (line.substr(0, 3) == "dir") {
                Node* child = new Node(current);
                current->children.insert({line.substr(4, line.size() - 4), child});
            }
            else if(line.substr(0, 4) == "$ cd") {
                if (line == "$ cd ..") {
                    current = current->parent;
                }
                else { // cd dir
                    current = current->children[line.substr(5, line.size() - 5)];
                }
            }
            else { // file found
                stringstream ss(line);
                int size_ = 0;
                string filename;
                ss >> size_ >> filename;
                Node* child = new Node(current);
                child->size = size_;
                current->children.insert({filename, child});
            }
        }
        add_sizes(root);
        int best = INT_MAX;
        get_size(root, "/", 30000000 - (70000000 - root->size), &best);
        cout << "the size to delete is : " << best << endl;
    }

}