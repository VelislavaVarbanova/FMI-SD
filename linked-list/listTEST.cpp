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

int main()
{


    doctest::Context().run();

    return 0;
}
