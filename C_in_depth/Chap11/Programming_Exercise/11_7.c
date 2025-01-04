/* Consider this structure
struct {
 char name;
 int age;
 int sal;
 }
 
  Write a program to store 10 records of this structure in the file and sort them on the basis of
 name and age, where name is the primary key and age is secondary key.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 10

// Define the structure
struct Employee {
    char name[50];
    int age;
    int sal;
};

// Function to compare two records based on name (primary key) and age (secondary key)
int compare(const void *a, const void *b) {
    struct Employee *emp1 = (struct Employee *)a;
    struct Employee *emp2 = (struct Employee *)b;

    // Compare by name (primary key)
    int name_compare = strcmp(emp1->name, emp2->name);
    if (name_compare != 0) {
        return name_compare;
    }
    // If names are the same, compare by age (secondary key)
    return emp1->age - emp2->age;
}

int main() {
    FILE *file;
    struct Employee employees[MAX_RECORDS];
    int i;

    // Open file to store records
    file = fopen("employee_records.dat", "wb");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    // Input 10 records
    printf("Enter 10 employee records (name, age, salary):\n");
    for (i = 0; i < MAX_RECORDS; i++) {
        printf("Enter name for employee %d: ", i + 1);
        scanf("%s", employees[i].name);
        printf("Enter age for employee %d: ", i + 1);
        scanf("%d", &employees[i].age);
        printf("Enter salary for employee %d: ", i + 1);
        scanf("%d", &employees[i].sal);
    }

    // Write the records to the file
    fwrite(employees, sizeof(struct Employee), MAX_RECORDS, file);
    fclose(file);

    // Open the file again to read and sort the records
    file = fopen("employee_records.dat", "rb");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    // Read the records from the file
    fread(employees, sizeof(struct Employee), MAX_RECORDS, file);
    fclose(file);

    // Sort the records using qsort
    qsort(employees, MAX_RECORDS, sizeof(struct Employee), compare);

    // Open the file to overwrite sorted records
    file = fopen("employee_records.dat", "wb");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    // Write the sorted records back to the file
    fwrite(employees, sizeof(struct Employee), MAX_RECORDS, file);
    fclose(file);

    // Print the sorted records
    printf("\nSorted employee records (by name and age):\n");
    for (i = 0; i < MAX_RECORDS; i++) {
        printf("Name: %s, Age: %d, Salary: %d\n", employees[i].name, employees[i].age, employees[i].sal);
    }

    return 0;
}
