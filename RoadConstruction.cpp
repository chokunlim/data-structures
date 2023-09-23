#include <iostream>
#include <vector>
using namespace std;

class Graph {
    private:
        int size;
        vector<vector<int>> adj;
        vector<bool> visited;    

    public:
        Graph(int size) {
            this->size = size;
            this->adj.resize(size + 1);
            this->visited.resize(size + 1, 0); 
        }

        void addEdge(int a, int b) {
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        void DFSVisit(int start) {
            visited[start] = true;  

            for (int city : adj[start]) {
                if (!visited[city]) {
                    DFSVisit(city);
                }
            }

        }

        int minimumOfRoadToBuild() {
            int roads_to_build = 0;

            for (int i = 0; i < size; ++i) {
                if (!visited[i+1]) {
                    DFSVisit(i+1);
                    roads_to_build++;
                }
            }

            return roads_to_build - 1;
        }
};

int main() 
{    
    int n, m; 
    cin >> n >> m;

    Graph graph(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph.addEdge(a, b);
    }

    cout << graph.minimumOfRoadToBuild();

    return 0;
}