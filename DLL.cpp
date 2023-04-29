//
// Created by Nour Muhammad on 4/26/2023.
//
/// \author Nour Muhammad - 20210428

#include"DLL.h"
#include<bits/stdc++.h>
using namespace std;

template<class T>
DLL<T>::DLL() {
    ///Time Complexity O(1)
    head = nullptr;
    tail = nullptr;
    size = 0;
}
template<class T>
DLL<T>::~DLL() {
    Node_dll<T>* temp = head;
    while(temp != nullptr){
        Node_dll<T>* temp2 = temp->next;
        free(temp);
        temp = temp2;
    }
}
template<class T>
void DLL<T>::insertAtHead(T element) {
    ///Time Complexity O(1)
    Node_dll<T>* newnode_dll = new Node_dll<T>(element);
    if(head == nullptr){
        head = newnode_dll;
        tail = newnode_dll;
    }
    else{
        newnode_dll->next= head;
        head->previous = newnode_dll;
        head = newnode_dll;
    }
    size++;
}

template<class T>
void DLL<T>::insertAtTail(T element) {
    ///Time Complexity O(1)
    Node_dll<T>* newnode_dll = new Node_dll<T>(element);
    if(head == nullptr){
        head = newnode_dll;
        tail = newnode_dll;
    }
    else{
        tail->next = newnode_dll;
        newnode_dll->previous = tail;
        tail = newnode_dll;
    }
    size++;
}
template<class T>
void DLL<T>::insertAt(T element, int index) {
    ///Time Complexity O(N)
    if(index<0 || index > size){
        cout<<"Index is out of range"<<endl;
        return;
    }
    if (index == 0){
        this->insertAtHead(element);
    }
    else if (index == size){
        this->insertAtTail(element);
    }
    else {
        Node_dll<T> *newnode_dll = new Node_dll<T>(element);
        int cnt = 0;
        Node_dll<T> *temp = head;
        while (cnt != index - 1) {
            temp = temp->next;
            cnt++;
        }
        newnode_dll->next = temp->next;
        newnode_dll->previous = temp;
        temp->next->previous = newnode_dll;
        temp->next = newnode_dll;
        size++;
    }
}

template<class T>
void DLL<T>::insertAfter(Node_dll<T> *prev_node_dll, T data) {
    ///Time Complexity O(1)
    Node_dll<T>* newnode_dll = new Node_dll<T>(data);
    newnode_dll->next = prev_node_dll->next;
    if(prev_node_dll != tail) {
        prev_node_dll->next->previous = newnode_dll;
    }
    newnode_dll->previous = prev_node_dll;
    prev_node_dll->next = newnode_dll;
    if(prev_node_dll == tail){
        tail = newnode_dll;
    }
    size++;
}

template<class T>
void DLL<T>::removeAtHead() {
    ///Time Complexity O(1)
    if(head == nullptr){
        cout<<"List is empty"<<endl;
        return;
    }
    if(size == 1){
        free(head);
        free(tail);
        head = tail = nullptr;
    }
    else{
        Node_dll<T>* temp = head;
        head = head->next;
        free(temp);
    }
    size--;
}

template<class T>
void DLL<T>::removeAtTail() {
    ///Time Complexity O(1)
    if(head == nullptr){
        cout<<"List is empty"<<endl;
        return;
    }
    if(size == 1){
        Node_dll<T> * temp = head;
        head = tail = nullptr;
        free(temp);
    }
    else{
        Node_dll<T> * temp = tail;
        tail = tail->previous;
        tail->next = nullptr;
        free(temp);
    }
    size--;
}

template<class T>
void DLL<T>::removeAt(int index) {
    ///Time Complexity O(N)
    if (index == 0) {
        this->removeAtHead();
    }
    else if(index == size-1){
        this->removeAtTail();
    }
    else {
        Node_dll<T> *temp = head;
        int cnt = 0;
        while (cnt != index) {
            temp = temp->next;
            cnt++;
        }
        temp->next->previous = temp->previous;
        temp->previous->next = temp->next;
        free(temp);
        size--;
    }
}

template<class T>
T DLL<T>::retrieveAt(int index) {
    ///Time Complexity O(N)
    int cnt = 0;
    Node_dll<T>* temp = head;
    while(cnt != index){
        temp = temp->next;
        cnt++;
    }
    return temp->data;
}

