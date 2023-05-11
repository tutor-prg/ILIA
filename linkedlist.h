#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
#include <stdlib.h>

using namespace std;

template <class T>
struct Node
{
    T x;
    Node<T> *next;

    Node(T _x){
        x = _x;
        next = NULL;
    }
};

template <class T>
class LinkedList
{
    Node<T> *first;
    Node<T> *last;
    int count;
public:
    LinkedList() {
        first = NULL;
        last = NULL;
        count = 0;
    }

    LinkedList(const LinkedList& other) {
        first = NULL;
        last = NULL;
        count = 0;

        Node<T>* cur = other.first;
        while (cur){
            push_back(cur->x);
            cur = cur->next;
        }
    }

    LinkedList& operator=(const LinkedList& other){
        if (this==&other) return *this;
        clear();
        first = NULL;
        last = NULL;
        count = 0;

        Node<T>* cur = other.first;
        while (cur){
            push_back(cur->x);
            cur = cur->next;
        }
        return *this;
    }

    bool isEmpty() const {
        return first == NULL;
    }

    void push_back(T x){
        Node<T>* node = new Node<T>(x);

        if (isEmpty()){
            first = node;
            last = node;
            count = 1;
            return;
        }

        last->next = node;
        last = node;
        count = count + 1;
    }

    T pop_back(){
        if (isEmpty()) throw "pop_back() - Error: List is Empty";

        if (count == 1){
            T x = first->x;
            delete first;
            first = NULL;
            last = NULL;
            count = 0;
            return x;
        }

        Node<T>* curr = first;
        while (curr->next != last){
            curr = curr->next;
        }

        T x = last->x;
        delete last;
        curr->next = NULL;
        last = curr;
        count = count - 1;
        return x;
    }

    T peep_back(){
        if (isEmpty()) throw "peep_back() - Error: List is Empty";
        return last->x;
    }

    void push_front(T x){
        Node<T>* node = new Node<T>(x);

        if (isEmpty()){
            first = node;
            last = node;
            count = 1;
            return;
        }

        node->next = first;
        first = node;
        count = count + 1;
    }

    T pop_front(){
        if (isEmpty()) throw "pop_front() - Error: List is Empty";

        if (count == 1){
            T x = first->x;
            delete first;
            first = NULL;
            last = NULL;
            count = 0;
            return x;
        }

        T x = first->x;
        Node<T> *fst = first;
        first = first->next;
        delete fst;
        count = count - 1;
        return x;
    }

    T peep_front(){
        if (isEmpty()) throw "peep_front() - Error: List is Empty";
        return first->x;
    }

    void show(bool CR=false) const {
        if (isEmpty()) {
            cout << "Is empty." << endl;
            return;
        }
        Node<T>* curr = first;
        while (curr != NULL){
            cout << curr->x << " ";
            if (CR) cout << endl;
            curr = curr->next;
        }
        cout << endl;
    }

    void show(bool CR=false) {
        if (isEmpty()) {
            cout << "Is empty." << endl;
            return;
        }
        Node<T>* curr = first;
        while (curr != NULL){
            cout << curr->x << " ";
            if (CR) cout << endl;
            curr = curr->next;
        }
        cout << endl;
    }

    int size()const {
        return count;
    }

    void clear(){
        while (!isEmpty()){
            pop_front();
        }
    }

    T& operator[](int idx){
        if (idx < 0)      throw "LinkedList::operator[](idx) - Error: idx<0";
        if (idx >= count) throw "LinkedList::operator[](idx) - Error: idx >= count";

        Node<T>* curr = first;
        for (int i=0; i<idx; i++){
            curr = curr->next;
        }

        return curr->x;
    }

    const T& operator[](int idx)const {
        if (idx < 0)      throw "LinkedList::operator[](idx) - Error: idx<0";
        if (idx >= count) throw "LinkedList::operator[](idx) - Error: idx >= count";

        Node<T>* curr = first;
        for (int i=0; i<idx; i++){
            curr = curr->next;
        }

        return curr->x;
    }

    virtual ~LinkedList() {
        clear();
    }
};

template <class T>
class Stack : public LinkedList<T>
{
public:
    Stack() {}
    void push(T x){
        LinkedList<T>::push_front(x);
    }
    T pop(){
        return LinkedList<T>::pop_front();
    }
    virtual ~Stack() {}
};

template <class T>
class Queue : public LinkedList<T>
{
public:
    Queue() {}
    void push(T x){
        LinkedList<T>::push_back(x);
    }
    T pop(){
        return LinkedList<T>::pop_front();
    }
    virtual ~Queue() {}
};

#endif // LINKEDLIST_H
