#ifndef NODE_H
#define NODE_H

typedef struct Node {
    int value;
    struct Node *next;
} Node;

Node *create_new_node(int value);
void append_node(Node *nodeList, int value);
Node* get_node_from_index(Node *nodeList, int index);
int get_node_list_length(Node *nodeList);
int* node_list_to_array(Node *nodeList);
Node *array_to_node_list(int *arr, int length);
void print_node_list(Node* nodeList);
#endif
