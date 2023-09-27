Polymorphism is a fundamental concept in object-oriented programming (OOP) that allows objects to be treated as instances of their base class, even if they are actually instances of a derived class. This means that a function can behave differently based on the actual type of the object it's operating on.  

<details>
<summary>Subtype Polymorphism:</summary> 
Subtype polymorphism is a form of polymorphism where a subclass can be used wherever a superclass is expected. This allows for more flexible and dynamic behavior at runtime. It is achieved through the use of virtual functions.

```
class Animal {
public:
    virtual void makeSound() const {
        std::cout << "Generic animal sound" << std::endl;
    }
};
class Dog : public Animal {
public:
    void makeSound() const override {
        std::cout << "Bark" << std::endl;
    }
};

class Cat : public Animal {
public:
    void makeSound() const override {
        std::cout << "Meow" << std::endl;
    }
};

void playWithAnimal(const Animal& animal) {
    animal.makeSound(); // Calls the appropriate makeSound based on the actual type of the object
}

int main() {
    Animal genericAnimal;
    Dog fido;
    Cat whiskers;

    playWithAnimal(genericAnimal); // Outputs: "Generic animal sound"
    playWithAnimal(fido);          // Outputs: "Bark"
    playWithAnimal(whiskers);      // Outputs: "Meow"

    return 0;
}
```

In this example, Dog and Cat are subclasses of Animal. They override the makeSound function. The playWithAnimal function takes an Animal object, demonstrating subtype polymorphism.
</details>


<details>
<summary>Abstract Classes</summary>

An abstract class is a class that cannot be instantiated directly. It is used as a base class to define an interface for derived classes. Abstract classes may have pure virtual functions, which are functions without a body, effectively requiring subclasses to implement them.

```
class Shape {
public:
    virtual double area() const = 0; // Pure virtual function
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    double area() const override {
        return 3.14 * radius * radius;
    }
};
```

In this example, Shape is an abstract class with a pure virtual function area(). The Circle class is derived from Shape and must implement the area() function.

</details>

<details>
<summary>Interfaces</summary>

In C++, interfaces are typically implemented using abstract classes with pure virtual functions. An interface defines a contract of behavior that a class must adhere to, without providing any implementation details. Classes implementing an interface must provide implementations for all the functions defined in the interface.

```
class Printable {
public:
    virtual void print() const = 0;
};

class Book : public Printable {
private:
    std::string title;

public:
    Book(const std::string& t) : title(t) {}

    void print() const override {
        std::cout << "Title: " << title << std::endl;
    }
};
```

Here, Printable is an interface with a pure virtual function print(). The Book class implements the Printable interface by providing an implementation for print().

</details>

In summary, subtype polymorphism allows objects to be treated as instances of their base class, abstract classes provide a blueprint for derived classes to implement, and interfaces define contracts of behavior that classes must adhere to. These concepts are fundamental to achieving flexibility and polymorphic behavior in C++.

<details>
<summary>WHY HAVE A VIRTUAL DESTRUCTOR ?</summary>

**1.Polymorphic Hierarchies:**

* In object-oriented programming, you might have a hierarchy of classes where a base class is inherited by one or more derived classes. These derived classes may add new members or behaviors.

* When you use dynamic memory allocation (e.g., new in C++) to create an object of a derived class, and you store the address of that object in a pointer to the base class, you create a situation where you may need a virtual destructor.

**2.Proper Cleanup in Derived Classes:**
* If the base class destructor is not virtual, and you delete an object of a derived class through a pointer to the base class, only the base class destructor will be called.

This can be problematic if the derived class has allocated resources (e.g., memory, file handles, etc.) that need to be cleaned up when the object is deleted.

**3.Memory Leaks and Undefined Behavior:**

* Without a virtual destructor, the derived class's destructor will not be called, leading to memory leaks and potentially other forms of undefined behavior.
* By making the destructor virtual in the base class, you ensure that the correct destructor (of the derived class) is called when deleting an object through a pointer to the base class. This allows for proper cleanup of resources.

<details>
    <summary>Why is the destructor of Animal virtual while the destructors of Cat, Dog and Animal are not ?</summary>

**Animal Class:**
* Virtual Destructor: The virtual destructor in the Animal class indicates that it is intended to be a base class in a polymorphic hierarchy. This means that it's designed to be inherited by other classes, and objects of those derived classes might be deleted through pointers of the base class type.
* By having a virtual destructor, it ensures that the correct destructor (either from the base class or the derived class) is called when deleting an object through a pointer to the base class. This is crucial for proper cleanup and avoiding memory leaks.


**Brain Class, Cat Class, and Dog Class:**
* Non-virtual Destructors: In these classes, they do not serve as base classes for any other classes. They are designed to be standalone classes with their own specific functionality.
* Since these classes are not intended to be inherited from, there is no need for their destructors to be virtual. They do not participate in polymorphic hierarchies, so the need for dynamic dispatch is not present.

</details>

</details>

<details>
<summary>WHY HAVE VIRTUAL FUNCTIONS ?</summary>

