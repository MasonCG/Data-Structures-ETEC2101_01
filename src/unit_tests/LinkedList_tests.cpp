//array_list_tests.cpp

#include <gtest/gtest.h>
#include <sstream>
#include <ostream>
#include <linkedList.h>


//=================================
//        Lab 6 Tests
//=================================


TEST(LinkedListTests, Defualt_Constructor_test) {
	ssuds::LinkedList<int> int_list;

	ASSERT_EQ(int_list.size(), 0);
}

TEST(LinkedListTests, Initializer_list_test) {
	ssuds::LinkedList<int> int_list = {0, 1, 2, 3};

	ASSERT_EQ(int_list[0], 0);
	ASSERT_EQ(int_list[1], 1);
	ASSERT_EQ(int_list[2], 2);
	ASSERT_EQ(int_list[3], 3);

}


TEST(LinkedListTests, Copy_Constructor_test) {
	ssuds::LinkedList<int> int_list = { 0, 1, 2, 3 };
	ssuds::LinkedList<int> int_list2 = int_list;
	ssuds::LinkedList<int> int_list3(int_list2);

	ASSERT_EQ(int_list2[0], 0);
	ASSERT_EQ(int_list2[1], 1);
	ASSERT_EQ(int_list3[2], 2);
	ASSERT_EQ(int_list3[3], 3);

}

TEST(LinkedListTests, Bracket_Operator_test) {
	ssuds::LinkedList<int> int_list = { 0, 1, 2, 3 };

	ASSERT_EQ(int_list[0], 0);
	ASSERT_EQ(int_list[1], 1);
	ASSERT_EQ(int_list[2], 2);
	ASSERT_EQ(int_list[3], 3);

}


TEST(LinkedListTests, Assignment_operator_test) {
	ssuds::LinkedList<int> int_list = { 0, 1, 2, 3 };
	ssuds::LinkedList<int> int_list2;
	int_list2 = int_list;

	ASSERT_EQ(int_list2[0], 0);
	ASSERT_EQ(int_list2[1], 1);
	ASSERT_EQ(int_list2[2], 2);
	ASSERT_EQ(int_list2[3], 3);

}

TEST(LinkedListTests, Append_test) {
	ssuds::LinkedList<int> int_list;

	for (int i = 0; i < 4; i++) {
		int_list.append(i);
	}

	ASSERT_EQ(int_list[0], 0);
	ASSERT_EQ(int_list[1], 1);
	ASSERT_EQ(int_list[2], 2);
	ASSERT_EQ(int_list[3], 3);

}

TEST(LinkedListTests, Prepend_test) {
	ssuds::LinkedList<int> int_list;

	for (int i = 0; i < 4; i++) {
		int_list.prepend(i);
	}

	ASSERT_EQ(int_list[0], 3);
	ASSERT_EQ(int_list[1], 2);
	ASSERT_EQ(int_list[2], 1);
	ASSERT_EQ(int_list[3], 0);

}

TEST(LinkedListTests, Output_test) {
	ssuds::LinkedList<int> int_list = { 0, 1, 2, 3 };

	std::ostringstream oss;
	int_list.output(oss);


	ASSERT_EQ(oss.str(), "[0, 1, 2, 3]");

}

TEST(LinkedListTests, Size_test) {
	ssuds::LinkedList<int> int_list = { 0, 1, 2, 3 };

	ASSERT_EQ(int_list.size(), 4);

}

TEST(LinkedListTests, insert_test) {
	ssuds::LinkedList<int> int_list = {0};
	int_list.insert(1, 0);
	int_list.insert(5, 2);
	int_list.insert(2, 2);


	ASSERT_EQ(int_list[0], 1);
	ASSERT_EQ(int_list[1], 0);
	ASSERT_EQ(int_list[3], 5);
	ASSERT_EQ(int_list[2], 2);

}

TEST(LinkedListTests, remove_index_test) {
	ssuds::LinkedList<int> int_list = { 0, 1, 2, 3, 4};

	int_list.remove(0);

	ASSERT_EQ(int_list[0], 1);
	ASSERT_EQ(int_list.size(), 4);

	int_list.remove(int_list.size() - 1);

	ASSERT_EQ(int_list[int_list.size()-1], 3);
	ASSERT_EQ(int_list.size(), 3);

	int_list.remove(1);
	ASSERT_EQ(int_list[0], 1);
	ASSERT_EQ(int_list[int_list.size() - 1], 3);
	ASSERT_EQ(int_list.size(), 2);

}

