#include "catch.hpp"
#include "../src/ll.h"
using namespace cs126linkedlist;

TEST_CASE("Constructor") {
    LinkedList<int> tester = LinkedList<int>();
    REQUIRE(tester.head == nullptr);
    REQUIRE(tester.tail == nullptr);
}
TEST_CASE("Constructor with vector") {
    std::vector<int> vector = {1,2,3,4,5};
    LinkedList<int> tester = LinkedList<int>(vector);
    REQUIRE(tester.head -> data == 1);
    REQUIRE(tester.tail -> data == 5);
}
TEST_CASE("Copy Constructor") {
    std::vector<int> vector = {1,2,3,4,5};
    LinkedList<int> tester = LinkedList<int>(vector);
    LinkedList<int> tester2 = tester;
    REQUIRE(tester2.front() == tester.front());
    REQUIRE(tester2.back() == tester.back());
}
TEST_CASE("Push_front") {
    std::vector<int> vector = {1,2,3,4,5};
    LinkedList<int> tester = LinkedList<int>(vector);
    tester.push_front(0);
    REQUIRE(tester.front() == 0);
}
TEST_CASE("Push_back") {
    std::vector<int> vector = {1,2,3,4,5};
    LinkedList<int> tester = LinkedList<int>(vector);
    tester.push_back(6);
    REQUIRE(tester.back() == 6);
}
TEST_CASE("front") {
    std::vector<int> vector = {1,2,3,4,5};
    LinkedList<int> tester = LinkedList<int>(vector);
    REQUIRE(tester.front() == tester.head -> data);
}
TEST_CASE("back") {
    std::vector<int> vector = {1,2,3,4,5};
    LinkedList<int> tester = LinkedList<int>(vector);
    REQUIRE(tester.back() == tester.tail -> data);
}
TEST_CASE("Pop_front") {
    std::vector<int> vector2 = {1,2,3,4,5};
    LinkedList<int> tester = LinkedList<int>(vector2);
    tester.pop_front();
    REQUIRE(tester.front() == 2);
}
TEST_CASE("Pop_back") {
    std::vector<int> vector = {1,2,3,4,5};
    LinkedList<int> tester = LinkedList<int>(vector);
    tester.pop_back();
    REQUIRE(tester.back() == 4);
}
TEST_CASE("Size") {
    std::vector<int> vector = {1,2,3,4,5};
    LinkedList<int> tester = LinkedList<int>(vector);
    REQUIRE(tester.size() == 5);
}
TEST_CASE("Empty") {
    LinkedList<int> tester = LinkedList<int>();
    REQUIRE(tester.empty());
}
TEST_CASE("Clear") {
    LinkedList<int> tester = LinkedList<int>();
    REQUIRE(tester.empty());
    REQUIRE(tester.head == nullptr);
}

TEST_CASE("print") {
    std::vector<int> vector = {1,2,3,4,5};
    LinkedList<int> tester = LinkedList<int>(vector);
    std::cout << tester;
}

TEST_CASE("RemoveOdd") {
    std::vector<int> vector = {0,1,2};
    LinkedList<int> tester = LinkedList<int>(vector);
    tester.RemoveOdd();
    std::cout << tester;
}
TEST_CASE("Move Constructor") {
    std::vector<int> vector = {1,2,3,4,5};
    LinkedList<int> tester = LinkedList<int>(vector);
    LinkedList<int> tester2 = tester;
    REQUIRE(tester2.front() == 1);
    REQUIRE(tester2.back() == 5);
    REQUIRE(tester2.front() != tester.front());
}

TEST_CASE("Destructor") {
    std::vector<int> vector = {1,2,3,4,5};
    LinkedList<int> tester = LinkedList<int>(vector);
    tester = LinkedList<int>();
    REQUIRE(tester.head == nullptr);
    REQUIRE(tester.tail == nullptr);
}