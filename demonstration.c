#include <stdio.h>

int main() {
    FILE *filePointer;

    filePointer = fopen("example.txt", "w");

    if (filePointer == NULL) {
        printf("Error opening the file.\n");
        return 1; 
    }

    fprintf(filePointer, "Hello, this is a demonstration of file primitives in C!\n");
    fprintf(filePointer, "You can use fprintf to write formatted data to a file.\n");

    fclose(filePointer);

    printf("Data has been written to the file successfully.\n");

    return 0;
}