TEST(LinkedListTests, remove_iterator_test) {
	ssuds::LinkedList<int> int_list = { 0, 1, 2, 3, 4 };
	ssuds::LinkedList<int>::LinkedListIterator it = int_list.begin();

	int_list.remove(it);

	ASSERT_EQ(int_list[0], 1);
	ASSERT_EQ(int_list.size(), 4);


	it + (int_list.size() - 1);
	int_list.remove(it);

	ASSERT_EQ(int_list[int_list.size() - 1], 3);
	ASSERT_EQ(int_list.size(), 3);

	it = ++int_list.begin();

	int_list.remove(it);
	ASSERT_EQ(int_list[0], 1);
	ASSERT_EQ(int_list[int_list.size() - 1], 3);
	ASSERT_EQ(int_list.size(), 2);

}



TEST(LinkedListTests, removeAll_test) {
	ssuds::LinkedList<int> int_list = {0, 2, 2, 5, 2, 2, 6, 7, 8, 2, 2};

	ASSERT_EQ(int_list.size(), 11);

	ASSERT_EQ(int_list.remove_all(2), 6);
	
	ASSERT_EQ(int_list.size(), 5);



}

TEST(LinkedListTests, At_test) {
	ssuds::LinkedList<int> int_list = { 0, 1, 2, 3, 4};

	ASSERT_EQ(int_list.at(2), int_list[2]);



}














//===============================
//=      LinkedListIterator     =
//===============================

TEST(LinkedListIteratorTests, dereference_operator_test) {
	ssuds::LinkedList<int> int_list = { 0, 1, 2, 3 };
	ssuds::LinkedList<int>::LinkedListIterator it = int_list.begin();

	ASSERT_EQ(*it, 0);
}

TEST(LinkedListIteratorTests, PlusPlus_right_test) {
	ssuds::LinkedList<int> int_list = { 0, 1, 2, 3 };
	ssuds::LinkedList<int>::LinkedListIterator it = int_list.begin();
	
	ASSERT_EQ(*it, 0);
	ASSERT_EQ(*(it++), 0);
	it++;
	ASSERT_EQ(*it, 2);
}

TEST(LinkedListIteratorTests, MinusMinus_left_test) {
	ssuds::LinkedList<int> int_list = { 0, 1, 2, 3 };
	int end = int_list.size()-1;
	ssuds::LinkedList<int>::LinkedListIterator it = int_list.begin()+end;

	ASSERT_EQ(*it, 3);
	ASSERT_EQ(*(--it), 2);
	--it;
	ASSERT_EQ(*it, 1);
}

TEST(LinkedListIteratorTests, MinusMinus_right_test) {
	ssuds::LinkedList<int> int_list = { 0, 1, 2, 3 };
	int end = int_list.size() - 1;
	ssuds::LinkedList<int>::LinkedListIterator it = int_list.begin() + end;

	ASSERT_EQ(*it, 3);
	ASSERT_EQ(*(it--), 3);
	it--;
	ASSERT_EQ(*it, 1);
}

TEST(LinkedListIteratorTests, PlusPlus_left_test) {
	ssuds::LinkedList<int> int_list = { 0, 1, 2, 3 };
	ssuds::LinkedList<int>::LinkedListIterator it = int_list.begin();

	ASSERT_EQ(*it, 0);
	ASSERT_EQ(*(++it), 1);
	++it;
	ASSERT_EQ(*it, 2);
}

TEST(LinkedListIteratorTests, Minus_Operator_test) {
	ssuds::LinkedList<int> int_list = { 0, 1, 2, 3 };
	ssuds::LinkedList<int>::LinkedListIterator it = int_list.begin()+(int_list.size()-1);

	ASSERT_EQ(*it, 3);
	it - 2;
	ASSERT_EQ(*it, 1);
	it - 10;
	ASSERT_EQ(*it, 0);


}


TEST(LinkedListIteratorTests, Plus_Operator_test) {
	ssuds::LinkedList<int> int_list = { 0, 1, 2, 3 };
	ssuds::LinkedList<int>::LinkedListIterator it = int_list.begin();

	ASSERT_EQ(*it, 0);
	it + 2;
	ASSERT_EQ(*it, 2);
	it + 3;
	ASSERT_EQ(*it, 3);

}

TEST(LinkedListIteratorTests, notEqual_operator_test) {
	ssuds::LinkedList<int> int_list = { 0, 1, 2, 3 };
	ssuds::LinkedList<int>::LinkedListIterator it = int_list.begin();
	
	ASSERT_FALSE(it != int_list.begin());
	ASSERT_TRUE(it != int_list.end());
}

TEST(LinkedListIteratorTests, Equal_operator_test) {
	ssuds::LinkedList<int> int_list = { 0, 1, 2, 3 };
	ssuds::LinkedList<int>::LinkedListIterator it = int_list.begin();

	ASSERT_TRUE(it == int_list.begin());
	ASSERT_FALSE(it == int_list.end());
}

TEST(LinkedListIteratorTests, forEachLoop_test) {
	ssuds::LinkedList<int> int_list = { 0, 1, 2, 3 };
	int index = 0;
	for (int val : int_list) {
		ASSERT_EQ(val, int_list[index]);
		index++;
	}
}

int main(int argc, char** argv) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}