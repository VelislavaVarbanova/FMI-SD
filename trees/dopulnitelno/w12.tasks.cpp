#include "toDottyFuncs.h"
#include <fstream>
#include <queue>
#include <vector>

template <class T>
void printLeftView(Node<T>* root, int level, std::vector<T>& v) 
{
    if (root == nullptr) 
    {
        return;
    }

    if (v.size() <= level) 
    {
        v.push_back(root->data);
    }

    printLeftView(root->right, level + 1, v);
    printLeftView(root->left, level + 1, v);
}
template <class T>
void printVector(const std::vector<T>& v) 
{
    for (T element : v) 
    {
        std::cout << element << " ";
    }
}

template <class T>
void printLeftView2(Node<T>* root) 
{
    std::queue<Node<T>*> q;
    q.push(root);
    q.push(nullptr);
    std::cout << root->data << " ";

    while(!q.empty()) 
    {
        Node<T>* temp = q.front();
        q.pop();

        if (temp == nullptr) 
        {
            if (q.empty()) 
            {
                break;
            }
            q.push(nullptr);
            std::cout << q.front()->data << " "; 
        } else 
        {
            if (temp->left != nullptr) 
            {
                q.push(temp->left);
            }

            if (temp->right != nullptr) 
            {
                q.push(temp->right);
            }
        }
    }
}

template <class T>
bool isTreeSymmetricHelper(Node<T>* left, Node<T>* right) 
{
    if (left == nullptr && right == nullptr) 
    {
        return true;
    }

    return (left != nullptr && right != nullptr) 
            && isTreeSymmetricHelper(left->left, right->right)
            && isTreeSymmetricHelper(left->right, right->left);
}

template <class T>
bool isTreeSymmetric(Node<T>* root) 
{
    if (root == nullptr) 
    {
        return true;
    }

    return isTreeSymmetricHelper(Root->left, root->right);
}

int main() {
    Node<int>* root = new Node<int>{1,
                        new Node<int>{2, nullptr, nullptr},
                        new Node<int>{3, 
                            new Node<int>{5,
                                new Node<int>{7, nullptr, nullptr},
                                new Node<int>{8, 
                                    nullptr,
                                    new Node<int>{10, nullptr, nullptr}}},
                            new Node<int>{6, nullptr, nullptr}}};

    Node<int>* root2 = new Node<int>{15, 
                            new Node<int>{10,
                                new Node<int>{10, nullptr, nullptr},
                                new Node<int>{10, nullptr, nullptr}},
                            new Node<int>{25, 
                                new Node<int>{25, nullptr, nullptr},
                                new Node<int>{25, nullptr, nullptr}}};

    std::ofstream dot("tree.dot");
    
    toDotty(root, dot);
    //printLeftView2(root);
    std::vector<int> v;
    printLeftView(root, 0, v);
    printVector(v);

    // subtree(root2, new Node<int>{26, nullptr, nullptr});

    // int array[] = {15, 10, 8, 12, 20, 16, 25};
    // std::vector<int> v;
    // v.push_back(15);
    // v.push_back(10);
    // v.push_back(8);
    // v.push_back(12);
    // v.push_back(20);
    // v.push_back(16);
    // v.push_back(25);
    // int index = 0;

    // std::cout << comparePreOrder(root2, v, index) << std::endl;

 //     Node<int>* root3;
 //     arrayToTree(root3, v);
    //toDotty(root, dot);

    //index = 0;
    // std::cout << "\n" << smallestSum(root2, 4, index) << std::endl;
    // smallestSum(root2, 3, index);

    //std::cout << findUniversalTreeHelper(root2) << std::endl;
 
    //5 7 8 10

    return 0;
}