<h4> CHOOSING THE CORRECT CONTAINER, EX00 </h4>

To choose the correct container for your C++ program to store the Bitcoin price data from the CSV file and efficiently retrieve values based on dates, you can consider using a data structure like a std::map or std::unordered_map. These containers provide efficient key-value lookup, which is suitable for your task where you need to associate dates with their corresponding Bitcoin prices.

Here's how you can choose between `std::map` and `std::unordered_map`:

<details>
<summary>std::map:</summary>

 The std::map is a standard template library (STL) container in C++ that represents an associative array. It stores elements in a sorted order based on their keys, and provides fast lookup, insertion, and deletion of elements. Specifically, std::map is implemented as a self-balancing binary search tree (usually a Red-Black Tree), which ensures efficient performance for various operations. Note that `std::map enforces` unique keys meaning that if you try to insert a key that already exists, the value associated with that key will be updated.

* Use a `std::map` if you want to store the data in a sorted order based on dates. This can be useful if you need to retrieve data in a chronological order.

* `std::map` uses a binary search tree (typically a Red-Black Tree) internally, which keeps the elements sorted by the key (date in your case).
This container provides logarithmic time complexity for insertion and retrieval operations.

Here are some key characteristics and functions associated with `std::map`:

**Declaration and Initialization:**
```
#include <map>

std::map<KeyType, ValueType> mapName;
```

`KeyType` is the type of the key (e.g., std::string for dates in your case).
`ValueType` is the type of the value associated with each key (e.g., float for Bitcoin prices).

**Inserting Elements:**

```
mapName[key] = value;  // Direct assignment
mapName.insert(std::make_pair(key, value));  // Using insert function
```

**Accessing Elements**

```
ValueType value = mapName[key]; // Retrieves the value associated with the key.
```

**Checking if a key exists**

```
if (mapName.find(key) != mapName.end()) {
    // Key exists in the map
}
```

**Iterating over elements**

```
for (auto it = mapName.begin(); it != mapName.end(); ++it) {
    KeyType key = it->first;
    ValueType value = it->second;
    // Do something with key and value
}
```
**Erasing Elements, getting size of the map...**

```
mapName.erase(key); // Removes the element with the specified key
```

</details>

<details> <summary>STD::RUNTIME_ERROR VS WHAT()</summary>

**Custom Exception Class:**

The key difference is that the first code snippet is about creating a custom exception class, which allows you to define your own types of exceptions with custom behavior. The second code snippet is actually throwing an instance of an existing exception class, std::runtime_error, which is part of the standard C++ library.

```
class FileNotOpen: public std::exception 
{
    public:
        virtual const char* what() const throw();
};

const char* BitcoinExchange::FileNotOpen::what() const throw(){
    return ("there was an error opening a file.");
};
```

* This code defines a custom exception `class FileNotOpen` that inherits from `std::exception`. This means `FileNotOpen` is a type of exception.

* The `FileNotOpen` class overrides the what function, which is a virtual function defined in `std::exception`. The what function is used to provide a description of the exception.

* In this case, when an instance of `FileNotOpen` is thrown, it will return the error message "there was an error opening a file." when the what function is called.

```
throw std::runtime_error("too large number");
```

* This line is throwing an instance of `std::runtime_error`, which is a standard C++ exception class. It takes a string message as an argument.

* This type of exception is used to indicate a runtime error. If this exception is thrown and not caught, it will propagate up the call stack until it is caught by an appropriate catch block.

So, to summarize:

The first code snippet is about defining a custom exception class with its own behavior and message.
The second code snippet is about throwing an instance of an existing exception class with a specific error message.

Both approaches have their use cases. Creating a custom exception class can be useful when you have specific types of errors that need specialized handling. Throwing standard library exceptions is appropriate for common error conditions that don't need custom behavior.

</details>

