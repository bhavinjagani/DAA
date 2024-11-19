#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void dfsHelper(int node, unordered_map<int, vector<int>> &graph, vector<bool> &visited, vector<int> &result)
{
    visited[node] = true;
    result.push_back(node);
    for (int neighbor : graph[node])
    {
        if (!visited[neighbor])
        {
            dfsHelper(neighbor, graph, visited, result);
        }
    }
}

vector<int> dfs(unordered_map<int, vector<int>> &graph, int start, int vertices)
{
    vector<bool> visited(vertices, false);
    vector<int> result;
    dfsHelper(start, graph, visited, result);
    return result;
}

int main()
{
    unordered_map<int, vector<int>> graph = {
        {0, {4, 5}},
        {1, {6, 7}},
        {2, {5}},
        {3, {}},
        {4, {}},
        {5, {}}};

    vector<int> traversal = dfs(graph, 0, 6);
    cout << "DFS Traversal: ";
    for (int v : traversal)
        cout << v << " ";
    cout << endl;

    return 0;
}
