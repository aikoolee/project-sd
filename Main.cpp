#include <fstream>
#include <iostream>
#include <map>
#include <cstring>
#include "Graph.h"
#include "customer.h"
#include "admin.h"
#include <cstdlib>
#include <stdlib.h>
#include <ctime>
#include <string>
#include <iomanip>

using namespace std;

Admin Admins[3];
Agent Agents[15];
map <string, int> m;
Tree trees;
GraphInt cost_graph;
GraphFloat time_graph;
map<string, string> parent;
map<string, int> distance;
// TravelPackage P[10];
bool admin_logged_in = false;

void enter();

void initializeLocations() {
    string locations[50] = {
        "New Delhi", "Mumbai", "Beijing", "Osaka", "Bangkok", "Singapore", "Sydney", "Melbourne",
        "Abu Dhabi", "Cairo", "Moscow", "Stockholm", "Seoul", "Toronto", "San Francisco",
        "Washington D.C.", "Los Angeles", "Chicago", "New York", "Cape Town", "Rio de Janeiro", "Basel", "Mexico City",
        "Seattle", "Miami", "Tokyo", "Berlin", "Rome", "Amsterdam", "Madrid", "Havana"
    };
    for (int i = 0; locations[i] != ""; i++) {
        m[locations[i]] = 1;
    }
    cout << "Initiated locations\n";
}

void print_path(string destination) {
    if (parent[destination] == destination) {
        cout << destination << " --->";
        return;
    }
    print_path(parent[destination]);
    cout << destination << " --->";
}

void admin_portal() {
    bool success = admin_logged_in || loginAdmin(Admins, 2);
    if (success) {
        admin_logged_in = true;
        system("clear");
        cout << "--------------- WELCOME TO ADMIN PORTAL ---------------\n\n";
        int input;
        cout << "1: Tambah Lokasi\n";
        cout << "2: Lihat Semua Pelanggan\n";
        cout << "3: Lihat Semua Pemesanan\n";
        cout << "4: Kembali\n";
        cout << "5: Exit\n";
        cin >> input;

        switch (input) {
        case 1: {
            system("clear");
            add_edge(cost_graph, time_graph);
            cout << "\nPress any key, followed by 'enter' key, to navigate back!\n";
            char c;
            cin >> c;
            admin_portal();
            break;
        }
        case 2: {
            system("clear");
            viewCustomer();
            cout << "\nPress any key, followed by 'enter' key, to navigate back!\n";
            char c;
            cin >> c;
            admin_portal();
            break;
        }
        case 3: {
            viewBooking();
            viewCustomer();
            cout << "\nPress any key, followed by 'enter' key, to navigate back!\n";
            char c;
            cin >> c;
            admin_portal();
            break;
        }
        case 4: {
            system("clear");
            admin_logged_in = false;
            enter();
            break;
        }
        case 5: {
            system("clear");
            admin_logged_in = false;
            cout << "Thank you. We look forward to welcoming you back soon!\n";
            cout << "Exitting now...\n";
            break;
        }
        default: {
            cout << "\nInvalid input!\n";
            enter();
            }
        }
    }
    else {
        cout << "\nLogin failed. Please go back and enter the correct details.\n";
        cout << "\nPress any key, followed by 'enter' key, to navigate back!\n";
        char c;
        cin >> c;
        enter();
    }
}

bool custom_booking(Booking& B, string destination);

void finding_a_custom_plan() {
    system("clear");
    string destination;
    cout << "--------------- CUSTOM PLAN ---------------\n\n";
    cout << "Masukkan nama tujuan: ";
    cin.ignore();
    getline(cin, destination);

    if (m.count(destination) == 0) {
        cout << "\nLocation not found!\n";
        cout << "Redirecting you back, press any key followed by 'enter' to proceed!\n";
        char c;
        cin >> c;
        customer_portal();
        return;
    }
    else {
        cout << "Location found!\n";
        cout << "\nFlight cost: " << ::distance[destination] << endl;
        cout << "The minimum cost plan is: " << (2 * ::distance[destination]) + 20000 << "Rupiah.\n\n";
        print_path(destination);
        cout << endl << endl;
        cout << "Masukkan pilihan:\n";
        cout << "1: Pesan\n";
        cout << "2: Masukkan tujuan lain\n";
        cout << "3: Kembali\n";
        int choice;
        cin >> choice;
        if (choice == 1) {
            Booking B1;
            bool done = custom_booking(B1, destination);
            if (done) {
                system("clear");
                cout << "--------------- BOOKING CONFIRMED ---------------\n\n";
                cout << "Your agent will get in touch with you soon!\n";
                B1.print();
                cout << "\nRedirecting you back, press any key followed by 'enter' to proceed!\n";
                char c;
                cin >> c;
                customer_portal();
                return;
            }
            else {
                cout << "\n\nSome error occured. Please try again.\n";
                cout << "Redirecting you back, press any key followed by 'enter' to proceed!\n";
                char c;
                cin >> c;
                customer_portal();
                return;
            }
        }
        else if (choice == 2) {
            finding_a_custom_plan();
            return;
        }
        else {
            customer_portal();
            return;
        }
    }
    return;
}

