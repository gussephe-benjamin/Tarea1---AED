//
// Created by NATALIA WATSON on 7/09/2024.
//



#include <iostream>
using namespace std;

template <typename T>
struct Node{
    T data;
    Node<T>* next;
    Node<T>* prev;

    Node(T data): data(data), next(nullptr), prev(nullptr){}

};

template <typename T>
class List{
private:
    Node<T>* head;
    Node<T>* tail;

public:
    List(): head(nullptr), tail(nullptr) {}

    T front(){
        return head->data;

    }

    T back(){
        return tail->data;
    }

    void push_front(T val){
        Node<T>* node = new Node<T>(val);

        if (head == nullptr){
            head = tail = node;
        }
        else{
            node->next = head;
            head->prev = node;
            head = node;
        }
    }

    void push_back(T val){
        Node<T>* node = new Node<T>(val);

        if (tail == nullptr){
            head = tail = node;
        }
        else{
            node->prev = tail;
            tail->next = node;
            tail = node;
        }
    }

    T pop_front(){
        if (head == nullptr){
            cout << "la lista esta vacía" << endl;
        }

        T val = head->data;
        Node<T>* temp = head;
        if (head == tail){
            head = tail = nullptr;
        }
        else{
            head = head->next;
            head->prev = nullptr;
        }
        delete temp;
        return val; //se retorna el valor que se ha quitado
    }

    T pop_back(){
        if (tail == nullptr){
            cout << "la lista está vacía" << endl;
        }
        T val = tail->data;
        Node<T>* temp = tail;
        if (head == tail){
            head = tail = nullptr;
        }
        else{
            tail = tail->prev;
            tail->next = nullptr;

        }
        delete temp;
        return val;
    }

    void insert(T val, int n){
        Node<T>* node = new Node<T>(val);

        if (n == 0){
            if (head == nullptr){
                head = tail = node;
            }
            else{
                node->next = head;
                head->prev = node;
                head = node;
            }
        }
        else{
            Node<T>* temp = head;

            for (int i = 0; i < n-1; ++i){
                temp = temp->next;
            }
            if (temp->next == nullptr){
                node->prev = temp;
                temp->next = node;
                tail = node;
            }
            else{
                node->next = temp->next;
                node->prev = temp;
                temp->next->prev = node;
                temp->next = node;
            }
        }

    }

    void remove(int n){
        Node <T>* temp = head;
        if (n == 0){
            if (head == tail){
                delete head;
                head = tail = nullptr;
            }
            else{
                head = head->next;
                head->prev = nullptr;
                delete temp;
            }
        }
        else{
            for (int i = 0; i < n; ++i){
                temp = temp->next;
            }
            if (temp == tail){
                tail = tail->prev;
                tail->next = nullptr;
                delete temp;
            }
            else{
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                delete temp;
            }
        }
    }

    T operator[](int n){
        Node<T>* temp = head;

        for (int i = 0; i < n; ++i){
            temp = temp->next;
        }

        return temp->data;
    }

    bool empty(){
        return head == nullptr;
    }

    int size(){

        int n = 0;
        Node<T>* temp = head;
        while (temp != nullptr){
            n++;
            temp = temp->next;
        }

        return n;
    }

    void clear(){

        while (head != nullptr){
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
    }

    void reverse() {
        if (head == nullptr) {
            return;
        }

        Node<T>* curr = head;
        Node<T>* temp = nullptr;

        while (curr != nullptr) {

            temp = curr->prev;
            curr->prev = curr->next;
            curr->next = temp;
            curr = curr->prev;
        }
        if (temp != nullptr) {
            tail = head;
            head = temp->prev;
        }
    }

};

