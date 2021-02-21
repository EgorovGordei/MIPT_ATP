#include "testing.cpp"

int main(int argc, char **argv)
{
	//::all_tests::InitGoogleTest(&argc, argv);
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

