//array_list_tests.cpp

#include <gtest/gtest.h>
#include <sstream>
#include <ostream>
#include <arrayLists.h>


//=================================
//        Lab 2 Tests
//=================================


TEST(ArrayListTests, Defualt_Constructor_test) {
	ssuds::ArrayList<int> int_list;

	EXPECT_EQ(int_list.size(), 0);
	EXPECT_EQ(int_list.capacity(), 0);

}


TEST(ArrayListTests, Copy_Constructor_test) {
	ssuds::ArrayList<int> int_list;
	for (int i = 0; i < 100; i++) {
		int_list.append(i);
	}

	ssuds::ArrayList<int> int_list2(int_list);
	
	for (int i = 0; i < int_list.size(); i++) {
		ASSERT_EQ(int_list[i], int_list2[i]);
	}


}

TEST(ArrayListTests, SquareBracket_operator_test) {
	ssuds::ArrayList<int> int_list;
	int_list.append(1);
	int_list.append(2);
	int_list.append(3);
	int_list.append(4);

	EXPECT_EQ(int_list[0], 1);
	EXPECT_EQ(int_list[1], 2);
	EXPECT_EQ(int_list[2], 3);
	ASSERT_EQ(int_list[3], 4);
}

TEST(ArrayListTests, Size_test) {
	ssuds::ArrayList<int> int_list;
	int_list.append(1);
	int_list.append(2);
	int_list.append(3);
	int_list.append(4);

	ASSERT_EQ(int_list.size(), 4);
}

TEST(ArrayListTests, Capacity_Grow_test) {
	ssuds::ArrayList<int> int_list;
	

	for (int i = 0; i < 10; i++) {
		int_list.append(i);
	}

	EXPECT_EQ(int_list.capacity(), 10);
	int_list.append(10);
	EXPECT_EQ(int_list.capacity(), 20);

}

TEST(ArrayListTests, Capacity_Shrink_test) {
	ssuds::ArrayList<int> int_list;


	for (int i = 0; i < 9; i++) {
		int_list.append(i);
	}

	int_list.append(5);
	EXPECT_EQ(int_list.capacity(), 10);
	
	for (int i = 0; i < 10; i++) {
		int_list.remove(0);
	}
	
	EXPECT_EQ(int_list.capacity(), 5);

}



TEST(ArrayListTests, Append_test) {
	ssuds::ArrayList<int> int_list;
	int_list.append(1);
	int_list.append(2);
	int_list.append(3);
	int_list.append(4);
	EXPECT_EQ(int_list[0], 1);
	EXPECT_EQ(int_list[1], 2);
	EXPECT_EQ(int_list[2], 3);
	ASSERT_EQ(int_list[3], 4);

}

TEST(ArrayListTests, remove_outOfRangeException_test) {
	ssuds::ArrayList<int> int_list;
	int_list.append(1);
	int_list.append(2);
	int_list.append(3);
	int_list.append(4);


	// test if index is out of range short

	unsigned int ui = -5;

	try {
		int_list.remove(ui);
		FAIL() << "Expected std::out_of_range";
	}
	catch (std::out_of_range const& err) {
		ASSERT_EQ(err.what(), std::string("Invalid index: " + std::to_string(ui)));
	}
	catch (...) {
		FAIL() << "Expected std::out_of_range";
	}

	// test index our of range long
	try {
		int_list.remove(25);
		FAIL() << "Expected std::out_of_range";
	}
	catch (std::out_of_range const& err) {
		ASSERT_EQ(err.what(), std::string("Invalid index: " + std::to_string(25)));
	}
	catch (...) {
		FAIL() << "Expected std::out_of_range";
	}
}

TEST(ArrayListTests, remove_test) {
	ssuds::ArrayList<int> int_list;
	int_list.append(1);
	int_list.append(2);
	int_list.append(3);
	int_list.append(4);

	int_list.remove(2);
	int_list.reserve(16);
	int_list.remove(2);

	EXPECT_EQ(int_list[0], 1);
	EXPECT_EQ(int_list[1], 2);
	EXPECT_EQ(int_list.size(), 2);
}

TEST(ArrayListTests, removeAll_small_test) {
	ssuds::ArrayList<int> int_list;
	int_list.append(1);
	int_list.append(2);
	int_list.append(3);
	int_list.append(2);

	int removed = int_list.remove_all(2);

	EXPECT_EQ(removed, 2);
	EXPECT_EQ(int_list[1], 3);
	EXPECT_EQ(int_list.size(), 2);
}

TEST(ArrayListTests, removeAll_large_test) {
	ssuds::ArrayList<int> int_list;
	for (int i = 0; i < 1000; i++) {
		int_list.append(1);
		int_list.append(2);
		int_list.append(3);
	}

	int removed = int_list.remove_all(1);

	EXPECT_EQ(removed, 1000);
	EXPECT_EQ(int_list[0], 2);
	EXPECT_EQ(int_list.size(), 2000);
}

