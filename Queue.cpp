//
// Created by Merna Islam on 26/04/2023.
//
/// \author Merna Islam - 20210500

#include "Queue.h"
#include <iostream>
using namespace std;
template<class T>
Queue<T>::Queue() {
    /// Time complexity O(1)
    size = 0;
    capacity = 100;
    arr = new T[capacity];
    front = 0;
    back = capacity -1;
}

template<class T>
Queue<T>::Queue(int sz) {
    /// Time complexity O(1)
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
    /// Time complexity O(1)
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
    /// Time complexity O(1)
    if(isEmpty()){
        cout << "Cannot remove items, Queue is empty\n";
    } else {
        T temp = arr[front];
        front = (front + 1) % capacity;
        size--;
        return temp;
    }
}

template<class T>
T Queue<T>::first() {
    /// Time complexity O(1)
    if(isEmpty()){
        assert(isEmpty());
    }
    return arr[front];
}

template<class T>
bool Queue<T>::isEmpty() {
    /// Time complexity O(1)
    return(size == 0);
}

template<class T>
int Queue<T>::queueSize() {
    /// Time complexity O(1)
    return size;
}

template<class T>
void Queue<T>::clear() {
    /// Time complexity O(1)
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