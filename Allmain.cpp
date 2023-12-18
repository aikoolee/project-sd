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
    Admin admins[2];
    Customer customers[2];
    GraphInt cost_graph;
    map<string, string> parent;
    map<string, int> distance;

    cout << "Menu:" << endl;
    cout << "1. Login Admin" << endl;
    cout << "2. Login Customer" << endl;
    cout << "3. Create Account Customer" << endl;
    cout << "Masukkan pilihan: ";

    int menu;
    cin >> menu;

    if (menu == 1) {
        admins[0].add("Admin1", "admin1@example.com", "123456789", "password1");
        admins[1].add("Admin2", "admin2@example.com", "987654321", "password2");

        bool loggedIn = loginAdmin(admins, 2);

        if (loggedIn) {
            cout << "Admin login successful!" << endl;

            cout << "Menu:" << endl;
            cout << "1. Masukkan lokasi" << endl;
            cout << "Masukkan pilihan: ";

            int menu2;
            cin >> menu2;

            if (menu2 == 1) {
                string lokasi_awal;
                string lokasi_tujuan;
                int biaya;

                cout << "Masukkan lokasi_awal: ";
                cin >> lokasi_awal;
                cout << "Masukkan lokasi_tujuan: ";
                cin >> lokasi_tujuan;
                cout << "Masukkan biaya: ";
                cin >> biaya;

                cost_graph.addEdge(lokasi_awal, lokasi_tujuan, biaya);
            }
            
        } else {
            cout << "Admin login failed. Please try again." << endl;
        }
    } else if (menu == 2) {
        customers[0].add("Customer1", "customer1@example.com", "jalan1", "123456789", "password1");
        customers[1].add("Customer2", "customer2@example.com", "jalan2", "987654321", "password2");

        bool loggedIn = loginCustomer(customers, 2);

        if (loggedIn) {
            cout << "Customer login successful!" << endl;

            cout << "Menu:" << endl;
            cout << "1. Mencari rencana perjalanan terbaik" << endl;
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
            }

        } else {
            cout << "Customer login failed. Please try again." << endl;
        }
    } else if (menu == 3) {
        
    }
    
    
    return 0;
}