//Write a program to accept name, age and address of five persons and display the name of each person.

#include <stdio.h>

struct Person {
    char name[100];
    int age;
    char address[200];
};

int main() {
    struct Person persons[5];  // Array to store details of 5 persons

    // Input details for 5 persons
    for (int i = 0; i < 5; i++) {
        printf("Enter details for person %d:\n", i + 1);
        
        printf("Name: ");
        fgets(persons[i].name, sizeof(persons[i].name), stdin);
        persons[i].name[strcspn(persons[i].name, "\n")] = '\0';  // Remove newline character
        
        printf("Age: ");
        scanf("%d", &persons[i].age);
        getchar();  // To consume the newline character left by scanf
        
        printf("Address: ");
        fgets(persons[i].address, sizeof(persons[i].address), stdin);
        persons[i].address[strcspn(persons[i].address, "\n")] = '\0';  // Remove newline character
    }

    // Display the names of all persons
    printf("\nNames of persons entered:\n");
    for (int i = 0; i < 5; i++) {
        printf("Person %d: %s\n", i + 1, persons[i].name);
    }

    return 0;
}
