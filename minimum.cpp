#include <iostream>
#include <map>
#include <list>
#include <cstring>
#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <set>
#include <climits>

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
    GraphInt cost_graph;

    cost_graph.addEdge("A", "D", 1000);
    cost_graph.addEdge("A", "C", 2000);
    cost_graph.addEdge("A", "F", 2000);
    cost_graph.addEdge("B", "G", 3000);
    cost_graph.addEdge("C", "D", 500);

    map<string, string> parent;
    map<string, int> distance;
    
    string source = "A";
    minimum_cost(source, parent, distance, cost_graph.m);

    cout << "Minimum costs from source " << source << ":\n";
    for (const auto& p : distance) {
        cout << "To " << p.first << ": " << p.second << "\n";
    }

    return 0;
}