#pragma once
#include <iostream>
#include <cstdint>

template <typename T>
struct Node{
    T data;
    Node* left;
    Node* right;
};

template <typename T>
void toDotty(Node<T> *root, std::ostream &out)
{
    out << "digraph G{\n";
    printDotStatements(root,out);
    out << "}";
}

template <typename T>
void printDotStatements(Node<T> *root, std::ostream &out)
{
    if(root==nullptr)
    {
        return;
    }

    printDotStatements(root->left,out);
    printDotStatements(root->right,out);

    out << reinterpret_cast<std::uintptr_t>(root) << "[label=\"" << root->data << "\"];\n";

    if(root->right != nullptr)
    {
        out << reinterpret_cast<std::uintptr_t>(root) << "->" << reinterpret_cast<std::uintptr_t>(root->right) << "[color=\"blue\",label=\"R\"];" << std::endl;
    }
    if(root->left != nullptr)
    {
        out << reinterpret_cast<std::uintptr_t>(root) << "->" << reinterpret_cast<std::uintptr_t>(root->left) << "[color=\"red\",label=\"L\"];" << std::endl;
    }
}