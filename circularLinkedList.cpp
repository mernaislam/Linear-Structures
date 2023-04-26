//
// Created by Mohannad on 26-Apr-23.
//

#include "circularLinkedList.h"
#include <iostream>
using namespace std;

template<class T>
circularLinkedList<T>::circularLinkedList() {
    head = nullptr;
    tail = nullptr;
    size = 0;
}

template<class T>
void circularLinkedList<T>::insertAtEnd(T item) {
    Node<T> *newNode = new Node<T>();
    newNode->data = item;
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
        size++;
        return;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
        tail->next = head;
        head->prev = tail;
        size++;
        return;
    }
}

template<class T>
void circularLinkedList<T>::insertAtHead(T item) {
    Node<T> *newNode = new Node<T>();
    newNode->data = item;
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
        size++;
        return;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        head->prev = tail;
        tail->next = head;
        size++;
        return;
    }
}

template<class T>
void circularLinkedList<T>::insertAt(T item, int indx) {
    if (isEmpty()) {
        cout << "CLL is empty." << endl;
        return;
    }
    if (indx > size - 1 || indx < 0) {
        cout << "Invalid input." << endl;
        return;
    } else {
        Node<T> *newNode = new Node<T>();
        newNode->data = item;
        Node<T> *tmp = head;
        bool first = true;
        int cnt = 0;
        while ((tmp != head || first) && cnt != indx) {
            tmp = tmp->next;
            first = false;
            cnt++;
        }
        if (cnt == 0) {
            head->prev = newNode;
            newNode->next = head;
            head = newNode;
            head->prev = tail;
            tail->next = head;
            size++;
            return;
        } else {
            tmp->prev->next = newNode;
            newNode->prev = tmp->prev;
            newNode->next = tmp;
            tmp->prev = newNode;
            size++;
            return;
        }
    }
}

template<class T>
void circularLinkedList<T>::removeAtHead() {
    if (isEmpty()) {
        cout << "CLL is empty." << endl;
        return;
    } else {
        Node<T> *tmp = head;
        head = head->next;
        head->prev = tail;
        tail->next = head;
        delete tmp;
        size--;
        return;
    }

}
template<class T>
void circularLinkedList<T>::removeAt(int indx) {
    if (isEmpty()) {
        cout << "CLL is empty." << endl;
        return;
    }
    if (indx > size - 1 || indx < 0) {
        cout << "Invalid input." << endl;
        return;
    }
    else {
        Node<T> *tmp = head;
        bool first = true;
        int cnt = 0;
        while ((tmp != head || first) && cnt != indx) {
            tmp = tmp->next;
            first = false;
            cnt++;
        }
        if (cnt == 0) {
            head = head->next;
            head->prev = tail;
            tail->next = head;
            delete tmp;
            size--;
            return;
        } else {
            tmp->prev->next = tmp->next;
            tmp->next->prev = tmp->prev;
            delete tmp;
            size--;
            return;
        }
    }
}

template<class T>
void circularLinkedList<T>::removeAtTail() {
    if (isEmpty())
        cout << "CLL is empty." << endl;
    else {
        Node<T> *tmp = tail;
        tail = tail->prev;
        tail->next = head;
        head->prev = tail;
        delete tmp;
        size--;
        return;
    }
}

template<class T>
T circularLinkedList<T>::retrieveAt(int indx){
    if (isEmpty()) {
        cout << "CLL is empty." << endl;
        return -1;
    }
    if (indx > size - 1 || indx < 0) {
        cout << "Invalid input." << endl;
        return -1;
    } else {
        Node<T> *tmp = head;
        bool first = true;
        int cnt = 0;
        while ((tmp != head || first) && cnt != indx) {
            tmp = tmp->next;
            first = false;
            cnt++;
        }
        return tmp->data;
    }
}

template<class T>
T circularLinkedList<T>::replaceAt(T item, int indx) {
    if(isEmpty()){
        cout << "CLL is empty." << endl;

    }
    if(indx > size-1 || indx < 0){
        cout << "Invalid input." << endl;

    }
    else{
        Node<T>* tmp=head;
        bool first = true;
        int cnt =0;
        while((tmp != head ||first) && cnt != indx){
            tmp=tmp->next;
            first = false;
            cnt++;
        }
        if(cnt == 0){
            head->data=item;
        }
        else{
            tmp->data = item;
        }
    }
}

template<class T>
bool circularLinkedList<T>::isExist(T item) {
    Node<T>* tmp=head;
    bool first=true;
    while(tmp !=head || first){
        if(tmp->data == item)
            return true;
        tmp=tmp->next;
        first= false;
    }
    return false;
}

template<class T>
bool circularLinkedList<T>::isItemAtEqual(T item, int indx) {
    if(isEmpty()){
        cout << "CLL is empty." << endl;
    }
    if(indx > size-1 || indx < 0){
        cout << "Invalid input." << endl;

    }
    else{
        Node<T>* tmp=head;
        bool first = true;
        int cnt =0;
        while((tmp != head ||first) && cnt != indx){
            tmp=tmp->next;
            first = false;
            cnt++;
        }
        if(cnt == 0){
            if(head->data == item)
                return true;
        }
        else{
            if(tmp->data = item)
                return true;
        }
    }
    return false;
}

template<class T>
void circularLinkedList<T>::swap(int firstItemIdx, int secondItemIdx){
    if(isEmpty()){
        cout << "CLL is empty." << endl;
        return;
    }
    if(firstItemIdx == secondItemIdx) {
        cout << "Indices are the same." << endl;
        return;
    }
    if((firstItemIdx > size-1 || firstItemIdx < 0)||(secondItemIdx > size-1 || secondItemIdx < 0)){
        cout << "Invalid input." << endl;
        return;
    }
    else{
        Node<T>* tmp1 = head;
        Node<T>* tmp2 = head;
        bool frst1 = true;
        bool frst2 = true;
        int cnt1=0;
        int cnt2=0;
        while((tmp1!=head || frst1) && cnt1 != firstItemIdx){
            tmp1=tmp1->next;
            frst1 = false;
            cnt1++;
        }
        while((tmp2!=head || frst2) && cnt2 != secondItemIdx){
            tmp2=tmp2->next;
            frst2 = false;
            cnt2++;
        }
        if(cnt1==0)
            head = tmp2;
        else if(cnt2==0)
            head=tmp1;
        tmp2->prev->next = tmp1;
        tmp1->prev->next = tmp2;
        Node<T>* tmp = tmp2->next;
        tmp2->next = tmp1->next;
        tmp1->next = tmp;
        tmp = tmp2->prev;
        tmp2->prev = tmp1->prev;
        tmp1->prev = tmp;
    }
}

template<class T>
bool circularLinkedList<T>::isEmpty() {
    return (size ==0);
}

template<class T>
int circularLinkedList<T>::cllSize(){
    return size;
}

template<class T>
void circularLinkedList<T>::clear(){
    head= nullptr;
    tail= nullptr;
    size=0;
}

template<class T>
void circularLinkedList<T>::print(){
    if (head == nullptr) {
        cout << "List is empty" << endl;
        return;
    }
    Node<T>* tmp = head;
    bool first = true;
    while (tmp != head || first) {
        cout << tmp->data << ' ';
        tmp = tmp->next;
        first = false;
    }
    cout << endl;
}

