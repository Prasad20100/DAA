#include <iostream>
#include <list>
#include <vector>
using namespace std;

class Graph {
public:
    Graph(int vertices); // Constructor to initialize the graph with the given number of vertices
    void add_edge(int src, int dst); // Adds an edge between src and dst
    int count_paths(int src, int dst); // Counts all paths from src to dst

private:
    int m_vertices; // Number of vertices in the graph
    list<int>* m_neighbours; // Array of adjacency lists for the graph
    void path_counter(int src, int dst, int& path_count, vector<bool>& visited); // Helper function to count paths
};

// Constructor to initialize the graph
Graph::Graph(int vertices) {
    m_vertices = vertices;
    m_neighbours = new list<int>[vertices]; // Array of lists to store the neighbours of each vertex
}

// Adds an edge between src and dst
void Graph::add_edge(int src, int dst) {
    m_neighbours[src].push_back(dst); // Add dst to the list of neighbours for src
}

// Counts the total number of paths from src to dst
int Graph::count_paths(int src, int dst) {
    int path_count = 0; // Initialize path count to 0
    vector<bool> visited(m_vertices, false); // Keep track of visited vertices
    path_counter(src, dst, path_count, visited); // Start counting paths
    return path_count; // Return the total path count
}

// Helper function to count paths recursively
void Graph::path_counter(int src, int dst, int& path_count, vector<bool>& visited) {
    visited[src] = true; // Mark the current vertex as visited
    
    // If we've reached the destination, increment the path count
    if (src == dst) {
        path_count++;
    } else {
        // Otherwise, visit all unvisited neighbours of the current vertex
        for (auto neighbour : m_neighbours[src]) {
            if (!visited[neighbour]) {
                path_counter(neighbour, dst, path_count, visited); // Recursively count paths from the neighbour
            }
        }
    }
    
    visited[src] = false; // Backtrack, unmark the current vertex as visited
}

int main() {
    Graph g(5); // Create a graph with 5 vertices
    g.add_edge(0, 1); // Add edges
    g.add_edge(0, 2);
    g.add_edge(0, 4);
    g.add_edge(1, 3);
    g.add_edge(1, 4);
    g.add_edge(2, 3);
    g.add_edge(2, 1);
    g.add_edge(3, 2);
    
    // Count and print the number of paths from vertex 0 to vertex 4
    cout << "Number of paths from 0 to 4: " << g.count_paths(0, 4) << endl;
    
    return 0;
}
