/* Consider this list of names of persons and cities
 Reeta·. Kanpur
 Alok- Rampur
 Reena- Rampur
 Deepali- Lucknow
 Suresh- Lucknow
 Saumya- Rampur
 Manish- Lucknow
 Divya-Kanpur
 Kriti-Renusagar
 Write a program such that ifa name ofa person is entered then the city is displayed and ifa city
 is entered then names.of all people living in that city are displayed.
 Hint: store the names of cities and persons in separate array of pointers to strings.*/

#include <stdio.h>
#include <string.h>

int main() {
    // Arrays of pointers to store names of persons and cities
    const char *persons[] = {
        "Reeta", "Alok", "Reena", "Deepali", "Suresh", "Saumya", "Manish", "Divya", "Kriti"
    };
    
    const char *cities[] = {
        "Kanpur", "Rampur", "Rampur", "Lucknow", "Lucknow", "Rampur", "Lucknow", "Kanpur", "Renusagar"
    };

    int numPersons = sizeof(persons) / sizeof(persons[0]);

    char input[100];

    // Input from the user (either a person's name or a city's name)
    printf("Enter a name or a city: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0'; // Remove newline character

    // Check if input is a name
    int found = 0;
    for (int i = 0; i < numPersons; i++) {
        if (strcmp(input, persons[i]) == 0) {
            printf("The city for %s is: %s\n", persons[i], cities[i]);
            found = 1;
            break;
        }
    }

    // If not a name, check if input is a city
    if (!found) {
        printf("People living in %s are:\n", input);
        found = 0;
        for (int i = 0; i < numPersons; i++) {
            if (strcmp(input, cities[i]) == 0) {
                printf("%s\n", persons[i]);
                found = 1;
            }
        }
    }

    // If no match found
    if (!found) {
        printf("No matching person or city found.\n");
    }

    return 0;
}