// bool choose_and_book_package(TravelPackage P, Booking& B) {
//     system("clear");
//     cin.clear();
//     fflush(stdin);
//     string email;
//     cout << "You need to have an account to make a booking.\n";
//     cout << "If you don't have an account press any key followed by 'enter', and you'd be redirected.\n";

//     cout << "Masukkan email:\n";
//     getline(cin, email);
//     bool exists = trees.search(email);

//     if (exists) {
//         cout << "\nMasukkan nama: ";
//         getline(cin, B.nama_cust);
//         B.email_cust = email;
//         int i = 0;
//         for (const string& s : P.destinations) {
//             B.destinasi[i] = s;
//             i++;
//         }

//         B.nama_agent = assign(Agents, 10);

//         cout << "Masukkan tanggal: ";
//         getline(cin, B.tanggal);

//         cout << "Masukkan jumlah orang: ";
//         cin >> B.banyak_orang;
//         B.jumlah = (P.cost) * B.banyak_orang;

//         fstream f1;
//         f1.open("bookings.txt", ios::app | ios::binary);
//         f1.write((char*)&B, sizeof(B));
//         f1.close();

//     }
//     else {
//         cout << "\nCreate an account to make a booking.\n";
//         return false;
//     }
//     return true;
// }

bool execute_custom_booking(Booking &B, string destination) {
    system("clear");
    cin.clear();
    fflush(stdin);
    string email;
    cout << "You need to have an account to make a booking.\n";
    cout << "If you don't have an account press any key followed by 'enter', and you'd be redirected.\n";

    cout << "Masukkan email:\n";
    getline(cin, email);
    bool exists = trees.search(email);

    if (exists) {
        cout << "\nMasukkan nama: ";
        cin.ignore();
        std::getline(cin, B.nama_cust);
        B.email_cust = email;
        // B.destinasi[0] = destination;
        B.nama_agent = assign(Agents, 10);

        cout << "Masukkan tanggal: ";
        std::getline(cin, B.tanggal);

        cout << "Masukkan jumlah pesanan: ";
        cin >> B.jumlah;
        int cost = (::distance[destination] * 2) + 20000;
        B.jumlah = (cost)*B.jumlah;

        fstream f1;
        f1.open("bookings.txt", ios::app | ios::binary);
        f1.write((char*)&B, sizeof(B));
        f1.close();
    }
    else {
        cout << "\nCreate an account to make a booking.\n";
        return false;
    }
    return true;
}

// void execute_package_booking() {
//     cout << "--------------- PLANS ---------------\n";
//     for (int i = 0; i < 10; i++) {
//         cout << i + 1 << " " << P[i].package_name << endl;
//         cout << "Price per person: " << P[i].cost << endl;
//         cout << "Number of days: " << P[i].duration << endl;
//         cout << "Places: ";
//         for (string s : P[i].destinations) {
//             cout << s << " ";
//         }
//         cout << "\n\n";
//     }

//     cout << "\nMasukkan pilihan:\n";
//     cout << "1: Pesan\n";
//     cout << "2: Kembali\n";

//     int c;
//     cin >> c;

//     if (c == 1) {
//         int choice;
//         cout << "\nMasukkan jumlah pesanan: ";
//         cin >> choice;
//         Booking B1;
//         bool done = choose_and_book_package(P[choice - 1], B1);
//         if (done) {
//             system("clear");
//             cout << "\n--------------- BOOKING CONFIRMED ---------------\n";
//             cout << "Your agent will get in touch with you soon!\n";
//             B1.print();
//             cout << "\nRedirecting you back, press any key followed by 'enter' to proceed!\n";
//             char c;
//             cin >> c;
//             customer_portal();
//             return;
//         }
//         else {
//             cout << "\nSome error occured. Please try again.\n";
//             cout << "Redirecting you back, press any key followed by 'enter' to proceed!\n";
//             char c;
//             cin >> c;
//             customer_portal();
//             return;
//         }
//     }
//     else {
//         customer_portal();
//         return;
//     }
// }

bool login_customer(string& email) {
    string input_email, password;
    cout << "--------------- CUSTOMER LOGIN ---------------\n";
    cout << "\nMasukkan email: ";
    cin >> input_email;
    email = input_email;

    cout << "Masukkan password: ";
    cin >> password;

    fstream f1;
    f1.open("customers.txt", ios::in);
    Customer C;
    bool p = false;
    while (!f1.eof()) {
        f1.read((char*)&C, sizeof(Customer));
        if (C.email == email && C.password == password) {
            p = true;
            break;
        }
    }
    f1.close();
    return p;
}

