// Eileen Huang

#include "my_memory.h"

// my_unique_ptr implementations

//default constructor - object points to nulltr
template<typename T>
my_unique_ptr<T>::my_unique_ptr() : ptr(nullptr){};

// constructor - new object takes ownership of pointed memory
// set orignial ptr to nullptr
template<typename T>
my_unique_ptr<T>::my_unique_ptr(T* obj_ptr) : ptr(obj_ptr){
    obj_ptr = nullptr;  
};

// move constructor
// ptr points to memory
// set orignial ptr to nullptr
template<typename T>
my_unique_ptr<T>::my_unique_ptr(my_unique_ptr<T> && obj_ptr) : ptr(obj_ptr.ptr) {
    obj_ptr.ptr = nullptr;
}

// destructor
template<typename T>
my_unique_ptr<T>::~my_unique_ptr() {
    if (ptr != nullptr)
        delete ptr;
}

// dereference operator
template<typename T>
T & my_unique_ptr<T>::operator* () {
    return *ptr;
}

// returns pointer to object and allows for class member access
template<typename T>
T* my_unique_ptr<T>::operator->() {
    return ptr;
}

// move assignment
template<typename T>
my_unique_ptr<T> & my_unique_ptr<T>::operator= (my_unique_ptr<T> && obj_ptr){
    T* tmp = ptr;       // tmp ptr points to old memory
    ptr = obj_ptr.ptr;  // point to new memory
    obj_ptr.ptr = nullptr;  // change original ptr to nullptr
    delete tmp;             // delete old memory
    return *this;
}

// returns true if ptr points to nullptr and false otherwise
template<typename T>
bool my_unique_ptr<T>::isNullptr() {
    return ptr == nullptr;
} 

// ----------------- my_shared_ptr implementaions ----------------------

// default constructor
// set ptr and counter to nullptr
template<typename T>
my_shared_ptr<T>::my_shared_ptr() : ptr(nullptr), counter(nullptr){}

// constructor 
// ptr points to object and set counter to 1
template<typename T>
my_shared_ptr<T>::my_shared_ptr(T* obj_ptr) : ptr(obj_ptr), counter(new int (1)){
    obj_ptr = nullptr;
}

// copy constructor 
// ptr points to object and increments counter
template<typename T>
my_shared_ptr<T>::my_shared_ptr(const my_shared_ptr<T> & shared_ptr) : ptr(shared_ptr.ptr),counter(shared_ptr.counter) {
    if (ptr != nullptr)
        *counter = *counter + 1; 
}

// move constructor 
// new object points to memory, old pointers set to nullptr
template<typename T> 
my_shared_ptr<T>::my_shared_ptr(my_shared_ptr<T> && shared_ptr) : ptr(shared_ptr.ptr), counter(shared_ptr.counter){
    shared_ptr.ptr = nullptr;
    shared_ptr.counter = nullptr;
}

//destructor
template<typename T>
my_shared_ptr<T>::~my_shared_ptr(){
    // delete pointers if this is the only pointer
    // otherwise decrement counter
    if (ptr != nullptr) {
        if (*counter == 1) {
            delete ptr;
            delete counter;
        }
        else {
            *counter = *counter - 1;
        }
    }
}

//dereferencing operator - returns object that ptr points to
template<typename T> 
T & my_shared_ptr<T>::operator*(){
    return *ptr;
}

// retruns pointer to object and allows for class member access
template<typename T>
T* my_shared_ptr<T>::operator->() {
    return ptr;
}

//copy assignment
template<typename T>
my_shared_ptr<T> & my_shared_ptr<T>::operator=(const my_shared_ptr<T> & shared_ptr) {
    // tmp pointers for memory to delete
    T* tmp = ptr;
    int* tmp_counter = counter;
    
    // point to new memory
    ptr = shared_ptr.ptr;
    counter = shared_ptr.counter;

    // increment counter if neecessary
    if (ptr != nullptr) {
        *counter = *counter + 1;
    }
    
    // release old memory if counter = 1
    // else decrement counter
    if (tmp != nullptr) {
        if (*tmp_counter == 1) {
            delete tmp;
            delete tmp_counter;
        }
        else {
            *tmp_counter = *tmp_counter - 1;
        }
    }
    return *this;
}

// move assignment
template<typename T>
my_shared_ptr<T> & my_shared_ptr<T>::operator=(my_shared_ptr<T> && shared_ptr) {
    
    // tmp pointers for memory to delete
    T* tmp = ptr;
    int* tmp_counter = counter;

    // point to new memory and set old pointers to nullptr
    ptr = shared_ptr.ptr;
    counter = shared_ptr.counter;
    shared_ptr.ptr = nullptr;
    shared_ptr.counter = nullptr;

    // release old memory if counter = 1
    // else decrement counter
    if (tmp != nullptr) {
        if (*tmp_counter == 1) {
            delete tmp;
            delete tmp_counter;
        }
        else {
            *tmp_counter = *tmp_counter - 1;
        }
    }
    return *this;
} 

// returns true if ptr points to nullptr and false otherwise
template<typename T>
bool my_shared_ptr<T>::isNullptr() {
    return ptr == nullptr;
} 
