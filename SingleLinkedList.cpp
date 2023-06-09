//
// Created by Merna Islam on 20/04/2023.
//
/// \author Merna Islam - 20210500

#include "SingleLinkedList.h"
#include <bits/stdc++.h>

template<class T>
SingleLinkedList<T>::SingleLinkedList(){
    /// Time complexity O(1)
    head = nullptr;
    size = 0;
}

template<class T>
void SingleLinkedList<T>::insertAtHead(T val) {
    /// Time complexity O(1)
    Node<T>* newnode = new Node<T>();
    newnode->value = val;
    if(isEmpty()){
        newnode->next = nullptr;
        head = newnode;
    } else {
        newnode->next = head;
        head = newnode;
    }
    size++;
}

template<class T>
void SingleLinkedList<T>::insertAtTail(T val){
    /// Time complexity O(n)
    Node<T> *newnode = new Node<T>();
    newnode->value = val;
    if(isEmpty()){
        head = newnode;
        newnode->next = nullptr;
    } else {
        Node<T>* current = head;
        while(current->next != nullptr){
            current = current->next;
        }
        current->next = newnode;
        newnode->next = nullptr;
    }
    size++;
}

template<class T>
void SingleLinkedList<T>::insertAt(T val, int index) {
    /// Time complexity O(n)
    if (index < 0 || index > size + 1) {
        cout << "Invalid index\n";
        return;
    }

    Node<T>* newnode = new Node<T>();
    newnode->value = val;

    if (index == 0) {
        newnode->next = head;
        head = newnode;
    } else {
        Node<T>* current = head;
        for (int i = 0; i < index-1; i++) {
            current = current->next;
        }
        newnode->next = current->next;
        current->next = newnode;
    }
    size++;
}

template<class T>
void SingleLinkedList<T>::removeAtHead(){
    /// Time complexity O(1)
    Node<T>* temp = nullptr;
    if(isEmpty()){
        cout << "Can't remove: List is already Empty\n";
        return;
    }
    if(head->next == nullptr) {
        temp = head;
        head = nullptr;
        delete temp;

    } else {
        temp = head;
        head = head->next;
        delete temp;
    }
    size--;
}

template<class T>
void SingleLinkedList<T>::removeAtTail(){
    /// Time complexity O(n)
    Node<T>* current = head;
    if(isEmpty()){
        cout << "Can't remove: List is already Empty\n";
        return;
    }
    if(head->next == nullptr) {
        head = nullptr;
        delete current;
    } else {
        Node<T>* previous = nullptr;
        while(current->next != nullptr){
            previous = current;
            current = current->next;
        }
        previous->next = current->next;
        delete current;
    }
    size--;
}

template<class T>
void SingleLinkedList<T>::removeAt(int index){
    /// Time complexity O(n)
    if(index < 0)
        return;
    Node<T>* previous = nullptr;
    Node<T>* current = head;
    int cnt = 0;
    if(isEmpty()){
        cout << "Can't remove: List is already Empty\n";
        return;
    } else if(index == 0){
        current = head;
        head = head->next;
        delete current;
    } else {
        while(current != nullptr) {
            if (cnt == index) {
                Node<T>* temp = current;
                previous->next = current->next;
                delete temp;
                return;
            }
            previous = current;
            current = current->next;
            cnt++;
        }
    }
    size--;
}

template<class T>
T SingleLinkedList<T>::retrieveAt(int index){
    /// Time complexity O(n)
    if(index < 0)
        return -1;
    Node<T>* current = head;
    int cnt = 0;
    while(current != nullptr){
        if(cnt == index){
            return current->value;
        }
        current = current->next;
        cnt++;
    }
    return -1;
}

template<class T>
void SingleLinkedList<T>::replaceAt(T val, int index){
    /// Time complexity O(n)
    Node<T>* current = head;
    if(index < 0)
        return;
    int cnt = 0;
    while(current != nullptr){
        if(cnt == index){
            current->value = val;
            break;
        }
        current = current->next;
        cnt++;
    }
}

template<class T>
bool SingleLinkedList<T>::isExist(T val){
    /// Time complexity O(n)
    Node<T>* current = head;
    bool found = false;
    while(current != nullptr){
        if(current->value == val){
            found = true;
        }
        current = current->next;
    }
    return found;
}

template<class T>
bool SingleLinkedList<T>::isItemAtEqual(T val, int index){
    /// Time complexity O(n)
    int cnt = 0;
    Node<T>* current = head;
    while(current != nullptr){
        if(current->value == val){
            if(cnt == index){
                return true;
            }
        }
        current = current->next;
        cnt++;
    }
    return false;
}

template<class T>
void SingleLinkedList<T>::swap(int firstItemIdx, int secondItemIdx){
    /// Time complexity O(n)
    if(firstItemIdx == secondItemIdx)
        return;

    Node<T>* prevFirst = nullptr;
    Node<T>* currFirst = head;
    int cntFirst = 0;
    while(currFirst != nullptr && cntFirst != firstItemIdx){
        prevFirst = currFirst;
        currFirst = currFirst-> next;
        cntFirst++;
    }

    Node<T>* prevSecond = nullptr;
    Node<T>* currSecond = head;
    int cntSecond = 0;
    while(currSecond != nullptr && cntSecond != secondItemIdx){
        prevSecond = currFirst;
        currSecond = currSecond-> next;
        cntSecond++;
    }

    if(currFirst == nullptr || currSecond == nullptr)
        return;

    if(prevFirst != nullptr){
        prevFirst->next = currSecond;
    } else {
        head = currSecond;
    }

    if(prevSecond != nullptr){
        prevSecond->next = currFirst;
    } else {
        head = currFirst;
    }

    Node<T>* temp = currFirst->next;
    currFirst->next = currSecond->next;
    currSecond->next = temp;

}

template<class T>
bool SingleLinkedList<T>::isEmpty() {
    /// Time complexity O(1)
    return(head == nullptr);
}

template<class T>
int SingleLinkedList<T>::linkedListSize() {
    /// Time complexity O(1)
    return size;
}

template<class T>
void SingleLinkedList<T>::clear(){
    /// Time complexity O(n)
    Node<T>* current = head;
    while(current != nullptr){
        Node<T>* temp = new Node<T>;
        temp = current;
        current = current->next;
        delete temp;
    }
    cleared = true;
}

template<class T>
void SingleLinkedList<T>::print() {
    /// Time complexity O(n)
    if(isEmpty()){
        cout << "Can't print: List is already Empty\n";
    } else {
        Node<T>* current = head;
        while(current != nullptr){
            cout << current->value << " ";
            current = current->next;
        }
        cout << "\n";
    }
}

template<class T>
SingleLinkedList<T>::~SingleLinkedList(){
    /// Time complexity O(n)
    if(!cleared){
        clear();
    }
}