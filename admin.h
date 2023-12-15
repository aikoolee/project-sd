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
    f1.open("admin.txt", ios::in);
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

void viewCustomer() {
    cout < "---------- VIEW CUSTOMER ----------" << endl;

    int total = 0;
    ifstream f1;
    Customer c1;
    f1.open("customer.txt", ios::in);
    f1.read((char*)&c1, sizeof(Customer));

    while (!f1.eof()) {
        cout << left;
        cout << c1.name << " - " << c1.address << " - " << c1.notelp << " - " << c1.email << endl;
        total++;
        f1.read((char*)&c1, sizeof(Customer));
    }
    
    cout << "Total customers: " << total << endl;
    f1.close();
}

void viewBooking() {
    cout < "---------- VIEW BOOKING ----------" << endl;

    int total = 0;
    ifstream f1;
    Booking b1;
    f1.open("booking.txt", ios::in);
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