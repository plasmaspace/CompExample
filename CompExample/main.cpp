//
//  main.cpp
//  CompExample
//
//  Created by panqj on 4/13/24.
//

// C++ code showing class inheritance, polymorphism, template, operator overload, move constructor and assignment, deep copy constructor and assignment, dyanmic memory, management, exception handling.

#include "Shape.hpp"
#include "Box.hpp"
#include <iostream>
#include <vector>
#include <memory>

using namespace std;

int main() {
    // Polymorphism and dynamic memory
    vector<shared_ptr<Shape>> shape;
    shape.push_back(make_shared<Circle>(2.0));
    shape.push_back(make_shared<Rectangle>(3.0,4.0));
    //shape.push_back(new Circle(2.0));  // This initilization of smart pointer doesn't work for some reason
    //shape.push_back(new Rectangle(3.0,4.0));
    for (auto sp : shape){
        sp->display();
        cout << "Area: " << sp->area() << endl;
        //delete sp;
    }
    
    // Template instantiation
    Box<int> intBox(42);
    cout << "Value in intBox: " << intBox.get() << endl;
    
    // Move constructor & exception handling
    Box<int> intBox2(std::move(intBox));
    try {
        cout << "Value in intBox: " << intBox.get() << endl;
    } catch (std::runtime_error& e) {
        cerr << e.what() << endl;
    }
    try {
        cout << "Value in intBox2: " << intBox2.get() << endl;
    } catch (std::runtime_error& e) {
        cerr << e.what() << endl;
    }
    
    // Move assignment
    Box<int> intBox3;
    intBox3 = std::move(intBox2);
    try {
        cout << "Value in intBox2: " << intBox2.get() << endl;
    } catch (const std::exception& e) {
        cerr << e.what() << endl;
    }
    try {
        cout << "Value in intBox3: " << intBox3.get() << endl;
    } catch (const std::exception& e) {
        cerr << e.what() << endl;
    }
    
    // Copy constructor
    Box<int> intBox4(intBox3);
    try {
        cout << "Value in intBox3: " << intBox3.get() << endl;
    } catch (const std::exception& e) {
        cerr << e.what() << endl;
    }
    try {
        cout << "Value in intBox4: " << intBox4.get() << endl;
    } catch (const std::exception& e) {
        cerr << e.what() << endl;
    }
    
    // Copy assignment
    Box<int> intBox5;
    intBox5 = intBox4;
    try {
        cout << "Value in intBox4: " << intBox4.get() << endl;
    } catch (const std::exception& e) {
        cerr << e.what() << endl;
    }
    try {
        cout << "Value in intBox5: " << intBox5.get() << endl;
    } catch (const std::exception& e) {
        cerr << e.what() << endl;
    }
    
    // Copy assignment
    intBox = intBox5;
    try {
        cout << "Value in intBox5: " << intBox5.get() << endl;
    } catch (const std::exception& e) {
        cerr << e.what() << endl;
    }
    try {
        cout << "Value in intBox: " << intBox.get() << endl;
    } catch (const std::exception& e) {
        cerr << e.what() << endl;
    }
    
    return 0;
}
