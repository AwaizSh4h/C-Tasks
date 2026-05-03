#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;
struct Graph {
    int V; // Number of vertice
    vector<list<int>> adj; // Adjacency list

    // Constructor
    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }
    
    // Function to add an edge
    void addEdge(int v, int w) {
        adj[v].push_back(w); // Add w to v’s list.
        // For undirected graph, add: adj[w].push_back(v);
    }

    void bfs(Graph& g, int startNode) {
    // Keep track of visited nodes to avoid infinite loops
    vector<bool> visited(g.V, false);
    
    // Create a queue for BFS
    queue<int> q;

    // Mark the current node as visited and enqueue it
    visited[startNode] = true;
    q.push(startNode);

   cout << "BFS Traversal starting from node " << startNode << ": ";

    while (!q.empty()) {
        // Dequeue a vertex and print it
        int curr = q.front();
        cout << curr << " ";
        q.pop();

        // Get all adjacent vertices of the dequeued vertex curr
        // If an adjacent vertex has not been visited, mark it visited and enqueue it
        for (int neighbor : g.adj[curr]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    cout << endl;
}
}
int main() {
    // Create a graph with 5 vertices (0 to 4)
    Graph g(5);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 4);

    bfs(g, 0);

    return 0;
}
