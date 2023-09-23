#include <iostream>
#include <queue>
#include <vector>
using namespace std;

bool isOpen(const vector<vector<int>> &matrix, int x, int y, const vector<vector<bool>> &visited) {
    return x >= 0 && 
           x < matrix.size() && 
           y >= 0 && y < matrix.size() && 
           matrix[x][y] == 0 && 
           !visited[x][y];
}

int findToilet(const vector<vector<int>> &matrix) {
    int n = matrix.size();
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    queue<pair<int, int>> q;
    q.push(make_pair(0, 0));

    vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if (x == n - 1 && y == n - 1) {
            return visited[x][y];
        }

        visited[x][y] = true;

        for (const auto &dir : directions) {
            int newX = x + dir.first;
            int newY = y + dir.second;

            if (isOpen(matrix, newX, newY, visited)) {
                q.push(make_pair(newX, newY));
                visited[newX][newY] = true;
            }
        }
    }

    return -1;
}

int main() 
{
    int n;
    cin >> n;

    vector<vector<int>> matrix(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }

    if (findToilet(matrix) != -1) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
