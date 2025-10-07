template <typename T>
ArrayStack<T>::ArrayStack(int i) {
    // TODO
    if (i <= 0) {
        throw string("Invalid stack size");
    }
    this->length = 0;
    this->maxSize = i;
    buffer = new T[this->maxSize];
}

template <typename T>
ArrayStack<T>::ArrayStack(const ArrayStack<T>& copyObj) {
    copy(copyObj);
}

template <typename T>
ArrayStack<T>& ArrayStack<T>::operator=(const ArrayStack<T>& rightObj) {
    if (this != &rightObj) {
        clear();
        copy(rightObj);
    }
    return *this;
}

template <typename T>
ArrayStack<T>::~ArrayStack() {
    delete[] buffer;
}

template <typename T>
void ArrayStack<T>::clear() {
    // TODO
    this->length = 0;
}

template <typename T>
void ArrayStack<T>::copy(const ArrayStack<T>& copyObj) {
    // TODO
    this->maxSize = copyObj.maxSize;
    this->length = copyObj.length;

    buffer = new T[this->maxSize];
    
    for(int i = 0; i < copyObj.length; i++) {
        buffer[i] = copyObj.buffer[i];
    }
}

template <typename T>
int ArrayStack<T>::getLength() const {
    return this->length;
}

template <typename T>
int ArrayStack<T>::getMaxSize() const {
    return maxSize;
}

template <typename T>
bool ArrayStack<T>::isEmpty() const {
    return this->length == 0;
}

template <typename T>
bool ArrayStack<T>::isFull() const {
    return this->length == maxSize;
}

template <typename T>
T ArrayStack<T>::peek() const {
    // TODO
    if(this->isEmpty()) {
        throw string("peek: error, stack is empty");
    }
    
    return buffer[this->length-1];
}

template <typename T>
void ArrayStack<T>::pop() {
    // TODO
    if(this->isEmpty()) {
        throw string("pop: error, stack is empty");
    }

    this->length--;
}

template <typename T>
void ArrayStack<T>::push(const T& elem) {
    // TODO
    if (this->length == maxSize) {
        throw string("push: error, stack is full");
    }
    
    buffer[this->length] = elem;
    this->length++;
}

template <typename T>
void ArrayStack<T>::rotate(typename Stack<T>::Direction dir) {
    // TODO
    if (this->isEmpty()) {
        throw string("rotate: error, stack is empty");
    } else if (dir == Stack<T>::RIGHT) {
        T topElem = buffer[this->length-1];
        for (int i = this->length-1; i > 0; i--) {
            buffer[i] = buffer[i-1];
        }
        buffer[0] = topElem;
    } else {
        T bottomElem = buffer[0];
        for (int i = 0; i < this->length-1; i++) {
            buffer[i] = buffer[i + 1];
        }
        buffer[this->length-1] = bottomElem;
    }
}

template <typename T>
ostream& operator<<(ostream& outStream, const ArrayStack<T>& myObj) {
    if (myObj.isEmpty()) {
        outStream << "Stack is empty, no elements to display.\n";
    }
    else {
        for (int i = myObj.length - 1; i >= 0; i--) {
            outStream << (i == myObj.length - 1 ? "top\t" : "\t")
                      << myObj.buffer[i] << endl;
        }
    }

    return outStream;
}

