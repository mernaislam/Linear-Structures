//
// Created by Nour Muhammad on 4/26/2023.
//
/// \author Nour Muhammad - 20210428

#include "Stack.h"
#include <bits/stdc++.h>
using namespace std;

template<class T>
Stack<T>::~Stack() {
    ///Time Complexity O(N)
    Node_s<T>* current = head;
    while(current!= nullptr){
        Node_s<T>* temp = current;
        current = current->next;
        delete temp;
    }
}


template<class T>
void Stack<T>::push(T element) {
    ///Time Complexity O(1)
    Node_s<T> * newNode_s = new Node_s<T>(element);
    if(head == nullptr){
        head = newNode_s;
    }
    else{
        newNode_s->next = head;
        head = newNode_s;
    }
    size++;
}

template<class T>
T Stack<T>::pop() {
    ///Time Complexity O(1)
    Node_s<T> * temp = head;
    T element = head->data;
    head = head->next;
    free(temp);
    size--;
    return element;

}

template<class T>
T Stack<T>::top() {
    ///Time Complexity O(1)
    return head->data;
}

template<class T>
bool Stack<T>::isEmpty() {
    ///Time Complexity O(1)
    return (size == 0);
}

template<class T>
int Stack<T>::stackSize() {
    ///Time Complexity O(1)
    return size;
}

template<class T>
void Stack<T>::clear() {
    ///Time Complexity O(N)
    int cnt = size;
    while(cnt--){
        this->pop();
    }
}

template<class T>
void Stack<T>::print() {
    ///Time Complexity O(N)
    if(head == nullptr){
        cout<<"Stack is empty"<<endl;
        return;
    }
    Node_s<T> *temp = head;
    while(temp != nullptr){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}



