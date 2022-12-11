template <typename T>
struct Node
{
    T data;
    Node<T>* left;
    Node<T>* right;
};

template <typename K, typename V>
class Dictionary
{
    Node<std::pair<K,V>> *root;

    Node<K,V>* add_helper(Node* root, std::pair<K,V> data)
    {
        if (root == nullptr)
        {
            return new Node<std::pair<K,V>> {data, nullptr, nullptr};
        }
        if (data.key > root.key)
        {
            
        }
        if (/* condition */)
        {
            /* code */
        }
        return root;
    }

    public:

    void add(K key, V value)
    {
        std::pair<K,V> data (key, value);
        this->root = add_helper(root, data);
    }

    V get_value(K key);

    bool contains(K key);

    void remove(K key)
    {
        Node<std::pair<K,V>> *parent;
        Node<std::pair<K,V>> *toDeleteNode = find(key, &parent);

        if (toDeleteNode->data.first == root->data.first)
        //is root
        {
            Node<std::pair<K,V> *current = root->right;
            while ((current->data.first > toDeleteNode->data.first) && (current->left != nullprt))
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
                if (parent->left.first == toDeleteNode.first)
                {
                    parent->left = toDeleteNode->right;
                }else
                {
                    perent->right = toDeleteNode->right;
                }
            }else
            {
                if (parent->left->data.first == toDeleteNode->data.first)
                {
                    parent->left = toDeleteNode->left;
                }else
                {
                    perent->right = toDeleteNode->left;
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
            if (perent->left->data.first == toDeleteNode->data.first)
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
