/*
Name:Denis Macharia
Reg No:CT100/G/26250/25
*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

// Function prototypes
void writeInputFile();
void processNumbers();
void displayFiles();

int main() {
    writeInputFile();     // Step 1: Get input and store in input.txt
    processNumbers();     // Step 2: Compute sum and average, store in output.txt
    displayFiles();       // Step 3: Display contents of both files
    return 0;
}

// ? Write integers to input.txt
void writeInputFile() {
    FILE *fptr;
    int num;

    fptr = fopen("input.txt", "w");
    if (fptr == NULL) {
        printf("Error opening file for writing!\n");
        exit(1);
    }

    printf("Enter %d integers:\n", SIZE);
    for (int i = 0; i < SIZE; i++) {
        scanf("%d", &num);
        fprintf(fptr, "%d ", num);
    }

    fclose(fptr);
    printf("Data successfully written to input.txt\n\n");
}

// ? Read integers, calculate sum & average, write to output.txt
void processNumbers() {
    FILE *inFile, *outFile;
    int num, count = 0, sum = 0;
    float avg;

    inFile = fopen("input.txt", "r");
    if (inFile == NULL) {
        printf("Error opening input.txt for reading!\n");
        exit(1);
    }

    while (fscanf(inFile, "%d", &num) == 1) {
        sum += num;
        count++;
    }

    fclose(inFile);

    if (count == 0) {
        printf("No numbers found in input.txt!\n");
        exit(1);
    }

    avg = (float)sum / count;

    outFile = fopen("output.txt", "w");
    if (outFile == NULL) {
        printf("Error opening output.txt for writing!\n");
        exit(1);
    }

    fprintf(outFile, "Sum = %d\nAverage = %.2f\n", sum, avg);
    fclose(outFile);
    printf("Results successfully written to output.txt\n\n");
}

// ? Display contents of both files
void displayFiles() {
    FILE *fptr;
    char ch;

    printf("--- Contents of input.txt ---\n");
    fptr = fopen("input.txt", "r");
    if (fptr == NULL) {
        printf("Error opening input.txt!\n");
        return;
    }
    while ((ch = fgetc(fptr)) != EOF)
        putchar(ch);
    fclose(fptr);

    printf("\n\n--- Contents of output.txt ---\n");
    fptr = fopen("output.txt", "r");
    if (fptr == NULL) {
        printf("Error opening output.txt!\n");
        return;
    }
    while ((ch = fgetc(fptr)) != EOF)
        putchar(ch);
    fclose(fptr);
}