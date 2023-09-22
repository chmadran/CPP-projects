NOTIONS

<h4>TO HEAP OR TO STACK</h4>

Dynamic allocation in C++ allows you to allocate memory at runtime, as opposed to static allocation which occurs at compile time. This is particularly useful when you need to work with data structures whose size isn't known until the program is running.

The dynamic allocation process involves two key operators:

new: This operator is used to allocate memory on the heap (free store in C++ terminology). It returns a pointer to the allocated memory.

`int* ptr = new int; // Allocates memory for an integer on the heap`

delete: This operator is used to deallocate memory that was previously allocated using new. It's important to free this memory when it's no longer needed to prevent memory leaks.

`delete ptr; // Deallocates memory pointed to by 'ptr'`


**Here's a step-by-step breakdown of dynamic allocation:**


Requesting Memory Allocation:

When you use new, the system is asked to allocate memory of a certain size. If successful, it returns a pointer to the allocated memory. If there isn't enough memory available, it returns a std::bad_alloc exception (if not caught, this will cause a program crash).

`int* ptr = new int; // Allocates memory for an integer on the heap`

Using the Allocated Memory:

You can now use the pointer ptr just like you would with a statically allocated variable : `*ptr = 42; // Assigning 42 to the dynamically allocated integer`


Deallocating Memory:

To prevent memory leaks, you must free the allocated memory using the delete operator when it's no longer needed.

`delete ptr; // Deallocates memory pointed to by 'ptr'`

Note: Always remember to delete the memory you allocate. Failing to do so will result in memory leaks, where memory is never returned to the system and can cause your program to consume excessive memory over time.

Deallocating Array:

If you dynamically allocate an array, you need to use delete[] instead of delete to free the entire array:

```
int* arr = new int[10]; // Allocates an array of 10 integers on the heap
delete[] arr; // Deallocates the entire array
```

Handling Allocation Failures:

It's important to check if dynamic memory allocation was successful, especially when working with large data structures. If new fails, it returns a null pointer. You should always check for this:

```
int* ptr = new(std::nothrow) int; // Does not throw an exception on failure
if (ptr == nullptr) {
    // Allocation failed, handle the error
}
```

Remember, dynamic memory management comes with added responsibility. You need to ensure that you free the allocated memory when you're done with it to avoid memory leaks. Additionally, be cautious about using raw pointers, as they can lead to memory management errors. Smart pointers and containers like std::vector can provide safer alternatives in many cases.

<details>
<summary>**Stack:**</summary>

Use the stack for small, short-lived variables that don't need to persist beyond the scope of the current block or function. This is often the default choice.

* Automatic Memory Management:  
The stack is used for local variables and function call management. When a function is called, its local variables are pushed onto the stack, and when the function returns, those variables are automatically popped off.

* Limited Size:  
The stack has a limited size, typically smaller than the heap. Exceeding the stack's capacity can lead to a stack overflow, causing a program crash.

* Faster Access:  
Accessing memory on the stack is generally faster than on the heap because it follows a simple and predictable pattern.

* Lifetime Tied to Scope:  
Variables allocated on the stack exist within the scope of the block they're defined in. They are automatically deallocated when the block ends.

</details>

<details>

<summary>**Heap:**</summary> 

Use the heap for larger objects that need to exist beyond the scope where they were created or when you need dynamic memory allocation (e.g., when the size of the data is not known at compile time).

For example, you'd use the stack for simple variables like integers, and the heap for things like dynamic arrays, complex data structures, or objects that need to exist outside of their creating function.

* Dynamic Memory Allocation:  
The heap is used for dynamic memory allocation, where you can allocate memory at runtime using functions like malloc() or new (in C++).

* Larger Size:  
The heap typically has more space than the stack. However, it's also more complex to manage.

* Manual Memory Management:  
Memory allocated on the heap needs to be manually deallocated when it's no longer needed. Forgetting to do so can lead to memory leaks.

* Indirect Access:  
Accessing memory on the heap involves using pointers, which can introduce more complexity and potential for errors.

</details>

<h4>REFERENCES AND POINTERS</h4>

<details>
<summary>Pointers:</summary>

**Declaration and Initialization:**
`std::string* stringPTR = &string;`

