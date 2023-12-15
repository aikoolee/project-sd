#include <fstream>
#include <iostream>
#include <cstring>
#include <list>
#include <unordered_map>
#include <cstdlib>
using namespace std;

void loginCust();

struct Node {
    char data;
    map <char, Node*> child;
    bool check;
    Node(char data) {
        this->data = data;
        check = false;
    }
};

struct Tree {
    Node* root;
    int count;
    Tree() {
        root = new Node('0');
        count = 0;
    }

    void insert(string email) {
        Node* temp = root;
        for (int i = 0; email[i] != '@'; i++) {
            if (email[i] == '0'){
                break;
            }
            
        }
        
    }
};