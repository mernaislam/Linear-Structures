//
// Created by Merna Islam on 26/04/2023.
//

#include "Queue.h"
#include <iostream>
using namespace std;
template<class T>
Queue<T>::Queue() {
    size = 0;
    capacity = 100;
    arr = new T[capacity];
    front = back = 0;
}

template<class T>
Queue<T>::Queue(int sz) {
    size = 0;
    capacity = sz;
    arr = new T[capacity];
    front = back = 0;
}

template<class T>
void Queue<T>::enqueue(T element) {
    if(size == capacity){
        cout << "Cannot add more items, Queue is full\n";
        return;
    } else {
       arr[size] = element;
    }
    size++;
    back++;
}

template<class T>
T Queue<T>::dequeue() {
    if(isEmpty()){
        cout << "Cannot remove items, Queue is empty\n";
//        return -1;
    } else {
        T temp = arr[front];
        front++;
        size--;
        return temp;
    }
}

template<class T>
T Queue<T>::first() {
    if(!isEmpty()){
        return arr[front];
    }
//    else {
//        cout << "Queue is Empty\n";
//        return -1;
//    }
//
}

template<class T>
bool Queue<T>::isEmpty() {
    return(size == 0);
}

template<class T>
int Queue<T>::queueSize() {
    return size;
}

template<class T>
void Queue<T>::clear() {
    delete[] arr;
    isCleared = true;
}

template<class T>
void Queue<T>::print() {
    if(size == 0){
        cout << "Queue is Empty\n";
    } else {
        for (int i = front; i < back; ++i) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
}

template<class T>
Queue<T>::~Queue() {
    if(!isCleared){
        delete[] arr;
    }
}