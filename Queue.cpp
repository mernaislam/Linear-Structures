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
    front = 0;
    back = capacity -1;
}

template<class T>
Queue<T>::Queue(int sz) {
    size = 0;
    if(sz <= 0){
        capacity = 100;
    } else {
        capacity = sz;
    }
    arr = new T[capacity];
    front = 0;
    back = capacity - 1;
}

template<class T>
void Queue<T>::enqueue(T element) {
    if(size == capacity){
        cout << "Cannot add more items, Queue is full\n";
        return;
    } else {
        back = (back + 1) % capacity;
        arr[back] = element;
        size++;
    }
}

template<class T>
T Queue<T>::dequeue() {
    if(isEmpty()){
        cout << "Cannot remove items, Queue is empty\n";
    } else {
        front = (front + 1) % capacity;
        T temp = arr[front];
        size--;
        return temp;
    }
}

template<class T>
T Queue<T>::first() {
    assert(!isEmpty());
    return arr[front];
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
        for (int i = front; i != back ; i = (i + 1) % capacity) {
            cout << arr[i] << " ";
        }
        cout << arr[back] << "\n";
    }
}

template<class T>
Queue<T>::~Queue() {
    if(!isCleared){
        delete[] arr;
    }
}