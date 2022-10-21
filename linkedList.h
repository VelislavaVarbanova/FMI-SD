

template <typename T>
class LinkedList
{
private:
    class Box
    {
        T data;
        Box* next;
        public:
        Box(const T& x);
        Box(const T& x, Box* next);
    };
    Box* first;
    Box* last;

    void copy(const LinkedList<T> :: Box* other_first);
    LinkedList<T> :: Box* copy_rec(const LinkedList<T> :: Box* other_first);
    

public:
    LinkedList();
    LinkedList(int x, int y); // създава свързан списък в интервала [x;y]
    ~LinkedList();
    void clear(); //трябва да е private, но заради тестовете е публична
    void push(const T& x); //вкарва елемент в началото на свързания списък
    int count(T x) const;
    size_t size() const;

    T& operator[](size_t i);
    T operator[](size_t i) const;
    LinkedList<T>& operator=(const LinkedList<T>& other);

    void push_back(const T& x); //insterLast 
    void insertAfter(const T& x, Box* iterator);
    int removeFirst();
    int removeLast();
    int removeAfter(Box* iterator);
};

