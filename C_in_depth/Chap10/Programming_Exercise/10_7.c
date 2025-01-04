//Write a program to count the number of occurrences of an element in the list.

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

// Function to count the occurrences of a specific element in the list
int countOccurrences(struct Node* head, int value) {
    int count = 0;
    struct Node* temp = head;

    // Traverse the list and count occurrences of the given value
    while (temp != NULL) {
        if (temp->data == value) {
            count++;
        }
        temp = temp->next;
    }
    
    return count;
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
    head->next->next->next = createNode(2);
    head->next->next->next->next = createNode(4);
    head->next->next->next->next->next = createNode(2);

    printf("Original List: \n");
    printList(head);

    int value = 2;
    int occurrences = countOccurrences(head, value);
    
    printf("The value %d occurs %d time(s) in the list.\n", value, occurrences);

    return 0;
}
