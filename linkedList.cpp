#include <iostream>
#include <stdexcept> 

#include "linkedList.h"

template <typename T>
LinkedList<T> :: LinkedList() : first(nullptr), last(nullptr) {}

template <typename T>
LinkedList<T> :: Box :: Box(const T& x) : data(x), next(nullptr) {}

template <typename T>
LinkedList<T> :: Box :: Box(const T& x, Box* next) : data(x), next(next) {}

template <typename T>
void LinkedList<T> :: clear() //!
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
LinkedList<T> :: ~LinkedList()
{
    clear();
}

template <typename T>
LinkedList<T> :: LinkedList(int x, int y)
{
    
}

template <typename T>
void LinkedList<T> :: push(const T& x)
{
    // LinkedList<T> :: Box* newBox = new LinkedList<T> :: Box;
    // newBox->data = x;
    // newBox->next = first;
    // first = &newBox;
    first = new LinkedList<T> :: Box {x, first}; //not requiring a constructor
    if (last == nullptr)
    {
        last = first;
    }
    
}

template <typename T>
int LinkedList<T> :: count(T x) const
{
    LinkedList<T> :: Box* crr = first;
    int count = 0;
    while (crr != nullptr)
    {
        if (crr->data == x)
        {
            count++;
        }
        crr = crr->next;
    }
    return count;
}

template <typename T>
size_t LinkedList<T> :: size() const
{
    LinkedList<T> :: Box* crr = first;
    size_t size = 0;
    while (crr != nullptr)
    {
        size++;
        crr = crr->next;
    }
    return size;
}

template <typename T>
T& LinkedList<T> :: operator[](size_t i)
{
    LinkedList<T> :: Box* crr = first;
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
T LinkedList<T> :: operator[](size_t i) const
{
   LinkedList<T> :: Box* crr = first;
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
LinkedList<T>& LinkedList<T> :: operator=(const LinkedList<T>& other) //!
{
    if (this != &other)
    {
        clear();
        copy(other.first);
    }
    return *this;
}

template <typename T> //!
void LinkedList<T> :: copy(const LinkedList<T> :: Box* other_first) //!
{
    //we assume the list is empty
    LinkedList<T> :: Box* last_created = nullptr;
    while (other_first != nullptr) //we can directly parse with other_first because 
    // its a copy of the pointer to the first elem 
    {
       LinkedList<T> :: Box* new_box = new LinkedList<T> :: Box {other_first->data, nullptr};
        if (last_created != nullptr)
        {
            last_created->next = new_box;
        }
        else
        {
            first = new_box;
        }
        last_created = new_box;
        other_first = other_first->next;
    }
}

template <typename T> //!
typename LinkedList<T> :: Box* LinkedList<T> ::  copy_rec(const LinkedList<T> :: Box* other_first) //!
{
    if (other_first == nullptr)
    {
        return nullptr;
    }
    LinkedList<T> :: Box* tail = copy_rec(other_first->next);
    return new LinkedList<T> :: Box {other_first->data, tail};
}

template <typename T> //!
void LinkedList<T> :: push_back(const T& x) //insert Last
{
    LinkedList<T> :: Box* box = new Box(x, next);
    if (this->last == nullptr)
    {
        this->first = box;
        this->last = box;
    }else {
        this->last->next = box;
        this->last = box;
    }
}

template <typename T>
void LinkedList<T> :: insertAfter(const T& x, Box* iterator)//!
{
    if (iterator == nullptr)
    {
        //do nothing
        return;
    }

    LinkedList<T> :: Box* box = new Box(const T& x);
    box->next = iterator->next;
    iterator->next = box;

    if (iterator->next == nullptr)
    {
        this->last = box;
    }
}

template <typename T>
int LinkedList<T> :: removeFirst()
{
    if (this->first == nullptr)
    {
        throw std::invalid_argument("Removing element from an empty list!"); 
    }
    LinkedList<T> :: Box* crr = this->first;
    int value = crr->data;
    this->first = this->first->next;
    delete crr;
    return value;
}

template <typename T>
int LinkedList<T> :: removeLast()
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
    
    LinkedList<T> :: Box* crr = this->first;
    while (crr->next != last)
    {
        crr = crr->next;
    }
    int value = crr->next->data;
    this->last = crr;
    delete crr->next;
    crr->next = nullptr;
    return value;
}

template <typename T>
int LinkedList<T> :: removeAfter(Box* iterator)
{
    if (iterator == nullptr || iterator == tail)
    {
        //do nothing
        return;
    }
    
    if (iterator->next == tail)
    {
        removeLast();
    }
    
    LinkedList<T> :: Box* crr = iterator->next;
    int value = crr->data;
    iterator->next = iterator->next->next;
    delete crr;
    return value;
}
