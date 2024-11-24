#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;

class Edge {
public:
    int target, weight;
    Edge(int target, int weight) : target(target), weight(weight) {}
};

class Graph {
private:
    int vertices;
    vector<vector<Edge>> adjacencyList;

public:
    Graph(int vertices) : vertices(vertices) {
        adjacencyList.resize(vertices);
    }

    void addEdge(int source, int target, int weight) {
        adjacencyList[source].emplace_back(target, weight);
    }

    // Function to implement Dijkstra's algorithm
    void dijkstra(int startVertex) {
        vector<int> distances(vertices, INT_MAX); 
        distances[startVertex] = 0;

       
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push({0, startVertex}); 

        while (!pq.empty()) {
            auto [currentDistance, currentVertex] = pq.top();
            pq.pop();

            if (currentDistance > distances[currentVertex]) continue;

            for (const auto& edge : adjacencyList[currentVertex]) {
                int neighbor = edge.target;
                int newDist = currentDistance + edge.weight;

                if (newDist < distances[neighbor]) {
                    distances[neighbor] = newDist;
                    pq.push({newDist, neighbor});
                }
            }
        }

        cout << "Shortest distances from source vertex " << startVertex << ":\n";
        for (int i = 0; i < vertices; ++i) {
            if (distances[i] == INT_MAX) {
                cout << "Vertex " << i << ": INF\n";
            } else {
                cout << "Vertex " << i << ": " << distances[i] << "\n";
            }
        }
    }
};

int main() {
    Graph graph(5); 
    

    graph.addEdge(0, 1, 10); // s -> t
    graph.addEdge(0, 2, 5);  // s -> y
    graph.addEdge(1, 2, 2);  // t -> y
    graph.addEdge(1, 3, 1);  // t -> x
    graph.addEdge(2, 1, 3);  // y -> t
    graph.addEdge(2, 3, 9);  // y -> x
    graph.addEdge(2, 4, 2);  // y -> z
    graph.addEdge(3, 4, 6);  // x -> z
    graph.addEdge(4, 0, 7);  // z -> s
    graph.addEdge(4, 3, 4);  // z -> x

    graph.dijkstra(0);

    return 0;
}
