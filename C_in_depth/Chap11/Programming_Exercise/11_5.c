//Write a program that concatenates any number of files and writes the ~utput in a destination file.
//The names of files should be passed through command line arguments.

#include <stdio.h>

int main(int argc, char *argv[]) {
    FILE *source, *destination;
    char ch;

    // Check if at least two arguments (including program name) are provided
    if (argc < 3) {
        printf("Usage: %s <source_file1> <source_file2> ... <destination_file>\n", argv[0]);
        return 1;
    }

    // Open the destination file in write mode
    destination = fopen(argv[argc - 1], "w");
    if (destination == NULL) {
        perror("Error opening destination file");
        return 1;
    }

    // Loop through all the source files passed as arguments
    for (int i = 1; i < argc - 1; i++) {
        source = fopen(argv[i], "r");
        if (source == NULL) {
            perror("Error opening source file");
            fclose(destination);
            return 1;
        }

        // Copy content of the current source file to the destination
        while ((ch = fgetc(source)) != EOF) {
            fputc(ch, destination);
        }

        fclose(source);
    }

    fclose(destination);

    printf("Files concatenated successfully into %s\n", argv[argc - 1]);

    return 0;
}
