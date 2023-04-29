//
// Created by Mohannad on 26-Apr-23.
//
/// \author Mohannad Hisham - 20210413

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
    Node_cll<T> *newNode_cll = new Node_cll<T>();
    newNode_cll->data = item;
    if (head == nullptr) {
        head = newNode_cll;
        tail = newNode_cll;
        size++;
        return;
    } else {
        tail->next = newNode_cll;
        newNode_cll->prev = tail;
        tail = newNode_cll;
        tail->next = head;
        head->prev = tail;
        size++;
        return;
    }
}

template<class T>
void circularLinkedList<T>::insertAtHead(T item) {
    Node_cll<T> *newNode_cll = new Node_cll<T>();
    newNode_cll->data = item;
    if (head == nullptr) {
        head = newNode_cll;
        tail = newNode_cll;
        size++;
        return;
    } else {
        newNode_cll->next = head;
        head->prev = newNode_cll;
        head = newNode_cll;
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
        Node_cll<T> *newNode_cll = new Node_cll<T>();
        newNode_cll->data = item;
        Node_cll<T> *tmp = head;
        bool first = true;
        int cnt = 0;
        while ((tmp != head || first) && cnt != indx) {
            tmp = tmp->next;
            first = false;
            cnt++;
        }
        if (cnt == 0) {
            head->prev = newNode_cll;
            newNode_cll->next = head;
            head = newNode_cll;
            head->prev = tail;
            tail->next = head;
            size++;
            return;
        } else {
            tmp->prev->next = newNode_cll;
            newNode_cll->prev = tmp->prev;
            newNode_cll->next = tmp;
            tmp->prev = newNode_cll;
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
        Node_cll<T> *tmp = head;
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
        Node_cll<T> *tmp = head;
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
        Node_cll<T> *tmp = tail;
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
        Node_cll<T> *tmp = head;
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
        Node_cll<T>* tmp=head;
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
    Node_cll<T>* tmp=head;
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
        Node_cll<T>* tmp=head;
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
            if(tmp->data == item)
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
        Node_cll<T>* tmp1 = head;
        Node_cll<T>* tmp2 = head;
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
        Node_cll<T>* tmp = tmp2->next;
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
    if(isEmpty()){
        cout << "CLL is empty." << endl;
        return;
    }
    Node_cll<T>* current = head;
    bool first = true;
    while (current != head || first) {
        Node_cll<T>* tmp = current;
        current = current->next;
        tmp->next=nullptr;
        tmp->prev=nullptr;
        first = false;
        delete tmp;
    }
    head = nullptr;
    tail = nullptr;
    this->size = 0;
}



//template<class T>
//void circularLinkedList<T>::clear(){
//    int cnt = cllSize();
//    while(cnt--){
//        this->removeAtTail();
//    }
//}

template<class T>
void circularLinkedList<T>::print(){
    if (head == nullptr) {
        cout << "List is empty" << endl;
        return;
    }
    Node_cll<T>* tmp = head;
    bool first = true;
    while (tmp != head || first) {
        cout << tmp->data << ' ';
        tmp = tmp->next;
        first = false;
    }
    cout << endl;
}

template<class T>
circularLinkedList<T>::~circularLinkedList() {
    Node_cll<T>* current = head;
    bool first = true;
    while (current != head || first) {
        Node_cll<T>* tmp = current;
        current = current->next;
        tmp->next=nullptr;
        tmp->prev=nullptr;
        first = false;
        delete tmp;
    }
    head = nullptr;
    tail = nullptr;
    this->size = 0;
}