STEP BY STEP EX00 : 
*	Constructeur cree avec en parametre le data file et l'input file avec les queries
*	Si l'input file n'est pas donne ou s'il est vide, throw an error
*	Sinon, remplir le container "map" avec le file data
*	Make sure to exit if the data file cannot be read or if one of the value is a float
*	Then getline on the input file, check if date is valid or find closest, check if value is valid
*	If both are fine, then print with the required format

<h4> STD::STACK, ex01</h4>

<details>
<summary> std:stack</summary>

Certainly! In C++, a stack is a container that provides a Last-In, First-Out (LIFO) data structure. This means that the last element added to the stack is the first one to be removed.

<h6>Characteristics of a Stack:</h6>

**LIFO Structure:**
* The last element added to the stack is the first one to be removed.

**Operations:**
* `push(element):` Adds an element to the top of the stack.
* `pop():` Removes the top element from the stack.
* `top():` Returns a reference to the top element without removing it.
* `empty():` Checks if the stack is empty.
* `size():` Returns the number of elements in the stack.

**Implementation:**
* Stacks can be implemented using various data structures like arrays, linked lists, or dynamically resizing arrays (e.g., `std::vector` in C++).

**Usage:**
* Stacks are used in various algorithms and applications, such as expression evaluation, parsing, recursion, undo functionality in applications, and more.

**C++ Stack Container (std::stack):**
* In C++, the Standard Template Library (STL) provides a container called std::stack which is an adapter class that uses other containers (like std::deque, std::vector, or std::list) as its underlying implementation. It provides the stack functionality with an easy-to-use interface.

</details>

STEP BY STEP EX01 : 
*	put all constructors in private except the one that takes a string as argument
*	when initialising, parse the input by checking : numbers < 10, only valid operators 
*	if you have a valid operator and the stack is at least 2 numbers, then launch the processor

<details> <summary> std::istringstream</summary>


In the context of the code you provided, a "token" refers to a single unit or element extracted from the input string. In this case, a token could be a number (e.g., "123"), an operator (e.g., "+"), or any other valid element in the expression.   

The std::istringstream object (iss) identifies tokens based on whitespace characters (spaces, tabs, newlines, etc.). When you use the >> operator with iss, it reads from the stream until it encounters a whitespace character. It then considers the characters it has read as a single token.   

For example, if input is the string "123 + 45 * 6", then the tokens extracted from iss would be:   

"123"   
"+"   
"45"   
"*"   
"6"   

The while (iss >> token) loop continues until there are no more tokens to extract. In each iteration, iss >> token attempts to extract a token and store it in the token variable. If successful, the loop continues; if no more tokens can be extracted (usually because the end of the string has been reached), the loop terminates.   

Keep in mind that the behavior of iss >> token can vary depending on the formatting of the input string. For example, if the input string used a different delimiter (e.g., commas), you might need to customize how tokens are identified and extracted.   

</details>

<details> <summary> MERGE-INSERT sort algorithm </summary>

The "merge-insert" sort algorithm is a hybrid sorting algorithm that combines the principles of both merge sort and insertion sort. This approach is particularly useful for sorting sequences of data that may have some pre-existing order, as it can take advantage of this order to achieve better performance.


<details> </summary> Merge Sort:</summary>
Merge sort is a classic, efficient, and stable comparison-based sorting algorithm. It follows the "divide and conquer" paradigm. Here's how it works:

* Divide: The unsorted list is divided into two equal halves (or approximately equal if the size is odd).

* Conquer: Each half is recursively sorted. This process continues until we reach a base case where the list contains only one element (which is already considered sorted).

* Merge: The sorted halves are then merged back together. During this process, the elements are compared and arranged in the correct order.

The merge step is the most crucial part of merge sort and is where the algorithm gets its name.

* Base Case: The recursion stops when the list size is reduced to one or zero, as a list of one or zero elements is inherently sorted.

Merge sort has an average and worst-case time complexity of O(n log n), making it very efficient for large data sets. It's also a stable sorting algorithm, meaning that the relative order of equal elements is preserved.
</details>


<details>
<summary>Insert Sort</summary>

