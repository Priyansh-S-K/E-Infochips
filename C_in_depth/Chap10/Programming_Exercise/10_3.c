/*/Write a program to accept 10 records with the structure
struct{
 char *name;
 int *age;
 float salary;
 }
 Display the records before sorting and after sorting. Sorting is based on the primary key ru
 and secondary keyage.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Employee {
    char *name;
    int age;
    float salary;
};

// Function to compare employees for sorting by salary and age
int compare(const void *a, const void *b) {
    struct Employee *empA = (struct Employee *)a;
    struct Employee *empB = (struct Employee *)b;

    // Primary key: compare salary
    if (empA->salary < empB->salary) {
        return -1;
    }
    if (empA->salary > empB->salary) {
        return 1;
    }

    // Secondary key: compare age
    if (empA->age < empB->age) {
        return -1;
    }
    if (empA->age > empB->age) {
        return 1;
    }

    return 0;
}

int main() {
    struct Employee employees[10];

    // Input details for 10 employees
    for (int i = 0; i < 10; i++) {
        employees[i].name = (char *)malloc(100 * sizeof(char));
        printf("Enter details for employee %d:\n", i + 1);

        printf("Name: ");
        fgets(employees[i].name, 100, stdin);
        employees[i].name[strcspn(employees[i].name, "\n")] = '\0';  // Remove newline character

        printf("Age: ");
        scanf("%d", &employees[i].age);

        printf("Salary: ");
        scanf("%f", &employees[i].salary);
        getchar();  // To consume the newline character left by scanf
    }

    // Display records before sorting
    printf("\nEmployee Records before Sorting:\n");
    for (int i = 0; i < 10; i++) {
        printf("Name: %s, Age: %d, Salary: %.2f\n", employees[i].name, employees[i].age, employees[i].salary);
    }

    // Sort employees based on salary (primary key) and age (secondary key)
    qsort(employees, 10, sizeof(struct Employee), compare);

    // Display records after sorting
    printf("\nEmployee Records after Sorting:\n");
    for (int i = 0; i < 10; i++) {
        printf("Name: %s, Age: %d, Salary: %.2f\n", employees[i].name, employees[i].age, employees[i].salary);
    }

    // Free dynamically allocated memory for names
    for (int i = 0; i < 10; i++) {
        free(employees[i].name);
    }

    return 0;
}
