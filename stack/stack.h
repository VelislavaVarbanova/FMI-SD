#include <cassert>
#include <stddef.h>

template <typename T>
class Stack
{
private:
    struct Box
    {
        T data;
        Box *next; 
    };
    size_t count;
    box *head;

    Box* copy(Box*);
    void clear();

public:
    Stack();
    Stack(const Stack&);
    Stack& operator= (const Stack<T>& other);
    ~Stack();

    T top();
    void pop();
    void push(const T&);
    bool empty();
    size_t size();
};