Insertion sort is a simple and intuitive sorting algorithm that builds the final sorted array one element at a time. It works like this:

* Construction of the Sorted Array: The algorithm starts with the second element in the array (assuming the first element is considered to be already sorted).

* Comparisons and Swaps: It compares the current element with the previous elements in the sorted section. If the current element is smaller, it's moved to the appropriate position in the sorted section.

This process is repeated for all elements in the array, effectively constructing a sorted section at the beginning.
Insertion sort has an average and worst-case time complexity of O(n^2), which makes it less efficient than more advanced algorithms like merge sort for large data sets. However, it has low constant factors and performs well on nearly sorted data or small lists.

It's worth noting that for small input sizes, insertion sort can outperform more complex algorithms due to its simplicity and lower constant factors. That's why hybrid sorting algorithms (like merge-insert sort) may switch to insertion sort when the input size is small.

</details>

</details>

CLARIFYING EX02 : 
* take a positive integer sequence as argument
* must sort that sequence using merge-insert algorithm (also called Ford-Johnson algorithm)
* Expected output is : 

[BEFORE] : "unsorted sequence"   
[AFTER] : "sorted sequence"   
[CONTAINER 1] : "container used" "time used to sort sequence"   
[CONTAINER 2] : "container used" "time used to sort sequence"   

STEP BY STEP EX02 :  

1. Check if the array is valid, meaning 
* At least one command-line argument must be provided.
* All command-line arguments must consist solely of digits (0-9).

2. Create the container, print the list in its before state while storing each number (atoied) inside

3. Sort both arrays respectively 
(i) while the size of the vector is higher than 16, it's using merge algorithm, below and it will fall into the insertion one

(ii) if higher, it divides the vector into two halves (left and right), sorts each half recursively using sortVector, and then merges them back together using mergeVector.

(iii) This function is responsible for merging two sorted sub-vectors (left and right) into one sorted vector. It iterates over the elements of left and right, comparing them and placing them in the correct position in the merged vector vec. The while loop compares elements from both left and right and copies the smaller element into vec. It increments the counters accordingly.

(iv) Finally, Insertion sort works by iterating through the elements and "inserting" each element into its correct position within the already sorted portion of the vector.

4. Prints the resulted sorted arrays 

4. Prints the time taken for each container to sort the array


**Sorting Functions (sortDeque, mergeDeque, insertDeque, sortVector, mergeVector, insertVector):**

These functions implement sorting algorithms for `std::deque` and `std::vector` data structures. They use a combination of merge sort and insertion sort, with a threshold value (threshold) determining when to switch from merge sort to insertion sort.

The merge sort part is implemented in the `sortDeque` and `sortVector` functions, while the insertion sort part is implemented in the `insertDeque` and `insertVector` functions.

The `mergeDeque` and `mergeVector` functions are used to merge two sorted subarrays in the merge sort process.

<details> 
<summary> The choice of containers std::vector and std::deque</summary>

<h4>std::vector: </h4>

**Advantages:**

std::vector is a dynamic array that provides fast random access to elements. This means that accessing elements by index is efficient (O(1) complexity).

It provides efficient sequential access to elements.
It can dynamically resize itself to accommodate more elements.

**Usage:**

`std::vector` is used when the program wants to take advantage of fast random access to elements and does not require frequent insertions or deletions in the middle of the sequence.

**In the Code:**

`std::vector` is used to create the container vec to store the integers from the command-line arguments. It's used to demonstrate sorting with this container.


<h4>std::deque (Double-Ended Queue):</h4>

**Advantages:**    

`std::deque` is a dynamic data structure that allows fast insertion and deletion at both ends (front and back) of the sequence (O(1) complexity).

It's efficient for operations like push_front, pop_front, push_back, and pop_back.

**Usage:**

`std::deque` is used when the program needs to perform a variety of operations at both ends of the sequence, such as adding elements to the front or back, or removing elements from the front or back.

**In the Code:**

