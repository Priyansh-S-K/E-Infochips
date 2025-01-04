// Write a program to input a number from 0 to 6 and print the corresponding day using array of
// pointers. For example if 0 is entered then print Sunday, if 1 is entered print Monday

#include <stdio.h>

int main() {
    // Array of pointers to strings representing the days of the week
    const char *days[] = {
        "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"
    };

    int num;

    // Input the number from 0 to 6
    printf("Enter a number between 0 and 6: ");
    scanf("%d", &num);

    // Check if the input is valid
    if (num >= 0 && num <= 6) {
        // Print the corresponding day
        printf("The corresponding day is: %s\n", days[num]);
    } else {
        printf("Invalid input. Please enter a number between 0 and 6.\n");
    }

    return 0;
}
