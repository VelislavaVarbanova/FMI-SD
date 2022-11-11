#include <iostream>

class Node
    {
    public:
        int data;
        Node *next;
        Node(int data, Node* next)
        {
            this->data = data;
            this->next = next;
        }
    };

int findIntersection(Node *firstHead, Node *secondHead)
{
    Node* crr1 = firstHead;
    Node* crr2 = secondHead;
    while (crr1 != nullptr)
    {
        crr2 = secondHead;
        while (crr2 != nullptr)
        {
           if (crr1 == crr2)
            {
                return crr1->data;
            } 
            crr2 = crr2->next;
        }
        crr1 = crr1->next;
    }
    return -1;
}

int main()
{
    Node* h3 = new Node{6, 
                    new Node{7, 
                    new Node{8, 
                    new Node{9, nullptr}}}};
    Node* h1 = new Node{2, 
                    new Node{3, 
                    new Node{4, 
                    new Node{5, h3}}}};
    Node* h2 = new Node{7, 
                    new Node{3, 
                    new Node{8, 
                    new Node{5, h3}}}};
    
    std::cout << findIntersection(h1, h2);


    return 0;
}
