template <typename T>
class DoubleLinkedList
{
private:
    class Box
    {
        T data;
        Box* next;
        Box* prev;
    public:
        Box(const T& x);
        Box(const T& x, Box* next, Box* prev);
    };
    Box* first;
    Box* last;

    void copy(const DoubleLinkedList<T> :: Box* other_first);
    DoubleLinkedList<T> :: Box* copy_rec(const DoubleLinkedList<T> :: Box* other_first);

public:
    DoubleLinkedList();
    ~DoubleLinkedList();
    void clear();
    size_t size() const;

    T& operator[](size_t i);
    T operator[](size_t i) const;
    DoubleLinkedList<T>& operator=(const DoubleLinkedList<T>& other);

    void push(const T& x);
    void push_back(const T& x);
    void push_after(const T& x, Box* iterator);
    int removeFirst();
    int removeLast();
    int removeAfter(Box* iterator);
};