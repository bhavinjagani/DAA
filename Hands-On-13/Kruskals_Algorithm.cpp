#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class UnionFind {
    vector<int> parent, rank;
public:
    UnionFind(int size) {
        parent.resize(size);
        rank.resize(size, 0);
        for (int i = 0; i < size; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]); // Path compression
        }
        return parent[x];
    }

    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
};

vector<pair<int, pair<int, int>>> kruskal(int vertices, vector<pair<int, pair<int, int>>>& edges) {
    sort(edges.begin(), edges.end()); // Sort edges by weight
    UnionFind uf(vertices);
    vector<pair<int, pair<int, int>>> mst;

    for (auto& edge : edges) {
        int weight = edge.first;
        int u = edge.second.first;
        int v = edge.second.second;

        if (uf.find(u) != uf.find(v)) {
            uf.unite(u, v);
            mst.push_back(edge);
        }
    }

    return mst;
}

int main() {
    int vertices = 5;
    vector<pair<int, pair<int, int>>> edges = {
        {10, {0, 1}}, {6, {0, 2}}, {5, {0, 3}}, {15, {1, 3}}, {4, {2, 3}}
    };

    vector<pair<int, pair<int, int>>> mst = kruskal(vertices, edges);
    cout << "MST Edges:\n";
    for (auto& edge : mst) {
        cout << edge.second.first << " - " << edge.second.second << " (Weight: " << edge.first << ")\n";
    }

    return 0;
}