TEST(ArrayListTests, clear_small_test) {
	ssuds::ArrayList<int> int_list;
	int_list.append(1);
	int_list.append(2);
	int_list.append(3);
	int_list.append(2);

	int_list.clear();

	EXPECT_EQ(int_list.size(), 0);
	EXPECT_EQ(int_list.capacity(), 0);
}

TEST(ArrayListTests, clear_large_test) {
	ssuds::ArrayList<int> int_list;
	for (int i = 0; i < 1000; i++) {
		int_list.append(1);
		int_list.append(2);
		int_list.append(3);
	}

	int_list.clear();

	EXPECT_EQ(int_list.size(), 0);
	EXPECT_EQ(int_list.capacity(), 0);
}

TEST(ArrayListTests,prepend_test) {
	ssuds::ArrayList<int> int_list;
	int_list.prepend(1);
	int_list.prepend(2);
	int_list.prepend(3);
	int_list.prepend(4);

	EXPECT_EQ(int_list[0], 4);
	EXPECT_EQ(int_list[1], 3);
	EXPECT_EQ(int_list[2], 2);
	EXPECT_EQ(int_list[3], 1);
}



TEST(ArrayListTests, At_outOfRangeException_test) {
	ssuds::ArrayList<int> int_list;
	int_list.append(1);
	int_list.append(2);
	int_list.append(3);
	int_list.append(4);


	// test if index is out of range short
	unsigned int ui = -5;

	try {
		int_list.at(ui);
		FAIL() << "Expected std::out_of_range";
	}
	catch (std::out_of_range const& err) {
		ASSERT_EQ(err.what(), std::string("Invalid index (" + std::to_string(ui) + ")"));
	}
	catch (...) {
		FAIL() << "Expected std::out_of_range";
	}

	// test index our of range long
	try {
		int_list.at(25);
		FAIL() << "Expected std::out_of_range";
	}
	catch (std::out_of_range const& err) {
		ASSERT_EQ(err.what(), std::string("Invalid index (" + std::to_string(25) + ")"));
	}
	catch (...) {
		FAIL() << "Expected std::out_of_range";
	}
}

TEST(ArrayListTests, At_test) {
	ssuds::ArrayList<int> int_list;
	int_list.prepend(1);
	int_list.prepend(2);
	int_list.prepend(3);
	int_list.prepend(4);

	EXPECT_EQ(int_list.at(0), 4);
	EXPECT_EQ(int_list.at(1), 3);
	EXPECT_EQ(int_list.at(2), 2);
	EXPECT_EQ(int_list.at(3), 1);
}

TEST(ArrayListTests, Reserve_test) {
	ssuds::ArrayList<int> int_list;
	int_list.prepend(1);
	int_list.prepend(2);
	int_list.prepend(3);
	int_list.prepend(4);

	EXPECT_EQ(int_list.capacity(), 5);

	int_list.reserve(256);
	
	EXPECT_EQ(int_list.capacity(), 256);

}

TEST(ArrayListTests, reserve_Less_test) {
	ssuds::ArrayList<int> int_list;
	for (int i = 0; i < 100; i++) {
		int_list.append(i);
	}

	int_list.reserve(25);

	ASSERT_TRUE(int_list.capacity() > 25);
}

TEST(ArrayListTests, Insert_outOfRangeException_test) {
	ssuds::ArrayList<int> int_list;
	int_list.append(1);
	int_list.append(2);
	int_list.append(3);
	int_list.append(4);

	unsigned int ui = -5;

	try {
		int_list.insert(5, ui);
		FAIL() << "Expected std::out_of_range";
	}
	catch (std::out_of_range const& err) {
		ASSERT_EQ(err.what(), std::string("Invalid index: " + std::to_string(ui)));
	}
	catch (...) {
		FAIL() << "Expected std::out_of_range";
	}

	// test index our of range long
	try {
		int_list.insert(6, 25);
		FAIL() << "Expected std::out_of_range";
	}
	catch (std::out_of_range const& err) {
		ASSERT_EQ(err.what(), std::string("Invalid index: " + std::to_string(25)));
	}
	catch (...) {
		FAIL() << "Expected std::out_of_range";
	}

}

TEST(ArrayListTests, Insert_test) {
	ssuds::ArrayList<int> int_list;
	int_list.append(1);
	int_list.append(2);
	int_list.append(3);
	int_list.append(4);

	
	int_list.insert(200, 2);
	EXPECT_EQ(int_list[0], 1);
	EXPECT_EQ(int_list[1], 2);
	EXPECT_EQ(int_list[2], 200);
	EXPECT_EQ(int_list[3], 3);
	EXPECT_EQ(int_list[4], 4);
}

TEST(ArrayListTests, Insert_index0_test) {
	ssuds::ArrayList<int> int_list;
	int_list.append(1);
	int_list.append(2);
	int_list.append(3);
	int_list.append(4);


	int_list.insert(200, 0);
	EXPECT_EQ(int_list[0], 200);
	EXPECT_EQ(int_list[1], 1);
	EXPECT_EQ(int_list[2], 2);
	EXPECT_EQ(int_list[3], 3);
	EXPECT_EQ(int_list[4], 4);
}

