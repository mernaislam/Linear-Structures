//
// Created by Merna Islam on 26/04/2023.
//

#ifndef LINKEDLISTS_QUEUE_H
#define LINKEDLISTS_QUEUE_H

template<class T>
class Queue {
    int front, back;
    T* arr;
    int size;
    int capacity;
    bool isCleared = false;
public:
    Queue();
    Queue(int sz);
    void enqueue (T element);
    T dequeue ();   //return the first element and remove it.
    T first ();     //return the first element without removing it.
    bool isEmpty ();
    int queueSize ();
    void clear ();
    void print ();
    ~Queue();
};


#endif //LINKEDLISTS_QUEUE_H