void customer_portal() {
    system("clear");
    cout << "--------------- WELCOME TO THE CUSTOMER PORTAL ---------------\n";
    int input;
    cout << "1: Buat akun\n";
    cout << "2: Lihat semua lokasi\n";
    cout << "3: Custom Plan\n";
    // cout << "4: Pesan paket\n";
    cout << "4: Lihat pemesanan\n";
    cout << "5: Kembali\n";
    cout << "6: Exit\n";
    cin >> input;

    switch (input) {
    case 1: {
        bool p = createAcc(trees);
        customer_portal();
        break;
    }
    case 2: {
        system("clear");
        cout << "--------------- AVAILABLE LOCATIONS ---------------\n";
        int i = 0;
        for (auto p : m) {
            i++;
            if (i % 5 == 1) {
                cout << endl;
            }
            cout << left;
            cout << setw(20) << p.first << "  ";
        }
        char c;
        cout << "\n\nPress any key, followed by 'enter' key, to navigate back!\n";
        cin >> c;
        cin.clear();
        fflush(stdin);
        customer_portal();
        break;
    }
    case 3: {
        finding_a_custom_plan();
        break;
    }
    // case 4: {
        // execute_package_booking();
        // break;
    // }
    case 4: {
        system("clear");
        string email;
        bool login_success = login_customer(email);
        if (login_success) {
            int bookings = 0;
            cout << "--------------- YOUR BOOKINGS ---------------\n";
            fstream f1;
            f1.open("bookings.txt", ios::in);

            Booking B;

            f1.read((char*)&B, sizeof(Booking));
            while (!f1.eof()) {
                if (B.email_cust == email) {
                    bookings++;
                    B.print();
                    cout << endl;
                }
                f1.read((char*)&B, sizeof(Booking));
            }
            if (bookings == 0) {
                cout << "\nNo bookings found for this account!\n";
            }

            f1.close();
            cout << "Press any key, followed by 'enter', to navigate back!\n";
            char c;
            cin >> c;
            customer_portal();
        }
        else {
            cout << "\nLogin failed. Please try again.\n";
            cout << "Press any key followed by 'enter' to continue!\n";
            char c;
            cin >> c;
            customer_portal();
        }
        break;
    }
    case 5: {
        enter();
        break;
    }
    case 6: {
        system("clear");
        cout << "Thank you. We look forward to welcoming you back soon!\n";
        cout << "Exitting now...\n";
        break;
    }
    default: {
        cout << "Invalid input!\n";
        cout << "Redirecting you back, press any key followed by 'enter' to proceed!\n";
        char c;
        cin >> c;
        customer_portal();
        }
    }
}

void enter() {
    int input;
    system("clear");
    cout << "--------------- WELCOME ---------------\n\n";
    cout << "1: Admin\n";
    cout << "2: User\n";
    cout << "3: Exit\n";
    cin >> input;

    switch (input) {
    case 1: {
        admin_portal();
        break;
    }
    case 2: {
        customer_portal();
        break;
    }
    case 3: {
        system("clear");
        cout << "Thank you. We look forward to welcoming you back soon!\n";
        cout << "Exitting now...\n";
        break;
    }
    default: {
        cout << "\nInvalid input!\n";
        enter();
        }
    }
}

void initializeGraph() {
    int edges = 0;
    Edge E1;

    fstream f1;

    f1.open("places.txt", ios::in);
    f1.read((char*)&E1, sizeof(E1));
    cost_graph.addEdge(E1.destination1, E1.destination2, E1.cost);

    while (!f1.eof()) {
        edges++;
        f1.read((char*)&E1, sizeof(E1));
        cost_graph.addEdge(E1.destination1, E1.destination2, E1.cost);
    }

    cout << "Graphs initiated, " << edges << " edges created!\n";

    f1.close();
}

int main() {
    system("clear");
    srand(time(NULL));

    readAdmin(Admins);

    int count_agent;
    readAgent(Agents, count_agent);
    cout << count_agent << " agents found!\n";

    initializeLocations();
    for (auto p : m) {
        cout << p.first << " ";
    }
    cout << endl;

    readCust(trees);

    initializeGraph();
    minimum_cost("New Delhi", parent, ::distance, cost_graph.m);
    cout << endl;
    // initializeTravelPackages(P, 10);

    char c;
    cout << "Press any key, followed by 'enter' key, to start the program!\n";
    cin >> c;
    cin.clear();
    fflush(stdin);
    enter();

    return 0;
}