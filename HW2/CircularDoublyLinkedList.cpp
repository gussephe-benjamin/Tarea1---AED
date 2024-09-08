#include <iostream>

template <typename T>
class CircularDoublyLinkedList {
private:
    struct Node {
        T data;
        Node* next;
        Node* prev;
        Node(T val) : data(val), next(nullptr), prev(nullptr) {}
    };
    Node* head;
    int count;

public:
    CircularDoublyLinkedList() : head(nullptr), count(0) {}

    ~CircularDoublyLinkedList() {
        clear();
    }

    T front() {
        if (empty()) throw std::out_of_range("List is empty");
        return head->data;
    }


    T back() {
        if (empty()) throw std::out_of_range("List is empty");
        return head->prev->data;
    }


    void push_front(T val) {
        Node* newNode = new Node(val);
        if (empty()) {
            head = newNode;
            head->next = head->prev = head;
        } else {
            Node* tail = head->prev;
            newNode->next = head;
            newNode->prev = tail;
            tail->next = head->prev = newNode;
            head = newNode;
        }
        count++;
    }

    void push_back(T val) {
        Node* newNode = new Node(val);
        if (empty()) {
            head = newNode;
            head->next = head->prev = head;
        } else {
            Node* tail = head->prev;
            newNode->next = head;
            newNode->prev = tail;
            tail->next = head->prev = newNode;
        }
        count++;
    }


    T pop_front() {
        if (empty()) throw std::out_of_range("List is empty");
        T val = head->data;
        if (size() == 1) {
            delete head;
            head = nullptr;
        } else {
            Node* tail = head->prev;
            Node* temp = head;
            head = head->next;
            head->prev = tail;
            tail->next = head;
            delete temp;
        }
        count--;
        return val;
    }


    T pop_back() {
        if (empty()) throw std::out_of_range("List is empty");
        Node* tail = head->prev;
        T val = tail->data;
        if (size() == 1) {
            delete head;
            head = nullptr;
        } else {
            Node* prevTail = tail->prev;
            prevTail->next = head;
            head->prev = prevTail;
            delete tail;
        }
        count--;
        return val;
    }

    void insert(T val, int pos) {
        if (pos < 0 || pos > count) throw std::out_of_range("Invalid position");
        if (pos == 0) {
            push_front(val);
        } else if (pos == count) {
            push_back(val);
        } else {
            Node* newNode = new Node(val);
            Node* temp = head;
            for (int i = 0; i < pos - 1; ++i) {
                temp = temp->next;
            }
            Node* nextNode = temp->next;
            newNode->next = nextNode;
            newNode->prev = temp;
            temp->next = newNode;
            nextNode->prev = newNode;
            count++;
        }
    }


    void remove(int pos) {
        if (pos < 0 || pos >= count) throw std::out_of_range("Invalid position");
        if (pos == 0) {
            pop_front();
        } else if (pos == count - 1) {
            pop_back();
        } else {
            Node* temp = head;
            for (int i = 0; i < pos; ++i) {
                temp = temp->next;
            }
            Node* prevNode = temp->prev;
            Node* nextNode = temp->next;
            prevNode->next = nextNode;
            nextNode->prev = prevNode;
            delete temp;
            count--;
        }
    }

    T operator[](int pos) {
        if (pos < 0 || pos >= count) throw std::out_of_range("Invalid position");
        Node* temp = head;
        for (int i = 0; i < pos; ++i) {
            temp = temp->next;
        }
        return temp->data;
    }

    bool empty() const {
        return count == 0;
    }


    int size() const {
        return count;
    }


    void clear() {
        while (!empty()) {
            pop_front();
        }
    }

    void reverse() {
        if (empty() || size() == 1) return;
        Node* curr = head;
        Node* temp = nullptr;
        do {
            temp = curr->prev;
            curr->prev = curr->next;
            curr->next = temp;
            curr = curr->prev;
        } while (curr != head);
        head = head->next;
    }
    void print() {
        if (empty()) {
            std::cout << "List is empty\n";
            return;
        }
        Node* temp = head;
        do {
            std::cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        std::cout << "\n";
    }
};

int main() {
    CircularDoublyLinkedList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.print();

    list.push_front(0);
    list.print();

    list.pop_back();
    list.print();

    list.insert(5, 2);
    list.print();

    list.reverse();
    list.print();

    return 0;
}
