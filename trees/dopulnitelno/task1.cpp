#include <iostream>
#include <vector>
#include <fstream>
#include "toDottyFuncs.h"

template <class T>
void saveTree(Node<T>* root, std::vector<Node<T>*>& v)
{
    if (!root)
    {
        return;
    }
    saveTree(root->left, v);
    v.push_back(root);
    saveTree(root->right, v);
}

template <class T>
Node<T>* balanceTreeHelper(std::vector<Node<T>*>& v, int start, int end)
{
    if (start > end)
    {
        return nullptr;
    }
    int midEl = (start + end) / 2;
    Node<T>* root = v[midEl];
    root->left = balanceTreeHelper(v, start, midEl-1);
    root->right = balanceTreeHelper(v, midEl+1, end);
    return root;
}

template <class T>
void balanceTree(Node<T>*& root)
{
    std::vector<Node<T>*> v;
    saveTree(root, v);
    int end = v.size() - 1;
    root = balanceTreeHelper(v, 0, end);
}

int main() {
    std::ofstream dot("task1.dot");
    Node<int>* root = new Node<int>{1,
                        nullptr, 
                        new Node<int>{2, 
                            nullptr, 
                            new Node<int>{3,
                                nullptr, 
                                new Node<int>{4,
                                    nullptr,
                                    new Node<int>{5, nullptr, nullptr}}}}};
    //toDotty(root, dot);
    balanceTree(root);
    toDotty(root, dot);

    // printTreePostOrder(root);

    return 0;
}