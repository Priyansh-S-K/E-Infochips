/*//Write a program to ~ccept five records of employee. The structure is
struct{ .
 char name[25] ;
 int age;
 int basic;
 }
 Calculate the total slary of the employees as
Total salary = Basic + DA + HRA
 DA = 10% ofbasic
 HRA = 5% ofbasic
 Display the name, age and total salary ofthe employees in descending order on the basis of
 . salary..*/

 #include <stdio.h>

struct Employee {
    char name[25];
    int age;
    int basic;
    float totalSalary;
};

// Function to calculate the total salary of the employee
void calculateSalary(struct Employee *emp) {
    float DA = 0.10 * emp->basic;  // DA = 10% of basic salary
    float HRA = 0.05 * emp->basic; // HRA = 5% of basic salary
    emp->totalSalary = emp->basic + DA + HRA;  // Total salary = Basic + DA + HRA
}

// Function to compare employees based on total salary for sorting in descending order
int compareSalary(const void *a, const void *b) {
    struct Employee *empA = (struct Employee *)a;
    struct Employee *empB = (struct Employee *)b;

    // Sort in descending order of total salary
    if (empA->totalSalary < empB->totalSalary) {
        return 1;
    } else if (empA->totalSalary > empB->totalSalary) {
        return -1;
    }
    return 0;
}

int main() {
    struct Employee employees[5];

    // Input details for 5 employees
    for (int i = 0; i < 5; i++) {
        printf("Enter details for employee %d:\n", i + 1);

        printf("Name: ");
        fgets(employees[i].name, sizeof(employees[i].name), stdin);
        employees[i].name[strcspn(employees[i].name, "\n")] = '\0';  // Remove newline character

        printf("Age: ");
        scanf("%d", &employees[i].age);

        printf("Basic Salary: ");
        scanf("%d", &employees[i].basic);
        getchar();  // To consume the newline character left by scanf

        // Calculate the total salary for the employee
        calculateSalary(&employees[i]);
    }

    // Sort employees by total salary in descending order
    qsort(employees, 5, sizeof(struct Employee), compareSalary);

    // Display the name, age, and total salary of employees
    printf("\nEmployee Records (Sorted by Total Salary in Descending Order):\n");
    for (int i = 0; i < 5; i++) {
        printf("Name: %s, Age: %d, Total Salary: %.2f\n", employees[i].name, employees[i].age, employees[i].totalSalary);
    }

    return 0;
}
