
// SCENARIO 1: Valid CWE 1295 Detection

/* Property ID: SA-CWE1295-1
   Type: Security
   Description: Detect improper validation of resource existence or permissions
   Validation Method: Pattern Matching
   Code Example (Non-Compliant): Opening a file without checking if it exists
   Code Example (Compliant): Checking if a file exists before opening
*/

// Code Sample with CWE 1295 Vulnerability
#include <stdio.h>
#include <stdlib.h>

void vulnerable_function() {
    FILE *fp;
    fp = fopen("example.txt", "r");  // Non-Compliant: No existence check
    if (fp == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    fclose(fp);
}

// Scenario 1 Test Case
void test_scenario_1() {
    // Normally this would involve running a static analysis tool programmatically,
    // but for example purposes, we'll just print the function definition.
    printf("/* Vulnerable Function Definition */\n");
    printf("%s\n", vulnerable_function);
}

// SCENARIO 2: CWE 1295 False Positive Check

/* Property ID: SA-CWE1295-2
   Type: Security
   Description: Ensure no false positives for CWE 1295
   Validation Method: Pattern Matching
   Code Example (Non-Compliant): Opening a file without checking if it exists
   Code Example (Compliant): Checking if a file exists before opening
*/

// Safe Code Sample
#include <stdio.h>
#include <stdlib.h>

void safe_function() {
    FILE *fp;
    if (access("example.txt", F_OK) != -1) {  // Compliant: Checking if file exists
        fp = fopen("example.txt", "r");
        if (fp == NULL) {
            perror("Error opening file");
            exit(EXIT_FAILURE);
        }
        fclose(fp);
    } else {
        printf("File does not exist.\n");
    }
}

// Scenario 2 Test Case
void test_scenario_2() {
    // Normally this would involve running a static analysis tool programmatically,
    // but for example purposes, we'll just print the function definition.
    printf("/* Safe Function Definition */\n");
    printf("%s\n", safe_function);
}

// SCENARIO 3: CWE 1295 Absence Detection

/* Property ID: SA-CWE1295-3
   Type: Security
   Description: Ensure no CWE 1295 vulnerabilities are present
   Validation Method: Pattern Matching
   Code Example (Non-Compliant): Opening a file without checking if it exists
   Code Example (Compliant): Checking if a file exists before opening
*/

// Compliant Code Sample
#include <stdio.h>
#include <stdlib.h>

void compliant_function() {
    FILE *fp;
    if (access("example.txt", F_OK) != -1) {  // Compliant: Checking if file exists
        fp = fopen("example.txt", "r");
        if (fp == NULL) {
            perror("Error opening file");
            exit(EXIT_FAILURE);
        }
        fclose(fp);
    } else {
        printf("File does not exist.\n");
    }
}

// Scenario 3 Test Case
void test_scenario_3() {
    // Normally this would involve running a static analysis tool programmatically,
    // but for example purposes, we'll just print the function definition.
    printf("/* Compliant Function Definition */\n");
    printf("%s\n", compliant_function);
}

// SCENARIO 4: Empty File Handling

/* Property ID: SA-FILE-1
   Type: Robustness
   Description: Ensure the tool handles empty files gracefully
   Validation Method: Pattern Matching
   Code Example (Non-Compliant): Not applicable (empty file)
   Code Example (Compliant): Empty file
*/

// Empty File Test Case
void test_scenario_4() {
    // Normally this would involve running a static analysis tool on an empty file.
    // For example purposes, we'll just simulate an empty file scenario.
    printf("/* Empty File Handling */\n");
    printf("/* No code in this function to simulate an empty file */\n");
}

// SCENARIO 5: Large File Performance

/* Property ID: SA-PERF-1
   Type: Performance
   Description: Ensure the tool performs well on large files
   Validation Method: Performance Profiling
   Code Example (Non-Compliant): Not applicable (large file with vulnerabilities)
   Code Example (Compliant): Large file with vulnerabilities
*/

// Large File with Vulnerabilities Test Case
void test_scenario_5() {
    // Normally this would involve running a static analysis tool on a large file.
    // For example purposes, we'll just simulate a large file with vulnerabilities.
    printf("/* Large File with Vulnerabilities Handling */\n");
    printf("/* This function would be defined in a large file with many similar vulnerabilities */\n");
    printf("%s\n", vulnerable_function);  // Reusing the vulnerable function for simplicity
}

// SCENARIO 6: Unsupported Syntax Handling

/* Property ID: SA-SYNTAX-1
   Type: Robustness
   Description: Ensure the tool handles unsupported syntax gracefully
   Validation Method: Error Detection
   Code Example (Non-Compliant): Unsupported syntax
   Code Example (Compliant): None
*/

// Unsupported Syntax Test Case
void test_scenario_6() {
    // Normally this would involve running a static analysis tool on a file with unsupported syntax.
    // For example purposes, we'll just simulate an unsupported syntax scenario.
    printf("/* Unsupported Syntax Handling */\n");
    printf("/* This code uses an unsupported syntax construct */\n");
    printf("int main() { int a = 10; if (a = 5) { /* Unsupported syntax */ }");
}
