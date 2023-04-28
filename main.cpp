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

template<class T>
Node<T>* merge(Node<T>* head1, Node<T>* head2) {
    if (!head1) {
        return head2;
    }
    if (!head2) {
        return head1;
    }
    Node<T>* mergedHead;
    if (head1->value < head2->value) {
        mergedHead = head1;
        if (head1->next) {
            mergedHead->next = merge(head1->next, head2);
        } else {
            mergedHead->next = head2;
        }
    } else {
        mergedHead = head2;
        if (head2->next) {
            mergedHead->next = merge(head1, head2->next);
        } else {
            mergedHead->next = head1;
        }
    }
    return mergedHead;
}

void mergeKSortedLists(int k, Node<int>* arr[]) {
    Node<int>* mergedList = arr[0];
    for (int i = 1; i < k; i++) {
        mergedList = merge(mergedList, arr[i]);
    }
    while (mergedList != nullptr) {
        cout << mergedList->value << " ";
        mergedList = mergedList->next;
    }
}

int precedence(char c){
    if(c == '^'){
        return 3;
    } else if(c == '*' || c == '/'){
        return 2;
    } else if(c == '+' || c == '-'){
        return 1;
    } else {
        return 0;
    }
}

bool isAlpha(char c){
    if(c >= 'a' && c <= 'z')
        return true;
    else if(c >= 'A' && c <= 'Z')
        return true;
    else if(c >= '0' && c <= '9')
        return true;
    else
        return false;

}

string infixToPostfix(string infix){
    Stack<char> stack;
    stack.push('#');
    string postfix;
    for (int i = 0; i < infix.size(); ++i) {
        if(isAlpha(infix[i])){
            postfix += infix[i];
            postfix += ' ';
        }
        else if(infix[i] == ' '){
            continue;
        }
        else if(infix[i] == '(' || infix[i] == '^'){
            stack.push(infix[i]);
        } else if(infix[i] == ')'){
            while (stack.top() != '#' && stack.top() != '('){
                postfix += stack.top();
                postfix += ' ';
                stack.pop();
            }
            stack.pop();
        } else {
            if(precedence(infix[i]) > precedence(stack.top())){
                stack.push(infix[i]);
            } else {
                while(precedence(infix[i]) <= precedence(stack.top()) && stack.top() != '#'){
                    postfix += stack.top();
                    postfix += ' ';
                    stack.pop();
                }
                stack.push(infix[i]);
            }
        }
    }
    while(stack.top() != '#'){
        postfix += stack.top();
        postfix += ' ';
        stack.pop();
    }
    return postfix;
}

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

//int n=5;
//    generateBinaryNumbers(n);
//    cout << endl;

//string infix1 = "X^Y / (5*Z) + 2";
//string infix2 = "A + B * C + D";
//string infix3 = "(A + B) * (C + D)";
//string infix = "a+b*(c^d-e)^(f+g*h)-i";
//string postfix = infixToPostfix(infix);
//cout << "Infix expression is: " << infix << "\n";
//cout << "Postfix expression is: " << postfix << "\n";

//int k = 4;
//SingleLinkedList<int> l1;
//l1.insertAtTail(3);
//l1.insertAtTail(5);
//l1.insertAtTail(9);
//l1.insertAtTail(10);
//SingleLinkedList<int> l2;
//l2.insertAtTail(1);
//l2.insertAtTail(4);
//l2.insertAtTail(6);
//l2.insertAtTail(10);
//SingleLinkedList<int> l3;
//l3.insertAtTail(4);
//l3.insertAtTail(6);
//l3.insertAtTail(8);
//l3.insertAtTail(15);
//SingleLinkedList<int> l4;
//l4.insertAtTail(-1);
//l4.insertAtTail(0);
//l4.insertAtTail(9);
//l4.insertAtTail(89);
//Node<int>* arr[4] = {l1.getHead(), l2.getHead(), l3.getHead(), l4.getHead()};
//mergeKSortedLists(k, arr);
}
