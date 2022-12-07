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

void add_sizes(Node* node, const string& name, int* val) {
    for (const auto& child : node->children) {
        add_sizes(child.second, child.first, val);
        node->size += child.second->size;
    }
    if (not node->children.empty()) {
        cout << "dir: " << name << " size: " << node->size << endl;
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
        int val = 0;
        add_sizes(root, "/", &val);
        cout << "total sum is: " << val << endl;
    }

}