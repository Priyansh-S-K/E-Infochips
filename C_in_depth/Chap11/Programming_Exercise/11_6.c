// Write a program to insert line numbers and page numbers in a file.

#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 1024

int main() {
    FILE *source, *destination;
    char line[MAX_LINE_LENGTH];
    int line_number = 1, page_number = 1;
    int lines_per_page = 20;  // Adjust this value as needed for your page length

    source = fopen("source.txt", "r");
    if (source == NULL) {
        perror("Error opening source file");
        return 1;
    }

    destination = fopen("destination.txt", "w");
    if (destination == NULL) {
        perror("Error opening destination file");
        fclose(source);
        return 1;
    }

    // Loop through each line in the source file
    while (fgets(line, sizeof(line), source)) {
        // Print page number at the beginning of each new page
        if (line_number == 1) {
            fprintf(destination, "Page %d\n\n", page_number);
        }

        // Insert line number at the beginning of each line
        fprintf(destination, "%d. %s", line_number, line);

        // Increment the line number and check for page overflow
        line_number++;
        if (line_number > lines_per_page) {
            page_number++;
            line_number = 1;
        }
    }

    fclose(source);
    fclose(destination);

    printf("File processed with line numbers and page numbers.\n");

    return 0;
}
