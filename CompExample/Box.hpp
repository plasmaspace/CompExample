//
//  Box.hpp
//  CompExample
//
//  Created by panqj on 4/13/24.
//

#ifndef Box_hpp
#define Box_hpp

#include <stdio.h>
#include <stdexcept>

// Template class
template<typename T>
class Box{
private:
    T* data;
public:
    Box(): data(nullptr) {}
    // Constructor
    Box(const T& value): data(new T(value)) {}
    
    // Move constructor
    Box(Box&& other) noexcept : data(other.data) {
        other.data = nullptr;
    }
    
    // Move assignement
    Box& operator=(Box&& other) noexcept {
        if (this != &other) { // "this" is a pointer, needing address operator &
            delete data;
            data = other.data;
            other.data = nullptr;
        }
        return *this; // Dereference "this" pointer and return the object "this" points to.
    }
    
    // Deep copy constructor
    Box(const Box& other) : data(other.data ? new T(*other.data) : nullptr){}
    
    //Deep copy assignment
    Box& operator=(const Box& other) {
        if (this != &other) {
            delete data;
            data = other.data ? new T(*other.data) : nullptr;
        }
        return *this;
    }
    
    ~Box(){
        delete data;
    }
    
    const T& get() const {
        if (!data) {
            throw std::runtime_error("No data");
        } else
        return *data;
    }
};

#endif /* Box_hpp */
