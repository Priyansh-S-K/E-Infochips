//Write a program to remove first node of the list and insert it at the end.

#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node with a given value
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to remove the first node and insert it at the end
void moveFirstNodeToEnd(struct Node** head) {
    if (*head == NULL || (*head)->next == NULL) {
        return; // No operation needed if the list is empty or has only one node
    }

    struct Node* temp = *head;
    *head = (*head)->next; // Move the head to the second node
    temp->next = NULL; // Disconnect the first node from the list

    struct Node* current = *head;
    while (current->next != NULL) {
        current = current->next; // Traverse to the last node
    }

    current->next = temp; // Append the removed node to the end
}

// Function to print the list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    printf("Original List: \n");
    printList(head);

    // Remove first node and insert it at the end
    moveFirstNodeToEnd(&head);

    printf("Modified List: \n");
    printList(head);

    return 0;
}
