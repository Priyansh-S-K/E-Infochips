//Write a program to accept name and arrival time offive trains and display the name with Rail
// time format.
// (Note: For example 2PM is written as 14.00 )

#include <stdio.h>
#include <string.h>

struct Train {
    char name[100];
    int hour;
    int minute;
};

void convertToRailTime(int hour, int minute) {
    if (hour < 10) {
        printf("0%d:", hour);
    } else {
        printf("%d:", hour);
    }

    if (minute < 10) {
        printf("0%d", minute);
    } else {
        printf("%d", minute);
    }
}

int main() {
    struct Train trains[5];  // Array to store details of 5 trains

    // Input details for 5 trains
    for (int i = 0; i < 5; i++) {
        printf("Enter details for train %d:\n", i + 1);
        
        printf("Train Name: ");
        fgets(trains[i].name, sizeof(trains[i].name), stdin);
        trains[i].name[strcspn(trains[i].name, "\n")] = '\0';  // Remove newline character
        
        printf("Arrival Hour (24-hour format): ");
        scanf("%d", &trains[i].hour);
        
        printf("Arrival Minute: ");
        scanf("%d", &trains[i].minute);
        getchar();  // To consume the newline character left by scanf
    }

    // Display train names and arrival times in Rail time format
    printf("\nTrain Arrival Times in Rail Time Format:\n");
    for (int i = 0; i < 5; i++) {
        printf("Train %d: %s, Arrival Time: ", i + 1, trains[i].name);
        convertToRailTime(trains[i].hour, trains[i].minute);
        printf("\n");
    }

    return 0;
}
