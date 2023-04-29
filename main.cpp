#include "SingleLinkedList.cpp"
#include"DLL.cpp"
#include "Queue.cpp"
#include"Stack.cpp"
#include "arrayBasedList.cpp"
#include "circularLinkedList.cpp"
#include <bits/stdc++.h>
#include <string>
using namespace std;

/// Problems:
void combineBetweenZeros(SingleLinkedList<int>* sll);
template<class T>
Node<T>* merge(Node<T>* head1, Node<T>* head2);
template<class T>
void mergeKSortedLists(int k, Node<T>* arr[]);
int precedence(char c);
bool isAlpha(char c);
string infixToPostfix(string infix);
void longest_valid_Parentheses(string input);
void generateBinaryNumbers(int n);

/// \author Nour Muhammad
/// \brief this is a class that creates a stack using the implemented queue
template<class T>
class ImplementedStackWithQueue {
    Queue<T> q;
    Queue<T> qTemp;
public:
    void push_s(T element){
        qTemp.enqueue(element);
        while(!q.isEmpty()){
            qTemp.enqueue(q.first());
            q.dequeue();
        }
        while(!qTemp.isEmpty()){
            q.enqueue(qTemp.first());
            qTemp.dequeue();
        }
    }
    void pop_s(){
        if(q.isEmpty()){
            return;
        }
        q.dequeue();
    }
    void print_s(){
        q.print();
    }
};


int main(){
/// Testing function Combine Nodes between Zeros
    cout << "\nTesting function Combine Nodes between Zeros:\n";
    SingleLinkedList<int> sll;
    sll.insertAtTail(0);
    sll.insertAtTail(1);
    sll.insertAtTail(1);
    sll.insertAtTail(2);
    sll.insertAtTail(0);
    sll.insertAtTail(3);
    sll.insertAtTail(3);
    sll.insertAtTail(9);
    sll.insertAtTail(0);
    sll.insertAtTail(4);
    sll.insertAtTail(5);
    sll.insertAtTail(0);
    sll.insertAtTail(3);
    sll.insertAtTail(0);
    sll.print();
    combineBetweenZeros(&sll);
    sll.print();

/// Testing function Merge k Sorted Linked lists
    cout << "\nTesting function Merge k Sorted Linked lists:\n";
    int k = 4;
    SingleLinkedList<int> l1;
    l1.insertAtTail(3);
    l1.insertAtTail(5);
    l1.insertAtTail(9);
    l1.insertAtTail(10);
    SingleLinkedList<int> l2;
    l2.insertAtTail(1);
    l2.insertAtTail(4);
    l2.insertAtTail(6);
    l2.insertAtTail(10);
    SingleLinkedList<int> l3;
    l3.insertAtTail(4);
    l3.insertAtTail(6);
    l3.insertAtTail(8);
    l3.insertAtTail(15);
    SingleLinkedList<int> l4;
    l4.insertAtTail(-1);
    l4.insertAtTail(0);
    l4.insertAtTail(9);
    l4.insertAtTail(89);
    SingleLinkedList<string> l5;
    l5.insertAtTail("malak");
    l5.insertAtTail("merna");
    l5.insertAtTail("orphan");
    l5.insertAtTail("rana");
    SingleLinkedList<string> l6;
    l6.insertAtTail("nayera");
    l6.insertAtTail("nour");
    l6.insertAtTail("pencil");
    l6.insertAtTail("soha");
    Node<int>* arr[4] = {l1.getHead(), l2.getHead(), l3.getHead(), l4.getHead()};
    Node<string>* arrStr[2] = {l5.getHead(), l6.getHead()};
    mergeKSortedLists(k, arr);
    mergeKSortedLists(2, arrStr);

/// Testing function Infix to Postix
    cout << "\nTesting function Infix to Postix:\n";
    string infix1 = "X^Y / (5*Z) + 2";
    string infix2 = "A + B * C + D";
    string infix3 = "(A + B) * (C + D)";
    string infix = "a+b*(c^d-e)^(f+g*h)-i";
    string postfix = infixToPostfix(infix);     // can try any other expression from the above
    cout << "Infix expression is: " << infix << "\n";
    cout << "Postfix expression is: " << postfix << "\n";

/// Testing function Longest Valid Parentheses
    cout << "\nTesting function Longest Valid Parentheses:\n";
    string val1 = "(()";
    string val2 = ")()())";
    longest_valid_Parentheses(val1);
    longest_valid_Parentheses(val2);

/// Testing function generateBinaryNumbers
    cout << "\nTesting function generateBinaryNumbers:\n";
    int n = 5;
    generateBinaryNumbers(n);
    generateBinaryNumbers(10);

/// Testing function ImplementedStackWithQueue
    cout << "\nTesting function ImplementedStackWithQueue:\n";
    ImplementedStackWithQueue<int> s;
    s.push_s(4);
    s.push_s(3);
    s.push_s(2);
    s.push_s(1);
    s.print_s();
    s.pop_s();
    s.pop_s();
    s.print_s();

/// Testing Array-Based list
    cout << "\nTesting Array-Based list:\n";
    arrayBasedList<int> arrB(6);
    arrB.insert(5);
    arrB.insert(6);
    arrB.insert(7);
    arrB.insert(8);
    arrB.insert(9);
    arrB.print();
    cout << arrB.isItemAtEqual(2,5);
    arrB.clear();
    arrB.print();

/// Testing Single Linked List
    cout << "\nTesting Single Linked List:\n";
    SingleLinkedList<int> sll2;
    sll2.insertAtHead(0);
    sll2.insertAtHead(6);
    sll2.insertAtHead(8);
    sll2.print();
    sll2.insertAtTail(8);
    sll2.insertAt(9, 2);
    sll2.print();
    sll2.removeAt(1);
    sll2.print();
    if(sll2.isItemAtEqual(8, 2)){
        cout << "yes\n";
    }
    sll2.swap(0, 1);
    cout << "List after swapping nodes at index 0 and 1: ";
    sll2.print();
    sll2.replaceAt(80, 3);
    cout << "List after replacing value at index 3 to be 80: ";
    sll2.print();
    cout << "Item retrieved at index 0: " << sll2.retrieveAt(0) << "\n";
    cout << "Removing all nodes:\n";
    sll2.removeAtHead();
    sll2.removeAtHead();
    sll2.removeAtTail();
    sll2.removeAtTail();
    sll2.removeAtHead();
    sll2.print();

/// Testing Doubly Linked List
    cout << "\nTesting Doubly Linked List:\n";


/// Testing Circular Linked List
    cout << "\nTesting Circular Linked List:\n";
    circularLinkedList<int> cll;
    cll.insertAtHead(0);
    cll.insertAtHead(6);
    cll.insertAtHead(8);
    cll.print();

/// Testing Stack
    cout << "\nTesting Stack:\n";


/// Testing Queue
    cout << "\nTesting Queue:\n";
    Queue<int> q;
    q.print();
    cout << "First element: " << q.first() << "\n";
    q.enqueue(3);
    cout << "Size after adding 1 element: " << q.queueSize() << "\n";
    cout << "First element: " << q.first() << "\n";
    q.enqueue(4);
    q.enqueue(5);
    cout << "Size after adding additional 2 elements: " << q.queueSize() << "\n";
    cout << "First element: " << q.first() << "\n";
    cout << "Quene elements: ";
    q.print();
    int val = q.dequeue();
    cout << "Deleting the first element: " << val << "\n";
    q.print();
    q.dequeue();
    q.dequeue();
    q.dequeue();
}

