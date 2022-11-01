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

TEST_CASE("test append")
{
    LinkedList<int> l1;
    LinkedList<int> l2;
    l1.push_back(0);
    l1.push_back(1);
    l1.push_back(2);
    l2.push_back(5);
    l2.push_back(6);
    l2.push_back(7);
    l1.append(l2);

    CHECK(l1.size() == 6);
    CHECK(l1[0] == 0);
    CHECK(l1[3] == 5);
    CHECK(l1[4] == 6);
    CHECK(l1[5] == 7);
}

int main()
{


    doctest::Context().run();

    return 0;
}
// g++ -static-libgcc -static-libstdc++ linked-list/listTEST.cpp 