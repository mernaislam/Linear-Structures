//
// Created by Nour Muhammad on 4/26/2023.
//

#ifndef LINKEDLISTS_STACK_H
#define LINKEDLISTS_STACK_H

template <class T>
struct Node_s{
public:
    T data;
    Node_s<T>* next;
    Node_s<T>(T value){
        data = value;
        next = nullptr;
    }
};

template<class T>
class Stack {
    Node_s<T>* head;
    int size;
public:
    Stack(){
        head = nullptr;
        size = 0;
    }
    void push(T element);
    T pop();
    T top();
    bool isEmpty();
    int stackSize();
    void clear();
    void print();
};


#endif //LINKEDLISTS_STACK_H