template<class T>
void DLL<T>::replaceAt(T element, int index) {
    ///Time Complexity O(N)
    int cnt = 0;
    Node_dll<T>* temp = head;
    while(cnt != index){
        temp = temp->next;
        cnt++;
    }
    temp->data = element;
}

template<class T>
bool DLL<T>::isExist(T element) {
    ///Time Complexity O(N)
    bool found = false;
    Node_dll<T>* temp = head;
    while(temp != nullptr){
        if(temp->data == element){
            found = true;
            break;
        }
        temp= temp->next;
    }
    return found;
}

template<class T>
bool DLL<T>::isItemAtEqual(T element, int index) {
    ///Time Complexity O(N)
    int cnt = 0;
    Node_dll<T>* temp = head;
    while(cnt != index){
        temp = temp->next;
        cnt++;
    }
    if(temp->data == element){
        return true;
    }
    else{
        return false;
    }
}

template<class T>
void DLL<T>::Swap(int firstIndex, int secondIndex) {
    ///Time Complexity O(N)
    if(size == 0 || size == 1){
        cout<<"List's size is not sufficient for swapping"<<endl;
        return;
    }
    if(firstIndex == secondIndex){
        return;
    }
    //get position of first node_dll
    int cnt1 = 0;
    Node_dll<T> *firstNode_dll = head;
    while (cnt1 != firstIndex) {
        firstNode_dll = firstNode_dll->next;
        cnt1++;
    }
    //get position of second node_dll
    int cnt2 = 0;
    Node_dll<T> *secondNode_dll = head;
    while (cnt2 != secondIndex) {
        secondNode_dll = secondNode_dll->next;
        cnt2++;
    }
    //change position of head or tail or both if needed
    if(firstNode_dll == head){
        head = secondNode_dll;
    }
    else if(secondNode_dll == head){
        head == firstNode_dll;
    }
    if(firstNode_dll == tail){
        tail = secondNode_dll;
    }
    else if(secondNode_dll == tail){
        tail = firstNode_dll;
    }

    //Reverse next pointers
    Node_dll<T> * temp;
    temp = firstNode_dll->next;
    firstNode_dll->next = secondNode_dll->next;
    secondNode_dll->next = temp;

    //make the next node_dll's previous pointing to the new node_dll if needed
    if(firstNode_dll->next != nullptr){
        firstNode_dll->next->previous = firstNode_dll;
    }
    if(secondNode_dll->next != nullptr){
        secondNode_dll->next->previous = secondNode_dll;
    }

    //reverse previous pointers
    temp = firstNode_dll->previous;
    firstNode_dll->previous = secondNode_dll->previous;
    secondNode_dll->previous = temp;

    //make the previous node_dll's next pointing to the new node_dll if needed
    if(firstNode_dll->previous != nullptr){
        firstNode_dll->previous->next = firstNode_dll;
    }
    if(secondNode_dll->previous != nullptr){
        secondNode_dll->previous->next = secondNode_dll;
    }
}

template<class T>
void DLL<T>::reverse() {
    ///Time Complexity O(N)
    Node_dll<T>* current = head;
    Node_dll<T>* nextNode_dll;
    while(current != nullptr){
        nextNode_dll = current->next;
        current->next = current->previous;
        current->previous = nextNode_dll;
        current = nextNode_dll;
    }
    current = head;
    head = tail;
    tail = current;
}

template<class T>
bool DLL<T>::isEmpty() {
    ///Time Complexity O(1)
    return(head == nullptr);
}
template<class T>
int DLL<T>::doubleLikedListSize() {
    ///Time Complexity O(1)
    return size;
}

template<class T>
void DLL<T>::clear() {
    ///Time Complexity O(N)
    int cnt = size;
    while(cnt--){
        this->removeAtTail();
    }
}

template<class T>
void DLL<T>::forwardTraversal() {
    ///Time Complexity O(N)
    if(head == nullptr){
        cout<<"The list is empty";
    }else{
        Node_dll<T>* temp = head;
        while(temp != nullptr){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
    }
}

template<class T>
void DLL<T>::backwardTraversal() {
    ///Time Complexity O(N)
    if(head == nullptr){
        cout<<"The list is empty";
    }
    else{
        Node_dll<T>* temp = tail;
        while(temp != nullptr){
            cout<<temp->data<<" ";
            temp = temp->previous;
        }
    }
}

