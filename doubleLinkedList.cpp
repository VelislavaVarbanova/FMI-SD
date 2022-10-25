#include <iostream>
#include <stdexcept> 

#include "doubleLinkedList.h"

template <typename T>
DoubleLinkedList<T> :: DoubleLinkedList() : first(nullptr), last(nullptr) {}

template <typename T>
DoubleLinkedList<T> :: Box :: Box(const T& x) : data(x), next(nullptr) {}

template <typename T>
DoubleLinkedList<T> :: Box :: Box(const T& x, Box* next, Box* prev) 
    : data(x), next(next), prev(prev) {}

template <typename T>
void DoubleLinkedList<T> :: clear() //!
{
    LinkedList<T> :: Box* save = first;
    while (first != nullptr)
    {
        save = first;
        first = first->next;
        delete save;
    }
}

template <typename T>
DoubleLinkedList<T> :: ~DoubleLinkedList()
{
    clear();
}

template <typename T>
size_t DoubleLinkedList<T> :: size() const
{
    DoubleLinkedList<T> :: Box* crr = first;
    size_t size = 0;
    while (crr != nullptr)
    {
        size++;
        crr = crr->next;
    }
    return size;
}

template <typename T>
T& DoubleLinkedList<T> :: operator[](size_t i)
{
    DoubleLinkedList<T> :: Box* crr = first;
    for (int k = 0; k < i; k++)
    {
        if (crr == nullptr)
        {
            throw std :: out_of_range("Index out of range!");
        }
        crr = crr->next;
    }
    return crr->data;
}

template <typename T>
T DoubleLinkedList<T> :: operator[](size_t i) const
{
   DoubleLinkedList<T> :: Box* crr = first;
    for (int k = 0; k < i; k++)
    {
        if (crr == nullptr)
        {
            throw std :: out_of_range("Index out of range!");
        }
        crr = crr->next;
    }
    return crr->data; 
}

template <typename T> //!
DoubleLinkedList<T>& DoubleLinkedList<T> :: operator=(const DoubleLinkedList<T>& other) //!
{
    if (this != &other)
    {
        clear();
        copy(other.first);
    }
    return *this;
}

template <typename T>
void DoubleLinkedList<T> :: push(const T& x)
{
    DoubleLinkedList<T> :: Box* box = new Box(x, nullptr, nullptr);
    if (this->first == nullptr)
    {
        this->first = box;
        this->last = box;
    }else {
        box->next = first;
        first->prev = box;
        this->first = box;
    }
}

template <typename T>
void DoubleLinkedList<T> :: push_back(const T& x)
{
    DoubleLinkedList<T> :: Box* box = new Box(x, nullptr, nullptr);
    if (this->last == nullptr)
    {
        this->first = box;
        this->last = box;
    }else {
        box->prev = last;
        last->next = box;
        this->last = box;
    }
}

template <typename T>
void DoubleLinkedList<T> :: push_after(const T& x, Box* iterator)
{
    if (iterator == nullptr)
    {
        return;
    }
    if (iterator->next == nullptr)
    {
        push_back(x);
    }else {
    DoubleLinkedList<T> :: Box* box = new Box(x, iterator->next, iterator);
    // box->next = iterator->next;
    // box->prev = iterator;
    iterator->next->prev = box;
    iterator->next = box;
    }
}

template <typename T>
int DoubleLinkedList<T> :: removeFirst()
{
    if (this->first == nullptr)
    {
        throw std::invalid_argument("Removing element from an empty list!"); 
    }
    DoubleLinkedList<T> :: Box* crr = this->first;
    int value = crr->data;
    first->next->prev = nullptr;
    this->first = this->first->next;
    delete crr;
    return value;
}

template <typename T>
int DoubleLinkedList<T> :: removeLast()
{
    if (this->last == nullptr)
    {
        throw std::invalid_argument("Removing element from an empty list!"); 
    }
    if (ths->first == this->last)
    {
        int value = this->first->data;
        delete this->first;
        this->first = nullptr;
        this->last = nullptr;
        return value;
    }
    int value = this->last->data;
    this->last = this->last->prev;
    delete this->last->next;
    this->last->next = nullptr;
    return value;
}

template <typename T>
int DoubleLinkedList<T> :: removeAfter(Box* iterator)
{
    if (iterator == nullptr || iterator == tail)
    {
        return;
    }
    if (iterator->next == tail)
    {
        return removeLast();
    }
    
    DoubleLinkedList<T> :: Box* crr = iterator->next;
    int value = crr->data;
    crr->next->prev = iterator;
    iterator->next = crr->next;
    delete crr;
    return value;
}
