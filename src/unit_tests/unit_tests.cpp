//array_list_tests.cpp

#include <gtest/gtest.h>
#include <sstream>
#include <ostream>
#include <arrayLists.h>


TEST(ArrayListTests, Defualt_Constructor_test) {
	ssuds::ArrayList<int> int_list;

	EXPECT_EQ(int_list.size(), 0);
	EXPECT_EQ(int_list.capacity(), 2);

}

TEST(ArrayListTests, Capcity_Constructor_test) {
	ssuds::ArrayList<int> int_list(1024);

	EXPECT_EQ(int_list.size(), 0);
	EXPECT_EQ(int_list.capacity(), 1024);

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

TEST(ArrayListTests, Capacity_test) {
	ssuds::ArrayList<int> int_list;
	
	for (int i = 0; i < 8; i++) {
		int_list.append(i);
	}

	EXPECT_EQ(int_list.capacity(), 8);
	int_list.append(5);
	EXPECT_EQ(int_list.capacity(), 16);

	for (int i = 0; i < int_list.capacity() * 0.75 + 1; i++) {
		int_list.remove(0);
	}

	EXPECT_EQ(int_list.capacity(), 8);


	



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
	try {
		int_list.remove(-5);
		FAIL() << "Expected std::out_of_range";
	}
	catch (std::out_of_range const& err) {
		EXPECT_EQ(err.what(), std::string("index is not in range"));
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
		EXPECT_EQ(err.what(), std::string("index is not in range"));
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

TEST(ArrayListTests, forEachLoop_test) {
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

TEST(ArrayListTests, At_outOfRangeException_test) {
	ssuds::ArrayList<int> int_list;
	int_list.append(1);
	int_list.append(2);
	int_list.append(3);
	int_list.append(4);


	// test if index is out of range short
	try {
		int_list.at(-5);
		FAIL() << "Expected std::out_of_range";
	}
	catch (std::out_of_range const& err) {
		EXPECT_EQ(err.what(), std::string("index is not in range"));
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
		EXPECT_EQ(err.what(), std::string("index is not in range"));
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

	EXPECT_EQ(int_list.capacity(), 4);

	int_list.reserve(256);
	
	EXPECT_EQ(int_list.capacity(), 256);

	int_list.reserve(16);

	EXPECT_EQ(int_list.capacity(), 16);

}

TEST(ArrayListTests, reserve_Less_test) {
	ssuds::ArrayList<int> int_list;
	for (int i = 0; i < 100; i++) {
		int_list.append(i);
	}


	// test if index is out of range short
	try {
		int_list.reserve(25);
		FAIL() << "Expected std::exception";
	}
	catch (std::exception const& err) {
		EXPECT_EQ(err.what(), std::string("you are attempting to make your array smaller than the amount of items it contains"));
	}
	catch (...) {
		FAIL() << "Expected std::exception";
	}
}

TEST(ArrayListTests, Insert_outOfRangeException_test) {
	ssuds::ArrayList<int> int_list;
	int_list.append(1);
	int_list.append(2);
	int_list.append(3);
	int_list.append(4);

	try {
		int_list.remove(-5);
		FAIL() << "Expected std::out_of_range";
	}
	catch (std::out_of_range const& err) {
		EXPECT_EQ(err.what(), std::string("index is not in range"));
	}
	catch (...) {
		FAIL() << "Expected std::out_of_range";
	}

	try {
		int_list.remove(25);
		FAIL() << "Expected std::out_of_range";
	}
	catch (std::out_of_range const& err) {
		EXPECT_EQ(err.what(), std::string("index is not in range"));
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


int main(int argc, char** argv) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}