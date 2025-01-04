//Write a program to accept any 10 names and display those names after sorting them alphabetically
// in descending order.

#include <stdio.h>
#include <string.h>

#define MAX 10
#define NAME_LEN 100

void sortNamesDescending(char names[MAX][NAME_LEN], int n) {
    char temp[NAME_LEN];
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(names[i], names[j]) < 0) {
                // Swap names[i] and names[j] for descending order
                strcpy(temp, names[i]);
                strcpy(names[i], names[j]);
                strcpy(names[j], temp);
            }
        }
    }
}

int main() {
    char names[MAX][NAME_LEN];
    int n = MAX;

    // Input 10 names
    printf("Enter 10 names:\n");
    for (int i = 0; i < n; i++) {
        printf("Name %d: ", i + 1);
        fgets(names[i], NAME_LEN, stdin);
        // Remove trailing newline character
        names[i][strcspn(names[i], "\n")] = '\0';
    }

    // Sort names in descending alphabetical order
    sortNamesDescending(names, n);

    // Display sorted names
    printf("\nNames sorted in descending order:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", names[i]);
    }

    return 0;
}
