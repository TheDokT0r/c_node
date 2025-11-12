#include "node.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

Node *create_new_node(int value) {
  Node *newNode = malloc(sizeof(Node));
  if (newNode == NULL) {
    fprintf(stderr, "Memory allocation of node failed\n");
    return NULL;
  }

  newNode->value = value;
  newNode->next = NULL;
  newNode->previous = NULL;

  return newNode;
}

void append_node(Node *nodeList, int value) {
  Node *newNode = create_new_node(value);
  if (newNode == NULL) {
    fprintf(stderr, "Memory allocation failed\n");
    return;
  }
  Node *lastNode = nodeList;
  while (lastNode->next != NULL) {
    lastNode = lastNode->next;
  }

  newNode->previous = lastNode;
  lastNode->next = newNode;
}

Node *get_node_from_index(Node *nodeList, int index) {
  Node *currentNode = nodeList;

  for (int i = 0; i < index; i++) {
    if (currentNode == NULL) {
      printf("Node out of bound");
      return NULL;
    }

    currentNode = currentNode->next;
  }

  return currentNode;
}

int get_node_list_length(Node *nodeList) {
  Node *currentNode = nodeList;
  int size = 0;
  while (currentNode != NULL) {
    size++;
    currentNode = currentNode->next;
  }

  return size;
}

int *node_list_to_array(Node *nodeList) {
  int nodeListLength = get_node_list_length(nodeList);
  int *arr = malloc(nodeListLength * sizeof(int));
  if (arr == NULL) {
    fprintf(stderr, "Memory allocation failed\n");
    return NULL;
  }

  Node *currentNode = nodeList;
  for (int i = 0; i < nodeListLength; i++) {
    arr[i] = currentNode->value;
    currentNode = currentNode->next;
  }

  return arr;
}

Node *array_to_node_list(int *arr, int length) {
  if (length <= 0 || arr == NULL) {
    fprintf(stderr, "0-Array index");
    return NULL;
  }

  Node *head = create_new_node(arr[0]);
  for (int i = 1; i < length; i++) {
    append_node(head, arr[i]);
  }

  return head;
}

void print_node_list(Node *nodeList) {
  if (nodeList == NULL) {
    fprintf(stderr, "Invalid node list");
    return;
  }

  int length = get_node_list_length(nodeList);
  int *arr = node_list_to_array(nodeList);

  for (int i = 0; i < length; i++) {
    printf("%i\n", arr[i]);
  }

  free(arr);
}

Node *get_node_list_head(Node *node) {
  Node *currentNode = node;
  while (currentNode->previous != NULL) {
    currentNode = currentNode->previous;
  }

  return currentNode;
}

void free_node_list(Node *node) {
  Node *head = get_node_list_head(node);
  Node *current = head;
  while (current != NULL) {
    Node *next = current->next;
    free(current);
    current = next;
  }
}

Node *sort_node_list(Node *node) {
  int length = get_node_list_length(node);
  int *arr = node_list_to_array(node);

  bool flag = true;
  while (flag) {
    flag = false;
    for (int i = 0; i < length - 1; i++) {
      if (arr[i] > arr[i + 1]) {
        flag = true;
        int temp = arr[i];
        arr[i] = arr[i + 1];
        arr[i + 1] = temp;
      }
    }
  }

  Node *sortedList = array_to_node_list(arr, length);
  free(arr);
  return sortedList;
}
