#pragma once

#include <iostream>
#include <map>
#include <list>
#include <cstring>
#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

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

// class TravelPackage {
// public:
//     std::string package_name;
//     int cost;
//     int duration;
//     list<std::string> destinations;
// };

// void initializeTravelPackages(TravelPackage packages[], int n) {
//     packages[0].package_name = "European Adventure";
//     packages[0].cost = 28000000;
//     packages[0].duration = 7;
//     packages[0].destinations.push_back("Amsterdam");
//     packages[0].destinations.push_back("Barcelona");
//     packages[0].destinations.push_back("Rome");

//     packages[1].package_name = "Mediterranean Magic";
//     packages[1].cost = 30000000;
//     packages[1].duration = 8;
//     packages[1].destinations.push_back("Athens");
//     packages[1].destinations.push_back("Nice");
//     packages[1].destinations.push_back("Venice");

//     packages[2].package_name = "Asian Expedition";
//     packages[2].cost = 24000000;
//     packages[2].duration = 8;
//     packages[2].destinations.push_back("Tokyo");
//     packages[2].destinations.push_back("Beijing");
//     packages[2].destinations.push_back("Bangkok");
//     packages[2].destinations.push_back("Seoul");

//     packages[3].package_name = "Caribbean Paradise";
//     packages[3].cost = 15000000;
//     packages[3].duration = 6;
//     packages[3].destinations.push_back("Havana");
//     packages[3].destinations.push_back("Nassau");
//     packages[3].destinations.push_back("San Juan");

//     packages[4].package_name = "Aussie Adventure";
//     packages[4].cost = 27000000;
//     packages[4].duration = 6;
//     packages[4].destinations.push_back("Sydney");
//     packages[4].destinations.push_back("Melbourne");

//     packages[5].package_name = "South American Discovery";
//     packages[5].cost = 23000000;
//     packages[5].duration = 6;
//     packages[5].destinations.push_back("Buenos Aires");
//     packages[5].destinations.push_back("Lima");
//     packages[5].destinations.push_back("Sao Paulo");

//     packages[6].package_name = "Canadian Wilderness Retreat";
//     packages[6].cost = 29000000;
//     packages[6].duration = 9;
//     packages[6].destinations.push_back("Banff");
//     packages[6].destinations.push_back("Vancouver");
//     packages[6].destinations.push_back("Toronto");

//     packages[7].package_name = "USA West Coast Extravaganza";
//     packages[7].cost = 17000000;
//     packages[7].duration = 8;
//     packages[7].destinations.push_back("San Francisco");
//     packages[7].destinations.push_back("Los Angeles");
//     packages[7].destinations.push_back("Las Vegas");

//     packages[8].package_name = "New England Charm";
//     packages[8].cost = 19000000;
//     packages[8].duration = 6;
//     packages[8].destinations.push_back("Boston");
//     packages[8].destinations.push_back("Portland");
//     packages[8].destinations.push_back("Providence");

//     packages[9].package_name = "Alaskan Wilderness Adventure";
//     packages[9].cost = 35000000;
//     packages[9].duration = 11;
//     packages[9].destinations.push_back("Anchorage");
//     packages[9].destinations.push_back("Juneau");
//     packages[9].destinations.push_back("Denali");
//     packages[9].destinations.push_back("Fairbanks");

//     cout << "Initialized Travel Packages\n";
// }

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