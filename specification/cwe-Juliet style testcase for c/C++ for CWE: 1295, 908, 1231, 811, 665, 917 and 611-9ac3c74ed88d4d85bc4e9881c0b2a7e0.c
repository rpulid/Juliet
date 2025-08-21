
// cwe1295_violation.cpp
// Property ID: SA-MEM-1
// Type: Memory Safety
// Description: CWE-1295 - Use of Incorrectly Calculated Length Value in read, write, copy, or allocation
// Validation Method: Pattern Matching
// Code Example (Non-Compliant): Reading a file into a buffer with incorrect size calculation

#include <fstream>
#include <iostream>

void read_file(const char* filename) {
    std::ifstream file(filename, std::ios::binary);
    if (!file) {
        std::cerr << "Failed to open file" << std::endl;
        return;
    }

    file.seekg(0, std::ios::end);
    std::streampos length = file.tellg();
    file.seekg(0, std::ios::beg);

    char* buffer = new char[length];  // Non-Compliant: Length not adjusted for null terminator
    file.read(buffer, length);
    buffer[length] = '\0';  // Out of bounds write

    std::cout << buffer << std::endl;
    delete[] buffer;
}

int main() {
    read_file("example.txt");
    return 0;
}

// Code Example (Compliant): Reading a file into a buffer with correct size calculation

// #include <fstream>
// #include <iostream>
//
// void read_file(const char* filename) {
//     std::ifstream file(filename, std::ios::binary);
//     if (!file) {
//         std::cerr << "Failed to open file" << std::endl;
//         return;
//     }
//
//     file.seekg(0, std::ios::end);
//     std::streampos length = file.tellg();
//     file.seekg(0, std::ios::beg);
//
//     char* buffer = new char[length + 1];  // Allocate space for null terminator
//     file.read(buffer, length);
//     buffer[length] = '\0';  // Safely add null terminator
//
//     std::cout << buffer << std::endl;
//     delete[] buffer;
// }
//
// int main() {
//     read_file("example.txt");
//     return 0;
// }


pp
// cwe908_violation.cpp
// Property ID: SA-SEC-1
// Type: Security
// Description: CWE-908 - Use of Untrusted Pointer as Buffer Address
// Validation Method: Pattern Matching
// Code Example (Non-Compliant): Using an untrusted pointer as buffer address

#include <iostream>
#include <cstring>

void process_data(char* data) {
    char buffer[10];
    std::strcpy(buffer, data);  // Non-Compliant: Untrusted pointer used as source
    std::cout << buffer << std::endl;
}

int main() {
    process_data("This is a long string that will cause buffer overflow");
    return 0;
}

// Code Example (Compliant): Using a trusted pointer as buffer address

// #include <iostream>
// #include <cstring>
//
// void process_data(const char* data) {
//     if (std::strlen(data) >= 10) {
//         std::cerr << "Data too long" << std::endl;
//         return;
//     }
//
//     char buffer[10];
//     std::strcpy(buffer, data);  // Compliant: Data length checked before copying
//     std::cout << buffer << std::endl;
// }
//
// int main() {
//     process_data("Short");
//     return 0;
// }
```

```cpp
// cwe1231_violation.cpp
// Property ID: SA-SEC-2
// Type: Security
// Description: CWE-1231 - Incorrect Calculation of Buffer Size
// Validation Method: Pattern Matching
// Code Example (Non-Compliant): Incorrect calculation of buffer size

#include <cstring>
#include <iostream>

void process_data(const char* data) {
    char buffer[sizeof(data)];  // Non-Compliant: sizeof(data) is size of pointer, not data
    std::strcpy(buffer, data);
    std::cout << buffer << std::endl;
}

int main() {
    process_data("Sample data");
    return 0;
}

// Code Example (Compliant): Correct calculation of buffer size

// #include <cstring>
// #include <iostream>
//
// void process_data(const char* data) {
//     char buffer[256];  // Compliant: Use fixed size larger than expected input
//     std::strncpy(buffer, data, sizeof(buffer) - 1);
//     buffer[sizeof(buffer) - 1] = '\0';  // Ensure null termination
//     std::cout << buffer << std::endl;
// }
//
// int main() {
//     process_data("Sample data");
//     return 0;
// }
```

```cpp
// cwe811_violuation.cpp
// Property ID: SA-SEC-3
// Type: Security
// Description: CWE-811 - Improper Restriction of Numeric Types in Event-Driven Application Without Input Validation
// Validation Method: Pattern Matching
// Code Example (Non-Compliant): Missing input validation for numeric types

#include <iostream>

void process_number(int number) {
    if (number < 0 || number > 100) {
        std::cerr << "Invalid number" << std::endl;
        return;
    }

    char buffer[number];  // Non-Compliant: Variable length array based on user input
    std::memset(buffer, 0, number);
    std::cout << "Processed number: " << number << std::endl;
}

