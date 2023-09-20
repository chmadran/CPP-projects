<h3>CLASSES</h3>

<details>
<summary>IMPLEMENTING A CLASS</summary>

<details>
<summary><h5>Define the Class:</h5></summary>
Start by declaring the class with the class keyword, followed by the class name. Optionally, you can specify a base class if inheritance is involved. This needs to be done in a .hpp file named after the class.  

```
class MyClass {
    // Class members go here
};
```
</details>

<details>
<summary><h5>Define Data Members:</h5></summary>
Inside the class, declare the data members (variables) that represent the properties of objects of this class. These are usually declared as private to encapsulate the internal state of the class.

```
class MyClass {
private:
    int myNumber;
    std::string myString;
};
```
</details>

<details>
<summary><h5>Define Member Functions:</h5></summary>
Member functions (methods) are the operations that can be performed on objects of the class. These can include constructors, destructors, and any other custom functions.

```
class MyClass {
private:
    int myNumber;
    std::string myString;

public:
    // Constructor
    MyClass(int num, std::string str) {
        myNumber = num;
        myString = str;
    }

    // Other member functions
    void printInfo() {
        std::cout << "Number: " << myNumber << ", String: " << myString << std::endl;
    }
};
```
</details>

<details>
<summary><h5>Implement Constructor(s) and Destructor :</h5></summary>
Constructors initialize the object's data members when an object is created. Destructors clean up resources when an object is destroyed.
</details>

<details>
<summary><h5>Define Member Functions Outside the Class:</h5></summary>
For more complex functions, you may choose to define them outside the class definition. This can make the class interface (defined in the header file) cleaner.

```
class MyClass {
private:
    int myNumber;
    std::string myString;

public:
    MyClass(int num, std::string str);

    void printInfo();
};

MyClass::MyClass(int num, std::string str) {
    myNumber = num;
    myString = str;
}

void MyClass::printInfo() {
    std::cout << "Number: " << myNumber << ", String: " << myString << std::endl;
}
```
</details>

</details>

USED : 

* `.compare` instead of strcmp
  
* `std::flush` ensures that the output is immediately displayed on the console, without waiting for a newline character (normally, output is buffered and displayed only when a newline character is encountered or when the buffer is full).
  
* `std::cin.fail()` is an expression that checks if the most recent input operation on std::cin has failed. It returns a boolean value (true if an error occurred, false otherwise). In this context, if the user enters something that is not a valid integer (e.g., a letter or a symbol), std::cin.fail() will return true.

* `std::cin.clear():` If an input operation fails (e.g., the user enters a letter instead of a number), std::cin enters a fail state. std::cin.clear() is used to clear this fail state. It resets the stream state flags so that further operations can be attempted.

* `std::cin.ignore():` After clearing the fail state, std::cin.ignore() is used to ignore any remaining characters in the input buffer. This is important because if the user entered a non-integer value, it may still be in the input buffer. ignore() discards it.
