#include <iostream>
#include <map>
#include <list>
#include <cstring>
#include <cstdlib>
#include <stdlib.h>
#include <ctime>
#include <string>
#include <iomanip>
#include <vector>
#include <unordered_map>
#include <set>
#include <climits>

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

// --- BOOKING ---

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
        this->next = nullptr;
        this->prev = nullptr;
    }

    // Constructor dengan parameter
    Node(Booking value, Node* ptr, Node* ptr2) {
        this->data = value;
        this->next = ptr;
        this->prev = ptr2;
    }

    // Destructor
    ~Node() {
        cout << "Node dihapus" << endl;
    }
};

struct DoubleLinkedList {
    Node* head;
    int size; 

    // Constructor
    DoubleLinkedList(){
        this->head = nullptr;
        size = 0;
    }

    // Add depan
    void insertHead(Booking value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = head;
        head = newNode;
        size++;
    }

    // Add belakang
    void insertBack(Booking value) {
        Node* newNode = new Node;
        newNode->data = value;
        
        if (head == nullptr) {
            insertHead(value);
        } else { 
            Node* current = head;
            
            while (current->next != nullptr) {
                current = current->next;
            }    

            
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

// --- CUSTOMER ---

int cust_size = 0;

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
        cust_size++;
    }

    bool login(string nama, string password) {
        if (nama == this->nama && password == this->password) {
            cout << "Login success" << endl;
            return true;
        }
        return false;
    }

    void print() {
        cout << "Customer Details:\n";
        cout << "Nama: " << nama << endl;
        cout << "Email: " << email << endl;
        cout << "Alamat: " << alamat << endl;
        cout << "Nomor Telepon: " << notelp << endl;
        cout << "Password: " << password << endl;

        // cout << "\nBooking History:\n";
        // Node* current = history.head;
        // while (current != nullptr) {
        //     current->data.print();
        //     cout << endl;
        //     current = current->next;
        // }
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
    
    Customer c1;
    c1.add(nama, email, alamat, notelp, password);
    cout << "Akun berhasil dibuat" << endl;
    return false;
}

// --- EDGE ---

class Edge {
public:
    string destination1;
    string destination2;
    int cost;
    float time;

    Edge(const string& a = "London", const string& b = "Paris", int c = 0, float t = 0.00)
        : destination1(a), destination2(b), cost(c), time(t) {}

    void initialize(const string& a, const string& b, int c, float t) {
        destination1 = a;
        destination2 = b;
        cost = c;
        time = t;
    }
};

class GraphInt {
public:
    int v;

    map<std::string, list<pair<std::string, int>>> m;

    void addEdge(std::string x, std::string y, int wt) {
        m[x].push_back(make_pair(y, wt));
        m[y].push_back(make_pair(x, wt));
    }

    void print() {
        for (const auto& entry : m) {
            std::cout << "Source " << entry.first << ": ";
            for (const auto& neighbor : entry.second) {
                std::cout << "(" << neighbor.first << ", " << neighbor.second << ") ";
            }
            std::cout << std::endl;
        }
    }
};

class GraphFloat {
public:
    int v;

    map<std::string, list<pair<std::string, float>>> m;

    void addEdge(std::string x, std::string y, float wt) {
        m[x].push_back(make_pair(y, wt));
        m[y].push_back(make_pair(x, wt));
    }
};

void minimum_cost(std::string src, map<std::string, std::string>& parent, map<std::string, int>& distance, map<std::string, list<pair<std::string, int>>>& m) {
    for (auto p : m) {
        distance[p.first] = INT_MAX;
    }

    distance[src] = 0;
    set<pair<int, std::string>> s;
    s.insert(make_pair(0, src));
    parent[src] = src;

    while (!s.empty()) {
        auto p = *(s.begin());
        std::string place = p.second;
        int node_distance = p.first;

        s.erase(s.begin());

        for (auto child_pair : m[place]) {
            int edge_weight = child_pair.second;
            if (node_distance + edge_weight < distance[child_pair.first]) {
                std::string vertex = child_pair.first;
                auto f = s.find(make_pair(distance[vertex], vertex));
                if (f != s.end()) {
                    s.erase(f);
                }
                parent[vertex] = place;
                distance[vertex] = node_distance + edge_weight;
                s.insert(make_pair(distance[vertex], vertex));
            }
        }
    }
}

void minimum_time(std::string src, std::string dest, vector<std::string>& path, map<std::string, list<pair<std::string, float>>>& m) {
    unordered_map<std::string, float> time;
    for (auto p : m) {
        time[p.first] = 100000.00;
    }

    time[src] = 0.00;

    set<pair<float, std::string>> s;
    s.insert(make_pair(0.00, src));

    while (!s.empty()) {
        auto p = *(s.begin());
        std::string place = p.second;
        float node_time = p.first;

        s.erase(s.begin());

        for (auto child_pair : m[place]) {
            float edge_weight = child_pair.second;
            if (node_time + edge_weight < time[child_pair.first]) {
                std::string vertex = child_pair.first;
                auto f = s.find(make_pair(time[vertex], vertex));
                if (f != s.end()) {
                    s.erase(f);
                }
                time[vertex] = node_time + edge_weight;
                s.insert(make_pair(time[vertex], vertex));
            }
        }
    }
}

int main() {
    Admin admins[4];
    Customer customers[10];
    GraphInt cost_graph;
    map<string, string> parent;
    map<string, int> distance;

    bool check = true;
    while (check) {
        cout << endl;
        cout << "Menu:" << endl;
        cout << "1. Login Admin" << endl;
        cout << "2. Login Customer" << endl;
        cout << "3. Create Customer's Account" << endl;
        cout << "4. Exit" << endl;
        cout << "Masukkan pilihan: ";

        int menu;
        cin >> menu;

        cost_graph.addEdge("Tokyo", "Dubai", 1000);
        cost_graph.addEdge("Tokyo", "Mumbai", 2000);
        cost_graph.addEdge("Tokyo", "London", 2000);
        cost_graph.addEdge("Dubai", "Jakarta", 3000);
        cost_graph.addEdge("Mumbai", "London", 500);

        customers[0].add("Customer1", "customer1@gmail.com", "Jalan1", "12345", "password1");
        customers[1].add("Customer2", "customer2@gmail.com", "Jalan2", "67890", "password2");

        Booking booking1;
        booking1.book("Customer1", "customer1@example.com", "12 Januari 2023", 1000, 1, "Agent1");

        for (int i = 0; i < cust_size; i++) {
            if (customers[i].nama == booking1.nama_cust) {
                customers[i].history.insertBack(booking1);
            }
        }

        Booking booking2;
        booking2.book("Customer1", "customer1@example.com", "12 Januari 2023", 1000, 2, "Agent1");

        for (int i = 0; i < cust_size; i++) {
            if (customers[i].nama == booking2.nama_cust) {
                customers[i].history.insertBack(booking2);
            }
        }

        Booking booking3;
        booking3.book("Customer2", "customer2@example.com", "12 Januari 2023", 1000, 3, "Agent1");

        for (int i = 0; i < cust_size; i++) {
        if (customers[i].nama == booking3.nama_cust) {
                customers[i].history.insertBack(booking3);
            }
        }

        if (menu == 1) {
            admins[0].add("Admin1", "admin1@example.com", "123456789", "password1");
            admins[1].add("Admin2", "admin2@example.com", "987654321", "password2");

            bool loggedIn = loginAdmin(admins, 2);

            if (loggedIn) {
                cout << "Admin login successful!" << endl;

                bool check2 = true;

                while (check2) {
                    cout << endl;
                    cout << "Menu:" << endl;
                    cout << "1. Add a Location" << endl;
                    cout << "2. View all locations" << endl;
                    cout << "3. View all customers" << endl;
                    cout << "4. View all customer's history" << endl;
                    cout << "5. Exit" << endl;
                    cout << "Masukkan pilihan: ";

                    int menu2;
                    cin >> menu2;

                    if (menu2 == 1) {
                        string destinasi1;
                        string destinasi2;
                        int biaya;

                        cout << "Masukkan destinasi 1: ";
                        cin >> destinasi1;
                        cout << "\nMasukkan destinasi 2: ";
                        cin >> destinasi2;
                        cout << "\nMasukkan biaya: ";
                        cin >> biaya;

                        cost_graph.addEdge(destinasi1, destinasi2, biaya);
                        cout << "Lokasi berhasil ditambahkan" << endl;
                    } else if (menu2 == 2) {    
                        cost_graph.print();
                    } else if (menu2 == 3) {
                        if (cust_size <= 0) {
                            cout << "No customer" << endl;
                        } else {
                            for (int i = 0; i < cust_size; i++) {
                                cout << "Customer details for " << customers[i].nama << ":\n";
                                customers[i].print();
                                cout << endl;
                            }
                        }
                    } else if (menu2 == 4) {
                        for (int i = 0; i < cust_size; i++) {
                            cout << "Booking history for " << customers[i].nama << ":\n";
                            customers[i].history.display();
                            cout << endl;
                        }

                        string best_cust = "none";
                        int max = -1;
                        for (int i = 0; i < cust_size; i++) {
                            if (customers[i].history.size > max) {
                                best_cust = customers[i].nama;
                                max = customers[i].history.size;
                            }
                        }
    
                        cout << "Best Customer: " << best_cust << endl;
                    } else if (menu2 == 5) {
                        check2 = false;
                    }
                }
            
            } else {
                cout << "Admin login failed. Please try again." << endl;
            }
        } else if (menu == 2) {
            bool loggedIn = loginCustomer(customers, cust_size);

            if (loggedIn) {
                cout << "Customer login successful!" << endl;

                bool check2 = true;

                while (check2) {
                    cout << endl;
                    cout << "Menu:" << endl;
                    cout << "1. Mencari rencana perjalanan terbaik" << endl;
                    cout << "2. Book rencana perjalanan" << endl;
                    cout << "3. Lihat booking history" << endl;
                    cout << "4. Exit" << endl;
                    cout << "Masukkan pilihan: ";

                    int menu2;
                    cin >> menu2;

                    if (menu2 == 1) {
                        string source;

                        cout << "Masukkan lokasi_awal: ";
                        cin >> source;

                        minimum_cost(source, parent, distance, cost_graph.m);

                        cout << "Minimum costs from source " << source << ":\n";
                        for (const auto& p : distance) {        
                            cout << "To " << p.first << ": " << p.second << "\n";
                        }
                    } else if (menu2 == 2) {
                        Booking booking;
                        string nama = customers->nama;
                        string email = customers->email;
                        string tanggal;
                        string source;
                        string destination;
                        int biaya = 0;
                        int jumlah;
                        string nama_agent;

                        cout << "Masukkan tanggal: ";
                        cin >> tanggal;
                        cout << "Masukkan lokasi awal: ";
                        cin.ignore();
                        getline(cin, source);
                        cout << "Masukkan lokasi tujuan: ";
                        getline(cin, destination);
                        cout << "Masukkan nama agent: ";
                        getline(cin, nama_agent);

                        minimum_cost(source, parent, distance, cost_graph.m);

                        for (const auto& p : distance) {
                            if (destination == p.first) {
                                biaya = p.second;
                            }
                        }

                        booking.book(nama, email, tanggal, biaya, jumlah, nama_agent);

                        for (int i = 0; i < cust_size; i++) {
                            if (customers[i].nama == booking.nama_cust) {
                                customers[i].history.insertBack(booking);
                            }
                        }

                        cout << "Book berhasil" << endl;
                    } else if (menu2 == 3) {
                        // for (int i = 0; i < 2; i++) {
                        //     if (customers[i].nama == customers->nama) {
                        //         cout << "Booking history for " << customers[i].nama << ":\n";
                        //         customers[i].history.display();
                        //         cout << endl;
                        //     }
                        // }

                        customers->history.display();
                    } else if (menu2 == 4) {
                        check2 = false;
                    }
                    
                    
                }

            } else {
                cout << "Customer login failed. Please try again." << endl;
            }
        } else if (menu == 3) {
            string nama;
            string email;
            string alamat;
            string notelp;
            string password;

            cout << "Masukkan nama: ";
            cin >> nama;
            cout << "Masukkan alamat: ";
            getline(cin, alamat);
            cout << "Masukkan email: ";
            cin >> email;
            cout << "Masukkan nomor telepon: ";
            cin.ignore();
            cin >> notelp;
            cout << "Masukkan password: ";
            cin >> password;

            customers[cust_size].add(nama, email, alamat, notelp, password);
            cout << "Akun berhasil dibuat" << endl;
        } else if (menu == 4) {
            check = false;
        }
    }
    
    return 0;
}