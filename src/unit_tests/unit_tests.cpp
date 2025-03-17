#include <array_list_tests.h>
#include <gtest/gtest.h>
//First, define a fixture class.By convention, you should give it the name FooTest where Foo is the class being tested.

class QueueTest : public testing::Test {
protected:
    QueueTest() {
   
    }

    Queue<int> n1;
    // ~QueueTest() override = default;
};


TEST_F(QueueTest, IsEmptyInitially) {
    EXPECT_EQ(n1.f2, 0);
}

int main(int argc, char** argv) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}