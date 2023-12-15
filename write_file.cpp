#include <iostream>
#include <fstream>
#include "Graph.h"
#include "customer.h"
#include "admin.h"
using namespace std;

int main(){
    Admin A[2];
    A[0].add("Helena", "helena@gmail.com", "123", "helenapw");
    A[0].add("Aiko", "aiko@gmail.com", "123", "aikopw");
    fstream f1;
    f1.open("admin.txt", ios::out);
    for (int i = 0; i <= 1; i++) {
        f1.write((char*)&A[i], sizeof(A[i]));
    }
    f1.close();
}