#include <iostream>

template <typename T>
struct Node
{
    T data;
    Node<T>* left;
    Node<T>* right;

    Node(T data, Node<T>* left, Node<T>* right)
    {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};

template <typename K, typename V>
class Dictionary
{
    Node<std::pair<K,V>> *root;

    Node<std::pair<K,V>>* get_node_and_parent_iterative(
                Node<std::pair<K,V>>* root_node,
                const K& key,
                Node<std::pair<K,V>> **parent_node)
    {
        Node<std::pair<K,V>>* current = root_node;

        while (current != nullptr)
        {
            if (current->data.first > key)
            {
                if (parent_node != nullptr)
                {
                    *parent_node = current;
                }
                current = current->left;
            }
            if (current->data.first < key)
            {
                if (parent_node != nullptr)
                {
                    *parent_node = current;
                }
                current = current ->right;
            }
            else if (current->data.first == key)
            {
                return current;
            }
        }
        return nullptr;
    }

    void add_helper(Node<std::pair<K,V>>*& root, std::pair<K,V> data)
    {
        if (root == nullptr)
        {
            root = new Node<std::pair<K,V>> {data, nullptr, nullptr};
        }
        if (data.first > root->data.first)
        {
            add_helper(root->right, data);
        }
        if (data.first < root->data.first)
        {
            add_helper(root->left, data);
        }
    }

    void printTreeHelper(Node<std::pair<K,V>>* root)
    {
        if (root != nullptr)
        {
            printTreeHelper(root->left);
            std:: cout << root->data.first <<" : " << root->data.second << std::endl;
            printTreeHelper(root->right);
        }
        return ;
    }

    public:

    Dictionary() : root(nullptr) {}

    void add(K key, V value)
    {
        std::pair<K,V> data (key, value);
        add_helper(root, data);
    }

    V get_value(K key);

    bool contains(K key);

    void printTree()
    {
        printTreeHelper(root);
    }

    void remove(K key)
    {
        Node<std::pair<K,V>> *parent = nullptr;
        Node<std::pair<K,V>> *toDeleteNode = get_node_and_parent_iterative(root, key, &parent);

        if (toDeleteNode->data.first == root->data.first)
        //is root
        {
            Node<std::pair<K,V>> *current = root->right;
            while ((current->data.first > toDeleteNode->data.first) && (current->left != nullptr))
            {
                current = current->left;
            }
            current->left = root->left;
            current->right = root->right;
            delete root;
            root = current;
        }
        else if ((toDeleteNode->left == nullptr && toDeleteNode->right != nullptr)
            || (toDeleteNode->left != nullptr && toDeleteNode->right == nullptr))
            //1 child
        {
            if (toDeleteNode->left == nullptr)
            {
                if (parent->left->data.first == toDeleteNode->data.first)
                {
                    parent->left = toDeleteNode->right;
                }else
                {
                    parent->right = toDeleteNode->right;
                }
            }else
            {
                if (parent->left->data.first == toDeleteNode->data.first)
                {
                    parent->left = toDeleteNode->left;
                }else
                {
                    parent->right = toDeleteNode->left;
                }
            }
            delete toDeleteNode;
        }
        else if (toDeleteNode->left == nullptr && toDeleteNode->right == nullptr)
        //is leaf
        {
            delete toDeleteNode;
        }
        else
        {
            if (parent->left->data.first == toDeleteNode->data.first)
            {
                parent->left = toDeleteNode->right;
                toDeleteNode->right->left = toDeleteNode->left;
            }else
            {
                parent->right = toDeleteNode->left;
                toDeleteNode->left->right = toDeleteNode->right;
            } 
            delete toDeleteNode;
        }
    }
};

int main()
{
    Dictionary<int, int> d;
    d.add(5,1);
    d.add(6,2);
    d.add(2,3);
    d.add(3,4);
    d.add(7,5);
    d.printTree();
    d.remove(3);
    std::cout << std::endl;
    d.printTree();

    return 0;
}