template <typename T>
struct Node
{
    T data;
    Node<T> *left;
    Node<T> *right;
};