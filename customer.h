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
    unordered_map <char, Node*> child;
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

            char chr = email[i];
            if (temp->child.count(chr)) {
                temp = temp->child[chr];
            } else {
                Node* node = new Node(chr);
                temp->child[chr] = node;
                temp = node;
            }
        }
        
        temp->check = true;
        count++;
    }

    bool search(string email) {
        Node* temp = root;
        for (int i = 0; email[i] != '@'; i++) {
            if (email[i] == '0') {
                break;
            }

            char chr = email[i];
            if (temp->child.count(chr) == 0) {
                return false;
            }
            
            temp = temp->child[chr];
        }
        
        return temp->check;
    }
};

struct Customer {
    string nama = "0";
    string alamat = "0";
    string email = "0";
    string notelp = "0";
    string password = "0";

    Customer(){

    }

    Customer(string nama, string alamat, string email, string notelp, string password) {
        this->nama = nama;
        this->alamat = alamat;
        this->email = email;
        this->notelp = notelp;
        this->password = password;
    }
};

void readCust(Tree t) {
    fstream f1;
    Customer c;

    f1.open("customer.txt", ios::in||ios::binary);
    do {
        f1.read((char*)&c, sizeof(Customer));
        string email = c.email;
        t.insert(email);
    } while (!f1.eof());

    cout << "Read customer tree" << endl;
    f1.close();
}

bool createAcc(Tree t) {
    string nama;
    string alamat;
    string email;
    string notelp;
    string password;

    cout << "Masukkan nama: ";
    cin >> nama;
    cout << "Masukkan alamat: ";
    cin >> alamat;
    cout << "Masukkan email: ";
    cin >> email;
    cout << "Masukkan nomor telepon: ";
    cin >> notelp;
    cout << "Masukkan password: ";
    cin >> password;

    bool check = t.search(email);
    if (check) {
        cout << "Email sudah digunakan. Coba email lain" << endl;
        return false;
    }
    
    Customer c1(nama, alamat, email, notelp, password);

    fstream f1;
    f1.open("customer.txt", ios::app||ios::binary);
    f1.write((char*)&c1, sizeof(c1));
    f1.close();

    t.insert(email);
    system("clear");
    cout << "Akun berhasil dibuat" << endl;
    return false;
}

struct Booking {
    string nama_cust;
    string email_cust;
    string tanggal;
    string tempat[10] = {"0", "0", "0", "0", "0", "0", "0", "0", "0", "0"};
    int jumlah;
    int banyak_orang;

    Booking(){

    }

    void book(string nama, string email, string tanggal, list<string> tempat, int jumlah, int banyak_orang) {
        this->nama_cust = nama;
        this->email_cust = email;
        this->tanggal = tanggal;
        
    }
};