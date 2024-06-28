#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs(const vector<vector<int>>& graph, int start) {
    // Initialize the queue with the start node
    queue<int> q;
    q.push(start);

    // Initialize the vector of visited nodes
    vector<bool> visited(graph.size(), false);
    visited[start] = true;

    while (!q.empty()) {
        // Dequeue a node from the front of the queue
        int current_node = q.front();
        q.pop();
        cout << current_node << " ";

        // Iterate over all adjacent nodes
        for (int neighbor : graph[current_node]) {
            if (!visited[neighbor]) {
                // Enqueue non-visited adjacent nodes
                q.push(neighbor);
                // Mark the node as visited
                visited[neighbor] = true;
            }
        }
    }
}

int main() {
    // Example graph represented as an adjacency list
    vector<vector<int>> graph = {
        {1, 2},    // Neighbors of node 0
        {0, 3, 4}, // Neighbors of node 1
        {0, 5},    // Neighbors of node 2
        {1},       // Neighbors of node 3
        {1, 5},    // Neighbors of node 4
        {2, 4}     // Neighbors of node 5
    };

    cout << "BFS starting from node 0: ";
    bfs(graph, 0);

    return 0;
}
