/*Write a program that maintains records of students using linked list. The structure of nod
 list would be
struct node{
 char name[20] ;
 int rollno;
 int marks;
 struct node *link;
 }
 Now search a particular record based on roll number.*/

 #include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for a node
struct node {
    char name[20];
    int rollno;
    int marks;
    struct node *link;
};

// Function to create a new node
struct node* createNode(char name[], int rollno, int marks) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    strcpy(newNode->name, name);
    newNode->rollno = rollno;
    newNode->marks = marks;
    newNode->link = NULL;
    return newNode;
}

// Function to add a new record to the linked list
void addRecord(struct node **head, char name[], int rollno, int marks) {
    struct node* newNode = createNode(name, rollno, marks);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct node* temp = *head;
        while (temp->link != NULL) {
            temp = temp->link;
        }
        temp->link = newNode;
    }
}

// Function to search for a record based on roll number
struct node* searchRecord(struct node *head, int rollno) {
    struct node* temp = head;
    while (temp != NULL) {
        if (temp->rollno == rollno) {
            return temp;
        }
        temp = temp->link;
    }
    return NULL;  // Return NULL if record not found
}

// Function to print the list of student records
void printRecords(struct node *head) {
    struct node* temp = head;
    while (temp != NULL) {
        printf("Name: %s, Roll No: %d, Marks: %d\n", temp->name, temp->rollno, temp->marks);
        temp = temp->link;
    }
}

// Main function to interact with the user
int main() {
    struct node *head = NULL;

    // Adding student records to the linked list
    addRecord(&head, "John", 101, 85);
    addRecord(&head, "Alice", 102, 92);
    addRecord(&head, "Bob", 103, 78);
    addRecord(&head, "Charlie", 104, 88);

    // Display the list of student records
    printf("Student Records:\n");
    printRecords(head);

    // Searching for a record based on roll number
    int rollnoToSearch;
    printf("\nEnter the roll number to search: ");
    scanf("%d", &rollnoToSearch);

    struct node* record = searchRecord(head, rollnoToSearch);
    if (record != NULL) {
        printf("Record found: Name: %s, Roll No: %d, Marks: %d\n", record->name, record->rollno, record->marks);
    } else {
        printf("No record found with roll number %d\n", rollnoToSearch);
    }

    return 0;
}
