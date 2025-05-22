#include <gtest/gtest.h>
#include "Vektorius.h"

// Test default constructor
TEST(VektoriusTest, DefaultConstructor) {
    Vektorius<int> v;
    EXPECT_EQ(v.size(), 0);
    EXPECT_EQ(v.capacity(), 0);
    EXPECT_TRUE(v.empty());
}

// Test size constructor
TEST(VektoriusTest, SizeConstructor) {
    Vektorius<int> v(5);
    EXPECT_EQ(v.size(), 5);
    for (size_t i = 0; i < 5; ++i)
        EXPECT_EQ(v[i], 0);
}

// Test size and value constructor
TEST(VektoriusTest, SizeValueConstructor) {
    Vektorius<int> v(3, 7);
    EXPECT_EQ(v.size(), 3);
    for (size_t i = 0; i < 3; ++i)
        EXPECT_EQ(v[i], 7);
}

TEST(VektoriusTest, InitializerListConstructor) {
    Vektorius<int> v{10, 20, 30, 40};
    EXPECT_EQ(v.size(), 4);
    EXPECT_EQ(v[0], 10);
    EXPECT_EQ(v[1], 20);
    EXPECT_EQ(v[2], 30);
    EXPECT_EQ(v[3], 40);
}

// Test copy constructor
TEST(VektoriusTest, CopyConstructor) {
    Vektorius<int> v1(2, 9);
    Vektorius<int> v2(v1);
    EXPECT_EQ(v2.size(), 2);
    EXPECT_EQ(v2[0], 9);
    EXPECT_EQ(v2[1], 9);
}

// Test copy assignment
TEST(VektoriusTest, CopyAssignment) {
    Vektorius<int> v1(2, 5);
    Vektorius<int> v2;
    v2 = v1;
    EXPECT_EQ(v2.size(), 2);
    EXPECT_EQ(v2[0], 5);
    EXPECT_EQ(v2[1], 5);
}

// Test move constructor
TEST(VektoriusTest, MoveConstructor) {
    Vektorius<int> v1(2, 3);
    Vektorius<int> v2(std::move(v1));
    EXPECT_EQ(v2.size(), 2);
    EXPECT_EQ(v2[0], 3);
    EXPECT_EQ(v2[1], 3);
}

// Test move assignment
TEST(VektoriusTest, MoveAssignment) {
    Vektorius<int> v1(2, 4);
    Vektorius<int> v2;
    v2 = std::move(v1);
    EXPECT_EQ(v2.size(), 2);
    EXPECT_EQ(v2[0], 4);
    EXPECT_EQ(v2[1], 4);
}

// Test push_back, pop_back, front, back
TEST(VektoriusTest, PushPopFrontBack) {
    Vektorius<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    EXPECT_EQ(v.size(), 3);
    EXPECT_EQ(v.front(), 1);
    EXPECT_EQ(v.back(), 3);
    v.pop_back();
    EXPECT_EQ(v.size(), 2);
    EXPECT_EQ(v.back(), 2);
}

// Test at() and operator[]
TEST(VektoriusTest, AtAndBracket) {
    Vektorius<int> v(2, 10);
    EXPECT_EQ(v.at(0), 10);
    EXPECT_EQ(v[1], 10);
    EXPECT_THROW(v.at(2), std::out_of_range);
}

// Test assign (count, value)
TEST(VektoriusTest, AssignCountValue) {
    Vektorius<int> v;
    v.assign(4, 8);
    EXPECT_EQ(v.size(), 4);
    for (size_t i = 0; i < 4; ++i)
        EXPECT_EQ(v[i], 8);
}

// Test assign (initializer_list)
TEST(VektoriusTest, AssignInitializerList) {
    Vektorius<int> v;
    v.assign({1, 2, 3});
    EXPECT_EQ(v.size(), 3);
    EXPECT_EQ(v[0], 1);
    EXPECT_EQ(v[1], 2);
    EXPECT_EQ(v[2], 3);
}

// Test clear, empty, shrink_to_fit, reserve, resize
TEST(VektoriusTest, ClearEmptyShrinkReserveResize) {
    Vektorius<int> v(5, 2);
    v.clear();
    EXPECT_EQ(v.size(), 0);
    EXPECT_TRUE(v.empty());
    v.reserve(10);
    EXPECT_GE(v.capacity(), 10);
    v.resize(3);
    EXPECT_EQ(v.size(), 3);
    v.shrink_to_fit();
    EXPECT_EQ(v.capacity(), v.size());
}

// Test insert (single, multiple, range)
TEST(VektoriusTest, Insert) {
    Vektorius<int> v;
    v.push_back(1);
    v.push_back(3);
    v.insert(v.begin() + 1, 2);
    EXPECT_EQ(v[1], 2);

    v.insert(v.end(), 2, 4);
    EXPECT_EQ(v[3], 4);
    EXPECT_EQ(v[4], 4);

    int arr[] = {5, 6};
    v.insert(v.end(), arr, arr + 2);
    EXPECT_EQ(v[5], 5);
    EXPECT_EQ(v[6], 6);
}

// Test erase (single, range)
TEST(VektoriusTest, Erase) {
    Vektorius<int> v = {1, 2, 3, 4, 5};
    v.erase(v.begin() + 1);
    EXPECT_EQ(v[1], 3);
    v.erase(v.begin(), v.begin() + 2);
    EXPECT_EQ(v[0], 4);
}

// Test emplace
TEST(VektoriusTest, Emplace) {
    Vektorius<std::string> v;
    v.emplace(v.begin(), "hello");
    v.emplace(v.end(), "world");
    EXPECT_EQ(v[0], "hello");
    EXPECT_EQ(v[1], "world");
}

// Test storage
TEST(VektoriusTest, Storage) {
    Vektorius<int> v = {1, 2, 3};
    int* ptr = v.storage();
    EXPECT_EQ(ptr[0], 1);
    EXPECT_EQ(ptr[1], 2);
    EXPECT_EQ(ptr[2], 3);
}

// Test iterators
TEST(VektoriusTest, Iterators) {
    Vektorius<int> v = {1, 2, 3};
    int sum = 0;
    for (auto it = v.begin(); it != v.end(); ++it)
        sum += *it;
    EXPECT_EQ(sum, 6);

    sum = 0;
    for (auto it = v.rbegin(); it != v.rend(); ++it)
        sum += *it;
    EXPECT_EQ(sum, 6);
}

// Test comparison operators
TEST(VektoriusTest, ComparisonOperators) {
    Vektorius<int> v1 = {1, 2, 3};
    Vektorius<int> v2 = {1, 2, 3};
    Vektorius<int> v3 = {1, 2, 4};
    Vektorius<int> v4 = {1, 2};

    EXPECT_TRUE(v1 == v2);
    EXPECT_FALSE(v1 != v2);
    EXPECT_TRUE(v1 < v3);
    EXPECT_TRUE(v3 > v1);
    EXPECT_TRUE(v4 < v1);
    EXPECT_TRUE(v1 > v4);
    EXPECT_TRUE(v1 <= v2);
    EXPECT_TRUE(v1 >= v2);
    EXPECT_TRUE(v1 <= v3);
    EXPECT_TRUE(v3 >= v1);
}

// Test front/back exception
TEST(VektoriusTest, FrontBackException) {
    Vektorius<int> v;
    EXPECT_THROW(v.front(), std::out_of_range);
    EXPECT_THROW(v.back(), std::out_of_range);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}