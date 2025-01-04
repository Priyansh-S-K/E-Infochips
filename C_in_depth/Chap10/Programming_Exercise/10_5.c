//Write a program to concatenate one linked list at the end of another.
#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to append a node at the end of the linked list
void append(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to concatenate one linked list at the end of another
void concatenate(struct Node** list1, struct Node* list2) {
    if (*list1 == NULL) {
        *list1 = list2;
        return;
    }

    struct Node* temp = *list1;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = list2;
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;

    // Append some nodes to the first list
    append(&list1, 1);
    append(&list1, 2);
    append(&list1, 3);

    // Append some nodes to the second list
    append(&list2, 4);
    append(&list2, 5);
    append(&list2, 6);

    // Print both lists before concatenation
    printf("List 1 before concatenation: ");
    printList(list1);
    printf("List 2 before concatenation: ");
    printList(list2);

    // Concatenate list2 at the end of list1
    concatenate(&list1, list2);

    // Print list1 after concatenation
    printf("\nList 1 after concatenation: ");
    printList(list1);

    return 0;
}
