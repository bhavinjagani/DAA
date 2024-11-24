#include <iostream>
#include <vector>
#include <climits>
using namespace std;

const int INF = 99999; // Representing infinity (no direct path)

// Function to print the shortest distance matrix
void printSolution(const vector<vector<int>>& dist, int vertices) {
    cout << "Shortest distances between every pair of vertices:" << endl;
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            if (dist[i][j] == INF) {
                cout << "INF ";
            } else {
                cout << dist[i][j] << "   ";
            }
        }
        cout << endl;
    }
}
// Floyd-Warshall Algorithm
void floydWarshall(vector<vector<int>>& graph, int vertices) {
    // Create a distance matrix and copy the original graph to it
    vector<vector<int>> dist(vertices, vector<int>(vertices));

    // Initialize distance matrix with the graph values
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            dist[i][j] = graph[i][j];
        }
    }

    // Perform the Floyd-Warshall algorithm
    for (int k = 0; k < vertices; k++) {
        for (int i = 0; i < vertices; i++) {
            for (int j = 0; j < vertices; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Print the shortest distances
    printSolution(dist, vertices);
}



int main() {
    int vertices = 4;

    // Define the graph as an adjacency matrix
    vector<vector<int>> graph = {
        {0, 3, INF, 7},
        {8, 0, 2, INF},
        {5, INF, 0, 1},
        {2, INF, INF, 0}
    };

    // Call Floyd-Warshall algorithm
    floydWarshall(graph, vertices);

    return 0;
}
