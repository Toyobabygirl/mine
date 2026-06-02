#include <stdio.h>
#include <stdlib.h>   
 // For storing the allocation details
struct Allocation{
    char type[30];
    int A;
    int Amountofbyteused;

};

 int main() {
    int totalbytecapacity;
    int memoryused = 0;
    int memoryavailable;
     

    printf("pleace enter the total byte capacity:   ");

    scanf("%d",&totalbytecapacity);

    if (scanf("%d", &totalbytecapacity) !=1 || totalbytecapacity <= 0){

        printf("the total byte of %d you inputed is not valid. \n");
        
        return 1;
       }

       // Allocating the virtual hard drive 
       char *virtualDrive = (char *)malloc(totalbytecapacity);
        if (virtualDrive == NULL) { 
            printf("Error: Memory allocation failed.\n");
             return 1;
             }
    memoryavailable = totalbytecapacity;


    int N;
     while (1) {
        printf("\nYOUR VIRTUAL HARD DRIVE.\n");
        printf("please input your memory allocation:\n");
        printf("Enter N: ");

        if (scanf("%d", &N) != 1) {
            printf("Error: Invalid input.\n");
            
            // Clear invalid input
            while(getchar() != '\n');
            continue;
        }


        char dataType[30];
        int A;
        int sizePercharacter = 0;

        printf("Enter data type (char/int/float/double): ");
        scanf("%s", dataType);

        printf("Enter number of spaces required: ");
        
        if (scanf("%d", &A) != 1 || A <= 0) {
            printf("Invalid number.\n");
            getchar() != '\n';
            continue;
        }
         // Determine size of data type
        if (strcmp(dataType, "char") == 0) {
            sizePercharacter = sizeof(char);
        }
        else if (strcmp(dataType, "int") == 0) {
            sizePercharacter = sizeof(int);
        }
        else if (strcmp(dataType, "float") == 0) {
            sizePercharacter = sizeof(float);
        }
        else if (strcmp(dataType, "double") == 0) {
            sizePercharacter = sizeof(double);
        }
        else {
            printf("Error: Data type unsuported.\n");
            continue;
        }

        int requiredMemory = sizePercharacter * A;

         // Check if enough memory exists

        if (requiredMemory > memoryavailable) {
            printf("Memory allocation failed!\n");
            printf("Not enough available memory.\n");
            printf("Requested: %d bytes\n", requiredMemory);
            printf("Available: %d bytes\n", memoryavailable);
            continue;
        }

        // Allocate memory from virtual drive
        void *ptr = malloc(requiredMemory);

        if (ptr == NULL) {
            printf("Error: Dynamic allocation failed.\n");
            continue;
        }

        // Update memory statistics
        memoryused += requiredMemory;
        memoryavailable = totalbytecapacity - memoryused;

        // Display allocation success
        printf("\nMemory allocated is successfully!\n");
        printf("Data Type: %s\n", dataType);
        printf("Spaces Allocated: %d\n", A);
        printf("Memory Used for Request: %d bytes\n", requiredMemory);

        // Display memory statistics
        printf("\n MEMORY STATUS \n");
        printf("Total Memory : %d bytes\n", totalbytecapacity);
        printf("Used Memory  : %d bytes\n", memoryused);
        printf("Free Memory  : %d bytes\n", memoryavailable);

        // Free allocated block after simulation
        free(ptr);
    }

    // Free virtual hard drive memory
    free(virtualDrive);

    return 0;


 }