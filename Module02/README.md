The Scope of this Module was to get to know C++ further and come in contact with classes in orthodox canonical form:   

ex00: class that can store a fixed point variable    
ex01: add constructors and functions to that class from ex00 to make it usable   
ex02: add all kinds of operator overloads to expand the usability of ex01 even more    
ex03: a use case which uses most of the previously written code by creating a function that can determine weither a point is inside a triangle or not   



<details>
<summary>Orthodox Canonical Form</summary>

From Module 02 to Module 09, your classes must be designed in the Orthodox Canonical Form, except when explicitely stated otherwise.

Here are the principles of Orthodox Canonical Form in C++98 presented in bullet points:

**Public Interface:** Declare the public interface (member functions and data members accessible from outside the class) in the class header file.

**Private Implementation:** Hide implementation details (such as private data members and private member functions) within the class's implementation file.

**Initialization and Cleanup:** Provide appropriate constructors for initialization and a destructor for cleanup.

**Memory Management:** If the class uses dynamic memory allocation, provide proper resource management through constructors for allocation and a destructor for deallocation.

**Copy Constructor and Assignment Operator:** Implement a copy constructor and an assignment operator if the class manages resources (like dynamic memory). This adheres to the Rule of Three in C++98.

**Proper Handling of Self-Assignment (for the assignment operator):** Ensure that the assignment operator can handle cases where an object is assigned to itself.

**No Move Semantics (C++98):** In C++98, move semantics are not available, so you focus on copy semantics.

**Equality and Comparison Operators (if applicable):** Implement comparison operators (e.g., ==, !=, <, >) if it makes sense for your class.


```
// MyClass.h (Header File)

class MyClass {
public:
    MyClass(); // Constructor
    ~MyClass(); // Destructor
    MyClass(const MyClass& other); // Copy Constructor
    MyClass& operator=(const MyClass& other); // Copy Assignment Operator

    // Other public member functions

private:
    // Private data members

    // Private member functions
};
```


```
// MyClass.cpp (Implementation File)

#include "MyClass.h"

MyClass::MyClass() {
    // Initialization logic
}

MyClass::~MyClass() {
    // Cleanup logic
}

MyClass::MyClass(const MyClass& other) {
    // Copy constructor logic
    // Perform deep copy if necessary
}

MyClass& MyClass::operator=(const MyClass& other) {
    if (this == &other) // Check for self-assignment
        return *this;

    // Copy assignment operator logic
    // Perform deep copy if necessary

    return *this;
}

// Other private member function implementations
```

</details>



<details>
<summary>
Copy Constructor:
</summary>

The copy constructor is a special member function in a class that is used to create a new object as a copy of an existing object of the same class. It is invoked when:

A new object is created based on an existing object.
An object is passed by value as an argument to a function.
An object is returned by value from a function.

`ClassName(const ClassName& other);`

</details>

<details>

<summary> Copy Assignment Operator: </summary>

The copy assignment operator (operator=) is another special member function in a class. It is used to copy the state of one object to another object of the same class after both objects have already been initialized.

`ClassName& operator=(const ClassName& other);`

The copy assignment operator is responsible for assigning the state of one object to another. This often involves freeing any resources held by the destination object and then copying the state from the source object. It should handle cases where the object is assigned to itself (self-assignment).

</details>


References are used for passing objects to functions (both in the copy constructor and copy assignment operator) for efficiency and to avoid unnecessary object copying.

<details>
<summary>Copy Constructor:<summary>

```
Fixed::Fixed(const Fixed &src) {
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}
```

Here, src is passed by constant reference (const Fixed &src). This means that the function receives a reference to an existing Fixed object (src) without making a copy of it. This is efficient, especially if the object is large or costly to copy.

The purpose of the copy constructor is to create a new object that is a copy of an existing one. Since the goal is to make a copy, passing by reference is appropriate.

</details>

<details>
<summary>Copy Assignment Operator:</summary>

```
Fixed &Fixed::operator=(const Fixed &nbr) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &nbr){
        _fixedValue = nbr.getRawBits();
    } 
    return (*this);
}
```

Similarly, in the copy assignment operator, nbr is passed by constant reference (const Fixed &nbr). Like before, this means that the function receives a reference to an existing Fixed object without making a copy.

The copy assignment operator is responsible for assigning the state of one object to another. By using a reference, it operates directly on the object that is being assigned to (*this) and the object providing the new state (nbr). This is more efficient than making copies.

In both cases, using references allows us to work with existing objects directly, which is faster and more memory-efficient compared to creating copies. It's particularly important in situations where making a copy of an object might be costly, such as when dealing with large data structures or objects with complex internal states.
</details>


<details>

<summary> Converting to fixed point value from an INT</summary>