TEST(ArrayListTests, Insert_indexSize_test) {
	ssuds::ArrayList<int> int_list;
	int_list.append(1);
	int_list.append(2);
	int_list.append(3);
	int_list.append(4);


	int_list.insert(200, int_list.size());
	EXPECT_EQ(int_list[0], 1);
	EXPECT_EQ(int_list[1], 2);
	EXPECT_EQ(int_list[2], 3);
	EXPECT_EQ(int_list[3], 4);
	EXPECT_EQ(int_list[4], 200);
}

TEST(ArrayListTests, output_small_test) {
	ssuds::ArrayList<int> int_list;
	int_list.append(1);
	int_list.append(2);
	int_list.append(3);
	int_list.append(4);

	std::ostringstream oss;

	int_list.output(oss);

	ASSERT_EQ(oss.str(), "[1, 2, 3, 4]");

}



TEST(ArrayListTests, ostreamInput_operator_small_test) {
	ssuds::ArrayList<int> int_list;
	int_list.append(1);
	int_list.append(2);
	int_list.append(3);
	int_list.append(4);

	std::ostringstream oss;

	oss << int_list;

	ASSERT_EQ(oss.str(), "[1, 2, 3, 4]");

}



//=================================
//        Lab 3 Tests
//=================================

TEST(ArrayListIteratorTests, begin_test) {
	ssuds::ArrayList<int> int_list;
	for (int i = 0; i < 4; i++) {
		int_list.append(i);
	}

	EXPECT_EQ(*int_list.begin(), 0);

}

TEST(ArrayListIteratorTests, assignment_operator_test) {
	ssuds::ArrayList<int> int_list;
	ssuds::ArrayList<int>::ArrayListIterator it = int_list.begin();
	ssuds::ArrayList<int>::ArrayListIterator it2 = it;

	for (int i = 0; i < 4; i++) {
		int_list.append(i);
	}

	EXPECT_EQ(*it, 0);

}

TEST(ArrayListIteratorTests, dereference_operator_test) {
	ssuds::ArrayList<int> int_list;
	ssuds::ArrayList<int>::ArrayListIterator it = int_list.begin();

	for (int i = 0; i < 4; i++) {
		int_list.append(i);
	}

	EXPECT_EQ(*it, 0);

}

TEST(ArrayListIteratorTests, PlusPlus_operator_test) {
	ssuds::ArrayList<int> int_list;
	ssuds::ArrayList<int>::ArrayListIterator it = int_list.begin();

	for (int i = 0; i < 4; i++) {
		int_list.append(i);
	}

	it++;
	EXPECT_EQ(*it, 1);

	++it;
	EXPECT_EQ(*it, 2);


}


TEST(ArrayListIteratorTests, Plus_operator_test) {
	ssuds::ArrayList<int> int_list;
	ssuds::ArrayList<int>::ArrayListIterator it = int_list.begin();

	for (int i = 0; i < 4; i++) {
		int_list.append(i);
	}

	it = it + 2;

	EXPECT_EQ(*it, 2);

}

TEST(ArrayListIteratorTests, Minus_operator_test) {
	ssuds::ArrayList<int> int_list;
	ssuds::ArrayList<int>::ArrayListIterator it = int_list.begin();

	for (int i = 0; i < 4; i++) {
		int_list.append(i);
	}

	it = it + 2;
	it = it - 1;

	EXPECT_EQ(*it, 1);

}

TEST(ArrayListIteratorTests, Equal_operator_test) {
	ssuds::ArrayList<int> int_list;
	ssuds::ArrayList<int>::ArrayListIterator it = int_list.begin();
	ssuds::ArrayList<int>::ArrayListIterator it2 = it;

	for (int i = 0; i < 4; i++) {
		int_list.append(i);
	}

	EXPECT_TRUE(it == it2);
	
	it2++;

	EXPECT_FALSE(it == it2);

}

TEST(ArrayListIteratorTests, NotEqual_operator_test) {
	ssuds::ArrayList<int> int_list;
	ssuds::ArrayList<int>::ArrayListIterator it = int_list.begin();
	ssuds::ArrayList<int>::ArrayListIterator it2 = it;

	for (int i = 0; i < 4; i++) {
		int_list.append(i);
	}


	EXPECT_FALSE(it != it2);

	it2++;
	EXPECT_TRUE(it != it2);


}


TEST(ArrayListIteratorTests, end_test) {
	ssuds::ArrayList<int> int_list;
	ssuds::ArrayList<int>::ArrayListIterator it = int_list.begin();

	for (int i = 0; i < 4; i++) {
		int_list.append(i);
	}

	int count = 0;
	while (it != int_list.end()) {
		it++;
		count++;
	}
	ASSERT_EQ(count, 4);

}

TEST(ArrayListIteratorTests, forEachLoop_test) {
	ssuds::ArrayList<int> int_list;
	int_list.prepend(1);
	int_list.prepend(2);
	int_list.prepend(3);
	int_list.prepend(4);

	int index = 0;
	for (int num : int_list) {

		EXPECT_EQ(num, int_list[index]);
		index++;
	}
}

int main(int argc, char** argv) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}