/// \author Merna Islam
/// \brief this is a function that combine nodes in between zeros, and edit the new values in that linked list
/// \param sll refers to a pointer of type single linked list created
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

/// \author Merna Islam
/// \brief this is a merge function for merging only 2 sorted linked lists
/// \tparam T is the template class T [data type]
/// \param head1 refers to the pointer of the head of the first linked list
/// \param head2 refers to the pointer of the head of the second linked list
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

/// \author Merna Islam
/// \brief this is a main merge k sorted linked list function for merging k given sorted linked lists
/// \tparam T is the template class T [data type]
/// \param head1 refers to the pointer of the head of the first linked list
/// \param head2 refers to the pointer of the head of the second linked list
template<class T>
void mergeKSortedLists(int k, Node<T>* arr[]) {
    Node<T>* mergedList = arr[0];
    for (int i = 1; i < k; i++) {
        mergedList = merge(mergedList, arr[i]);
    }
    while (mergedList != nullptr) {
        cout << mergedList->value << " ";
        mergedList = mergedList->next;
    }
    cout << "\n";
}

/// \author Merna Islam
/// \brief this is a function that calculates the precedence of each operator to decide whether to pop or push on top of it
/// \param c refers to the operator tested to return its precedence value
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

/// \author Merna Islam
/// \brief this is a function that identify whether the character passed to the function is a letter or not
/// \param c refers to the character to be tested
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

/// \author Merna Islam
/// \brief this is a function that convert infix expression to postfix expression
/// \param infix refers to the string infix before conversion
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

/// \author Nour Muhammad
/// \brief this is a function that calculates the longest valid parentheses in a given string
/// \param input refers to the string given to test its longest valid parentheses number
void longest_valid_Parentheses(string input){
    int cnt = 0;
    Stack<char> s;
    for(auto i : input){
        if(i == '('){
            s.push(i);
        }
        if(i == ')' && !s.isEmpty()){
            s.pop();
            cnt += 2;
        }
    }
    cout << "The longest valid parentheses is: " << cnt << endl;
}

/// \author Mohannad Hisham
/// \brief this is a function that generates and prints all binary integers from 1 to N.
/// \param n refers to the number given to print binary numbers till that n
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
    cout << endl;
}

/// \author Mohannad Hisham
/// \brief this is a function that sorts a given queue
/// \param q refers to an object by reference of the implemented queue given
void sortQueue(Queue<int>& q) {
    if (q.isEmpty() || q.queueSize() == 1) {
        return;
    }
    int sz = q.queueSize();
    int tmp = q.first();
    q.dequeue();
    Queue<int> lQ, rQ;
    for (int i = 1; i < sz; i++) {
        int x = q.first();
        q.dequeue();
        if (x < tmp)
            lQ.enqueue(x);

        else
            rQ.enqueue(x);

    }
    sortQueue(lQ);
    sortQueue(rQ);
    while (!lQ.isEmpty()) {
        q.enqueue(lQ.first());
        lQ.dequeue();
    }
    q.enqueue(tmp);
    while(!rQ.isEmpty()){
        q.enqueue(rQ.first());
        rQ.dequeue();
    }
}