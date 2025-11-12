#include "node.h"
#include <stdio.h>

int main() {
    Node *node = create_new_node(5);
    append_node(node, 4);
    append_node(node, 10);
    append_node(node, 20);

    print_node_list(node);

    printf("\n\n");

    node = sort_node_list(node);
    print_node_list(node);

    return 0;
}
