//
// Created by akhtyamovpavel on 5/1/20.
//

#include "AddTestCase.h"
#include "Functions.h"

TEST(AddingTest, Simple)
{
	EXPECT_EQ(Add(4, -3), 1);
}

