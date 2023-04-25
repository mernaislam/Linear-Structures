//
// Created by Merna Islam on 20/04/2023.
//
#include "SingleLinkedList.cpp"
#include "Queue.cpp"
#include <bits/stdc++.h>
using namespace std;

int main(){
    SingleLinkedList<int> sll;
    sll.insertAtHead(0);
    sll.insertAtHead(6);
    sll.insertAtHead(8);
    sll.print();
    sll.insertAtTail(8);
    sll.insertAt(9, 2);
    sll.print();
    sll.removeAt(1);
    sll.print();
    if(sll.isItemAtEqual(8, 2)){
        cout << "yes\n";
    }

    Queue<int> q;
    q.print();
    cout << "first2: " << q.first() << "\n";
    q.enqueue(3);
    cout << "size1:" << q.queueSize() << "\n";
    cout << "first2: " << q.first() << "\n";
    q.enqueue(4);
    q.enqueue(5);
    cout << "size2:" << q.queueSize() << "\n";
    cout << "first2: " << q.first() << "\n";
    q.print();
    int val = q.dequeue();
    cout << val << "\n";
    q.print();
    int val2 = q.dequeue();
    cout << val2 << "\n";
    q.print();
    int val3 = q.dequeue();
    cout << val3 << "\n";
    q.print();
    q.dequeue();
}
