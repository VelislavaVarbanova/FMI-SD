#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
#include "linkedList.cpp"

TEST_CASE("test push")
{
    LinkedList<int> l;
    l.push(0);
    l.push(1);
    l.push(2);

    CHECK(l.size() == 3);
    CHECK(l[0] == 2);
    CHECK(l[1] == 1);
    CHECK(l[2] == 0);
}

TEST_CASE("test push_back")
{
    LinkedList<int> l;
    l.push_back(0);
    l.push_back(1);
    l.push_back(2);

    CHECK(l.size() == 3);
    CHECK(l[2] == 2);
    CHECK(l[1] == 1);
    CHECK(l[0] == 0);
}

TEST_CASE("Clear test")
{
    LinkedList<int> l;
    l.push(5);
    l.push(3);
    l.push(2);

    l.clear();
    CHECK(l.size() == 0);
    l.clear();
    l.push(0);
    CHECK(l.size() == 1);
}

TEST_CASE("Count test")
{
    LinkedList<int> l;
    l.push(5);
    l.push(3);
    l.push(2);
    l.push(5);
    l.push(1);

    CHECK(l.count(5) == 2);
    l.clear();
    CHECK(l.count(5) == 0);
}

// TEST_CASE("Interval constructor test")
// {
//     LinkedList<int> l(1,5);
//     CHECK(l[0] == 1);
//     CHECK(l[4] == 5);
//     CHECK(l.size() == 5);

//     LinkedList<int> l2(5,1);
//     CHECK(l2.size() == 0);
// }

// TEST_CASE("insertAfter test")
// {
//     LinkedList<int> l;
//     LinkedList<int> :: Box* iterator = new LinkedList<int> :: Box(1);
//     l.push(1);
//     l.insertAfter(2,)
// }

TEST_CASE("test removeLast")
{
    LinkedList<int> l;
    l.push(5);
    l.push(3);
    l.push(2);
    CHECK(l.size() == 3);
    l.removeLast();
    CHECK(l.size() == 2);
    CHECK(l.getLast()->data == 3);
}

TEST_CASE("test removeFirst")
{
     LinkedList<int> l;
    l.push(5);
    l.push(3);
    l.push(2);
    CHECK(l.size() == 3);
    l.removeFirst();
    CHECK(l.size() == 2);
    CHECK(l.getFirst()->data == 3);
}

// test  void insertAfter(x, Box* iterator) ; int removeAfter(Box* iterator);


// TEST_CASE("test append")
// {
//     LinkedList<int> l1;
//     LinkedList<int> l2;
//     l1.push_back(0);
//     l1.push_back(1);
//     l1.push_back(2);
//     l2.push_back(5);
//     l2.push_back(6);
//     l2.push_back(7);
//     l1.append(l2);

//     CHECK(l1.size() == 6);
//     CHECK(l1[0] == 0);
//     CHECK(l1[3] == 5);
//     CHECK(l1[4] == 6);
//     CHECK(l1[5] == 7);
// }

int main()
{
    LinkedList<int> l;
    l.push_back(0);
    l.push_back(1);
    l.push_back(2);
    for (int i = 0; i < l.size(); i++)
    {
        std::cout << i << ": " << l[i] << std::endl;
    }
    //l.print();

    doctest::Context().run();

    return 0;
}
// g++ -static-libgcc -static-libstdc++ linked-list/listTEST.cpp 