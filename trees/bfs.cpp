#include <vector>
#include <iostream>
#include <queue>
#include <fstream>
#include "./dopulnitelno/task6.cpp"
#include "./dopulnitelno/toDottyFuncs.h"

// template<typename T>
// struct Node {
//     T data;   
//     Node<T> *left; 
//     Node<T> *right;

//     Node(T data, Node<T>* left, Node<T>* right) {
//         this->data = data;
//         this->left = left;
//         this->right = right;
//     }
// };

// interface used to visit nodes
template<typename T>
class NodeVisitor {
   public:
      // pure virtual function providing interface framework.
      virtual void visit(Node<T> node) = 0;
};
  
// we want to visit all node in level order
/*
     ┌──────┐
     │ root │.        (First level)
     └──┬───┘
   ┌────┴─────┐
   │          │
┌──┴───┐  ┌───┴───┐
│   L  │  │   R   │   (Second Level)
└──────┘  └───┬───┘
         ┌────┴─────┐
         │          │
      ┌──┴───┐  ┌───┴───┐
      │  R.L │  │  R.R  │   (Thrid Level)
      └──────┘  └───┬───┘
Root -> L -> R -> R.L -> R.R 
*/
template<typename T>
void bfs(Node<T>* root /*, const NodeVisitor<T> &visitor*/) {
    // first check base case if tree is empty - no nodes -then we have visited everything
    if (root == nullptr)
    {
        return;
    }
    // Then we need to create empty queue to keep visited nodes with a name "queue"
    std::queue<Node<T>*> queue;
    // then we put the root (we will visit the root as it's the 0 level)
    queue.push(root);
    while ( !queue.empty() ) {
        // visit the first node 
        Node<T>* node = queue.front(); 
        //visitor.visit(node);
        std::cout << node->data << " ";
        queue.pop();

        // then we add to the queue the current visited node children
        if (node->left != nullptr)
        {
            queue.push(node->left);
        }
        if (node->right != nullptr)
        {
            queue.push(node->right);
        }
    }
}

template <typename T>
Node<T>* minDataNode(Node<T>* node)
{
    Node<T>* current = node;
    while (current && current->left != nullptr)
    {
        current = current->left;
    }
    return current;
}

template <typename T>
Node<T>* deleteKey(Node<T>* root, const T& key)
{
    if (root == nullptr)
    {
        return root;
    }
    if (key < root->data)
    {
        root->left = deleteKey(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = deleteKey(root->right, key);
    }
    else 
    {
        if (root->left == nullptr && root->right == nullptr) //is leaf
        {
            return nullptr;
        }
        else if (root->right == nullptr) // 1 child
        {
            Node<T>* temp = root->left;
            delete root;
            return temp;
        }
        else if (root->left == nullptr)// 1 child
        {
            Node<T>* temp = root->right;
            delete root;
            return temp;
        }
        else
        {
            Node<T>* temp = minDataNode(root->right);
            root->data = temp->data;
            root->right = deleteKey(root->right, temp->data);
        }
    }
    return root;
}


template <class T>
std::vector<T> averageOfLevels(Node<T>* root) 
{
    std:: vector<double> result;
    //if(root == nullptr)
    //{
    //   return nullptr;
    //}
    std::queue<Node<T>*> q;
    q.push(root);
    while(!q.empty())
    {
        double level_sum = 0;
        int level_count = 0;
        for (int i = 0; i < q.size(); i++)
        {
            Node<T>* current = q.front();
            q.pop();
            level_sum = current->data;
            level_count++;
            if (current->left)
            {
                q.push(current->left);
            }
            if (current->right)
            {
                q.push(current->right);
            }
        }
        result.push_back(level_sum / level_count);
    }
    return result;
}

int main()
{
    std::ofstream dot("bfs.dot");
    Node<int>* root = new Node<int>{10,
                         nullptr, 
                         new Node<int>{2, 
                             nullptr, 
                             new Node<int>{3,
                                 new Node<int>{17, nullptr, nullptr}, 
                                 new Node<int>{14,
                                     nullptr,
                                     new Node<int>{-5, nullptr, nullptr}}}}};

    //bfs(root);
    //toDotty(root, dot);

    convertToBST(root);
    deleteKey(root, 2);
    toDotty(root, dot);

    return 0;
}