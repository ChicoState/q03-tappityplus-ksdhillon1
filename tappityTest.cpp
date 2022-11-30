/**
 * Unit Test suite
**/

#include <gtest/gtest.h>
#include "tappity.h"
using namespace std;

class tappityTest : public ::testing::Test
{
	protected:
		tappityTest(){}
		virtual ~tappityTest(){}
		virtual void SetUp(){}
		virtual void TearDown(){}
};

TEST(tappityTest, smoke_test)
{
    ASSERT_TRUE(true);
}

TEST(tappityTest, sameLength_test)
{
    tappity tap1("y");
    tap1.entry("t");
    int result = tap1.length_difference();
    ASSERT_EQ(result, 0);
}

TEST(tappityTest, referencelengthGreater_test)
{
    tappity tap1("hello");
    tap1.entry("he");
    int result = tap1.length_difference();
    ASSERT_EQ(result, 3);
}

TEST(tappityTest, inputlengthGreater_test)
{
    tappity tap1("he");
    tap1.entry("hello");
    int result = tap1.length_difference();
    ASSERT_EQ(result, 3);
}

TEST(tappityTest, emptyreference_test)
{
    tappity tap1("");
    tap1.entry("hello");
    int result = tap1.length_difference();
    ASSERT_EQ(result, 5);
}

TEST(tappityTest, emptyinput_test)
{
    tappity tap1("hello");
    tap1.entry("");
    int result = tap1.length_difference();
    ASSERT_EQ(result, 5);
}

TEST(tappityTest, spacereferencelength_test)
{
    tappity tap1("house");
    tap1.entry(" ");
    int result = tap1.length_difference();
    ASSERT_EQ(result, 4);
}

TEST(tappityTest, halfsizeEntry_accuracy)
{
    tappity tap1("yooo");
    tap1.entry("yo");
    double result = tap1.accuracy();
    ASSERT_EQ(result, 50);
}

TEST(tappityTest, halfsizeReference_accuracy)
{
    tappity tap1("yo");
    tap1.entry("yooo");
    double result = tap1.accuracy();
    ASSERT_EQ(result, 50);
}

TEST(tappityTest, middlewrong_accuracy)
{
    tappity tap1("the quick brown fox");
    tap1.entry("the quickbrown");
    double result = tap1.accuracy();
    ASSERT_EQ(result, 47.3684);
}

TEST(tappityTest, firstletterwrong_accuracy)
{
    tappity tap1("too");
    tap1.entry("boo");
    double result = tap1.accuracy();
    ASSERT_EQ(result, 66.6667);
}

TEST(tappityTest, lastletterwrong_accuracy2)
{
    tappity tap1("the quick brown fox");
    tap1.entry("the quick brown for");
    double result = tap1.accuracy();
    ASSERT_EQ(result,94.7368);
}
