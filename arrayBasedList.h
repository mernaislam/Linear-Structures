//
// Created by Mohannad on 26-Apr-23.
//
/// \author Mohannad Hisham - 20210413

#ifndef ASSIGN_3_ARRAYBASEDLIST_H
#define ASSIGN_3_ARRAYBASEDLIST_H

template <class T>
class arrayBasedList{
    T* list;
    int len;
    int maxSize;
public:
    arrayBasedList(int sz);
    ~arrayBasedList();
    int seqSearch(T& item);
    void insert(T item);
    void insertAt(int indx,T item);
    T retrieveAt(int indx);
    void removeAt(int indx);
    T replaceAt(int indx,T item);
    bool isItemAtEqual(int indx,T item);
    bool isEmpty();
    bool isFull();
    int listSize();
    int maxListSize();
    void clear();
    void print();
};


#endif //ASSIGN_3_ARRAYBASEDLIST_H
