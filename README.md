# CPP

<h3>BASICS</h3>

<details>
<summary><h4>Constructor</h4></summary>

* A constructor is a special member function of a class that gets called when an object of the class is created. Its primary purpose is to initialize the object's data members or perform any necessary setup.
* Constructors ensure that an object is in a valid state after it is created. They can set default values, allocate resources, and perform any other necessary initialization tasks.
* You can have multiple constructors in a class, each with different parameter lists (overloaded constructors). This allows you to create objects with various initial states.
</details>

<details>
<summary><h4>Destructor</h4></summary>

* A destructor is also a special member function of a class, but it gets called when an object is about to be destroyed or goes out of scope. Its purpose is to clean up resources or perform any necessary cleanup tasks.
* Destructors are crucial when a class manages resources like dynamic memory allocation (e.g., using new and delete in C++) or external resources (e.g., file handles, network connections). They ensure that resources are released properly to prevent memory leaks or resource leaks.
* Like constructors, you can define a destructor for your class. If you don't define one explicitly, the compiler will provide a default destructor for you.

Not every class needs a constructor or a destructor. If a class doesn't have any resource management requirements and doesn't need specific initialization or cleanup, you can omit these special functions, and the compiler will provide default ones.  

It's important to note that in some languages like Python or JavaScript, constructors (or equivalent functions) are typically present but may not be explicitly defined by the programmer. In these cases, the language runtime often provides a default constructor that initializes object properties, and there's no need for explicit destructor definitions since memory management is handled by garbage collection.  

In summary, constructors and destructors are essential tools for managing object initialization and cleanup in object-oriented programming, but whether you include them in your class depends on the specific needs of your program and the resources it manages.
</details>

<details>
<summary><h4>VISIBILITY OF CLASS MEMBERS</h4></summary>
In C++, the private and public access specifiers are used to control the visibility of class members (data members and member functions) from outside the class. Here's how they work:

<details>
<summary><h3>Private:</h3></summary>

Members declared as private are not accessible outside the class in which they are defined. They are only accessible within the class itself.
This is used to encapsulate the internal state and behavior of the class, hiding implementation details from users of the class.
Private members are typically accessed and modified through member functions (methods) which can enforce specific behavior and constraints.

```
class Example {
private:
    int privateData;
    
public:
    void setPrivateData(int value) {
        privateData = value;
    }
    
    int getPrivateData() {
        return privateData;
    }
};
```
</details>

<details>
<summary><h3>Public:</h3></summary>

Members declared as public are accessible from outside the class. They can be accessed and modified by objects of the class.
These are typically the interface of the class, providing a way for external code to interact with the object.
Public members should represent the behavior that the class is intended to exhibit.

```
class Example {
private:• Write class names in UpperCamelCase format. Files containing class code will
always be named according to the class name. For instance:
ClassName.hpp/ClassName.h, ClassName.cpp, or ClassName.tpp. Then, if you
have a header file containing the definition of a class "BrickWall" standing for a
brick wall, its name will be BrickWall.hpp.
• Unless specified otherwise, every output messages must be ended by a new-line
character and displayed to the standard output.
    int privateData;
    
public:
    void setPrivateData(int value) {
        privateData = value;
    }
    
    int getPrivateData() {
        return privateData;
    }
};
```
</details>

<details>
  <summary><h3>Protected</h3></summary>

protected members are similar to private members, but they are also accessible in derived classes (inheritance).
```
class Base {
protected:
    int protectedData;
};

class Derived : public Base {
public:
    void setProtectedData(int value) {
        protectedData = value; // Accessible because Derived inherits from Base
    }
};
```
</details>

The choice between private and public is a design decision based on encapsulation and information hiding principles. Generally, you want to keep as much information private as possible to prevent unintended interference and to maintain a clean interface for users of the class. The public interface should expose only what's necessary for external code to interact with the class in a meaningful way.

Remember, in C++, classes have a default access level of private if not specified otherwise. Therefore, if you don't explicitly specify public or private, members and inheritance are considered private by default.
</details>

<details>
  <summary><h4>INPUT OUTPUT OPERATIONS</h4></summary>

In C++, stdio stands for Standard Input/Output and it refers to a set of functions and streams used for handling input and output operations. These streams are provided by the C++ Standard Library and allow you to perform I/O operations on various devices, such as the console, files, and other input/output devices.

Here are the three main standard I/O streams in C++:

<details>
 <summary> <h3>STD::CIN</h3></summary>
This is the standard input stream. It is used to read data from the console or other input devices.

It is associated with the keyboard by default, but it can be redirected to read from files or other input sources.

```
int num;
std::cin >> num; // Reads a value from the standard input and stores it in 'num'
```
</details>

<details>
<summary><h3>STD::COUT</h3></summary>
This is the standard output stream. It is used to write data to the console or other output devices.
It is associated with the console by default, but it can be redirected to write to files or other output destinations.

```
int num = 42;
std::cout << "The value of num is: " << num << std::endl; // Prints a message to the standard output
```
</details>

<details>
<summary><h3>STD::CERR</h3></summary>
This is the standard error stream. It is used to output error messages and other critical information.
Like std::cout, it is associated with the console by default but can be redirected.
Unlike std::cout, std::cerr is unbuffered by default, meaning that it does not wait to accumulate a certain amount of data before sending it to the output device. This is important for error messages that need to be displayed immediately.

```
std::cerr << "An error occurred!" << std::endl;
```
</details>

These streams are part of the Standard Template Library (STL) in C++, and they are defined in the <iostream> header file.

Remember that std::cin and std::cout are instances of std::istream and std::ostream classes respectively, and they inherit the functions provided by those classes. This allows you to perform various operations on them, such as formatting, seeking, and more.

Additionally, the << operator is overloaded for output streams, allowing you to chain multiple output operations together, which is known as the "insertion operator". Similarly, the >> operator is overloaded for input streams, allowing you to chain multiple input operations, which is known as the "extraction operator".

Overall, these streams provide a convenient and flexible way to handle input and output operations in C++.
  
</details>


<h3>RULES</h3>

The rules to implement throughout the projects : 
* Write class names in UpperCamelCase format. Files containing class code will
always be named according to the class name.

* Unless specified otherwise, every output messages must be ended by a new-line
character and displayed to the standard output.

* However, you can’t use any other external library. It means C++11 (and derived
forms) and Boost libraries are forbidden. The following functions are forbidden
too: *printf(), *alloc() and free(). 

* Note that unless explicitly stated otherwise, the using namespace <ns_name> and
friend keywords are forbidden. Otherwise, your grade will be -42.

* From Module 02 to Module 09, your classes must be designed in the Orthodox
Canonical Form, except when explicitely stated otherwise.

* Private member objects start with an underscore 