`std::deque` is used to create the container deq to store the integers from the command-line arguments. It's used to demonstrate sorting with this container.

**Why Both?:**

Using both std::vector and std::deque allows the program to showcase the flexibility and efficiency of different container types. It demonstrates that depending on the specific requirements of a task (e.g., the need for random access or efficient insertion/removal at both ends), different container types may be more suitable.    

By implementing sorting algorithms for both containers, the code provides a comparison of their performance in the context of the specific sorting operations being performed. This can be useful for understanding the strengths and weaknesses of different container types in different scenarios.    

</details>

<details> <summary>TIME DIFFERENCE IN SORTING</summary>

The variation in sorting times between `std::vector` and `std::deque` can be attributed to the underlying data structures and how they handle element storage and access. Here are some factors that could contribute to the differences in sorting times:

**Data Structure Differences:**

* `std::vector` is a dynamically resizing array. Elements are stored in contiguous memory locations. This allows for fast random access to elements, which is efficient for algorithms like quicksort.

* `std::deque` is a double-ended queue. It typically uses multiple blocks of memory, and elements are not guaranteed to be stored in contiguous memory. Inserting and removing elements from the beginning or end of a deque is generally faster compared to a vector, but random access to elements may be slower.


**Algorithmic Considerations:**

Depending on the size and structure of the data, different sorting algorithms may perform better. For example, quicksort tends to perform well on random data, while mergesort is more consistent and performs well on almost all types of data.

**Optimizations by the Standard Library Implementation:**

The standard library implementation you're using may have specific optimizations or tweaks for `std::vector` and `std::deque` operations. These can affect performance.

**Compiler Optimizations:**

Different compilers and compiler settings may generate different machine code, affecting the execution time of algorithms.

**Size of Data:**

The performance characteristics of different containers can vary based on the size of the data. For very small datasets, the overhead of managing blocks of memory in `std::deque` might make it slower. For very large datasets, cache locality and access patterns become more significant factors.

**Specifics of Your Data:**

The specific values and arrangement of elements in your dataset can influence the performance of the sorting algorithms. For example, some algorithms perform better or worse with certain types of data distributions.

Overall, the differences in sorting times between `std::vector` and `std::deque` are a result of a combination of these factors. It's not uncommon for different data structures to have varying performance characteristics for different types of operations.


Le code que vous avez partagé est une implémentation d'un algorithme de tri appelé "Tri Fusion" (Merge Sort) en C++. Voici une explication en termes généraux :

La fonction sortVector trie un vecteur d'entiers en utilisant l'algorithme de tri fusion.

Si la taille du vecteur est inférieure ou égale à 1, il est considéré déjà trié et la fonction se termine.
Sinon, si la taille du vecteur est inférieure ou égale à un seuil (dans ce cas 16), la fonction utilise un autre algorithme de tri appelé "Tri par Insertion" (insertVector).
Sinon, la fonction divise le vecteur en deux moitiés, trie chaque moitié récursivement en appelant sortVector, puis fusionne les deux moitiés triées en appelant mergeVector.
La fonction mergeVector fusionne deux vecteurs triés (gauche et droite) en un seul vecteur trié.

Elle initialise trois indices : i pour le vecteur final, j pour le vecteur de gauche, et k pour le vecteur de droite.
Tant que j et k sont inférieurs à leurs tailles respectives, elle compare les éléments de gauche et de droite et les ajoute au vecteur final en incrémentant les indices appropriés.
La fonction insertVector trie un vecteur en utilisant l'algorithme de tri par insertion.

Elle parcourt le vecteur à partir du deuxième élément.
Pour chaque élément, elle le compare avec les éléments précédents et le place à la bonne position dans la séquence triée.
En bref, le code met en œuvre l'algorithme de tri fusion, qui divise récursivement le vecteur en sous-vecteurs, les trie individuellement, puis les fusionne pour obtenir un vecteur trié. Si le vecteur est assez petit, il utilise l'algorithme de tri par insertion pour gagner en efficacité.

</details>
