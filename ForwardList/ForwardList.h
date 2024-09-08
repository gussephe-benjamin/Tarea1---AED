#ifndef FORWARDLIST_H
#define FORWARDLIST_H

#include<iostream>
using namespace std;

template <typename T>
struct Node {
    T val;
    Node* next;

    Node(T val) : val(val), next(nullptr) {}
};


template <typename T>
class ForwardList {
private:
    Node<T>* head;
public:
    ForwardList();
    ~ForwardList();

    Node<T>* front();
    Node<T>* back();

    void push_front(T);
    void push_back(T);

    void pop_front();
    void pop_back();

    T operator[](int);

    bool empty();
    int size();

    void clear();
    void sort();
    void reverse();
    void printList();
};

#include "ForwardList.cpp"  // Incluir las definiciones de las funciones

#endif