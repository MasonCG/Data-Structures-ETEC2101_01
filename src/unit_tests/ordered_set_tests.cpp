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


TEST(OrderedSetTests, insert_and_size_test) {
	ssuds::OrderedSet<int> int_set;
	
	ASSERT_TRUE(int_set.insert(1));
	ASSERT_EQ(int_set.size(), 1);
	
	ASSERT_TRUE(int_set.insert(2));
	ASSERT_EQ(int_set.size(), 2);
}


TEST(OrderedSetTests, contains_test) {
	ssuds::OrderedSet<int> int_set;
	int_set.insert(0);
	int_set.insert(1);
	int_set.insert(2);
	int_set.insert(3);

	ASSERT_TRUE(int_set.contains(0));
	ASSERT_TRUE(int_set.contains(3));
}



TEST(OrderedSetTests, clear_test) {
	ssuds::OrderedSet<int> int_set;

	for (int i = 0; i < 10; i++) {
		bool inserted = int_set.insert(i);
	}
	
	int_set.clear();

	ASSERT_EQ(int_set.size(), 0);

	for (int i = 0; i < 10; i++) {
		ASSERT_FALSE(int_set.contains(i));
	}


}

TEST(OrderedSetTests, getHeight_test) {
	ssuds::OrderedSet<int> int_set;

	// testing adds all numbers to the right of root 0
	for (int i = 0; i < 10; i++) {
		bool inserted = int_set.insert(i);
	}

	ASSERT_EQ(int_set.get_height(), 10);
	
	int_set.clear();

	
	// better example of a tree with the root at 5 instead of 0
	int_set.insert(5);
	for (int i = 0; i < 10; i++) {
		bool inserted = int_set.insert(i);
	}
	
	ASSERT_EQ(int_set.get_height(), 6);


}

TEST(OrderedSetTests, getParent_test) {
	ssuds::OrderedSet<int> int_set;


	int_set.insert(5);
	for (int i = 0; i < 10; i++) {
		bool inserted = int_set.insert(i);
	}

	ASSERT_FALSE(int_set.get_parent(5).has_value());
	ASSERT_EQ(int_set.get_parent(3).value(), 2);
	ASSERT_EQ(int_set.get_parent(9).value(), 8);




}


TEST(OrderedSetTests, Initializer_list_test) {
	ssuds::OrderedSet<int> int_set = { 0, 1, 2, 3 };

	ASSERT_TRUE(int_set.contains(0));
	ASSERT_TRUE(int_set.contains(1));
	ASSERT_TRUE(int_set.contains(2));
	ASSERT_TRUE(int_set.contains(3));




}

TEST(OrderedSetTests,Traversal_test) {
	ssuds::OrderedSet<int> int_set = { 0, 1, 2, 3 };


	ssuds::ArrayList<int> int_list;
	int_list = int_set.traversal();

	ASSERT_EQ(int_list.size(), 4);

}

TEST(OrderedSetTests, stream_test) {
	ssuds::OrderedSet<int> int_set;
	int_set.insert(5);
	for (int i = 0; i < 10; i++) {
		bool inserted = int_set.insert(i);
	}

	std::ostringstream oss;
	oss << int_set;

	ASSERT_EQ(oss.str(), "[0, 1, 2, 3, 4, 5, 6, 7, 8, 9]");

}


TEST(OrderedSetTests,rebalance_test) {
	ssuds::OrderedSet<int> int_set;
	for (int i = 0; i < 10; i++) {
		bool inserted = int_set.insert(i);
	}

	ASSERT_EQ(int_set.get_height(), 10);
	int_set.rebalance();
	ASSERT_EQ(int_set.get_height(), 6);


}


TEST(OrderedSetTests, treeString_test) {
	ssuds::OrderedSet<int> int_set;
	int_set.insert(50);
	int_set.insert(25);
	int_set.insert(75);
	int_set.insert(12);
	int_set.insert(22);
	int_set.insert(4);
	int_set.insert(18);
	int_set.insert(23);
	int_set.insert(80);
	int_set.insert(65);
	int_set.insert(71);
	int_set.insert(83);
	int_set.insert(76);


	std::cout << int_set.tree_string();

}

/*
TEST(OrderedSetTests, erase_test) {
	ssuds::OrderedSet<int> int_set;
	int_set.insert(50);
	int_set.insert(25);
	int_set.insert(75);
	int_set.insert(12);
	int_set.insert(22);
	int_set.insert(4);
	int_set.insert(18);
	int_set.insert(23);
	int_set.insert(80);
	int_set.insert(65);
	int_set.insert(71);
	int_set.insert(83);
	int_set.insert(76);


	ASSERT_TRUE(int_set.erase(4));
	std::cout << int_set;
}

*/




