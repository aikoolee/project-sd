#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cstring>

using namespace std;

struct Admin {
    string nama;
    string email;
    string notelp;
    string password;

    void add(string nama, string email, string notelp, string password) {
        this->nama = nama;
        this->email = email;
        this->notelp = notelp;
        this->password = password;
    }

    bool login(string nama, string password) {
        if (nama == this->nama && password == this->password) {
            cout << "Login success" << endl;
            return true;
        }
        return false;
    }
};

void readAdmin(Admin A[]) {
    ifstream f1;
    f1.open("admins.txt", ios::in);
    int i = 0;
    while (!f1.eof()) {
        f1.read((char*)&A[i], sizeof(Admin));
        i++;
    }
    cout << "Read admin information" << endl;
    f1.close();
}

bool loginAdmin(Admin A[], int n = 2) {
    string nama;
    cout << "Masukkan nama: ";
    cin >> nama;

    string password;
    cout << "Masukkan password: ";
    cin >> password;

    for (int i = 0; i < n; i++) {
        bool check = A[i].login(nama, password);
        if (check) {
            return true;
        }
    }
    
    return false;
}

struct Agent {
    string nama;
    string email;
    string notelp;

    Agent() {
    
    }

    Agent(string nama, string email, string notelp) {
        this->nama = nama;
        this->email = email;
        this->notelp = notelp;
    }

    void add (string nama, string email, string notelp) {
        this->nama = nama;
        this->email = email;
        this->notelp = notelp;
    }

    string getNama() {
        return nama;
    }
};

void readAgent(Agent A[], int &count) {
    count = 0;
    ifstream f1;
    f1.open("agents.txt", ios::in);
    int i = 0;
    f1.read((char*)&A[i], sizeof(Agent));

    while (!f1.eof()) {
        i++;
        f1.read((char*)&A[i], sizeof(Agent));
    }

    cout << "Read agent" << endl;
    count = i;
    f1.close();
}

string assign(Agent A[], int no = 10) {
    int c = rand()%(no-1);
    return A[c].getNama();
}

void viewCustomer() {
    cout << "---------- VIEW CUSTOMER ----------" << endl;

    int total = 0;
    ifstream f1;
    Customer c1;
    f1.open("customers.txt", ios::in);
    f1.read((char*)&c1, sizeof(Customer));

    while (!f1.eof()) {
        cout << left;
        cout << c1.nama << " - " << c1.alamat << " - " << c1.notelp << " - " << c1.email << endl;
        total++;
        f1.read((char*)&c1, sizeof(Customer));
    }
    
    cout << "Total customers: " << total << endl;
    f1.close();
}

void viewBooking() {
    cout << "---------- VIEW BOOKING ----------" << endl;

    int total = 0;
    ifstream f1;
    Booking b1;
    f1.open("bookings.txt", ios::in);
    f1.read((char*)&b1, sizeof(Booking));
    while (!f1.eof()) {
        b1.print();
        cout << endl;
        f1.read((char*)&b1, sizeof(Booking));
        total++;
    }
    
    cout << "Total bookings: " << total << endl;
    f1.close();
}

class Edge;
class GraphInt;
class GraphFloat;

bool add_edge(GraphInt &g1, GraphFloat &g2) {
    char a[30], b[30];
    int cost;
    float time;

    cout << "Masukkan lokasi awal: ";
    cin >> a;

    cout << "Masukkan lokasi tujuan: ";
    cin >> b;

    cout << "Masukkan biaya: ";
    cin >> cost;

    cout << "Masukkan jadwal keberangkatan: ";
    cin >> time;

    Edge e(a, b, cost, time);
    fstream f3;
    f3.open("places.txt", ios::app);
    f3.write((char*)&e, sizeof(e));
    f3.close();

    g1.addEdge(a, b, cost);
    g2.addEdge(a, b, time);
    cout << "Jadwal berhasil ditambahkan" << endl;
    return true;
}