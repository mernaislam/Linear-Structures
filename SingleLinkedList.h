//
// Created by Merna Islam on 20/04/2023.
//

#ifndef ASSIGNMENT_2_SINGLELINKEDLIST_H
#define ASSIGNMENT_2_SINGLELINKEDLIST_H

#include <iostream>
using namespace std;

template<class T>
struct Node {
    int value;
    Node* next;
};

template<class T>
class SingleLinkedList {
private:
    Node<T>* head;
    int size;
    bool cleared = false;
public:
    SingleLinkedList();
    void insertAtHead(T val);
    void insertAtTail(T val);
    void insertAt(T val, int index);
    void removeAtHead();
    void removeAtTail();
    void removeAt(int index);
    T retrieveAt(int index);
    void replaceAt(T val, int index);
    bool isExist(T val);
    bool isItemAtEqual(T val, int index);
    void swap(int firstItemIdx, int secondItemIdx);
    bool isEmpty();
    int linkedListSize();
    void clear();
    void print();
    ~SingleLinkedList();
    Node<T>* getHead(){
        return head;
    }
};


#endif //ASSIGNMENT_2_SINGLELINKEDLIST_H