This constructor is for the Fixed class and it takes an integer nbr as an argument. Let's break down what it does:

```
Fixed::Fixed(const int nbr) : _fixedValue(nbr << _nBits) {
    std::cout << "Int constructor called" << std::endl;
}
```

**Input Argument:** The constructor takes an integer nbr as its argument.

**Initializer List:** The constructor uses an initializer list to initialize the member variable _fixedValue.  

**`: _fixedValue(nbr << _nBits)`** assigns the result of the expression `nbr << _nBits`` to the member `_fixedValue``.

**Bitwise Left Shift (<<):** The expression `nbr << _nBits` performs a bitwise left shift operation on nbr.

In this case, _nBits is a constant (assumed to be 8 in this context), which means nbr is shifted 8 bits to the left. This effectively multiplies nbr by 2^8, or 256. This is because a left shift by n bits is equivalent to multiplying by 2^n.

**Storing in _fixedValue:** The result of the bitwise left shift operation is then stored in the member variable `_fixedValue`.

**Output Message:** Finally, `std::cout << "Int constructor called" << std::endl;` prints a message indicating that the integer constructor has been called.

In summary, this constructor takes an integer value, left-shifts it by _nBits (which is assumed to be 8 in this context), effectively converting it to its fixed-point representation, and stores it in the member variable _fixedValue. This allows for the creation of a Fixed object from an integer value with appropriate conversion.

When we perform a bitwise left shift operation by n bits, it's equivalent to multiplying the number by 2^n. This is because in binary representation, shifting a number to the left is equivalent to multiplying it by powers of 2.

In the case of fixed-point representation, we want to represent fractional values using integers. By shifting the bits to the left, we effectively scale up the value, which is equivalent to multiplying by a power of 2.

Here's why this works for fixed-point:

**Fixed-Point Representation:** In fixed-point representation, a number is represented with a fixed number of bits reserved for the fractional part. For example, if we have 8 bits for the fractional part (which is common), then we have 24 bits left for the integer part in a 32-bit fixed-point number.

**Scaling Factor:** When you shift the bits left by n positions, you are effectively multiplying the number by 2^n. This is equivalent to scaling up the value by a factor of 2^n.

For example, shifting left by 8 bits (or multiplying by 256) is equivalent to scaling the value by a factor of 2^8, which is 256.

**Conversion to Fixed-Point:** When you apply this shift to an integer value, you're effectively converting it to a fixed-point representation.

For instance, if you have the integer 5, shifting it left by 8 bits would give 1280. In fixed-point terms (with 8 bits for the fractional part), this represents 5.0.

Similarly, if you had 2.5, it would be represented as 640 after the shift. This represents 2.5 in the fixed-point format.

So, the operation effectively converts integer values to their corresponding fixed-point representation.

Keep in mind that this assumes a specific number of bits are reserved for the fractional part, which determines the precision of the fixed-point representation. 
</details>



<details>

<summary> Converting to fixed point value from an INT</summary>

This constructor is for the Fixed class and it takes a float value nbr as an argument. Let's break down what it does:

```
Fixed::Fixed(const float nbr) : _fixedValue(std::roundf(nbr * (1 << _nBits))) {
    std::cout << "Float constructor called" << std::endl;
}
```

**Input Argument:** The constructor takes a float value nbr as its argument.

**Initializer List:** The constructor uses an initializer list to initialize the member variable _fixedValue.

