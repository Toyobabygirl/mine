#include <stdio.h>
#include <stdlib.h>  
#include <string.h> 

 int main() {
    int total_byte_capacity;
    int memory_used = 0;
    int memory_available;
     

    printf("pleace enter the total byte capacity: ");

    scanf("%d",&total_byte_capacity);
    getchar() != '\n';

    if (scanf("%d", &total_byte_capacity) !=1 || total_byte_capacity <= 0){

        printf("the total byte of %d you inputed is not valid. \n");
        
        return 1;
       }

       // Allocating the virtual hard drive 
       char *ptr = (char *)malloc(total_byte_capacity);
        if (ptr == NULL) { 
            printf("Error: Memory allocation failed.\n");
             return 1;
             }
    memory_available = total_byte_capacity;


    int space_number;
    printf("YOUR VIRTUAL HARD DRIVE.\n");
    printf("please input your memory allocation: \n");
     while (1) {
        printf("Enter space number : ");

        if (scanf("%d", &space_number) != 1) {
            printf("Error: Invalid input.\n");
            
            // Clear invalid input
            while(getchar() != '\n');
            continue;
        }


        char data_type[30];
        int space_type;
        int size_Per_character = space_type;

        // printf("Enter data type /n charpress 1 /int press 2/float press 3/double press 4: \n");
        printf("Enter data type\n 1. char\n2. int\n3. float\n4. double\n");
        scanf("%s", data_type);

        
    // Determine size of data type
     if (scanf("%s, &space_type") == 1){
            size_Per_character = sizeof(char);
        }
        else if (scanf("%s, &space_type") == 2){
            size_Per_character = sizeof(int);
        }
        else if (scanf("%s, &space_type") == 3){
            size_Per_character = sizeof(float);
        }
        else if (scanf("%s, &space_type") == 4){
            size_Per_character = sizeof(double);
        }
        else {
            printf("Error: Data type unsuported.\n");
            continue;
        }

        int required_memory = size_Per_character * space_type;

         // Check if enough memory exists

        if (required_memory > memory_available) {
            printf("Memory allocation failed!\n");
            printf("Not enough available memory.\n");
            printf("Requested: %d bytes\n", required_memory);
            printf("Available: %d bytes\n", memory_available);
            continue;
        }

        // Allocate memory from virtual drive
    //    printf("allocated memory address: ",(void*)ptr);
    //   // void* prt(required_memory=memory_used, required_memory<memory_available, required_memory++);
    //    for (int memory_available = 0; memory_available < required_memory; memory_available++) {
    //     ptr[memory_available] = (required_memory + 1) * required_memory; 
    // }
       char *current_ptr_position = ptr + memory_used;
       printf("Current pointer position: %p\n", (void *)current_ptr_position);
        // Update memory statistics
        memory_used += required_memory;
        memory_available = total_byte_capacity - memory_used;

        // Display allocation success
        printf("\nMemory allocated is successfully!\n");
        printf("Data Type: %d\n", space_type);
        printf("Spaces Allocated: %d\n", space_number);
        printf("Memory Used for Request: %d bytes\n", required_memory);

        // Display memory in bytes
        printf("\n MEMORY STATUS \n");
        printf("Total Memory : %d bytes\n", total_byte_capacity);
        printf("Used Memory  : %d bytes\n", memory_used);
        printf("Free Memory  : %d bytes\n", memory_available);

    }

    // Free virtual hard drive memory
    free(ptr);

    return 0;


 }