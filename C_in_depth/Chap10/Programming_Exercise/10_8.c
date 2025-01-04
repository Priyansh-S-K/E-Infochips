//Find the largest and smallest element of a linked list, print total of all elements and find ou
// average.

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

// Function to find the largest and smallest elements in the list, 
// and calculate the sum and average of all elements
void findStats(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    int largest = head->data, smallest = head->data;
    int sum = 0, count = 0;
    struct Node* temp = head;

    // Traverse the list and compute the required values
    while (temp != NULL) {
        if (temp->data > largest) {
            largest = temp->data;
        }
        if (temp->data < smallest) {
            smallest = temp->data;
        }
        sum += temp->data;
        count++;
        temp = temp->next;
    }

    float average = (float)sum / count;
    printf("Largest element: %d\n", largest);
    printf("Smallest element: %d\n", smallest);
    printf("Total sum of elements: %d\n", sum);
    printf("Average of elements: %.2f\n", average);
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
    struct Node* head = createNode(10);
    head->next = createNode(20);
    head->next->next = createNode(30);
    head->next->next->next = createNode(5);
    head->next->next->next->next = createNode(15);

    printf("Original List: \n");
    printList(head);

    // Find largest, smallest, total and average of the elements
    findStats(head);

    return 0;
}
