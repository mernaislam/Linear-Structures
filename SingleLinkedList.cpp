//
// Created by Merna Islam on 20/04/2023.
//

#include "SingleLinkedList.h"
#include <bits/stdc++.h>

template<class T>
SingleLinkedList<T>::SingleLinkedList(){
    head = nullptr;
    size = 0;
}

template<class T>
void SingleLinkedList<T>::insertAtHead(T val) {
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
    Node<T>* temp = nullptr;
    if(isEmpty()){
        return;
    }
    if(head->next == nullptr) {
        temp = head;
        cout << "insideee\n";
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
    Node<T>* current = head;
    if(isEmpty()){
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
    if(index < 0)
        return;
    Node<T>* previous = nullptr;
    Node<T>* current = head;
    int cnt = 0;
    if(isEmpty()){
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
    return(head == nullptr);
}

template<class T>
int SingleLinkedList<T>::linkedListSize() {
    return size;
}

template<class T>
void SingleLinkedList<T>::clear(){
    Node<T>* current = head;
    while(current != nullptr){
        Node<T>* temp = current;
        current = current->next;
        delete temp;
    }
    cleared = true;
}

template<class T>
void SingleLinkedList<T>::print() {
    Node<T>* current = head;
    while(current != nullptr){
        cout << current->value << " ";
        current = current->next;
    }
    cout << "\n";
}

template<class T>
SingleLinkedList<T>::~SingleLinkedList(){
    if(!cleared){
        clear();
    }
}

template<class T>
void SingleLinkedList<T>::combineBetweenZeros(){
    Node<T>* temp = head;
    vector<int> vecTemp;
    int sum = 0;
    int cnt = linkedListSize() + 1;
    while(temp != nullptr){
        if(temp->value == 0){
            vecTemp.push_back(sum);
            sum = 0;
        } else {
            sum += temp->value;
        }
        temp = temp->next;
    }
    for (int i = 0; i < vecTemp.size(); ++i) {
        insertAtTail(vecTemp[i]);
    }
    while(cnt--){
        removeAtHead();
    }
}





