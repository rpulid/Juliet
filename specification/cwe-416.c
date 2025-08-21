
// SA-MEM-1
// Type: Memory Safety
// Description: The code must not use a pointer after it has been freed.
// Validation Method: Data Flow Analysis
// Code Example (Non-Compliant):
// int *ptr = (int *)malloc(sizeof(int));
// free(ptr);
// *ptr = 10;  // Use after free

// Code Example (Compliant):
// int *ptr = (int *)malloc(sizeof(int));
// *ptr = 10;
// free(ptr);

// SA-MEM-2
// Type: Memory Safety
// Description: The code must not use a pointer after it has been freed, even with conditional statements.
// Validation Method: Data Flow Analysis
// Code Example (Non-Compliant):
// int *ptr = (int *)malloc(sizeof(int));
// free(ptr);
// if (some_condition) {
//     *ptr = 10;  // Use after free
// }

// Code Example (Compliant):
// int *ptr = (int *)malloc(sizeof(int));
// if (some_condition) {
//     *ptr = 10;
// }
// free(ptr);

// SA-MEM-3
// Type: Memory Safety
// Description: The code must not produce false positives for use after free when no use after free occurs.
// Validation Method: Data Flow Analysis
// Code Example (Non-Compliant):
// int *ptr = (int *)malloc(sizeof(int));
// *ptr = 10;
// free(ptr);
// // No use after free, but tool flags it

// Code Example (Compliant):
// int *ptr = (int *)malloc(sizeof(int));
// *ptr = 10;
// free(ptr);
// // No use after free, tool does not flag it

// SA-MEM-4
// Type: Memory Safety
// Description: The code must not use a pointer after it has been freed, even if it is reallocated immediately.
// Validation Method: Data Flow Analysis
// Code Example (Non-Compliant):
// int *ptr = (int *)malloc(sizeof(int));
// free(ptr);
// *ptr = 10;  // Use after free
// ptr = (int *)malloc(sizeof(int));

// Code Example (Compliant):
// int *ptr = (int *)malloc(sizeof(int));
// free(ptr);
// ptr = (int *)malloc(sizeof(int));
// *ptr = 10;

// SA-MEM-5
// Type: Memory Safety
// Description: The code must not use a pointer after it has been freed in a different scope.
// Validation Method: Data Flow Analysis
// Code Example (Non-Compliant):
// void some_function() {
//     int *ptr = (int *)malloc(sizeof(int));
//     free(ptr);
// }
// void another_function() {
//     *ptr = 10;  // Use after free
// }

// Code Example (Compliant):
// int *ptr;
// void some_function() {
//     ptr = (int *)malloc(sizeof(int));
//     free(ptr);
// }
// void another_function() {
//     // No use after free
// }

// SA-MEM-6
// Type: Memory Safety
// Description: The code must not use a pointer after it has been freed, even with nested functions.
// Validation Method: Data Flow Analysis
// Code Example (Non-Compliant):
// void nested_function(int *ptr) {
//     *ptr = 10;  // Use after free
// }
// void some_function() {
//     int *ptr = (int *)malloc(sizeof(int));
//     free(ptr);
//     nested_function(ptr);
// }

// Code Example (Compliant):
// void nested_function(int *ptr) {
//     *ptr = 10;
// }
// void some_function() {
//     int *ptr = (int *)malloc(sizeof(int));
//     nested_function(ptr);
//     free(ptr);
// }
