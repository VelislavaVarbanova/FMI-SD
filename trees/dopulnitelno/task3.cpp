#include "toDottyFuncs.h"
#include <fstream>

template <class T>
bool areEqual(Node<T>* root1, Node<T>* root2)
{
    //std::cout << "pf  ";
    if (root1 == nullptr && root2 == nullptr)
    {
        return true;
    }
    if (root1 == nullptr || root2 == nullptr)
    {
        return false;
    }
    
    return root1->data == root2->data &&
                areEqual(root1->left, root2->left) &&
                areEqual(root1->right, root2->right);
}

template <class T>
bool isSubTree(Node<T>* tree, Node<T>* subtree)
{
    if (subtree == nullptr)
    {
        return true;
    }
    if (tree == nullptr)
    {
        false;
    }

    if (areEqual(tree, subtree))
    {
        return true;
    }
    //std::cout << "f  ";
    return isSubTree(tree->left,subtree) || isSubTree(tree->right,subtree);
}

/*
template <class T>
bool identical(Node<T>* root1, Node<T>* root2) {
    if (root1 == nullptr && root2 == nullptr) {
        return true;
    }
    
    if (root1 == nullptr || root2 == nullptr) {
        return false;
    }

    return root1->data == root2->data &&
            identical(root1->left, root2->left) &&
            identical(root1->right, root2->right);
}

template <class T>
bool subtree(Node<T>* target, Node<T>* source) {
    if (source == nullptr) {
        return true;
    }

    if (target == nullptr) {
        return false;
    }

    if (identical(target, source)) {
        return true;
    }

    return subtree(target->left, source) || subtree(target->right, source);
}
*/

int main() {
    std::ofstream dot("task3.dot");
    Node<int>* root = new Node<int>{1,
                        nullptr, 
                        new Node<int>{2, 
                            nullptr, 
                            new Node<int>{3,
                                new Node<int>{7, nullptr, nullptr}, 
                                new Node<int>{4,
                                    nullptr,
                                    new Node<int>{5, nullptr, nullptr}}}}};

    Node<int>* source = new Node<int>{4, 
                            nullptr,
                            new Node<int>{5, nullptr, nullptr}};

    //std::cout << "strt  ";
    std::cout << std::boolalpha << isSubTree(root, source) << std::endl; 
    
    toDotty(root, dot);

    return 0;
}