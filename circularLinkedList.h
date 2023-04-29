//
// Created by Mohannad on 26-Apr-23.
//

#ifndef ASSIGN_3_CIRCULARLINKEDLIST_H
#define ASSIGN_3_CIRCULARLINKEDLIST_H


template<typename T>
struct Node_cll{
    T data;
    Node_cll* next;
    Node_cll* prev;
    Node_cll(){
        data = 0;
        next = nullptr;
        prev = nullptr;
    }
};
template<class T>
class circularLinkedList{
private:
    Node_cll<T> *head;
    Node_cll<T>* tail;
    int size;
public:
    circularLinkedList();
    ~circularLinkedList();
    void insertAtEnd(T item);
    void insertAtHead(T item);
    void insertAt(T item,int indx);
    void removeAtHead();
    void removeAtTail();
    void removeAt(int indx);
    T retrieveAt(int indx);
    T replaceAt(T item,int indx);
    bool isExist(T item);
    bool isItemAtEqual(T item,int indx);
    void swap(int firstItemIdx, int secondItemIdx);
    bool isEmpty();
    int cllSize();
    void clear();
    void print();


};


#endif //ASSIGN_3_CIRCULARLINKEDLIST_H
