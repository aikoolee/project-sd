#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

// --- ADMIN ---

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

bool loginAdmin(Admin A[], int n) {
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

// --- AGENT ---

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

// --- CUSTOMER ---

struct treeNode {
    char data;
    unordered_map <char, treeNode*> child;
    bool check;
    treeNode(char data) {
        this->data = data;
        check = false;
    }
};

struct Tree {
    treeNode* root;
    int count;
    Tree() {
        root = new treeNode('0');
        count = 0;
    }

    void insert(string email) {
        treeNode* temp = root;
        for (int i = 0; email[i] != '@'; i++) {
            if (email[i] == '0'){
                break;
            }

            char chr = email[i];
            if (temp->child.count(chr)) {
                temp = temp->child[chr];
            } else {
                treeNode* node = new treeNode(chr);
                temp->child[chr] = node;
                temp = node;
            }
        }
        
        temp->check = true;
        count++;
    }

    bool search(string email) {
        treeNode* temp = root;
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
    string nama;
    string email;
    string alamat;
    string notelp;
    string password;

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

bool loginCustomer(Customer C[], int n) {
    string nama;
    cout << "Masukkan nama: ";
    cin >> nama;

    string password;
    cout << "Masukkan password: ";
    cin >> password;

    for (int i = 0; i < n; i++) {
        bool check = C[i].login(nama, password);
        if (check) {
            return true;
        }
    }
    
    return false;
}

int main() {
    cout << "Menu:" << endl;
    cout << "1. Login Admin" << endl;
    cout << "2. Login Customer" << endl;
    cout << "3. Create Account Customer" << endl;
    cout << "Masukkan pilihan: ";

    int menu;
    cin >> menu;

    if (menu == 1) {
        Admin admins[2];
        admins[0].add("Admin1", "admin1@example.com", "123456789", "password1");
        admins[1].add("Admin2", "admin2@example.com", "987654321", "password2");

        bool loggedIn = loginAdmin(admins, 2);

        if (loggedIn) {
            cout << "Admin login successful!" << endl;
        } else {
            cout << "Admin login failed. Please try again." << endl;
        }
    } else if (menu == 2) {
        Customer customers[2];
        customers[0].add("Customer1", "customer1@example.com", "jalan1", "123456789", "password1");
        customers[1].add("Customer2", "customer2@example.com", "jalan2", "987654321", "password2");

        bool loggedIn = loginCustomer(customers, 2);

        if (loggedIn) {
            cout << "Customer login successful!" << endl;
        } else {
            cout << "Customer login failed. Please try again." << endl;
        }
    }
    
    return 0;
}