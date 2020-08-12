// Eileen Huang

#ifndef MY_MEMORY_
#define MY_MEMORY_


template<typename T>
class my_unique_ptr {
private:
    T *ptr;
public:
    my_unique_ptr(); // default constructor
    my_unique_ptr(T* obj); // constructor - new object takes ownership of pointed memory
    my_unique_ptr(my_unique_ptr<T> && obj_ptr); // move constructor
    my_unique_ptr(const my_unique_ptr<T> & obj_ptr) = delete; // delete copy constructor
    ~my_unique_ptr(); // destructor
    T & operator*(); // dereference operator - returns a reference to the item pointed by object
    T* operator->(); //returns pointer to object and allows for class member access
    my_unique_ptr<T> & operator= (my_unique_ptr<T> && obj_ptr); // move assignment
    my_unique_ptr<T> & operator= (const my_unique_ptr<T> & obj_ptr) = delete; // delete copy assignment 
    bool isNullptr(); // returns true if ptr points to nullptr and false otherwise
};

template<typename T>
class my_shared_ptr{
private:
    T *ptr;
    int *counter;
public:
    my_shared_ptr(); // default constructor
    my_shared_ptr(T* obj_ptr); // constructor
    my_shared_ptr(const my_shared_ptr<T> & shared_ptr); // copy constructor
    my_shared_ptr(my_shared_ptr<T> && shared_ptr); // move constructor
    ~my_shared_ptr<T>(); // destructor
    T & operator*(); // dereference operator
    T* operator->(); // retruns pointer to object and allows for class member access
    my_shared_ptr<T> & operator=(const my_shared_ptr<T> & shared_ptr); //copy assignment
    my_shared_ptr<T> & operator=(my_shared_ptr<T> && shared_ptr); // move assignment
    bool isNullptr(); // returns true if ptr points to nullptr and false otherwise
};

#include "my_memory.cpp"
#endif