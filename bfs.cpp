#include <iostream>
#include <vector>
#include <queue>
#include <list>

class Graph {
    int numVertices;
    std::list<int> *adj; // Pointer to an array containing adjacency lists

public:
    Graph(int vertices);
    void addEdge(int src, int dest);
    void BFS(int startVertex);
};

// Constructor to create a graph with a given number of vertices
Graph::Graph(int vertices) {
    numVertices = vertices;
    adj = new std::list<int>[vertices];
}

// Add an edge to the graph
void Graph::addEdge(int src, int dest) {
    adj[src].push_back(dest); // Add dest to src's list
}

// BFS traversal from a given source s
void Graph::BFS(int startVertex) {
    // Create a boolean array to mark visited vertices
    std::vector<bool> visited(numVertices, false);

    // Create a queue for BFS
    std::queue<int> queue;

    // Mark the current node as visited and enqueue it
    visited[startVertex] = true;
    queue.push(startVertex);

    std::cout << "Breadth First Traversal (starting from vertex " << startVertex << "): ";

    while (!queue.empty()) {
        // Dequeue a vertex from queue and print it
        int currentVertex = queue.front();
        std::cout << currentVertex << " ";
        queue.pop();

        // Get all adjacent vertices of the dequeued vertex currentVertex
        // If an adjacent has not been visited, then mark it visited
        // and enqueue it
        for (int adjacentVertex : adj[currentVertex]) {
            if (!visited[adjacentVertex]) {
                visited[adjacentVertex] = true;
                queue.push(adjacentVertex);
            }
        }
    }
    std::cout << std::endl;
}

int main() {
    // Create a graph given in the above diagram
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    g.BFS(2);

    return 0;
}