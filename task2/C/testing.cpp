#include <gtest/gtest.h>

#include "A/index.h"
#include "B/lib.h"
#include "B/lib.cpp"

TEST(Test1, FirstTest)
{
	EXPECT_EQ(D(), "this is D");
}

TEST(Test2, SecondTest)
{
	EXPECT_EQ(C, 123098);
}