Virtual functions are a powerful mechanism that enables polymorphism, allowing different classes to provide their own implementations for a common interface defined by a base class. This leads to more flexible, reusable, and maintainable code. Although it's not NECESSARY to use the `override` key word its highly recommended. 


```
class Base {
public:
    virtual void print() {
        std::cout << "Base class\n";
    }
};

class Derived : public Base {
public:
    void print() override {
        std::cout << "Derived class\n";
    }
};

Base* ptr = new Derived();
ptr->print(); // Output will be "Derived class"
```
</details>

<details>
    <summary>POLYMORPHISM GO FURTHER</summary>

Polymorphism is a fundamental concept in object-oriented programming (OOP) that allows objects to be treated as instances of their base type, even when they are actually instances of derived types. This enables code to work with different types of objects in a uniform way.

There are two main types of polymorphism in C++: compile-time (static) polymorphism and run-time (dynamic) polymorphism. Let's dive into both:

<details>
    <summary>1. Compile-Time Polymorphism (Static Binding):</summary>

Compile-time polymorphism is resolved during the compile time. It is achieved through function overloading and operator overloading.

**a. Function Overloading:**
Function overloading allows you to define multiple functions with the same name but with different parameter lists. The appropriate function to be called is determined based on the arguments provided at compile time.

```
class MathOperations {
public:
    int add(int a, int b) {
        return a + b;
    }

    double add(double a, double b) {
        return a + b;
    }
};
```

**b. Operator Overloading:**
Operator overloading allows you to define how operators like +, -, *, etc., behave for objects of a class.

```
class ComplexNumber {
private:
    int real;
    int imaginary;

public:
    ComplexNumber operator+(const ComplexNumber& other) {
        ComplexNumber result;
        result.real = this->real + other.real;
        result.imaginary = this->imaginary + other.imaginary;
        return result;
    }
};
``` 
</details>

<details>
    <summary>2. Run-Time Polymorphism (Dynamic Binding):</summary>

Run-time polymorphism allows you to achieve different behavior for objects of different derived types, even when accessed through pointers or references of a common base type.

**a. Virtual Functions:**
Virtual functions are functions in a base class that are declared with the virtual keyword. They can be overridden in derived classes, and the correct function is called at runtime based on the actual type of the object.

```
class Animal {
public:
    virtual void makeSound() {
        std::cout << "Generic Animal Sound\n";
    }
};

class Dog : public Animal {
public:
    void makeSound() override {
        std::cout << "Bark!\n";
    }
};
```

**b. Pure Virtual Functions and Abstract Classes:**
A pure virtual function is a virtual function that is set to 0 in the base class. It means that the base class is now an abstract class, and any derived class must implement this function.

```
class Shape {
public:
    virtual void draw() = 0;
};

class Circle : public Shape {
public:
    void draw() override {
        std::cout << "Drawing a circle\n";
    }
};
```
</details>
<details>
    <summary>Benefits of Polymorphism</summary>
    
**Code Reusability:** You can write code that operates on a base class, and it can be used with any derived classes.

**Flexibility and Extensibility:** New derived classes can be added without modifying existing code that uses the base class.

**Reduced Coupling:** Code that interacts with objects only needs to know about the base class interface, not the specific derived classes.

**Dynamic Behavior:** Run-time polymorphism allows for behavior to be determined at runtime, providing flexibility in handling different types of objects.

**Encapsulation:** Polymorphism allows you to encapsulate behavior in objects, making the code more modular and easier to maintain.
</details>

</details>


In this module...

<details>
    <summary>SUMMARY</summary>

In the provided code, you have defined a hierarchy of classes that demonstrate polymorphism. Let's break it down step by step:

**Base Class Animal:**
Animal is an abstract base class that provides a common interface for different types of animals. It has a virtual function makeSound which will be overridden in the derived classes to provide specific sound behavior for each animal type.
It also has a data member _type to store the type of the animal.

**Derived Classes Cat and Dog:**
Both Cat and Dog inherit from the Animal class. They are specific types of animals, each with their own characteristics and behavior.
They override the makeSound function to provide their unique sound behavior.

**Virtual Inheritance:**    
Cat inherits virtually from Animal. This is done to avoid having multiple copies of the base class (Animal) in the inheritance hierarchy in case Cat is inherited by another class.

**Composition with Brain:**   
Both Cat and Dog classes have a Brain object as a data member. This demonstrates composition, where a class contains an object of another class. Each animal can have its own brain with a set of ideas.

**Polymorphism:**     
Polymorphism is exemplified through the use of virtual functions. Specifically, the makeSound function is virtual in the Animal class and is overridden in both Cat and Dog classes. This allows you to call makeSound on an object of type Animal*, and the correct sound for the specific animal type will be executed based on the actual type of the object.

**Dynamic Binding:**  
When you have a pointer or reference of type Animal*, you can assign it to an object of type Cat* or Dog*. At runtime, the appropriate makeSound function will be called based on the actual type of the object.

</details>



