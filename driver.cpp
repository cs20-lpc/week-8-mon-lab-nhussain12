#include "ArrayStack.hpp"
#include <string>

template <typename T>
void testRotate(ArrayStack<T>&);

template <typename T>
void testRotate(ArrayStack<T>& stack) {
    cout << "Original stack:\n" << stack << endl;

    // RIGHT rotation
    stack.rotate(Stack<T>::RIGHT);
    cout << "After RIGHT rotation:\n" << stack << endl;

    // LEFT rotation
    stack.rotate(Stack<T>::LEFT);
    cout << "After LEFT rotation:\n" << stack << endl;
}

int main() {

    // Create a stack of integers and a stack of string values
    ArrayStack<int> intStack(10);
    ArrayStack<string> stringStack(15);

    // Fill integer stack with values
    for (int i = 0; i < intStack.getMaxSize(); i++) {
        intStack.push(i); 
    }
    cout << intStack;

    // Check if int stack is full
    if (intStack.isFull()) {
        cout << "Integer Stack is Full!" << endl;
    } else {
        cout << "Integer Stack is NOT Full!" << endl;
    }

    // Try to push to full stack
    try {
        intStack.push(10);
    }
    catch (string& e) {
        cout << e;
    }

    // Delete a value from int stack
    intStack.pop();

    // Check again if integer stack is full
    if (intStack.isFull()) {
        cout << "Integer Stack is Full!" << endl;
    } else {
        cout << "Integer Stack is NOT Full!" << endl;
    }

    // Check if string stack is empty
    if(stringStack.isEmpty()) {
        cout << "String Stack is Empty!" << endl;
    } else {
        cout << "String Stack is NOT Empty!" << endl;
    }

    // Add values to string stack
    stringStack.push("Vanilla");
    stringStack.push("Chocolate");
    stringStack.push("Strawberry");
    stringStack.push("Pineapple");
    cout << stringStack << endl;

    // Check again if string stack is empty
    if(stringStack.isEmpty()) {
        cout << "String Stack is Empty!" << endl;
    } else {
        cout << "String Stack is NOT Empty!" << endl;
    }

    // Get string stack's length and top value
    cout << stringStack.getLength() << endl;
    cout << stringStack.peek() << endl;
    
    // Rotate both stacks
    testRotate(stringStack);
    testRotate(intStack);

    // Create a second int stack to copy to
    ArrayStack<int> intStack2(20);
    cout << intStack2;
    intStack2 = intStack;
    cout << intStack2;

    // Clear both stacks
    stringStack.clear();
    intStack.clear();

    // Perform test cases with empty stacks
    try {
        intStack.pop();
    }
    catch (string& e) {
        cout << e;
    }

    try {
        stringStack.peek();
    }
    catch (string& e) {
        cout << e;
    }


    
    








    



























    return 0;
}