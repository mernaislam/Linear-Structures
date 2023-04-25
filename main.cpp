//
// Created by Merna Islam on 20/04/2023.
//
#include "SingleLinkedList.cpp"
#include <iostream>
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
}
