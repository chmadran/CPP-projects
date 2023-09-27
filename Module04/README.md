Polymorphism is a fundamental concept in object-oriented programming (OOP) that allows objects to be treated as instances of their base class, even if they are actually instances of a derived class. This means that a function can behave differently based on the actual type of the object it's operating on.  

<details>
<summary>ABSTRACT CLASSES</summary>

An abstract class is a class that cannot be instantiated directly. It is used as a base class to define an interface for derived classes. Abstract classes may have pure virtual functions, which are functions without a body, effectively requiring subclasses to implement them.

</details>


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
<summary>ABSTRACT CLASSES</summary>

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
<summary>INTERFACES</summary>

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

