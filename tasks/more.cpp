#include <iostream>

template <typename T>
struct Node {
    int data;
    Node* next;
};

template <typename T>
void split(Node<int>* first, Node<int>*& a, Node<int>*& b) {
    if (first == nullptr) {
        return;
    }
    Node<int>* fast = first->next;
    Node<int>* slow = first;

    while (fast != nullptr) {
        fast = fast->next;
        if (fast != nullptr) {
            fast = fast->next;
            slow = slow->next; 
        }
    }
    // if not void return slow;
    a = first;
    b = slow->next;
    slow->next = nullptr;
}

template <typename T>
Node<int>* binarySearch(Node<int>* first, int key, Node<int>* last = nullptr) 
{
    if (first == nullptr) {
        return first;
    }

    Node<int>* middle = findMiddleElementInList(first, last);
    if (key == middle->data) {
        return middle;
    } else if (key < middle->data) {
        return binarySearch(first, key, middle);
    } else {
        return binarySearch(middle->next, key);
    }
}