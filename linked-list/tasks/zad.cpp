#include <iostream>

template <typename T>
struct Node {
    int data;
    Node* next;
};

template <typename T>
void printNode(Node<T>* head)
{
    while (head != nullptr)
    {
        std::cout << head->data << std::endl;
        head = head->next;
    }
}

template <typename T>
void reverseList(Node<int>*& first) {
    if (first == nullptr || first->next == nullptr) {
        return;
    }

    Node<int>* current = first;
    Node<int>* prev = nullptr;
    Node<int>* nxt = nullptr;

    while (current != nullptr) {
        nxt = current->next;
        current->next = prev;
        prev = current;
        current = nxt;
    }

    first = prev;
}

Node<int>* fibonacci(int n)
{
    if (n <= 0)
    {
        return nullptr;
    }
    Node<int>* head = new Node<int>{1, nullptr};
    if (n == 1)
    {
        
        return head;
    }
    if (n == 2)
    {
        Node<int>* prev = head;
        Node<int>* crr = new Node<int>{1, nullptr};
        head->next = crr;
        return head;
    }else
    {
        Node<int>* prev = head;
        Node<int>* crr = new Node<int>{1, nullptr};
        head->next = crr;
        while (n != 2)
        {
            Node<int>* temp = new Node<int>{(prev->data + crr->data),nullptr};
            crr->next = temp;
            prev = crr;
            crr = temp;
            n--;
        }
        return head;
    } 
}


int main()
{
    Node<int>* h = fibonacci(6);
    //reverseList(h);
    printNode(h);

    return 0;
};

// }else
//     {
//         Node<int>* prev = head;
//         Node<int>* crr = new Node<int>{1, head};
//         while (n > 1)
//         {  
//         Node<int>* temp = new Node<int>{(prev->data + crr->data),crr};
//         prev = crr;
//         crr = temp;
//         head = temp;
//         n--;
//         }
//     }
//     return head;