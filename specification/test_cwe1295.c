
// File: test_cwe1295.c
// Compile with: gcc -o test_cwe1295 test_cwe1295.c -Wall -Wextra -Werror
// Run with: ./test_cwe1295

#include <stdio.h>
#include <stdlib.h>

// Property ID: SA-CWE-1295-1
// Type: Security
// Description: Detect use of deprecated or insecure functions.
// Validation Method: Pattern Matching
// Code Example (Non-Compliant): Using gets() function which is vulnerable to CWE-1295.
// Code Example (Compliant): Using fgets() function which is secure.

// Scenario 1: Valid CWE 1295 Detection
void test_cwe1295_vulnerable() {
    char buffer[10];
    // Non-Compliant: Using gets() function
    gets(buffer);  // CWE-1295: Use of deprecated or insecure function
}

// Scenario 2: CWE 1295 False Positive Check
void test_cwe1295_safe() {
    char buffer[10];
    // Compliant: Using fgets() function with proper handling
    if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        size_t len = strlen(buffer);
        if (len > 0 && buffer[len-1] == '\n') {
            buffer[len-1] = '\0';
        }
    }
}

// Scenario 3: CWE 1295 Absence Detection
void test_cwe1295_compliant() {
    char buffer[10];
    // Compliant: Using fgets() function
    fgets(buffer, sizeof(buffer), stdin);
}

// Scenario 4: Empty File Handling
// This file itself is not empty, but the logic can be tested by creating and analyzing an empty .c file.

// Scenario 5: Large File Performance
// This can be tested by creating a large file with multiple instances of CWE-1295 vulnerabilities.

// Scenario 6: Unsupported Syntax Handling
// This can be tested by inserting unsupported syntax in the file and analyzing it.

int main() {
    // This is a dummy main function to compile the file
    // Actual testing would be done with a static code analysis tool
    return 0;
}
