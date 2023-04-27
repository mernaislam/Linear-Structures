//
// Created by Merna Islam on 20/04/2023.
//
#include "SingleLinkedList.cpp"
#include"DLL.cpp"
#include "Queue.cpp"
#include"Stack.cpp"
#include "arrayBasedList.cpp"
#include "circularLinkedList.cpp"
#include <bits/stdc++.h>
using namespace std;

void longest_valid_Parentheses(){
    int cnt = 0;
    Stack<char> s;
    string input;
    cout<<"Enter the string for the longest valid parentheses:  ";
    cin>>input;
    for(auto i : input){
        if(i == '('){
            s.push(i);
        }
        if(i == ')' && !s.isEmpty()){
            s.pop();
            cnt+=2;
        }
    }
    cout<<"The longest valid parentheses is: "<<cnt<<endl;
}

void combineBetweenZeros(SingleLinkedList<int>* sll){
    Node<int>* temp = sll->getHead();
    vector<int> vecTemp;
    int sum = 0;
    int cnt = sll->linkedListSize() + 1;
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
        sll->insertAtTail(vecTemp[i]);
    }
    while(cnt--){
        sll->removeAtHead();
    }
}

void generateBinaryNumbers(int n){
    Queue<string> q;
    q.enqueue("1");
    while (n--)
    {
        string s1 = q.first();
        q.enqueue(q.first() + '0');
        q.enqueue(q.first() + '1');
        cout << q.first() << ' ';
        q.dequeue();
    }
}

void generate(int n){
    queue<string> q;
    q.push("1");
    while (n--)
    {
        string s1 = q.front();
        q.push(q.front() + '0');
        q.push(q.front() + '1');
        cout << q.front() << ' ';
        q.pop();
    }
}

int main(){
//    SingleLinkedList<int> sll;
//    sll.insertAtTail(0);
//    sll.insertAtTail(1);
//    sll.insertAtTail(1);
//    sll.insertAtTail(2);
//    sll.insertAtTail(0);
//    sll.insertAtTail(3);
//    sll.insertAtTail(3);
//    sll.insertAtTail(9);
//    sll.insertAtTail(0);
//    sll.insertAtTail(4);
//    sll.insertAtTail(5);
//    sll.insertAtTail(0);
//    sll.insertAtTail(3);
//    sll.insertAtTail(0);
//    sll.print();
//    combineBetweenZeros(&sll);
//    sll.print();
//    sll.insertAtHead(0);
//    sll.insertAtHead(6);
//    sll.insertAtHead(8);
//    sll.print();
//    sll.insertAtTail(8);
//    sll.insertAt(9, 2);
//    sll.print();
//    sll.removeAt(1);
//    sll.print();
//    if(sll.isItemAtEqual(8, 2)){
//        cout << "yes\n";
//    }
//
//    Queue<int> q;
//    q.print();
//    cout << "first2: " << q.first() << "\n";
//    q.enqueue(3);
//    cout << "size1:" << q.queueSize() << "\n";
//    cout << "first2: " << q.first() << "\n";
//    q.enqueue(4);
//    q.enqueue(5);
//    cout << "size2:" << q.queueSize() << "\n";
//    cout << "first2: " << q.first() << "\n";
//    q.print();
//    int val = q.dequeue();
//    cout << val << "\n";
//    q.print();
//    int val2 = q.dequeue();
//    cout << val2 << "\n";
//    q.print();
//    int val3 = q.dequeue();
//    cout << val3 << "\n";
//    q.print();
//    q.dequeue();

//    circularLinkedList<int> cll;
//    cll.insertAtHead(0);
//    cll.insertAtHead(6);
//    cll.insertAtHead(8);
//    cll.print();
//
//
//    arrayBasedList<int> arr(6);
//    arr.insert(5);
//    arr.insert(6);
//    arr.insert(7);
//    arr.insert(8);
//    arr.insert(9);
//    arr.print();
//    cout << arr.isItemAtEqual(2,5);
//    arr.clear();
//    arr.print();

int n=5;
    generateBinaryNumbers(n);
    cout << endl;
    generate(n);

}
