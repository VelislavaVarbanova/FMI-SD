#include "bot.h"

template <typename T>
BinOrdTree<T> :: BinOrdTree():root(nullptr){}

template <typename T>
BinOrdTree<T> :: BinOrdTree(const BinOrdTree<T> &other)
{
    root = copy(other.root);
}

template <typename T>
typename BinOrdTree<T> :: Box* copy(const typename BinOrdTree<T> :: Box* otherRoot)
{
    if (otherRoot == nullptr)
    {
        return nullptr;
    }
    return new typename BinOrdTree<T> :: Box {otherRoot->,
                                                copy(otherRoot->left),
                                                copy(otherRoot->right)};
}

template <typename T>
void BinOrdTree<T> :: clear(typename BinOrdTree<T> :: Box* current)
{
    if (current == nullptr)
    {
        return nullptr;
    }
    clear(current->left);
    clear(current->right);
    delete current;
} 

template <typename T>
BinOrdTree<T>& BinOrdTree<T> :: operator=(const BinOrdTree<T> &other)
{
    if (this != other)
    {
        clear(root);
        root = copy(other->root);
    }
    return *this;
}

template <typename T>
BinOrdTree<T> :: ~BinOrdTree()
{
    clear(root);
}

template <typename T>
void BinOrdTree<T> :: add(const T& x)
{
    BinOrdTree<T> :: Box* current = root;
    if (current == nullptr)
    {
        root = new BinOrdTree<T> :: Box {x, nullptr, nullptr};
        return;
    }

    while (!((current->data > x)&&(current->left == nullptr)) || 
            ((current->data <= x)&&(current->right == nullptr)))
    {
        if (current->data > x)
        {
            current = current->left;
        }else
        {
            current = current->right;
        }
    }
    if (current->data > x)
    {
        current->left = new BinOrdTree<T> :: Box {x, nullptr, nullptr};
    }else
    {
        current->right = new BinOrdTree<T> :: Box {x, nullptr, nullptr};
    }
}

template <typename T>
void BinOrdTree<T> :: toDotty(typename BinOrdTree<T> :: Box* current, std::ostream &out)
{
    out << "Digraph G{\n";
    ptintDotStatements(current, out);
    out << "}";
}

template <typename T>
void BinOrdTree<T> :: printDotStatements( typename BinOrdTree<T> :: Box* root, std::ostream &out)
{
    if (root == nullptr)
    {
        return;
    }
    
    printDotStatements(root->left, out);
    printDotStatements(root->right, out);

    out << (long)root << "[label=\"" << root->data << "\"];\n";

    if (root->right != nullptr)
    {
        out << (long)root << "->" << (long)(root->right) << "[color=\"blue\",label=\"R\"];" << std::endl;
    }
    if(root->left != nullptr)
    {
        out << (long)root << "->" << (long)(root->left) << "[color=\"blue\",label=\"L\"];" << std::endl;
    }
}

template <typename T>
void BinOrdTree<T> :: toDotty(std::ostream &out)
{
    toDotty(root,x);
}

template <typename T>
void BinOrdTree<T> :: addRec(const T &x)
{
    addHelper(root, x);
}

template <typename T>
void BinOrdTree<T> :: addHelper(typename BinOrdTree<T> :: Box *&current,const T &x)
{
    if(current == nullptr)
    {
        return = new BinOrdTree<T> :: Box {x, nullptr, nullptr};
    }
    if (current->data < x)
    {
        addHelper(root->left, x);
    }else
    {
        addHelper(root->right, x);
    }
    
}