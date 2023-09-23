#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node *parent;
    vector<Node*> children;
};

vector<Node*> tree(200000);
vector<int> descendants(200000, 0);

void createTree(int n) {
    for (int i = 0; i < n; i++) {
        tree[i] = new Node{ i + 1, nullptr, {} };
    }
}

void addEdge(int parent, int child) {
    tree[child - 1]->parent = tree[parent - 1];
    tree[parent - 1]->children.push_back(tree[child - 1]);
}

void findDescendants(Node* node) {
    for (Node *child : node->children) {
        findDescendants(child);
        descendants[node->data - 1] += 1 + descendants[child->data - 1];
    }
}

int main() 
{
    int n;
    cin >> n;
    createTree(n);

    for (int i = 2; i < n + 1; i++) {
        int parent, child = i;
        cin >> parent;
        addEdge(parent, child);
    }

    findDescendants(tree[0]);

    for (int i = 0; i < n; i++) {
        cout << descendants[i] << ' ';
        delete tree[i];
    }


    return 0;
}