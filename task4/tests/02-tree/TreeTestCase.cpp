//
// Created by akhtyamovpavel on 5/1/20.
//

#include "TreeTestCase.h"
#include "Tree.h"


std::string tmp_path;
void GetReadyForTests()
{
	std::ofstream tmp_file;
	
	tmp_path = boost::filesystem::temp_directory_path().string();
	if (!(boost::filesystem::exists(tmp_path + "/TreeTest.NotADirectory")))
		boost::filesystem::create_directory(tmp_path + "/TreeTest.NotADirectory");
	tmp_file.open(tmp_path + "/TreeTest.NotADirectory/file");
	tmp_file.close();

	if (!(boost::filesystem::exists(tmp_path + "/TreeTest.1/")))
		boost::filesystem::create_directory(tmp_path + "/TreeTest.1");
	tmp_file.open(tmp_path + "/TreeTest.1/file1");
	tmp_file.close();
	if (!(boost::filesystem::exists(tmp_path + "/TreeTest.1/.1")))
		boost::filesystem::create_directory(tmp_path + "/TreeTest.1/.1");
	tmp_file.open(tmp_path + "/TreeTest.1/.1/file1.1");
	tmp_file.close();
	if (!(boost::filesystem::exists(tmp_path + "/TreeTest.1/.2")))
		boost::filesystem::create_directory(tmp_path + "/TreeTest.1/.2");
	tmp_file.open(tmp_path + "/TreeTest.1/.2/file1.2.1");
	tmp_file.close();
	tmp_file.open(tmp_path + "/TreeTest.1/.2/file1.2.2");
	tmp_file.close();

	if (!(boost::filesystem::exists(tmp_path + "/TreeTest.1/.3")))
		boost::filesystem::create_directory(tmp_path + "/TreeTest.1/.3");
}


TEST(TreeTest, NotExists)
{
	GetReadyForTests();
	try
	{
		GetTree(tmp_path + "/TreeTest.NoExists/this_file_doesnt_exist__really", false);
		ASSERT_TRUE(false);
	} catch (std::invalid_argument& a) 
	{
		ASSERT_TRUE(std::strcmp(a.what(), "Path not exist") == 0);
	}
}
TEST(TreeTest, NotADirectory)
{
	GetReadyForTests();
	try
	{
		GetTree(tmp_path + "/TreeTest.NotADirectory/file", false);
		ASSERT_TRUE(false);
	} catch (std::invalid_argument& a) 
	{
		ASSERT_TRUE(std::strcmp(a.what(), "Path is not directory") == 0);
	}
}



long long hash(const std::string& s)
{
	long long ans = 0;
	for (char c : s) ans += c;
	return ans;
}
TEST(TreeTest, GetTree_Files)
{
	GetReadyForTests();
	FileNode result = GetTree(tmp_path + "/TreeTest.1", false);
	std::string ans = "";
	ans += result.name;
	for (auto it : result.children)
	{
		ans += it.name;
	}
	
	ASSERT_TRUE(hash(ans) == hash("TreeTest.1.1.2file1.3"));
	
}
TEST(TreeTest, GetTree_Folders)
{
	GetReadyForTests();
	FileNode result = GetTree(tmp_path + "/TreeTest.1", true);
	std::string ans = "";
	ans += result.name;
	for (auto it : result.children)
	{
		ans += it.name;
	}
	
	ASSERT_TRUE(hash(ans) == hash("TreeTest.1.1.2.3"));
}
TEST(TreeTest, FilterEmptyNodes1)
{
	GetReadyForTests();
	FileNode result = GetTree(tmp_path + "/TreeTest.1", true);
	FilterEmptyNodes(result, ".");
	result = GetTree(tmp_path + "/TreeTest.1", true);
	std::string ans = "";
	ans += result.name;
	for (auto it : result.children)
	{
		ans += it.name;
	}
	
	ASSERT_TRUE(hash(ans) == hash("TreeTest.1.1.2.3"));
}

TEST(TreeTest, FilterEmptyNodes2)
{
	GetReadyForTests();
	FileNode result = GetTree(tmp_path + "/TreeTest.1/.1/", false);
	FilterEmptyNodes(result.children[0], ".");
	result = GetTree(tmp_path + "/TreeTest.1", true);
	std::string ans = "";
	ans += result.name;
	for (auto it : result.children)
	{
		ans += it.name;
	}
	
	ASSERT_TRUE(hash(ans) == hash("TreeTest.1.1.2.3"));
}
TEST(TreeTest, FilterEquals)
{
	GetReadyForTests();
	FileNode result = GetTree(tmp_path + "/TreeTest.1", true);
	ASSERT_TRUE(result == result);
	FileNode result2 = GetTree(tmp_path, true);
	ASSERT_FALSE(result == result2);
	FileNode result3 = GetTree(tmp_path + "/TreeTest.1", false);
	ASSERT_FALSE(result == result3);
	FileNode result4 = GetTree(tmp_path + "/TreeTest.1/.1", false).children[0];
	ASSERT_FALSE(result == result4);
}

