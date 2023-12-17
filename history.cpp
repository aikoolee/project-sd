#include <fstream>
#include <iostream>
#include <cstring>
#include <list>
#include <unordered_map>
#include <cstdlib>

using namespace std;

struct Booking {
    string nama_cust;
    string email_cust;
    string tanggal;
    int biaya;
    int jumlah;
    string nama_agent;

    Booking(){

    }

    void book(string nama, string email, string tanggal, int biaya, int jumlah, string nama_agent) {
        this->nama_cust = nama;
        this->email_cust = email;
        this->tanggal = tanggal;
        this->biaya = biaya * jumlah;
        this->jumlah = jumlah;
        this->nama_agent = nama_agent;
    }

    void print() {
        cout << "Nama customer: " << nama_cust << endl;
        cout << "Email customer: " << email_cust << endl;
        cout << "Tanggal booking: " << tanggal << endl;
        cout << "Jumlah tiket: " << jumlah << endl;
        cout << "Total biaya: " << biaya << endl;
        cout << "Nama agent: " << nama_agent << endl;
    }
};

struct Node {
    Booking data;
    Node* next;
    Node* prev;

    // Constructor
    Node() {
        this -> next = nullptr;
        this->prev = nullptr;
    }

    // Constructor dengan parameter
    Node(Booking value, Node* ptr, Node* ptr2) {
        this -> data = value;
        this -> next = ptr;
        this->prev = ptr2;
    }

    // Destructor
    ~Node() {
        cout << "Node dihapus" << endl;
    }
};

struct DoubleLinkedList {
    Node* head; // head or first or front
    // Node* tail; // tail or last or rear
    int size; // size or length or count

    // Constructor
    DoubleLinkedList(){
        this->head = nullptr;
        size = 0;
    }

    // Add depan
    void insertHead(Booking value) {
        // bikin node baru pakai pointer
        Node* newNode = new Node;
        newNode->data = value;

        // ubah next dari head yang baru jadi head lama
        newNode->next = head;

        // ubah head
        head = newNode;

        // tambahi size
        size++;
    }

    // Add tengah (di index tertentu)
    void insertAtIndex(int index, Booking value) {
        // buat node baru
        Node* newNode = new Node;
        newNode->data = value;

        // ubah next dari head yang baru jadi head lama
        if (index == 0) {
            insertHead(value);
        } else {
            Node* current = head;

            // maju sampai sebelum 1 posisi sebelun index yg dituju
            for (int i = 0; i < index-1 && current != nullptr; i++) {
                current = current->next;
            }
            
            if (current != nullptr) {
                newNode->next = current->next;
                current->next = newNode;
                size++;
            } else {
                cout << "Index out of bound" << endl;
            }
            
        }
        
        // ubah head
        head = newNode;

        // tambahi size
        size++;
    }

    // Add belakang
    void insertBack(Booking value) {
        // buat node baru
        Node* newNode = new Node;
        newNode->data = value;
        
        // kasus khusus ketika LL kosong
        if (head == nullptr) {
            insertHead(value);
        } else { 
            Node* current = head;
            // maju sampai current ada di node paling belakang
            while (current->next != nullptr) {
                current = current->next;
            }    

            // ubah next dari current jadi newNode
            current->next = newNode;
        }

        size++;
    }

    // Display
    void display() {
        Node* current = head;
        while (current != nullptr) {
            current->data.print();
            current = current->next;
            cout << endl;
        }
    }
};

struct Customer {
    string nama;
    string email;
    string alamat;
    string notelp;
    string password;
    DoubleLinkedList history;

    void add(string nama, string email, string alamat, string notelp, string password) {
        this->nama = nama;
        this->email = email;
        this->alamat = alamat;
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

int main() {
    Customer customers[2];
    customers[0].add("Customer1", "customer1@example.com", "jalan1", "123456789", "password1");
    customers[1].add("Customer2", "customer2@example.com", "jalan2", "987654321", "password2");

    Booking booking1;
    booking1.book("Customer1", "customer1@example.com", "12 Januari 2023", 1000, 1, "Agent1");

    for (int i = 0; i < 2; i++) {
        if (customers[i].nama == booking1.nama_cust) {
            customers[i].history.insertBack(booking1);
        }
    }

    Booking booking2;
    booking2.book("Customer1", "customer1@example.com", "12 Januari 2023", 1000, 2, "Agent1");

    for (int i = 0; i < 2; i++) {
        if (customers[i].nama == booking2.nama_cust) {
            customers[i].history.insertBack(booking2);
        }
    }

    Booking booking3;
    booking3.book("Customer1", "customer1@example.com", "12 Januari 2023", 1000, 3, "Agent1");

    for (int i = 0; i < 2; i++) {
        if (customers[i].nama == booking3.nama_cust) {
            customers[i].history.insertBack(booking3);
        }
    }

    Booking booking4;
    booking4.book("Customer1", "customer1@example.com", "12 Januari 2023", 1000, 1, "Agent1");

    for (int i = 0; i < 2; i++) {
        if (customers[i].nama == booking4.nama_cust) {
            customers[i].history.insertBack(booking4);
        }
    }

    Booking booking5;
    booking5.book("Customer2", "customer2@example.com", "12 Januari 2023", 20000, 1, "Agent1");

    for (int i = 0; i < 2; i++) {
        if (customers[i].nama == booking5.nama_cust) {
            customers[i].history.insertBack(booking5);
        }
    }

    Booking booking6;
    booking6.book("Customer2", "customer2@example.com", "12 Januari 2023", 20000, 2, "Agent1");

    for (int i = 0; i < 2; i++) {
        if (customers[i].nama == booking6.nama_cust) {
            customers[i].history.insertBack(booking6);
        }
    }

    for (int i = 0; i < 2; i++) {
        cout << "Booking history for " << customers[i].nama << ":\n";
        customers[i].history.display();
        cout << endl;
    }

    string best_cust = "none";
    int max = -1;
    for (int i = 0; i < 2; i++) {
        if (customers[i].history.size > max) {
            best_cust = customers[i].nama;
            max = customers[i].history.size;
        }
    }
    
    cout << "Best Customer: " << best_cust << endl;
}