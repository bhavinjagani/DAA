#include <iostream>
#include <vector>
#include <climits>
#include <iomanip>
using namespace std;

class Edge {
public:
    int source, destination, weight;
    Edge(int source, int destination, int weight) {
        this->source = source;
        this->destination = destination;
        this->weight = weight;
    }
};

void printPath(int current, const vector<int>& predecessor) {
    if (current == -1) {
        return;
    }
    printPath(predecessor[current], predecessor);
    cout << current << " ";
}
void printSolution(const vector<int>& distance, const vector<int>& predecessor, int source) {
    cout << "Vertex Distance from Source and Path:" << endl;
    for (int i = 0; i < distance.size(); i++) {
        if (distance[i] == INT_MAX) {
            cout << "Vertex " << i << ": No path from source" << endl;
        } else {
            cout << "Vertex " << i << " : " << distance[i] << " (Path: ";
            printPath(i, predecessor);
            cout << ")" << endl;
        }
    }
}

// Bellman-Ford Algorithm
void bellmanFord(int vertices, int edgesCount, vector<Edge>& edges, int source) {
    vector<int> distance(vertices, INT_MAX);
    vector<int> predecessor(vertices, -1);

    distance[source] = 0;

    // Relax edges repeatedly
    for (int i = 1; i < vertices; i++) {
        for (int j = 0; j < edgesCount; j++) {
            int u = edges[j].source;
            int v = edges[j].destination;
            int weight = edges[j].weight;

            if (distance[u] != INT_MAX && distance[u] + weight < distance[v]) {
                distance[v] = distance[u] + weight;
                predecessor[v] = u; // Update the path
            }
        }
    }

    for (int j = 0; j < edgesCount; j++) {
        int u = edges[j].source;
        int v = edges[j].destination;
        int weight = edges[j].weight;

        if (distance[u] != INT_MAX && distance[u] + weight < distance[v]) {
            cout << "Graph contains a negative-weight cycle" << endl;
            return;
        }
    }

    printSolution(distance, predecessor, source);
}

int main() {
    int vertices = 5; 
    int edgesCount = 10; 

    vector<Edge> edges;

    // Add edges to the graph
    edges.push_back(Edge(0, 1, 6));  // s -> t
    edges.push_back(Edge(0, 2, 7));  // s -> y
    edges.push_back(Edge(1, 3, 5));  // t -> x
    edges.push_back(Edge(1, 2, 8));  // t -> y
    edges.push_back(Edge(1, 4, -4)); // t -> z
    edges.push_back(Edge(2, 3, -3)); // y -> x
    edges.push_back(Edge(2, 4, 9));  // y -> z
    edges.push_back(Edge(3, 1, -2)); // x -> t
    edges.push_back(Edge(4, 0, 2));  // z -> s
    edges.push_back(Edge(4, 3, 7));  // z -> x

    bellmanFord(vertices, edgesCount, edges, 0);

    return 0;
}