int main() {
    process_number(500);  // Exploit large number to cause stack overflow
    return 0;
}

// Code Example (Compliant): Validating input before using it

// #include <iostream>
//
// void process_number(int number) {
//     const int MAX_SIZE = 100;
//     if (number < 0 || number > MAX_SIZE) {
//         std::cerr << "Invalid number" << std::endl;
//         return;
//     }
//
//     char buffer[MAX_SIZE];  // Compliant: Use fixed size array
//     std::memset(buffer, 0, sizeof(buffer));
//     std::cout << "Processed number: " << number << std::endl;
// }
//
// int main() {
//     process_number(50);
//     return 0;
// }
```

```cpp
// cwe665_violation.cpp
// Property ID: SA-MEM-2
// Type: Memory Safety
// Description: CWE-665 - Improper Initialization
// Validation Method: Pattern Matching
// Code Example (Non-Compliant): Uninitialized variable used

#include <iostream>

void print_value() {
    int value;  // Non-Compliant: Uninitialized variable
    std::cout << "Value: " << value << std::endl;
}

int main() {
    print_value();
    return 0;
}

// Code Example (Compliant): Variable initialized before use

// #include <iostream>
//
// void print_value() {
//     int value = 0;  // Compliant: Variable initialized to 0
//     std::cout << "Value: " << value << std::endl;
// }
//
// int main() {
//     print_value();
//     return 0;
// }
```

```cpp
// cwe917_violation.cpp
// Property ID: SA-CSS-1
// Type: Code Style
// Description: CWE-917 - Use of a Variable After It Should Be Invalidated
// Validation Method: Data Flow Analysis
// Code Example (Non-Compliant): Using a pointer after it has been freed

#include <iostream>

void process_data() {
    int* data = new int(10);
    std::cout << "Data: " << *data << std::endl;
    delete data;
    std::cout << "Freed Data: " << *data << std::endl;  // Non-Compliant: Use after free
}

int main() {
    process_data();
    return 0;
}

// Code Example (Compliant): Invalidating pointer after it has been freed

// #include <iostream>
//
// void process_data() {
//     int* data = new int(10);
//     std::cout << "Data: " << *data << std::endl;
//     delete data;
//     data = nullptr;  // Compliant: Set pointer to nullptr after freeing
//     // std::cout << "Freed Data: " << *data << std::endl;  // This would now be a compile-time error
// }
//
// int main() {
//     process_data();
//     return 0;
// }
```

```cpp
// cwe611_violation.cpp
// Property ID: SA-SEC-4
// Type: Security
// Description: CWE-611 - Improper Restriction of XML External Entity Reference
// Validation Method: Pattern Matching
// Code Example (Non-Compliant): XML parser allowing external entities

#include <iostream>
#include <libxml/parser.h>
#include <libxml/tree.h>

void parse_xml(const char* xml_data) {
    xmlDoc* doc = xmlReadMemory(xml_data, strlen(xml_data), "noname.xml", NULL, 0);  // Non-Compliant: No disallowing of external entities
    if (doc == NULL) {
        std::cerr << "Failed to parse XML" << std::endl;
        return;
    }

    xmlFreeDoc(doc);
    xmlCleanupParser();
}

int main() {
    const char* xml_data = "<!DOCTYPE foo [ <!ENTITY xxe SYSTEM \"file:///etc/passwd\" > ]><foo>&xxe;</foo>";
    parse_xml(xml_data);
    return 0;
}

// Code Example (Compliant): XML parser disallowing external entities

// #include <iostream>
// #include <libxml/parser.h>
// #include <libxml/tree.h>
//
// void parse_xml(const char* xml_data) {
//     xmlParserCtxtPtr ctxt = xmlNewParserCtxt();
//     if (ctxt == NULL) {
//         std::cerr << "Failed to create parser context" << std::endl;
//         return;
//     }
//
//     xmlCtxtUseOptions(ctxt, XML_PARSE_NONET);  // Compliant: Disallow network access
//     xmlDoc* doc = xmlCtxtReadMemory(ctxt, xml_data, strlen(xml_data), "noname.xml", NULL, 0);
//     if (doc == NULL) {
//         std::cerr << "Failed to parse XML" << std::endl;
//         xmlFreeParserCtxt(ctxt);
//         return;
//     }
//
//     xmlFreeDoc(doc);
//     xmlFreeParserCtxt(ctxt);
//     xmlCleanupParser();
// }
//
// int main() {
//     const char* xml_data = "<!DOCTYPE foo [ <!ENTITY xxe SYSTEM \"file:///etc/passwd\" > ]><foo>&xxe;</foo>";
//     parse_xml(xml_data);
//     return 0;
// }
```