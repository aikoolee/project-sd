#include <iostream>
#include <fstream>
#include "Graph.h"
#include "customer.h"
#include "admin.h"
using namespace std;

int main(){
    Admin A[2];
    A[0].add("Helena", "helena@gmail.com", "123", "helenapw");
    A[1].add("Aiko", "aiko@gmail.com", "456", "aikopw");
    fstream f1;
    f1.open("admin.txt", ios::out);
    for (int i = 0; i <= 1; i++) {
        f1.write((char*)&A[i], sizeof(A[i]));
    }
    f1.close();

    Agent G[3];
    G[0].add("Ana", "ana@gmail.com", "321");
    G[1].add("Rina", "rina@gmail.com", "654");
    G[2].add("Adi", "adi@gmail.com", "987");
    fstream f2("agent.txt", ios::out);
    for (int i = 0; i <= 1; i++) {
        f1.write((char*)&G[i], sizeof(G[i]));
    }
    f1.close();
}