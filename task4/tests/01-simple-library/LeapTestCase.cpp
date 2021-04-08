//
// Created by akhtyamovpavel on 5/1/20.
//

#include "LeapTestCase.h"

#include <Functions.h>


TEST(IsLeapTest, BadYears)
{
	try
	{
		IsLeap(0);
		ASSERT_TRUE(false);
	} catch (...) {}	
}
TEST(IsLeapTest, OtherYears)
{
	ASSERT_TRUE(IsLeap(400));
	ASSERT_TRUE(!IsLeap(200));
	ASSERT_TRUE(!IsLeap(100));
	ASSERT_TRUE(!IsLeap(50));
	ASSERT_TRUE(IsLeap(4));
	ASSERT_TRUE(!IsLeap(1));
	
}



TEST(GetMonthDaysTest, February)
{
	EXPECT_EQ(GetMonthDays(400, 2), 29);
	EXPECT_EQ(GetMonthDays(200, 2), 28);
}
TEST(GetMonthDaysTest, BadMonths)
{
	try
	{
		GetMonthDays(2021, -1);
		ASSERT_TRUE(false);
	} catch (...) {}
	try
	{
		GetMonthDays(2021, 13);
		ASSERT_TRUE(false);
	} catch (...) {}
}
TEST(GetMonthDaysTest, OtherMonths)
{
	EXPECT_EQ(GetMonthDays(2021, 1), 31);
	EXPECT_EQ(GetMonthDays(2021, 4), 30);
	EXPECT_EQ(GetMonthDays(2021, 6), 30);
	EXPECT_EQ(GetMonthDays(2021, 9), 30);
	EXPECT_EQ(GetMonthDays(2021, 11), 30);
}
