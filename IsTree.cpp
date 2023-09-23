#include <iostream>
#include <vector>
using namespace std;

class Graph {
private:
    int size;
    vector<vector<int>> adj;
    bool *visited;

    bool isCycle(int v, bool visited[], int parent) {
        visited[v] = true;

        for (auto i = adj[v].begin(); i != adj[v].end(); i++) {
            if (!visited[*i]) {
                if (isCycle(*i, visited, v)) { return true; }
            } else if (*i != parent) { return true; }
        }

        return false;
    }

public:
    Graph(int size) {
        this->size = size;
        adj.resize(size + 1);
        visited = new bool[size]();
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bool isTree() {
        if (isCycle(0, visited, -1)) { return false; }
        
        for (int i = 0; i < size; i++) {
            if (!visited[i]) { return false; }
        }

        return true;
    }
};

int main() 
{
    int N, M;
    cin >> N >> M;
    Graph graph(N);

    for (int i = 0; i < M; i++) {
        int U, V;
        cin >> U >> V;
        graph.addEdge(U, V);
    }

    cout << (graph.isTree() ? "YES" : "NO");

    return 0;
}