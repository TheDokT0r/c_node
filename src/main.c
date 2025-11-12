#include "node.h"

int main() {
    Node *node = create_new_node(5);
    append_node(node, 4);
    append_node(node, 10);
    append_node(node, 20);

    print_node_list(node);

    int length = get_node_list_length(node);
    int *arr = node_list_to_array(node);

    print_node_list(array_to_node_list(arr, length));

    return 0;
}
