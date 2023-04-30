//
// Created by Mohannad on 26-Apr-23.
//
/// \author Mohannad Hisham - 20210413

#include "arrayBasedList.h"
#include <iostream>
using namespace std;

template <class T>
arrayBasedList<T> ::arrayBasedList(int sz) {
    if (sz < 0){
        cout << "Size must be positive. Creating"
             << "an array of size 50. " << endl;
        maxSize = 50;
    }
    else
        maxSize = sz;
    len = 0;
    list = new T[maxSize];
}

template <class T>
arrayBasedList<T>::~arrayBasedList(){
    delete [] list;
}

template <class T>
int arrayBasedList<T>::seqSearch(T& item){
    int loc;
    bool found=false;
    for(int i=0;i < len;i++){
        if(list[loc] == item){
            found=true;
            loc++;
            break;
        }
    }
    if(found)
        return loc;
    else
        return -1;
}

template <class T>
void arrayBasedList<T>::insert(T item){
    int loc;
    if(len ==0)
        list[len++] = item;
    else if(len == maxSize)
        cout << "Cannot insert, List is Full." << endl;
    else{
        loc = seqSearch(item);
        if(loc == -1)
            list[len++] = item;
        else
            cout << "Item exists." << endl;
    }
}

template <class T>
void arrayBasedList<T>::insertAt(int indx, T item) {
    if(indx < 0 || indx >= maxSize)
        cout << "Out of range." << endl;
    else{
        if(len >= maxSize)
            cout << "List is full." << endl;
        else{
            for(int i=len ; i > indx;i--){
                list[i]= list[i-1];
            }
            list[indx] = item;
            len++;
        }
    }
}

template <class T>
T arrayBasedList<T>::retrieveAt(int indx) {
    if(indx < 0 || indx >=len)
        cout << "Index out of range." << endl;
    else{
        cout << list[indx] << endl;
    }
}

template <class T>
void arrayBasedList<T>::removeAt(int indx) {
    if(indx < 0 || indx >=len)
        cout << "Index out of range." << endl;
    else{
        for(int i = indx;i< len-1;i++)
            list[i] = list[i+1];
        len--;
    }
}

template <class T>
T arrayBasedList<T>::replaceAt(int indx, T item) {
    if(indx < 0 || indx >=len)
        cout << "Index out of range." << endl;
    else
        list[indx]=item;
}

template <class T>
bool arrayBasedList<T>::isItemAtEqual(int indx, T item) {
    return (list[indx] == item);
}

template <class T>
bool arrayBasedList<T>::isEmpty() {
    return (len == 0);
}

template <class T>
bool arrayBasedList<T>::isFull(){
    return (len == maxSize);
}

template <class T>
void arrayBasedList<T>::clear() {
    len = 0;
}

template <class T>
void arrayBasedList<T>::print() {
    if (isEmpty())
        cout << "List is empty." << endl;
    for(int i=0;i < len;i++){
        cout << list[i] << ' ';
    }
    cout << endl;
}

template <class T>
int arrayBasedList<T>::listSize() {
    return len;
}

template <class T>
int arrayBasedList<T>::maxListSize() {
    return maxSize;
}