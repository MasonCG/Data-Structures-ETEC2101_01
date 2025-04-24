//ordered_set_tests.cpp

#include <gtest/gtest.h>
#include <sstream>
#include <ostream>
#include <linkedList.h>
#include <OrderedSet.h>


//=================================
//        Lab 6 Tests
//=================================


TEST(OrderedSetTests, Defualt_Constructor_test) {
	ssuds::OrderedSet<int> int_set;

	ASSERT_EQ(int_set.size(), 0);

}


TEST(OrderedSetTests, size_test) {
	ssuds::OrderedSet<int> int_set;
	int_set.insert(1);


	ASSERT_EQ(int_set.size(), 1);

}


/*
TEST(OrderedSetTests, Initializer_list_test) {
	ssuds::LinkedList<int> int_list = { 0, 1, 2, 3 };

	ASSERT_EQ(int_list[0], 0);
	ASSERT_EQ(int_list[1], 1);
	ASSERT_EQ(int_list[2], 2);
	ASSERT_EQ(int_list[3], 3);

}

*/