`std::string*` declares stringPTR as a pointer to a std::string.
`&string` gets the memory address of the string variable, and assigns it to stringPTR.

**Accessing Value through a Pointer:**

`*stringPTR`

The * operator is used to dereference the pointer, allowing you to access the value stored at the memory location it points to.

**Memory Addresses:**

&stringPTR would print the memory address of the pointer itself (not the memory address it's pointing to).

</details>

<details>

<summary>References:</summary>

**Declaration and Initialization:**

`std::string& stringREF = string;`

std::string& declares stringREF as a reference to a std::string.
string is assigned to stringREF.

**Accessing Value through a Reference:**

`stringREF` no need for dereferencing with *. A reference is treated as an alias to the variable it refers to.

**Memory Addresses:**

`&stringREF` would print the memory address of the string variable (because stringREF is an alias for string).

</details>

**Important Points:**

* Both pointers and references allow you to indirectly access variables.
* Pointers can be reassigned to point to different memory locations. References are constant aliases, once bound, they cannot be re-bound.
* Pointers can be null (pointing to nothing), references must always be bound to a valid object.
* Use pointers when you need the option to not point to anything (null), or when you want to change the object being pointed to.


<h4>FILE EXISTENCE</h4>

````
bool fileExists(const std::string& filename) {
		struct stat buffer;
		return (stat(filename.c_str(), &buffer) == 0);
}
```

`struct stat buffer:`

`struct stat` is a structure used to store information about files. It includes attributes like file size, permissions, and more.

buffer is an instance of this structure. It will be used to store information about the file specified by filename.

`stat(filename.c_str(), &buffer):`

stat is a system call in C/C++ that retrieves information about a specified file.

filename.c_str() converts the std::string filename to a C-style string (a null-terminated character array) which stat expects.
&buffer passes a pointer to the buffer structure. This is where stat will store information about the file.

`return (stat(filename.c_str(), &buffer) == 0):`

stat(filename.c_str(), &buffer) returns 0 if the file exists and the operation was successful, otherwise it returns a non-zero value.

The == 0 comparison checks if stat returned 0, which indicates a successful operation.

The result of this comparison (a boolean) is then returned by the function.

The function essentially checks if the file specified by filename exists on the file system. It does this by attempting to retrieve information about the file using stat. If stat returns 0, it means the file exists, and the function returns true. If stat returns a non-zero value, it means an error occurred or the file does not exist, and the function returns false.

This function is useful when you want to perform operations on a file, but you need to ensure that the file actually exists before proceeding.


<h4>OPENING FILES IN C++</h4>

In C++, you can open a file using the std::ifstream (input) or std::ofstream (output) classes from the <fstream> header. Here are examples of how to open a file for reading and writing:

<details> 

<summary>Opening a File for Reading (Input)</summary>

```
#include <iostream>
#include <fstream>

int main() {
    std::ifstream inputFile; // Create an input file stream object

    // Open the file
    inputFile.open("example.txt");

    // Check if the file was successfully opened
    if (!inputFile.is_open()) {
        std::cerr << "Error opening the file." << std::endl;
        return 1;
    }

    // Read from the file

    // Don't forget to close the file when you're done
    inputFile.close();

    return 0;
}
```

</details>


<details> 

<summary>Opening a File for Writing (Output)</summary>

```
#include <iostream>
#include <fstream>

int main() {
    std::ofstream outputFile; // Create an output file stream object

    // Open the file
    outputFile.open("output.txt");

    // Check if the file was successfully opened
    if (!outputFile.is_open()) {
        std::cerr << "Error opening the file." << std::endl;
        return 1;
    }

    // Write to the file

    // Don't forget to close the file when you're done
    outputFile.close();

    return 0;
}
```

</details>

<details> 

<summary>Opening a File for Appending</summary>

```
#include <iostream>
#include <fstream>

int main() {
    std::ofstream outputFile; // Create an output file stream object

    // Open the file in append mode
    outputFile.open("existing_file.txt", std::ios::app);

    // Check if the file was successfully opened
    if (!outputFile.is_open()) {
        std::cerr << "Error opening the file." << std::endl;
        return 1;
    }

    // Append data to the file

    // Don't forget to close the file when you're done
    outputFile.close();

    return 0;
}
```
</details>

<h4>FUNCTION POINTER</h4>