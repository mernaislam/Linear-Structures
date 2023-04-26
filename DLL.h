//
// Created by Nour Muhammad on 4/26/2023.
//

#ifndef LINKEDLISTS_DLL_H
#define LINKEDLISTS_DLL_H

template <class T>
class Node_dll{
public:
    T data;
    Node_dll* previous;
    Node_dll* next;
    Node_dll(T value){
        data = value;
        next = nullptr;
        previous = nullptr;
    }
};

template<class T>
class DLL {
    Node_dll<T>* head;
    Node_dll<T>* tail;
    int size;
public:
    DLL();
    void insertAtHead(T element);
    void insertAtTail(T element);
    void insertAt(T element, int index);
    void insertAfter(Node_dll<T>* prev_node_dll, T data);
    void removeAtHead();
    void removeAtTail();
    void removeAt(int index);
    T retrieveAt(int index);
    void replaceAt(T element, int index);
    bool isExist(T element);
    bool isItemAtEqual(T element, int index);
    void Swap(int firstIndex, int secondIndex);
    void reverse();
    bool isEmpty();
    int doubleLikedListSize();
    void clear();
    void forwardTraversal();
    void backwardTraversal();
};


#endif //LINKEDLISTS_DLL_H
