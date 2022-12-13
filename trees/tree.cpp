#include <iostream>
#include <fstream>
#include <cassert>

template <typename T>
struct Box
{
    T data;
    Box* left;
    Box* right;
};

template <typename T>
bool setAt(Box<T> *&root, const char* trace, const T& data)
{
    if (trace[0] == 0)
    {
        if (root == nullptr)
        {
            root = new Box*<T> {data,nullptr,nullptr}
        }else
        {
            root->data = data;
        }
        return true;
    }else
    {
        if (root == nullptr)
        {
            return false;
        }
        if (trace[0] == 'L' || trace[0] == 'l')
        {
            return setAt(root->left, trace+1, data)
        }else if (trace[0] == 'R' || trace[0] == 'r')
        {
            return setAt(root->right, trace+1, data)
        }
        return false;
    }
}

template <typename T>
void toDotty(Box<T> *root, std :: ostream &out)
{
    out << "Digraph G{\n";
    printDotStatements(root, out);
    out << "}";
}

template <typename T>
void printDoStatements(Box<T> *root, std :: ostream &out)
{
    if (root == nullptr)
    {
        return;
    }
    
    printDoStatements(root->left, out);
    printDoStatements(root->right, out);

    out << (long)root << "[label=\"" << root->data << "\"];\n";

    if (root->right != nullptr)
    {
        out << (long)root <<  "->" << (long)(root->right) << "[color=\"blue\",label=\"R\"];" << std::endl;
    }
    if(root->left != nullptr)
    {
        out << (long)root << "->" << (long)(root->left) << "[color=\"red\",label=\"L\"];" << std::endl;
    }
}

template <typename T>
bool elem(Box<T> *root, const T& x)
{
    return root != nullptr && 
            ((root->data == x) ||
            elem(root->left, x) ||
            elem(root->right, x));
}

template <typename T>
T sum(Box<T> *root, const T& x)
{
    if (root == nullptr)
    {
        return 0;
    }
    
    return (root->data == x) + 
            elem(root->left, x) +
            elem(root->right, x);
}

template <typename T>
void toScheme(Box<T> *root, std:: ostream &out)
{
    if (root == nullptr)
    {
        out << "()";
        return;
    }
    
    out << "(" << root->data << " ";
    toScheme(root->left, out);
    out << " ";
    toScheme(root->right, out);
    out << ")";
}

template <typename T>
bool equalTrees(Box<T> *t1, Box<T> *t2)
{
    return (t1 == nullptr && t2 == nullptr) ||
            (t1 != nullptr && 
            t2 != nullptr &&
            t1->data == t2->data &&
            equalTrees(t1->left, t2->left) &&
            equalTrees(t1->right, t2->right));
}

template <typename T>
Box<T>* fromScheme(std::istream &in)
{
    assert(in.get()=='(');

    if (in.peek() == ')')
    {
        in.get(); //премахваме затварящата скоба от входа
        return nullptr;
    }

    //знаем, че не е ) и приемаме, че е цифра
    //<стойност на корена> <ляво> <дясно>)

    T data; in >> data;
    // <ляво> <дясно>)
    assert(in.get()==32);

    //<ляво> <дясно>)
    box<T> *left=fromScheme<T>(in);
    
    // <дясно>)
    assert(in.get()==32);
    //<дясно>)

    box<T> *right=fromScheme<T>(in);
    //)
    assert(in.get()==')');

    return new Box<T> {data, left, right};
    
}

template <typename T>
void traverse_inorder(Box<T>* current)
{
    if (current == nullptr)
    {
        traverse_inorder(current->left);
        std::cout << current->data;
        traverse_inorder(current->right);
    }
}

template <typename T>
void traverse_preorder(Box<T>* current)
{
    if (current != nullptr)
    {
        std::cout << current->data;
        traverse_preorder(current->left);
        traverse_preorder(current->right);
    }
}

int main()
{
    Box<int> *myTree = nullptr;

    setAt(myTree, "", 7);
    setAt(myTree, "L", 30);
    setAt(myTree, "R", 5);
    setAt(myTree,"LR",12);
    setAt(myTree,"RL",50);
    setAt(myTree,"LRL",90);

    std::ofstream dot("output.dot"),
                  scm("output.scm");

    toDotty(myTree,dot);
    toScheme(myTree,scm);

    scm.close();
    std::ifstream scmIn("output.scm");

    Box<int> *created = fromScheme<int>(scmIn);

    std::ofstream dot2("output2.dot");
    toDotty(created,dot2);

    std::cout << "eq=" 
              << std::boolalpha 
              << equalTrees(myTree,created) 
              << std::endl;

    return 0;
}