#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

void dfs(int node, unordered_map<int, vector<int>>& graph, vector<bool>& visited, stack<int>& result) {
    visited[node] = true;
    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, graph, visited, result);
        }
    }
    result.push(node);
}

vector<int> topologicalSort(int vertices, vector<pair<int, int>>& edges) {
    unordered_map<int, vector<int>> graph;
    for (auto& edge : edges) {
        graph[edge.first].push_back(edge.second);
    }

    vector<bool> visited(vertices, false);
    stack<int> result;

    for (int i = 0; i < vertices; i++) {
        if (!visited[i]) {
            dfs(i, graph, visited, result);
        }
    }

    vector<int> topoOrder;
    while (!result.empty()) {
        topoOrder.push_back(result.top());
        result.pop();
    }
    return topoOrder;
}

int main() {
    int vertices = 6;
    vector<pair<int, int>> edges = {{0, 2}, {1, 2}, {2, 3}, {3, 4}, {5, 4}};
    
    vector<int> topoOrder = topologicalSort(vertices, edges);
    cout << "Topological Order: ";
    for (int v : topoOrder) cout << v << " ";
    cout << endl;

    return 0;
}
