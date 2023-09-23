#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char name[100];
    int size;
    int type; 
    int total_size;
    struct node* parent;
    struct node* firstChild;
    struct node* nextSibling;
} Node;

Node *createNode(char *name, int size, int type) {
    Node *node = (Node*) malloc(sizeof(Node));

    strcpy(node->name, name);
    node->size = size;
    node->type = type;
    node->total_size = 0;
    node->parent = NULL;
    node->firstChild = NULL;
    node->nextSibling = NULL;

    return node;
}

void addChild(Node *parent, Node *child) {
    if (parent == NULL || child == NULL) return;
    child->parent = parent;
    child->nextSibling = parent->firstChild;
    parent->firstChild = child;
}

void preorderTraversal(Node *node) {
    if (node == NULL) return;
    Node *child = node->firstChild;
    while (child != NULL) {
        preorderTraversal(child);
        child = child->nextSibling;
    }

    node->total_size = node->size;
    child = node->firstChild;
    while (child != NULL) {
        node->total_size += child->total_size;
        child = child->nextSibling;
    }
}

void postorderTraversal(Node *node) {
    if (node == NULL) return;
    Node *child = node->firstChild;
    while (child != NULL) {
        postorderTraversal(child);
        child = child->nextSibling;
    }

    printf("Name: %-20s total size: %dK\n", node->name, node->total_size);
}

void freeTree(Node *node) {
    if (node == NULL) return;
    Node *child = node->firstChild;
    while (child != NULL) {
        Node *nextChild = child->nextSibling;
        freeTree(child);
        child = nextChild;
    }

    free(node); 
}

int main() 
{
    //folders
    Node *root = createNode("/user/rt/courses/", 1,1);
    Node *cs016 = createNode("cs016/", 2, 1);
    Node *cs252 = createNode("cs252/", 1, 1);
    Node *homeworks = createNode("homeworks/", 1, 1);
    Node *programs = createNode("programs/", 1, 1);
    Node *projects = createNode("projects/", 1, 1);
    Node *papers = createNode("papers/", 1, 1);
    Node *demos = createNode("demos/", 1, 1);

    //files
    Node *cs016_grades = createNode("grades", 8, 0);
    Node *cs252_grades = createNode("grades", 3, 0);
    Node *hw1 = createNode("hw1", 3, 0);
    Node *hw2 = createNode("hw2", 2, 0);
    Node *hw3 = createNode("hw3", 4, 0);
    Node *pr1 = createNode("pr1", 57, 0);
    Node *pr2 = createNode("pr2", 97, 0);
    Node *pr3 = createNode("pr3", 74, 0);
    Node *buylow = createNode("buylow", 26, 0);
    Node *sellhigh = createNode("sellhigh", 55, 0);
    Node *market = createNode("market", 4786, 0);

    addChild(root, cs016);
    addChild(root, cs252);
    
    //cs016
    addChild(cs016, cs016_grades);
    addChild(cs016, homeworks);
    addChild(cs016, programs);
    //cs016/homeworks
    addChild(homeworks, hw1);
    addChild(homeworks, hw2);
    addChild(homeworks, hw3);
    //cs016/programs
    addChild(programs, pr1);
    addChild(programs, pr2);
    addChild(programs, pr3);

    //cs252
    addChild(cs252, projects);
    addChild(cs252, cs252_grades);
    //cs252/projects
    addChild(projects, papers);
    addChild(projects, demos);
    //cs252/projects/papers
    addChild(papers, buylow);
    addChild(papers, sellhigh);
    //cs252/projects/demos
    addChild(demos, market);

    preorderTraversal(root); 
    postorderTraversal(root);

    freeTree(root);

    return 0;
}