**```: _fixedValue(std::roundf(nbr * (1 << _nBits)))``** computes the fixed-point representation of the floating-point value nbr and assigns it to _fixedValue.

**Scaling Factor:** `(1 << _nBits)` is a bitwise left shift operation. As explained before, this is equivalent to multiplying by 2^n, where _nBits is assumed to be 8 in this context.

This operation creates a scaling factor that depends on the value of _nBits. It's used to effectively convert the floating-point value to its corresponding fixed-point representation.

**Multiplication and Rounding:** nbr * (1 << _nBits) scales up the floating-point value by the scaling factor.

std::roundf(...) rounds the result to the nearest integer. This is important to ensure that the fixed-point representation is as accurate as possible.

**Storing in _fixedValue:** The result of the multiplication and rounding operation is then stored in the member variable _fixedValue.

**Output Message:** Finally, std::cout << "Float constructor called" << std::endl; prints a message indicating that the float constructor has been called.

In summary, this constructor takes a floating-point value, scales it up using the scaling factor (1 << _nBits), rounds it to the nearest integer, and stores it in the member variable _fixedValue. 

This effectively converts a floating-point value to its corresponding fixed-point representation.

</details>

The conversion from a float to a fixed-point value and from an int to a fixed-point value are different operations because they involve different types of input data and utilize distinct mathematical operations to perform the conversion.

**Conversion from int to Fixed-Point:**

In this case, we're converting a whole number (an integer) to a fixed-point value. The process involves a bitwise left shift operation `(nbr << _nBits)`, which effectively multiplies the integer value by a power of 2 (where _nBits is the number of fractional bits).

For example, if _nBits is 8, this operation is equivalent to multiplying the integer value by 256. This creates a scaling factor that effectively converts the integer value to its corresponding fixed-point representation.

The result is then stored in `_fixedValue.`

**Conversion from float to Fixed-Point:**

When converting a floating-point value to a fixed-point representation, it's a bit more involved.

First, the floating-point value is multiplied by a scaling factor `(nbr * (1 << _nBits))`. This effectively scales up the value to fit within the fixed-point format.

Then, the result is rounded to the nearest integer using `std::roundf(...)` to ensure that the fixed-point representation is as accurate as possible.

Finally, the rounded result is stored in `_fixedValue`.

This process accounts for the potentially fractional nature of floating-point values, making the conversion more complex compared to converting an integer.

In summary, while both operations involve converting a numerical value to a fixed-point format, they have different input types (integer vs. floating-point) and use distinct mathematical operations **(bitwise left shift vs. multiplication and rounding)** to achieve the conversion. These differences arise from the inherent characteristics of integer and floating-point data types.

<details>

<summary>CONVERTING THE OTHER WAY AROUND</summary>

**Conversion from Fixed-Point to FLOAT:**

```
float Fixed::toFloat() const {
    return ((static_cast<float>(this->getRawBits())) / (1 << _nBits));
}
```

**`getRawBits()`:** this->getRawBits() retrieves the raw fixed-point representation from the object. It returns an integer value.


**`static_cast<float>(...):`**This performs a type cast, converting the integer representation obtained from getRawBits() into a float.

**`/ (1 << _nBits):`** This scales down the fixed-point value to its original floating-point representation. `(1 << _nBits)` is equivalent to multiplying by `2^_nBits`, which reverses the scaling factor used during the conversion from float to fixed-point.

**Return:** The result is returned as a float.

In summary, toFloat() retrieves the fixed-point representation, converts it to a float, and then scales it down to the original value using the inverse of the scaling factor used during the conversion to fixed-point.

**Conversion from Fixed-Point to INT:**

```
int Fixed::toInt() const {
    return (_fixedValue >> _nBits);
}
```

**`_fixedValue:`** _fixedValue is the internal representation of the fixed-point number.

**`>> _nBits:`**This performs a bitwise right shift operation on `_fixedValue`. This effectively divides the value by `2^_nBits`, which is the reverse of the scaling factor used during the conversion from int to fixed-point.

**Return:** The result is returned as an int.

In summary, toInt() retrieves the fixed-point representation and then scales it down to the original integer value using the inverse of the scaling factor used during the conversion to fixed-point.

</details>

<details>
<summary> Overload of << </summary>

We are asked to create an overload of the insertion («) operator that inserts a floating-point representation of the fixed-point number into the output stream object passed as parameter.

```
std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
	os << fixed.toFloat();
	return (os);
}
```

This code provides a way to print the value of a Fixed object to an output stream (like the console) using the << operator.

`std::ostream& operator<<(std::ostream& os, const Fixed& fixed):` This line is declaring a function named `operator<<.` This function is designed to work with output streams (like the console).

It takes two arguments:
* `os` is the output stream (like std::cout for the console).
* `const Fixed& fixed` is a reference to a Fixed object, which is what we want to print.

`os << fixed.toFloat();:` This line means "send the result of converting fixed to a floating-point value (fixed.toFloat()) to the output stream os". It uses << to insert the value into the output stream.

`return (os);:` This line returns the output stream. This allows you to chain more operations after this one.

`fixed.toFloat():` This calls the toFloat() function on the fixed object. This function converts the Fixed object to a floating-point value.

So, in simple terms, this code lets you use << to print a Fixed object to the console. It does this by converting the Fixed object to a floating-point value and sending it to the output stream.

</details>

THING TO NOTE 

**Prefix Increment (++a):**
	* The prefix increment operator ++ is defined in your Fixed class as Fixed& operator++(void).
	* This allows you to use it in the form ++a, where a is a Fixed object.

**Postfix Increment (a++):**
	* The postfix increment operator ++ is defined in your Fixed class as Fixed operator++(int).
	* This allows you to use it in the form a++, where a is a Fixed object.

The presence of the int parameter in the postfix increment operator's definition is what distinguishes it from the prefix increment operator. This is a standard convention in C++. The int parameter is not used in the function; it's simply there to indicate that this is the postfix version.  

So, in your main function, you're able to use both prefix and postfix increment and decrement operators without any explicit parameter because these operators are correctly defined in your Fixed class.  





