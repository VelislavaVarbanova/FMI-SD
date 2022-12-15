#include <iostream>

template <typename T>
struct Node {
    int data;
    Node* next;
};

Node<int>*& abs_sort(Node<int>*& head, Node<int>* end)
{
    if (head != end)
    {
        Node<int>* crr = head;
        while (crr->next != end)
        {
            if (abs(crr->next->data) < abs(crr->data))
            {
                int a = crr->data;
                crr->data = crr->next->data;
                crr->next->data = a;
            }
            crr = crr->next;
        }
        end = crr;
        return abs_sort(head, end);
    }
    return head;
}

void sort_after_abs(Node<int>*& head)
{
    Node<int>* crr = head;
    while (crr->next != nullptr)
    {
        if (crr->next->data < 0)
        {
            Node<int>* temp = crr->next;
            crr->next = temp->next;
            temp->next = head;
            head = temp;
        }else
        {
            crr = crr->next;
        }
    }
}

void printNode(Node<int>* head)
{
    while (head != nullptr)
    {
        std::cout << head->data << std::endl;
        head = head->next;
    }
}

int main()
{
    Node<int>* h3 = new Node<int>{-2, nullptr};
    Node<int>* h2 = new Node<int>{-7, h3};
    Node<int>* h1 = new Node<int>{1, h2};
    Node<int>* h0 = new Node<int>{3, h1};
    abs_sort(h0, nullptr);
    printNode(h0);
    std::cout << std::endl;
    sort_after_abs(h0);
    printNode(h0);
    delete h3;
    delete h2;
    delete h1; 
    delete h0;

    return 0;
}