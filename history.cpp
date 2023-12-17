#include <fstream>
#include <iostream>
#include <cstring>
#include <list>
#include <unordered_map>
#include <cstdlib>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;

    // Constructor
    Node() {
        this -> data = 0;
        this -> next = nullptr;
        this->prev = nullptr;
    }

    // Constructor dengan parameter
    Node(int value, Node* ptr, Node* ptr2) {
        this -> data = value;
        this -> next = ptr;
        this->prev = ptr2;
    }

    // Destructor
    ~Node() {
        cout << "Node " << this->data << " dihapus" << endl;
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
    void insertHead(int value) {
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
    void insertAtIndex(int index, int value) {
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
    void insertBack(int value) {
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

    // Remove head : menghapus node di head
    void removeHead() {
        // kalau linked list kosong
        if (head == nullptr) {
            cout << "Linked list kosong, tidak ada yang dihapus" << endl;
            return;
        }

        // kalau linked list ga kosong
        Node* removeNode = head;

        // ubah head
        head = head->next;

        // delete
        delete removeNode;

        // kurangi size
        size--;
    }

    // Remove di Index
    void removeAtIndex(int index){
        // kalau linked list kosong
        if (head == nullptr) {
            cout << "Linked list kosong, tidak ada yang dihapus" << endl;
            return;
        }

        // kasus khusus : remove index 0 = remove head
        if (index == 0) {
            removeHead();
        } else {
            // jika isi linked list lebih dari 1
            Node* current = head;
            Node* previous = nullptr;
            int currentIndex = 0;

            // maju sampai node terakhir linked list
            while (current != nullptr && currentIndex < index) {
                previous = current;
                current = current->next;
                currentIndex++;
            }

            if (current != nullptr) {
                // delete node tengah
                previous->next = current->next;
                delete current;

                // kurangi size
                 size--;
            } else {
                cout << "Index out of bound" << endl;
            }
        }
    }

    // Remove Belakang
    void removeBack(){
        // kalau linked list kosong
        if (head == nullptr) {
            cout << "Linked list kosong, tidak ada yang dihapus" << endl;
            return;
        }

        // kalau linked list ga kosong
        // kasus khusus : isi linkedlist cuman 1
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            size--;
            return;
        }
        
        // jika isi linked list lebih dari 1
        Node* current = head;
        Node* previous = nullptr;

        // maju sampai node terakhir linked list
        while (current->next != nullptr) {
            previous = current;
            current = current->next;
        }
        
        // delete node terakhir
        previous->next = nullptr;
        delete current;

        // kurangi size
        size--;
    }

    // Display
    void display() {
        cout << "Print" << endl;
        Node* current = head;

        // kalau current sudah sampai null ptr, berarti sudah sampai paling belakang
        while (current != nullptr) {
            cout << current->data << endl;
            if (current->next != nullptr) {
                cout << "Next: " << current->next->data << endl;
            } else {
                cout << "Next is null" << endl;
            }
            current = current->next;
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

int main() {
    Customer customers[2];
    customers[0].add("Customer1", "customer1@example.com", "jalan1", "123456789", "password1");
    customers[1].add("Customer2", "customer2@example.com", "jalan2", "987654321", "password2");

    Booking booking
}